//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_SIZE 2048

typedef enum {
  JSON_NULL = 0,
  JSON_BOOLEAN,
  JSON_NUMBER,
  JSON_STRING,
  JSON_ARRAY,
  JSON_OBJECT
} json_type;

typedef struct json_value {
  json_type type;
  union {
    int boolean;
    double number;
    char* string;
    struct json_array* array;
    struct json_object* object;
  } data;
} json_value;

typedef struct json_array {
  int size;
  struct json_value** values;
} json_array;

typedef struct json_object {
  int size;
  char** keys;
  struct json_value** values;
} json_object;

void print_indent(int level) {
  for (int i = 0; i < level; i++) {
    putchar(' ');
    putchar(' ');
  }
}

void print_value(json_value* value, int level) {
  switch (value->type) {
    case JSON_NULL: {
        printf("null");
        break;
    }
    case JSON_BOOLEAN: {
        printf(value->data.boolean ? "true" : "false");
        break;
    }
    case JSON_NUMBER: {
        printf("%g", value->data.number);
        break;
    }
    case JSON_STRING: {
        printf("\"%s\"", value->data.string);
        break;
    }
    case JSON_ARRAY: {
        printf("[\n");
        for (int i = 0; i < value->data.array->size; i++) {
          print_indent(level + 1);
          print_value(value->data.array->values[i], level + 1);
          putchar(i == value->data.array->size - 1 ? '\n' : ',');
        }
        print_indent(level);
        putchar(']');
        break;
    }
    case JSON_OBJECT: {
        printf("{\n");
        for (int i = 0; i < value->data.object->size; i++) {
          print_indent(level + 1);
          printf("\"%s\" : ", value->data.object->keys[i]);
          print_value(value->data.object->values[i], level + 1);
          putchar(i == value->data.object->size - 1 ? '\n' : ',');
        }
        print_indent(level);
        putchar('}');
        break;
    }
  }
}

json_value* parse_value(const char** json);

json_value* parse_null(const char** json) {
  if (strncmp(*json, "null", 4) == 0) {
    *json += 4;
    json_value* value = malloc(sizeof(json_value));
    value->type = JSON_NULL;
    return value;
  }
  return NULL;
}

json_value* parse_boolean(const char** json) {
  if (strncmp(*json, "true", 4) == 0) {
    *json += 4;
    json_value* value = malloc(sizeof(json_value));
    value->type = JSON_BOOLEAN;
    value->data.boolean = 1;
    return value;
  }
  if (strncmp(*json, "false", 5) == 0) {
    *json += 5;
    json_value* value = malloc(sizeof(json_value));
    value->type = JSON_BOOLEAN;
    value->data.boolean = 0;
    return value;
  }
  return NULL;
}

json_value* parse_number(const char** json) {
  char* endptr;
  double number = strtod(*json, &endptr);
  if (*json != endptr) {
    *json = endptr;
    json_value* value = malloc(sizeof(json_value));
    value->type = JSON_NUMBER;
    value->data.number = number;
    return value;
  }
  return NULL;
}

json_value* parse_string(const char** json) {
  if (**json == '\"') {
    const char* end = *json + 1;
    while (*end != '\"' && *end != '\0') {
      if (*end == '\\') ++end;
      ++end;
    }
    if (*end == '\"') {
      int len = end - *json - 1;
      char* str = malloc(len + 1);
      char* dest = str;
      char* src = (char*)*json + 1;
      while (*src != '\"' && *src != '\0') {
        if (*src == '\\') ++src;
        *dest = *src;
        ++src;
        ++dest;
      }
      *dest = '\0';
      *json = end + 1;
      json_value* value = malloc(sizeof(json_value));
      value->type = JSON_STRING;
      value->data.string = str;
      return value;
    }
  }
  return NULL;
}

json_value* parse_array(const char** json) {
  if (**json == '[') {
    ++(*json);
    json_array* array = malloc(sizeof(json_array));
    array->size = 0;
    array->values = NULL;
    while (**json != ']' && **json != '\0') {
      json_value* value = parse_value(json);
      if (value == NULL) return NULL;
      ++array->size;
      array->values = realloc(array->values, array->size * sizeof(json_value*));
      array->values[array->size - 1] = value;
      if (**json == ',') ++(*json);
    }
    if (**json == ']') {
      ++(*json);
      json_value* value = malloc(sizeof(json_value));
      value->type = JSON_ARRAY;
      value->data.array = array;
      return value;
    }
  }
  return NULL;
}

json_value* parse_object(const char** json) {
  if (**json == '{') {
    ++(*json);
    json_object* object = malloc(sizeof(json_object));
    object->size = 0;
    object->keys = NULL;
    object->values = NULL;
    while (**json != '}' && **json != '\0') {
      json_value* key = parse_string(json);
      if (key == NULL) return NULL;
      if (**json != ':') return NULL;
      ++(*json);
      json_value* value = parse_value(json);
      if (value == NULL) return NULL;
      ++object->size;
      object->keys = realloc(object->keys, object->size * sizeof(char*));
      object->values = realloc(object->values, object->size * sizeof(json_value*));
      object->keys[object->size - 1] = key->data.string;
      object->values[object->size - 1] = value;
      if (**json == ',') ++(*json);
    }
    if (**json == '}') {
      ++(*json);
      json_value* value = malloc(sizeof(json_value));
      value->type = JSON_OBJECT;
      value->data.object = object;
      return value;
    }
  }
  return NULL;
}

json_value* parse_value(const char** json) {
  json_value* value = parse_null(json);
  if (value != NULL) return value;
  value = parse_boolean(json);
  if (value != NULL) return value;
  value = parse_number(json);
  if (value != NULL) return value;
  value = parse_string(json);
  if (value != NULL) return value;
  value = parse_array(json);
  if (value != NULL) return value;
  value = parse_object(json);
  return value;
}

json_value* parse_json(const char* json) {
  json_value* value = parse_value(&json);
  while (isspace(*json)) ++json;
  return *json == '\0' ? value : NULL;
}

int main(void) {
  char json_str[MAX_JSON_SIZE];
  printf("Enter a JSON string:\n");
  fgets(json_str, MAX_JSON_SIZE, stdin);
  json_value* json = parse_json(json_str);
  if (json == NULL) {
    printf("Invalid JSON input\n");
    return 1;
  }
  printf("Parsed JSON:\n");
  print_value(json, 0);
  putchar('\n');
  return 0;
}