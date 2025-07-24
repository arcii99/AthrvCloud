//FormAI DATASET v1.0 Category: Text processing ; Style: relaxed
#include <stdio.h>
#include <string.h>

// Function to reverse a string
void reverse(char str[])
{
    int i = 0, j = strlen(str)-1;
    while(i<j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int main()
{
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    
    // Removing newline character from the string
    str[strcspn(str, "\n")] = 0;
    
    // Reversing the string
    reverse(str);
    
    printf("Reversed string: %s", str);
    
    return 0;
}