//FormAI DATASET v1.0 Category: Data mining ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUMBERS_PER_LINE 100

int main() {
    FILE *fp;
    char *filename = "numbers.txt";
    char line[MAX_LINE_LENGTH];
    int line_counter = 0;
    int num_counter = 0;
    int numbers[MAX_NUMBERS_PER_LINE];
    
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    
    // Read each line of the file
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        line_counter++;
        char *token = strtok(line, " "); // Split line by space
        
        // Parse each number in the line
        while (token != NULL) {
            int num = atoi(token); // Convert token to int
            numbers[num_counter++] = num;
            token = strtok(NULL, " ");
        }
        
        // Calculate sum and average of numbers in line
        int sum = 0;
        for (int i = 0; i < num_counter; i++) {
            sum += numbers[i];
        }
        float average = (float)sum / num_counter;
        
        printf("Line %d: Sum = %d, Average = %.2f\n", line_counter, sum, average);
        
        num_counter = 0; // Reset counter for next line
        
        // If we've reached the end of the file, print overall sum and average
        if (feof(fp)) {
            int total_sum = 0;
            int num_numbers = (line_counter - 1) * MAX_NUMBERS_PER_LINE + num_counter; // Calculate total number of numbers in file
            for (int i = 0; i < num_counter; i++) {
                total_sum += numbers[i];
            }
            float overall_average = (float)total_sum / num_numbers;
            printf("Overall Sum = %d, Overall Average = %.2f\n", total_sum, overall_average);
        }
    }
    
    fclose(fp);
    return 0;
}