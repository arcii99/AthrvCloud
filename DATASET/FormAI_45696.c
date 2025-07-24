//FormAI DATASET v1.0 Category: Word Count Tool ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// Function to count the number of words in the given string
int count_words(char* str){
    int count = 0;
    int flag = 0; // Flag to identify if a word has started or not
    for(int i = 0; i < strlen(str); i++){
        if(isalpha(str[i])){
            flag = 1; // Word has started
        }
        else if(isspace(str[i]) && flag==1){
            count++; // Word has ended
            flag = 0; // Reset the flag
        }
    }
    if(flag==1){
        count++; // In case the string ends with a word
    }
    return count;
}

int main(){
    // Read the input string from the user
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    
    // Count the number of words in the given string
    int count = count_words(str);
    
    // Print the count
    printf("The number of words in the given string is %d\n", count);
    
    return 0;
}