//FormAI DATASET v1.0 Category: Mailing list manager ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing details of each email
struct Email {
  char *to;
  char *subject;
  char *body;
};

// Structure for storing details of a mailing list
struct MailingList {
  char *name;
  char **emails;
  int num_emails;
};

// Function to add an email to a mailing list
void addEmailToMailingList(struct MailingList* list, char* email) {
  list->num_emails++;
  list->emails = realloc(list->emails, list->num_emails * sizeof(char*));
  list->emails[list->num_emails - 1] = email;
}

// Function to create a new mailing list
struct MailingList* createMailingList(char* name) {
  struct MailingList* list = malloc(sizeof(struct MailingList));
  list->name = name;
  list->num_emails = 0;
  list->emails = NULL;
  return list;
}

// Function to delete a mailing list
void deleteMailingList(struct MailingList* list) {
  free(list->name);
  for (int i = 0; i < list->num_emails; i++) {
    free(list->emails[i]);
  }
  free(list->emails);
  free(list);
}

// Function to send an email
void sendEmail(char* to, char* subject, char* body) {
  printf("To: %s\n", to);
  printf("Subject: %s\n", subject);
  printf("Body: %s\n", body);
}

int main() {
  // Create a new mailing list
  struct MailingList* list = createMailingList("My List");

  // Add some emails to the mailing list
  addEmailToMailingList(list, "foo@example.com");
  addEmailToMailingList(list, "bar@example.com");
  addEmailToMailingList(list, "baz@example.com");

  // Send an email to everyone in the mailing list
  for (int i = 0; i < list->num_emails; i++) {
    struct Email email = {
      .to = list->emails[i],
      .subject = "Hello from My Program",
      .body = "This is a test email sent from my C mailing list manager program."
    };
    sendEmail(email.to, email.subject, email.body);
  }

  // Delete the mailing list
  deleteMailingList(list);

  return 0;
}