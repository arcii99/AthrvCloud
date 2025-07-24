//FormAI DATASET v1.0 Category: Data validation ; Style: asynchronous
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_INPUT_LENGTH 256

static char input[MAX_INPUT_LENGTH];
static bool valid = true;

static void validate_data(const char *data)
{
    if (!data || data[0] == '\0') {
        valid = false;
        return;
    }

    for (int i = 0; data[i] != '\0'; i++) {
        if (!isdigit(data[i])) {
            valid = false;
            return;
        }
    }
}

static void async_input_callback(char *data)
{
    validate_data(data);
    free(data);

    if (valid) {
        printf("Input is valid!\n");
    } else {
        printf("Input is not valid!\n");
    }
}

int main(int argc, char **argv)
{
    puts("Please enter some data:");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    char *data = malloc((strlen(input) + 1) * sizeof(char));

    if (!data) {
        perror("Failed to allocate memory!");
        exit(EXIT_FAILURE);
    }

    strcpy(data, input);

    async_input_callback(data);

    return 0;
}