//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LEN 50
#define MAX_ASCII_WIDTH 80


void print_header(char* text) {
    printf("\n");
    for(int i=0; i<(MAX_ASCII_WIDTH-strlen(text))/2; i++)
        printf(" ");
    printf("%s\n", text);
}

void print_bottom_border() {
    printf("\n");
    for(int i=0; i<MAX_ASCII_WIDTH; i++)
        printf("*");
    printf("\n");
}

int main() {
    char ascii_char[126][10] = {
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        " *****     ",
        "**   **    ",
        "**    **   ",
        "**     **  ",
        "**      ** ",
        "**       **",
        "**       **",
        "**       **",
        "**      ** ",
        "**     **  ",
        "**    **   ",
        "**   **    ",
        " *****     ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "*           *",
        "**         **",
        "***       ***",
        "****     ****",
        "** **   ** **",
        "**  ** **  **",
        "**   ***   **",
        "**    *    **",
        "**         **",
        "**         **",
        "**         **",
        "**         **",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "*****      ",
        "**   **    ",
        "**    **   ",
        "**     **  ",
        "**     **  ",
        "**     **  ",
        "**     **  ",
        "**     **  ",
        "**     **  ",
        "**     **  ",
        "**    **   ",
        "**   **    ",
        "*****      ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "**     **  ",
        "***    **  ",
        "****   **  ",
        "** **  **  ",
        "**  ** **  ",
        "**   ****  ",
        "**    ***  ",
        "**     **  ",
        "**     **  ",
        "**     **  ",
        "**     **  ",
        "**     **  ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "           ",
        "**     **  ",
        "***    **  ",
        "****   **  ",
        "** **  **  ",
        "**  ** **  ",
        "**   ****  ",
        "**    ***  ",
        "**     **  ",
        "**     **  ",
        "**     **  ",
        "**     **  ",
        "**     **  ",
        "           ",
    };
    
    char input[MAX_INPUT_LEN];
    printf("Enter a text: ");
    fgets(input, MAX_INPUT_LEN, stdin);
    input[strcspn(input, "\n")] = 0;

    int input_len = strlen(input);
    int width = input_len * 9 + 10;

    if(width > MAX_ASCII_WIDTH)
        width = MAX_ASCII_WIDTH;

    //Print ASCII art
    print_header(input);

    for(int row=0; row<11; row++) {
        for(int col=0; col<input_len; col++) {
            printf("%s", ascii_char[input[col]][row]);
        }
        printf("\n");
    }

    print_bottom_border();

    return 0;
}