//FormAI DATASET v1.0 Category: Email Client ; Style: Linus Torvalds
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

// define constants
#define MAX_EMAIL_COUNT 50
#define MAX_BUFFER_SIZE 2048
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 500

// define global variables
static char to[MAX_EMAIL_COUNT][MAX_BUFFER_SIZE];
static char cc[MAX_EMAIL_COUNT][MAX_BUFFER_SIZE];
static char bcc[MAX_EMAIL_COUNT][MAX_BUFFER_SIZE];
static char subject[MAX_SUBJECT_LENGTH];
static char body[MAX_BODY_LENGTH];
static char sender[MAX_BUFFER_SIZE];
static char password[MAX_BUFFER_SIZE];
static char smtp_server[MAX_BUFFER_SIZE];
static int to_count = 0;
static int cc_count = 0;
static int bcc_count = 0;

// function to read input from user
static void read_input(char *buffer) {
    fgets(buffer, MAX_BUFFER_SIZE - 1, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
}

// main function
int main(int argc, char **argv) {
    // read inputs
    printf("Enter sender email address: ");
    read_input(sender);
    printf("Enter sender email password: ");
    read_input(password);
    printf("Enter SMTP server address: ");
    read_input(smtp_server);
    printf("\nEnter recipients (separated by comma): ");
    read_input(to[0]);
    char *token = strtok(to[0], ",");
    while (token != NULL) {
        to_count++;
        strcpy(to[to_count], token);
        token = strtok(NULL, ",");
    }
    printf("Enter cc (separated by comma): ");
    read_input(cc[0]);
    token = strtok(cc[0], ",");
    while (token != NULL) {
        cc_count++;
        strcpy(cc[cc_count], token);
        token = strtok(NULL, ",");
    }
    printf("Enter bcc (separated by comma): ");
    read_input(bcc[0]);
    token = strtok(bcc[0], ",");
    while (token != NULL) {
        bcc_count++;
        strcpy(bcc[bcc_count], token);
        token = strtok(NULL, ",");
    }
    printf("Enter subject: ");
    read_input(subject);
    printf("Enter email body: ");
    read_input(body);

    // construct email message
    char message[MAX_BUFFER_SIZE];
    sprintf(message, "From: %s\r\n", sender);
    strcat(message, "To: ");
    for (int i = 1; i <= to_count; i++) {
        strcat(message, to[i]);
        if (i != to_count) strcat(message, ",");
    }
    strcat(message, "\r\nCc: ");
    for (int i = 1; i <= cc_count; i++) {
        strcat(message, cc[i]);
        if (i != cc_count) strcat(message, ",");
    }
    strcat(message, "\r\nBcc: ");
    for (int i = 1; i <= bcc_count; i++) {
        strcat(message, bcc[i]);
        if (i != bcc_count) strcat(message, ",");
    }
    strcat(message, "\r\nSubject: ");
    strcat(message, subject);
    strcat(message, "\r\n\r\n");
    strcat(message, body);

    // create temporary file for email message
    char temp_file[MAX_BUFFER_SIZE];
    sprintf(temp_file, "/tmp/email_%d.txt", getpid());
    FILE *fp = fopen(temp_file, "w");
    fprintf(fp, message);
    fclose(fp);

    // send email using 'sendmail' command
    char sendmail_cmd[MAX_BUFFER_SIZE];
    sprintf(sendmail_cmd, "echo %s | openssl s_client -starttls smtp -connect %s:587 -crlf -quiet -ign_eof", password, smtp_server);
    char sendmail_options[MAX_BUFFER_SIZE];
    sprintf(sendmail_options, "%s -f %s %s <%s", sendmail_cmd, sender, to[1], temp_file);
    system(sendmail_options);

    // delete temporary file
    remove(temp_file);

    // print success message and exit
    printf("\nEmail sent successfully!\n");
    exit(0);
}