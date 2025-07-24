//FormAI DATASET v1.0 Category: HTML beautifier ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

bool is_tag(char c) {
    if(c == '<' || c == '>') {
        return true;
    }
    return false;
}

void beautify_html(char* file_name) {
    FILE* file = fopen(file_name, "r");
    if(file == NULL) {
        printf("Error opening file");
        exit(0);
    }

    char line[MAX_LINE_LENGTH];
    char spaces[50];
    memset(spaces, ' ', 50*sizeof(char));
    int indent = 0;
    bool new_line = true;

    while(fgets(line, MAX_LINE_LENGTH, file)) {
        int i = 0;
        while(line[i] != '\0') {
            if(new_line) {
                printf("%s", spaces);
                new_line = false;
            }

            if(line[i] == '<') {
                if(line[i+1] == '/') {
                    indent -= 4;
                    printf("%c%c", line[i], line[i+1]);
                    i+=2;
                } else {
                    printf("%c", line[i]);
                    if(!is_tag(line[i+1])) {
                        printf("%c", line[i+1]);
                    }
                    printf("\n");
                    indent += 4;
                    new_line = true;
                }
            } else if(line[i] == '>') {
                printf("%c\n", line[i]);
                new_line = true;
            } else {
                printf("%c", line[i]);
            }

            i++;
        }
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if(argc < 2) {
        printf("Usage: %s file_name", argv[0]);
        exit(0);
    }

    beautify_html(argv[1]);

    return 0;
}