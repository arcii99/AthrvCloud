//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: energetic
#include <stdio.h>
#include <string.h>

int main() {
    char message[1000];
    int i, j;
    
    printf("Welcome to the Alien Language Translator!\n");

    printf("Enter a message in the C Alien Language: ");
    fgets(message, sizeof(message), stdin);

    printf("\nTranslating message...\n");

    for(i = 0; message[i] != '\0'; ++i) {
        j = i + 1;
        if(message[i] == 'c' || message[i] == 'C') {
            if(message[j] == 'c' || message[j] == 'C') {
                printf("Z");
                ++i;
            }
            else {
                printf("X");
            }
        }
        else if(message[i] == 'e' || message[i] == 'E') {
            printf("R");
        }
        else if(message[i] == 'g' || message[i] == 'G') {
            if(message[j] == 'h' || message[j] == 'H') {
                printf("J");
                ++i;
            }
            else {
                printf("T");
            }
        }
        else if(message[i] == 'y' || message[i] == 'Y') {
            printf("Q");
        }
        else if(message[i] == 'i' || message[i] == 'I') {
            printf("K");
        }
        else if(message[i] == 'm' || message[i] == 'M') {
            printf("N");
        }
        else if(message[i] == 'o' || message[i] == 'O') {
            printf("P");
        }
        else if(message[i] == 'q' || message[i] == 'Q') {
            printf("W");
        }
        else if(message[i] == 's' || message[i] == 'S') {
            printf("F");
        }
        else if(message[i] == 'u' || message[i] == 'U') {
            printf("V");
        }
        else if(message[i] == 'w' || message[i] == 'W') {
            printf("Y");
        }
        else if(message[i] == 'a' || message[i] == 'A') {
            printf("B");
        }
        else if(message[i] == 'b' || message[i] == 'B') {
            printf("D");
        }
        else if(message[i] == 'd' || message[i] == 'D') {
            printf("G");
        }
        else if(message[i] == 'f' || message[i] == 'F') {
            printf("H");
        }
        else if(message[i] == 'h' || message[i] == 'H') {
            printf("L");
        }
        else if(message[i] == 'j' || message[i] == 'J') {
            printf("M");
        }
        else if(message[i] == 'k' || message[i] == 'K') {
            printf("O");
        }
        else if(message[i] == 'l' || message[i] == 'L') {
            printf("Q");
        }
        else if(message[i] == 'n' || message[i] == 'N') {
            printf("S");
        }
        else if(message[i] == 'p' || message[i] == 'P') {
            printf("U");
        }
        else if(message[i] == 't' || message[i] == 'T') {
            printf("Z");
        }
        else if(message[i] == 'v' || message[i] == 'V') {
            printf("X");
        }
        else if(message[i] == 'z' || message[i] == 'Z') {
            printf("A");
        }
        else {
            printf("%c", message[i]);
        }
    }

    printf("\n");
    return 0;
}