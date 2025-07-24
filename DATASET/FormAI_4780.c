//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: creative
#include <stdio.h>

// Function to print the ASCII art
void printASCIIArt(char *text) {
    // Define the ASCII art array
    char art[8][80] = {
        "        ,-.                            ",
        "        / ()\\                          ",
        "       |`    `|                         ",
        "       \\  ()  /                         ",
        "        `.  ,'                          ",
        "        |\\  /|                          ",
        "        \\ `'/                           ",
        "         `-'                            " 
    };
    
    // Print each line of the ASCII art array 
    for(int i=0; i<8; i++) {
        for(int j=0; text[j]!='\0'; j++) {
            if(text[j]>='a' && text[j]<='z') {
                printf("%c", art[i][text[j]-'a']);
            }
            else if(text[j]>='A' && text[j]<='Z') {
                printf("%c", art[i][text[j]-'A']);
            }
            else {
                printf("%c", text[j]);
            }
        }
        printf("\n");
    }
}

// Main function
int main() {
    char text[50];
    
    // Prompt the user for input
    printf("Enter your text to convert to ASCII art: ");
    scanf("%[^\n]", text);
    
    // Print the ASCII art
    printASCIIArt(text);
    
    return 0;
}