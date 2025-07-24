//FormAI DATASET v1.0 Category: Data mining ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Surreal C Data Mining Example
// By a chatbot

int main() {
    srand(time(NULL));
    int data[100];
    int sum = 0;
    float average;
    
    // Generating surreal data
    for(int i=0;i<100;i++) {
        if(i%5 == 0 || i%7 == 0) {
            data[i] = rand()%500 + 500;
        }
        else if(i%3 == 0) {
            data[i] = rand()%1000 + 2000;
        }
        else {
            data[i] = rand()%200 + 300;
        }
    }
    
    // Displaying the surreal data
    printf("The surreal data is: \n");
    for(int i=0;i<100;i++) {
        printf("%d ", data[i]);
        if(i%10 == 9)
            printf("\n");
    }
    
    // Calculating the sum of surreal data
    for(int i=0;i<100;i++) {
        sum += data[i];
    }
    
    // Calculating the average of surreal data
    average = (float)sum / 100;
    
    // Displaying the sum and average of surreal data
    printf("\nThe sum of surreal data is: %d\n", sum);
    printf("The average of surreal data is: %.2f\n", average);
    
    return 0;
}