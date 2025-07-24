//FormAI DATASET v1.0 Category: Memory management ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

/* Define a data structure that will hold a string */
typedef struct {
    char* string;
} Data;

int main() {
    /* Declare a pointer variable for a Data structure */
    Data* data_ptr;

    /* Allocate memory for the data_ptr */
    data_ptr = (Data*) malloc(sizeof(Data));

    /* Check if allocation was successful */
    if (data_ptr == NULL) {
        printf("Memory allocation failed. Exiting program.\n");
        exit(1);
    }

    /* Allocate memory for the string and assign it to the data_ptr */
    data_ptr->string = (char*) malloc(sizeof(char) * 20);

    /* Check if allocation was successful */
    if (data_ptr->string == NULL) {
        printf("Memory allocation failed. Exiting program.\n");
        exit(1);
    }

    /* Initialize the string */
    data_ptr->string = "Hello World!";

    /* Print the string */
    printf("%s\n", data_ptr->string);

    /* Free the allocated memory */
    free(data_ptr->string);
    free(data_ptr);

    return 0;
}