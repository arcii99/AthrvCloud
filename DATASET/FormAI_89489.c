//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(char c){
    switch(c){
        case 'A':        case 'a':
            printf("   /\\  \n  /  \\ \n / /\\ \\\n/ ____ \\\n");
            break;
        case 'B':        case 'b':
            printf(" ____  \n|    \\ \n|____/ \n|    \\ \n|____/ \n");
            break;
        case 'C':        case 'c':
            printf("  ____\n /    \\\n|      \n|      \n \\____/\n");
            break;
        case 'D':        case 'd':
            printf(" ____  \n|    \\ \n|     \\\n|     /\n|____/ \n");
            break;
        case 'E':        case 'e':
            printf(" _____\n|  ___|\n| |__  \n|  __| \n| |___ \n");
            break;
        case 'F':        case 'f':
            printf(" _____\n|  ___|\n| |__  \n|  __| \n| |    \n");
            break;
        case 'G':        case 'g':
            printf("  ____\n /    \\\n|      \n|  ____\n \\___  \\\n ____/ |\n|_____/ \n");
            break;
        case 'H':        case 'h':
            printf(" _    _\n| |  | |\n| |__| |\n|  __  |\n| |  | |\n");
            break;
        case 'I':        case 'i':
            printf(" ___\n|_  |\n | |\n | |\n|___|\n");
            break;
        case 'J':        case 'j':
            printf("    ___\n   |_  |\n     | |\n _   | |\n| |__| |\n \\____/ \n");
            break;
        case 'K':        case 'k':
            printf(" _  __\n| |/ /\n| ' / \n|  <  \n|_|\\_\\\n");
            break;
        case 'L':        case 'l':
            printf(" _     \n| |    \n| |    \n| |___ \n|_____| \n");
            break;
        case 'M':        case 'm':
            printf(" /\\    /\\\n|  \\  /  |\n|   \\/   |\n|        |\n|        |\n");
            break;
        case 'N':        case 'n':
            printf(" _   _ \n| \\ | |\n|  \\| |\n|     |\n|_|\\__|\n");
            break;
        case 'O':        case 'o':
            printf("  ___  \n /   \\ \n|     |\n|     |\n \\___/ \n");
            break;
        case 'P':        case 'p':
            printf(" ____  \n|    \\ \n|____/\n|     \n|     \n");
            break;
        case 'Q':        case 'q':
            printf("  ___  \n /   \\ \n|     |\n|     |\n \\__,_|\n");
            break;
        case 'R':        case 'r':
            printf(" ____  \n|    \\ \n|____/\n|  _ \\ \n|_| \\_\\\n");
            break;
        case 'S':        case 's':
            printf("  _____\n /     \\\n|  ___  \n \\_____| \n       |\n\\_____/ \n");
            break;
        case 'T':        case 't':
            printf(" _____\n|_   _|\n  | |  \n  | |  \n  |_|  \n");
            break;
        case 'U':        case 'u':
            printf(" _    _\n| |  | |\n| |  | |\n| |  | |\n \\___/ \n");
            break;
        case 'V':        case 'v':
            printf(" _     _\n| |   | |\n| |   | |\n| |___| |\n \\______/\n");
            break;
        case 'W':        case 'w':
            printf(" _        _\n| |      | |\n| |  /\\  | |\n| | /  \\ | |\n| |/ /\\ \\| |\n|___/  \\___|\n");
            break;
        case 'X':        case 'x':
            printf("\\ \\    / /\n \\ \\  / / \n  \\ \\/ /  \n  / /\\ \\  \n /_/  \\_\\\n");
            break;
        case 'Y':        case 'y':
            printf(" _    _\n| |  | |\n| |__| |\n|  __  |\n|_|  |_|\n");
            break;
        case 'Z':        case 'z':
            printf(" ______\n|____  |\n    / / \n   / /  \n  /_/   \n");
            break;
        default:
            printf("      \n      \n      \n      \n      \n"); // space
            break;
    }
}

int main(){
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin); // read in user input as a string

    for(int i=0; i<strlen(str); i++){
        print(str[i]); // call print function to print ASCII art of each character in the string
    }
    return 0;
}