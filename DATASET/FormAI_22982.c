//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define maximum length of keys and values in JSON file
#define MAX_KEY_LEN 50
#define MAX_VAL_LEN 100

// JSON parser function
void parseJSON(char *filename) {

    // open JSON file for reading
    FILE *fp = fopen(filename, "r");

    // declare variables for storing current key-value pair
    char key[MAX_KEY_LEN];
    char val[MAX_VAL_LEN];

    // loop through JSON file contents
    int c;
    while ((c = fgetc(fp)) != EOF) {

        // check if current character is start of a key-value pair
        if (c == '\"') {

            // extract key and discard colon
            fscanf(fp, "%[^\"]", key);
            fseek(fp, 1, SEEK_CUR);

            // extract value and discard comma or end brace
            fscanf(fp, " %[^\"]", val);
            fseek(fp, 1, SEEK_CUR);

            // print key-value pair
            printf("%s: %s\n", key, val);
        }
    }

    // close file
    fclose(fp);
}

int main() {

    // call JSON parser function
    parseJSON("example.json");

    return 0;
}