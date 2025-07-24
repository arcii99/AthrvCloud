//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: all-encompassing
#include <stdio.h>

//function to convert (some) characters to ASCII art
void toArt(char c) {
    switch(c) {
        case 'A':
            printf("  /\\  \n /  \\ \n/    \\n/------\\\nAVAVAVAV\n");
            break;
        case 'B':
            printf("|-----\\\n|      \\\n|-----\\\n|      \\\n|-----/\n");
            break;
        case 'C':
            printf("  _____\n /      \\\n/        \\\n\\        /\n \\_____/\n");
            break;
        //add more cases for other characters here
        default:
            printf("Sorry, unable to convert this character to ASCII art.\n");
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    printf("Your string in ASCII art:\n");
    for(int i=0; str[i]!='\0'; i++) {
        toArt(str[i]);
    }
    return 0;
}