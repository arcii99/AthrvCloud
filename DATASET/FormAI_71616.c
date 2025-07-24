//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct json_object {
    enum { JSON_NULL, JSON_BOOL, JSON_NUMBER, JSON_STRING, JSON_ARRAY, JSON_OBJECT } type;
    union {
        int boolean;
        double number;
        char *string;
        struct json_object **array;
        struct json_object **object;
    } value;
};

struct json_token {
    enum { JSON_TOKEN_INVALID, JSON_TOKEN_NULL, JSON_TOKEN_BOOL, JSON_TOKEN_NUMBER, JSON_TOKEN_STRING, JSON_TOKEN_COLON, JSON_TOKEN_COMMA, JSON_TOKEN_LEFT_BRACKET, JSON_TOKEN_RIGHT_BRACKET, JSON_TOKEN_LEFT_BRACE, JSON_TOKEN_RIGHT_BRACE } type;
    char *value;
};

int is_whitespace(char c) {
    return c == ' ' || c == '\t' || c == '\r' || c == '\n';
}

char *load_file(char *filename) {
    FILE *fp = fopen(filename, "r");

    if (!fp) {
        printf("Unable to open file %s", filename);
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *buffer = malloc(fileSize);
    fread(buffer, 1, fileSize, fp);

    fclose(fp);

    return buffer;
}

struct json_token *next_token(char **json) {
    struct json_token *token = malloc(sizeof(struct json_token));
    token->type = JSON_TOKEN_INVALID;
    token->value = NULL;

    while (**json) {
        if (is_whitespace(**json)) {
            (*json)++;
            continue;
        }

        if (**json == ':') {
            (*json)++;
            token->type = JSON_TOKEN_COLON;
            return token;
        }

        if (**json == ',') {
            (*json)++;
            token->type = JSON_TOKEN_COMMA;
            return token;
        }

        if (**json == '[') {
            (*json)++;
            token->type = JSON_TOKEN_LEFT_BRACKET;
            return token;
        }

        if (**json == ']') {
            (*json)++;
            token->type = JSON_TOKEN_RIGHT_BRACKET;
            return token;
        }

        if (**json == '{') {
            (*json)++;
            token->type = JSON_TOKEN_LEFT_BRACE;
            return token;
        }

        if (**json == '}') {
            (*json)++;
            token->type = JSON_TOKEN_RIGHT_BRACE;
            return token;
        }

        if (**json == 'n' && strncmp(*json, "null", 4) == 0) {
            (*json) += 4;
            token->type = JSON_TOKEN_NULL;
            return token;
        }

        if (**json == 't' && strncmp(*json, "true", 4) == 0) {
            (*json) += 4;
            token->type = JSON_TOKEN_BOOL;
            token->value = "true";
            return token;
        }

        if (**json == 'f' && strncmp(*json, "false", 5) == 0) {
            (*json) += 5;
            token->type = JSON_TOKEN_BOOL;
            token->value = "false";
            return token;
        }

        if (**json == '\"') {
            (*json)++;
            int length = 0;
            char *start = *json;

            while (**json && **json != '\"') {
                (*json)++;
                length++;
            }

            if (**json) {
                (*json)++;
                token->type = JSON_TOKEN_STRING;
                token->value = malloc(length);
                strncpy(token->value, start, length);
                token->value[length] = '\0';
                return token;
            }
        }

        if (**json >= '0' && **json <= '9') {
            int length = 0;
            char *start = *json;

            while (**json >= '0' && **json <= '9') {
                (*json)++;
                length++;
            }

            if (**json == '.') {
                (*json)++;
                length++;

                while (**json >= '0' && **json <= '9') {
                    (*json)++;
                    length++;
                }
            }

            token->type = JSON_TOKEN_NUMBER;
            token->value = malloc(length);
            strncpy(token->value, start, length);
            token->value[length] = '\0';
            return token;
        }

        break;
    }

    free(token);
    return NULL;
}

struct json_object *parse_value(char **json);

struct json_object *parse_array(char **json) {
    struct json_object **array = malloc(sizeof(struct json_object *));
    int size = 0;

    (*json)++;
    while (**json) {
        if (is_whitespace(**json)) {
            (*json)++;
            continue;
        }

        if (**json == ']') {
            (*json)++;
            break;
        }

        if (size > 0) {
            struct json_token *comma = next_token(json);
            if (!comma || comma->type != JSON_TOKEN_COMMA) {
                printf("Expected comma in array\n");
                exit(1);
            }
        }

        array = realloc(array, sizeof(struct json_object *) * ++size);
        array[size-1] = parse_value(json);
    }

    struct json_object *obj = malloc(sizeof(struct json_object));
    obj->type = JSON_ARRAY;
    obj->value.array = array;

    return obj;
}

struct json_object *parse_object(char **json) {
    struct json_object **object = malloc(sizeof(struct json_object *));
    int size = 0;

    (*json)++;
    while (**json) {
        if (is_whitespace(**json)) {
            (*json)++;
            continue;
        }

        if (**json == '}') {
            (*json)++;
            break;
        }

        if (size > 0) {
            struct json_token *comma = next_token(json);
            if (!comma || comma->type != JSON_TOKEN_COMMA) {
                printf("Expected comma in object\n");
                exit(1);
            }
        }

        struct json_token *name = next_token(json);
        if (!name || name->type != JSON_TOKEN_STRING) {
            printf("Expected string as key in object\n");
            exit(1);
        }

        if (!next_token(json) || next_token(json)->type != JSON_TOKEN_COLON) {
            printf("Expected colon in object\n");
            exit(1);
        }

        object = realloc(object, sizeof(struct json_object *) * ++size);
        object[size-1] = malloc(sizeof(struct json_object));
        object[size-1]->type = JSON_STRING;
        object[size-1]->value.string = name->value;

        struct json_object *value = parse_value(json);
        object = realloc(object, sizeof(struct json_object *) * ++size);
        object[size-1] = value;

        free(name);
    }

    struct json_object *obj = malloc(sizeof(struct json_object));
    obj->type = JSON_OBJECT;
    obj->value.object = object;

    return obj;
}

struct json_object *parse_value(char **json) {
    struct json_token *token = next_token(json);

    if (!token) {
        printf("Unexpected end of JSON data\n");
        exit(1);
    }

    if (token->type == JSON_TOKEN_NULL) {
        struct json_object *obj = malloc(sizeof(struct json_object));
        obj->type = JSON_NULL;
        return obj;
    }

    if (token->type == JSON_TOKEN_BOOL) {
        struct json_object *obj = malloc(sizeof(struct json_object));
        obj->type = JSON_BOOL;
        obj->value.boolean = strcmp(token->value, "true") == 0;
        return obj;
    }

    if (token->type == JSON_TOKEN_NUMBER) {
        struct json_object *obj = malloc(sizeof(struct json_object));
        obj->type = JSON_NUMBER;
        obj->value.number = atof(token->value);
        return obj;
    }

    if (token->type == JSON_TOKEN_STRING) {
        struct json_object *obj = malloc(sizeof(struct json_object));
        obj->type = JSON_STRING;
        obj->value.string = token->value;
        return obj;
    }

    if (token->type == JSON_TOKEN_LEFT_BRACKET) {
        return parse_array(json);
    }

    if (token->type == JSON_TOKEN_LEFT_BRACE) {
        return parse_object(json);
    }

    printf("Invalid token in JSON data\n");
    exit(1);
}

struct json_object *parse_json(char *data) {
    char **json = &data;
    return parse_value(json);
}

void print_object(struct json_object *obj, int indent) {
    int i, j;

    switch (obj->type) {
        case JSON_NULL:
            printf("null");
            break;
        case JSON_BOOL:
            printf("%s", obj->value.boolean ? "true" : "false");
            break;
        case JSON_NUMBER:
            printf("%f", obj->value.number);
            break;
        case JSON_STRING:
            printf("\"%s\"", obj->value.string);
            break;
        case JSON_ARRAY:
            printf("[\n");
            for (i = 0; i < sizeof(obj->value.array)/sizeof(obj->value.array[0]); i++) {
                for (j = 0; j <= indent; j++)
                    printf("\t");
                print_object(obj->value.array[i], indent + 1);
                if (i < sizeof(obj->value.array)/sizeof(obj->value.array[0]) - 1)
                    printf(",");
                printf("\n");
            }
            for (j = 0; j < indent; j++)
                printf("\t");
            printf("]");
            break;
        case JSON_OBJECT:
            printf("{\n");
            for (i = 0; i < sizeof(obj->value.object)/sizeof(obj->value.object[0]); i++) {
                for (j = 0; j <= indent; j++)
                    printf("\t");
                printf("\"%s\": ", obj->value.object[i]->value.string);
                print_object(obj->value.object[i + 1], indent + 1);
                if (i < sizeof(obj->value.object)/sizeof(obj->value.object[0]) - 2)
                    printf(",");
                printf("\n");
                i++;
            }
            for (j = 0; j < indent; j++)
                printf("\t");
            printf("}");
            break;
    }
}

int main() {
    char *json_data = load_file("example.json");
    if (!json_data) {
        return 1;
    }

    struct json_object *obj = parse_json(json_data);
    free(json_data);

    if (!obj) {
        return 1;
    }

    print_object(obj, 0);

    return 0;
}