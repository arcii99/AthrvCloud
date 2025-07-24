//FormAI DATASET v1.0 Category: File handling ; Style: bold
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file_pointer;
    char filename[] = "sample_textfile.txt";
    char buffer[1000];
    
    // Write to the file
    file_pointer = fopen(filename, "w");
    if (file_pointer == NULL) {
        printf("Unable to open file!\n");
        exit(1);
    }
    printf("Enter text to write to the file:\n");
    scanf("%[^\n]", buffer);
    fprintf(file_pointer, "%s", buffer);
    printf("\nSuccessfully wrote to the file %s!\n", filename);
    fclose(file_pointer);
    
    // Read from the file
    file_pointer = fopen(filename, "r");
    if (file_pointer == NULL) {
        printf("Unable to open file!\n");
        exit(1);
    }
    printf("\nThe contents of the file %s are:\n", filename);
    while(fgets(buffer, 1000, file_pointer)) {
        printf("%s", buffer);
    }
    fclose(file_pointer);
    
    return 0;
}