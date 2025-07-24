//FormAI DATASET v1.0 Category: Email Client ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_EMAILS 100

struct Email {
  char sender[100];
  char recipient[100];
  char subject[200];
  char message[1000];
};

struct Inbox {
  struct Email emails[MAX_EMAILS];
  int count;
};

struct Sent {
  struct Email emails[MAX_EMAILS];
  int count;
};

struct Email create_email(char sender[], char recipient[], char subject[], char message[]) {
  struct Email email;
  strcpy(email.sender, sender);
  strcpy(email.recipient, recipient);
  strcpy(email.subject, subject);
  strcpy(email.message, message);
  return email;
}

void send_email(struct Email email, struct Inbox *inbox, struct Sent *sent) {
  sent->emails[sent->count] = email;
  sent->count++;
  
  inbox->emails[inbox->count] = email;
  inbox->count++;
}

void print_email(struct Email email) {
  printf("From: %s\n", email.sender);
  printf("To: %s\n", email.recipient);
  printf("Subject: %s\n", email.subject);
  printf("Message: %s\n", email.message);
}

void print_emails(struct Email emails[], int count) {
  int i;
  for(i = 0; i < count; i++) {
    printf("%d) ------------\n", i+1);
    print_email(emails[i]);
    printf("\n");
  }
}

void print_inbox(struct Inbox inbox) {
  printf("INBOX:\n");
  print_emails(inbox.emails, inbox.count);
}

void print_sent(struct Sent sent) {
  printf("SENT:\n");
  print_emails(sent.emails, sent.count);
}

int main() {
  struct Inbox inbox = { .count = 0 };
  struct Sent sent = { .count = 0 };
  struct Email email;

  // Send some emails
  email = create_email("john@example.com", "jane@example.com", "Hello Jane", "How are you?");
  send_email(email, &inbox, &sent);

  email = create_email("jane@example.com", "john@example.com", "Re: Hello John", "I'm good, thanks. How are you?");
  send_email(email, &inbox, &sent);

  // Print inbox and sent
  print_inbox(inbox);
  print_sent(sent);

  return 0;
}