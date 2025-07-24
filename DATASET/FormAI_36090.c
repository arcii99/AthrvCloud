//FormAI DATASET v1.0 Category: Syntax parsing ; Style: authentic
#include<stdio.h>

int main()
{
    char str[100];
    int i=0,words=0,lines=0,characters=0;
    printf("Enter your string: ");

    while((str[i]=getchar())!= '\n') //Read from user till he enters new line
    {
        if(str[i]==' ') //Checking for spaces
            words++;
        else if(str[i]=='\n') //Checking for new lines
            lines++;
        else //If not a space or a new line character its considered a character
            characters++;
        i++;
    }
    words++; //As last word will not have any space after it
    printf("\nNumber of characters in the given string are: %d",characters);
    printf("\nNumber of words in the given string are: %d",words);
    printf("\nNumber of lines in the given string are: %d",lines+1); //New line characters are considered as new lines, so adding 1 here
    return 0;
}