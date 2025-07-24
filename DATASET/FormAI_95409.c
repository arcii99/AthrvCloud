//FormAI DATASET v1.0 Category: Log analysis ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LINE_SIZE 1000

int main(int argc, char *argv[]) {
    // checking if the required number of arguments are passed
    if (argc != 2) {
        printf("Error: Invalid number of arguments. Usage: ./program <file_path>\n");
        return 1;
    }
    
    // opening the file
    FILE *fptr = fopen(argv[1], "r");
    
    // checking if file exists and readable
    if (fptr == NULL) {
        printf("Error: File not found or cannot be opened\n");
        return 1;
    }
    
    int total_lines = 0;
    int error_count = 0;
    char line[LINE_SIZE];
    
    // looping through each line in the file
    while (fgets(line, LINE_SIZE, fptr) != NULL) {
        total_lines++;
        
        // checking if the line contains "error"
        if (strstr(line, "error") != NULL) {
            error_count++;
            printf("Line %d: %s", total_lines, line);
        }
    }
    
    if (total_lines == 0) {
        printf("Error: File is empty\n");
        return 1;
    }
    
    // calculating and printing the error percentage
    float error_percentage = ((float)error_count / total_lines) * 100;
    printf("\nTotal Lines: %d\nError Lines: %d\nError Percentage: %.2f%%\n", 
    total_lines, error_count, error_percentage);
    
    // closing the file
    fclose(fptr);
    
    return 0;
}