//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LEN 100
#define MAX_NAME_LEN 50
#define MAX_LIST_LEN 100

typedef struct {
  char name[MAX_NAME_LEN];
  char email[MAX_EMAIL_LEN];
} Person;

typedef struct {
  char name[MAX_NAME_LEN];
  Person people[MAX_LIST_LEN];
  int count;
} List;

List createList(char *listName) {
  List list;
  strcpy(list.name, listName);
  list.count = 0;
  return list;
}

void addPerson(List *list, char *name, char *email) {
  Person person;
  strcpy(person.name, name);
  strcpy(person.email, email);
  list->people[list->count] = person;
  list->count++;
}

void printList(List *list) {
  printf("%s:\n", list->name);
  for(int i=0; i<list->count; i++) {
    printf("%s <%s>\n", list->people[i].name, list->people[i].email);
  }
}

void exportList(List *list, char *filename) {
  FILE *fp = fopen(filename, "w");
  fprintf(fp, "%s:\n", list->name);
  for(int i=0; i<list->count; i++) {
    fprintf(fp, "%s <%s>\n", list->people[i].name, list->people[i].email);
  }
  fclose(fp);
}

int main() {
  List myFriends = createList("My Friends");
  addPerson(&myFriends, "John Smith", "johnsmith@gmail.com");
  addPerson(&myFriends, "Sarah Johnson", "sarahjohnson@hotmail.com");
  addPerson(&myFriends, "Mike Davis", "mikedavis@yahoo.com");
  printList(&myFriends);
  exportList(&myFriends, "myfriends.txt");
  return 0;
}