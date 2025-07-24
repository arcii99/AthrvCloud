//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[100];
    char morse[100][10] = {
        {'.', '-', '.', '.', '.'},   //A
        {'-', '.', '.', '.', '-'},   //B
        {'-', '.', '-', '.', '-'},   //C
        {'-', '.', '.', '.', '.'},   //D
        {'.', '.', '-', '.', '.'},   //E
        {'.', '.', '.', '-', '.'},   //F
        {'-', '-', '.', '.', '-'},   //G
        {'.', '.', '.', '.', '.'},   //H
        {'.', '.', '.', '.'},        //I
        {'.', '-', '-', '-'},        //J
        {'-', '.', '-', '-'},        //K
        {'.', '-', '.', '.', '.'},   //L
        {'-', '-', '.', '.'},        //M
        {'-', '.', '.', '.'},        //N
        {'-', '-', '-', '-'},        //O
        {'.', '-', '-', '.', '.'},   //P
        {'-', '-', '.', '-'},        //Q
        {'.', '-', '.', '.'},        //R
        {'.', '.', '.', '-'},        //S
        {'-', '-'},                  //T
        {'.', '.', '-', '-'},        //U
        {'.', '.', '.', '-'},        //V
        {'.', '-', '-'},             //W
        {'-', '.', '.', '-'},        //X
        {'-', '.', '-', '-'},        //Y
        {'-', '-', '.', '.'},        //Z
        {' ', ' '},                  //SPACE
    };
    printf("Enter a text string: ");
    fgets(text, 100, stdin);
    printf("The Morse Code for %s is: \n", text);

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            char c = toupper(text[i]);
            int index = (int)c - 65;
            if (c == ' ')
            {
                printf(" ");
            }
            else
            {
                for (int j = 0; j < 5; j++)
                {
                    printf("%c", morse[index][j]);
                }
                printf(" ");
            }
        }
    }
    printf("\n");
    return 0;
}