//FormAI DATASET v1.0 Category: Word Count Tool ; Style: detailed
#include<stdio.h>
#include<string.h>

int main() {
    char input[1000];
    printf("Enter the text: ");
    fgets(input,1000,stdin);
    int wordCount=0;
    int charCount=0;
    int spaceCount=0;
    for(int i=0;i<strlen(input);i++) {
        charCount++;
        if(input[i]==' ' || input[i]=='\n') {
            spaceCount++;
        }
    }
    wordCount=spaceCount+1;
    printf("\n");
    printf("Word count: %d\n",wordCount);
    printf("Character count: %d\n",charCount-1);
    printf("Spaces count: %d\n",spaceCount);
    return 0;
}