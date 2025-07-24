//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: ephemeral
#include<stdio.h>
#include<string.h>
#define MAX_SIZE 100

// A function to reverse a given string
void reverse(char str[])
{
    int length = strlen(str);
    int mid = length/2;
    for(int i=0;i<mid;i++)
    {
        char temp = str[i];
        str[i] = str[length-i-1];
        str[length-i-1] = temp;
    }
}

// A function to check if the given string is palindrome or not
int isPalindrome(char str[])
{
    char temp[MAX_SIZE];
    strcpy(temp,str);
    reverse(temp);
    if(strcmp(temp,str)==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char str[MAX_SIZE];
    printf("*** Welcome to Palindrome Checker ***\n");
    printf("Please enter a string to check whether it is Palindrome or not:\n");
    scanf("%[^\n]s",str);  // Read input string with whitespaces
    if(isPalindrome(str))
    {
        printf("The given string '%s' is Palindrome\n",str);
    }
    else
    {
        printf("The given string '%s' is not Palindrome\n",str);
    }
    return 0;
}