# kmeans_1d

This is a program that executes k means algorithm in one dimensional case.

The data for testing comes from UCI Machine Learning Repository(Link: https://archive.ics.uci.edu/ml/datasets/Communities+and+Crime)
The data used is for 1D case is comes from the "ViolentCrimesPerPop" section which contains information of city id and percentage value
The city id is unique for each city, and this program use the id as index on the 1d axis and put the percentage value in the corresponding location
I mainly used array as the data structure for this algorithm, even though I think a linked list with the head contains information of mean value or a tree with root contains that information would also probably work. I'll think about those ways of implementing later when updating.
The program could be expanded for using the data set with more dimensions - just change how the distance between two points is calculated.

There're more things I'd like to try with this program, and I'll upload any updats in the future.

---------------------------------------------------------------------------------
Included is also the R code for clusters with 3 and 6 nodes along with the data. For the R code to work simply change the setwd(diretory) to the directory where you have saved the data. The code should print out regression tables as well as the plots for the original and segmented data.
