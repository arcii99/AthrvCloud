//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STACK_SIZE 1000
#define MAX_JSON_SIZE 10000

typedef enum {
  NONE,
  EXPECT_KEY,
  EXPECT_COLON,
  EXPECT_VALUE,
  EXPECT_COMMA,
} ParserState;

typedef enum {
  OBJECT,
  ARRAY,
} ValueType;

typedef struct {
  char name[128];
  ValueType type;
} Member;

typedef struct {
  char key[128];
  char value[1024];
  ValueType type;
} JsonNode;

typedef struct {
  JsonNode nodes[128];
  int length;
} JsonArray;

typedef struct {
  Member members[128];
  JsonNode nodes[128];
  int length;
} JsonObject;

typedef struct {
  ParserState state;
  char stack[MAX_STACK_SIZE];
  int stackSize;
  char json[MAX_JSON_SIZE];
  int jsonSize;

  JsonObject objectStack[MAX_STACK_SIZE];
  int objectStackSize;
  JsonArray arrayStack[MAX_STACK_SIZE];
  int arrayStackSize;

  char key[128];
  char value[1024];
  bool escapeChar;
  bool isValueString;
  int index;
  ValueType valueType;
} JsonParser;

void push(JsonParser *parser, char c) {
  parser->stack[parser->stackSize++] = c;
}

char pop(JsonParser *parser) {
  return parser->stack[--parser->stackSize];
}

void clear(JsonParser *parser) {
  memset(parser->json, 0, MAX_JSON_SIZE);
  parser->jsonSize = 0;
  parser->state = NONE;
  memset(parser->stack, 0, MAX_STACK_SIZE);
  parser->stackSize = 0;
  memset(parser->objectStack, 0, MAX_STACK_SIZE);
  parser->objectStackSize = 0;
  memset(parser->arrayStack, 0, MAX_STACK_SIZE);
  parser->arrayStackSize = 0;
  memset(parser->key, 0, 128);
  memset(parser->value, 0, 1024);
  parser->escapeChar = false;
  parser->isValueString = false;
  parser->index = 0;
  parser->valueType = OBJECT;
}

char *trim(char *str) {
  char *end;

  while (isspace(*str)) str++;

  if (*str == 0) return str;

  end = str + strlen(str) - 1;
  while (end > str && isspace(*end)) end--;

  *(end+1) = 0;

  return str;
}

