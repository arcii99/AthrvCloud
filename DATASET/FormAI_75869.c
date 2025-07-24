//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FORTUNES 10
#define MAX_FORTUNE_LEN 100

char fortunes[MAX_FORTUNES][MAX_FORTUNE_LEN];

int load_fortunes() {
    FILE *file;
    char filename[] = "fortunes.dat";
    int num_fortunes = 0;

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        return 0;
    }

    char line[MAX_FORTUNE_LEN];

    // Read contents of file into the fortunes array
    while (fgets(line, MAX_FORTUNE_LEN, file) != NULL) {
        if (num_fortunes == MAX_FORTUNES) {
            printf("Warning: maximum number of fortunes reached (%d)\n", MAX_FORTUNES);
            break;
        }

        // Remove newline character at end of line
        line[strcspn(line, "\n")] = 0;

        strcpy(fortunes[num_fortunes], line);
        num_fortunes++;
    }

    fclose(file);

    return num_fortunes;
}

int main(void) {
    int num_fortunes = load_fortunes();

    if (num_fortunes == 0) {
        return 1;
    }

    srand(time(NULL));

    printf("Welcome to the automated fortune teller!\n\n");

    while (1) {
        printf("Enter your question (or 'quit' to exit): ");
        char input[100];
        fgets(input, 100, stdin);

        if (strstr(input, "quit") != NULL) {
            break;
        }

        int fortune_index = rand() % num_fortunes;
        char* fortune = fortunes[fortune_index];

        printf("\n%s\n\n", fortune);
    }

    printf("Thanks for using the automated fortune teller!\n");

    return 0;
}