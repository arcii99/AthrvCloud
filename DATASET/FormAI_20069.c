//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char input[1000];
    int i = 0, j = 0;
    printf("Enter your string: ");
    fgets(input, 1000, stdin); //input from user 

    while (input[i] != '\0') //loop until the end of string found 
    {
        if (input[i] == '\n') 
        {
            input[i] = '\0'; //replace new line with null character 
            break;
        }

        if (input[i] >= 32 && input[i] <= 126) //only allow ASCII printable characters  
        {
            input[j] = input[i];
            j++;
        }
        i++;
    }
    input[j] = '\0'; //append null character to final string 

    printf("Your sanitized string is: %s\n", input); //output the sanitized string 
    return 0;
}