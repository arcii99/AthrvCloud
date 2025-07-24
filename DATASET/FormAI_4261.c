//FormAI DATASET v1.0 Category: Text processing ; Style: high level of detail
#include<stdio.h>
#include<string.h>

int main()
{
    char inputStr[100]; //Define input string
    char outputStr[100]; //Define output string
    int i, j=0, len=0; //Define loop variables i, j and length variable len

    printf("Enter a string of characters: ");
    scanf("%[^\n]%*c", inputStr); //Read input string from user

    len = strlen(inputStr); //Calculate length of input string

    //Loop through input string to remove all punctuation and spaces
    for(i=0; i<len; i++)
    {
        if((inputStr[i]>='a' && inputStr[i]<='z') || (inputStr[i]>='A' && inputStr[i]<='Z')) //Check if the character is an alphabet
        {
            outputStr[j] = inputStr[i]; //Copy the alphabet to output string
            j++; //Increment index of output string
        }
    }

    outputStr[j] = '\0'; //Terminate the output string with null character

    printf("\nProcessed output string without spaces and punctuation: %s", outputStr);

    return 0;
}