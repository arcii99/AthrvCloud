//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Sherlock Holmes
#include<stdio.h>
#include<string.h>

// Function to count occurrences of a word in a string
int count_word(char *str, char *word){
    int count = 0;
    char *ptr = strstr(str, word);
    while(ptr != NULL){
        count++;
        ptr = strstr(ptr + 1, word);
    }
    return count;
}

// Function to calculate the length of a string
int str_len(char *str){
    int len = 0;
    while(str[len] != '\0'){
        len++;
    }
    return len;
}

// Function to remove all occurrences of a word from a string
void remove_word(char *str, char *word){
    int len = str_len(word);
    char *ptr = strstr(str, word);
    while(ptr != NULL){
        memmove(ptr, ptr + len, str_len(ptr + len) + 1);
        ptr = strstr(str, word);
    }
}

int main(){

    // Prompt user to enter the text to summarize
    printf("Enter the text to summarize:\n");
    char text[1000];
    fgets(text, sizeof(text), stdin);
    printf("\n");

    // Remove all punctuation marks
    remove_word(text, ".");
    remove_word(text, ",");
    remove_word(text, ";");
    remove_word(text, ":");

    // Count the occurrences of each word in the text
    int and_count = count_word(text, "and");
    int but_count = count_word(text, "but");
    int however_count = count_word(text, "however");

    // Determine which word occurs the most
    char *max_word;
    int max_count;
    if(and_count > but_count && and_count > however_count){
        max_word = "and";
        max_count = and_count;
    }else if(but_count > and_count && but_count > however_count){
        max_word = "but";
        max_count = but_count;
    }else{
        max_word = "however";
        max_count = however_count;
    }

    // Print out the summary using Sherlock Holmes style language
    printf("The text can be summarized as follows:\n");
    printf("In the %d-word text, the word \"%s\" appears the most. ", str_len(text), max_word);
    printf("This indicates that the writer was attempting to convey a contrasting point.\n");

    // Return 0 to indicate successful completion of program
    return 0;
}