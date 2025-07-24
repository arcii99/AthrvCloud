//FormAI DATASET v1.0 Category: Stock market tracker ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    
    int A[100];
    int i;
    float index = 0;
    float sum = 0;
    float average = 0;
    
    printf("Welcome to the C Stock Market Tracker\n\n");
    
    //seed random number generator
    srand(time(NULL));
    
    //populate array with random stock values between 50 and 200
    for(i=0;i<100;i++){
        A[i] = rand()%151 + 50;
        printf("Stock %d: %d\n", i+1, A[i]);
    }
    
    //print stock values above and below the average value
    for(i=0;i<100;i++){
        sum += A[i];
    }
    average = sum/100;
    
    printf("\nAverage Stock Value: %.2f\n", average);
    printf("\nStock Values Above Average: \n");
    for(i=0;i<100;i++){
        if(A[i]>average){
            printf("Stock %d: %d\n", i+1, A[i]);
        }
    }
    printf("\nStock Values Below Average: \n");
    for(i=0;i<100;i++){
        if(A[i]<average){
            printf("Stock %d: %d\n", i+1, A[i]);
        }
    }
    
    //calculate index value
    for(i=0;i<100;i++){
        index += A[i];
    }
    index /= 100;
    
    printf("\nStock Market Index Value: %.2f\n", index);
    
    return 0;
}