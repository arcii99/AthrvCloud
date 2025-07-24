//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int score(char* word);

int main() {
    char tweet[MAX_LENGTH];
    printf("Enter a tweet: ");
    fgets(tweet, MAX_LENGTH, stdin);
    int length = strlen(tweet);
    if (tweet[length - 1] == '\n') {
        tweet[length - 1] = '\0';
    }
    char* token = strtok(tweet, " ");
    int total_score = 0;
    int count = 0;
    while (token != NULL) {
        int word_score = score(token);
        if (word_score != -1) {
            total_score += word_score;
            count++;
        }
        token = strtok(NULL, " ");
    }
    if (count == 0) {
        printf("The tweet was neutral\n");
    } else if (total_score / count > 0) {
        printf("The tweet was positive\n");
    } else if (total_score / count < 0) {
        printf("The tweet was negative\n");
    } else {
        printf("The tweet was neutral\n");
    }
    return 0;
}

int score(char* word) {
    int length = strlen(word);
    if (word[0] == '#' || word[0] == '@') {
        return -1;
    }
    if (word[length - 1] == ',' || word[length - 1] == '.' || word[length - 1] == '!') {
        length--;
    }
    if (word[length - 1] == '?' || word[length - 1] == '.') {
        length--;
    }
    int sum = 0;
    int i;
    char c;
    for (i = 0; i < length; i++) {
        c = tolower(word[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            sum++;
        } else {
            sum--;
        }
    }
    return sum;
}