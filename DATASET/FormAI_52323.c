//FormAI DATASET v1.0 Category: HTML beautifier ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void beautify(char* input_file, char* output_file) {
    FILE* input = fopen(input_file, "r");
    FILE* output = fopen(output_file, "w");

    char* buffer = (char*)calloc(1000, sizeof(char));
    int indent = 0;

    while(fgets(buffer, 1000, input) != NULL) {
        if(strstr(buffer, "</") != NULL) {  // close tag
            indent--;
        }

        for(int i = 0; i < indent; i++) {  // add indentation
            fprintf(output, "\t");
        }

        fprintf(output, "%s", buffer);  // write line

        if(strstr(buffer, "<") != NULL && strstr(buffer, "</") == NULL) {  // open tag
            indent++; 
        }
    }

    free(buffer);
    fclose(input);
    fclose(output);

    printf("Beautification complete.\n");
}

int main() {
    beautify("input.html", "output.html");
    return 0;
}