//FormAI DATASET v1.0 Category: Syntax parsing ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define Token Types */
typedef enum {
  TOK_EOF,
  TOK_IDENT,
  TOK_NUMBER,
  TOK_STRING,
  TOK_PLUS,
  TOK_MINUS,
  TOK_STAR,
  TOK_SLASH,
  TOK_LPAREN,
  TOK_RPAREN,
  TOK_SEMI,
  TOK_ASSIGN,
  TOK_LT,
  TOK_GT,
  TOK_EQ,
  TOK_NEQ,
  TOK_LEQ,
  TOK_GEQ
} TokenType;

/*
 * Define Token structure:
 * type: TokenType
 * value: char* (string or number)
 */
typedef struct {
  TokenType type;
  char* value;
} Token;

/* Define Parser structure */
typedef struct {
  Token token;
  char* input;
} Parser;

/* Forward declarations to satisfy C compiler */
void error(char* msg);
Parser parser_new(char* input);
void parser_advance(Parser* parser);
void parser_eat(Parser* parser, TokenType type);
int parser_parse_number(Parser* parser);
char* parser_parse_identifier(Parser* parser);
char* parser_parse_string(Parser* parser);
void parser_reset_token(Parser* parser, TokenType type, char* value);
void parser_reset(Parser* parser, Token token, char* input);
void parser_parse_expression(Parser* parser);

/*
 * Error function to report errors.
 */
void error(char* msg) {
  printf("Error: %s\n", msg);
  exit(1);
}

/*
 * Create and return a new Parser with the given input.
 */
Parser parser_new(char* input) {
  Parser parser;
  parser.input = input;
  parser_advance(&parser);
  return parser;
}

/*
 * Advance to the next Token and set it in the Parser.
 */
void parser_advance(Parser* parser) {
  char current_char = parser->input[0];
  if (current_char == '\0') {
    parser_reset_token(parser, TOK_EOF, "");
    return;
  }
  
  /* Numerical token */
  if (isdigit(current_char)) {
    int number = parser_parse_number(parser);
    char buf[32];
    snprintf(buf, 32, "%d", number); /* convert int to string */
    parser_reset_token(parser, TOK_NUMBER, strdup(buf));
    return;
  }
  
  /* Identifier token */
  if (isalpha(current_char)) {
    char* identifier = parser_parse_identifier(parser);
    parser_reset_token(parser, TOK_IDENT, identifier);
    return;
  }
  
  /* String token */
  if (current_char == '\"') {
    char* string = parser_parse_string(parser);
    parser_reset_token(parser, TOK_STRING, string);
    return;
  }
  
  /* Other single-character token */
  switch (current_char) {
    case '+':
      parser_reset_token(parser, TOK_PLUS, "+");
      break;
    case '-':
      parser_reset_token(parser, TOK_MINUS, "-");
      break;
    case '*':
      parser_reset_token(parser, TOK_STAR, "*");
      break;
    case '/':
      parser_reset_token(parser, TOK_SLASH, "/");
      break;
    case '(':
      parser_reset_token(parser, TOK_LPAREN, "(");
      break;
    case ')':
      parser_reset_token(parser, TOK_RPAREN, ")");
      break;
    case ';':
      parser_reset_token(parser, TOK_SEMI, ";");
      break;
    case '<':
      if (parser->input[1] == '=') {
        parser->input++;
        parser_reset_token(parser, TOK_LEQ, "<=");
      } else {
        parser_reset_token(parser, TOK_LT, "<");
      }
      break;
    case '>':
      if (parser->input[1] == '=') {
        parser->input++;
        parser_reset_token(parser, TOK_GEQ, ">=");
      } else {
        parser_reset_token(parser, TOK_GT, ">");
      }
      break;
    case '=':
      if (parser->input[1] == '=') {
        parser->input++;
        parser_reset_token(parser, TOK_EQ, "==");
      } else {
        parser_reset_token(parser, TOK_ASSIGN, "=");
      }
      break;
    case '!':
      if (parser->input[1] == '=') {
        parser->input++;
        parser_reset_token(parser, TOK_NEQ, "!=");
      }
      break;
    default:
      error("Invalid character");
  }
  
  parser->input++;
}

/*
 * Verify that the current token is of the expected type,
 * then advance to the next token.
 */
void parser_eat(Parser* parser, TokenType type) {
  if (parser->token.type == type) {
    parser_advance(parser);
  } else {
    printf("Unexpected token '%s'. Expected '%d'\n", parser->token.value, type);
    exit(1);
  }
}

/*
 * Parse a number starting at the current position of the parser.
 * Return the resulting integer.
 */
int parser_parse_number(Parser* parser) {
  int number = 0;
  while (isdigit(parser->input[0])) {
    number = number * 10 + (parser->input[0] - '0');
    parser->input++;
  }
  return number;
}

/*
 * Parse an identifier starting at the current position of the parser.
 * Return the resulting string.
 */
char* parser_parse_identifier(Parser* parser) {
  char* identifier = calloc(1, sizeof(char));
  int i = 0;
  while (isalpha(parser->input[0])) {
    identifier = realloc(identifier, (i + 2) * sizeof(char));
    identifier[i++] = parser->input[0];
    parser->input++;
  }
  return identifier;
}

/*
 * Parse a string starting at the current position of the parser.
 * Return the resulting string.
 */
char* parser_parse_string(Parser* parser) {
  char* string = calloc(1, sizeof(char));
  int i = 0;
  parser->input++; /* skip the opening quote */
  while (parser->input[0] != '\"') {
    string = realloc(string, (i + 2) * sizeof(char));
    string[i++] = parser->input[0];
    parser->input++;
  }
  parser->input++; /* skip the closing quote */
  return string;
}

/*
 * Reset the token in the given parser to the given values.
 */
void parser_reset_token(Parser* parser, TokenType type, char* value) {
  if (parser->token.value) free(parser->token.value);
  parser->token.type = type;
  parser->token.value = value;
}

/*
 * Reset the given parser to the given token and input string.
 */
void parser_reset(Parser* parser, Token token, char* input) {
  parser->token = token;
  parser->input = input;
}

/*
 * Parse an expression starting at the current position of the parser.
 */
void parser_parse_expression(Parser* parser) {
  /* TODO: Implement this */
}

int main(int argc, char** argv) {
  /* TODO: Implement a test program */
  return 0;
}