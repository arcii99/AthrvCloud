//FormAI DATASET v1.0 Category: Compression algorithms ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*C Compression Algorithm*/

int main()
{
    char str[1000], compstr[1000];      // declare character arrays to store input and compressed strings
    printf("Enter a string to compress: ");
    fgets(str, sizeof(str), stdin);     // read input string from standard input

    int count = 1;
    char ch = str[0];
    int i, j = 0;
    for (i = 1; str[i] != '\0'; i++)     
    {
        if (ch == str[i])         
        {
            count++;    
        }
        else         
        {
            compstr[j] = ch;    
            compstr[j + 1] = count + '0'; 
            j += 2;     
            count = 1;  
            ch = str[i]; 
        }
    }
    // Add the last character and its count to compressed string
    compstr[j] = ch;
    compstr[j + 1] = count + '0';

    printf("Compressed string: %s\n", compstr);

    return 0;   
}