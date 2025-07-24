//FormAI DATASET v1.0 Category: Spam Detection System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPAM_WORDS 20

char spam_words[MAX_SPAM_WORDS][50] = {"viagra", "lottery", "rich", "cash", "dollars", "earn",
                                        "income", "guarantee", "limited time", "offer", 
                                        "free", "trial", "discount", "price", "win",
                                        "click", "credit card", "investment", "loan", "debt"};

int check_spam(char *message)
{
    int i;
    char *word;

    // Convert all characters to lower case.
    for(i = 0; message[i]; i++){
        message[i] = tolower(message[i]);
    }

    // Check each word in the message against spam words list.
    for(i = 0; i < MAX_SPAM_WORDS; i++){
        word = strstr(message, spam_words[i]);
        if(word != NULL){
            return 1;
        }
    }

    return 0;
}

int main()
{
    char message[500];

    printf("Enter your message: ");
    fgets(message, 500, stdin);

    if(check_spam(message)){
        printf("Your message contains spam.\n");
    }
    else{
        printf("Your message is valid.\n");
    }
    
    return 0;
}