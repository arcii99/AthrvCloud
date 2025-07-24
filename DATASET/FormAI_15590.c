//FormAI DATASET v1.0 Category: Error handling ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

void errorHandler(const char* errorMsg) {
    printf("\nAn error occurred: %s\nPlease try again later.\n", errorMsg);
    exit(EXIT_FAILURE);
}

int main() {
    FILE* file = NULL;
    char fileName[20];
    printf("Please enter the name of the file to open: ");
    scanf("%s", fileName);

    // Try to open the file
    file = fopen(fileName, "r");
    if (file == NULL) {
        errorHandler("Could not open the file.");
    }

    // Read the file line by line
    char buffer[100];
    while (fgets(buffer, 100, file)) {
        printf("%s", buffer);
    }

    // Close the file
    if (fclose(file) != 0) {
        errorHandler("Could not close the file.");
    }

    printf("\nFile successfully read!\n");
    return 0;
}