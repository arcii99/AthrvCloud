//FormAI DATASET v1.0 Category: File Encyptor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 3 // change the value of KEY for a stronger encryption

int main(){
    FILE *fpin, *fpout;
    char inputFilename[50], outputFilename[50];
    char ch;
    int choice = 1;
    printf("Enter the input filename : ");
    scanf("%s", inputFilename);
    printf("Enter the output filename : ");
    scanf("%s", outputFilename);
    fpin = fopen(inputFilename, "r");
    if(fpin == NULL){
        printf("%s does not exist!", inputFilename);
        exit(1);
    }else{
        fpout = fopen(outputFilename, "w");
        while((ch=fgetc(fpin))!= EOF){
            ch = ch + KEY;
            fputc(ch, fpout);
        }
        fclose(fpin);
        fclose(fpout);
        printf("File encrypted successfully.");
    }
    return 0;
}