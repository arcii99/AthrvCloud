//FormAI DATASET v1.0 Category: Spell checking ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[100];
    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);
    char words[20][20];
    int count = 0;
    char *token = strtok(sentence, " .,;:\n\r");
    while(token != NULL)
    {
        strcpy(words[count], token);
        count++;
        token = strtok(NULL, " .,;:\n\r");
    }
    char dictionary[10][10] = {"thou", "thee", "thy", "shall", "mayest", "art", "hath", "doth", "wouldst", "wherefore"};
    int correct_words = 0;
    for(int i=0; i<count; i++)
    {
        int found = 0;
        for(int j=0; j<10; j++)
        {
            if(strcmp(words[i], dictionary[j]) == 0)
            {
                found = 1;
                correct_words++;
                break;
            }
        }
        if(found == 0)
        {
            printf("Ah, I see thou hast used the wrong word - \"%s\".\n", words[i]);
            char correct[10];
            printf("What word wouldst thou have used instead? ");
            scanf("%s", correct);
            strcpy(words[i], correct);
        }
    }
    printf("\nAll is well that ends well, thy sentence is:\n");
    for(int i=0; i<count; i++)
    {
        printf("%s ", words[i]);
    }
    printf("\nThou hast %d correctly spelled words in thy sentence.\n", correct_words);
    return 0;
}