//FormAI DATASET v1.0 Category: String manipulation ; Style: satisfied
#include<stdio.h>
#include<string.h>

int main()
{
    char str1[50], str2[50], temp[50];
    
    //Getting inputs from user
    printf("Enter first string: ");
    fgets(str1, 50, stdin);
    printf("Enter second string: ");
    fgets(str2, 50, stdin);
    
    //Removing the new line character from the input
    str1[strcspn(str1, "\n")] = 0;
    str2[strcspn(str2, "\n")] = 0;
    
    //Printing the original inputs
    printf("Original Strings\n");
    printf("First string: %s\n", str1);
    printf("Second string: %s\n", str2);
    
    //Swapping the strings using temporary variable
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
    
    //Printing the swapped strings
    printf("Swapped Strings\n");
    printf("First string: %s\n", str1);
    printf("Second string: %s\n", str2);
    
    //Merging the strings
    strcat(str1, " ");
    strcat(str1, str2);
    
    //Printing the merged string
    printf("Merged String: %s\n", str1);
    
    //Reversing the string
    int len = strlen(str1);
    for(int i=0; i<len/2; i++)
    {
        char temp = str1[i];
        str1[i] = str1[len-i-1];
        str1[len-i-1] = temp;
    }
    
    //Printing the reversed string
    printf("Reversed String: %s\n", str1);
    
    return 0;
}