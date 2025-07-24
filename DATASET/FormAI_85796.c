//FormAI DATASET v1.0 Category: Temperature monitor ; Style: calm
#include<stdio.h>

/* Temperature Monitor */

int main(){

    float temperature;
    int count;
    float sum=0;
    float average;

    printf("Welcome to the Temperature Monitor Program\n\n");

    printf("How many temperature readings would you like to enter? ");
    scanf("%d",&count);

    printf("\n");

    for(int i=1;i<=count;i++){
        printf("Enter temperature reading %d: ",i);
        scanf("%f",&temperature);
        sum+=temperature;
    }

    average=sum/count;

    printf("\nAverage temperature is %.2f\n",average);

    if(average>=30){
        printf("\nHigh Temperature Alert!\n");
    }
    else if(average>=20 && average<30){
        printf("\nNormal Temperature Range\n");
    }
    else{
        printf("\nLow Temperature Alert!\n");
    }

    return 0;
}