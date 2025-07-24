//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void createWatermark(char *originalFile, char *watermark){
    FILE *original, *marked;
    original = fopen(originalFile,"r");
    marked = fopen(watermark,"w");
    char ch;
    int count=0;
    while( ( ch = fgetc(original) ) != EOF)
    {
        if(count%2==0){
            fputc(ch,marked);
            fputc('~',marked);
        }
        else{
            fputc(ch,marked);
        }
        count++;
    }
    fclose(original);
    fclose(marked);
}

void extractWatermark(char *markedFile, char *extracted){
    FILE *marked, *output;
    marked = fopen(markedFile,"r");
    output = fopen(extracted,"w");
    char ch, prev;
    int count=0;
    while( ( ch = fgetc(marked) ) != EOF)
    {
        if(count%2==0){
            fputc(ch,output);
        }
        count++;
    }
    fclose(marked);
    fclose(output);
}

int main(){
    char originalFile[] = "original.txt";
    char markedFile[] = "marked.txt";
    char extracted[] = "extracted.txt";
    createWatermark(originalFile,markedFile);
    extractWatermark(markedFile,extracted);
    printf("Watermark created and extracted successfully!");
    return 0;
}