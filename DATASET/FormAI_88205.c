//FormAI DATASET v1.0 Category: Error handling ; Style: energetic
#include<stdio.h>
#include<stdlib.h>

// A function to handle the error
void errorHandling(const char* msg)
{
    fprintf(stderr, "%s\n", msg); // prints the error message
    exit(EXIT_FAILURE); // exits the program with failure status
}

// A function to divide two numbers
int divide(int a, int b)
{
    if(b == 0) // if divisor is zero
        errorHandling("Cannot divide by zero!");

    return a/b;
}

int main()
{
    int a = 10, b = 2;
    int result;

    // handling error when dividing by zero
    result = divide(a, 0);
    printf("%d / %d = %d\n", a, b, result);

    // handling error when malloc fails to allocate memory
    int* arr = (int*) malloc(5*sizeof(int));
    if(arr == NULL)
        errorHandling("Memory allocation failed!"); // prints error message and exits with failure status

    // accessing array out of bounds to trigger segmentation fault
    printf("Enter a number to access array out of bounds: ");
    int index;
    scanf("%d", &index);
    printf("Element at index %d: %d\n", index, arr[index]);

    // freeing up allocated memory
    free(arr);

    return 0;
}