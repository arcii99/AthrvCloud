//FormAI DATASET v1.0 Category: Text processing ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int main() {
    char* input_string = (char*)malloc(MAX_SIZE * sizeof(char));
    printf("Enter a string: ");
    scanf("%[^\n]s", input_string);

    int* frequency = (int*)calloc(128, sizeof(int));

    if (input_string == NULL) {
        printf("Error: memory not allocated.");
        exit(1);
    }

    int length = strlen(input_string);
    for (int i = 0; i < length; i++)
        frequency[(int)input_string[i]]++;

    printf("Frequency of characters in the string: \n");
    for (int i = 0; i < 128; i++)
        if (frequency[i] > 0)
            printf("%c: %d\n", i, frequency[i]);

    free(input_string);
    input_string = NULL;
    free(frequency);
    frequency = NULL;

    return 0;
}