//FormAI DATASET v1.0 Category: Spam Detection System ; Style: realistic
#include <stdio.h>
#include <string.h>

#define MAX_SPAM_WORDS 50

char *spam_word_list[MAX_SPAM_WORDS] = {"free", "limited time offer", "get rich quick", "guaranteed",
                                        "money back", "click here", "winner", "credit card", "urgent",
                                        "act now", "call now", "risk free", "bulk email", "order now",
                                        "discount", "cash", "no obligation", "only", "prize", "promise",
                                        "quote", "compare", "save", "customer", "easy", "dollars",
                                        "earn extra cash", "hidden", "investment", "million", "partnership",
                                        "profits", "removal", "cash bonus", "certified", "affordable",
                                        "as seen on", "cancel", "centuries", "collect", "competitive edge",
                                        "direct email", "fantastic", "fast cash", "exclusive", "gift",
                                        "maintained", "marketing solutions"};

int main() {
    char input_string[1000];
    printf("Enter the message you want to check for spam: ");
    fgets(input_string, 1000, stdin);
    input_string[strcspn(input_string, "\n")] = 0; // remove newline character

    int i, j, length_of_string = strlen(input_string), spam_count = 0;
    for (i = 0; i < length_of_string; i++) {
        for (j = 0; j < MAX_SPAM_WORDS; j++) {
            int length_of_spam_word = strlen(spam_word_list[j]);
            if (strncmp(&input_string[i], spam_word_list[j], length_of_spam_word) == 0) {
                spam_count++;
                i += length_of_spam_word;
                break;
            }
        }
    }

    if (spam_count > 0) {
        printf("This message has %d spam words.\n", spam_count);
    } else {
        printf("This message does not contain any spam words.\n");
    }

    return 0;
}