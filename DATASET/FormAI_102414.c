//FormAI DATASET v1.0 Category: HTML beautifier ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This function takes an input file name, an output file name, and the number of spaces to be used as tabs
void beautify(char* input_file, char* output_file, int num_spaces) {
    FILE *in_fp, *out_fp; // input file and output file pointers
    int c, num_tabs = 0, i;

    // Open the input file in read mode
    in_fp = fopen(input_file, "r");
    if(in_fp == NULL) {
        printf("Error: Could not open input file\n");
        return;
    }

    // Open the output file in write mode
    out_fp = fopen(output_file, "w");
    if(out_fp == NULL) {
        printf("Error: Could not open output file\n");
        fclose(in_fp);
        return;
    }

    // Read the input file character by character
    while((c = fgetc(in_fp)) != EOF) {
        // Increase the number of tabs if a new line character is encountered
        if(c == '\n') {
            fprintf(out_fp, "\n");
            for(i = 0; i < num_tabs; i++) {
                fprintf(out_fp, " ");
            }
        }
        // Decrease the number of tabs if a closing brace is encountered
        else if(c == '}') {
            num_tabs--;
            fprintf(out_fp, "}\n");
            for(i = 0; i < num_tabs; i++) {
                fprintf(out_fp, " ");
            }
        }
        // Write the character to the output file
        else {
            fputc(c, out_fp);
        }
        // Increase the number of tabs if an opening brace is encountered
        if(c == '{') {
            num_tabs++;
            fprintf(out_fp, "{\n");
            for(i = 0; i < num_tabs; i++) {
                fprintf(out_fp, " ");
            }
        }
    }

    // Close the file pointers 
    fclose(in_fp);
    fclose(out_fp);
}

int main() {
    char input_file[] = "input.html";
    char output_file[] = "output.html";
    int num_spaces = 2;

    beautify(input_file, output_file, num_spaces);

    return 0;
}