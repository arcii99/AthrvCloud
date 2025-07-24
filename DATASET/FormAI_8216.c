//FormAI DATASET v1.0 Category: HTML beautifier ; Style: grateful
#include<stdio.h>
#include<stdlib.h>

void beautify(char* input_file, char* output_file)
{
    FILE* in = fopen(input_file, "r");
    FILE* out = fopen(output_file, "w");

    if (in == NULL || out == NULL) {
        printf("Failed to open file.");
        exit(1);
    }
    
    int indent = 0, prev_char = '\0', curr_char;
    while ((curr_char = fgetc(in)) != EOF) {
        if (prev_char == '<' && curr_char != '/') {
            fprintf(out, "\n");
            for (int i = 0; i < indent; i++) {
                fprintf(out, "  ");
            }
            indent++;
        } else if (prev_char == '/' && curr_char == '>') {
            indent--;
        }
        if (prev_char != '>' && curr_char != '>') {
            fprintf(out, "%c", curr_char);
        }
        prev_char = curr_char;
    }
    fclose(in);
    fclose(out);
    printf("Beautification complete.");
}

int main()
{
    char* input_file = "input.html";
    char* output_file = "output.html";

    beautify(input_file, output_file);

    return 0;
}