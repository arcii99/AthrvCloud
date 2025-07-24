//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Print a row of ASCII art characters */
void print_art_row(char *row) {
    printf("%s\n", row);
}

/* Generate ASCII art from input text */
void generate_ascii_art(char *text) {

    /* Define ASCII art characters */
    char *art_chars[] = {
        "  _____ _____    ____   _____ _      _____ ____    _____ _  ___",
        " |_   _/ ____|  / __ \\ / ____| |    |_   _/ __ \\  |_   _/ |/ _ \\",
        "   | || |      | |  | | (___ | |      | || |  | |   | | | | (_) |",
        "   | || |      | |  | |\\___ \\| |      | || |  | |   | | | |> _ <",
        "  _| || |____  | |__| |____) | |____ _| || |__| |  _| |_| | (_) |",
        " |____\\_____|  \\____/|_____/|______|____\\____/  |____/|_|\\___/"
    };

    /* Calculate the number of rows in the ASCII art */
    int num_rows = sizeof(art_chars) / sizeof(char *);

    /* Create a new string to hold the final output */
    char *output = malloc(strlen(art_chars[0]) * strlen(text) * num_rows);

    /* Loop through each row of the ASCII art */
    for (int row = 0; row < num_rows; row++) {

        /* Loop through each character in the input text */
        for (int i = 0; i < strlen(text); i++) {

            /* Get the ASCII value of the character at this position */
            int ascii = (int) text[i];

            /* If the ASCII value is outside of the printable range, default to space */
            if (ascii < 32 || ascii > 126) {
                ascii = 32;
            }

            /* Calculate the index of the ASCII art character to use */
            int index = (ascii - 32) * strlen(art_chars[0]);

            /* Copy the appropriate section of the ASCII art to the output */
            strcat(output, &art_chars[row][index]);
        }

        /* Print the current row of ASCII art */
        print_art_row(output);

        /* Reset the output string */
        memset(output, 0, strlen(output));
    }

    /* Free the memory used by the output string */
    free(output);
}

int main() {

    /* Get input text from the user */
    char input[100];
    printf("Enter any text: ");
    fgets(input, 100, stdin);

    /* Remove trailing newline character from input */
    input[strcspn(input, "\n")] = 0;

    /* Generate ASCII art from input text */
    generate_ascii_art(input);

    return 0;
}