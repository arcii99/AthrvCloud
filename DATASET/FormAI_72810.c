//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEPTH 10
#define MAX_STRING_LENGTH 100

typedef enum {
  JSON_OBJECT,
  JSON_ARRAY,
  JSON_STRING,
  JSON_NUMBER,
  JSON_TRUE,
  JSON_FALSE,
  JSON_NULL
} json_type;

typedef struct json_value {
  json_type type;
  union {
    struct json_value** obj_values;
    double number_value;
    char* string_value;
    int boolean_value;
  } value;
} json_value;

void parse_value(json_value* value, const char* json, int* index, int depth);

void parse_string(json_value* value, const char* json, int* index) {
  int i, j;
  char string[MAX_STRING_LENGTH];
  for (i = *index + 1, j = 0; json[i] != '\"' && j < MAX_STRING_LENGTH; i++, j++) {
    if (json[i] == '\\') {
      i++;
    }
    string[j] = json[i];
  }
  string[j] = '\0';
  value->value.string_value = malloc(sizeof(char) * (strlen(string) + 1));
  strcpy(value->value.string_value, string);
  value->type = JSON_STRING;
  *index = i + 1;
}

void parse_number(json_value* value, const char* json, int* index) {
  char* endptr;
  value->value.number_value = strtod(&json[*index], &endptr);
  value->type = JSON_NUMBER;
  *index = (int)(endptr - json);
}

void parse_boolean(json_value* value, const char* json, int* index) {
  if (strncmp(&json[*index], "true", 4) == 0) {
    value->value.boolean_value = 1;
    value->type = JSON_TRUE;
    *index += 4;
  } else if (strncmp(&json[*index], "false", 5) == 0) {
    value->value.boolean_value = 0;
    value->type = JSON_FALSE;
    *index += 5;
  }
}

void parse_null(json_value* value, const char* json, int* index) {
  if (strncmp(&json[*index], "null", 4) == 0) {
    value->type = JSON_NULL;
    *index += 4;
  }
}

void parse_array(json_value* value, const char* json, int* index, int depth) {
  int count = 0;
  struct json_value** values = malloc(MAX_DEPTH * sizeof(struct json_value*));
  *index += 1;
  while (json[*index] != ']' && count < MAX_DEPTH) {
    values[count] = malloc(sizeof(json_value));
    parse_value(values[count], json, index, depth + 1);
    count++;
    if (json[*index] == ',') {
      *index += 1;
    }
  }
  *index += 1;
  value->value.obj_values = malloc(sizeof(struct json_value*) * count);
  memcpy(value->value.obj_values, values, sizeof(struct json_value*) * count);
  value->type = JSON_ARRAY;
}

void parse_object(json_value* value, const char* json, int* index, int depth) {
  int count = 0;
  struct json_value** values = malloc(sizeof(struct json_value*) * MAX_DEPTH);
  int i = *index + 1;
  while (json[*index] != '}' && count < MAX_DEPTH) {
    if (json[*index] == '\"') {
      values[count] = malloc(sizeof(json_value));
      parse_string(values[count], json, index);
      if (json[*index] == ':') {
        *index += 1;
        parse_value(values[count], json, index, depth + 1);
        count++;
      }
    }
    if (json[*index] == ',') {
      *index += 1;
    }
  }
  *index += 1;
  value->value.obj_values = malloc(sizeof(struct json_value*) * count);
  memcpy(value->value.obj_values, values, sizeof(struct json_value*) * count);
  value->type = JSON_OBJECT;
}

void parse_value(json_value* value, const char* json, int* index, int depth) {
  switch (json[*index]) {
    case '{': parse_object(value, json, index, depth); break;
    case '[': parse_array(value, json, index, depth); break;
    case '\"': parse_string(value, json, index); break;
    case 't': case 'f': parse_boolean(value, json, index); break;
    case 'n': parse_null(value, json, index); break;
    default: parse_number(value, json, index);
  }
}

void print_value(json_value* value, int depth) {
  switch (value->type) {
    case JSON_OBJECT: {
      printf("{\n");
      int i;
      for (i = 0; i < depth; i++) {
        printf("  ");
      }
      depth++;
      for (i = 0; i < sizeof(value->value.obj_values) / sizeof(json_value*); i++) {
        for (int j = 0; j < depth; j++) {
          printf("  ");
        }
        printf("%s: ", value->value.obj_values[i]->value.string_value);
        print_value(value->value.obj_values[i], depth);
        if (i < (sizeof(value->value.obj_values) / sizeof(json_value*)) - 1) {
          printf(",");
        }
        printf("\n");
      }
      depth--;
      for (i = 0; i < depth; i++) {
        printf("  ");
      }
      printf("}");
      break;
    }
    case JSON_ARRAY: {
      printf("[\n");
      int i;
      for (i = 0; i < depth; i++) {
        printf("  ");
      }
      depth++;
      for (i = 0; i < sizeof(value->value.obj_values) / sizeof(json_value*); i++) {
        print_value(value->value.obj_values[i], depth);
        if (i < (sizeof(value->value.obj_values) / sizeof(json_value*)) - 1) {
          printf(",");
        }
        printf("\n");
      }
      depth--;
      for (i = 0; i < depth; i++) {
        printf("  ");
      }
      printf("]\n");
      break;
    }
    case JSON_STRING: printf("\"%s\"", value->value.string_value); break;
    case JSON_NUMBER: printf("%lf", value->value.number_value); break;
    case JSON_TRUE: printf("true"); break;
    case JSON_FALSE: printf("false"); break;
    case JSON_NULL: printf("null"); break;
  }
}

int main() {
  const char* json = "{\"name\": \"John Smith\", \"age\": 25, \"friends\": [\"Alice\", \"Bob\", \"Charlie\"]}";
  int index = 0;
  json_value* value = malloc(sizeof(json_value));
  parse_value(value, json, &index, 0);
  print_value(value, 0);
  return 0;
}