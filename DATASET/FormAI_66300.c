//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: scientific
#include <stdio.h>
#include <string.h>

int main(){

    char text[50];
    int len;
    int i, j;

    printf("Enter the text you wish to convert to ASCII art:\n");
    scanf("%[^\n]", text);

    len = strlen(text);

    for(i=0; i<len; i++){

        switch(text[i]){
            case 'A':
                printf("      /\\\n");
                printf("     /  \\\n");
                printf("    /----\\\n");
                printf("   /      \\\n");
                printf("  /        \\\n");
                break;
            case 'B':
                printf("  _______\n");
                printf(" |   __  |\n");
                printf(" |  |__| |\n");
                printf(" |       |\n");
                printf(" |_______|\n");
                break;
            case 'C':
                printf("   _______\n");
                printf(" /   _____|\n");
                printf(" \\  \\_____ \n");
                printf("  \\_____  |\n");
                printf("        |/ \n");
                break;
            case 'D':
                printf("  _______ \n");
                printf(" |   _   |\n");
                printf(" |  | |  |\n");
                printf(" |  |_|  |\n");
                printf(" |_______|\n");
                break;
            case 'E':
                printf("  _______\n");
                printf(" |   ___ \\\n");
                printf(" |  |___| |\n");
                printf(" |   ___   |\n");
                printf(" |  |___|  |\n");
                printf(" |________|\n");
                break;
            case 'F':
                printf("  _______\n");
                printf(" |   ___ \\\n");
                printf(" |  |___|\n");
                printf(" |   ___  \n");
                printf(" |  |      \n");
                printf(" |__|      \n");
                break;
            case 'G':
                printf("   _______\n");
                printf(" /   _____/\n");
                printf(" \\_____  \\ \n");
                printf(" /  ____/ \n");
                printf("/\\______/\n");
                break;
            case 'H':
                printf("  /\\      /\\\n");
                printf(" /  \\    /  \\\n");
                printf("/____\\  /____\\\n");
                printf("\\    /  \\    /\n");
                printf(" \\__/    \\__/ \n");
                break;
            case 'I':
                printf("  _______\n");
                printf("     |\n");
                printf("     |\n");
                printf("     |\n");
                printf(" |___| \n");
                break;
            case 'J':
                printf("      __\n");
                printf("     |  |\n");
                printf("     |  |\n");
                printf("     |  |\n");
                printf(" \\__/   \n");
                break;
            case 'K':
                printf("  /\\   /\\\n");
                printf(" /  \\ /  \\\n");
                printf("|    X    |\n");
                printf(" \\  / \\  /\n");
                printf("  \\/   \\/ \n");
                break;
            case 'L':
                printf("  |\n");
                printf("  |\n");
                printf("  |\n");
                printf("  |\n");
                printf("  |_______\n");
                break;
            case 'M':
                printf("/\\      /\\\n");
                printf("|\\ \\    / /|\n");
                printf("| \\ \\  / / |\n");
                printf("|  \\ \\/ /  |\n");
                printf("|   \\  /   |\n");
                printf("|    \\/    |\n");
                printf("|           |\n");
                printf("|           |\n");
                break;
            case 'N':
                printf("/\\     |   \n");
                printf("|\\ \\    |   \n");
                printf("| \\ \\   |   \n");
                printf("|  \\ \\  |   \n");
                printf("|   \\ \\ |   \n");
                printf("|    \\ \\|   \n");
                printf("|       |   \n");
                printf("|       |   \n");
                break;
            case 'O':
                printf("   _____ \n");
                printf(" /      \\\n");
                printf("|        |\n");
                printf("|        |\n");
                printf("|______  |\n");
                printf("       |/ \n");
                break;
            case 'P':
                printf("  _______\n");
                printf(" |   __  \\\n");
                printf(" |  |__| |\n");
                printf(" |   ____/\n");
                printf(" |  |\n");
                printf(" |__|\n");
                break;
            case 'Q':
                printf("   _____ \n");
                printf(" /      \\\n");
                printf("|        |\n");
                printf("|   __   |\n");
                printf("|  |__|  |\n");
                printf("|______\\ | \n");
                break;
            case 'R':
                printf("  _______ \n");
                printf(" |   __  \\\n");
                printf(" |  |__| |\n");
                printf(" |   __   /\n");
                printf(" |  |  \\  \n");
                printf(" |__|\\__\\ \n");
                break;
            case 'S':
                printf("   _______\n");
                printf(" /   _____|\n");
                printf(" \\  \\_____\n");
                printf("  \\_____ \\\n");
                printf(" /_____/|\n");
                printf("|________|\n");
                break;
            case 'T':
                printf("  _______\n");
                printf("     |\n");
                printf("     |\n");
                printf("     |\n");
                printf("     |\n");
                printf("     |\n");
                printf("     |\n");
                printf("     |\n");
                break;
            case 'U':
                printf("  /\\    /\\\n");
                printf(" /  \\  /  \\\n");
                printf("|    ||    |\n");
                printf("|____||____|\n");
                printf("      |     \n");
                break;
            case 'V':
                printf(" /\\           /\\\n");
                printf("/  \\         /  \\\n");
                printf("|    \\     /    |\n");
                printf("|     \\___/     |\n");
                printf(" \\            /\n");
                printf("  \\          /\n");
                printf("   \\________/\n");
                break;
            case 'W':
                printf("/\\           /\\           /\\ \n");
                printf("|  \\       /    \\       /  |\n");
                printf("|    \\   /        \\   /    |\n");
                printf("|     \\/            \\/     |\n");
                printf("|     /\\            /\\     |\n");
                printf("|   /    \\        /    \\   |\n");
                printf("| /        \\    /        \\ |\n");
                printf("|/            /            \\|\n");
                break;
            case 'X':
                printf("\\   /\\\n");
                printf(" \\ /  \\\n");
                printf("  X    \n");
                printf(" / \\  /\n");
                printf("/   \\/ \n");
                break;
            case 'Y':
                printf("\\       /\n");
                printf(" \\     / \n");
                printf("  \\   /  \n");
                printf("   \\ /   \n");
                printf("    Y    \n");
                printf("    |    \n");
                printf("    |    \n");
                break;
            case 'Z':
                printf(" _______\n");
                printf("|___   _|\n");
                printf("    | |  \n");
                printf("    | |  \n");
                printf(" ___| |__\n");
                printf("|_______|\n");
                break;
            case ' ':
                printf("\n");
                printf("\n");
                printf("\n");
                printf("\n");
                break;
            default:
                printf("\nInvalid character detected!\n");
                return 0;
        }
    }
    return 0;
}