//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// function to parse a JSON string
void parse_json(char* json_str) {
    // initialize variables to hold data
    int object_count = 0;
    int array_count = 0;

    // initialize stack to hold object and array counts
    int stack[1024];
    int top = -1;

    // loop through string
    for (int i = 0; i < strlen(json_str); i++) {
        // check for opening brace
        if (json_str[i] == '{') {
            // increment object count and push onto stack
            object_count++;
            stack[++top] = object_count;
            printf("Found object #%d\n", object_count);
        }

        // check for opening bracket
        if (json_str[i] == '[') {
            // increment array count and push onto stack
            array_count++;
            stack[++top] = -array_count;
            printf("Found array #%d\n", array_count);
        }

        // check for closing brace or bracket
        if (json_str[i] == '}' || json_str[i] == ']') {
            // pop from stack and print count
            int count = stack[top--];
            if (count > 0) {
                printf("Found end of object #%d\n", count);
            } else {
                printf("Found end of array #%d\n", -count);
            }
        }
    }

    // check if all objects and arrays have been closed
    if (top == -1) {
        printf("JSON parsing successful!\n");
    } else {
        printf("Error: Not all objects and arrays have been closed.\n");
    }
}

int main() {
    char* json_str = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\",\"pets\":[{\"name\":\"Fluffy\",\"species\":\"Cat\"},{\"name\":\"Buddy\",\"species\":\"Dog\"}],\"favorite_numbers\":[2,4,6,8]}";
    parse_json(json_str);
    return 0;
}