//FormAI DATASET v1.0 Category: String manipulation ; Style: energetic
#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];  //declare a char array of size 100
    int i, j, k;    //declare some variables for later use

    printf("Enter a string: ");
    scanf("%s", str);   //get input from user

    //convert every alternate character in the string to uppercase
    for(i = 0; i < strlen(str); i++)
    {
        if(i % 2 == 0)
        {
            str[i] = toupper(str[i]);   //convert to uppercase if index is even
        }
    }

    //reverse the entire string
    j = strlen(str) - 1;    //set the last index
    for(i = 0; i < j; i++, j--)
    {
        k = str[i];
        str[i] = str[j];
        str[j] = k;
    }

    //replace every occurence of the letter 'o' with the letter 'x'
    for(i = 0; i < strlen(str); i++)
    {
        if(str[i] == 'o')
        {
            str[i] = 'x';
        }
    }

    printf("Final string: %s", str);   //print the modified string
    
    return 0;   //end of program
}