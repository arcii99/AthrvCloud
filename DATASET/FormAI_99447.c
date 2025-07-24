//FormAI DATASET v1.0 Category: Text processing ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LENGTH 100

/* Define a safe version of strcpy called safe_strcpy */
void safe_strcpy(char dest[], char src[]) {
    int i = 0;
    while (src[i] != '\0' && i < MAX_STRING_LENGTH) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

/* Define a safe version of strcat called safe_strcat */
void safe_strcat(char dest[], char src[]) {
    int i = strlen(dest);
    int j = 0;
    while (src[j] != '\0' && i < MAX_STRING_LENGTH) {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
}

int main() {
    char input_string[MAX_STRING_LENGTH];
    char output_string[MAX_STRING_LENGTH] = "";

    printf("Please enter a string: ");
    fgets(input_string, MAX_STRING_LENGTH, stdin);

    char *token = strtok(input_string, " ");
    while (token != NULL) {
        char temp_string[MAX_STRING_LENGTH];
        safe_strcpy(temp_string, token);
        int length = strlen(temp_string);
        if (length > 1 && temp_string[length-1] == 's') {
            temp_string[length-1] = '\0';
        } else {
            safe_strcat(temp_string, "s");
        }
        safe_strcat(output_string, temp_string);
        safe_strcat(output_string, " ");
        token = strtok(NULL, " ");
    }

    printf("Output string: %s\n", output_string);

    return 0;
}