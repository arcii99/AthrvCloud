//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: surprised
#include <stdio.h>
#include <string.h>

int main()
{
    char input[100];
    
    printf("Enter your text: ");
    fgets(input, 100, stdin); // Read input from user
    
    // ASCII Art generator starts here
    printf("                      _       _           _     _ \n");
    printf("  ____ _ _ __ ___  (_)___  (_)___  __ _| | __| |\n");
    printf(" / _  | '_ ` _ \\   | / __| | / __|/ _` | |/ _` |\n");
    printf("| (_| | | | | | |  | \\__ \\ | \\__ \\ (_| | | (_| |\n");
    printf(" \\__,_|_| |_| |_|  |_|___/ |_|___/\\__,_|_|\\__,_|\n");
    printf("\n");
    
    int length = strlen(input);
    
    for(int i=0;i<length;i++)
    {
        printf("     ");
        for(int j=0;j<5;j++)
        {
            char c = input[i];
            if(c == ' ')
            {
                printf("   ");
            }
            else
            {
                printf("%c  ", c);
            }
        }
        printf("\n");
    }
    
    printf("\n");
    return 0;
}