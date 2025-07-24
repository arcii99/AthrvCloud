//FormAI DATASET v1.0 Category: Data recovery tool ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

void recoverData(FILE *fptr, int fileSize, char *outputFileName){
    char data[100];
    FILE *outFptr = fopen(outputFileName,"w");
    if(outFptr == NULL){
        printf("Error! Unable to create output file.");
        return;
    }
    int i=0, j=0;
    while(i<fileSize){
        char c = fgetc(fptr);
        if(c != EOF){
            data[j] = c;
            j++;
        }
        else{
            int len = strlen(data);
            if(len>0){
                data[len] = '\0';
                fputs(data, outFptr);
                j = 0;
            }
        }
        i++;
    }
    fclose(outFptr);
}

void main(){
    char inputFileName[] = "data.txt"; //The name of the file from which data needs to be recovered
    FILE *fptr = fopen(inputFileName,"r");
    if(fptr == NULL){
        printf("Error! Unable to open file.");
        return;
    }
    fseek(fptr,0,SEEK_END);
    int fileSize = ftell(fptr);
    fclose(fptr);
    recoverData(fopen(inputFileName,"r"),fileSize,"output.txt");
    printf("Data recovered successfully!");
}