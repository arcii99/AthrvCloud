//FormAI DATASET v1.0 Category: HTML beautifier ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautify(char *filename) {
    FILE *file_ptr;
    int temp_char, last_char = ' ';
    file_ptr = fopen(filename, "r+");
    if (!file_ptr) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    while ((temp_char = fgetc(file_ptr)) != EOF) {
        if (temp_char == '<') {
            fputc(temp_char, stdout);
            fputc('\n', stdout);
            last_char = temp_char;
        } else if (temp_char == '>') {
            fputc('\n', stdout);
            fputc(temp_char, stdout);
            last_char = temp_char;
        } else if (temp_char == ' ' || temp_char == '\t' || temp_char == '\n') {
            if (last_char == '<' || last_char == '>') {
                continue;
            } else if (last_char != ' ' && last_char != '\t' && last_char != '\n') {
                fputc(' ', stdout);
            }
        } else {
            fputc(temp_char, stdout);
        }
        last_char = temp_char;
    }
    fclose(file_ptr);
}

int main() {
    char filename[50];
    printf("Enter filename with .html extension: ");
    scanf("%s", filename);
    beautify(filename);
    printf("File beautified successfully!");
    return 0;
}