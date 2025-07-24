//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_LENGTH 1024

char* parse_json(char* json_str)
{
    char* parsed_json = malloc(MAX_JSON_LENGTH * sizeof(char));
    if(parsed_json == NULL)
    {
        printf("Error: Could not allocate memory for parsed json string\n");
        exit(EXIT_FAILURE);
    }
    memset(parsed_json, 0, MAX_JSON_LENGTH);

    int position = 0;
    int json_length = strlen(json_str);

    while(position < json_length)
    {
        char delimiter = json_str[position];
        if(delimiter == '{' || delimiter == '}' || delimiter == ':' || delimiter == ',')
        {
            char formatted_char[3];
            snprintf(formatted_char, sizeof(formatted_char), "\\%c", delimiter);
            strcat(parsed_json, formatted_char);
        }
        else
        {
            strncat(parsed_json, &json_str[position], 1);
        }
        position++;
    }

    return parsed_json;
}

int main()
{
    char json[] = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";

    char* parsed_json = parse_json(json);
    printf("Parsed JSON: %s\n", parsed_json);

    free(parsed_json);

    return EXIT_SUCCESS;
}