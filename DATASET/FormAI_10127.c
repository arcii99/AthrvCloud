//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_STR_LEN 1000

typedef struct {
    char key[50];
    char value[50];
} KeyValue;

typedef struct {
    KeyValue *pairs;
    int num_pairs;
} JSON;

JSON* parse_json(char *json_str);
char* get_value_from_key(JSON *json_obj, char *key);

int main() {
    char json_str[MAX_JSON_STR_LEN] = "{\"name\":\"John Smith\",\"age\":30,\"city\":\"New York\"}";

    JSON *json_obj = parse_json(json_str);

    // Get value of "name" key
    char *name = get_value_from_key(json_obj, "name");
    printf("Name: %s\n", name);

    // Get value of "age" key
    char *age = get_value_from_key(json_obj, "age");
    printf("Age: %s\n", age);

    // Get value of "city" key
    char *city = get_value_from_key(json_obj, "city");
    printf("City: %s\n", city);

    free(json_obj->pairs);
    free(json_obj);
    return 0;
}

JSON* parse_json(char *json_str) {
    int num_pairs = 0, i = 0;
    KeyValue *pairs = NULL;

    // Remove all whitespace characters from the string
    char *ptr = json_str;
    while (*ptr != '\0') {
        if (*ptr == ' ' || *ptr == '\n' || *ptr == '\r' || *ptr == '\t') {
            memmove(ptr, ptr+1, strlen(ptr));
        } 
        else {
            ptr++;
        }
    }

    // Remove curly braces from the ends
    if (json_str[0] == '{') {
        memmove(json_str, json_str+1, strlen(json_str));
    }
    if (json_str[strlen(json_str)-1] == '}') {
        json_str[strlen(json_str)-1] = '\0';
    }

    // Split into key-value pairs
    char* temp;
    char* pair = strtok_r(json_str, ",", &temp);
    while (pair != NULL) {
        KeyValue kv;
        char *kv_temp;
        char *key = strtok_r(pair, ":", &kv_temp);
        if (key != NULL) {
            if (key[0] == '\"' && key[strlen(key)-1] == '\"') {
                key++;
                key[strlen(key)-1] = '\0';
            }
            strcpy(kv.key, key);
        }
        char *val = strtok_r(NULL, "", &kv_temp);
        if (val != NULL) {
            if (val[0] == '\"' && val[strlen(val)-1] == '\"') {
                val++;
                val[strlen(val)-1] = '\0';
            }
            strcpy(kv.value, val);
        }
        num_pairs++;
        pairs = (KeyValue*)realloc(pairs, sizeof(KeyValue)*num_pairs);
        pairs[num_pairs-1] = kv;
        pair = strtok_r(NULL, ",", &temp);
    }

    JSON *json = (JSON*)malloc(sizeof(JSON));
    json->pairs = pairs;
    json->num_pairs = num_pairs;
    return json;
}

char* get_value_from_key(JSON *json_obj, char *key) {
    for (int i = 0; i < json_obj->num_pairs; i++) {
        if (strcmp(json_obj->pairs[i].key, key) == 0) {
            return json_obj->pairs[i].value;
        }
    }
    return NULL;
}