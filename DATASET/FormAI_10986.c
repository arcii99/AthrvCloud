//FormAI DATASET v1.0 Category: HTML beautifier ; Style: active
#include<stdio.h>
#include<stdlib.h>

void beautifyHTML(char *inputFileName,char *outputFileName) {
    FILE *inputFile=fopen(inputFileName,"r");
    FILE *outputFile=fopen(outputFileName,"w");
    if(inputFile==NULL || outputFile==NULL) {
        printf("Error opening file!");
        exit(1);
    }
    char c;
    int tabCount=0;
    while((c=fgetc(inputFile)) != EOF) {
        if(c=='<') {
            if(fgetc(inputFile)=='/') {
                tabCount--;
            }
            else {
                tabCount++;
                fseek(inputFile,-1,SEEK_CUR);
            }
            fprintf(outputFile,"\n");
            for(int i=0;i<tabCount;i++) {
                fprintf(outputFile,"\t");
            }
            fprintf(outputFile,"%c",c);
        }
        else if(c=='>') {
            fprintf(outputFile,"%c\n",c);
        }
        else if(c=='/') {
            fprintf(outputFile,"%c",c);
        }
        else {
            fprintf(outputFile,"%c",c);
        }
    }
    fclose(inputFile);
    fclose(outputFile);
}

int main() {
    beautifyHTML("input.html","output.html");
    return 0;
}