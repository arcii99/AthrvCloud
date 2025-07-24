//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING 255

typedef enum {
  TK_LSQBRACKET,  // '['
  TK_RSQBRACKET,  // ']'
  TK_LCPAREN,     // '{'
  TK_RCPAREN,     // '}'
  TK_COLON,       // ':'
  TK_COMMA,       // ','
  TK_STRING,      // ""
  TK_NUMBER,      // numbers
  TK_TRUE,
  TK_FALSE,
  TK_NULL,
  TK_ERROR,
} token_t;

typedef struct {
  token_t kind;
  union {
    char string[MAX_STRING + 1];
    double number;
  } val;
} json_token;

typedef struct {
  char *json;
  char *p;
  size_t len;
} json_parser;

json_token parse(json_parser *parser);
json_token parse_object(json_parser *parser);
json_token parse_array(json_parser *parser);
json_token parse_value(json_parser *parser);

json_token parse(json_parser *parser) {
  json_token token = {0};

  while (*parser->p != '\0') {
    if (isspace(*parser->p)) {
      parser->p++;
      continue;
    }

    switch (*parser->p) {
      case '{':
        token.kind = TK_LCPAREN;
        return token;

      case '}':
        token.kind = TK_RCPAREN;
        return token;

      case '[':
        token.kind = TK_LSQBRACKET;
        return token;

      case ']':
        token.kind = TK_RSQBRACKET;
        return token;

      case ',':
        token.kind = TK_COMMA;
        parser->p++;
        return token;

      case ':':
        token.kind = TK_COLON;
        parser->p++;
        return token;

      case '\"':
        token = parse_value(parser);
        return token;

      case 't':
        token.kind = TK_TRUE;
        parser->p += 4;
        return token;

      case 'f':
        token.kind = TK_FALSE;
        parser->p += 5;
        return token;

      case 'n':
        token.kind = TK_NULL;
        parser->p += 4;
        return token;

      default:
        if (isdigit(*parser->p) || *parser->p == '-') {
          token = parse_value(parser);
          return token;
        }
        token.kind = TK_ERROR;
        return token;
    }
  }

  return token;
}

json_token parse_object(json_parser *parser) {
  json_token token = {0};

  while (*parser->p != '\0') {
    token = parse(parser);

    if (token.kind == TK_RCPAREN) {
      return token;
    } else if (token.kind != TK_STRING) {
      return (json_token){TK_ERROR};
    }

    printf("Found key: %s\n", token.val.string);

    token = parse(parser);

    if (token.kind != TK_COLON) {
      return (json_token){TK_ERROR};
    }

    printf("Expecting value for key: %s\n", parser->p);

    token = parse(parser);

    if (token.kind == TK_ERROR) {
      return token;
    }
  }

  return token;
}

json_token parse_array(json_parser *parser) {
  json_token token = {0};

  while (*parser->p != '\0') {
    token = parse(parser);

    if (token.kind == TK_RSQBRACKET) {
      return token;
    } else if (token.kind == TK_ERROR) {
      return token;
    }
  }

  return token;
}

json_token parse_value(json_parser *parser) {
  json_token token = {0};
  int i = 0, num_dots = 0;

  if (*parser->p == '\"') {
    token.kind = TK_STRING;
    parser->p++;

    while (*parser->p != '\"' && i < MAX_STRING) {
      token.val.string[i++] = *(parser->p++);
    }

    if (*parser->p != '\"') {
      token.kind = TK_ERROR;
    }

    token.val.string[i] = '\0';

    parser->p++;
  } else if (isdigit(*parser->p) || *parser->p == '-') {
    token.kind = TK_NUMBER;

    while (isdigit(*parser->p) || *parser->p == '.' || *parser->p == 'e' || *parser->p == '-') {
      if (num_dots > 1) {
        token.kind = TK_ERROR;
        return token;
      } else if (*parser->p == '.') {
        num_dots++;
      }

      token.val.string[i++] = *(parser->p++);
    }

    token.val.string[i] = '\0';

    if (num_dots == 0) {
      token.val.number = atoi(token.val.string);
    } else {
      token.val.number = atof(token.val.string);
    }
  }

  return token;
}

int main(int argc, char **argv) {
  char *json = "{\"name\": \"John\", \"age\": 23, \"is_active\": true}";

  json_parser parser = {.json = json, .p = json, .len = strlen(json)};
  json_token token = {0};

  token = parse(&parser);

  if (token.kind == TK_LCPAREN) {
    token = parse_object(&parser);
  }

  return 0;
}