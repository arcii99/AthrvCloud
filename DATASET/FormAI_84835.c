//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: ephemeral
#include<stdio.h>

int main(){
  //Initializing Variables
  int streetLength=5;
  int numLanes=3;
  int numVehicles=15;
  int timer=0;
  int trafficDensity[streetLength][numLanes];
  int tempDensity[streetLength][numLanes];
  
  //Setting up initial traffic density
  for(int i=0;i<streetLength;i++){
    for(int j=0;j<numLanes;j++){
      trafficDensity[i][j]=0;
    }
  }
  for(int i=0;i<numVehicles;i++){
    trafficDensity[0][i%numLanes]+=1;
  }
  
  //Printing the initial traffic density
  printf("Initial Traffic density:\n");
  for(int i=0;i<streetLength;i++){
    for(int j=0;j<numLanes;j++){
      printf("%d ",trafficDensity[i][j]);
    }
    printf("\n");
  }
  
  //Traffic Flow Simulation
  while(timer<10){
    for(int i=0;i<streetLength;i++){
      for(int j=0;j<numLanes;j++){
        int density=0;
        //Calculating Density around a lane
        for(int x=-1;x<=1;x++){
          if(i+x>=0 && i+x<streetLength){
            density+=trafficDensity[i+x][j];
          }
        }
        //Calculating updated density based on traffic rules
        if(density>2){
          tempDensity[i][j]=trafficDensity[i][j]-1;
        }
        else if(density<2){
          tempDensity[i][j]=trafficDensity[i][j]+1;
        }
        else{
          tempDensity[i][j]=trafficDensity[i][j];
        }
      }
    }
    //Updating actual density with updated one
    for(int i=0;i<streetLength;i++){
      for(int j=0;j<numLanes;j++){
        trafficDensity[i][j]=tempDensity[i][j];
      }
    }
    //Printing Updated Density
    printf("\nDensity at %d Seconds:\n",timer+1);
    for(int i=0;i<streetLength;i++){
      for(int j=0;j<numLanes;j++){
        printf("%d ",trafficDensity[i][j]);
      }
      printf("\n");
    }
    //Increasing Timer
    timer++;
  }
  
  return 0;
}