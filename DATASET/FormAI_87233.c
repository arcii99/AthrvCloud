//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: puzzling
#include<stdio.h>
#include<ctype.h>
#include<string.h>

void printHeader();

int main()
{
    printHeader();

    char suspiciousCode[1000];
    printf("Please input code to scan:\n");
    gets(suspiciousCode);

    char safeCode[1000];
    int i, j = 0;
    for(i = 0; suspiciousCode[i] != '\0'; i++)
    {
        if(!isspace(suspiciousCode[i]))
        {
            safeCode[j] = suspiciousCode[i];
            j++;
        }
    }
    safeCode[j] = '\0';

    char virus[5] = "root";
    if(strstr(safeCode, virus))
    {
        printf("\n\nALERT! Virus Detected!\n\n");
    }
    else
    {
        printf("\n\nCode is Clean\n\n");
    }

    return 0;
}

void printHeader()
{
    printf(" _________________________________________________________________");
    printf("\n|                                                                 |");
    printf("\n|                                                                 |");
    printf("\n|                       *** C ANTIVIRUS ***                       |");
    printf("\n|                                                                 |");
    printf("\n|_________________________________________________________________|\n\n");
}