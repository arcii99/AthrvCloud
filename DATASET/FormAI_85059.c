//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    OBJECT,
    ARRAY,
    STRING,
    NUMBER,
    BOOLEAN,
    NULL_VALUE
} json_type;

typedef struct {
    json_type type;
    void* value;
} json_data;

void parse_json(char* json, json_data* data);

int main(int argc, char** argv) {
    char* json = "{\"name\": \"John\", \"age\": 30, \"city\": \"New York\"}";

    json_data data;
    parse_json(json, &data);

    printf("Name: %s\n", (char*)data.value);
    printf("Age: %d\n", *((int*)data.value + 1));
    printf("City: %s\n", (char*)data.value + 12);

    free(data.value);

    return 0;
}

void parse_json(char* json, json_data* data) {
    int len = strlen(json);
    int i = 0;

    // Check if the json is an object
    if (json[i] == '{' && json[len - 1] == '}') {
        data->type = OBJECT;
        data->value = malloc(sizeof(json_data) * 3);

        int j = 1;
        int k = 0;
        while (j < len - 1) {
            // Find key
            char* key = (char*)malloc(sizeof(char) * 100);
            int l = 0;
            while (json[j] != ':' && json[j] != '}') {
                key[l++] = json[j++];
            }
            key[l] = '\0';

            j++;
            // Find value
            json_data* value = (json_data*)malloc(sizeof(json_data));
            if (json[j] == '{' && json[len - 1] == '}') {
                value->type = OBJECT;
                parse_json(json + j, value);
                j = j + strlen(json + j);
            } else if (json[j] == '[' && json[len - 1] == ']') {
                value->type = ARRAY;
                parse_json(json + j, value);
                j = j + strlen(json + j);
            } else if (json[j] == '\"') {
                value->type = STRING;
                value->value = (void*)malloc(sizeof(char) * 100);
                l = 0;
                j++;
                while (json[j] != '\"' && json[j] != '\0') {
                    ((char*)value->value)[l++] = json[j++];
                }
                ((char*)value->value)[l] = '\0';
                j++;
            } else if (json[j] == 't' || json[j] == 'f') {
                value->type = BOOLEAN;
                value->value = (void*)malloc(sizeof(int));
                *((int*)value->value) = json[j] == 't' ? 1 : 0;
                j = j + 4;
            } else if (json[j] == 'n') {
                value->type = NULL_VALUE;
                value->value = NULL;
                j = j + 4;
            } else {
                value->type = NUMBER;
                value->value = (void*)malloc(sizeof(int));
                sscanf(json + j, "%d", (int*)value->value);
                j = j + strlen((char*)value->value);
            }

            ((json_data*)(data->value))[k].type = value->type;
            ((json_data*)(data->value))[k].value = value->value;
            k++;

            if (json[j] == ',') j++;
            free(key);
        }
    } else if (json[i] == '[' && json[len - 1] == ']') {
        data->type = ARRAY;
        data->value = malloc(sizeof(json_data) * 3);

        int j = 1;
        int k = 0;
        while (j < len - 1) {
            json_data* value = (json_data*)malloc(sizeof(json_data));
            if (json[j] == '{' && json[len - 1] == '}') {
                value->type = OBJECT;
                parse_json(json + j, value);
                j = j + strlen(json + j);
            } else if (json[j] == '[' && json[len - 1] == ']') {
                value->type = ARRAY;
                parse_json(json + j, value);
                j = j + strlen(json + j);
            } else if (json[j] == '\"') {
                value->type = STRING;
                value->value = (void*)malloc(sizeof(char) * 100);
                int l = 0;
                j++;
                while (json[j] != '\"' && json[j] != '\0') {
                    ((char*)value->value)[l++] = json[j++];
                }
                ((char*)value->value)[l] = '\0';
                j++;
            } else if (json[j] == 't' || json[j] == 'f') {
                value->type = BOOLEAN;
                value->value = (void*)malloc(sizeof(int));
                *((int*)value->value) = json[j] == 't' ? 1 : 0;
                j = j + 4;
            } else if (json[j] == 'n') {
                value->type = NULL_VALUE;
                value->value = NULL;
                j = j + 4;
            } else {
                value->type = NUMBER;
                value->value = (void*)malloc(sizeof(int));
                sscanf(json + j, "%d", (int*)value->value);
                j = j + strlen((char*)value->value);
            }

            ((json_data*)(data->value))[k].type = value->type;
            ((json_data*)(data->value))[k].value = value->value;
            k++;

            if (json[j] == ',') j++;
        }
    } 
}