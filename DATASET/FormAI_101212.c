//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 1000                    // Maximum length of user input
#define ART_ROW 7                       // Number of ASCII art rows
#define ART_COL 50                      // Number of ASCII art columns

// ASCII art patterns
const char ART_PATTERN[ART_ROW][ART_COL] = 
{
    "   ___                 __    ____                ",
    "  / _ )___  ___ ______/ /__ / __/_________ _____",
    " / _  / _ \\/ -_) __/ _  / -_) _/ __/ __/ // / -_)",
    "/____/ .__/\\__/_/  \\_,_/\\__/_/ \\__/\\__/_\\_,_/_/  ",
    "    /_/                                          ",
    "                                                 ",
    "                                                 "
};

// Function to display the ASCII art
void display_art()
{
    int i, j;

    for(i = 0; i < ART_ROW; i++)
    {
        for(j = 0; j < ART_COL; j++)
        {
            printf("%c", ART_PATTERN[i][j]);
        }
        printf("\n");
    }
}

// Function to convert user input to ASCII art
void convert_to_art(char* str)
{
    int i, j, len;
    char art[ART_ROW][MAX_LEN];

    len = strlen(str);

    // Convert each character of user input to ASCII art
    for(i = 0; i < ART_ROW; i++)
    {
        for(j = 0; j < len; j++)
        {
            if(str[j] >= 'A' && str[j] <= 'Z')
            {
                art[i][j] = ART_PATTERN[i][str[j]-'A'];
            }
            else if(str[j] >= 'a' && str[j] <= 'z')
            {
                art[i][j] = ART_PATTERN[i][str[j]-'a'];
            }
            else if(str[j] == ' ')
            {
                art[i][j] = ' ';
            }
            else
            {
                art[i][j] = '?';
            }
        }
    }

    // Display the converted ASCII art
    for(i = 0; i < ART_ROW; i++)
    {
        for(j = 0; j < len; j++)
        {
            printf("%c", art[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    char input_str[MAX_LEN];

    printf("Welcome to ASCII Art Generator!\n\n");
    printf("Enter your string (max %d characters): ", MAX_LEN);
    fgets(input_str, MAX_LEN, stdin);

    printf("\nOriginal string:\n%s\n\n", input_str);

    printf("ASCII art:\n");
    display_art();                      // Display the original ASCII art

    printf("\nConverted string to ASCII art:\n");
    convert_to_art(input_str);          // Convert user input to ASCII art and display

    return 0;
}