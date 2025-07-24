//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Ada Lovelace
#include<stdio.h>
#include<string.h>

void printChar(char c){
    switch(c){
        case 'A':
            printf("        /\\\n       /  \\\n      /    \\\n     /      \\\n    /________\\\n   /\\        /\\\n  /  \\      /  \\\n /    \\    /    \\\n/      \\  /      \\\n\n");
            break;
        case 'B':
            printf("_______\n|      |\n|______|\n|      |\n|______|\n|      |\n|______|\n\n");
            break;
        case 'C':
            printf("  ______\n/       \\\n|        \\\n|          \n|        /\n|______/\n\n");
            break;
        case 'D':
            printf(" _______\n|       \\\n|        \\\n|        /\n|       /\n|______/\n\n");
            break;
        case 'E':
            printf("________\n|         \n|________\n|         \n|________\n\n");
            break;
        case 'F':
            printf("________\n|         \n|________\n|         \n|\n\n");
            break;
        case 'G':
            printf("  ______\n/       \\\n|         \n|     ____\n\\       /\n  \\_____\\\n\n");
            break;
        case 'H':
            printf("         \n|       |\n|_______|\n|       |\n|       |\n\n");
            break;
        case 'I':
            printf(" ____\n|__  |\n   | |\n   | |\n___| |___\n\n");
            break;
        case 'J':
            printf("      ____\n     |\n     |\n     |\n     |____\n/_______/\n\n");
            break;
        case 'K':
            printf("   \n|  / \\\n| /   \\\n| \\   /\n|  \\ /\n\n");
            break;
        case 'L':
            printf("|\n|\n|\n|\n|______\n\n");
            break;
        case 'M':
            printf("        /\\       /\\     \n       /  \\     /  \\    \n      /    \\   /    \\   \n     /      \\ /      \\  \n    /        V        \\ \n   /         |         \\ \n  /          |          \\ \n /_____      |      _____\\\n       |     |     |      \n       |_____|_____|      \n\n");
            break;
        case 'N':
            printf("        /\\      |      \\\n       /  \\     |       \\\n      /    \\    |        \\\n     /      \\   |         \\\n    /        \\  |         /\n   /          \\ |        /\n  /            \\|       /\n /______________\\_____/\n\n");
            break;
        case 'O':
            printf("  ______\n/       \\\n|       |\n|       |\n\\       /\n  \\____/\n\n");
            break;
        case 'P':
            printf("_______\n|      |\n|______|\n|      \n|\n\n");
            break;
        case 'Q':
            printf("  ______\n/       \\\n|       |\n|       |\n\\     \\|\n  \\____\\_\n\n");
            break;
        case 'R':
            printf(" _______\n|       \\\n|        \\\n|       / \n|______/\n\n");
            break;
        case 'S':
            printf("  ______\n/       \n|        \n|_______\n       /\n  ______\n\n");
            break;
        case 'T':
            printf("________\n   |   \n   |___\n   |   \n   |___\n\n");
            break;
        case 'U':
            printf("         \n|       |\n|       |\n|       |\n \\     /\n  \\___/\n\n");
            break;
        case 'V':
            printf("         \n\\       /\n \\     /\n  \\   /\n   \\ /\n    V\n\n");
            break;
        case 'W':
            printf("         \n/\\     /\\      /\\     /\\ \n\\ \\   /  \\    /  \\   / / \n \\ \\ /    \\  /    \\ / /  \n  \\\\      \\/      //   \n   \\\\              //    \n    \\\\____/\\____//     \n\n");
            break;
        case 'X':
            printf("        \n\\      /\n \\    /\n  \\  /\n   \\/\n  /\\\n /  \\\n/    \\\n\n");
            break;
        case 'Y':
            printf("        \n\\      /\n \\    /\n  \\  /\n   ||\n   ||\n   ||\n   ||\n\n");
            break;
        case 'Z':
            printf("________\n      /\n     /\n    /\n   /\n  /\n /\n/________\n\n");
            break;
        case ' ':
            printf("     \n     \n     \n     \n     \n     \n     \n     \n\n");
            break;
        case '!':
            printf(" _ \n| |\n| |\n|_|\n(_)\n\n");
            break;
        case '@':
            printf("            /\\        \n       ___ /  \\       \n     /     o\\/       \n     \\__    /        \n        /\\_/\\       \n       /     \\      \n      /       \\     \n\n");
            break;
        case '#':
            printf("   ###   ### \n  ## ## ## ##\n   ###   ### \n # ## ## ## #\n   ###   ### \n  ## ## ## ##\n   ###   ### \n\n");
            break;
        case '$':
            printf("    __      \n  _|  |___\n |___    /\n     |_|\n\\__     \\\n   |_____\\\n\n");
            break;
        case '%':
            printf("          /\\\n|      //  \\\n|     //\n\\__  \\\\\n/  \\__\\\\\n\\      _/\n \\\\  /\n  \\\\/\n");
            break;
        case '^':
            printf("    __      \n  //\\\\\\  \n //  \\\\\\\n\n");
            break;
        case '&':
            printf("     ___   __\n  /      \\/  \\\n |___  __|___|\n     \\/   \\___\n\n");
            break;
        case '*':
            printf("    *\n  * * *\n   ***\n\n");
            break;
        case '(':
            printf("    __\n   / /\n  / /\n | |\n | |\n  \\ \\\n   \\_\\\n\n");
            break;
        case ')':
            printf("  __\n  \\ \\\n   \\ \\\n   | |\n   | |\n  / /\n /_/\n\n");
            break;
        case '-':
            printf("\n\n\n___\n\n\n\n");
            break;
        case '_':
            printf("\n\n\n\n\n\n___\n\n");
            break;
        case '+':
            printf("     \n     \n  ___\n |___|\n  |_|\n  |_|\n   |\n\n");
            break;
        default:
            printf("\n");
            break;
    }
}

int main(){
    char input[1000];
    printf("Enter text to convert to ASCII art:\n");
    scanf("%[^\n]", input);
    printf("\n");
    int length = strlen(input);
    for(int i=0; i<length; i++){
        printChar(input[i]);
    }
    return 0;
}