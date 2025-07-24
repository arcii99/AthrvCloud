//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: genious
#include<stdio.h>
#include<string.h>

// Function to convert given alien language word to English word
char* convertToEnglish(char* alienWord)
{
    int i,j,l;
    char temp[100],temp2[100];
    strcpy(temp,alienWord); // storing alien word to temp string
    l=strlen(temp); 
    // Reversing the given alien word
    for(i=0,j=l-1;i<l;i++,j--)
    {
        temp2[i]=temp[j];
    }
    temp2[l]='\0'; // Converting it to string format
    if(strcmp(temp2,"dne")==0) // Checking for "dne" word
        return "hello";
    if(strcmp(temp2,"ylno")==0) // Checking for "ylno" word
        return "world";
    return "unknown"; // If given alien word is not recognized return "unknown"
}

int main()
{
    int n,i;
    char alienWord[100];
    printf("Enter number of words: ");
    scanf("%d",&n);
    getchar(); // Clearing buffer
    for(i=0;i<n;i++)
    {
        printf("\nEnter word %d: ",i+1);
        gets(alienWord); // Getting input word
        printf("English Version: %s",convertToEnglish(alienWord)); // Converting and displaying result
    }
    return 0; // End of program
}