//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: innovative
#include <stdio.h> 

int main() 
{ 
    char text[100];
    printf("Enter your text: "); 
    fgets(text, sizeof(text), stdin); //getting input from user
    int i, j;

    for (i = 0; text[i] != '\0'; i++) { //iterating through each character

        switch (text[i]) {
            case 'A': //ASCII art for A
                printf("  /\\  \n /  \\ \n/____\\\n");
                break;

            case 'B': //ASCII art for B
                printf(" ____  \n|    \\ \n|____/\n|    \\\n|____/\n");
                break;

            case 'C': //ASCII art for C
                printf("  ____ \n / ___\\\n| |    \n| |___ \n \\____\\\n");
                break;

            //ASCII art for more characters can be added here

            default: //for all other characters
                printf("\n"); //print new line character
                break;
        }

        if (text[i] == ' ') { //for spaces, skipping one character
            i++;
        }
    }
    return 0;
}