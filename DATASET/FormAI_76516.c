//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: innovative
#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
  
// Define a struct to store word count data  
struct Word_Count  
{  
    char word[20];  
    int count;  
};  
  
int main()  
{  
    struct Word_Count wc[1000];  
    char str[1000];  
  
    // Ask user to enter some text  
    printf("Enter some text: \n");  
    fgets(str, sizeof(str), stdin);  
  
    // Remove the '\n' character from str  
    strtok(str, "\n");  
  
    // Split the text into words separated by spaces  
    char* word = strtok(str, " ");  
  
    // Initialize the word count data to zero  
    for(int i = 0; i < 1000; i++)  
    {  
        strcpy(wc[i].word,"\0");  
        wc[i].count = 0;  
    }  
  
    // Loop through each word and count its frequency  
    int i = 0;  
    while(word != NULL)  
    {  
        // Check if the word already exists in the struct array  
        int j = 0, flag = 0;  
        while(strcmp(wc[j].word,"\0") != 0)  
        {  
            if(strcmp(wc[j].word, word) == 0)  
            {  
                flag = 1;  
                wc[j].count++;  
                break;  
            }  
            j++;  
        }  
  
        // If word doesn't exist in struct array, add it to the end of the array  
        if(flag == 0)  
        {  
            strcpy(wc[j].word, word);  
            wc[j].count++;  
        }  
  
        // Get the next word from the text  
        word = strtok(NULL, " ");  
        i++;  
    }  
  
    printf("\nWord Frequency Count:\n");  
    printf("------------------------\n");  
    printf("   Word\t\tFrequency\n");  
    printf("------------------------\n");  
  
    // Print the word count data  
    for(int i = 0; i < 1000; i++)  
    {  
        if(strcmp(wc[i].word,"\0") == 0)  
            break;  
  
        printf("%8s\t\t%5d\n", wc[i].word, wc[i].count);  
    }  
  
    return 0;  
}