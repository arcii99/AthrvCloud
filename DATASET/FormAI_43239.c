//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: retro
#include <stdio.h>

int main(){
    // ASCII art generator program

    char message[100];

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    printf("\n");

    // ASCII characters used for generating art
    char ascii[] = {'#', '.', 'O', 'o', '+'};

    // loop through the input message
    for(int i=0; message[i]!='\0'; i++){
        // convert the character to ASCII code, and use modulo to keep it in range of 0-4
        int index = (message[i] % 5);

        // print the corresponding ASCII character
        printf("%c%c%c\n", ascii[index], ascii[index], ascii[index]);
        printf("%c %c\n", ascii[index], ascii[index]);

        // add some space between characters
        printf("\n");
    }

    return 0;
}