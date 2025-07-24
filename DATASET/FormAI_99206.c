//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { T_STRING, T_NUMBER, T_TRUE, T_FALSE, T_NULL, T_OBJECT_START, T_OBJECT_END,
               T_ARRAY_START, T_ARRAY_END, T_COLON, T_COMMA, T_EOF } token_type;

typedef struct {
    token_type type;
    const char *start;
    int length;
    int line;
} token;

typedef struct {
    char *json;
    int position;
    int line;
} parser;

static void parse_value(parser *p);
static void parse_object(parser *p);
static void parse_array(parser *p);
static token get_token(parser *p);
static void parse_error(parser *p, const char *message);
static void expect(parser *p, token_type expected_type);
static int match(parser *p, token_type expected_type);

void print_token(token t) {
    printf("Token type: %d, start: %.*s, length: %d, line: %d\n", t.type, t.length, t.start, t.length, t.line);
}

void print_json(const char *json) {
    parser p = { json, 0, 1 };
    token t;

    while ((t = get_token(&p)).type != T_EOF) {
        print_token(t);
    }
}

token get_token(parser *p) {
    token t = { T_EOF, p->json + p->position, 0, p->line };

    while (*p->json) {
        switch (*p->json) {
            case '{':
                t.type = T_OBJECT_START;
                t.length = 1;
                p->position++;
                return t;
            case '}':
                t.type = T_OBJECT_END;
                t.length = 1;
                p->position++;
                return t;
            case '[':
                t.type = T_ARRAY_START;
                t.length = 1;
                p->position++;
                return t;
            case ']':
                t.type = T_ARRAY_END;
                t.length = 1;
                p->position++;
                return t;
            case ':':
                t.type = T_COLON;
                t.length = 1;
                p->position++;
                return t;
            case ',':
                t.type = T_COMMA;
                t.length = 1;
                p->position++;
                return t;
            case '"': {
                const char *start = ++p->json;
                while (*p->json && *p->json != '"') {
                    // Handle escape sequences
                    if (*p->json == '\\') p->json++;
                    p->json++;
                }
                if (*p->json != '"') {
                    parse_error(p, "Unterminated string");
                }
                t.type = T_STRING;
                t.start = start;
                t.length = p->json - start;
                p->json++;
                return t;
            }
            case 't': {
                const char *start = p->json;
                if (!match(p, T_TRUE)) {
                    parse_error(p, "Invalid token");
                }
                t.type = T_TRUE;
                t.start = start;
                t.length = 4;
                return t;
            }
            case 'f': {
                const char *start = p->json;
                if (!match(p, T_FALSE)) {
                    parse_error(p, "Invalid token");
                }
                t.type = T_FALSE;
                t.start = start;
                t.length = 5;
                return t;
            }
            case 'n': {
                const char *start = p->json;
                if (!match(p, T_NULL)) {
                    parse_error(p, "Invalid token");
                }
                t.type = T_NULL;
                t.start = start;
                t.length = 4;
                return t;
            }
            default: {
                if (*p->json >= '0' && *p->json <= '9') {
                    const char *start = p->json;
                    while (*p->json && *p->json >= '0' && *p->json <= '9') {
                        p->json++;
                    }
                    // Allow for fractional part
                    if (*p->json == '.') {
                        p->json++;
                        while (*p->json && *p->json >= '0' && *p->json <= '9') {
                            p->json++;
                        }
                    }
                    t.type = T_NUMBER;
                    t.start = start;
                    t.length = p->json - start;
                    return t;
                }
                else if (*p->json <= ' ') {  // Ignore whitespace
                    if (*p->json == '\n') {
                        p->line++;
                    }
                    p->json++;
                }
                else {
                    parse_error(p, "Invalid token");
                }
                break;
            }
        }
    }

    return t;
}

static void parse_error(parser *p, const char *message) {
    printf("Parse error on line %d: %s\n", p->line, message);
    exit(1);
}

static void parse_value(parser *p) {
    token t = get_token(p);

    switch (t.type) {
        case T_STRING:
            printf("Found string: %.*s\n", t.length, t.start);
            break;
        case T_NUMBER:
            printf("Found number: %.*s\n", t.length, t.start);
            break;
        case T_TRUE:
            printf("Found boolean: true\n");
            break;
        case T_FALSE:
            printf("Found boolean: false\n");
            break;
        case T_NULL:
            printf("Found null value\n");
            break;
        case T_OBJECT_START:
            printf("Found object start\n");
            parse_object(p);
            break;
        case T_ARRAY_START:
            printf("Found array start\n");
            parse_array(p);
            break;
        default:
            parse_error(p, "Unexpected token");
            break;
    }
}

static void parse_object(parser *p) {
    while (1) {
        token t = get_token(p);

        switch (t.type) {
            case T_OBJECT_END:
                printf("Found object end\n");
                return;
            case T_STRING:
                printf("Found object key: %.*s\n", t.length, t.start);
                expect(p, T_COLON);
                parse_value(p);
                if (get_token(p).type != T_COMMA) {
                    if (match(p, T_OBJECT_END)) {
                        printf("Found object end\n");
                        return;
                    }
                    parse_error(p, "Expected comma or object end");
                }
                break;
            default:
                parse_error(p, "Unexpected token");
        }
    }
}

static void parse_array(parser *p) {
    while (1) {
        token t = get_token(p);

        switch (t.type) {
            case T_ARRAY_END:
                printf("Found array end\n");
                return;
            default:
                parse_value(p);
                if (get_token(p).type != T_COMMA) {
                    if (match(p, T_ARRAY_END)) {
                        printf("Found array end\n");
                        return;
                    }
                    parse_error(p, "Expected comma or array end");
                }
                break;
        }
    }
}

static void expect(parser *p, token_type expected_type) {
    token t = get_token(p);
    if (t.type != expected_type) {
        parse_error(p, "Unexpected token");
    }
}

static int match(parser *p, token_type expected_type) {
    token t = get_token(p);
    if (t.type == expected_type) {
        return 1;
    }
    p->position -= t.length;
    return 0;
}

int main(int argc, char *argv[]) {
    const char *json_str = "{\"name\": \"John Doe\", \"age\": 35, \"isStudent\": false, \"grades\": [90, 85, 95]}";
    printf("Parsing JSON\n");
    print_json(json_str);
    return 0;
}