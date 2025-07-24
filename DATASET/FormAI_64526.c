//FormAI DATASET v1.0 Category: Log analysis ; Style: invasive
#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fptr;
    char filename[100], c;
    int count = 0;

    printf("Enter the filename to open: ");
    scanf("%s", filename);

    // Open file
    fptr = fopen(filename, "r");

    // Check if file exists
    if (fptr == NULL){
        printf("Error: File does not exist!\n");
        exit(0);
    }

    // Read the contents of the file
    while ((c = fgetc(fptr)) != EOF){
        if(c == '\n')
            count++; // Count number of lines
    }

    // Print the result
    printf("Number of lines in %sfile is: %d\n", filename, count);

    // Close file
    fclose(fptr);

    return 0;
}