//FormAI DATASET v1.0 Category: String manipulation ; Style: visionary
#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    char temp[100];

    printf("Enter a string: ");
    scanf("%s", str);

    int length = strlen(str);

    // Convert the string to uppercase
    for(int i=0; i<length; i++){
        temp[i] = toupper(str[i]);
    }
    temp[length] = '\0';

    printf("Uppercase string is: %s\n", temp);

    // Convert the string to lowercase
    for(int i=0; i<length; i++){
        temp[i] = tolower(str[i]);
    }
    temp[length] = '\0';

    printf("Lowercase string is: %s\n", temp);

    // Reverse the string
    for(int i=0; i<length/2; i++){
        char tempChar = str[i];
        str[i] = str[length-i-1];
        str[length-i-1] = tempChar;
    }

    printf("Reversed string is: %s\n", str);

    return 0;
}