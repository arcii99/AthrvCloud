//FormAI DATASET v1.0 Category: Data mining ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(NULL));

    printf("Welcome to the Data Mining Fun House!\n");

    int data[100] = {0};

    printf("Generating random data... ");

    for(int i=0; i<100; i++){
        data[i] = rand() % 100;
    }

    printf("Done!\n\n");

    int searchValue = rand() % 100;
    int found = 0;

    printf("Our search value is: %d\n", searchValue);

    for(int i=0; i<100; i++){
        if(data[i] == searchValue){
            printf("Found it at index %d\n", i);
            found = 1;
            break;
        }
    }

    if(!found){
        printf("Sorry, couldn't find the value!\n");
    }

    printf("\nMining for the largest value... ");

    int max = 0;

    for(int i=0; i<100; i++){
        if(data[i] > max){
            max = data[i];
        }
    }

    printf("Found it! It's %d\n", max);

    printf("\nMining for the smallest value... ");

    int min = 100;

    for(int i=0; i<100; i++){
        if(data[i] < min){
            min = data[i];
        }
    }

    printf("Found it! It's %d\n", min);

    printf("\nSorting the data... ");

    for(int i=0; i<100; i++){
        for(int j=0; j<99; j++){
            if(data[j] > data[j+1]){
                int temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }

    printf("Done!\n\n");

    printf("Here's the sorted data: ");

    for(int i=0; i<100; i++){
        printf("%d ", data[i]);
    }

    printf("\n");

    printf("Thanks for visiting the Data Mining Fun House! Come back soon!\n");

    return 0;
}