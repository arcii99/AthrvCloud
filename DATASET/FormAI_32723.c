//FormAI DATASET v1.0 Category: Error handling ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

void handleError(char *errorMessage){
    printf("Error: %s\n",errorMessage);
    exit(EXIT_FAILURE);
}

int main(){
    FILE *file = NULL;
    int num1, num2, result;
    char fileName[] = "input.txt";
    
    // Open the file only if it exists
    if ((file = fopen(fileName, "r")) == NULL) {
        handleError("Cannot open the file!");
    }
    
    // Read two integers from the file
    if(fscanf(file, "%d %d", &num1, &num2) != 2){
        handleError("Failed to read integers from file!");
    }
    
    // Perform division and check for divide-by-zero error
    if(num2 == 0){
        handleError("Cannot divide by zero!");
    } else{
        result = num1 / num2;
    }
    
    // Output the result to the console
    printf("%d\n", result);
    
    // Close the file
    if (fclose(file) == EOF) {
        handleError("Cannot close the file!");
    }
    
    return 0;
}