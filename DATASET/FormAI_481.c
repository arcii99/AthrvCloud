//FormAI DATASET v1.0 Category: Word Count Tool ; Style: grateful
#include <stdio.h>
#include <string.h>

int main()
{
    char file_name[100], word[20], ch;
    FILE *fp;
    int count = 0, match =0, i, j;

    printf("Enter the file name: ");
    scanf("%s", file_name);

    printf("Enter the word to be searched: ");
    scanf("%s", word);

    fp = fopen(file_name, "r");

    if(fp == NULL)
    {
        printf("Error: File not found!");
        return 1;
    }

    while((ch = fgetc(fp)) != EOF)
    {
        if(ch == ' ' || ch == '\n')
        {
            if(match == strlen(word))
                count++;
            match=0;
        }
        else if(ch == word[match])
            match++;
        else
            match=0;
    }

    if(match == strlen(word))
        count++;

    printf("\n\n'%s' occurs %d times in the file.", word, count);

    fclose(fp);
    return 0;
}