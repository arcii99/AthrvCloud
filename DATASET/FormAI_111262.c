//FormAI DATASET v1.0 Category: Spam Detection System ; Style: medieval
#include <stdio.h>
#include <string.h>

// Function to check if a given message is spam or not
int is_spam(char* message) {
    int i, j, k, l, m, n;

    // Count the number of occurrences of "buy", "cheap", "discount" in the message
    i = j = k = 0;
    l = strlen(message);
    while (i < l) {
        if (tolower(message[i]) == 'b' && tolower(message[i+1]) == 'u' && tolower(message[i+2]) == 'y') {
            j++;
        }
        if (tolower(message[i]) == 'c' && tolower(message[i+1]) == 'h' && tolower(message[i+2]) == 'e' && tolower(message[i+3]) == 'a' && tolower(message[i+4]) == 'p') {
            k++;
        }
        if (tolower(message[i]) == 'd' && tolower(message[i+1]) == 'i' && tolower(message[i+2]) == 's' && tolower(message[i+3]) == 'c' && tolower(message[i+4]) == 'o' && tolower(message[i+5]) == 'u' && tolower(message[i+6]) == 'n' && tolower(message[i+7]) == 't') {
            l++;
        }
        i++;
    }

    // Determine if message is spam based on the number of occurrences
    if (j > 0 || k > 0 || l > 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char message[1000];
    int is_spam_flag;

    printf("Hark ye, good sir/madam. What message would thou like to check? ");
    fgets(message, 1000, stdin);

    is_spam_flag = is_spam(message);

    if (is_spam_flag == 1) {
        printf("Verily, this message appears to be spam! Begone!");
    } else {
        printf("This message is not of the spammy sort, thou art free to go.");
    }

    return 0;
}