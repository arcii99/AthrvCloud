//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: happy
#include<stdio.h>
#include<string.h>
#define MAX_SIZE 1000

int main(){
    char str[MAX_SIZE];
    int freq[26] = {0}; // initialize the frequency of each letter to zero
    int i = 0, total = 0;
    printf("Hello there, let's count the frequency of all letters in your text!\n");
    printf("Please enter your text:\n");
    fgets(str, MAX_SIZE, stdin); // get the input text from the user
    while(str[i] != '\0') {
        if(str[i]>='a' && str[i]<='z') {
            freq[str[i]-'a']++; // increment the frequency of each letter
            total++; // increment the total number of characters in the text
        }
        i++;
    }
    printf("The frequency of each letter in the text is:\n");
    for(i=0; i<26; i++){
        printf("%c: %d\n",i+'a',freq[i]); // print the frequency of each letter
    }
    printf("The total number of characters in the text is: %d\n",total);
    printf("Yayyy! We're done counting :D\n");
    return 0;
}