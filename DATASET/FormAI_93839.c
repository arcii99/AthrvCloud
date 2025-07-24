//FormAI DATASET v1.0 Category: File handling ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char fileName[256];
 
    printf("Enter name of file to create: ");
    scanf("%s", fileName);
 
    file = fopen(fileName, "w");
 
    if (file == NULL) {
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }
 
    printf("File created successfully!\n");
    
    char message[1000];
    printf("Enter message to write to file: ");
    scanf(" %[^\n]s", message);
 
    fprintf(file, "%s", message);
 
    fclose(file);
    
    printf("Message has been written to file.\n");
    
    file = fopen(fileName, "r");
    
    if (file == NULL) {
        printf("Unable to open file.\n");
        exit(EXIT_FAILURE);
    }
    
    printf("Reading contents from file:\n\n");
    
    char ch;
    while((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }
    
    fclose(file);
    
    printf("\n\nEnd of file!\n");
    
    return 0;
}