//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: grateful
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

// Define ASCII art for each letter
char A[] =
"  /\\ \n"
" /  \\ \n"
"/____\\ ";

char B[] =
"|\\       /|\n"
"| \\     / |\n"
"|  \\   /  |\n"
"|   \\ /   |\n"
"|    /    |\n"
"|___/\\___|";

// More letters defined here...

char error[] = 
"  ____\n"
" /    \\\n"
"|      |\n"
"|      |\n"
"|      |\n"
"|______|\n"
"  /||\\\n"
" / || \\\n"
"/__||__\\\n";


int main() {
    char input[MAX_LINE_LENGTH];
    printf("Enter text to be converted to ASCII art:\n");
    fgets(input, MAX_LINE_LENGTH, stdin);
    int length = strlen(input);
    for (int i = 0; i < length; i++) {
        char c = input[i];
        switch (c) {
            case 'A':
                printf("%s\n", A);
                break;
            case 'B':
                printf("%s\n", B);
                break;
            // More cases for each letter...
            default:
                printf("%s", error);
        }
    }
    return 0;
}