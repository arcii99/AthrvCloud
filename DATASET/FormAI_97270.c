//FormAI DATASET v1.0 Category: Text processing ; Style: realistic
#include <stdio.h>
#include <string.h>

int main()
{
    char text[1000]; // maximum length of text is set to 1000
    char search_word[100]; // maximum length of search_word is set to 100
    printf("Enter some text: ");
    fgets(text, 1000, stdin); // get the text input from user
    printf("Enter a word to search for: ");
    scanf("%s", search_word); // get the search_word input from user

    int count = 0; // initializing count variable to 0
    char *token = strtok(text, " ,.-"); // tokenizing the text using space, comma, hyphen, and period as delimiters

    while(token != NULL) // loop through tokens until it reaches the end
    {
        if(strcmp(token, search_word)==0) // if the token is equal to the search word, increase the count
        {
            count++;
        }
        token = strtok(NULL, " ,.-"); // getting the next token
    }

    printf("The word '%s' appears %d times in the text.", search_word, count);

    return 0;
}