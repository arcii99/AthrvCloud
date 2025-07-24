//FormAI DATASET v1.0 Category: Spam Detection System ; Style: multivariable
#include<stdio.h>
#include<string.h>

int main()
{
    char input[1000]; //declaring input variable to store user input
    int i, j, count = 0, flag = 0; //declaring variables for counting characters, and checking flag

    printf("Enter your message: "); 
    fflush(stdout); //clearing the buffer
    fgets(input, 1000, stdin); //taking user input as string

    for(i = 0; input[i] != '\0'; i++) //iterating through input string
    {
        //checking for repeated characters in input
        if(input[i] == input[i+1] && (input[i] >= 'a' && input[i] <= 'z' || input[i] >= 'A' && input[i] <= 'Z'))
        {
            count++; //increasing count variable if repeated character found
        }
        else 
        {
            count = 0;
        }

        //checking for consecutive vowels in input
        if(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u' || input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U') 
        {
            if(input[i+1] == 'a' || input[i+1] == 'e' || input[i+1] == 'i' || input[i+1] == 'o' || input[i+1] == 'u' || input[i+1] == 'A' || input[i+1] == 'E' || input[i+1] == 'I' || input[i+1] == 'O' || input[i+1] == 'U')
            {
                flag++; //increasing flag variable if consecutive vowels found
            }
        }

        //checking for digit count in input
        if(isdigit(input[i])) //checking if the character is a digit
        {
            if(isdigit(input[i+1])) 
            {
                count++; //increasing count variable if two or more consecutive digits found
            }
            else 
            {
                count = 0;
            }
        }
        else
        {
            count = 0;
        }
    }

    //checking for spam messages
    if(flag >= 2 || count >= 3) 
    {
        printf("This message appears to be spam.\n");
    }
    else 
    {
        printf("This message is not spam.\n");
    }

    return 0;
}