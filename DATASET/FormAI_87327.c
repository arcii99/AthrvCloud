//FormAI DATASET v1.0 Category: Text processing ; Style: configurable
#include<stdio.h>
#include<string.h>

#define MAX_TEXT_LEN 10000

int main()
{
    char text[MAX_TEXT_LEN];
    char delims[] = " ";
    char config[] = "lowercase";
    int i, j;

    // read input text
    printf("Enter text: ");
    fgets(text, MAX_TEXT_LEN, stdin);

    // apply configuration
    if(strcmp(config, "lowercase") == 0)
    {
        for(i=0; text[i]!='\0'; i++)
        {
            text[i] = tolower(text[i]);
        }
    }
    else if(strcmp(config, "uppercase") == 0)
    {
        for(i=0; text[i]!='\0'; i++)
        {
            text[i] = toupper(text[i]);
        }
    }

    // process text
    char* token = strtok(text, delims);
    int word_cnt = 0;
    while(token != NULL)
    {
        word_cnt++;

        // print word count and length
        printf("Word %d: '%s', length %d\n", word_cnt, token, strlen(token));

        // check if word is palindrome
        int len = strlen(token);
        int is_palindrome = 1;
        for(i=0, j=len-1; i<len/2; i++, j--)
        {
            if(token[i] != token[j])
            {
                is_palindrome = 0;
                break;
            }
        }
        if(is_palindrome)
        {
            printf("Word is palindrome!\n");
        }
        else
        {
            printf("Word is NOT palindrome!\n");
        }

        token = strtok(NULL, delims);
    }

    return 0;
}