//FormAI DATASET v1.0 Category: Text processing ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char text[100];
    int upper=0, lower=0, digits=0, spaces=0, special_characters=0;

    printf("Enter a string of text : ");
    fgets(text, 100, stdin);

    for(int i=0; i<strlen(text); i++)
    {
        if(text[i]>='A' && text[i]<='Z')
            upper++;
        else if(text[i]>='a' && text[i]<='z')
            lower++;
        else if(text[i]>='0' && text[i]<='9')
            digits++;
        else if(text[i]==' ')
            spaces++;
        else
            special_characters++;
    }

    printf("\nThe given text contains : \n");
    printf("%d Upper case letters\n", upper);
    printf("%d Lower case letters\n", lower);
    printf("%d Digits\n", digits);
    printf("%d Spaces\n", spaces);
    printf("%d Special characters\n", special_characters);

    return 0;
}