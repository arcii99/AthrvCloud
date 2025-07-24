//FormAI DATASET v1.0 Category: Word Count Tool ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// function to count words in a given string
int word_count(char str[]) {
    int i, count = 0;

    for(i=0;str[i] != '\0';i++) {
        // checks for spaces, tabs and new lines and increase the count
        if(str[i]==' ' || str[i] == '\t' || str[i] == '\n') {
            count++;
        }
    }
    // return the total count of words
    return count+1;
}

int main() {
    char str[1000];
    printf("Enter the string:\n");
    //gets the input string from the user
    fgets(str,1000,stdin);

    //removes the new line character from the end of the string
    if(str[strlen(str)-1]=='\n') {
        str[strlen(str)-1]='\0';
    }

    //calls the word_count function to get the count of words in the given string
    int count = word_count(str);
    printf("Total words in the given string are: %d\n",count);

    return 0;
}