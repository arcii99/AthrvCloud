//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

/* Utility function to check if a character is a whitespace character */
int is_whitespace(char c)
{
    return (c == ' ' || c == '\n' || c == '\r' || c == '\t');
}

/* Utility struct to store parsed JSON data */
typedef struct {
    char* name;
    char* value;
} json_data;

/* Utility function to create a new json_data struct */
json_data* create_json_data(char* name, char* value)
{
    json_data* data = (json_data*) malloc(sizeof(json_data));
    data->name = strdup(name);
    data->value = strdup(value);
    return data;
}

/* Utility function to free a previously created json_data struct */
void free_json_data(json_data* data)
{
    free(data->name);
    free(data->value);
    free(data);
}

/* Main function to parse a JSON string */
int parse_json(char* json_str, json_data** data_list)
{
    int num_data = 0;
    int i = 0;
    int len = strlen(json_str);
    char buffer[BUFFER_SIZE];
    
    /* Skip any leading whitespace */
    while (i < len && is_whitespace(json_str[i])) {
        i++;
    }

    /* Parse each name-value pair */
    while (i < len && json_str[i] != '}') {
        char name[BUFFER_SIZE];
        char value[BUFFER_SIZE];
        int name_len = 0;
        int value_len = 0;

        /* Skip over the opening quote for the name */
        i++;

        /* Parse the name */
        while (i < len && json_str[i] != '\"') {
            name[name_len++] = json_str[i++];
        }

        /* Skip over the closing quote for the name */
        i++;

        /* Skip over any whitespace between the name and the colon */
        while (i < len && is_whitespace(json_str[i])) {
            i++;
        }

        /* Verify that the next character is a colon */
        if (i >= len || json_str[i] != ':') {
            return -1;
        }
        
        /* Skip over the colon */
        i++;

        /* Skip over any whitespace between the colon and the value */
        while (i < len && is_whitespace(json_str[i])) {
            i++;
        }

        /* Parse the value */
        if (json_str[i] == '\"') {
            /* Parse a string value */
            i++;
            while (i < len && json_str[i] != '\"') {
                value[value_len++] = json_str[i++];
            }
            i++;
        }
        else if (json_str[i] == '-') {
            /* Parse a negative number */
            value[value_len++] = '-';
            i++;
            while (i < len && json_str[i] >= '0' && json_str[i] <= '9') {
                value[value_len++] = json_str[i++];
            }
        }
        else if (json_str[i] >= '0' && json_str[i] <= '9') {
            /* Parse a positive number */
            while (i < len && json_str[i] >= '0' && json_str[i] <= '9') {
                value[value_len++] = json_str[i++];
            }
        }
        else if (json_str[i] == 't') {
            /* Parse a boolean true value */
            if (i + 3 >= len || memcmp(&json_str[i], "true", 4) != 0) {
                return -1;
            }
            memcpy(value, "true", 4);
            value_len = 4;
            i += 4;
        }
        else if (json_str[i] == 'f') {
            /* Parse a boolean false value */
            if (i + 4 >= len || memcmp(&json_str[i], "false", 5) != 0) {
                return -1;
            }
            memcpy(value, "false", 5);
            value_len = 5;
            i += 5;
        }
        else if (json_str[i] == 'n') {
            /* Parse a null value */
            if (i + 3 >= len || memcmp(&json_str[i], "null", 4) != 0) {
                return -1;
            }
            memcpy(value, "null", 4);
            value_len = 4;
            i += 4;
        }
        else {
            /* Invalid value */
            return -1;
        }

        /* Skip over any whitespace between the value and the comma or closing brace */
        while (i < len && is_whitespace(json_str[i])) {
            i++;
        }

        /* Add the parsed name-value pair to the list */
        data_list[num_data++] = create_json_data(name, value);

        /* Check if there is another name-value pair */
        if (i < len && json_str[i] == ',') {
            i++;
        }
    }

    return num_data;
}

/* Main function */
int main()
{
    char* json_str = "{ \"name\": \"John Doe\", \"age\": 30, \"is_married\": false, \"address\": { \"street\": \"123 Main St\", \"city\": \"Anytown\", \"state\": \"CA\" } }";
    json_data* data_list[10];
    int num_data = parse_json(json_str, data_list);
    
    if (num_data >= 0) {
        for (int i = 0; i < num_data; i++) {
            printf("%s: %s\n", data_list[i]->name, data_list[i]->value);
            free_json_data(data_list[i]);
        }
    } else {
        printf("Error parsing JSON\n");
    }

    return 0;
}