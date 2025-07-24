//FormAI DATASET v1.0 Category: File handling ; Style: detailed
// This program takes user input for names and ages, stores them in a file, and then reads and prints them out.

#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[20];
    printf("Please enter filename: ");
    scanf("%s", filename);

    // Open file for writing
    FILE *fptr = fopen(filename, "w");
    if (fptr == NULL) {
        printf("Unable to create file.");
        exit(1);
    }

    // Get user input for names and ages
    int count = 0;
    char name[20];
    int age;
    printf("Enter name and age (Enter -1 to quit):\n");
    scanf("%s %d", name, &age);
    while (strcmp(name, "-1") != 0) {
        fprintf(fptr, "%s %d\n", name, age);
        count++;
        scanf("%s %d", name, &age);
    }

    fclose(fptr);

    // Open file for reading
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Unable to open file.");
        exit(1);
    }

    // Read and print data from file
    printf("\nData in file:\n\n");
    for (int i = 0; i < count; i++) {
        fscanf(fptr, "%s %d", name, &age);
        printf("%s is %d years old.\n", name, age);
    }

    fclose(fptr);

    return 0;
}