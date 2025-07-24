//FormAI DATASET v1.0 Category: Text processing ; Style: funny
#include <stdio.h>

int main()
{
    // declaring variables
    char str[100], ch;
    int i, count = 0;

    // prompting user for input
    printf("Please enter a funny sentence: ");
    fgets(str,sizeof(str),stdin);

    // counting number of characters
    for (i = 0; str[i] != '\n'; i++) {
        if (str[i] != ' ') {
            count++;
        }
    }

    // converting all characters to uppercase for extra humor
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            ch = str[i] - 32;
            str[i] = ch;
        }
    }

    // printing the results
    printf("\nYour funny sentence has %d characters!\n", count);
    printf("And here it is in ALL CAPS: %s", str);

    return 0;
}