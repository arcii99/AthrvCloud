//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: grateful
#include<stdio.h>
#include<string.h>

/*This is a Palindrome Program that checks if a given word or sentence is same even after reversing it*/

int main()
{
    char word[1000], reverse[1000],temp;
    int i, j, length;
 
    printf("Hey there! I am your Palindrome Checker.\n");
    printf("Please enter a word or sentence to check if it is a palindrome.\n");
    fgets(word, 1000, stdin);  //Taking input of word to be checked
  
    length = strlen(word);
    
    /* Reversing the input word and storing it in reverse[]*/
    for(i=0, j=length-1; i<j; i++, j--)
    {
        temp = word[i];
        word[i] = word[j];
        word[j] = temp;
    }
    
    printf("\nProcessing");
    
    /*Checking if the original word and the reversed word are same*/
    for(i=0; i<length; i++)
    {
        if(word[i] == reverse[i])
        {
            continue;
        }
        else
        {
            printf("\nThe given word or sentence is not a Palindrome.");
            return 0;
        }
    }
    
    printf("\nThe given word or sentence is a Palindrome. Awesome!");
    return 0;
}