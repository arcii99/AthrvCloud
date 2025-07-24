//FormAI DATASET v1.0 Category: Error handling ; Style: content
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    FILE *fptr;
    char filename[100];
    printf("Enter the name of the file you want to open (with extension): ");
    scanf("%s", filename);
    fptr = fopen(filename, "r");
    if(fptr == NULL) {
        printf("Unable to open file '%s'. Error code: %d.\n", filename, errno);
        perror("Error");
        exit(EXIT_FAILURE);
    } else {
        printf("File '%s' opened successfully.\n", filename);
        fclose(fptr);
        return 0;
    }
}