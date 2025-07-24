//FormAI DATASET v1.0 Category: Error handling ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10

void generate_error(int error_code) {
    switch (error_code) {
        case 1:
            printf("ERROR: Invalid input detected\n");
            break;
        case 2:
            printf("ERROR: Memory allocation failed\n");
            break;
        case 3:
            printf("ERROR: File not found\n");
            break;
        // Add more error codes and messages as needed
        default:
            printf("ERROR: Unspecified error\n");
            break;
    }
}

int main() {
    char input[LENGTH];
    FILE *fp;
    char *ptr;
    int num, sum = 0;
    
    // Read input from user
    printf("Enter a comma-separated list of integers (no spaces): ");
    fgets(input, LENGTH, stdin);
    
    // Check for invalid input
    for (int i = 0; i < LENGTH; i++) {
        if (input[i] == '\n') {
            input[i] = '\0';
            break;
        } else if (input[i] < '0' || input[i] > '9') {
            generate_error(1);
            return 1;
        }   
    }
    
    // Allocate memory for integer array
    int *arr = (int *)malloc(strlen(input) * sizeof(int));
    
    // Check if memory allocation failed
    if (arr == NULL) {
        generate_error(2);
        return 1;
    }
    
    // Convert comma-separated string to integer array
    ptr = strtok(input, ",");
    int i = 0;
    while (ptr != NULL) {
        num = atoi(ptr);
        if (num == 0 && ptr[0] != '0') {
            generate_error(1);
            return 1;
        } else {
            arr[i++] = num;
        }
        ptr = strtok(NULL, ",");
    }
    
    // Open file for writing
    fp = fopen("output.txt", "w");
    
    // Check if file was opened successfully
    if (fp == NULL) {
        free(arr);
        generate_error(3);
        return 1;
    }
    
    // Calculate sum of integers and write to file
    for (int j = 0; j < i; j++) {
        sum += arr[j];
        fprintf(fp, "%d\n", arr[j]);
    }
    
    // Close file and free memory
    fclose(fp);
    free(arr);
    
    printf("Sum of integers: %d\n", sum);
    
    return 0;
}