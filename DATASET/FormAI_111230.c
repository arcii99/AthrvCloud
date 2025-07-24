//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: high level of detail
#include <stdio.h>

/* function to convert character to ASCII art */
void printArt(char c) {
    switch(c) {
        case 'A':
        case 'a':
            printf("   /\\   \n");
            printf("  /  \\  \n");
            printf(" / /\\ \\ \n");
            printf("/ ____ \\\n");
            printf("_/    \\_\n");
            break;
        case 'B':
        case 'b':
            printf(" ____  \n");
            printf("|  _ \\ \n");
            printf("| |_) )\n");
            printf("|  _ ( \n");
            printf("| |_) )\n");
            printf("|____/ \n");
            break;
         /* Add more ASCII characters here */
        default:
            printf("Invalid character!\n");
            break;
    }
}

/* main function */
int main() {
    char str[50];
    int i = 0;
    
    printf("Enter a string: ");
    fgets(str, 50, stdin);
    
    printf("\n");
    while(str[i] != '\0') {
        printArt(str[i]);
        i++;
    }
    
    return 0;
}