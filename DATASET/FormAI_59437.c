//FormAI DATASET v1.0 Category: Data mining ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DATA_SIZE 1000
#define NUM_ELEMENTS 20

int main() {
    int data[MAX_DATA_SIZE];
    srand(time(NULL)); // seed random number generator
    
    // generate random data
    for(int i = 0; i < MAX_DATA_SIZE; i++) {
        data[i] = (rand() % NUM_ELEMENTS) + 1;
    }
    
    // count frequency of each number
    int frequencies[NUM_ELEMENTS] = {0};
    for(int i = 0; i < MAX_DATA_SIZE; i++) {
        frequencies[data[i] - 1]++;
    }
    
    // print histogram of frequency distribution
    printf("Data Mining Example Program (Retro Style)\n");
    printf("-----------------------------------------\n");
    printf("| NUM | FREQUENCY |\n");
    printf("|-----|-----------|\n");
    for(int i = 0; i < NUM_ELEMENTS; i++) {
        printf("| %3d | ", i + 1);
        for(int j = 0; j < frequencies[i]; j++) {
            printf("*");
        }
        printf(" |\n");
    }
    printf("-----------------------------------------\n");
    
    return 0;
}