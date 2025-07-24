//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_SIZE 1024

struct json_object {
  char* name;
  char* value;
  int isArray;
  struct json_object** nestedObjects;
};

struct json_parser {
  char* json;
  int index;
  struct json_object* root;
};

void error(char* message) {
  printf("[ERROR]: %s\n", message);
  exit(1);
}

void consume_space(struct json_parser* parser) {
  while (parser->json[parser->index] == ' ') {
    parser->index++;
  }
}

struct json_parser* json_parser_create(char* json) {
  struct json_parser* parser = malloc(sizeof(struct json_parser));
  parser->json = json;
  parser->index = 0;
  parser->root = NULL;

  return parser;
}

void json_parser_destroy(struct json_parser* parser) {
  free(parser->json);
  free(parser);
}

char* parse_name(struct json_parser* parser) {
  consume_space(parser);

  int len = 0;
  while (parser->json[parser->index + len] != ':' && parser->json[parser->index + len] != ',' && parser->json[parser->index + len] != '}') {
    len++;
  }

  char* name = malloc(len + 1);
  strncpy(name, parser->json + parser->index, len);
  name[len] = '\0';

  parser->index += len;

  return name;
}

char* parse_value(struct json_parser* parser) {
  consume_space(parser);

  int len = 0;
  while (parser->json[parser->index + len] != ',' && parser->json[parser->index + len] != '}') {
    len++;
  }

  char* value = malloc(len + 1);
  strncpy(value, parser->json + parser->index, len);
  value[len] = '\0';

  parser->index += len;

  return value;
}

struct json_object* parse_object(struct json_parser* parser);

struct json_object* parse_array(struct json_parser* parser) {
  consume_space(parser);

  struct json_object* object = malloc(sizeof(struct json_object));
  object->isArray = 1;

  int numObjects = 0;
  struct json_object** nestedObjects = malloc(sizeof(struct json_object*));

  while (parser->json[parser->index] != ']') {
    consume_space(parser);

    if (parser->json[parser->index] != '{') {
      error("Invalid JSON syntax: array objects must start with {");
    }

    struct json_object* nestedObject = parse_object(parser);

    numObjects++;
    nestedObjects = realloc(nestedObjects, numObjects * sizeof(struct json_object*));
    nestedObjects[numObjects - 1] = nestedObject;

    consume_space(parser);

    if (parser->json[parser->index] == ',') {
      parser->index++;
    }
  }

  object->nestedObjects = nestedObjects;

  return object;
}

struct json_object* parse_object(struct json_parser* parser) {
  consume_space(parser);

  struct json_object* object = malloc(sizeof(struct json_object));
  object->name = NULL;
  object->value = NULL;
  object->isArray = 0;
  object->nestedObjects = NULL;

  if (parser->json[parser->index] != '{') {
    error("Invalid JSON syntax: objects must start with {");
  }

  parser->index++;

  while (parser->json[parser->index] != '}') {
    char* name = parse_name(parser);

    consume_space(parser);

    if (parser->json[parser->index] != ':') {
      error("Invalid JSON syntax: name-value pairs must be separated by :");
    }

    parser->index++;

    consume_space(parser);

    char* value;

    if (parser->json[parser->index] == '{') {
      struct json_object* nestedObject = parse_object(parser);

      value = malloc(sizeof(char*));
      snprintf(value, sizeof(char*), "%p", (void*)nestedObject);
    } else if (parser->json[parser->index] == '[') {
      struct json_object* nestedArray = parse_array(parser);

      value = malloc(sizeof(char*));
      snprintf(value, sizeof(char*), "%p", (void*)nestedArray);
    } else {
      value = parse_value(parser);
    }

    consume_space(parser);

    struct json_object* newObject = malloc(sizeof(struct json_object));
    newObject->name = name;
    newObject->value = value;
    newObject->isArray = 0;
    newObject->nestedObjects = NULL;

    if (object->name == NULL) {
      object->name = name;
      object->value = value;
    } else {
      int numObjects = 2;
      struct json_object** nestedObjects = malloc(numObjects * sizeof(struct json_object*));
      nestedObjects[0] = object;
      nestedObjects[1] = newObject;

      struct json_object* newParentObject = malloc(sizeof(struct json_object));
      newParentObject->name = NULL;
      newParentObject->value = NULL;
      newParentObject->isArray = 0;
      newParentObject->nestedObjects = nestedObjects;

      object = newParentObject;
    }

    if (parser->json[parser->index] == ',') {
      parser->index++;
    }
  }

  parser->index++;

  return object;
}

struct json_object* json_parser_parse(struct json_parser* parser) {
  parser->root = parse_object(parser);
  return parser->root;
}

void json_object_print(struct json_object* object, int depth) {
  if (object->isArray) {
    int i;
    printf("[");
    for (i = 0; object->nestedObjects[i] != NULL; i++) {
      json_object_print(object->nestedObjects[i], depth + 1);
      if (object->nestedObjects[i + 1] != NULL) {
        printf(", ");
      }
    }
    printf("]");
  } else {
    printf("{\n");
    int i;
    for (i = 0; object->nestedObjects != NULL && object->nestedObjects[i] != NULL; i++) {
      int j;
      for (j = 0; j < depth + 1; j++) {
        printf("  ");
      }
      printf("\"%s\": ", object->nestedObjects[i]->name);
      json_object_print(object->nestedObjects[i], depth + 1);
      if (object->nestedObjects[i + 1] != NULL) {
        printf(",\n");
      }
    }
    printf("\n");
    int j;
    for (j = 0; j < depth; j++) {
      printf("  ");
    }
    printf("}");
  }
}

int main(int argc, char** argv) {
  char* json = "{\"name\":\"John Smith\",\"age\":25,\"city\":\"New York\",\"children\":[{\"name\":\"Jane Smith\",\"age\":5},{\"name\":\"Tom Smith\",\"age\":3}]}";

  struct json_parser* parser = json_parser_create(json);

  struct json_object* object = json_parser_parse(parser);

  json_object_print(object, 0);

  json_parser_destroy(parser);

  return 0;
}