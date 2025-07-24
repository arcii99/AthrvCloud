//FormAI DATASET v1.0 Category: Email Client ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_SUBJECT_LEN 50
#define MAX_BODY_LEN 500

// Structure to store mail information
typedef struct {
    char to[50];
    char from[50];
    char subject[MAX_SUBJECT_LEN];
    char body[MAX_BODY_LEN];
} Mail;

// Function to send an email
void sendMail(Mail* mail) {
    char path[50] = "/usr/sbin/sendmail -t";
    FILE* mailPipe = popen(path, "w");

    if (!mailPipe) {
        perror("Could not open pipe to sendmail");
        exit(EXIT_FAILURE);
    }

    // Create email
    fprintf(mailPipe, "To: %s\n", mail->to);
    fprintf(mailPipe, "From: %s\n", mail->from);
    fprintf(mailPipe, "Subject: %s\n\n", mail->subject);
    fprintf(mailPipe, "%s\n", mail->body);

    pclose(mailPipe);
    printf("Mail sent successfully!\n");
}

int main() {
    Mail newMail;

    printf("Enter recipient's email address: ");
    fgets(newMail.to, 50, stdin);
    newMail.to[strcspn(newMail.to, "\n")] = '\0';

    printf("Enter your email address: ");
    fgets(newMail.from, 50, stdin);
    newMail.from[strcspn(newMail.from, "\n")] = '\0';

    printf("Enter email subject: ");
    fgets(newMail.subject, 50, stdin);
    newMail.subject[strcspn(newMail.subject, "\n")] = '\0';

    printf("Enter email body: ");
    fgets(newMail.body, 500, stdin);
    newMail.body[strcspn(newMail.body, "\n")] = '\0';

    sendMail(&newMail);

    return 0;
}