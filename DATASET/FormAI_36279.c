//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

//Function to generate Fibonacci sequence up to a given limit
void generateFibonacci(int limit){
    int previous_term = 0, current_term = 1, next_term, i;
    printf("%d %d ", previous_term, current_term); //print first two terms

    for(i=2; i<limit; i++){
        next_term = previous_term + current_term;
        printf("%d ", next_term); //print next term
        previous_term = current_term;
        current_term = next_term;
    }
}

//Function to display the Fibonacci sequence visually
void displayVisualizer(int limit){
    int previous_term = 0, current_term = 1, next_term, i, j, k, space = limit - 2;

    for(i=0; i<limit-1; i++){
        next_term = previous_term + current_term;
        previous_term = current_term;
        current_term = next_term;

        for(j=0; j<space; j++){
            printf(" ");
        }
        space -= 2;

        for(k=0; k<=i; k++){
            printf("%d ", next_term);
        }
        printf("\n");
    }
}

int main(){
    int limit;
    printf("Enter the limit for the Fibonacci sequence: ");
    scanf("%d", &limit);
    printf("The Fibonacci sequence up to %d terms is:\n", limit);
    generateFibonacci(limit);
    printf("\n\nThe Fibonacci sequence visualizer for %d terms is:\n", limit);
    displayVisualizer(limit);
    return 0;
}