void parseObject(JsonParser *parser) {
  JsonObject object;
  object.length = 0;

  while (true) {
    char c = pop(parser);

    if (c == '}') {
      JsonObject *parentObject = parser->objectStack + parser->objectStackSize - 1;

      if (parentObject->length == 0) {
        memcpy(parentObject->nodes, object.nodes, object.length * sizeof(JsonNode));
        parentObject->length = object.length;
      } else {
        for (int i = 0; i < object.length; i++) {
          bool found = false;
          for (int j = 0; j < parentObject->length; j++) {
            if (strcmp(parentObject->nodes[j].key, object.nodes[i].key) == 0) {
              memcpy(parentObject->nodes[j].value, object.nodes[i].value, strlen(object.nodes[i].value));
              found = true;
              break;
            }
          }
          if (!found) {
            memcpy(parentObject->nodes + parentObject->length++, object.nodes + i, sizeof(JsonNode));
          }
        }
      }

      parser->objectStackSize--;
      parser->valueType = OBJECT;
      break;
    } else if (c == ',') {
      JsonObject *parentObject = parser->objectStack + parser->objectStackSize - 1;

      if (parentObject->length == 0) {
        memcpy(parentObject->nodes, object.nodes, object.length * sizeof(JsonNode));
        parentObject->length = object.length;
      } else {
        for (int i = 0; i < object.length; i++) {
          bool found = false;
          for (int j = 0; j < parentObject->length; j++) {
            if (strcmp(parentObject->nodes[j].key, object.nodes[i].key) == 0) {
              memcpy(parentObject->nodes[j].value, object.nodes[i].value, strlen(object.nodes[i].value));
              found = true;
              break;
            }
          }
          if (!found) {
            memcpy(parentObject->nodes + parentObject->length++, object.nodes + i, sizeof(JsonNode));
          }
        }
      }

      object.length = 0;
      parser->state = EXPECT_KEY;
    } else if (c == ':') {
      strcpy(object.nodes[object.length - 1].value, parser->value);
      memset(parser->value, 0, 1024);
      parser->state = EXPECT_VALUE;
    } else if (c == '\"') {
      if (parser->isValueString && !parser->escapeChar) {
        parser->isValueString = false;
        strcpy(object.nodes[object.length - 1].value, parser->value);
        memset(parser->value, 0, 1024);
      } else if (!parser->isValueString) {
        parser->isValueString = true;
      }
    } else if (c == '\\') {
      parser->escapeChar = true;
    } else if (c == 'n' && parser->escapeChar) {
      strcat(parser->value, "\n");
      parser->escapeChar = false;
    } else if (c == 't' && parser->escapeChar) {
      strcat(parser->value, "\t");
      parser->escapeChar = false;
    } else {
      if (parser->state == EXPECT_KEY) {
        strcat(parser->key, &c);
      } else if (parser->state == EXPECT_VALUE) {
        strcat(parser->value, &c);
      }
    }

    if (parser->state == EXPECT_KEY && c == '\"') {
      memset(parser->key, 0, 128);
      parser->state = EXPECT_COLON;
    } else if (parser->state == EXPECT_VALUE && !parser->isValueString && (c == ',' || c == '}')) {
      strcpy(object.nodes[object.length++].key, parser->key);
      memset(parser->key, 0, 128);
      memset(parser->value, 0, 1024);
      parser->state = EXPECT_KEY;
      parser->isValueString = false;
    }
  }
}

void parseArray(JsonParser *parser) {
  JsonArray array;
  array.length = 0;

  while (true) {
    char c = pop(parser);

    if (c == ']') {
      JsonArray *parentArray = parser->arrayStack + parser->arrayStackSize - 1;

      for (int i = 0; i < array.length; i++) {
        memcpy(parentArray->nodes + parentArray->length++, array.nodes + i, sizeof(JsonNode));
      }

      parser->arrayStackSize--;
      parser->valueType = OBJECT;
      break;
    } else if (c == ',') {
      JsonArray *parentArray = parser->arrayStack + parser->arrayStackSize - 1;

      for (int i = 0; i < array.length; i++) {
        memcpy(parentArray->nodes + parentArray->length++, array.nodes + i, sizeof(JsonNode));
      }

      array.length = 0;
      parser->state = EXPECT_VALUE;
    } else {
      if (c == '\"') {
        if (parser->isValueString && !parser->escapeChar) {
          parser->isValueString = false;
          strcpy(array.nodes[array.length - 1].value, parser->value);
          memset(parser->value, 0, 1024);
        } else if (!parser->isValueString) {
          parser->isValueString = true;
        }
      } else if (c == '\\') {
        parser->escapeChar = true;
      } else if (parser->state == EXPECT_VALUE) {
        strcat(parser->value, &c);
      }

      if (!parser->isValueString && (c == ',' || c == ']')) {
        memset(parser->value, 0, 1024);
        array.nodes[array.length++].type = parser->valueType;
        parser->state = EXPECT_VALUE;
      }
    }

    if (parser->state == EXPECT_VALUE && (c == '{' || c == '[')) {
      if (c == '{') {
        parser->objectStack[parser->objectStackSize++].length = 0;
        parser->valueType = OBJECT;
      } else {
        parser->arrayStack[parser->arrayStackSize++].length = 0;
        parser->valueType = ARRAY;
      }
      clear(parser);
      push(parser, c);
      parse(parser);
    }
  }
}

