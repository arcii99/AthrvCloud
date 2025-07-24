//FormAI DATASET v1.0 Category: HTML beautifier ; Style: artistic
#include<stdio.h>
#include<stdlib.h>

// HTML beautifier function to format the HTML code
void beautify(char *inFile, char *outFile) {
    FILE *in = fopen(inFile, "r");
    FILE *out = fopen(outFile, "w");
    char ch, prevCh = '\0';
    int indentLevel = 0;

    while((ch = fgetc(in)) != EOF) {
        if(ch == '<') {
            fputs("\n", out);
            for(int i=0; i<indentLevel; i++) {
                fputs("    ", out);  // 4 spaces for each indent level
            }
            fputs("<", out);
            if(prevCh == '\n') {
                for(int i=0; i<indentLevel; i++) {
                    fputs("    ", out);  // 4 spaces for each indent level
                }
            }
            indentLevel++;
        }
        else if(ch == '>') {
            fputc(ch, out);
            prevCh = '>';
        }
        else if(ch == '/') {
            fputc(ch, out);
        }
        else if(ch == '\n') {
            fputc(ch, out);
            prevCh = '\n';
        }
        else if(ch == '-') {
            if(prevCh == '<') {
                fputc(ch, out);
                indentLevel--;
                for(int i=0; i<indentLevel; i++) {
                    fputs("    ", out);  // 4 spaces for each indent level
                }
            }
        }
        else {
            fputc(ch, out);
        }
        prevCh = ch;
    }

    fclose(in);
    fclose(out);
}

int main() {
    beautify("input.html", "output.html");
    printf("HTML code formatted successfully!");
    return 0;
}