//FormAI DATASET v1.0 Category: File handling ; Style: happy
#include <stdio.h>
#include <string.h>

// Define the max length of each line
#define MAX_LINE_LENGTH 100

// Define the max number of lines in the file
#define MAX_NUM_LINES 100

int main() {
    // Open the file for writing
    FILE *file = fopen("happy_file.txt", "w");

    // If the file cannot be opened, return an error.
    if (!file) {
        printf("Error opening file!");
        return 1;
    }

    // Define an array of happy messages
    char *happy_messages[] = {
        "Life is beautiful!",
        "Smile and the world will smile back at you!",
        "Every day is a new opportunity to be happy!",
        "You are amazing just the way you are!",
        "Happiness is contagious!",
        "You deserve all the happiness in the world!",
        "Dream big and believe in yourself!",
        "Be kind, spread happiness!",
        "You can do anything you set your mind to!",
        "Life is too short to be anything but happy!"
    };

    // Write the happy messages to the file
    for (int i = 0; i < 10; i++) {
        fprintf(file, "%s\n", happy_messages[i]);
    }

    // Close the file
    fclose(file);

    // Open the file for reading
    file = fopen("happy_file.txt", "r");

    // If the file cannot be opened, return an error.
    if (!file) {
        printf("Error opening file!");
        return 1;
    }

    // Read the contents of the file and write them to the console
    char line[MAX_LINE_LENGTH];
    int line_count = 0;
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL && line_count < MAX_NUM_LINES) {
        line[strcspn(line, "\n")] = 0; // Remove the newline character
        printf("%s\n", line);
        line_count++;
    }

    // Close the file
    fclose(file);

    return 0;
}