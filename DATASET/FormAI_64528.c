//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printShockedArt(char input[])
{
    for(int i=0; i<strlen(input); i++)
    {
        //convert character to ascii value
        int asciiVal = (int)input[i];
        
        //create shocked face ascii art depending on the ascii value
        switch(asciiVal)
        {
            case 65: //A
            case 97: //a
                printf("    / \\    \n");
                printf("   / _ \\   \n");
                printf("  / ___ \\  \n");
                printf(" /_/   \\_\\ \n");
                printf("a-A-aAa-aAa\n");
                break;
            case 66: //B
            case 98: //b
                printf(" _________ \n");
                printf("|  ___   |\n");
                printf("| |   |__| |\n");
                printf("| |___    |\n");
                printf("|_____|B__|\n");
                break;
            case 67: //C
            case 99: //c
                printf("   _____   \n");
                printf(" /  ___  \\ \n");
                printf("|  /   \\  |\n");
                printf("|  \\___/  |\n");
                printf(" \\_______/C\n");
                break;
            //continue adding ascii art for other letters and symbols
            default:
                printf("      __      \n");
                printf("     /  \\     \n");
                printf("     \\/\\/     \n");
                printf("              \n");
                printf("Shocked face! \n");
                break;
        }
    }
}

int main()
{
    char testString[] = "Hello, World!";
    
    printShockedArt(testString);
    
    return 0;
}