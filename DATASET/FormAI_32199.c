//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Donald Knuth
#include <stdio.h>

int main(){
    FILE *filePtr;
    char fileName[50], ch;
    int indent = 0;
    
    printf("Enter file name:\n");
    scanf("%s", fileName);
    
    filePtr = fopen(fileName, "r+");
    
    if(filePtr == NULL){
        printf("File could not be opened.");
        return 0;
    }
    
    while((ch = fgetc(filePtr)) != EOF)
    {
        if(ch == '<') {
            printf("\n");
            for(int i = 1; i <= indent; i++)
                printf("\t");
            indent++;
        }
        else if(ch == '>') {
            printf(">");
        }
        else if(ch == '/') {
            indent--;
            printf("\n");
            for(int i = 1; i <= indent; i++)
                printf("\t");
        }
        else {
            printf("%c", ch);
        }
    }
    
    fclose(filePtr);
    
    return 0;
}