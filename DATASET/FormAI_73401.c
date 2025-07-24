//FormAI DATASET v1.0 Category: Arithmetic ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
 #include <time.h>
int main() {
    int num_operands;
    printf("Enter the number of operands: ");
    scanf("%d", &num_operands);

    int* operands = (int*)malloc(num_operands * sizeof(int));
    char* operators = (char*)malloc((num_operands - 1) * sizeof(char));

    srand(time(NULL));
    for(int i=0; i<num_operands; i++){
        operands[i] = rand() % 100;
    }

    for(int i=0; i<num_operands-1; i++){
        printf("Select operator to use between %d and %d: \n", operands[i], operands[i+1]);
        printf("+ or - or *(multiplication) or / (division)? ");
        scanf(" %c", &operators[i]);
    }

    int result = operands[0];
    for(int i=0; i<num_operands-1; i++){
        switch(operators[i]){
            case '+':
                result += operands[i+1];
                break;
            case '-':
                result -= operands[i+1];
                break;
            case '*':
                result *= operands[i+1];
                break;
            case '/':
                result /= operands[i+1];
                break;
            default:
                printf("Incorrect operator: %c\n", operators[i]);
                break;
        }
    }

    printf("\nThe result is: %d\n", result);

    free(operands);
    free(operators);
    return 0;
}