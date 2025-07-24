//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>

int main() {
    char ch;
    int indent = 0;
    FILE *fptr1, *fptr2;

    fptr1 = fopen("input.html", "r");
    if(fptr1 == NULL) {
        printf("Unable to open the input file.\n");
        exit(EXIT_FAILURE);
    }

    fptr2 = fopen("output.html", "w");
    if(fptr2 == NULL) {
        printf("Unable to open the output file.\n");
        fclose(fptr1);
        exit(EXIT_FAILURE);
    }

    while((ch = fgetc(fptr1)) != EOF) {
        if(ch == '<') {
            fputc(ch, fptr2);

            if(fgetc(fptr1) == '/') {
                indent--;
                fputc('\n', fptr2);
                for(int i=0;i<indent;i++) {
                    fputc('\t', fptr2);
                }
            }
            else {
                fputc('\n', fptr2);
                for(int i=0;i<indent;i++) {
                    fputc('\t', fptr2);
                }
                indent++;
            }
        }
        else if(ch == '>') {
            fputc(ch, fptr2);
            fputc('\n', fptr2);

            if(fgetc(fptr1) != '<') {
                for(int i=0;i<indent;i++) {
                    fputc('\t', fptr2);
                }
            }
            else {
                fseek(fptr1,-1,SEEK_CUR);
            }

        }
        else {
            fputc(ch,fptr2);
        }
    }

    fclose(fptr1);
    fclose(fptr2);

    return 0;
}