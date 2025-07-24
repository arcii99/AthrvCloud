//FormAI DATASET v1.0 Category: Memory management ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // declaring integer variable num and allocating memory for it
    int *num = (int*)malloc(sizeof(int));
    if (num == NULL) { //check for successful memory allocation
        printf("Failed to allocate memory");
        return 1;
    }

    // declaring integer variable count and allocating memory for it
    int *count = (int*)calloc(1, sizeof(int));
    if (count == NULL) { //check for successful memory allocation
        printf("Failed to allocate memory");
        free(num); //free previously allocated memory
        return 1;
    }

    // allocating memory for a character array of size 10 and assigning it the value "hello"
    char *str = (char*)malloc(10 * sizeof(char));
    if (str == NULL) { //check for successful memory allocation
        printf("Failed to allocate memory");
        free(num); //free previously allocated memory
        free(count); //free previously allocated memory
        return 1;
    }
    strcpy(str, "hello");

    printf("Enter a number: ");
    scanf("%d", num);
    (*count)++; //increment count by 1

    printf("You entered: %d\n", *num);
    printf("Count: %d\n", *count);
    printf("String: %s\n", str);

    //free allocated memory
    free(num); 
    free(count); 
    free(str);

    return 0;
}