void parse(JsonParser *parser) {
  char c = pop(parser);

  if (c == '{') {
    parser->objectStack[parser->objectStackSize++].length = 0;
    parser->valueType = OBJECT;
    parse(parser);
  } else if (c == '[') {
    parser->arrayStack[parser->arrayStackSize++].length = 0;
    parser->valueType = ARRAY;
    parse(parser);
  } else if (parser->state == EXPECT_COMMA && c == '\"') {
    parser->state = EXPECT_KEY;
    memset(parser->key, 0, 128);
    strcat(parser->key, &c);
  } else if (parser->state == EXPECT_KEY && c == '\"') {
    memset(parser->key, 0, 128);
    parser->state = EXPECT_COLON;
  } else if (parser->state == EXPECT_COLON && c == ':') {
    parser->state = EXPECT_VALUE;
  } else if (parser->state == EXPECT_VALUE && c == '\"') {
    parser->isValueString = true;
  } else if (parser->state == EXPECT_VALUE && !parser->isValueString && (c == ',' || c == '}')) {
    JsonNode node;
    strcpy(node.key, parser->key);
    strcpy(node.value, parser->value);
    memset(parser->key, 0, 128);
    memset(parser->value, 0, 1024);

    if (parser->valueType == OBJECT) {
      parser->objectStack[parser->objectStackSize - 1].nodes[parser->objectStack[parser->objectStackSize - 1].length++] = node;
    } else {
      parser->arrayStack[parser->arrayStackSize - 1].nodes[parser->arrayStack[parser->arrayStackSize - 1].length++] = node;
    }

    if (c == ',') {
      parser->state = EXPECT_COMMA;
    } else {
      if (parser->valueType == OBJECT) {
        parseObject(parser);
      } else {
        parseArray(parser);
      }
    }
  } else {
    if (c == '\\') {
      parser->escapeChar = true;
    } else if (parser->state == EXPECT_VALUE) {
      strcat(parser->value, &c);
    }

    if (parser->state == EXPECT_VALUE && (c == '{' || c == '[')) {
      if (c == '{') {
        parser->objectStack[parser->objectStackSize++].length = 0;
        parser->valueType = OBJECT;
      } else {
        parser->arrayStack[parser->arrayStackSize++].length = 0;
        parser->valueType = ARRAY;
      }
      clear(parser);
      push(parser, c);
      parse(parser);
    }
  }
}

int main() {
  JsonParser parser;
  clear(&parser);
  char json[] = "{\n \"name\": \"John\", \n \"age\": 30, \n \"cars\": [ \n  { \"name\":\"Ford\", \"models\":[ \"Fiesta\", \"Focus\", \"Mustang\" ] }, \n  { \"name\":\"BMW\", \"models\":[ \"320\", \"X3\", \"X5\" ] }, \n  { \"name\":\"Fiat\", \"models\":[ \"500\", \"Panda\" ] }\n ]\n}";

  for (int i = strlen(json) - 1; i >= 0; i--) {
    push(&parser, json[i]);
  }

  parse(&parser);

  JsonObject *root = &parser.objectStack[0];

  for (int i = 0; i < root->length; i++) {
    printf("%s: %s\n", root->nodes[i].key, root->nodes[i].value);

    if (strcmp(root->nodes[i].key, "cars") == 0) {
      for (int j = 0; j < root->nodes[i].type; j++) {
        printf("Car %d:\n", j + 1);
        JsonArray *car = &parser.arrayStack[j];
        for (int k = 0; k < car->length; k++) {
          printf("\t%s: %s\n", car->nodes[k].key, car->nodes[k].value);
          if (strcmp(car->nodes[k].key, "models") == 0) {
            for (int l = 0; l < car->nodes[k].type; l++) {
              printf("\t\t%s\n", car->nodes[k].value + l * strlen(car->nodes[k].value) / car->nodes[k].type);
            }
          }
        }
      }
    }
  }

  return 0;
}