//FormAI DATASET v1.0 Category: Pattern printing ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

void printChar(char c, int n);

int main()
{
    srand(time(NULL));
    int num = rand() % 5 + 3; // random number between 3-7
    char alpha = 'A';
    int spaces = num - 1;
    
    // Print top half of C pattern
    for(int i=0; i<num; i++)
    {
        printChar(' ', spaces);
        if(i==0 || i==num-1) // first and last line
            printChar(alpha, num);
        else
            printf("%c", alpha);
        printf("\n");
        alpha++;
        spaces--;
    }
    
    // Print bottom half of C pattern
    spaces = 0;
    alpha -= 2; // move back one letter before last
    for(int i=num-1; i>=0; i--)
    {
        printChar(' ', spaces);
        if(i==0 || i==num-1) // first and last line
            printChar(alpha, num);
        else
            printf("%c", alpha);
        printf("\n");
        alpha--;
        spaces++;
    }
    
    return 0;
}

void printChar(char c, int n)
{
    for(int i=0; i<n; i++)
        printf("%c", c);
}