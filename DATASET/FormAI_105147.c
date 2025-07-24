//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

void beautifyHTML(char* input, char* output) {
    char buffer[1000];
    int indentLevel = 0;
    int outputIndex = 0;
    int inputIndex = 0;

    while(input[inputIndex] != '\0') {
        if(input[inputIndex] == '<') {
            if(input[inputIndex + 1] == '/') {
                indentLevel--;
            }
            for(int i=0; i<indentLevel; i++) {
                output[outputIndex++] = '\t';
            }
            if(input[inputIndex + 1] == '!' || input[inputIndex + 1] == '?') {
                strncpy(buffer, input+inputIndex, 9);
                buffer[9] = '\0';
                outputIndex += sprintf(output + outputIndex, "%s\n", buffer);
                inputIndex += 9;
            } else {
                while(input[inputIndex] != '>') {
                    output[outputIndex++] = input[inputIndex++];
                }
                output[outputIndex++] = input[inputIndex++];
                if(input[inputIndex-2] != '/') {
                    output[outputIndex++] = '\n';
                    indentLevel++;
                } else {
                    output[outputIndex++] = '\n';
                }
            }
        } else {
            output[outputIndex++] = input[inputIndex++];
        }
    }
    output[outputIndex] = '\0';
}

int main() {
    char input[] = "<!DOCTYPE html><html><head><title>Page Title</title></head><body><h1>This is a Heading</h1><p>This is a paragraph.</p></body></html>";
    char output[2000];
    beautifyHTML(input, output);
    printf("%s\n", output);
    return 0;
}