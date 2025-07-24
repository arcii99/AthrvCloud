//FormAI DATASET v1.0 Category: Text processing ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input_string[50];
    char final_string[50];
    int count = 0;
    int length;

    printf("Enter a string: ");
    fgets(input_string, sizeof(input_string), stdin);

    length = strlen(input_string);

    for (int i=0; i<length; i++) {
        if (input_string[i] != ' ') {
            final_string[count++] = input_string[i];
        }
    }

    final_string[count] = '\0';

    printf("Final string without spaces: %s", final_string);

    return 0;
}