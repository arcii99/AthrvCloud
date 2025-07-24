//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: funny
#include <stdio.h>
#include <ctype.h>

int main(void) {
    char sentence[1000];
    printf("Welcome to the ASCII Art Generator!\n");
    printf("Please input the text you would like to convert:\n");

    fgets(sentence, sizeof(sentence), stdin);
    printf("\n");

    int asciiCode;

    printf("Here's your text in ASCII art:\n\n");

    for(int i = 0; i < strlen(sentence); i++) {
        asciiCode = (int)sentence[i];
        if(isalpha(sentence[i])) {
            printf("   ");
            for(int j = 0; j < 5; j++) {
                if(j == 0 || j == 4) {
                    printf("*    *\n");
                } else if(j == 1) {
                    printf("*  %c *\n", toupper(sentence[i]));
                } else if(j == 3) {
                    printf("*  %c *\n", toupper(sentence[i]));
                } else {
                    printf("*    *\n");
                }
            }
        } else if(isdigit(sentence[i])) {
            printf("   ");
            for(int j = 0; j < 5; j++) {
                if(j == 0 || j == 4) {
                    printf("*    *\n");
                } else if(j == 2) {
                    printf("*  %c *\n", sentence[i]);
                } else {
                    printf("*    *\n");
                }
            }
        } else {
            printf("   ");
            for(int j = 0; j < 5; j++) {
                if(j == 0 || j == 4) {
                    printf("*    *\n");
                } else if(j == 2) {
                    printf("*  %3d *\n", asciiCode);
                } else {
                    printf("*    *\n");
                }
            }
        }
    }

    printf("\nThanks for using ASCII Art Generator! Have a nice day!\n");
    return 0;
}