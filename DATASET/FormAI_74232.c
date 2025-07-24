//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: immersive
#include <stdio.h>

int main() {
    printf("Welcome to the Text to ASCII Art Generator!\n\n");
    printf("Please enter the text you would like to convert: ");
    
    char text[100];
    fgets(text, 100, stdin);
    printf("\n");

    printf("Converting...\n\n");

    for (int i = 0; i < 10; i++) {
        for (int j = 0; text[j] != '\0'; j++) {
            switch(text[j]) {
                case 'a': printf("      /\\      \n     /  \\     \n    /    \\    \n   /------\\   \n  /        \\  \n /          \\ \n"); break;
                case 'b': printf(" --------   \n|        \\  \n|         | \n|         | \n|         | \n|        /  \n--------'   \n"); break;
                case 'c': printf("   ______   \n /        \\ \n/           \\\n|            \n\\           /\n \\_________/ \n"); break;
                case 'd': printf("-------   \n|     \\  \n|      | \n|      | \n|      | \n|     /  \n-------' \n"); break;
                case 'e': printf("-------- \n|         \n|         \n--------  \n|         \n|         \n-------- \n"); break;
                case 'f': printf("-------- \n|         \n|         \n--------  \n|         \n|         \n|         \n"); break;
                case 'g': printf(" ________ \n/        \\\n|         \\\n|          |\n|  ____    |\n\\    /    \n \\__/     \n"); break;
                case 'h': printf("|        |\n|        |\n|--------|\n|        |\n|        |\n|        |\n|        |\n"); break;
                case 'i': printf(" ______ \n|      |\n|      |\n|      |\n|      |\n|      |\n|______|\n"); break;
                case 'j': printf("    ____ \n   |    |\n   |    |\n   |    |\n __|    |\n|       |\n \\______/\n"); break;
                case 'k': printf("|       /\n|     /  \n|---<    \n|     \\  \n|       \\\n|        \\\n|         \\\n"); break;
                case 'l': printf("|         \n|         \n|         \n|         \n|         \n|         \n|_______  \n"); break;
                case 'm': printf("|\\     /| \n| \\   / | \n|  \\ /  | \n|       | \n|       | \n|       | \n|       |\n"); break;
                case 'n': printf("|\\        |\n| \\       |\n|  \\      |\n|   \\     |\n|    \\    |\n|     \\   |\n|      \\  |\n"); break;
                case 'o': printf("   ____   \n /      \\ \n/        \\\n|        |\n\\        /\n \\______/ \n"); break;
                case 'p': printf("-------- \n|       \\\n|        |\n|-------/\n|         \n|         \n|         \n"); break;
                case 'q': printf("  ^-----^ \n /       \\\n|         |\n|         |\n|   __  __/\n\\   \\/ /  \n \\___\\/   \n"); break;
                case 'r': printf("--------  \n|       \\\n|        |\n|   __ _/\n|      \\  \n|       \\ \n|        \\\n"); break;
                case 's': printf(" ___ \n|    \\\n|    |\n \\___/\n    \\ \n    | \n\\___/ \n"); break;
                case 't': printf(" ______ \n|      |\n|      |\n|      |\n|      |\n|      |\n \\____/ \n"); break;
                case 'u': printf("|        |\n|        |\n|        |\n|        |\n|        |\n \\______/ \n"); break;
                case 'v': printf("\\        /\n \\      / \n  \\    /  \n   \\  /   \n    \\/    \n"); break;
                case 'w': printf("|       |\n|       |\n|       |\n|   |   |\n|   |   |\n|___|___|\n"); break;
                case 'x': printf("\\      /\n  \\  /  \n    \\/   \n    /\\   \n  /    \\ \n/        \\\n"); break;
                case 'y': printf("\\      /\n \\    / \n  \\  /  \n   \\/   \n   /    \n  /     \n/       \n"); break;
                case 'z': printf(" ______\n|     /\n|    / \n|   /  \n|  /   \n| /    \n|/_____\n"); break;
                default: printf("      \n      \n      \n      \n      \n      \n      \n"); break;
            }
            printf("    ");
        }
        printf("\n");
    }

    return 0;
}