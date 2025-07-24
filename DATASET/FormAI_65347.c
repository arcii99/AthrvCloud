//FormAI DATASET v1.0 Category: HTML beautifier ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

void putIndent(FILE* out, int indentLevel);
void beautify(FILE* in, FILE* out, int indentWidth);

int main() {
    FILE *in, *out;
    in = fopen("input.html", "r");
    out = fopen("output.html", "w");
    beautify(in, out, 4);
    printf("HTML code beautification completed successfully!\n");

    fclose(in);
    fclose(out);

    return 0;
}

void putIndent(FILE* out, int indentLevel) {
    int i;
    for(i=0; i<indentLevel; i++) {
        fprintf(out, " ");
    }
}

void beautify(FILE* in, FILE* out, int indentWidth) {
    char c;
    int inTag = 0, inSingleQuote = 0, inDoubleQuote = 0, inComment = 0;
    int currentIndent = 0;

    while((c = fgetc(in)) != EOF) {
        if(c == '<') {
            inTag = 1;
        }
        else if(c == '>') {
            if(!inComment) {
                fprintf(out, "%c\n", c);
            }
            else {
                fprintf(out, "%c", c);
            }
            inTag = 0;
        }
        else {
            if(inTag) {
                if(c == '\'') {
                    if(!inDoubleQuote) {
                        inSingleQuote = !inSingleQuote;
                    }
                }
                else if(c == '\"') {
                    if(!inSingleQuote) {
                        inDoubleQuote = !inDoubleQuote;
                    }
                }

                if(!inSingleQuote && !inDoubleQuote) {
                    if(c == '/' && fgetc(in) == '/') {
                        inComment = 1;
                        fprintf(out, "//");
                    }
                    else if(c == '-' && fgetc(in) == '-') {
                        inComment = 1;
                        fprintf(out, "--");
                    }
                    else {
                        if(!inComment) {
                            fprintf(out, "%c", c);
                        }
                    }
                }
                else {
                    if(!inComment) {
                        fprintf(out, "%c", c);
                    }
                }
            }
            else {
                if(c == '\n') {
                    currentIndent = 0;
                    fprintf(out, "%c", c);
                }
                else {
                    if(currentIndent == 0 && c == ' ') {
                        // Ignore leading white-space
                    }
                    else {
                        if(!inComment) {
                            if(currentIndent == 0) {
                                putIndent(out, indentWidth);
                                currentIndent += indentWidth;
                            }
                            fprintf(out, "%c", c);
                            currentIndent++;
                        }
                    }
                }
            }
        }
    }
}