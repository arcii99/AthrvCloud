//FormAI DATASET v1.0 Category: Spam Detection System ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

#define MAX_MESSAGES 1000
#define MAX_MESSAGE_LENGTH 200

typedef struct {
    char message[MAX_MESSAGE_LENGTH];
    int spam_score;
} Message;

void check_for_spam(Message *message) {
    char *keywords[] = {"discount", "free", "winner", "money", "credit", "opportunity"};
    int num_keywords = sizeof(keywords)/sizeof(keywords[0]);
    
    for (int i = 0; i < num_keywords; i++) {
        if (strstr(message->message, keywords[i])) {
            message->spam_score += 1;
        }
    }
}

int main() {
    Message messages[MAX_MESSAGES];
    int num_messages = 0;
    
    printf("Welcome to the Post-Apocalyptic Spam Detection System\n");
    printf("Enter your messages to be checked for spam. Type 'quit' to exit.\n");
    
    while (1) {
        printf("> ");
        char input[MAX_MESSAGE_LENGTH]; 
        fgets(input, MAX_MESSAGE_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0; // remove trailing newline
        
        if (strcmp(input, "quit") == 0) {
            break;
        }
        
        Message new_message;
        strcpy(new_message.message, input);
        new_message.spam_score = 0;
        
        check_for_spam(&new_message);
        
        messages[num_messages] = new_message;
        num_messages++;
    }
    
    printf("\n\nRESULTS:\n");
    printf("===============================================\n");
    
    for (int i = 0; i < num_messages; i++) {
        printf("Message %d:\n", i+1);
        printf("\t%s\n", messages[i].message);
        printf("\tSpam score: %d\n", messages[i].spam_score);
        printf("\n");
    }
    
    return 0;
}