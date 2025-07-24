//FormAI DATASET v1.0 Category: Sorting ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    //Let's declare an array of numbers to be sorted
    int numbers[10] = {8,5,1,0,3,6,9,4,2,7};

    printf("Before sorting: ");
    for(int i=0; i<10; i++){
        printf("%d ",numbers[i]);
    }

    //Implementing a unique sorting algorithm using a random number generator
    srand(time(NULL)); //Initializing the random number generator 

    for(int i=0; i<10; i++){
        int random_index = rand() % 10; //Generating a random index number
        int temp = numbers[i];
        numbers[i] = numbers[random_index];
        numbers[random_index] = temp; //Swapping the elements at index i and the randomly generated index
        printf("\nSwapping index %d with index %d",i,random_index); //Printing each step of the sorting process in a funny way 
    }

    printf("\n\nAfter sorting: ");
    for(int i=0; i<10; i++){
        printf("%d ",numbers[i]);
    }

    return 0;
}