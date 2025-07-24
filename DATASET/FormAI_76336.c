//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

/* Structure to represent a JSON object */
struct object {
    char key[MAX_SIZE];
    char value[MAX_SIZE];
};

/* Structure to represent a JSON array */
struct array {
    char values[MAX_SIZE][MAX_SIZE];
};

/* Function to parse a JSON object */
struct object parse_object(char* input) {
    struct object obj;
    int i, j;

    /* First, find the key */
    i = 1; // Skip curly bracket
    j = 0;
    while(input[i] != ':') {
        obj.key[j++] = input[i++];
    }
    obj.key[j] = '\0';

    /* Find the value */
    i++; // Skip colon
    j = 0;
    while(input[i] != '}') {
        obj.value[j++] = input[i++];
    }
    obj.value[j] = '\0';

    return obj;
}

/* Function to parse a JSON array */
struct array parse_array(char* input) {
    struct array arr;
    int i, j, k;

    /* Skip '[' */
    i = 1;

    /* Loop through each value in the array */
    j = 0;
    k = 0;
    while(input[i] != ']') {
        if(input[i] == ',') {
            arr.values[j++][k] = '\0';
            k = 0;
            i++;
        } else {
            arr.values[j][k++] = input[i++];
        }
    }
    arr.values[j][k] = '\0';

    return arr;
}

int main() {
    char input[MAX_SIZE];
    struct object obj;
    struct array arr;

    /* Read the input string */
    printf("Enter JSON string: ");
    fgets(input, MAX_SIZE, stdin);

    /* Check if it's an object or array */
    if(input[0] == '{') {
        obj = parse_object(input);
        printf("Object parsed: %s => %s\n", obj.key, obj.value);
    } else if(input[0] == '[') {
        arr = parse_array(input);
        printf("Array parsed with %d values:\n", strlen(arr.values));
        for(int i = 0; i < strlen(arr.values); i++) {
            printf("%s\n", arr.values[i]);
        }
    } else {
        printf("Invalid input!\n");
    }

    return 0;
}