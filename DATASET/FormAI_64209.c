//FormAI DATASET v1.0 Category: Text processing ; Style: unmistakable
#include <stdio.h>
#include <string.h>

// A function to reverse a given string
void reverse(char str[])
{
    int length = strlen(str);
    int i;
    char temp;
    
    for(i=0; i<length/2; i++){
        temp = str[i];
        str[i] = str[length-i-1];
        str[length-i-1] = temp;
    }
}

int main()
{
    char str[100];
    
    printf("Enter a string to be reversed: ");
    scanf("%s", str);
    
    reverse(str);
    
    printf("The reversed string is: %s\n", str);
    
    return 0;
}