//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: expert-level
#include <stdio.h>
#include <string.h>

int main()
{
    char str[1000];
    int i,j, len;
    char c;

    printf("Enter the sentence in C Cat Language: ");
    fgets(str, 1000, stdin);

    len = strlen(str);

    // Translation from C Cat Language to English

    printf("The English Translation: ");

    for(i=0;i<len;i++)
    {
        if(str[i] == 'm' && str[i+1] == 'e' && str[i+2] == 'o')
        {
            printf("cat");
            i += 2;
        }

        else if(str[i] == 'p' && str[i+1] == 'u' && str[i+2] == 'r' && str[i+3] == 'r')
        {
            printf("purr");
            i += 3;
        }

        else if(str[i] == 'h' && str[i+1] == 'i' && str[i+2] == 's' && str[i+3] == 's')
        {
            printf("hiss");
            i += 3;
        }

        else if(str[i] == 'm' && str[i+1] == 'e' && str[i+2] == 'o' && str[i+3] == 'w')
        {
            printf("meow");
            i += 3;
        }

        else if(str[i] == 'y' && str[i+1] == 'o' && str[i+2] == 'w' && str[i+3] == 'l')
        {
            printf("yowl");
            i += 3;
        }

        else if(str[i] == 'p' && str[i+1] == 'a' && str[i+2] == 'w')
        {
            printf("paw");
            i += 2;
        }

        else if(str[i] == 'w' && str[i+1] == 'h' && str[i+2] == 'i' && str[i+3] == 's' && str[i+4] == 'k' && str[i+5] == 'e' && str[i+6] == 'r')
        {
            printf("whisker");
            i += 6;
        }

        else if(str[i] == 'n' && str[i+1] == 'a' && str[i+2] == 'p')
        {
            printf("nap");
            i += 2;
        }

        else if(str[i] == 's' && str[i+1] == 'c' && str[i+2] == 'r' && str[i+3] == 'a' && str[i+4] == 't' && str[i+5] == 'c' && str[i+6] == 'h')
        {
            printf("scratch");
            i += 6;
        }

        else if(str[i] == 'f' && str[i+1] == 'u' && str[i+2] == 'r')
        {
            printf("fur");
            i += 2;
        }

        else if(str[i] == 't' && str[i+1] == 'a' && str[i+2] == 'i' && str[i+3] == 'l')
        {
            printf("tail");
            i += 3;
        }

        else if(str[i] == 'c' && str[i+1] == 'l' && str[i+2] == 'a' && str[i+3] == 'w')
        {
            printf("claw");
            i += 3;
        }

        else if(str[i] == 'r' && str[i+1] == 'o' && str[i+2] == 'l' && str[i+3] == 'l' && str[i+4] == 'o' && str[i+5] == 'v' && str[i+6] == 'e')
        {
            printf("rollover");
            i += 6;
        }

        else if(str[i] == 'c' && str[i+1] == 'u' && str[i+2] == 'd' && str[i+3] == 'd' && str[i+4] == 'l' && str[i+5] == 'e')
        {
            printf("cuddle");
            i += 5;
        }

        else if(str[i] == 'h' && str[i+1] == 'o' && str[i+2] == 'p')
        {
            printf("hop");
            i += 2;
        }

        else if(str[i] == 'l' && str[i+1] == 'i' && str[i+2] == 'c' && str[i+3] == 'k')
        {
            printf("lick");
            i += 3;
        }

        else if(str[i] == 'n' && str[i+1] == 'i' && str[i+2] == 'b' && str[i+3] == 'b' && str[i+4] == 'l' && str[i+5] == 'e')
        {
            printf("nibble");
            i += 5;
        }

        else if(str[i] == 'r' && str[i+1] == 'u' && str[i+2] == 'b')
        {
            printf("rub");
            i += 2;
        }

        else if(str[i] == 's' && str[i+1] == 'n' && str[i+2] == 'i' && str[i+3] == 'f' && str[i+4] == 'f')
        {
            printf("sniff");
            i += 4;
        }

        else if(str[i] == 's' && str[i+1] == 't' && str[i+2] == 'r' && str[i+3] == 'e' && str[i+4] == 't' && str[i+5] == 'c' && str[i+6] == 'h')
        {
            printf("stretch");
            i += 6;
        }

        else if(str[i] == 'w' && str[i+1] == 'a' && str[i+2] == 'i' && str[i+3] == 't')
        {
            printf("wait");
            i += 3;
        }

        else if(str[i] == 'c' && str[i+1] == 'h' && str[i+2] == 'a' && str[i+3] == 's' && str[i+4] == 'e')
        {
            printf("chase");
            i += 4;
        }

        else if(str[i] == 's' && str[i+1] == 't' && str[i+2] == 'a' && str[i+3] == 'l' && str[i+4] == 'k')
        {
            printf("stalk");
            i += 4;
        }

        else if(str[i] == 'h' && str[i+1] == 'u' && str[i+2] == 'n' && str[i+3] == 't')
        {
            printf("hunt");
            i += 3;
        }

        else
        {
            printf("%c", str[i]);
        }

    }

    return 0;
}