//FormAI DATASET v1.0 Category: Spam Detection System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char message[200];
    int flag = 0, i;

    printf("Enter a message: ");
    fgets(message, 200, stdin);

    char words[10][20] = {"buy", "deal", "offer", "click", "money", "subscribe", "limited time", "winner", "cash", "won"};

    for (i = 0; i < 10; i++) {
        char *ptr = strstr(message, words[i]); // Check if the word is present in the message
        if (ptr != NULL) { // If the word is present
            flag = 1;
            break;
        }
    }

    if (flag) { // If any spam word is found
        printf("This message is spam.\n");
    } else { // If no spam word is found
        printf("This message is not spam.\n");
    }

    return 0;
}