//FormAI DATASET v1.0 Category: File handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fptr;
    char filename[50], content[200];

    printf("Enter the filename to write to: ");
    scanf("%s", filename);

    fptr = fopen(filename, "w");

    if(fptr == NULL){
        printf("Error opening file!");
        exit(1);
    }

    printf("\nEnter content for the file: ");
    scanf(" %[^\n]s", content);

    fprintf(fptr, "%s", content);
    fclose(fptr);

    printf("File %s created successfully with content:\n%s", filename, content);

    // READ FILE

    char c;

    fptr = fopen(filename, "r");

    printf("\nContent of the file:\n");

    if(fptr){
        while((c = getc(fptr)) != EOF){
            putchar(c);
        }
        fclose(fptr);
    }
    else {
        printf("Error opening file!");
        exit(1);
    }

    return 0;
}