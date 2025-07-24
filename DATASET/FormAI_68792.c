//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: introspective
#include<stdio.h>
#include<string.h>

/*
 * Function to print the character as ASCII art
 */
void print_art(char ch) {
    switch(ch) {
        case 'A':
            printf("  /\\  \n");
            printf(" /  \\ \n");
            printf("/____\\\n");
            break;
        case 'B':
            printf("|¯¯¯¯\\ \n");
            printf("|    | \n");
            printf("|____/ \n");
            break;
        case 'C':
            printf("  ___ \n");
            printf(" /   \\\n");
            printf("|     \n");
            printf(" \\___/\n");
            break;
        /*Add more cases for ASCII art*/
        default:
            printf("Invalid character\n");
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    /* Reading string from user */
    fgets(str, sizeof(str), stdin);
    /* Removing the \n character from string */
    str[strcspn(str, "\n")] = 0;
    printf("ASCII art for entered string:\n");
    int len = strlen(str);
    for(int i=0; i<len; i++) {
        print_art(str[i]);
    }
    return 0;
}