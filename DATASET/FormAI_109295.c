//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char prog[80], virus[15];
    int i, j, k;

    printf("Enter the name of the program: ");
    scanf("%s", prog);

    printf("Enter the name of the virus: ");
    scanf("%s", virus);

    i = strlen(prog) - 1;
    j = strlen(virus) - 1;
    k = 0;

    while (i >= 0 && j >= 0) {
        k = (prog[i] == virus[j]) ? k + 1 : 0;
        i--;
        j--;
    }

    if (k == strlen(virus)) {
        printf("The program contains the virus.\n");
    } else {
        printf("The program does not contain the virus.\n");
    }

    return 0;
}