//FormAI DATASET v1.0 Category: HTML beautifier ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

void beautify_html(char *filename) {
    FILE *fp;
    FILE *outputFile;

    fp = fopen(filename, "r");
    outputFile = fopen("beautified.html", "w");

    if (fp == NULL) {
        printf("Cannot open file \n");
        exit(0);
    }
    
    char c;
    int flag = 0;

    while ((c = fgetc(fp)) != EOF) {
        if (c == '<') {
            fprintf(outputFile, "\n%c", c);
            flag = 1;
        }
        else if (c == '>') {
            fprintf(outputFile, "%c\n", c);
            flag = 0;
        }
        else if (c == ' ' && flag == 1) {
            while (c == ' ') {
                c = fgetc(fp);
            }
            fputc(' ', outputFile);
            fputc(c, outputFile);
        }
        else {
            fputc(c, outputFile);
        }
    }
    fclose(fp);
    fclose(outputFile);
    printf("HTML file is beautified successfully.\n");
}

int main() {
    char *filename = "index.html";
    beautify_html(filename);
    return 0;
}