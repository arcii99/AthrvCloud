//FormAI DATASET v1.0 Category: String manipulation ; Style: medieval
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[30], str2[30], str3[30];
    int length;

    // Get input strings
    printf("Enter the first string: ");
    fgets(str1, 30, stdin);

    printf("Enter the second string: ");
    fgets(str2, 30, stdin);

    // Concatenate the two strings
    strcat(str1, str2);

    // Copy the concatenated string to str3
    strcpy(str3, str1);

    // Get the length of the string
    length = strlen(str3);

    // Change the fifth character of the string to 'E'
    str3[4] = 'E';

    // Convert all the characters to uppercase
    for(int i=0; i<length; i++){
        if(str3[i] >= 'a' && str3[i] <= 'z'){
            str3[i] = str3[i] - 32;
        }
    }

    // Print the manipulated string
    printf("\nThe manipulated string is: \n%s", str3);

    return 0;
}