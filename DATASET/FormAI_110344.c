//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 100

int main() {
    FILE *in;
    char line[MAX_LINE];
    char *token;
    int total, used, free;

    in = popen("free", "r");

    if (in == NULL) {
        perror("Unable to execute command");
        exit(1);
    }

    /* Ignore first line */
    fgets(line, MAX_LINE, in);

    /* Read the second line */
    fgets(line, MAX_LINE, in);

    /* Parse the line */
    token = strtok(line, " ");
    total = atoi(token);

    token = strtok(NULL, " ");
    used = atoi(token);

    token = strtok(NULL, " ");
    free = atoi(token);

    /* Print the results */
    printf("Total RAM: %d\n", total);
    printf("Used RAM: %d\n", used);
    printf("Free RAM: %d\n", free);

    pclose(in);
    return 0;
}