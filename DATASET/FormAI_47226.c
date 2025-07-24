//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: excited
#include <stdio.h>
#include <string.h>

int main()
{
    char input[100];
    int ascii_value;
    int i = 0;
    printf("Enter your input:\n");
    fgets(input, 100, stdin); //Get user input
    while (input[i] != '\0') //While loop to iterate through the input string
    {
        ascii_value = (int)input[i]; //Get the ASCII value of each character
        if ((ascii_value >= 65 && ascii_value <= 90) || (ascii_value >= 97 && ascii_value <= 122)) 
            //Check if character is an alphabet
        {
            if (ascii_value >= 65 && ascii_value <= 90) //If uppercase alphabet
            {
                ascii_value += 32; //Convert to lowercase
                input[i] = (char)ascii_value; //Assign new value to input string
            }
        }
        else if (ascii_value == 32) //If space
        {
            input[i] = '_'; //Replace with underscore
        }
        else if (ascii_value >= 48 && ascii_value <= 57) //If digit
        {
            //Do nothing, leave it as it is
        }
        else //If any other character
        {
            input[i] = '?'; //Replace with question mark
        }
        i++; //Move to next character in string
    }
    printf("\nYour sanitized input is:\n%s", input); //Display sanitized input
    return 0;
}