//FormAI DATASET v1.0 Category: Text processing ; Style: active
#include <stdio.h>
#include <string.h>

int main()
{
    char text[1000]; // declare character array to store text input
    int count = 0;

    printf("Enter some text: ");
    fgets(text, sizeof(text), stdin); // read input text from standard input

    // loop through each character in the string
    for (int i = 0; i < strlen(text); i++)
    {
        // if the current character is a space, increment the counter
        if (text[i] == ' ')
        {
            count++;
        }
    }

    printf("The input text has %d spaces.\n", count);

    return 0;
}