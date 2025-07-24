//FormAI DATASET v1.0 Category: Browser Plugin ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Define our browser plugin structure
typedef struct {
    char *name;
    char *version;
    char *(*function)(char *);
} BrowserPlugin;

// Our first plugin function
char *to_uppercase(char *str) {
    int i;
    for (i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
    return str;
}

// Our second plugin function
char *to_lowercase(char *str) {
    int i;
    for (i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

// Our third plugin function
char *reverse_string(char *str) {
    int i = 0, j = strlen(str)-1;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    return str;
}

// Define our plugins
BrowserPlugin plugins[] = {
    {"to_uppercase", "1.0", to_uppercase},
    {"to_lowercase", "1.0", to_lowercase},
    {"reverse_string", "1.0", reverse_string}
};

int main() {
    int num_plugins = sizeof(plugins) / sizeof(BrowserPlugin);
    char str[100];

    // Prompt user to enter a string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character
    str[strcspn(str, "\n")] = '\0';

    // Loop through each plugin and execute its function on the string
    for (int i = 0; i < num_plugins; i++) {
        char *result = plugins[i].function(str);
        printf("%s: %s\n", plugins[i].name, result);
    }

    return 0;
}