//FormAI DATASET v1.0 Category: Data recovery tool ; Style: authentic
#include<stdio.h>
#include<stdlib.h>

int main() {
    FILE *fp;               // Pointer to the file
    char file_name[20];     // Name of the file
    char ch;                // Character variable to read characters from the file
    
    printf("Enter the file name: ");
    scanf("%s", file_name);
    
    fp = fopen(file_name, "r");
    
    if(fp == NULL) {        // If the file doesn't exist or cannot be opened
        printf("Unable to open the file.\n");
        exit(0);
    }
    
    printf("\nContents of the file:\n\n");
    
    while((ch = fgetc(fp)) != EOF) {    // Read characters from the file until end-of-file
        putchar(ch);
    }
    
    fclose(fp);
    
    return 0;
}