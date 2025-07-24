//FormAI DATASET v1.0 Category: File handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "numbers.txt"

int main() {
    FILE *fptr;
    char line[100];
    int num, sum = 0, count = 0, max = 0, min = 0, first = 0;
    float avg = 0.0;

    // Open file for reading
    fptr = fopen(FILENAME, "r");
    if (fptr == NULL) {
        printf("Error opening file %s\n", FILENAME);
        return 1;
    }

    // Read each line from file and do calculations
    while (fgets(line, sizeof(line), fptr)) {
        num = atoi(line);
        sum += num;
        count++;

        if (first == 0) {
            max = num;
            min = num;
            first = 1;
        }
        else {
            if (num > max) {
                max = num;
            }
            if (num < min) {
                min = num;
            }
        }
    }

    // Close file
    fclose(fptr);

    // Calculate average
    if (count > 0) {
        avg = (float)sum / (float)count;
    }

    // Print results
    printf("Sum of all numbers: %d\n", sum);
    printf("Average of all numbers: %.2f\n", avg);
    printf("Maximum number: %d\n", max);
    printf("Minimum number: %d\n", min);
    printf("Total numbers: %d\n", count);

    return 0;
}