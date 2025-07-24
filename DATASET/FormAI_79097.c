//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the input JSON string
#define MAX_SIZE 1000

struct json_obj {
    char key[50];
    char value[50];
} json_dict[50];

// Define a function to parse the input JSON string
void json_parser(char *input_string) {

    char key[50], value[50];
    int key_flag = 0, value_flag = 0, object_start_flag = 0, object_end_flag = 0, i, j = 0;

    // Loop through the input string
    for (i = 0; input_string[i] != '\0'; i++) {
        if (input_string[i] == '\"' && key_flag == 0 && object_start_flag == 0) {
            key_flag = 1;
            continue;
        }
        if (input_string[i] == '\"' && key_flag == 1 && value_flag == 0 && object_start_flag == 0) {
            key_flag = 0;
            value_flag = 1;
            continue;
        }
        if (input_string[i] == '\"' && key_flag == 0 && value_flag == 1 && object_start_flag == 0) {
            value_flag = 0;
            continue;
        }
        if (input_string[i] == '{') {
            object_start_flag = 1;
            continue;
        }
        if (input_string[i] == '}') {
            object_end_flag = 1;
        }
        if (object_start_flag == 1 && object_end_flag == 0) {
            if (input_string[i] == '\"' && key_flag == 0) {
                key_flag = 1;
                continue;
            }
            if (input_string[i] == '\"' && key_flag == 1 && value_flag == 0) {
                key_flag = 0;
                value_flag = 1;
                continue;
            }
            if (input_string[i] == '\"' && key_flag == 0 && value_flag == 1) {
                value_flag = 0;
                strcpy(json_dict[j].key, key);
                strcpy(json_dict[j].value, value);
                memset(key, 0, sizeof(key));
                memset(value, 0, sizeof(value));
                j++;
                continue;
            }
            if (key_flag == 1 && value_flag == 0) {
                strncat(key, &input_string[i], 1);
                continue;
            }
            if (key_flag == 0 && value_flag == 1) {
                strncat(value, &input_string[i], 1);
                continue;
            }
        }
    }
}

int main() {

    char input[MAX_SIZE];
    printf("Enter the JSON string to be parsed: ");
    scanf("%[^\n]%*c", input);

    json_parser(input);

    printf("\nParsed JSON object:\n");
    for (int i = 0; *json_dict[i].key != '\0'; i++) {
        printf("%s : %s\n", json_dict[i].key, json_dict[i].value);
    }

    return 0;
}