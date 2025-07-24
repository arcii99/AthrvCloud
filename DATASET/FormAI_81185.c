//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BUFFER_SIZE 100 // Configurable buffer size

int main(void) {
    char input[BUFFER_SIZE];
    double ans = 0.0;
    int cont = 1;

    printf("--- BASIC CALCULATOR ---\n");
    printf("Enter 'q' to quit\n");

    while (cont) {
        printf("Enter calculation:\n");
        fgets(input, BUFFER_SIZE, stdin);

        if (input[0] == 'q' || input[0] == 'Q') {
            printf("Goodbye!\n");
            cont = 0;
        } else {
            // Parse input
            int i = 0;
            double total = 0.0;
            int op = 1;
            int numCount = 0;
            double nums[50];
            char opers[50];
            int numStart = 0;

            while (input[i] != '\0' && input[i] != '\n') {
                if (input[i] == ' ' || input[i] == '\t') {
                    if (i > numStart) {
                        char numStr[BUFFER_SIZE];
                        int j;
                        for (j = 0; j < (i - numStart); j++){
                            numStr[j] = input[numStart + j];
                        }
                        numStr[j] = '\0';                        
                        nums[numCount] = atof(numStr);
                        numCount++;                        
                    }
                    numStart = i + 1;
                } else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '^') {
                    opers[numCount] = input[i];
                    op = input[i];
                }
                i++;
            }

            if (i > numStart) {
                char numStr[BUFFER_SIZE];
                int j;
                for (j = 0; j < (i - numStart); j++){
                    numStr[j] = input[numStart + j];
                }
                numStr[j] = '\0';                        
                nums[numCount] = atof(numStr);
                numCount++;                        
            }

            if (numCount < 2) {
                printf("Invalid input, need at least two numbers for an operation.\n");
            } else {
                // Perform operations
                int j;
                for (j = 0; j < numCount; j++) {
                    if (opers[j-1] == '+') {
                        total += nums[j];
                    } else if (opers[j-1] == '-') {
                        total -= nums[j];
                    } else if (opers[j-1] == '*') {
                        total *= nums[j];
                    } else if (opers[j-1] == '/') {
                        if (nums[j] == 0) {
                            printf("Divide by zero error.\n");
                            break;
                        }
                        total /= nums[j];
                    } else if (opers[j-1] == '^') {
                        total = pow(total, nums[j]);
                    } else if (j == 0) {
                        total = nums[j];
                    }
                }

                ans = total;
                printf("Answer: %f\n", ans);
            }
        }
    }

    return 0;
}