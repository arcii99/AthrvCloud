//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int days, prob, count=0;
    srand(time(0));
    printf("Welcome to the C Alien Invasion Probability Calculator.\n");
    printf("Enter how many days you would like to calculate the probability for (maximum 365): ");
    scanf("%d", &days);

    for(int i=1; i<=days; i++){
        prob=rand()%101;
        if(prob>=50){
            count++;
        }
    }

    float probability=((float)count/days)*100;

    printf("\nBased on the probability index of 50:\n");
    printf("The probability of an alien invasion over %d day(s) is: %.2f%%.\n", days, probability);
    if(probability>=75){
        printf("WARNING: Potential threat of alien invasion detected!\n");
    }
    else{
        printf("Safe from alien invasion for %d day(s)!\n", days);
    }

    return 0;
}