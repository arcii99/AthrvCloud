//FormAI DATASET v1.0 Category: File handling ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    char file_name[100], text[100], search_text[100];
    int count = 0;

    printf("Enter the file name: ");
    scanf("%s", file_name);

    fp = fopen(file_name, "r");

    if (fp == NULL)
    {
        printf("Could not open file %s", file_name);
        return 1;
    }

    printf("Enter the search word/phrase: ");
    scanf("%s", search_text);

    while (fgets(text, sizeof(text), fp) != NULL)
    {
        if (strstr(text, search_text) != NULL)
        {
            printf("Found \"%s\" in the file!\n", search_text);
            count++;
        }
    }

    if (count == 0)
    {
        printf("Sorry, \"%s\" was not found in the file.\n", search_text);
    }

    fclose(fp);

    return 0;
}