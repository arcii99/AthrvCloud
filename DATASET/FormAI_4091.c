//FormAI DATASET v1.0 Category: Text processing ; Style: detailed
#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 100

int main() {
    char input_str[MAX_STR_LEN];
    char output_str[MAX_STR_LEN];
    int i, j, k;

    printf("Enter a string: ");
    fgets(input_str, MAX_STR_LEN, stdin);

    i = j = k = 0;

    while (input_str[i] != '\0') {
        if (input_str[i] == ' ') {
            output_str[j++] = input_str[i++];
            continue;
        }
        if (i == 0 || input_str[i-1] == ' ') {
            if (input_str[i] >= 'a' && input_str[i] <= 'z') {
                output_str[j++] = input_str[i++] - 32;
            } else {
                output_str[j++] = input_str[i++];
            }
        } else {
            if (input_str[i] >= 'A' && input_str[i] <= 'Z') {
                output_str[j++] = input_str[i++] + 32;
            } else {
                output_str[j++] = input_str[i++];
            }
        }
    }
    output_str[j] = '\0';

    printf("Output String: %s", output_str);
    return 0;
}