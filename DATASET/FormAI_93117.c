//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 100

typedef enum {
  JSON_STRING,
  JSON_NUMBER,
  JSON_BOOLEAN,
  JSON_OBJECT,
  JSON_ARRAY,
  JSON_NULL
} JSON_TYPE;

typedef struct json {
  JSON_TYPE type;
  char* key;
  union {
    char* string;
    double number;
    bool boolean;
    struct json** children;
  } value;
} JSON;

char* read_token(FILE* file) {
  char* token = malloc(sizeof(char) * MAX_LENGTH);
  char c = fgetc(file);
  int i = 0;

  while (c != EOF && c != ' ' && c != '\n' && c != '\r' && c != '\t' && c != ',' && c != ':' && c != '[' && c != ']'
      && c != '{' && c != '}') {
    token[i] = c;
    i++;
    c = fgetc(file);
  }

  token[i] = '\0';

  if (c != EOF) {
    ungetc(c, file);
  }

  return token;
}

JSON* parse_json(FILE* file) {
  JSON* json = malloc(sizeof(JSON));
  char* token = read_token(file);

  if (strcmp(token, "{") == 0) {
    json->type = JSON_OBJECT;
    token = read_token(file);
    json->key = malloc(sizeof(char) * strlen(token));
    strcpy(json->key, token);

    token = read_token(file);

    if (strcmp(token, "}") != 0) {
      ungetc(token[0], file);
      json->value.children = malloc(sizeof(JSON*) * MAX_LENGTH);
      int i = 0;

      while (true) {
        json->value.children[i] = parse_json(file);
        token = read_token(file);

        if (strcmp(token, "}") == 0) {
          break;
        }

        i++;
      }
    } else {
      json->value.children = NULL;
    }
  } else if (strcmp(token, "[") == 0) {
    json->type = JSON_ARRAY;
    json->key = NULL;

    token = read_token(file);

    if (strcmp(token, "]") != 0) {
      ungetc(token[0], file);
      json->value.children = malloc(sizeof(JSON*) * MAX_LENGTH);
      int i = 0;

      while (true) {
        json->value.children[i] = parse_json(file);
        token = read_token(file);

        if (strcmp(token, "]") == 0) {
          break;
        }

        i++;
      }
    } else {
      json->value.children = NULL;
    }
  } else {
    json->key = NULL;

    if (strcmp(token, "true") == 0) {
      json->type = JSON_BOOLEAN;
      json->value.boolean = true;
    } else if (strcmp(token, "false") == 0) {
      json->type = JSON_BOOLEAN;
      json->value.boolean = false;
    } else if (strcmp(token, "null") == 0) {
      json->type = JSON_NULL;
      json->value.string = NULL;
    } else if (token[0] == '\"') {
      json->type = JSON_STRING;
      json->value.string = malloc(sizeof(char) * strlen(token));
      strcpy(json->value.string, token + 1);

      while (token[strlen(token)-1] != '\"') {
        token = read_token(file);
        strcat(json->value.string, " ");
        strcat(json->value.string, token);
      }

      json->value.string[strlen(json->value.string)-1] = '\0';
    } else {
      json->type = JSON_NUMBER;
      json->value.number = atof(token);
    }
  }

  return json;
}

void print_json(JSON* json) {
  if (json == NULL) {
    printf("null");
    return;
  }

  switch (json->type) {
    case JSON_STRING:
      printf("\"%s\"", json->value.string);
      break;
    case JSON_NUMBER:
      printf("%f", json->value.number);
      break;
    case JSON_BOOLEAN:
      printf(json->value.boolean ? "true" : "false");
      break;
    case JSON_OBJECT: {
      printf("{ \"%s\" : {", json->key);

      for (int i = 0; json->value.children[i] != NULL; i++) {
        printf("%s", i == 0 ? "" : ", ");
        printf(" \"%s\" : ", json->value.children[i]->key);
        print_json(json->value.children[i]);
      }

      printf(" } }");
      break;
    }
    case JSON_ARRAY: {
      printf("{ \"%s\" : [", json->key);

      for (int i = 0; i < MAX_LENGTH && json->value.children[i] != NULL; i++) {
        printf("%s", i == 0 ? "" : ", ");
        print_json(json->value.children[i]);
      }

      printf(" ] }");
      break;
    }
    case JSON_NULL:
      printf("null");
      break;
  }
}

int main() {
  FILE* file = fopen("example.json", "r");

  if (file != NULL) {
    JSON* json = parse_json(file);
    print_json(json);
    fclose(file);
  }

  return 0;
}