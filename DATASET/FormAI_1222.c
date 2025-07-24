//FormAI DATASET v1.0 Category: Data mining ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 256 // Maximum line size for input file
#define MAX_NUM_LETTERS 26 // Number of letters in English alphabet

// Function to calculate the occurrence of each letter in the input file
void calculateFrequency(char* inputFile, int* frequency)
{
    FILE* fp;
    char line[MAX_LINE_SIZE], *ptr;

    fp = fopen(inputFile, "r"); // Open input file for reading

    if (fp == NULL) // Error checking
    {
        printf("Error: Unable to open input file!");
        exit(1);
    }

    while (fgets(line, MAX_LINE_SIZE, fp) != NULL) // Read input file line by line
    {
        ptr = line;

        while (*ptr != '\0') // Traverse each line in the input file
        {
            if (*ptr >= 'A' && *ptr <= 'Z') // Only count uppercase letters
            {
                frequency[*ptr - 'A']++; // Increment frequency of corresponding letter
            }
            ptr++;
        }
    }

    fclose(fp); // Close input file
}

// Function to print the letter frequency in descending order from the input file
void printFrequency(int* frequency)
{
    int i, maxFrequency = 0, maxIndex = -1;

    printf("Letter Frequency in Descending Order:\n");

    for (i = 0; i < MAX_NUM_LETTERS; i++) // Traverse the frequency array to find the maximum value in each iteration
    {
        maxFrequency = 0;

        for (int j = 0; j < MAX_NUM_LETTERS; j++)
        {
            if (frequency[j] > maxFrequency)
            {
                maxFrequency = frequency[j]; // Update maximum frequency
                maxIndex = j; // Update index of maximum frequency
            }
        }

        if (maxFrequency > 0) // Print only if frequency is greater than zero
        {
            printf("%c: %d\n", maxIndex + 'A', maxFrequency); // Print corresponding letter and its frequency
            frequency[maxIndex] = 0; // Set current maximum frequency to zero to find next highest frequency
        }
        else // Break the loop if all frequencies have been printed
        {
            break;
        }
    }
}

int main()
{
    int frequency[MAX_NUM_LETTERS] = { 0 }; // Initialize all elements of frequency array to zero

    calculateFrequency("input.txt", frequency); // Calculate letter frequency from input file
    printFrequency(frequency); // Print letter frequency in descending order

    return 0;
}