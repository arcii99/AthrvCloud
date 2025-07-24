//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int strength[5];
    int i;
    double average;

    printf("Enter the signal strength of 5 Wi-Fi networks\n");

    for(i=0;i<5;i++){
        printf("Network %d: ", i+1);
        scanf("%d", &strength[i]);
    }

    //calculate average
    average = 0;
    for(i=0;i<5;i++){
        average += strength[i];
    }
    average = average/5;

    printf("\nAverage signal strength: %f\n", average);

    //display strength levels
    printf("\nStrength levels:\n");
    for(i=0; i<5; i++){
        if(strength[i] >= average){
            printf("Network %d: Strong\n", i+1);
        }
        else{
            printf("Network %d: Weak\n", i+1);
        }
    }

    return 0;
}