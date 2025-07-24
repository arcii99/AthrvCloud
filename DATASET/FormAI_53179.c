//FormAI DATASET v1.0 Category: Spam Detection System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the maximum length of an email message
#define MAX_MESSAGE_LENGTH 1000

// define the threshold for spam messages
#define SPAM_THRESHOLD 0.5

// function to calculate the frequency of a character in a string
int char_frequency(char* str, char c, int len, int freq);

// recursive function to calculate the spam score of a message
float calculate_spam_score(char* message, int len, int spam_freq) {

    // check if the message is empty
    if (len == 0) {
        return 0;
    }

    // get the frequency of the spammy characters in the message
    int freq = 0;
    char_frequency(message, 'x', len, freq);
    char_frequency(message, 'y', len, freq);

    // calculate the spam score as the ratio of spammy characters to total characters
    float spam_score = (float)freq / len;

    // recursive call to calculate the spam score of the remaining characters in the message
    spam_score += calculate_spam_score(message + 1, len - 1, spam_freq);

    return spam_score;
}

// function to calculate the frequency of a character in a string
int char_frequency(char* str, char c, int len, int freq) {

    // check if the string is empty
    if (len == 0) {
        return freq;
    }

    // check if the current character matches the input character
    if (str[0] == c) {
        freq++;
    }

    // recursive call to calculate the frequency of the remaining characters in the string
    freq = char_frequency(str + 1, c, len - 1, freq);

    return freq;
}

int main() {

    // get the email message from the user
    char message[MAX_MESSAGE_LENGTH];
    printf("Enter your message:\n");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    // calculate the spam score of the message
    int len = strlen(message) - 1;
    float spam_score = calculate_spam_score(message, len, 0);

    // print the spam score
    printf("Spam score: %f\n", spam_score);

    // check if the message is spam
    if (spam_score >= SPAM_THRESHOLD) {
        printf("This message is spam!\n");
    } else {
        printf("This message is not spam.\n");
    }

    return 0;
}