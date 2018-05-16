setwd("C:/Users/Isaac/Desktop")
communities <- read.csv("communities.csv")
#cluster N
cluster3 <- read.csv("result3.csv")
community_clusters3<- communities
community_clusters3$cluster <- cluster3$cluster

#basic regression of all data
basic_model <- lm(communities$ViolentCrimesPerPop ~ communities$population + communities$racePctWhite + communities$PctPopUnderPov)
summary(basic_model)
plot(communities$ViolentCrimesPerPop ~ communities$population + communities$racePctWhite + communities$PctPopUnderPov)

#runs regression for each cluster
output3 <- list()
regression3 <- list()
for (x in c(1,3,2)){
  output3[[x]] <- subset(community_clusters3, community_clusters3$cluster==(x-1))
  regression3[[x]] <- lm(output3[[x]]$ViolentCrimesPerPop ~ output3[[x]]$population + output3[[x]]$racePctWhite + output3[[x]]$PctPopUnderPov)
  print(summary(regression3[[x]]))
}
#plots data
plot(communities_3c$ViolentCrimesPerPop~communities_3c$PctPopUnderPov,xlab="Instances",ylab="Violent crimes", col = ifelse(communities_3c$cluster == 0,'green',ifelse(communities_3c$cluster ==1 ,'red','blue')), pch = 19 )
abline(regression3[[1]])#green
abline(regression3[[2]])#red
abline(regression3[[3]])#blue
plot(communities_3c$ViolentCrimesPerPop ~ communities$racePctWhite,xlab="Instances",ylab = "violent crime")
abline(basic_model)
