//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_JSON_LEN 1000

typedef enum {
    JSON_STRING,
    JSON_NUMBER,
    JSON_OBJECT_START,
    JSON_OBJECT_END,
    JSON_ARRAY_START,
    JSON_ARRAY_END,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NULL
} JSONType;

typedef struct {
    JSONType type;
    char value[MAX_JSON_LEN];
} JSONToken;

typedef struct {
    char key[MAX_JSON_LEN];
    JSONToken value;
} JSONObject;

typedef struct {
    JSONToken* tokens;
    int num_tokens;
} JSON;

JSON parse_json(char* json_string) {
    JSON result = { .tokens = NULL, .num_tokens = -1 };

    if (json_string == NULL) {
        printf("Empty JSON string\n");
        return result;
    }

    JSONToken* tokens = malloc(sizeof(JSONToken));
    int num_tokens = 0;

    int i = 0;
    while (json_string[i] != '\0') {
        if (isspace(json_string[i])) {
            i++;
            continue;
        }

        if (json_string[i] == '{') {
            tokens[num_tokens].type = JSON_OBJECT_START;
            strcpy(tokens[num_tokens].value, "{");
            num_tokens++;
        } else if (json_string[i] == '}') {
            tokens[num_tokens].type = JSON_OBJECT_END;
            strcpy(tokens[num_tokens].value, "}");
            num_tokens++;
        } else if (json_string[i] == '[') {
            tokens[num_tokens].type = JSON_ARRAY_START;
            strcpy(tokens[num_tokens].value, "[");
            num_tokens++;
        } else if (json_string[i] == ']') {
            tokens[num_tokens].type = JSON_ARRAY_END;
            strcpy(tokens[num_tokens].value, "]");
            num_tokens++;
        } else if (json_string[i] == ':') {
            tokens[num_tokens-1].type = JSON_STRING;
        } else if (json_string[i] == ',' || json_string[i] == ' ') {
            i++;
            continue;
        } else if (json_string[i] == '\"') {
            int j = i + 1;
            while (json_string[j] != '\"') {
                j++;
            }
            strncpy(tokens[num_tokens].value, json_string+i+1, j-i-1);
            tokens[num_tokens].type = JSON_STRING;
            num_tokens++;
            i = j + 1;
            continue;
        } else if (isdigit(json_string[i])) {
            int j = i + 1;
            while (isdigit(json_string[j])) {
                j++;
            }
            strncpy(tokens[num_tokens].value, json_string+i, j-i);
            tokens[num_tokens].type = JSON_NUMBER;
            num_tokens++;
            i = j;
            continue;
        } else if (strncmp(json_string+i, "true", 4) == 0) {
            tokens[num_tokens].type = JSON_TRUE;
            strncpy(tokens[num_tokens].value, "true", 4);
            num_tokens++;
            i = i + 4;
            continue;
        } else if (strncmp(json_string+i, "false", 5) == 0) {
            tokens[num_tokens].type = JSON_FALSE;
            strncpy(tokens[num_tokens].value, "false", 5);
            num_tokens++;
            i = i + 5;
            continue;
        } else if (strncmp(json_string+i, "null", 4) == 0) {
            tokens[num_tokens].type = JSON_NULL;
            strncpy(tokens[num_tokens].value, "null", 4);
            num_tokens++;
            i = i + 4;
            continue;
        } else {
            printf("Invalid JSON syntax: unexpected character %c at position %d\n", json_string[i], i+1);
            free(tokens);
            return result;
        }

        i++;
        tokens = realloc(tokens, (num_tokens+1) * sizeof(JSONToken));
    }

    if (tokens[num_tokens-1].type != JSON_OBJECT_END && tokens[num_tokens-1].type != JSON_ARRAY_END) {
        printf("Invalid JSON syntax: expected } or ] at end of JSON, got %s\n", tokens[num_tokens-1].value);
        free(tokens);
        return result;
    }

    result.tokens = tokens;
    result.num_tokens = num_tokens;

    return result;
}

void print_json_token(JSONToken token) {
    switch (token.type) {
        case JSON_STRING:
            printf("\"%s\"", token.value);
            break;
        case JSON_NUMBER:
            printf("%s", token.value);
            break;
        case JSON_OBJECT_START:
            printf("{");
            break;
        case JSON_OBJECT_END:
            printf("}");
            break;
        case JSON_ARRAY_START:
            printf("[");
            break;
        case JSON_ARRAY_END:
            printf("]");
            break;
        case JSON_TRUE:
            printf("true");
            break;
        case JSON_FALSE:
            printf("false");
            break;
        case JSON_NULL:
            printf("null");
            break;
    }
}

void print_json(JSONObject json) {
    printf("\"%s\": ", json.key);
    print_json_token(json.value);
}

int main() {
    char* json_string = "{ \"name\": \"Alice\", \"age\": 30, \"friends\": [\"Bob\", \"Charlie\"], \"address\": { \"city\": \"London\", \"country\": \"UK\" }}";
    JSON json = parse_json(json_string);

    if (json.num_tokens == -1) {
        printf("Error parsing JSON\n");
        return 1;
    }

    printf("Parsed JSON:\n");

    JSONObject current_object;
    int level = 0;
    for (int i = 0; i < json.num_tokens; i++) {
        if (json.tokens[i].type == JSON_OBJECT_START || json.tokens[i].type == JSON_ARRAY_START) {
            level++;
        } else if (json.tokens[i].type == JSON_OBJECT_END || json.tokens[i].type == JSON_ARRAY_END) {
            level--;
        } else if (json.tokens[i].type == JSON_STRING) {
            if (level == 1) {
                strcpy(current_object.key, json.tokens[i].value);
            }
        } else {
            current_object.value = json.tokens[i];
            if (level == 1) {
                print_json(current_object);
                printf("\n");
            }
        }
    }

    return 0;
}