//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: surrealist
#include<stdio.h>
#include<string.h>
#include<stdlib.h> /*for dynamic memory allocation*/

void reverse(char *str)
{
        int length=strlen(str);
        char *newstr=(char*)malloc(sizeof(char)*length); /* Allocation of memory */
        for(int i=0; i<length;i++)
        {
                newstr[i]=str[length-i-1];
        }
        printf("\nReverse of the string = %s\n", newstr);
        free(newstr); /*Freeing up memory*/

}

void check_palindrome(char *str)
{
        int length=strlen(str);
        for(int i=0;i<length/2;i++)
        {
                if(str[i]!=str[length-i-1])
                {
                        printf("\nNot a palindrome!\n");
                        return;
                }
        }
        printf("\nIt's a palindrome!\n");
}

int main()
{
        char *str=(char*)malloc(sizeof(char)*100); /* Allocation of memory */
        printf("Please enter a string: ");
        scanf("%s",str);
        check_palindrome(str);
        reverse(str);
        free(str);
        return 0;
}