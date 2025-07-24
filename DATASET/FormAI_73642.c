//FormAI DATASET v1.0 Category: Spam Detection System ; Style: portable
#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[]) {

    char spam_list[10][20] = {"make money", "earn money", "money back", "100% guaranteed", "limited time offer", "call now", "buy now", "click here", "double your", "extra cash"};

    int i, j, spam_count = 0, total_words = 0;
    char input[500], words[50][20];
    
    printf("Enter your input: ");
    fgets(input, 500, stdin); //take input from user
    
    char *token = strtok(input, " "); //tokenize input based on space
    
    while(token != NULL) { //loop through tokens and store in words array
        strcpy(words[total_words], token);
        total_words++;
        token = strtok(NULL, " ");
    }
    
    for(i=0; i<total_words; i++) { //check if each word is present in spam_list
        for(j=0; j<10; j++) {
            if(strcmp(words[i], spam_list[j]) == 0) {
                spam_count++;
            }
        }
    }
    
    printf("\nNumber of spam words: %d\n", spam_count);
    
    if(spam_count > 2) { //if more than two spam words detected, mark as spam
        printf("This is a spam message!\n");
    }
    else {
        printf("This is not a spam message.\n");
    }
    
    return 0;
}