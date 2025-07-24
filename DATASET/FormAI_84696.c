//FormAI DATASET v1.0 Category: Spam Detection System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_spam(char *subject) {
    int len = strlen(subject);
    char *fwd_ptr = subject;
    char *end_ptr = &subject[len - 1];

    // Strip leading and trailing whitespace
    while (*fwd_ptr && isspace(*fwd_ptr)) { fwd_ptr++; }
    while (end_ptr > fwd_ptr && isspace(*end_ptr)) { end_ptr--; }
    end_ptr++;

    // Check empty subject
    if (end_ptr <= fwd_ptr) { return 1; }

    // Search for specific keywords within the subject recursively
    if (strstr(fwd_ptr, "FREE") || strstr(fwd_ptr, "WIN") || strstr(fwd_ptr, "NOW")) {
        return 1;
    } else if (strstr(fwd_ptr, "RE: ")) {
        return is_spam(fwd_ptr + 4);
    } else if (strstr(fwd_ptr, "FW: ")) {
        return is_spam(fwd_ptr + 4);
    } else if (strstr(fwd_ptr, "FWD: ")) {
        return is_spam(fwd_ptr + 5);
    } else if (strstr(fwd_ptr, "URGENT")) {
        return is_spam(fwd_ptr + 6);
    } else if (strstr(fwd_ptr, "IMPORTANT")) {
        return is_spam(fwd_ptr + 9);
    } else {
        return 0;
    }
}

int main() {
    char subject[101];
    printf("Please enter the subject of your email: ");
    fgets(subject, 100, stdin);

    if (is_spam(subject)) {
        printf("The subject is a spam.\n");
    } else {
        printf("The subject is not a spam.\n");
    }

    return 0;
}