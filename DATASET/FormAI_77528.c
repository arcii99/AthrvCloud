//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: peaceful
#include <stdio.h>
#include <string.h>

int main() 
{
    char input[100];
    int b = 0;
    
    printf("Enter a sentence in C Cat Language: ");
    fgets(input, 100, stdin);
    
    for (int i=0; i < strlen(input); i++) 
    {
        if (input[i] == 'm') 
        {
            printf("purr");
            b++;
        } 
        else if (input[i] == 'p') 
        {
            printf("meow");
            b++;
        } 
        else if (input[i] == 'n') 
        {
            printf("paw");
            b++;
        } 
        else if (input[i] == 'b') 
        {
            printf("treat");
            b++;
        } 
        else if (input[i] == 'f') 
        {
            printf("claw");
            b++;
        } 
        else if (input[i] == 's') 
        {
            printf("nap");
            b++;
        } 
        else 
        {
            printf("%c", input[i]);
        }
    }
    
    if (b == 0) 
    {
        printf("I think you forgot to write in C Cat Language. Try again!\n");
    }
    
    return 0;
}