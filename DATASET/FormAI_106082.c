//FormAI DATASET v1.0 Category: Text processing ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LENGTH 100

char *lines[MAX_LINES];
int num_lines = 0;

void read_input() {
    char input[MAX_LENGTH];
    while (fgets(input, MAX_LENGTH, stdin) != NULL) {
        lines[num_lines] = malloc(strlen(input) + 1);
        strcpy(lines[num_lines], input);
        num_lines++;
    }
}

void print_output() {
    for (int i = 0; i < num_lines; i++) {
        printf("%s", lines[i]);
    }
}

void sort_lines() {
    char *temp;
    for (int i = 0; i < num_lines - 1; i++) {
        for (int j = i + 1; j < num_lines; j++) {
            if (strcmp(lines[i], lines[j]) > 0) {
                temp = lines[i];
                lines[i] = lines[j];
                lines[j] = temp;
            }
        }
    }
}

int main() {
    printf("Enter text to sort alphabetically:\n");
    read_input();
    sort_lines();
    printf("\nSorted text:\n");
    print_output();
    return 0;
}