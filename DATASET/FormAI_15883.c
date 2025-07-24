//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: happy
#include <stdio.h>

int main() {
    int num, i, j, k, sum = 0;
    
    printf("Hello there! Let's visualize Fibonacci series with some joy!\n\n");
    printf("Enter the number of terms you want to see in the sequence: ");
    scanf("%d", &num);
    
    printf("\nYay! Here's the Fibonacci sequence of %d terms:\n\n", num);
    
    // First two terms of the sequence
    i = 0;
    j = 1;
    
    printf("%d ", i);
    printf("%d ", j);
    
    for (k = 3; k <= num; k++) {
        sum = i + j;                // Calculate the next term
        printf("%d ", sum);
        i = j;                      // Shift the values
        j = sum;
    }
    
    printf("\n\nWow! That was amazing! Let's celebrate it together!!!\n\n");
    printf("                                             **\n");
    printf("                                            ****\n");
    printf("                                          ********\n");
    printf("                                      **************\n");
    printf("                                    ******************\n");
    printf("                                  ********************\n");
    printf("                                **********************\n");
    printf("                             *************************\n");
    printf("                       *******************************\n");
    printf("                 ****************************************\n");
    printf("          ************************************************\n");
    printf("     ********************************************************\n");
    printf("       *****************************************************\n");
    printf("          ***********************************************\n");
    printf("                 *************************************\n");
    printf("                       ***************************\n");
    printf("                             *******************\n");
    printf("                                 *************\n");
    printf("                                     ******\n");
    printf("                                        **\n");

    return 0;
}