//FormAI DATASET v1.0 Category: Mailing list manager ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 50
#define MAX_SUBJECT_LEN 100
#define MAX_BODY_LEN 500

typedef struct {
  char name[MAX_NAME_LEN];
  char email[MAX_EMAIL_LEN];
} Email;

typedef struct {
  Email to;
  char subject[MAX_SUBJECT_LEN];
  char body[MAX_BODY_LEN];
} Message;

typedef struct {
  Email emails[MAX_EMAILS];
  int count;
} MailingList;

void addEmail(MailingList* list, char* name, char* email) {
  if (list->count >= MAX_EMAILS) {
    printf("Mailing list is full!");
    return;
  }

  Email newEmail;
  strcpy(newEmail.name, name);
  strcpy(newEmail.email, email);
  list->emails[list->count++] = newEmail;
}

void displayEmails(MailingList* list) {
  printf("Email List:\n");
  printf("%-20s %-30s\n", "Name", "Email");
  printf("--------------------------------------------\n");

  for (int i = 0; i < list->count; i++) {
    printf("%-20s %-30s\n", list->emails[i].name, list->emails[i].email);
  }
}

void sendMessage(MailingList* list, char* name, char* subject, char* body) {
  int found = 0;

  for (int i = 0; i < list->count; i++) {
    if (strcmp(list->emails[i].name, name) == 0) {
      found = 1;

      Message newMessage;
      newMessage.to = list->emails[i];
      strcpy(newMessage.subject, subject);
      strcpy(newMessage.body, body);

      printf("\n\nTo: %s <%s>\n", newMessage.to.name, newMessage.to.email);
      printf("Subject: %s\n", newMessage.subject);
      printf("Body: %s\n", newMessage.body);
    }
  }

  if (!found) {
    printf("Email with name %s not found!\n", name);
  }
}

int main(void) {
  MailingList list = { .count = 0 };

  addEmail(&list, "John Doe", "john.doe@example.com");
  addEmail(&list, "Jane Doe", "jane.doe@example.com");

  displayEmails(&list);

  printf("\nSending message to John Doe...\n");
  sendMessage(&list, "John Doe", "Hello John!", "Hey John, how are you?");

  printf("\nSending message to Bob Smith...\n");
  sendMessage(&list, "Bob Smith", "Hello Bob!", "Hey Bob, how are you?");

  return 0;
}