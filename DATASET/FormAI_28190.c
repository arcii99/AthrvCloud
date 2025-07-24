//FormAI DATASET v1.0 Category: HTML beautifier ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to beautify HTML code
void beautifyHTML(char* input, char* output) {
    int indent = 0;
    int size = strlen(input);
    for (int i = 0; i < size; i++) {
        if (input[i] == '<') {
            if (input[i+1] == '/') indent--;
            for (int j = 0; j < indent; j++) strcat(output, "    ");
            if (input[i+1] == '/') indent--;
            strcat(output, "<");
            if (input[i+1] == '/') indent--;
            if (input[i+1] != '!') indent++;
        }
        else if (input[i] == '>') {
            strcat(output, ">");
            if (input[i-1] == '/') indent--;
            if (input[i+1] != '<') strcat(output, "\n");
        }
        else {
            strcat(output, input[i] == '\n' ? "" : &(input[i]));
            if (input[i] == '/') indent--;
            if (input[i] == '\n') {
                for (int j = 0; j < indent; j++) strcat(output, "    ");
            }
        }
    }
}

int main() {
    char input[1000] = "<html><head><title>My website</title></head><body><h1>Welcome to my website!</h1><p>This is a paragraph.</p></body></html>";
    char output[10000] = "";
    beautifyHTML(input, output);
    printf("%s\n", output);
    return 0;
}