//FormAI DATASET v1.0 Category: String manipulation ; Style: statistical
#include<stdio.h>
#include<string.h>

int main()
{
    char original_string[100], new_string[100];
    int length, i, j, frequency[26] = {0};

    printf("Enter a string: ");
    gets(original_string);

    length = strlen(original_string);

    //Checking frequency of each character in the original string
    for(i=0; i<length; i++)
    {
        if(original_string[i]>='a' && original_string[i]<='z') //checking only lower case letters
        {
            frequency[original_string[i]-'a']++; //incrementing the frequency of that letter
        }
    }

    //Creating the new string by adding the letter and its frequency
    j=0; //index for new string
    for(i=0; i<length; i++)
    {
        if(original_string[i]>='a' && original_string[i]<='z') //checking only lower case letters
        {
            if(frequency[original_string[i]-'a']>0) //this condition to make sure one letter appears only once in the new string
            {
                new_string[j] = original_string[i];
                j++;
                new_string[j] = (char)(frequency[original_string[i]-'a'] + '0'); //converting the integer frequency to a character and storing it in the new string
                j++;
                frequency[original_string[i]-'a'] = 0; //setting the frequency to zero to make sure the same letter is not added again in the new string
            }
        }
    }
    new_string[j] = '\0'; //adding null character at the end to make it a valid string

    printf("\nOriginal String: %s\n", original_string);
    printf("New String: %s\n", new_string);

    return 0;
}