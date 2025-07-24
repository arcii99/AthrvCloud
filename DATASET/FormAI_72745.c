//FormAI DATASET v1.0 Category: Spam Detection System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define SPAM_THRESHOLD 3 // Minimum number of suspicious words to flag post as spam
#define MAX_WORD_LENGTH 20 // Maximum length of a suspicious word
#define MAX_POST_LENGTH 500 // Maximum length of a post
#define MAX_SPAM_POSTS 10 // Maximum number of spam posts allowed before user is banned
 
// Function to check if a word is in the list of suspicious words
int is_suspicious_word(char word[MAX_WORD_LENGTH], char **suspicious_words, int num_suspicious_words) {
    int i;
    for(i=0; i<num_suspicious_words; i++) {
        if(strcmp(word, suspicious_words[i]) == 0) {
            return 1;
        }
    }
    return 0;
}
 
int main() {
    int num_suspicious_words = 3;
    char *suspicious_words[3] = {"buy", "free", "click"};
    char post[MAX_POST_LENGTH];
    int num_spam_posts = 0;
 
    while(1) {
        // Get post from user
        printf("Enter your post: ");
        fgets(post, MAX_POST_LENGTH, stdin);
 
        // Check if post is spam
        int count = 0;
        char *word = strtok(post, " .,\n"); // Split post into words
 
        while(word != NULL) {
            if(is_suspicious_word(word, suspicious_words, num_suspicious_words)) {
                count++;
            }
            word = strtok(NULL, " .,\n");
        }
 
        if(count >= SPAM_THRESHOLD) {
            num_spam_posts++;
            printf("Your post contains suspicious words and may be flagged as spam.\n");
        } else {
            printf("Your post is safe and will be displayed.\n");
        }
 
        // Check if user has exceeded maximum number of spam posts
        if(num_spam_posts >= MAX_SPAM_POSTS) {
            printf("You have been banned for posting too much spam.\n");
            break;
        }
    }
 
    return 0;
}