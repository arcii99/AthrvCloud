//FormAI DATASET v1.0 Category: Spam Detection System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to recursively search for spam words in a given text
int isSpam(char *text, char **spamWords, int numOfSpamWords)
{
    // Base case: if the text is empty or the number of spam words is 0, return 0
    if (strlen(text) == 0 || numOfSpamWords == 0)
    {
        return 0;
    }
        
    // Check if the first word in the text matches any of the spam words
    int len = strlen(spamWords[0]);
    if (strncmp(text, spamWords[0], len) == 0)
    {
        return 1 + isSpam(text + len, spamWords, numOfSpamWords);
    }
    else
    {
        return isSpam(text + 1, spamWords, numOfSpamWords);
    }
}

int main()
{
    // List of spam words to search for
    char *spamWords[] = {"buy", "sell", "earn money"};

    // Get the number of spam words
    int numOfSpamWords = sizeof(spamWords) / sizeof(spamWords[0]);

    // Test cases
    char text1[] = "I want to buy a car";
    char text2[] = "You can sell your old phone and earn money";
    char text3[] = "This is a normal text";
    char text4[] = "Earn money while you sleep by investing in stocks";
    char text5[] = "";

    // Test the isSpam function with the test cases
    int spam1 = isSpam(text1, spamWords, numOfSpamWords);
    int spam2 = isSpam(text2, spamWords, numOfSpamWords);
    int spam3 = isSpam(text3, spamWords, numOfSpamWords);
    int spam4 = isSpam(text4, spamWords, numOfSpamWords);
    int spam5 = isSpam(text5, spamWords, numOfSpamWords);

    // Print the results
    printf("'%s' contains %d spam word(s)\n", text1, spam1);
    printf("'%s' contains %d spam word(s)\n", text2, spam2);
    printf("'%s' contains %d spam word(s)\n", text3, spam3);
    printf("'%s' contains %d spam word(s)\n", text4, spam4);
    printf("'%s' contains %d spam word(s)\n", text5, spam5);

    return 0;
}