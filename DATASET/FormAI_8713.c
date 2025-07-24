//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

typedef enum {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_BOOLEAN,
    JSON_NULL
} json_type;

typedef struct {
    json_type type;
    void *data;
} json_value;

typedef struct {
    char *key;
    json_value value;
} json_pair;

typedef struct {
    size_t size;
    json_pair *pairs;
} json_object;

typedef struct {
    size_t size;
    json_value *elements;
} json_array;

json_value parse_value(char *json);

json_object parse_object(char *json) {
    json_object obj;
    obj.size = 0;
    obj.pairs = NULL;

    // remove surrounding braces
    json++;
    json[strlen(json)-1] = '\0';

    // iterate over object
    char *token, *key, *value;
    token = strtok(json, ",");
    while (token != NULL) {
        // split key-value pair
        key = strtok(token, ":");
        value = strtok(NULL, ":");

        // parse key
        key++;
        key[strlen(key)-1] = '\0';

        // create pair
        json_pair pair;
        pair.key = strdup(key);
        pair.value = parse_value(value);

        // add pair to object
        obj.size++;
        obj.pairs = realloc(obj.pairs, obj.size * sizeof(json_pair));
        obj.pairs[obj.size-1] = pair;

        // get next token
        token = strtok(NULL, ",");
    }

    return obj;
}

json_array parse_array(char *json) {
    json_array arr;
    arr.size = 0;
    arr.elements = NULL;

    // remove surrounding brackets
    json++;
    json[strlen(json)-1] = '\0';

    // iterate over array
    char *token;
    token = strtok(json, ",");
    while (token != NULL) {
        // parse value
        json_value val = parse_value(token);

        // add value to array
        arr.size++;
        arr.elements = realloc(arr.elements, arr.size * sizeof(json_value));
        arr.elements[arr.size-1] = val;

        // get next token
        token = strtok(NULL, ",");
    }

    return arr;
}

json_value parse_value(char *json) {
    // check for string
    if (json[0] == '"') {
        json_value val;
        val.type = JSON_STRING;

        // remove surrounding quotes
        json++;
        json[strlen(json)-1] = '\0';

        // store string
        char *str = strdup(json);
        val.data = str;
        return val;
    }

    // check for number
    if (isdigit(json[0]) || json[0] == '-') {
        json_value val;
        val.type = JSON_NUMBER;

        // store number
        double *num = malloc(sizeof(double));
        *num = strtod(json, NULL);
        val.data = num;
        return val;
    }

    // check for boolean
    if (strcmp(json, "true") == 0 || strcmp(json, "false") == 0) {
        json_value val;
        val.type = JSON_BOOLEAN;

        // store boolean
        int *bl = malloc(sizeof(int));
        *bl = (strcmp(json, "true") == 0);
        val.data = bl;
        return val;
    }

    // check for null
    if (strcmp(json, "null") == 0) {
        json_value val;
        val.type = JSON_NULL;
        val.data = NULL;
        return val;
    }

    // check for object
    if (json[0] == '{') {
        json_value val;
        val.type = JSON_OBJECT;

        // parse object
        json_object obj = parse_object(json);
        val.data = &obj;
        return val;
    }

    // check for array
    if (json[0] == '[') {
        json_value val;
        val.type = JSON_ARRAY;

        // parse array
        json_array arr = parse_array(json);
        val.data = &arr;
        return val;
    }

    // error
    fprintf(stderr, "Error: invalid JSON value\n");
    exit(1);
}

int main(void) {
    // test parsing
    char *json = "{\"name\":\"John\", \"age\":42, \"addresses\":[{\"city\":\"New York\", \"state\":\"NY\"}, {\"city\":\"Los Angeles\", \"state\":\"CA\"}]}";
    json_value val = parse_value(json);
    json_object obj = *((json_object*)val.data);

    printf("Name: %s\n", (char*)obj.pairs[0].value.data);
    printf("Age: %lf\n", *((double*)obj.pairs[1].value.data));
    json_array arr = *((json_array*)obj.pairs[2].value.data);
    printf("Addresses:\n");
    for (int i = 0; i < arr.size; i++) {
        json_object obj = *((json_object*)arr.elements[i].data);
        printf("  Address %d: %s, %s\n", i+1, (char*)obj.pairs[0].value.data, (char*)obj.pairs[1].value.data);
    }

    // free memory
    free(val.data);
    for (int i = 0; i < obj.size; i++) {
        free(obj.pairs[i].key);
        free(obj.pairs[i].value.data);
    }
    free(obj.pairs);
    for (int i = 0; i < arr.size; i++) {
        free(arr.elements[i].data);
    }
    free(arr.elements);

    return 0;
}