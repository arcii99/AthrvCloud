//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to parse JSON */
void parse_JSON(char* json_str) {
    int i = 0;
    while (json_str[i] != '\0') {
        if (json_str[i] == '{') {
            printf("Ahoy! Brace yourself, we have an object!\n");
            // Code to handle object
        }
        else if (json_str[i] == '[') {
            printf("Arrrr! We have an array me mateys!\n");
            // Code to handle array
        }
        else if (json_str[i] == '\"') {
            printf("Shiver me timbers! We be findin' a string!\n");
            // Code to handle string
        }
        else if (json_str[i] >= '0' && json_str[i] <= '9') {
            printf("Blimey! Ye be findin' a number ye landlubber!\n");
            // Code to handle number
        }
        else if (json_str[i] == 't' || json_str[i] == 'f' || json_str[i] == 'n') {
            printf("Avast! Ye be findin' a boolean or null!\n");
            // Code to handle boolean or null
        }
        i++;
    }
}

int main() {
    char json_str[1000];
    printf("Yo ho ho! Enter the JSON string ya scallywag:\n");
    fgets(json_str, 1000, stdin);
    printf("Aye, this be the JSON string we received:\n%s", json_str);
    parse_JSON(json_str);   // Call function to parse JSON
    printf("Yo ho ho! We be done parsing the JSON! Cheers matey!\n");
    return 0;
}