//FormAI DATASET v1.0 Category: File handling ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char c;

    // Opening file for writing
    fp = fopen("example.txt","w");
    if(fp == NULL) {
        printf("Error in opening file.");
        exit(1);
    }

    printf("Please enter text: ");

    // writing text to file
    while((c = getchar()) != '\n')
        putc(c, fp);

    fclose(fp);

    // Opening file again for reading
    fp = fopen("example.txt","r");
    if(fp == NULL) {
        printf("Error in opening file.");
        exit(1);
    }

    printf("\nThe contents of the file are: \n");

    // Displaying file contents
    while((c = getc(fp)) != EOF)
        putchar(c);
    
    fclose(fp); // close the file
    
    return 0;
}