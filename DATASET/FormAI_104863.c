//FormAI DATASET v1.0 Category: Word Count Tool ; Style: authentic
#include <stdio.h> 

int main() 
{ 
    char str[100]; 
    int count = 0, i;
    
    printf("Enter a string: "); 
    fgets(str, 100, stdin);  // read string input from the user

    for(i = 0; str[i] != '\0'; i++) // loop until end of string
    {
        if(str[i] == 'c' || str[i] == 'C') // check if character is 'c' or 'C'
        {
            count++; // increment count if character is found
        }
    }

    printf("Count of c's in the given string: %d",count);

    return 0; 
}