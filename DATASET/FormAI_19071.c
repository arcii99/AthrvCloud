//FormAI DATASET v1.0 Category: Text processing ; Style: irregular
#include<stdio.h>

int main()
{
    char text[] = "ThIs iS aN UnIqUe CoDE sNiPpEt tO pRoCeSS TeXT IN An iRrEgUlAr WAnnaBe StyLe!";
    int i;

    printf("Original text: %s\n\n", text);

    //Convert every alternate character to uppercase
    for(i=0; text[i]!='\0'; i++)
    {
        if(i%2 != 0) //If character is at odd index
        {
            if(text[i]>='a' && text[i]<='z')
            {
                text[i] = text[i] - 32; //Converting character to uppercase
            }
        }
    }

    printf("Alternate characters converted to uppercase: %s\n\n", text);

    //Remove all vowels from the text
    for(i=0; text[i]!='\0'; i++)
    {
        if(text[i]=='a' || text[i]=='e' || text[i]=='i' || text[i]=='o' || text[i]=='u' || text[i]=='A' || text[i]=='E' || text[i]=='I' || text[i]=='O' || text[i]=='U')
        {
            int j;
            for(j=i; text[j]!='\0'; j++)
            {
                text[j] = text[j+1]; //Shift all characters one place to left
            }
            i--; //Decrease index to compensate for removed character
        }
    }

    printf("Vowels removed from text: %s\n\n", text);

    //Replace spaces with underscores and vice versa
    for(i=0; text[i]!='\0'; i++)
    {
        if(text[i]==' ')
        {
            text[i] = '_';
        }
        else if(text[i]=='_')
        {
            text[i] = ' ';
        }
    }

    printf("Spaces and underscores swapped in text: %s\n\n", text);

    printf("Thank you for processing text in an irregular style!\n\n");

    return 0;
}