//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: complex
#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
#include<math.h> 

int generate_hash(char *);

int main() 
{ 
    char input_string[100]; 
    
    printf("Please enter a string to generate hash: ");
    scanf("%s", input_string);
    
    printf("The generated hash value for string '%s' is: %d", input_string, generate_hash(input_string));
    
    return 0; 
} 

int generate_hash(char *str)
{
    int len = strlen(str);
    int hash = 5381;
    int i = 0;

    for(i = 0; i < len; i++)
    {
        hash = ((hash << 5) + hash) + str[i]; 
    }

    return (hash % 1000);
}