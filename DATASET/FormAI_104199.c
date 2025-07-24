//FormAI DATASET v1.0 Category: HTML beautifier ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

void beautify_html(char *filename);

int main()
{
    char filename[MAX_LENGTH];
    printf("Enter filename: ");
    fgets(filename, MAX_LENGTH, stdin);
    filename[strcspn(filename, "\n")] = 0;
    beautify_html(filename);
    return 0;
}

void beautify_html(char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("File not found!");
        exit(EXIT_FAILURE);
    }

    char temp[MAX_LENGTH], c;
    int tab_cnt = 0;

    printf("Beautified HTML:\n");
    while ((c = fgetc(fp)) != EOF)
    {
        if (c == '<' && fgetc(fp) != '/')
        {
            printf("\n");
            for (int i = 0; i < tab_cnt; i++)
            {
                printf("\t");
            }
            tab_cnt++;
            printf("<");
            fseek(fp, -1, SEEK_CUR);
        }
        else if (c == '<' && fgetc(fp) == '/')
        {
            printf("\n");
            tab_cnt--;
            for (int i = 0; i < tab_cnt; i++)
            {
                printf("\t");
            }
            printf("</");
            fseek(fp, -1, SEEK_CUR);
        }
        else if (c == '/')
        {
            printf("/");
            fseek(fp, -1, SEEK_CUR);
        }
        else if (c == '>')
        {
            printf("%c", c);
            printf("\n");
            fseek(fp, -1, SEEK_CUR);
            for (int i = 0; i < tab_cnt; i++)
            {
                printf("\t");
            }
        }
        else
        {
            printf("%c", c);
        }
    }

    fclose(fp);
}