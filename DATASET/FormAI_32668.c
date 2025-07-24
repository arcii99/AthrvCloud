//FormAI DATASET v1.0 Category: Word Count Tool ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORD_LEN 50
#define MAX_FILE_NAME_LEN 100

int main()
{
    FILE *fp;
    char fileName[MAX_FILE_NAME_LEN];
    char word[MAX_WORD_LEN];
    int wordCount = 0;

    printf("Enter the file name: ");
    scanf("%s", fileName);

    fp = fopen(fileName, "r");
    if(fp == NULL) {
        printf("Could not open the file: %s\n", fileName);
        exit(1);
    }

    while(fscanf(fp, "%s", word) != EOF) {
        int i;
        int len = strlen(word);
        
        for(i = 0; i < len; ++i) {
            if(!isalpha(word[i])) {
                break;
            }
        }
        
        if(i == len) {
            ++wordCount;
        }
    }

    printf("The total number of words in the file is: %d\n", wordCount);

    fclose(fp);

    return 0;
}