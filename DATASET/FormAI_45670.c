//FormAI DATASET v1.0 Category: Text processing ; Style: innovative
#include <stdio.h>
#include <string.h>

void reverse(char* sentence)
{
    int i, j, len = strlen(sentence);
    char temp;
 
    for (i = 0, j = len - 1; i < j; i++, j--)
    {
        temp = sentence[i];
        sentence[i] = sentence[j];
        sentence[j] = temp;
    }
}
 
void removeSpaces(char* sentence)
{
    int i, j;
    for (i = 0, j = 0; sentence[i]; i++)
        if (sentence[i] != ' ')
            sentence[j++] = sentence[i];
    sentence[j] = '\0';
}

int main() {
    // Initialize the string variable.
    char sentence[100];
    printf("Enter a sentence: ");
    scanf("%[^\n]s", sentence);
    printf("Original Sentence: %s\n", sentence);
    
    // Reverse the entire sentence.
    reverse(sentence);
    printf("Reversed Sentence: %s\n", sentence);
    
    // Remove spaces from the sentence.
    removeSpaces(sentence);
    printf("Sentence without Spaces: %s\n", sentence);
    
    // Check if the sentence is a palindrome.
    reverse(sentence);
    if (strcmp(sentence, sentence) == 0)
        printf("The sentence is a palindrome.\n");
    else
        printf("The sentence is not a palindrome.\n");
    
    return 0;
}