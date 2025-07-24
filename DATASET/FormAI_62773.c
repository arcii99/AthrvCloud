//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000
#define MAX_ALPHABET_LENGTH 26
#define MAX_CHAR_PER_LINE 100

typedef struct {
    char letter;
    int count;
} LetterCount;

// Function to read input from a file line by line and return the total number of lines
int readInput(char inputFile[], char input[][MAX_CHAR_PER_LINE]) {
    int lineCount = 0;
    FILE *fp = fopen(inputFile, "r");
    if (fp == NULL) {
        printf("ERROR: Failed to open input file \"%s\"\n", inputFile);
        return 0;
    }
    char line[MAX_CHAR_PER_LINE];
    while (fgets(line, MAX_CHAR_PER_LINE, fp) != NULL) {
        strcpy(input[lineCount], line);
        lineCount++;
    }
    fclose(fp);
    return lineCount;
}

// Function to calculate the frequency count of each letter in the given input
void countLetters(char input[MAX_INPUT_LENGTH], LetterCount letterCount[MAX_ALPHABET_LENGTH], int *totalLetters) {
    for (int i = 0; i < strlen(input); i++) {
        char c = input[i];
        if (c >= 65 && c <= 90) {
            letterCount[c - 65].letter = c;
            letterCount[c - 65].count += 1;
            (*totalLetters) += 1;
        }
        else if (c >= 97 && c <= 122) {
            letterCount[c - 97].letter = c;
            letterCount[c - 97].count += 1;
            (*totalLetters) += 1;
        }
    }
}

// Function to sort the letter frequency count array in descending order of frequency count
void sortLetterCountArray(LetterCount letterCount[MAX_ALPHABET_LENGTH]) {
    for (int i = 0; i < MAX_ALPHABET_LENGTH - 1; i++) {
        for (int j = i + 1; j < MAX_ALPHABET_LENGTH; j++) {
            if (letterCount[i].count < letterCount[j].count) {
                LetterCount temp = letterCount[i];
                letterCount[i] = letterCount[j];
                letterCount[j] = temp;
            }
        }
    }
}

// Function to print the letter frequency count array in a human-readable format
void printLetterCountArray(LetterCount letterCount[MAX_ALPHABET_LENGTH], int totalLetters) {
    printf("Letter Frequency Count:\n");
    printf("------------------------\n");
    float percentage;
    for (int i = 0; i < MAX_ALPHABET_LENGTH; i++) {
        if (letterCount[i].count > 0) {
            percentage = ((float) letterCount[i].count / totalLetters) * 100;
            printf("%c: %d (%.2f%%)\n", letterCount[i].letter, letterCount[i].count, percentage);
        }
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("ERROR: Invalid number of arguments\n");
        printf("USAGE: %s <input_file>\n", argv[0]);
        return 1;
    }
    char input[MAX_INPUT_LENGTH];
    char inputFile[MAX_CHAR_PER_LINE];
    LetterCount letterCount[MAX_ALPHABET_LENGTH] = {0};
    int totalLetters = 0;
    memset(input, 0, sizeof(input)); // Initialize input array with null characters
    memset(inputFile, 0, sizeof(inputFile)); // Initialize inputFile array with null characters
    printf("Enter name of input file: ");
    fgets(inputFile, MAX_CHAR_PER_LINE, stdin);
    inputFile[strcspn(inputFile, "\n")] = '\0'; // Remove trailing newline character from input
    int lineCount = readInput(inputFile, input); // Read input from file and get total number of lines
    if (lineCount == 0) return 1; // If input file read failed, return error code
    for (int i = 0; i < lineCount; i++) {
        countLetters(input[i], letterCount, &totalLetters); // Calculate the frequency count of each letter in each line of input
    }
    sortLetterCountArray(letterCount); // Sort the letter frequency count array in descending order of frequency count
    printLetterCountArray(letterCount, totalLetters); // Print the letter frequency count array in a human-readable format
    return 0;
}