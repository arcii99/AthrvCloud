//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

char ASCII_ART[127][9] = {
    // ASCII Code 32
    {"        "},
    // ASCII Code 33 (!)
    {"   ||   "},
    {"   ||   "},
    {"   ||   "},
    {"   ||   "},
    {"   ||   "},
    {"   ||   "},
    {"   ||   "},
    {"   ||   "},
    {"   ||   "},
    {"________"},
    // ASCII Code 34 (")
    {"\\      /"},
    {" \\____/ "},
    {"        "},
    {"        "},
    {"        "},
    {"        "},
    {"        "},
    {"        "},
    {"        "},
    {"        "},
    // ASCII Code 35 (#)
    {"   /\\   "},
    {"  //\\\\  "},
    {" //  \\\\ "},
    {"////////"},
    {"  \\\\  //" },
    {"   \\\\//  "},
    {"        "},
    {"        "},
    {"        "},
    {"        "},
    // ASCII Code 36 ($)
    {"    $   "},
    {"  $$$$  "},
    {"$ |__| $"},
    {"  $|$   "},
    {"  $|$   "},
    {"$ |__| $" },
    {"  $$$$  "},
    {"    $   "},
    {"        "},
    {"        "},
};

int main() 
{
    char input[MAX_INPUT_LENGTH];
    printf("Enter text for ASCII art: \n");
    fgets(input, MAX_INPUT_LENGTH, stdin);  // get user input from command line

    // covert the input string to upper case and remove newline
    for(int i = 0; i < strlen(input); i++) {
        if (input[i] == '\n') {
            input[i] = '\0';
        } else {
            input[i] = toupper(input[i]);
        }
    }

    // loop through each character in the input string and print out the corresponding ASCII art
    for(int i = 0; i < strlen(input); i++) {
        char c = input[i];
        if(c >= 32 && c <= 126) {  // check if character is within ASCII range
            printf("%s  ", ASCII_ART[c]); // print ASCII art
        } else {
            printf("   "); // print empty space
        }
    }
    printf("\n");
    return 0;
}