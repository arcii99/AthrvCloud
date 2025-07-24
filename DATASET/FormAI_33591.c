//FormAI DATASET v1.0 Category: Email Client ; Style: Romeo and Juliet
// Romeo and Juliet - An email client program in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LEN 1000
#define MAX_SUBJECT_LEN 100

int read_email(char *to, char *subject, char *message) {
    printf("O Juliet, what's thine lover's email address?\n");
    scanf("%s", to);
    printf("And, what shall the subject be, my love?\n");
    scanf("%s", subject);
    printf("Now, speak thine message to be conveyed.\n");
    getchar();  // clear input buffer
    fgets(message, MAX_EMAIL_LEN, stdin);
    return strlen(message);
}

int send_email(char *to, char *subject, char *message) {
    printf("To email: %s\n", to);
    printf("Subject: %s\n", subject);
    printf("Message:\n");
    printf("==============================\n");
    printf("%s", message);
    printf("==============================\n");
    printf("Your message hath been sent. Doth feelth proud.\n");
    return 0;
}

int main() {
    char to[MAX_EMAIL_LEN], subject[MAX_SUBJECT_LEN], message[MAX_EMAIL_LEN];
    int message_len = read_email(to, subject, message);
    send_email(to, subject, message);
    return 0;
}