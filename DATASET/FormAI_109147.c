//FormAI DATASET v1.0 Category: File handling ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char file_name[] = "example.txt";
    char line[100];
    
    // Open the file in write mode
    fp = fopen(file_name, "w");
    
    // Check if the file was opened successfully
    if (fp == NULL) {
        printf("Error opening file %s\n", file_name);
        exit(1);
    }
    
    // Write some lines to the file
    fprintf(fp, "This is line 1\n");
    fprintf(fp, "This is line 2\n");
    fprintf(fp, "This is line 3\n");
    fprintf(fp, "This is line 4\n");
    fprintf(fp, "This is line 5\n");
    
    // Close the file
    fclose(fp);
    
    // Open the file in read mode
    fp = fopen(file_name, "r");
    
    // Check if the file was opened successfully
    if (fp == NULL) {
        printf("Error opening file %s\n", file_name);
        exit(1);
    }
    
    // Read the file line by line and print it to the console
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    
    // Close the file
    fclose(fp);
    
    return 0;
}