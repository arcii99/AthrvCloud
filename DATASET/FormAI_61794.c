//FormAI DATASET v1.0 Category: File handling ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function to write an integer to a file.
void writeIntToFile(FILE *file, int num) {
    fprintf(file, "%d\n", num);
}

// Function to read an integer from a file.
int readIntFromFile(FILE *file) {
    int num;
    fscanf(file, "%d", &num);
    return num;
}

int main() {
    FILE *file;

    // Open the file for writing.
    file = fopen("numbers.txt", "w");

    // Write some integers to the file.
    writeIntToFile(file, 10);
    writeIntToFile(file, 20);
    writeIntToFile(file, 30);
    writeIntToFile(file, 40);
    writeIntToFile(file, 50);

    // Close the file.
    fclose(file);

    // Open the file for reading.
    file = fopen("numbers.txt", "r");

    // Read the integers from the file.
    int num1 = readIntFromFile(file);
    int num2 = readIntFromFile(file);
    int num3 = readIntFromFile(file);
    int num4 = readIntFromFile(file);
    int num5 = readIntFromFile(file);

    // Close the file.
    fclose(file);

    // Print the integers to the console.
    printf("%d\n%d\n%d\n%d\n%d\n", num1, num2, num3, num4, num5);

    return 0;
}