//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRING_LENGTH 100

typedef enum {
  JSON_OBJECT,
  JSON_ARRAY,
  JSON_STRING,
  JSON_NUMBER,
  JSON_TRUE,
  JSON_FALSE,
  JSON_NULL
} json_token_type;

typedef struct {
  json_token_type type;
  char *value;  
} json_token;

typedef struct node_t {
  json_token token;
  struct node_t *next;
} list_node;

list_node *parse_json(char *json_string);
list_node *parse_object(char *json_string, int *cursor);
list_node *parse_array(char *json_string, int *cursor);
json_token parse_string(char *json_string, int *cursor);
json_token parse_number(char *json_string, int *cursor);
void print_list(list_node *head);
void free_list(list_node *head);

int main() {
  char json_string[] = "{\"name\":\"John\",\"age\":25,\"pets\":[\"dog\",\"cat\"]}";
  list_node *json_list = parse_json(json_string);
  
  printf("The parsed JSON:\n");
  print_list(json_list);

  free_list(json_list);
  
  return 0;
}

list_node *parse_json(char *json_string) {
  int cursor = 0;
  list_node *head = parse_object(json_string, &cursor);
  
  return head;
}

list_node *parse_object(char *json_string, int *cursor) {
  list_node *head = NULL;
  list_node *tail = NULL;
  
  (*cursor)++; // skip '{'
  
  while (json_string[*cursor] != '}') {
    if (json_string[*cursor] == ',') {
      (*cursor)++;
    }
    
    json_token key = parse_string(json_string, cursor);
    (*cursor)++; // skip ':'
    json_token value = parse_string(json_string, cursor);
    
    if (!head) {
      head = malloc(sizeof(list_node));
      tail = head;
    } else {
      tail->next = malloc(sizeof(list_node));
      tail = tail->next;
    }
    
    tail->token.type = JSON_STRING;
    tail->token.value = key.value;
    tail->next = malloc(sizeof(list_node));
    tail = tail->next;
    tail->token = value;
  }
  
  (*cursor)++; // skip '}'
  
  return head;
}

list_node *parse_array(char *json_string, int *cursor) {
  list_node *head = NULL;
  list_node *tail = NULL;
  
  (*cursor)++; // skip '['
  
  while (json_string[*cursor] != ']') {
    if (json_string[*cursor] == ',') {
      (*cursor)++;
    }
    
    json_token value = parse_string(json_string, cursor);
    
    if (!head) {
      head = malloc(sizeof(list_node));
      tail = head;
    } else {
      tail->next = malloc(sizeof(list_node));
      tail = tail->next;
    }
    
    tail->token = value;
  }
  
  (*cursor)++; // skip ']'
  
  return head;
}

json_token parse_string(char *json_string, int *cursor) {
  (*cursor)++; // skip '"'
  char string_value[MAX_STRING_LENGTH];
  int i = 0;
  
  while (json_string[*cursor] != '"') {
    string_value[i] = json_string[*cursor];
    i++;
    (*cursor)++;
  }
  
  (*cursor)++; // skip '"'
  
  json_token token;
  token.type = JSON_STRING;
  token.value = strdup(string_value);
  
  return token;
}

json_token parse_number(char *json_string, int *cursor) {
  char number_value[MAX_STRING_LENGTH];
  int i = 0;
  
  while (isdigit(json_string[*cursor])) {
    number_value[i] = json_string[*cursor];
    i++;
    (*cursor)++;
  }
  
  json_token token;
  token.type = JSON_NUMBER;
  token.value = strdup(number_value);
  
  return token;
}

void print_list(list_node *head) {
  list_node *current = head;
  
  while (current) {
    switch(current->token.type) {
      case JSON_OBJECT:
        printf("{\n");
        print_list(current->token.value);
        printf("}\n");
        break;
      case JSON_ARRAY:
        printf("[\n");
        print_list(current->token.value);
        printf("]\n");
        break;
      case JSON_STRING:
        printf("\"%s\"\n", current->token.value);
        break;
      case JSON_NUMBER:
        printf("%s\n", current->token.value);
        break;
      case JSON_TRUE:
        printf("true\n");
        break;
      case JSON_FALSE:
        printf("false\n");
        break;
      case JSON_NULL:
        printf("null\n");
        break;
    }
    
    current = current->next;
  }
}

void free_list(list_node *head) {
  list_node *current = head;
  
  while (current) {
    list_node *next = current->next;
    free(current->token.value);
    free(current);
    current = next;
  }
}