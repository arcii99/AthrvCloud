//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    JSMN_UNDEFINED = 0,
    JSMN_OBJECT = 1,
    JSMN_ARRAY = 2,
    JSMN_STRING = 3,
    JSMN_PRIMITIVE = 4
} jsmntype_t;

typedef struct {
    jsmntype_t type;
    int start;
    int end;
    int size;
} jsmntok_t;

typedef struct {
    const char *json;
    size_t toknext;
    size_t toksuper;
    jsmntok_t *tokens;
} jsmn_parser;

int jsmn_parse_primitive(jsmn_parser *parser, const char *js, size_t len, jsmntok_t *token) {
    size_t start = parser->toknext;
    for (; start < len && js[start] != '\0'; start++) {
        switch (js[start]) {
            case ' ':
            case '\n':
            case '\r':
            case '\t':
            case ',':
            case ']':
            case '}':
                goto found;
        }
    }
    return -1;

found:
    token->type = JSMN_PRIMITIVE;
    token->start = start;
    token->end = start;
    token->size = 0;
    parser->toknext = start;
    return 0;
}

int jsmn_parse_string(jsmn_parser *parser, const char *js, size_t len, jsmntok_t *token) {
    size_t start = parser->toknext;
    token->type = JSMN_STRING;
    for (; parser->toknext < len && js[parser->toknext] != '\0'; parser->toknext++) {
        char c = js[parser->toknext];
        if (c == '\"') {
            token->start = start + 1;
            token->end = parser->toknext;
            parser->toknext++;
            token->size = 0;
            return 0;
        }

        if (c == '\\' && (parser->toknext + 1) < len) {
            parser->toknext++;
            switch (js[parser->toknext]) {
                case '\"':
                case '/':
                case '\\':
                case 'b':
                case 'f':
                case 'r':
                case 'n':
                case 't':
                    break;
                case 'u':
                    if ((parser->toknext + 4) < len) {
                        /* TODO validate unicode */
                        parser->toknext += 4;
                        break;
                    }
                    return -2;

                default:
                    return -3;
            }
        }
    }
    return -1;
}

int jsmn_parse_array(jsmn_parser *parser, const char *js, size_t len, jsmntok_t *token) {
    size_t start = parser->toknext;
    int count = 0;
    token->type = JSMN_ARRAY;
    parser->toknext++;

    for (; parser->toknext < len && js[parser->toknext] != '\0'; parser->toknext++) {
        switch (js[parser->toknext]) {
            case '\"':
                jsmn_parse_string(parser, js, len, &parser->tokens[parser->toknext++]);
                count++;
                break;
            case ']':
                token->start = start;
                token->end = parser->toknext+1;
                token->size = count;
                return 0;
            case ',':
                break;

            default:
                return -1;
        }
    }
    return -2;
}

int jsmn_parse_object(jsmn_parser *parser, const char *js, size_t len, jsmntok_t *token) {
    size_t start = parser->toknext;
    int count = 0;
    token->type = JSMN_OBJECT;
    parser->toknext++;

    for (; parser->toknext < len && js[parser->toknext] != '\0'; parser->toknext++) {
        switch (js[parser->toknext]) {
            case '\"':
                jsmn_parse_string(parser, js, len, &parser->tokens[parser->toknext++]);
                count++;
                break;

            case ':':
                break;

            case ',':
                break;

            case '}':
                token->start = start;
                token->end = parser->toknext+1;
                token->size = count;
                return 0;

            default:
                return -1;
        }
    }
    return -2;
}

int jsmn_parse(const char *js, size_t len, jsmntok_t *tokens, unsigned int num_tokens) {
    jsmn_parser parser;
    int r;
    size_t i;
    jsmntok_t *token;

    parser.json = js;
    parser.toknext = 0;
    parser.toksuper = -1;

    for (; parser.toknext < len && js[parser.toknext] != '\0'; parser.toknext++) {
        char c;
        jsmntype_t type;

        c = js[parser.toknext];
        switch (c) {
            case '{':
            case '[':
                parser.toksuper++;
                tokens[parser.toksuper].type = (c == '{' ? JSMN_OBJECT : JSMN_ARRAY);
                tokens[parser.toksuper].start = parser.toknext;
                break;

            case '}':
            case ']':
                token = &tokens[parser.toksuper];
                token->end = parser.toknext + 1;

                if (parser.toksuper > 0) {
                    tokens[parser.toksuper - 1].size++;
                }

                parser.toksuper--;
                break;

            case '\"':
                jsmn_parse_string(&parser, js, len, &tokens[parser.toksuper]);
                if (parser.toksuper > 0) {
                    tokens[parser.toksuper - 1].size++;
                }
                break;

            case '\t':
            case '\r':
            case '\n':
            case ' ':
                break;

            case ':':
                tokens[parser.toksuper].type = JSMN_STRING;
                break;

            case ',':
                if (tokens[parser.toksuper].type == JSMN_OBJECT ||
                    tokens[parser.toksuper].type == JSMN_ARRAY) {
                    break;
                }

            default:
                if (parser.toksuper == -1) {
                    break;
                }

                token = &tokens[parser.toksuper];
                if (token->type == JSMN_OBJECT &&
                    token->size % 2 == 0) {
                    token->type = JSMN_STRING;
                    token->start = parser.toknext;
                    r = jsmn_parse_string(&parser, js, len, &tokens[++parser.toksuper]);
                    if (r < 0) {
                        return r;
                    }
                    token = &tokens[parser.toksuper - 1];
                }

                if (token->type == JSMN_STRING) {
                    r = jsmn_parse_primitive(&parser, js, len, &tokens[++parser.toksuper]);
                    if (r < 0) {
                        return r;
                    }

                    token = &tokens[parser.toksuper - 1];
                    token->end = parser.toknext + 1;
                    token->size++;
                }
                break;
        }
    }

    token = &tokens[0];
    if (token->type == JSMN_ARRAY || token->type == JSMN_OBJECT) {
        return -4;
    }

    for (i = 1; i < num_tokens; i++) {
        if (tokens[i].start == -1) {
            break;
        }
    }

    return (int)i;
}

int main() {
    char json[] = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";
    jsmntok_t tokens[1024];
    jsmn_parse(json, strlen(json), tokens, sizeof(tokens)/sizeof(tokens[0]));

    int i;
    for (i = 0; tokens[i].start < strlen(json); i++) {
        printf("Token[%d]: type=%d, start=%d, end=%d, size=%d\n",
                i, tokens[i].type, tokens[i].start, tokens[i].end, tokens[i].size);
    }

    return 0;
}