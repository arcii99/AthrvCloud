//FormAI DATASET v1.0 Category: Arithmetic ; Style: visionary
#include <stdio.h>

int main() {
    char message[100], cipher[100];
    int key, i;

    printf("Enter a message: ");
    fgets(message, 100, stdin);

    printf("Enter a key (an integer value between 1 and 100): ");
    scanf("%d", &key);

    for(i = 0; message[i] != '\0'; ++i) {
        char ch = message[i];

        if(ch >= 'a' && ch <= 'z') {
            ch = 'a' + ((ch - 'a' + key) % 26);
        }
        else if(ch >= 'A' && ch <= 'Z') {
            ch = 'A' + ((ch - 'A' + key) % 26);
        }
        else if(ch >= '0' && ch <= '9') {
            ch = '0' + ((ch - '0' + key) % 10);
        }
        else {
            ch = ' ';
        }

        cipher[i] = ch;
    }

    printf("The encrypted message is: ");
    puts(cipher);

    return 0;
}