//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#define ALPHABET_SIZE 26

void alienTranslator(char *testString);

int main()
{
    char testString[1000];
    printf("Enter the string you want to translate: ");
    scanf("%[^\n]%*c", testString); // read input string until \n character
    alienTranslator(testString);
    return 0;
}

void alienTranslator(char *testString)
{
    int stringLength = strlen(testString);
    int i, j, count = 0, alienCount = 0;
    int alphabetList[ALPHABET_SIZE] = {0};
    for(i = 0; i < stringLength; i++)
    {
        if(testString[i] == ' ')
        {
            for(j = 0; j < ALPHABET_SIZE; j++)
            {
                if(alphabetList[j])
                {
                    alienCount++;
                }
            }
            printf("\n Alien %d: ", ++count);
            for(j = 0; j < ALPHABET_SIZE; j++)
            {
                if(alphabetList[j])
                {
                    printf("%c", (char) (j + 'a'));
                }
            }
            memset(alphabetList,0,sizeof(alphabetList)); //reset alphabetList for new alien language
        }
        else if(isalpha(testString[i]))
        {
            alphabetList[tolower(testString[i]) - 'a'] = 1; //add alphabet to the list
        }
    }
    if(alienCount==0)
    {
        printf("\n No alien language found!!\n");
    }
    else
    {
        printf("\nTotal number of alien languages found: %d\n", alienCount);
    }
}