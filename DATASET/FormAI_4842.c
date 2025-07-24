//FormAI DATASET v1.0 Category: Spam Detection System ; Style: portable
#include <stdio.h>
#include <string.h>

#define MAX_MSG_LEN 1024
#define SPAM_KEYWORDS_NUM 5

char spam_keywords[SPAM_KEYWORDS_NUM][20] = {"viagra", "lottery", "prince", "nigerian", "inheritance"};

int is_spam(char* msg) {
    char temp_msg[MAX_MSG_LEN];
    int i, j;

    strcpy(temp_msg, msg);

    // convert every letter to lowercase for case-insensitive comparison
    for(i = 0; i < strlen(temp_msg); i++) {
        temp_msg[i] = tolower(temp_msg[i]);
    }

    // check if any spam keyword exists in the message
    for(i = 0; i < SPAM_KEYWORDS_NUM; i++) {
        char* keyword = spam_keywords[i];
        int keyword_len = strlen(keyword);

        for(j = 0; j < strlen(temp_msg) - keyword_len; j++) {
            if(strncmp(temp_msg + j, keyword, keyword_len) == 0) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    char msg[MAX_MSG_LEN];

    printf("Enter a message: ");
    fgets(msg, MAX_MSG_LEN, stdin);

    if(is_spam(msg)) {
        printf("This message is marked as spam!\n");
    } else {
        printf("This message is not spam.\n");
    }

    return 0;
}