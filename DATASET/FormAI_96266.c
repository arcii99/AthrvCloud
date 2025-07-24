//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: intelligent
#include <stdio.h>

// function to convert a character to ASCII art
void charToArt(char c){
    switch(c){
        case 'A':
            printf("   /\\   \n");
            printf("  /  \\  \n");
            printf(" / /\\ \\ \n");
            printf("/ ____ \\\n");
            printf("/_/  \\_\\\n");
            break;
        case 'B':
            printf(" ____ \n");
            printf("|  _ \\ \n");
            printf("| |_) |\n");
            printf("|  _ < \n");
            printf("|_| \\_\\\n");
            break;
        case 'C':
            printf("  ____ \n");
            printf(" / ___\\\n");
            printf("| |    \n");
            printf("| |___ \n");
            printf(" \\____\\\n");
            break;
        // add more cases for other characters
        default:
            printf("   /\n");
            printf("  / \\\n");
            printf(" /   \\\n");
            printf("/_/\\_\\\n");
            break;
    }
}

int main(){
    char str[100];
    printf("Enter a string: ");
    scanf("%[^\n]s", str); // read the input string with spaces

    // loop through each character in the string and convert it to ASCII art
    for(int i=0; str[i]!='\0'; i++){
        charToArt(str[i]);
    }

    return 0;
}