//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold parsed JSON data
typedef struct {
    char* name;
    char* value;
} json_data;

// Function to parse JSON object
json_data* parse_json(const char* json_obj) {
    int obj_size = strlen(json_obj);
    int len = 0, data_len = 0;

    // Allocate memory for holding parsed JSON data
    json_data* data = (json_data*)malloc(sizeof(json_data) * obj_size);

    // Iterate through the JSON object
    for (int i = 0; i < obj_size; i++) {
        if (json_obj[i] == '\"') {
            i++;

            // Get the name of the data
            char* name = (char*)malloc(sizeof(char) * obj_size);
            len = 0;
            while (json_obj[i] != '\"') {
                name[len++] = json_obj[i++];
            }
            name[len] = '\0';

            i++;

            // Get the value of the data
            char* value = (char*)malloc(sizeof(char) * obj_size);
            data_len = 0;
            while (json_obj[i] != '\"') {
                value[data_len++] = json_obj[i++];
            }
            value[data_len] = '\0';

            // Store the parsed data in the structure
            data[len] = (json_data){name, value};
        }
    }

    return data;
}

int main() {
    // Example JSON object
    const char* json_obj = "{\"name\": \"John\", \"age\": 30, \"city\": \"New York\"}";

    // Parse the JSON object
    json_data* data = parse_json(json_obj);

    // Print the parsed data
    for (int i = 0; i < strlen(json_obj); i++) {
        if (json_obj[i] == '\"') {
            printf("%s: %s\n", data[i].name, data[i].value);
        }
    }

    // Free the allocated memory
    free(data);

    return 0;
}