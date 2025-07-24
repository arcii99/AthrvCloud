//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  JSMN_OBJECT,
  JSMN_ARRAY,
  JSMN_STRING,
  JSMN_PRIMITIVE
} jsmntype_t;

typedef struct {
  jsmntype_t type;
  int start;
  int end;
  int size;
} jsmntok_t;

typedef struct {
  jsmntok_t* tokens;
  int num_tokens;
} jsmn_parser_t;

#define JSON_STRING_TEST "{\"name\": \"John Smith\", \"age\": 40, \"isMarried\": true, \"salary\": 120000.50, \"pets\": [\"dog\", \"cat\"]}"
#define JSMN_NUM_TOKENS 128

int jsmn_parse(jsmn_parser_t* parser, const char* json, size_t len) {
  jsmntok_t* tokens = parser->tokens;
  int num_tokens = 0;
  int i, j;

  /* Count number of tokens required */
  for (i = 0; i < len; i++) {
    switch (json[i]) {
      case '{':
      case '[':
        num_tokens++;
        break;
      case '}':
      case ']':
        num_tokens++;
        break;
      case '"':
        num_tokens++;
        for (i++; json[i] != '"' && i < len; i++);
        break;
      default:
        if (json[i] == '-' || (json[i] >= '0' && json[i] <= '9')) {
          num_tokens++;
          for (i++; json[i] >= '0' && json[i] <= '9'; i++);
          if (json[i] == '.') {
            num_tokens++;
            for (i++; json[i] >= '0' && json[i] <= '9'; i++);
          }
          i--;
        } else if (json[i] == 't' || json[i] == 'f' || json[i] == 'n') {
          num_tokens++;
          for (j = i+1; json[j] >= 'a' && json[j] <= 'z'; j++);
          if (strncmp(json+i, "true", 4) == 0 || strncmp(json+i, "null", 4) == 0) {
            i += 3;
          } else {
            i += 4;
          }
        }
        break;
    }
  }

  /* Allocate tokens */
  tokens = (jsmntok_t*) calloc(num_tokens, sizeof(jsmntok_t));
  if (tokens == NULL) {
    return -1;
  }
  parser->tokens = tokens;
  parser->num_tokens = num_tokens;

  /* Populate tokens */
  num_tokens = 0;
  for (i = 0; i < len; i++) {
    switch (json[i]) {
      case '{':
        tokens[num_tokens].type = JSMN_OBJECT;
        tokens[num_tokens].start = i;
        num_tokens++;
        break;
      case '}':
        tokens[num_tokens].type = JSMN_OBJECT;
        tokens[num_tokens].end = i+1;
        num_tokens++;
        break;
      case '[':
        tokens[num_tokens].type = JSMN_ARRAY;
        tokens[num_tokens].start = i;
        num_tokens++;
        break;
      case ']':
        tokens[num_tokens].type = JSMN_ARRAY;
        tokens[num_tokens].end = i+1;
        num_tokens++;
        break;
      case '"':
        tokens[num_tokens].type = JSMN_STRING;
        tokens[num_tokens].start = i+1;
        for (i++; json[i] != '"' && i < len; i++);
        tokens[num_tokens].end = i;
        num_tokens++;
        break;
      default:
        if (json[i] == '-' || (json[i] >= '0' && json[i] <= '9')) {
          tokens[num_tokens].type = JSMN_PRIMITIVE;
          tokens[num_tokens].start = i;
          for (i++; json[i] >= '0' && json[i] <= '9'; i++);
          if (json[i] == '.') {
            i++;
            for (; json[i] >= '0' && json[i] <= '9'; i++);
          }
          tokens[num_tokens].end = i;
          num_tokens++;
          i--;
        } else if (json[i] == 't' || json[i] == 'f' || json[i] == 'n') {
          tokens[num_tokens].type = JSMN_PRIMITIVE;
          tokens[num_tokens].start = i;
          for (j = i+1; json[j] >= 'a' && json[j] <= 'z'; j++);
          if (strncmp(json+i, "true", 4) == 0 || strncmp(json+i, "null", 4) == 0) {
            tokens[num_tokens].end = i+4;
            i += 3;
          } else {
            tokens[num_tokens].end = i+5;
            i += 4;
          }
          num_tokens++;
        }
        break;
    }
  }

  return 0;
}

int main() {
  const char* json = JSON_STRING_TEST;
  jsmn_parser_t parser;
  int i;
  
  jsmn_parse(&parser, json, strlen(json));
  
  printf("Number of tokens: %d\n", parser.num_tokens);
  for (i = 0; i < parser.num_tokens; i++) {
    switch (parser.tokens[i].type) {
      case JSMN_OBJECT:
        printf("%d: Object {start: %d, end: %d, size: %d}\n", i, parser.tokens[i].start, parser.tokens[i].end, parser.tokens[i].size);
        break;
      case JSMN_ARRAY:
        printf("%d: Array {start: %d, end: %d, size: %d}\n", i, parser.tokens[i].start, parser.tokens[i].end, parser.tokens[i].size);
        break;
      case JSMN_STRING:
        printf("%d: String {start: %d, end: %d}\n", i, parser.tokens[i].start, parser.tokens[i].end);
        break;
      case JSMN_PRIMITIVE:
        printf("%d: Primitive {start: %d, end: %d}\n", i, parser.tokens[i].start, parser.tokens[i].end);
        break;
    }
  }
  
  free(parser.tokens);
  
  return 0;
}