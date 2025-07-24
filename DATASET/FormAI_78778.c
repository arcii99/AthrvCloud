//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: puzzling
#include<stdio.h>
#include<string.h>

void printLetter(char c)
{
    switch(c){
        case 'A':
            printf("     /\\\n");
            printf("    /  \\\n");
            printf("   /____\\n");
            printf("  /      \\\n");
            printf(" /        \\\n");
            break;

        case 'B':
            printf(" ______\n");
            printf("|      \\\n");
            printf("|       \\\n");
            printf("|       /\n");
            printf("|______/\n");
            break;

        case 'C':
            printf("   _____\n");
            printf(" /       \\\n");
            printf("|\n");
            printf("|       \\\n");
            printf(" \\_____/\n");
            break;

        case 'D':
            printf(" _______\n");
            printf("|       \\\n");
            printf("|        \\\n");
            printf("|        /\n");
            printf("|_______/\n");
            break;

        case 'E':
            printf(" ______\n");
            printf("|      \\\n");
            printf("|_______\n");
            printf("|      \\\n");
            printf("|_______\\\n");
            break;

        case 'F':
            printf(" ______\n");
            printf("|      \\\n");
            printf("|_______\n");
            printf("|      \\\n");
            printf("|      \n");
            break;

        case 'G':
            printf("   _____\n");
            printf(" /       \\\n");
            printf("|         \n");
            printf("|    ____\\\n");
            printf(" \\_____/\n");
            break;

        case 'H':
            printf(" /\\      /\n");
            printf("/  \\    /  \\\n");
            printf("|         |\n");
            printf("|         |\n");
            printf("|         |\n");
            break;

        case 'I':
            printf(" _______\n");
            printf("|       |\n");
            printf("|       |\n");
            printf("|       |\n");
            printf("|_______|\n");
            break;

        case 'J':
            printf("         /\n");
            printf("        /\n");
            printf("        |\n");
            printf("        |\n");
            printf("\\______/ \n");
            break;

        case 'K':
            printf("/  \\    /  \\\n");
            printf("|        /\n");
            printf("|      / \n");
            printf("|     \\  \n");
            printf("\\      \\\n");
            break;

        case 'L':
            printf("       /\n");
            printf("      /\n");
            printf("     /\n");
            printf("|   /\n");
            printf("|__/\n");
            break;

        case 'M':
            printf("/\\      /\\\n");
            printf("|  \\    /  |\n");
            printf("|    \\/    |\n");
            printf("|          |\n");
            printf("|          |\n");
            break;

        case 'N':
            printf("/\\      |\\n");
            printf("|\\ \\     |\\n");
            printf("| \\ \\    |\\\n");
            printf("|  \\ \\   |\\\n");
            printf("|   \\ \\  |\\n");
            break;

        case 'O':
            printf("   ____\n");
            printf(" /      \\\n");
            printf("|        |\n");
            printf("|        |\n");
            printf(" \\______/\n");
            break;

        case 'P':
            printf(" _____\n");
            printf("|     \\\n");
            printf("|      \\\n");
            printf("|      /\n");
            printf("|     /\n");
            break;

        case 'Q':
            printf("   ____\n");
            printf(" /      \\\n");
            printf("|        |\n");
            printf("|     \\  |\n");
            printf(" \\______\\ \n");
            break;

        case 'R':
            printf(" ______\n");
            printf("|      \\\n");
            printf("|       \\\n");
            printf("|      / \n");
            printf("|     / \\\n");
            break;

        case 'S':
            printf(" _____\n");
            printf("/     \\\n");
            printf("\\_____/\n");
            printf("      \\\n");
            printf("\\_____/\n");
            break;

        case 'T':
            printf(" _______\n");
            printf("|       |\n");
            printf("        |\n");
            printf("        |\n");
            printf("        |\n");
            break;

        case 'U':
            printf("/        \\\n");
            printf("|         |\n");
            printf("|         |\n");
            printf("|         |\n");
            printf("\\_______/\n");
            break;

        case 'V':
            printf("/        \\\n");
            printf("\\        /\n");
            printf(" \\      /\n");
            printf("  \\    /\n");
            printf("   \\__/\n");
            break;

        case 'W':
            printf("/\\         /\\\n");
            printf("|  \\      /  |\n");
            printf("|    \\/\\/    |\n");
            printf("|            |\n");
            printf("|            |\n");
            break;

        case 'X':
            printf("\\        /\n");
            printf(" \\      /\n");
            printf("   \\  /\n");
            printf("   /  \\\n");
            printf("/      \\\n");
            break;

        case 'Y':
            printf("/\\      /\n");
            printf("\\  \\  /\n");
            printf(" \\    /\n");
            printf("  |  |\n");
            printf("  |__|\n");
            break;

        case 'Z':
            printf(" ______\n");
            printf("|      \\\n");
            printf(" \\     /\n");
            printf("  \\   /\n");
            printf("   \\__\\\n");
            break;

        default:
            printf("\nThe input character is not supported in the program");
    }
}

int main(){
    printf("Enter the string :");
    char str[1000];
    fgets(str, sizeof(str), stdin);
    printf("\n\n");
    int i,len;
    len=strlen(str)-1;
    printf("ASCII ART GENERATOR\n");
    printf("--------------------\n");
    for(i=0;i<len;i++){
        printLetter(str[i]);
        printf(" ");
    }
    printf("\n");
    return 0;
}