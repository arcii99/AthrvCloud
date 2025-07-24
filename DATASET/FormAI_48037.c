//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <string.h>

#define MAX_LEN 1000

typedef struct {
    char* json_str;
    int len;
} ParsedData;

// Helper function to parse json object
ParsedData parse_json_object(char* json_str, int start_index){
    ParsedData data;
    int len = strlen(json_str);
    int index = start_index;
    char key[MAX_LEN], value[MAX_LEN];
    bool is_key = true;
    while (index < len){
        char curr_char = json_str[index];
        if (curr_char == '}'){
            break;
        } else if (curr_char == '\"'){
            if (is_key){
                int i = 0;
                while (json_str[index + 1 + i] != '\"'){
                    key[i] = json_str[index + 1 + i];
                    i++;
                }
                key[i] = '\0';
            } else {
                int i = 0;
                while (json_str[index + 1 + i] != '\"'){
                    value[i] = json_str[index + 1 + i];
                    i++;
                }
                value[i] = '\0';
                printf("%s : %s\n", key, value);
            }
            is_key = !is_key;
        }
        index++;
    }
    data.len = index - start_index + 1;
    data.json_str = (char*) malloc((index - start_index + 1) * sizeof(char));
    strncpy(data.json_str, json_str + start_index, index - start_index + 1);
    return data;
}

// Thread function to parse json objects
void* parse_json_objects(void* json_str){
    char* str = (char*) json_str;
    int len = strlen(str);
    int i = 0;
    while (i < len){
        if (str[i] == '{'){
            ParsedData data = parse_json_object(str, i);
            printf("Parsed JSON Object: %s\n", data.json_str);
            i += data.len;
            free(data.json_str);
        } else {
            i++;
        }
    }
    pthread_exit(NULL);
}

int main() {
    char* json_str = "{ \"name\": \"John\", \"age\": 30 }{ \"name\": \"Jane\", \"age\": 40 }";
    pthread_t thread;
    pthread_create(&thread, NULL, parse_json_objects, (void*) json_str);
    pthread_join(thread, NULL);
    return 0;
}