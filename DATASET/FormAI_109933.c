//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

// Function Declarations
void beautify(char* html_file);

int main() {
    char* html_file = "example.html";
    beautify(html_file);
    return 0;
}

void beautify(char* html_file) {
    char current_char;
    char previous_char = '\0';
    int spaces = 0;

    FILE* input_file = fopen(html_file, "r");
    FILE* output_file = fopen("beautified.html", "w");

    // check if file is opened successfully
    if (input_file == NULL || output_file == NULL) {
        printf("Failed to open file!\n");
        exit(1);
    }

    while ((current_char = fgetc(input_file)) != EOF) {
        if (current_char == ' ') {
            spaces++;
            continue;
        }
        if (current_char == '<') {
            if (previous_char != '\n') {
                fprintf(output_file, "\n");
            }
            fprintf(output_file, "%*c", spaces, ' ');
        }
        fprintf(output_file, "%c", current_char);
        if (current_char == '>') {
            fprintf(output_file, "\n");
        }
        previous_char = current_char;
    }

    // close files
    fclose(input_file);
    fclose(output_file);
}