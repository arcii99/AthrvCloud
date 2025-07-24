//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: introspective
#include <stdio.h>
#include <string.h>

void printChar(char c){
    switch(c){
        case 'A': printf("  /\\      \n /  \\     \n/    \\    \n------    \n|    |    \n|    |    \n"); break;
        case 'B': printf("-----     \n|    \\    \n|     \\   \n|      \\  \n|     /   \n|    /    \n-----     \n"); break;
        case 'C': printf("  /----\\  \n /      \\ \n|        |\n|        |\n \\      /\n  \\----/ \n"); break;
        case 'D': printf("-----     \n|    \\    \n|     \\   \n|      \\  \n|     /   \n|    /    \n-----     \n"); break;
        case 'E': printf("------    \n|        |\n|        |\n------    \n|        |\n|        |\n------    \n"); break;
        case 'F': printf("------    \n|        |\n|        |\n------    \n|        |\n|        |\n|        |\n"); break;
        case 'G': printf("  /----\\  \n /      \\ \n|        |\n|    -----\n|        |\n|        |\n \\------/ \n"); break;
        case 'H': printf("|        |\n|        |\n|        |\n------    \n|        |\n|        |\n|        |\n"); break;
        case 'I': printf("  /\\      \n /  \\     \n/    \\    \n  |       \n  |       \n  |       \n------    \n"); break;
        case 'J': printf("  /\\      \n /  \\     \n|    |    \n|    |    \n \\  /     \n  \\/      \n"); break;
        case 'K': printf("|      / \n|     /  \n|    /   \n|   /    \n|  /     \n| /      \n|/       \n"); break;
        case 'L': printf("|        |\n|        |\n|        |\n|        |\n|        |\n \\------/ \n"); break;
        case 'M': printf("|\\     /|\n| \\   / |\n|  \\ /  |\n|   V   |\n|       |\n|       |\n|       |\n"); break;
        case 'N': printf("|\\      |\n| \\     |\n|  \\    |\n|   \\   |\n|    \\  |\n|     \\ |\n|      \\|\n"); break;
        case 'O': printf("  /----\\  \n /      \\ \n|        |\n|        |\n|        |\n|        |\n \\----__/ \n"); break;
        case 'P': printf("-----     \n|    \\    \n|     \\   \n|      \\  \n|        |\n|        |\n|        |\n"); break;
        case 'Q': printf("  /----\\  \n /      \\ \n|        |\n|        |\n|     /\\ |\n|    /  \\|\n \\----\\__/\n"); break;
        case 'R': printf("-----     \n|    \\    \n|     \\   \n|      \\  \n|     /   \n|    /    \n|/      \\ \n"); break;
        case 'S': printf("  /----\\  \n /      \\ \n|        |\n \\------\\\n        |\n|       /\n \\------/ \n"); break;
        case 'T': printf("-------   \n   |      \n   |      \n   |      \n   |      \n   |      \n   |      \n"); break;
        case 'U': printf("|        |\n|        |\n|        |\n|        |\n|        |\n \\------/ \n"); break;
        case 'V': printf("\\        /\n \\      / \n  \\    /  \n   \\  /   \n    \\/    \n"); break;
        case 'W': printf("|       |\n|       |\n|       |\n|       |\n|  /\\ |  |\n| /  \\|  |\n|/    \\__|\n"); break;
        case 'X': printf("\\      / \n \\    /  \n  \\  /   \n   \\/    \n  /\\      \n /  \\     \n/    \\    \n"); break;
        case 'Y': printf("\\      / \n \\    /  \n  \\  /   \n   \\/    \n   |      \n   |      \n   |      \n"); break;
        case 'Z': printf("-------- \n      /  \n     /   \n  --/    \n /       \n/        \n-------- \n"); break;
        case ' ': printf("\n\n\n"); break;
        default: printf("Invalid character"); break;
    }
}

void printASCIIart(char* string){
    int length = strlen(string);
    for(int i=0; i<7; i++){
        for(int j=0; j<length; j++){
            printChar(string[j]);
        }
        printf("\n");
    }
}

int main(){
    char string[100];
    printf("Enter a string to convert to ASCII art:\n");
    scanf("%[^\n]", string);
    printASCIIart(string);
    return 0;
}