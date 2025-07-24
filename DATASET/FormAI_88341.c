//FormAI DATASET v1.0 Category: HTML beautifier ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  char data;
  struct node *next;
  struct node *prev;
};

typedef struct node Node;

Node *new_node(char data) {
  Node *p = (Node *) malloc(sizeof(Node));
  p->data = data;
  p->next = NULL;
  p->prev = NULL;
  return p;
}

typedef struct {
  Node *head;
  Node *tail;
} List;

void init_list(List *list) {
  list->head = NULL;
  list->tail = NULL;
}

void append(List *list, char data) {
  Node *p = new_node(data);
  if (list->tail == NULL) {
    list->head = p;
    list->tail = p;
  } else {
    p->prev = list->tail;
    list->tail->next = p;
    list->tail = p;
  }
}

void print_list(List *list) {
  Node *p = list->head;
  while (p != NULL) {
    printf("%c", p->data);
    p = p->next;
  }
}

void beautify(char *string) {
  int length = strlen(string);
  List list;
  init_list(&list);
  int indentation_level = 0;
  for (int i = 0; i < length; i++) {
    char current_char = string[i];
    if (current_char == '<') {
      append(&list, current_char);
      if (i+1 < length && string[i+1] == '/') {
        print_list(&list);
        printf("\n");
        for (int j = 0; j < indentation_level-2; j++) {
          printf(" ");
        }
        indentation_level -= 2;
      } else {
        for (int j = 0; j < indentation_level; j++) {
          printf(" ");
        }
        printf("%c", current_char);
        if (i+1 < length && string[i+1] != '/') {
          printf("\n");
          indentation_level += 2;
        }
      }
    } else if (current_char == '>') {
      append(&list, current_char);
      printf("%c", current_char);
      if (i+1 < length && string[i+1] != '<') {
        printf("\n");
      }
    } else {
      append(&list, current_char);
      printf("%c", current_char);
    }
  }
}

int main() {
  char *string = "<html><head><title>My Page</title></head><body><h1>Welcome to my page</h1><p>This is my first web page</p></body></html>";
  beautify(string);
  return 0;
}