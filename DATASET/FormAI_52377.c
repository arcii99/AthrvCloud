//FormAI DATASET v1.0 Category: Spam Detection System ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SPAM 50
#define MAX_MESSAGE_LENGTH 500

/* Structure to store the spam words */
typedef struct {
    char word[MAX_MESSAGE_LENGTH];
} spam_word;

/* Function to check if a word is spam or not */
int is_spam(char *word, spam_word spam_list[], int spam_count) {
    int i;
    /* Convert the word to lower case */
    for(i=0; i<strlen(word); i++) {
        word[i] = tolower(word[i]);
    }
    /* Check if the word matches any spam word */
    for(i=0; i<spam_count; i++) {
        if(strcmp(spam_list[i].word, word)==0) {
            return 1;
        }
    }
    /* If not, return 0 */
    return 0;
}

int main() {
    int i, j, k, message_length, spam_flag = 0, spam_count = 0;
    char message[MAX_MESSAGE_LENGTH];
    char word[MAX_MESSAGE_LENGTH];
    spam_word spam_list[MAX_SPAM];
    
    /* Read the spam words from a file */
    FILE *fp = fopen("spam_words.txt", "r");
    if(fp==NULL) {
        printf("Error opening file!\n");
        return 0;
    }
    while(fgets(word, MAX_MESSAGE_LENGTH, fp) != NULL) {
        word[strcspn(word, "\n")] = 0; /* Remove newline character */
        strcpy(spam_list[spam_count].word, word);
        spam_count++;
    }
    fclose(fp);

    /* Get the message from the user */
    printf("Enter your message:\n");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    message[strcspn(message, "\n")] = 0; /* Remove newline character */
    message_length = strlen(message);

    /* Check every word in the message for spam */
    for(i=0; i<message_length; i++) {
        /* If it's a space, reset the word */
        if(message[i]==' ') {
            word[j] = '\0';
            j = 0;
            /* Check if the previous word was spam */
            if(is_spam(word, spam_list, spam_count)) {
                spam_flag = 1;
            }
        }
        /* If it's a character, add it to the word */
        else if(isalpha(message[i])) {
            word[j] = message[i];
            j++;
        }
        /* If it's not a space or a character, ignore it */
        else {
            continue;
        }
    }
    /* Check the last word */
    word[j] = '\0';
    if(is_spam(word, spam_list, spam_count)) {
        spam_flag = 1;
    }

    /* Print the result */
    if(spam_flag==1) {
        printf("SPAM detected!\n");
    }
    else {
        printf("Message is clean.\n");
    }

    return 0;
}