//FormAI DATASET v1.0 Category: File handling ; Style: energetic
#include <stdio.h>

int main() {
    printf("Let's create a new file and write into it!\n");
    
    FILE *fptr;
    char filename[20];
    char txt[50];
    
    printf("Enter the filename (with extension): ");
    scanf("%s", filename);

    fptr = fopen(filename, "w");
    
    if (fptr == NULL) {
        printf("Error! Couldn't create the file.");
        return 0;
    }

    printf("Enter the text to be written in the file:\n");
    scanf("%s", txt);

    fprintf(fptr, "%s", txt);
    fclose(fptr);

    printf("File created and data written successfully!\n");

    return 0;
}