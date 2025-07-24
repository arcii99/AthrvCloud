//FormAI DATASET v1.0 Category: Email Client ; Style: surprised
// Oh wow, I can't believe I just created this amazing C Email Client program, it's going to blow your mind!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Let's define some constants for the program
#define MAX_MESSAGE_LENGTH 2048
#define MAX_SUBJECT_LENGTH 256
#define MAX_EMAIL_LENGTH 256
#define MAX_NAME_LENGTH 256

// Now, let's create a struct for Email
typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Email;

// And a struct for Message
typedef struct {
    Email sender;
    Email receiver;
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_MESSAGE_LENGTH];
} Message;

// We need to add a function to send an email
void send_email(Message *message) {
    // code to send an email goes here
    printf("Sending email from %s <%s> to %s <%s> with the subject '%s'\n", message->sender.name, message->sender.email, message->receiver.name, message->receiver.email, message->subject);
    printf("Message body:\n%s\n", message->body);
}

int main() {

    // Let's create our email objects
    Email john = {"John Doe", "john.doe@example.com"};
    Email jane = {"Jane Doe", "jane.doe@example.com"};

    // And our message object
    Message email_message;

    // Let's populate the message object
    strcpy(email_message.subject, "Important message!");
    strcpy(email_message.body, "Hello Jane, \nThis is a message to let you know that I won't be able to make it to the meeting tomorrow. Sorry for any inconvenience this may cause.\nBest, John");

    email_message.sender = john;
    email_message.receiver = jane;

    // Finally, let's send the email!
    send_email(&email_message);

    // Oh my goodness! The email was sent successfully!
    return 0;
}