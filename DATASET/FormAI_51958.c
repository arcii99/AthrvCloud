//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int number_of_seconds)  { 
    int milli_seconds = 1000 * number_of_seconds; 
    clock_t start_time = clock(); 
    while (clock() < start_time + milli_seconds); 
} 

int main() {
    int num, first = 0, second = 1, next, i;
    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("Enter the number of terms you want to generate: ");
    scanf("%d", &num);
    printf("\nGenerating Fibonacci sequence...\n");
    delay(1000);
    printf("\n%d %d ", first, second);
    
    for (i = 2; i < num; i++) {
        next = first + second;
        first = second;
        second = next;
        printf("%d ", next);
        delay(500); // delay added for visual effect
    }
    printf("\nDone generating the Fibonacci sequence!");
    return 0;
}