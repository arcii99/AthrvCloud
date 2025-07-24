//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    JSON_STRING,
    JSON_NUMBER,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NULL,
    JSON_OBJECT_OPEN,
    JSON_OBJECT_CLOSE,
    JSON_ARRAY_OPEN,
    JSON_ARRAY_CLOSE,
    JSON_COLON,
    JSON_COMMA,
    JSON_ERROR
} json_type;

typedef struct {
    json_type type;
    char *value;
} json_token;

json_token *get_next_token(char *json_string, int *position) {

    // skip any white space
    while (json_string[*position] == ' ' || json_string[*position] == '\n' || json_string[*position] == '\r' || json_string[*position] == '\t') {
        (*position)++;
    }

    // check for end of string
    if (json_string[*position] == '\0') {
        return NULL;
    }

    // check for null value
    if (json_string[*position] == 'n' && json_string[*position+1] == 'u' && json_string[*position+2] == 'l' && json_string[*position+3] == 'l') {
        char *value = malloc(sizeof(char) * 5);
        strncpy(value, "null", 4);
        value[4] = '\0';
        (*position) += 4;

        json_token *token = malloc(sizeof(json_token));
        token->type = JSON_NULL;
        token->value = value;
        return token;
    }

    // check for true value
    if (json_string[*position] == 't' && json_string[*position+1] == 'r' && json_string[*position+2] == 'u' && json_string[*position+3] == 'e') {
        char *value = malloc(sizeof(char) * 5);
        strncpy(value, "true", 4);
        value[4] = '\0';
        (*position) += 4;

        json_token *token = malloc(sizeof(json_token));
        token->type = JSON_TRUE;
        token->value = value;
        return token;
    }

    // check for false value
    if (json_string[*position] == 'f' && json_string[*position+1] == 'a' && json_string[*position+2] == 'l' && json_string[*position+3] == 's' && json_string[*position+4] == 'e') {
        char *value = malloc(sizeof(char) * 6);
        strncpy(value, "false", 5);
        value[5] = '\0';
        (*position) += 5;

        json_token *token = malloc(sizeof(json_token));
        token->type = JSON_FALSE;
        token->value = value;
        return token;
    }

    // check for string value
    if (json_string[*position] == '\"') {
        (*position)++;
        int start = *position;
        while (json_string[*position] != '\"') {
            (*position)++;
        }
        int end = *position;
        (*position)++;

        char *value = malloc(sizeof(char) * (end - start + 1));
        strncpy(value, &json_string[start], end - start);
        value[end - start] = '\0';

        json_token *token = malloc(sizeof(json_token));
        token->type = JSON_STRING;
        token->value = value;
        return token;
    }

    // check for number value
    if ((json_string[*position] >= '0' && json_string[*position] <= '9') || json_string[*position] == '-') {
        int start = *position;
        while ((json_string[*position] >= '0' && json_string[*position] <= '9') || json_string[*position] == '.' || json_string[*position] == '+' || json_string[*position] == '-') {
            (*position)++;
        }
        int end = *position;

        char *value = malloc(sizeof(char) * (end - start + 1));
        strncpy(value, &json_string[start], end - start);
        value[end - start] = '\0';

        json_token *token = malloc(sizeof(json_token));
        token->type = JSON_NUMBER;
        token->value = value;
        return token;
    }

    // check for colon
    if (json_string[*position] == ':') {
        (*position)++;
        json_token *token = malloc(sizeof(json_token));
        token->type = JSON_COLON;
        token->value = NULL;
        return token;
    }

    // check for comma
    if (json_string[*position] == ',') {
        (*position)++;
        json_token *token = malloc(sizeof(json_token));
        token->type = JSON_COMMA;
        token->value = NULL;
        return token;
    }

    // check for array open
    if (json_string[*position] == '[') {
        (*position)++;
        json_token *token = malloc(sizeof(json_token));
        token->type = JSON_ARRAY_OPEN;
        token->value = NULL;
        return token;
    }

    // check for array close
    if (json_string[*position] == ']') {
        (*position)++;
        json_token *token = malloc(sizeof(json_token));
        token->type = JSON_ARRAY_CLOSE;
        token->value = NULL;
        return token;
    }

    // check for object open
    if (json_string[*position] == '{') {
        (*position)++;
        json_token *token = malloc(sizeof(json_token));
        token->type = JSON_OBJECT_OPEN;
        token->value = NULL;
        return token;
    }

    // check for object close
    if (json_string[*position] == '}') {
        (*position)++;
        json_token *token = malloc(sizeof(json_token));
        token->type = JSON_OBJECT_CLOSE;
        token->value = NULL;
        return token;
    }

    // set error token
    char *value = malloc(sizeof(char) * 2);
    strncpy(value, " ", 1);
    value[1] = '\0';

    json_token *token = malloc(sizeof(json_token));
    token->type = JSON_ERROR;
    token->value = value;
    return token;
}

