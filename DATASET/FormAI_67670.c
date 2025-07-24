//FormAI DATASET v1.0 Category: Ebook reader ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A struct to represent an ebook
typedef struct {
    char title[100];
    char author[100];
    int year;
    char publisher[100];
    char filename[100];
} Ebook;

// A function to read an ebook from a file
Ebook read_ebook_from_file(char *filename) {
    Ebook ebook;

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    fscanf(file, "%[^\n]\n", ebook.title);
    fscanf(file, "%[^\n]\n", ebook.author);
    fscanf(file, "%d\n", &ebook.year);
    fscanf(file, "%[^\n]\n", ebook.publisher);
    fscanf(file, "%[^\n]\n", ebook.filename);

    fclose(file);

    return ebook;
}

// A function to display an ebook
void display_ebook(Ebook ebook) {
    printf("%s\n", ebook.title);
    printf("by %s\n", ebook.author);
    printf("Published by %s in %d\n", ebook.publisher, ebook.year);
}

// A function to read user input
void read_user_input(char *input) {
    printf("Enter command: ");
    fgets(input, 100, stdin);
    strtok(input, "\n");
}

// A function to print all ebooks in a directory
void print_ebooks_in_directory(char *directory) {
    printf("Ebooks in %s directory:\n", directory);

    FILE *fp;
    char command[100];

    sprintf(command, "ls %s/*.txt", directory);

    fp = popen(command, "r");
    if (fp == NULL) {
        printf("Error: Could not open directory %s\n", directory);
        return;
    }

    char filename[100];

    while (fgets(filename, sizeof(filename), fp) != NULL) {
        strtok(filename, "\n");

        Ebook ebook = read_ebook_from_file(filename);
        printf("%s\n", ebook.title);
    }

    pclose(fp);
}

// A function to read an ebook from a file and display it
void display_ebook_from_file(char *filename) {
    Ebook ebook = read_ebook_from_file(filename);
    display_ebook(ebook);
}

int main() {
    char input[100];

    while (1) {
        read_user_input(input);

        // List all ebooks in a directory
        if (strcmp(input, "list") == 0) {
            print_ebooks_in_directory("ebooks");
        }

        // Display an ebook
        else if (strncmp(input, "display", 7) == 0) {
            char *filename = input + 8;
            display_ebook_from_file(filename);
        }

        // Quit the program
        else if (strcmp(input, "quit") == 0) {
            printf("Goodbye!\n");
            break;
        }

        // Invalid command
        else {
            printf("Invalid command!\n");
        }
    }

    return 0;
}