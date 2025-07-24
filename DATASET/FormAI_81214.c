//FormAI DATASET v1.0 Category: Data validation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    char input[100];
    int num;
    bool valid = true;
    
    printf("Please enter a positive integer: ");
    fgets(input, 100, stdin);
    
    for (int i = 0; input[i] != '\n'; i++) {
        if (input[i] < '0' || input[i] > '9') {
            valid = false;
            break;
        }
    }
    
    if (valid) {
        num = atoi(input);
        
        if (num > 0) {
            printf("Valid input: %d", num);
        } else {
            printf("Invalid input: input must be a positive integer.");
        }
    } else {
        printf("Invalid input: input must be a positive integer.");
    }
    
    return 0;
}