void parse_json_object(char *json_string, int *position) {
    json_token *token = get_next_token(json_string, position);
    if (token == NULL || token->type == JSON_ERROR) {
        printf("Invalid JSON syntax\n");
        exit(0);
    } else if (token->type == JSON_OBJECT_CLOSE) {
        return;
    }

    printf("{ ");
    while (1) {
        free(token);
        token = get_next_token(json_string, position);

        if (token == NULL || token->type == JSON_ERROR) {
            printf("Invalid JSON syntax\n");
            exit(0);
        } else if (token->type == JSON_OBJECT_CLOSE) {
            printf(" }\n");
            return;
        } else if (token->type != JSON_STRING) {
            printf("Invalid JSON syntax\n");
            exit(0);
        }

        printf("%s: ", token->value);

        free(token);
        token = get_next_token(json_string, position);

        if (token == NULL || token->type == JSON_ERROR) {
            printf("Invalid JSON syntax\n");
            exit(0);
        } else if (token->type == JSON_OBJECT_OPEN) {
            parse_json_object(json_string, position);
        } else if (token->type == JSON_ARRAY_OPEN) {
            parse_json_array(json_string, position);
        } else if (token->type != JSON_STRING && token->type != JSON_NUMBER && token->type != JSON_TRUE && token->type != JSON_FALSE && token->type != JSON_NULL) {
            printf("Invalid JSON syntax\n");
            exit(0);
        } else {
            printf("%s", token->value);
        }

        free(token);
        token = get_next_token(json_string, position);

        if (token == NULL || token->type == JSON_ERROR) {
            printf("Invalid JSON syntax\n");
            exit(0);
        } else if (token->type == JSON_OBJECT_CLOSE) {
            printf(" }\n");
            return;
        } else if (token->type != JSON_COMMA) {
            printf("Invalid JSON syntax\n");
            exit(0);
        }

        printf(", ");
    }
}

void parse_json_array(char *json_string, int *position) {
    json_token *token = get_next_token(json_string, position);
    if (token == NULL || token->type == JSON_ERROR) {
        printf("Invalid JSON syntax\n");
        exit(0);
    } else if (token->type == JSON_ARRAY_CLOSE) {
        return;
    }

    printf("[ ");
    while (1) {
        if (token->type == JSON_OBJECT_OPEN) {
            parse_json_object(json_string, position);
        } else if (token->type == JSON_ARRAY_OPEN) {
            parse_json_array(json_string, position);
        } else if (token->type != JSON_STRING && token->type != JSON_NUMBER && token->type != JSON_TRUE && token->type != JSON_FALSE && token->type != JSON_NULL) {
            printf("Invalid JSON syntax\n");
            exit(0);
        } else {
            printf("%s", token->value);
        }

        free(token);
        token = get_next_token(json_string, position);

        if (token == NULL || token->type == JSON_ERROR) {
            printf("Invalid JSON syntax\n");
            exit(0);
        } else if (token->type == JSON_ARRAY_CLOSE) {
            printf(" ]\n");
            return;
        } else if (token->type != JSON_COMMA) {
            printf("Invalid JSON syntax\n");
            exit(0);
        }

        printf(", ");
        free(token);
        token = get_next_token(json_string, position);
    }
}

void parse_json(char *json_string) {
    int position = 0;
    json_token *token = get_next_token(json_string, &position);

    if (token->type == JSON_OBJECT_OPEN) {
        parse_json_object(json_string, &position);
    } else if (token->type == JSON_ARRAY_OPEN) {
        parse_json_array(json_string, &position);
    } else {
        printf("Invalid JSON syntax\n");
    }

    free(token);
}

int main() {

    char *json_string = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";
    printf("Parsing: %s\n", json_string);
    parse_json(json_string);

    json_string = "[{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}, {\"name\":\"Jane\",\"age\":25,\"city\":\"Boston\"}]";
    printf("Parsing: %s\n", json_string);
    parse_json(json_string);

    json_string = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\",\"pets\":[{\"name\":\"Rufus\",\"type\":\"dog\"},{\"name\":\"Fluffy\",\"type\":\"cat\"}]}";
    printf("Parsing: %s\n", json_string);
    parse_json(json_string);

    return 0;
}