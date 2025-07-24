//FormAI DATASET v1.0 Category: Spell checking ; Style: standalone
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{
    char input[1000];
    int i,j=0,flag = 0; // flag is used for error checking and j is for counting errors in a word.

    printf("Enter the text you want to check:\n");
    fgets(input,1000,stdin); // get user input.

    printf("\n\n\t\t SPELLCHECK REPORT\n\n");

    for(i=0;i<strlen(input);i++)
    {
        if(!isspace(input[i])) // check if space is encountered.
        {
            if(!isalnum(input[i])) // if input is not alphanumeric, then it is definitely an error.
            {
                if(input[i]=='.' || input[i]==',' || input[i]==';' || input[i]==':' || input[i]=='"' || input[i]=='\'')
                {
                    continue; // These are considered as correct spell words but not alpha numeric,so they are skipped.
                }
                else
                {
                    printf("\t\t'%c' is not an alphabetic character.\n\n",input[i]);
                    flag = 1; // set flag to 1 if alphabetic character is not encountered.
                }
            }
            else
            {
                while(!isspace(input[i])) // if character is alphanumeric, continue till it reaches a space. 
                {
                    i++;
                }
                j++; // increment the error counter for that word.
            }
        }
    }

    if(flag == 0)// if there are no errors then output will change accordingly.
    {
        printf("\t\tGreat! No spelling errors found in the text.\n\n");
    }
    else
    {
        printf("\t\tTotal %d spelling errors found in the text.\n\n",j);
    }
    return 0;
}