//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char str[100];
    printf("Enter text: ");
    fgets(str, 100, stdin); // Read string from user input
    
    int length = strlen(str);
    
    //Print the ASCII art based on the input
    printf("  ___ _               __     _        \n");
    printf(" / __| |_  _ _ _  ___/ /__  (_)___ ___\n");
    printf("| (_ | ' \\| ' \\/ _ \\ / / _ \\| / -_|_-<\n");
    printf(" \\___|_||_|_||_\\___/_/\\___/|_\\___/__/ \n\n");

    //Loop through each character of the string
    for(int i=0; i<length; i++){
        switch(str[i]){
            // Letters
            case 'A':
            case 'a':
                printf("  /\\  \n /  \\ \n/ /\\ \\n");
                break;
            case 'B':
            case 'b':
                printf("|||| \n||__/ \n||_|_ \n");
                break;
            case 'C':
            case 'c':
                printf("  ___ \n / __| \n \\__  \n");
                break;
            case 'D':
            case 'd':
                printf("||||| \n||__| \n||__| \n");
                break;
            case 'E':
            case 'e':
                printf("|||| \n|__/ \n||__ \n");
                break;
            case 'F':
            case 'f':
                printf("||||| \n||__  \n||    \n");
                break;
            case 'G':
            case 'g':
                printf(" __|_ \n|_   \\\n|__|_/\n");
                break;
            case 'H':
            case 'h':
                printf("|| || \n|=|=| \n|| || \n");
                break;
            case 'I':
            case 'i':
                printf("|| \n|| \n|| \n");
                break;
            case 'J':
            case 'j':
                printf("   || \n   || \n|__|| \n");
                break;
            case 'K':
            case 'k':
                printf("|| /  \n||<   \n|| \\_ \n");
                break;
            case 'L':
            case 'l':
                printf("||    \n||___ \n||    \n");
                break;
            case 'M':
            case 'm':
                printf("||\\/||\n||  ||\n||  ||\n");
                break;
            case 'N':
            case 'n':
                printf("||\\ ||\n|| \\||\n||  ||\n");
                break;
            case 'O':
            case 'o':
                printf(" __  \n/  \\ \n\\__/ \n");
                break;
            case 'P':
            case 'p':
                printf("|||| \n||/  \n||   \n");
                break;
            case 'Q':
            case 'q':
                printf(" __  \n/  \\ \n\\__X \n");
                break;
            case 'R':
            case 'r':
                printf("||||  \n||/   \n||\\_  \n");
                break;
            case 'S':
            case 's':
                printf(" ____\n/ __/\n\\___\\\n");
                break;
            case 'T':
            case 't':
                printf("||||| \n ||   \n ||   \n");
                break;
            case 'U':
            case 'u':
                printf("|| || \n|| || \n||_|| \n");
                break;
            case 'V':
            case 'v':
                printf("\\    / \n \\  /  \n  \\/   \n");
                break;
            case 'W':
            case 'w':
                printf("|| || \n|| || \n|| || \n");
                break;
            case 'X':
            case 'x':
                printf("\\  / \n ><  \n/  \\ \n");
                break;
            case 'Y':
            case 'y':
                printf("\\  / \n \\/  \n /   \n");
                break;
            case 'Z':
            case 'z':
                printf("==== \n  /  \n==== \n");
                break;
            // Numbers
            case '0':
                printf(" __  \n/  \\ \n\\__/ \n");
                break;
            case '1':
                printf(" /| \n/ | \n  | \n");
                break;
            case '2':
                printf(" __  \n/_/\\ \n\\_\\/ \n");
                break;
            case '3':
                printf(" ____\n\\__ \\\n/___/\n");
                break;
            case '4':
                printf(" / '\\ \n/__'\\\n    < \n");
                break;
            case '5':
                printf(" ____\n/___ \\\n\\___/\n");
                break;
            case '6':
                printf(" ____\n/ __/\n\\__ \\\n");
                break;
            case '7':
                printf("==== \n  /  \n /   \n");
                break;
            case '8':
                printf(" ___ \n/ _ \\\n\\___/\n");
                break;
            case '9':
                printf(" ___ \n/ _ \\\n\\__X\n");
                break;
            // Symbols
            case ' ':
                printf("    \n    \n    \n");
                break;
            case '.':
                printf(" /\\ \n\\/__\n    \n");
                break;
            case ',':
                printf("    \n /\\ \n(())\n");
                break;
            case ';':
                printf(" /\\ \n(())\n/\\ \n");
                break;
            case ':':
                printf(" :: \n    \n :: \n");
                break;
            case '!':
                printf(" |  \n |  \n o  \n");
                break;
            case '?':
                printf(" ___ \n/__X\\\n |__/\n");
                break;
            case '\"':
                printf(" /\\ /\\ \n/  V  \n      \n");
                break;
            default:
                printf("    \n    \n    \n");
                break;
        }
    }
    return 0;
}