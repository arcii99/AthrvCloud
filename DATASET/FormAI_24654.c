//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the JSON object structure */
typedef enum {
    JSON_OBJ_STRING,
    JSON_OBJ_NUMBER,
    JSON_OBJ_BOOLEAN,
    JSON_OBJ_NULL,
    JSON_OBJ_ARRAY,
    JSON_OBJ_OBJECT
} json_type_t;

typedef struct json_object {
    json_type_t type;
    char *key;
    void *value;
    int num_children;
    struct json_object **children;
} json_object_t;

/* Define the parse function */
json_object_t *parse(char *json);

/* Define helper functions */
char *get_value_between(char *json, char start, char end);
void strip_quotes(char *str);
int count_children(char *json);
json_object_t **parse_children(char *json, int num_children);
void print_json_object(json_object_t *obj);

/* Implement the parse function */
json_object_t *parse(char *json) {
    int len = strlen(json);
    if (len < 2) {
        return NULL;
    }
    json_object_t *obj = (json_object_t*) malloc(sizeof(json_object_t));
    obj->children = NULL;
    obj->num_children = 0;

    /* Determine the type of the JSON object */
    if (json[0] == '{' && json[len-1] == '}') {
        obj->type = JSON_OBJ_OBJECT;
    } else if (json[0] == '[' && json[len-1] == ']') {
        obj->type = JSON_OBJ_ARRAY;
    } else if (json[0] == '"' && json[len-1] == '"') {
        obj->type = JSON_OBJ_STRING;
        /* Strip the quotes from the string */
        strip_quotes(json);
        obj->value = (void*) strdup(json);
    } else if (!strncmp(json, "true", 4)) {
        obj->type = JSON_OBJ_BOOLEAN;
        obj->value = (void*) (long long) 1;
    } else if (!strncmp(json, "false", 5)) {
        obj->type = JSON_OBJ_BOOLEAN;
        obj->value = (void*) (long long) 0;
    } else if (!strncmp(json, "null", 4)) {
        obj->type = JSON_OBJ_NULL;
    } else {
        obj->type = JSON_OBJ_NUMBER;
        obj->value = (void*) (long long) strtol(json, NULL, 10);
    }

    /* Parse the children if the object is an array or object */
    if (obj->type == JSON_OBJ_ARRAY || obj->type == JSON_OBJ_OBJECT) {
        obj->num_children = count_children(json);
        if (obj->num_children > 0) {
            obj->children = parse_children(json, obj->num_children);
        }
    }

    return obj;
}

/* Implement helper functions */
char *get_value_between(char *json, char start, char end) {
    int i = 1;
    int j = 0;
    while (json[i] != '\0' && json[i] != end) {
        if (json[i] == start) {
            /* Skip nested values */
            int nested = 1;
            i++;
            while (nested > 0 && json[i] != '\0') {
                if (json[i] == start) { nested++; }
                if (json[i] == end) { nested--; }
                i++;
            }
        }
        j++;
        i++;
    }
    if (j == 0) {
        return NULL;
    }
    char *value = (char*) malloc((j+1) * sizeof(char));
    strncpy(value, json+1, j);
    value[j] = '\0';
    return value;
}

void strip_quotes(char *str) {
    int len = strlen(str)-1;
    if (str[0] == '"' && str[len] == '"') {
        memmove(str, str+1, len);
        str[len-1] = '\0';
    }
}

int count_children(char *json) {
    int count = 0;
    int nested = 0;
    int i = 0;
    while (json[i] != '\0') {
        if (json[i] == ':') {
            /* Skip the value */
            int j = i+1;
            while (json[j] != '\0' && json[j] != ',' && json[j] != '}' && json[j] != ']') {
                if (json[j] == '{' || json[j] == '[') { nested++; }
                if (json[j] == '}' || json[j] == ']') { nested--; }
                j++;
            }
            count++;
        } else if (json[i] == ',') {
            if (nested == 0) {
                count++;
            }
        } else if (json[i] == '{' || json[i] == '[') {
            nested++;
        } else if (json[i] == '}' || json[i] == ']') {
            nested--;
        }
        i++;
    }
    return count;
}

json_object_t **parse_children(char *json, int num_children) {
    json_object_t **children = (json_object_t**) malloc(num_children * sizeof(json_object_t*));
    int i = 0;
    int nested = 0;
    int j = 0;
    while (json[i] != '\0') {
        if (json[i] == ':') {
            /* Get the key */
            char *key = get_value_between(json+i, '"', '"');
            children[j]->key = key;
            /* Get the value */
            int k = i+1;
            int n = 1;
            int len;
            while (n > 0 && json[k] != '\0') {
                if (json[k] == '[' || json[k] == '{') { n++; }
                if (json[k] == ']' || json[k] == '}') { n--; }
                k++;
            }
            len = k-i-1;
            char *value = (char*) malloc((len+1) * sizeof(char));
            strncpy(value, json+i+1, len);
            value[len-1] = '\0';
            /* Parse the value */
            children[j]->value = (void*) parse(value);
            /* Increment the counter */
            j++;
        }
        if (json[i] == ',' && nested == 0) {
            children[j] = (json_object_t*) malloc(sizeof(json_object_t));
            children[j]->children = NULL;
            children[j]->num_children = 0;
        } else if (json[i] == '{' || json[i] == '[') {
            nested++;
        } else if (json[i] == '}' || json[i] == ']') {
            nested--;
        }
        i++;
    }
    return children;
}

void print_json_object(json_object_t *obj) {
    if (obj == NULL) {
        printf("NULL\n");
        return;
    }
    switch (obj->type) {
        case JSON_OBJ_STRING:
            printf("\"%s\"\n", (char*) obj->value);
            break;
        case JSON_OBJ_NUMBER:
            printf("%lld\n", (long long) obj->value);
            break;
        case JSON_OBJ_BOOLEAN:
            printf("%s\n", (int) obj->value ? "true" : "false");
            break;
        case JSON_OBJ_NULL:
            printf("null\n");
            break;
        case JSON_OBJ_ARRAY:
            printf("[");
            for (int i = 0; i < obj->num_children; i++) {
                print_json_object(obj->children[i]);
                if (i < obj->num_children-1) {
                    printf(",");
                }
            }
            printf("]\n");
            break;
        case JSON_OBJ_OBJECT:
            printf("{");
            for (int i = 0; i < obj->num_children; i++) {
                printf("\"%s\":", obj->children[i]->key);
                print_json_object(obj->children[i]->value);
                if (i < obj->num_children-1) {
                    printf(",");
                }
            }
            printf("}\n");
            break;
        default:
            printf("Unknown JSON object type\n");
            break;
    }
}

/* Example usage */
int main(void) {
    char *json_string = "{\"firstName\": \"John\",\"lastName\": \"Doe\",\"age\": 25,\"address\": {\"streetAddress\": \"100 Random Street\",\"city\": \"Anytown\",\"state\": \"NY\"},\"phoneNumbers\": [ {\"type\": \"home\",\"number\": \"123-456-7890\"},{\"type\": \"mobile\",\"number\": \"456-789-1234\"} ]}";
    json_object_t *json_obj = parse(json_string);
    print_json_object(json_obj);
    return 0;
}