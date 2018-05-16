setwd("C:/Users/Isaac/Desktop")
communities <- read.csv("communities.csv")
#cluster N
cluster <- read.csv("result6.csv")
community_clusters<-communities
community_clusters$cluster <- cluster$Cluster

output <- list()
regressions <- list()
for (x in c(5,4,6,1,3,2)){
  output[[x]] <- subset(community_clusters, community_clusters$cluster==(x-1))
  regressions[[x]] <- lm(output[[x]]$ViolentCrimesPerPop ~ output[[x]]$population + output[[x]]$racePctWhite + output[[x]]$PctPopUnderPov)
  print(summary(regressions[[x]]))
  }
plot(community_clusters$ViolentCrimesPerPop~community_clusters$PctPopUnderPov,xlab="percentage of population under poverty",
     ylab="Violent crimes",col = ifelse(community_clusters$cluster == 0,'yellow',ifelse(community_clusters$cluster ==1 ,'red', 
                                                                                     ifelse(community_clusters$cluster ==2,'orange',
                                                                                            ifelse(community_clusters$cluster ==3,'blue',
                                                                                                   ifelse(community_clusters$cluster ==4,'purple','green'))))), pch = 19 )
for(x in c(5,4,6,1,3,2)){
  abline(regressions[[x]])
}                            
                  
     