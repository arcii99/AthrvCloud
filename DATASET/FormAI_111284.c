//FormAI DATASET v1.0 Category: Data mining ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
  int data[9][3]={{1,0,1},{1,1,0},{1,0,0},{0,1,0},{0,1,1},{0,0,1},{1,1,1},{0,0,0},{1,1,0}};
  int i,j,k;
  float mean[3], std_dev[3];
  //Calculating Mean
  for(j=0; j<3; j++){
    mean[j]=0;
    for(i=0; i<9; i++){
      mean[j]+= data[i][j];
    }
    mean[j]/=9;
  }
  //Calculating Standard Deviation
  for(j=0; j<3; j++){
    std_dev[j]=0;
    for(i=0; i<9; i++){
      std_dev[j]+= pow(data[i][j]-mean[j],2);
    }
    std_dev[j]=sqrt(std_dev[j]/9);
  }
  
  //Printing the Calculated Values
  printf("Mean Values: \n");
  for(i=0; i<3; i++){
    printf("Attribute %d: %.2f\n",i+1,mean[i]);
  }
  printf("Standard Deviation Values: \n");
  for(i=0; i<3; i++){
    printf("Attribute %d: %.2f\n",i+1,std_dev[i]);
  }
  
  //Checking for Outliers
  printf("The following data points can be considered as outliers:\n");
  for(i=0; i<9; i++){
    for(j=0; j<3; j++){
      if((data[i][j] < (mean[j]-2*std_dev[j])) || (data[i][j] > (mean[j]+2*std_dev[j]))){
        printf("(%d,%d,%d)\n",data[i][0],data[i][1],data[i][2]);
        break;
      }
    }
  }
  return 0;
}