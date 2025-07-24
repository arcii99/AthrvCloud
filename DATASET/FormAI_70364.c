//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: romantic
#include <stdio.h>
#include <string.h>

int main()
{
    char word[100], reverse[100];
    int length = 0, flag = 0, i;

    printf("My Love,\n\n");
    printf("Today I had a sudden realization, just like how you are my forever, 'Palindrome' is also a forever.\n");
    printf("Palindrome, two different halves but made for each other, and that’s exactly what we are.\n");
    printf("So, I decided to make a program for you to check whether the word you type is a palindrome or not.\n\n");
    printf("Type a word for me to check: ");
    scanf("%s", word);

    // Find the length of the word
    length = strlen(word);
    
    // Reverse the word
    for(i=0; i<length; i++)
    {
        reverse[i] = word[length-i-1];
    }
    
    // Check if the word and its reverse are the same
    for(i=0; i<length; i++)
    {
        if(reverse[i] != word[i])
        {
            flag = 1;
            break;
        }
    }

    if(flag == 0)
        printf("\nOh my love, you typed a Palindrome word. It's just like us, a perfect match, always the same from both ends.\n");
    else
        printf("\nMy love, sorry to inform you but the word you typed is not a Palindrome unlike us, who are meant to be till eternity.\n");

    printf("\nThis small token is a reminder of how much I love you, just like how Palindrome is a forever, my love for you is too.\n");
    printf("I promise to love and cherish you till my last breath. You mean the world to me.\n");
    return 0;
}