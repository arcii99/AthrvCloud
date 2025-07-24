//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: irregular
#include <stdio.h>

int main() {
    int prev = 0;
    int curr = 1;
    int limit;

    printf("Enter the limit for the Fibonacci sequence: ");
    scanf("%d", &limit);

    for(int i = 0; i < limit; i++) {
        
        /* Define the color and style for the output */
        switch(i % 5) {
            case 0:
                printf("\033[1;31m");  /* Red bold text */
                break;
            case 1:
                printf("\033[1;32m");  /* Green bold text */
                break;
            case 2:
                printf("\033[1;33m");  /* Yellow bold text */
                break;
            case 3:
                printf("\033[1;34m");  /* Blue bold text */
                break;
            case 4:
                printf("\033[1;35m");  /* Magenta bold text */
                break;
        }

        printf("%d ", curr);
        int next = prev + curr;
        prev = curr;
        curr = next;
        
        /* Reset the color and style */
        printf("\033[0m");
        
        /* Add some random whitespace for visual effect */
        for(int j = 0; j < i % 5 + 1; j++) {
            printf(" ");
        }
    }

    return 0;
}