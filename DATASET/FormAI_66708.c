//FormAI DATASET v1.0 Category: Memory management ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the memory puzzle!\n");
    
    int *ptr1 = (int*) malloc(sizeof(int)); // allocate memory for integer
    char *ptr2 = (char*) calloc(5, sizeof(char)); // allocate memory for five characters
    
    // puzzle time!
    int num1 = *ptr1 + 5;
    char char1 = *(ptr2 + 1) + 'a';
    
    printf("num1 is %d and char1 is %c\n", num1, char1);
    
    free(ptr1); // deallocate integer memory
    free(ptr2); // deallocate character memory
    
    printf("Thanks for playing the memory puzzle!\n");
    
    return 0;
}