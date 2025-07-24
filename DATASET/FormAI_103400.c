//FormAI DATASET v1.0 Category: String manipulation ; Style: happy
#include <stdio.h>
#include <string.h>

int main()
{
    char str[100], happy[10] = "happy";
    int len, foundHappy = 0, i, j;
    
    printf("Enter a string: ");
    scanf("%s", str);
    
    len = strlen(str);
    
    // Check if "happy" is in the string
    for(i = 0; i < len - 4; i++)
    {
        if(str[i] == 'h' && str[i+1] == 'a' && str[i+2] == 'p' && str[i+3] == 'p' && str[i+4] == 'y')
        {
            foundHappy = 1;
            break;
        }
    }
    
    if(foundHappy == 1)
    {
        // Replace "happy" with "HAPPY"
        for(j = i; j < i + 5; j++)
        {
            str[j] = 'H';
        }
        str[j] = '!';
        
        printf("Yay! You made me %s\n", str);
    }
    else
    {
        // Add "happy" to the end of the string
        strcat(str, " happy!");
        
        printf("Aww, you didn't make me happy. But now I am %s\n", str);
    }
    
    return 0;
}