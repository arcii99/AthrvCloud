//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: medieval
#include <stdio.h>
#include <string.h>

int main()
{
    int i,j,k;
    
    char alien_language[10][10];
    char english_alphabet[26];
    
    //filling the alien language array with random characters
    for(i=0; i<10; ++i)
    {
        for(j=0; j<10; ++j)
        {
            alien_language[i][j] = 'A' + rand()%26;
        }
    }
    
    //filling the english alphabet array
    for(i=0; i<26; ++i)
    {
        english_alphabet[i] = 'A' + i;
    }
    
    printf("Welcome to the Alien Language Translator!\n\n");
    printf("Please enter the message you want to translate: ");
    
    char input[100];
    fgets(input, 100, stdin);
    
    //removing newline character
    if(input[strlen(input)-1] == '\n')
    {
        input[strlen(input)-1] = '\0';
    }
    
    printf("\nTranslation in progress...\n\n");
    
    for(i=0; i<strlen(input); ++i)
    {
        //converting each character to lowercase for easy comparison
        char curr_char = tolower(input[i]);
        int found = 0;
        
        for(j=0; j<26; ++j)
        {
            if(english_alphabet[j] == curr_char)
            {
                found = 1;
                
                for(k=0; k<10; ++k)
                {
                    printf("%c", alien_language[j][k]);
                }
                
                //adding a space between translated characters
                printf(" ");
                break;
            }
        }
        
        //if the character is not found in the english alphabet array
        //then just print the same character
        if(found == 0)
        {
            printf("%c", input[i]);
        }
    }
    
    printf("\n\nTranslation complete!");
    
    return 0;
}