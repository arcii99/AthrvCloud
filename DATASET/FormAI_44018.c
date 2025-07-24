//FormAI DATASET v1.0 Category: File handling ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILENAME "decentralized-example.txt" // define the filename to use

// random data to write to file
const char* DATA[] = {"apple", "banana", "cherry", "date", "elderberry", "fig"};

// function to write data to a file
void writeDataToFile(char* data) {
    FILE* file = fopen(FILENAME, "a"); // open file for appending
    if (file == NULL) {
        printf("Error: Could not open file!\n");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "%s\n", data);
    fclose(file);
}

// function to read data from a file
void readDataFromFile() {
    FILE* file = fopen(FILENAME, "r"); // open file for reading
    if (file == NULL) {
        printf("Error: Could not open file!\n");
        exit(EXIT_FAILURE);
    }
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }
    fclose(file);
}

int main() {
    srand(time(NULL)); // seed random number generator

    int numDataPoints = rand() % 10 + 1; // generate a random number of data points to write

    // write random data to file
    for (int i = 0; i < numDataPoints; i++) {
        int randomIndex = rand() % (sizeof(DATA) / sizeof(*DATA));
        writeDataToFile((char*) DATA[randomIndex]);
    }

    // read data from file
    printf("Data in file:\n");
    readDataFromFile();

    return 0;
}