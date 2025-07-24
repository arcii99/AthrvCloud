//FormAI DATASET v1.0 Category: Spam Detection System ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main()
{
    char message[100];
    int spam_count = 0;
    int keyword_count = 0;

    printf("Welcome to the Spam Detection System! 🤖\n\n");

    do {
        printf("Please enter your message (type 'exit' to quit): \n");
        gets(message);

        if(strcmp(message, "exit") == 0) {
            break;
        }

        char* keywords[] = {"make money", "free money", "lottery winner", "congratulations", "work from home"};

        for(int i = 0; i < sizeof(keywords)/sizeof(keywords[0]); i++) {
            if(strstr(message, keywords[i]) != NULL) {
                keyword_count++;
            }
        }

        if(keyword_count >= 2 || strlen(message) > 50) {
            printf("SPAM ALERT! 🚨\n\n");
            spam_count++;
        } else {
            printf("Message received. 📩\n\n");
        }

        keyword_count = 0;

    } while(1);

    printf("Thank you for using Spam Detection System! 🙌\n");
    printf("Total number of spam messages detected: %d\n", spam_count);
    return 0;
}