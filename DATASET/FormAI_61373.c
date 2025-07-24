//FormAI DATASET v1.0 Category: Word Count Tool ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000 //Maximum length of input string

int main()
{
    char str[MAX]; //Initialising  input string
    int count=0; //Initialising the word count variable as 0
    
    printf("Enter a string: ");
    fgets(str, MAX, stdin); //Reads the whole line with spaces from input and stores in str

    for(int i=0;str[i]!='\0';i++) //Traversing through the string until it reaches end
    {
        if(str[i]==' ' || str[i]=='\n') // If space or line break is found
        {
            count++; //Then count the word by incrementing count
        }
    }
    printf("\nWord count: %d", count+1); //Adding 1 because the last word won't be counted if there is no line break or space after it

    return 0;
}