//FormAI DATASET v1.0 Category: Spam Detection System ; Style: authentic
#include <stdio.h>
#include <string.h>

#define SPAM_KEYWORDS {"buy now", "limited time offer", "click here", "earn money fast"}

typedef struct {
    char sender[100];
    char message[1000];
} Email;

int main() {
    char keywords[][20] = SPAM_KEYWORDS;
    int num_keywords = sizeof(keywords) / sizeof(keywords[0]);
    Email inbox[100];
    int num_emails = 0;

    // Simulate receiving some emails
    strcpy(inbox[num_emails].sender, "jane@spam.com");
    strcpy(inbox[num_emails].message, "Buy now and get a 10% discount!");
    num_emails++;
    strcpy(inbox[num_emails].sender, "john@spam.com");
    strcpy(inbox[num_emails].message, "Click here for an amazing offer!");
    num_emails++;
    strcpy(inbox[num_emails].sender, "spam@spam.com");
    strcpy(inbox[num_emails].message, "Earn money fast with this opportunity!");
    num_emails++;
    strcpy(inbox[num_emails].sender, "legit@company.com");
    strcpy(inbox[num_emails].message, "Thank you for your recent purchase.");
    num_emails++;

    // Check emails for spam keywords
    int spam_counter = 0;
    for (int i = 0; i < num_emails; i++) {
        for (int j = 0; j < num_keywords; j++) {
            if (strstr(inbox[i].message, keywords[j]) != NULL) {
                printf("Warning: Possible spam email from %s\n", inbox[i].sender);
                spam_counter++;
                break;
            }
        }
    }

    if (spam_counter == 0) {
        printf("No spam emails found.\n");
    }

    return 0;
}