//FormAI DATASET v1.0 Category: Word Count Tool ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[100];
    int count = 0;
    
    printf("Welcome to the C Word Count Tool!\n");
    printf("Please enter a string of text: ");
    fgets(str, 100, stdin); // read input from user
    
    char *token = strtok(str, " "); // tokenize string using space as delimiter
    while (token != NULL) {
        count++; // increment count for each token
        token = strtok(NULL, " ");
    }
    
    printf("\n");
    printf("The number of words in the input text is: %d\n", count);
    printf("\n");
    printf("Thank you for using the C Word Count Tool!\n");
    
    return 0;
}