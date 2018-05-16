//Yangjia Li

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

//get the distance between two points in 1D
float getDist(float p1, float p2){
  float dist; /*distance between two points*/

  dist = fabsf(p1 - p2); /*in 1D case, that distance would just be the absolute value of the subtraction of two values*/

  return dist;
}

/*get the nearest distance from a given point to other centers
 *return the label number the nearest center
 */
int getNearestDist(float array[], float p, int k){
  float nearestDist = 1.0; /*in this particular data set, we're deal with percentage, so the largest distance between two point would be 1*/
  float dist; /*distance between two points*/
  int i; /*counter and index*/
  int label; /*label number of each cluster*/

  //compare the distance between the given point and each center
  for(i = 0; i < k; i++){
    dist = getDist(array[i], p);
    //find the closest center and update the label to be the label number of this cluster
    if(dist < nearestDist){
      nearestDist = dist;
      label = i;
    }
  }

  return label;
}

/*get the mean of each cluster
 *set that value as new center
 */
float getMean(float vArray[], int lArray[], int label, int size){
  float sum = 0.0; /*sum of distances from center to all points in this cluster*/
  float counter = 0.0;
  float mean;
  int i = 1;

  for(; i < size + 1; i++){
    if(lArray[i] == label){
      sum += vArray[i];
      counter++;
    }
  }

  mean = sum/counter;

  return mean;
}

int main(){
  int dataSize = 1994; /* number of data point */
  int k = 1; /* cluster number */
  int i = 1; /* counter, also use as id for each data point*/
  int label; /* label of each cluster */
  float datum; /* value of each data point */
  int repeat; /* how many times to repeat */

  /*scan for k value
   *located in the first line of data set
   */
  scanf("%d", &k);

  /*create three arrays to store data
   *labelArray and valueArray use the id for each data point as index
   *therfore, for these two arrays index starts from 1
   *centerArray use label number as index
   */
  int labelArray[dataSize]; /* store the label of each data at corresponding locataion */
  float valueArray[dataSize]; /* store the value of each data at corresponding location */
  float centerArray[k]; /* store the mean value of each cluster at corresponding location */

  //write in data for valueArray;
  for(; i < dataSize + 1; i++){
    scanf("%f", &datum);
    valueArray[i] = datum;
  }

  //use first k points in valueArray as center;
  for(i = 0; i < k; i++)
    centerArray[i] = valueArray[i + 1];

  for(repeat = 0; repeat < 30; repeat++){
    //write in label for each data point
    for(i = 1; i < dataSize + 1; i++){
      label = getNearestDist(centerArray, valueArray[i], k);
      labelArray[i] = label;
    }

    /*calculate the mean value of each cluster
     *set it as the new center
     */
    for(i = 0; i < k; i++){
      centerArray[i] = getMean(valueArray, labelArray, i, dataSize);
      //printf("new center is %f\n", centerArray[i]);
    }
  }

  //another sytle of output
  /*
    for(i = 0; i < k; i++){
      printf("-----------Cluster %d-----------\n", i);
      for(int j = 1; j < dataSize + 1; j++){
        if(labelArray[j] == i)
          printf("index %d value %0.2f\n", j, valueArray[j]);
      }
    }
  */

  //output id and corresponding label
  for(i = 1; i < dataSize + 1; i++)
    printf("%d,%d\n", i, labelArray[i]);

  //output center value
  for(i = 0; i < k; i++)
    printf("center %d  is %f\n", i,  centerArray[i]);
  
  return 0;
}


