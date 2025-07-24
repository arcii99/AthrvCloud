//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: random
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct metadata {
    char *key;
    char *value;
};

/* Function to extract metadata */
struct metadata *extract_metadata(char *str) {
    struct metadata *meta = NULL;
    int count = 0, i, j, len;
    char delimiter[] = " \t\n", *token;

    /* Get the number of metadata entries */
    token = strtok(str, delimiter);
    while(token != NULL) {
        if(strncmp(token, "META", 4) == 0)
            count++;

        token = strtok(NULL, delimiter);
    }

    /* Allocate memory for metadata array */
    meta = (struct metadata*) malloc(count * sizeof(struct metadata));

    /* Extract metadata */
    i = 0;
    token = strtok(str, delimiter);
    while(token != NULL) {
        if(strncmp(token, "META", 4) == 0) {
            len = strlen(token);
            meta[i].key = (char*) malloc((len + 1) * sizeof(char));
            strncpy(meta[i].key, token, len);
            meta[i].key[len] = '\0';

            token = strtok(NULL, delimiter);

            len = strlen(token);
            meta[i].value = (char*) malloc((len + 1) * sizeof(char));
            strncpy(meta[i].value, token, len);
            meta[i].value[len] = '\0';

            i++;
        }

        token = strtok(NULL, delimiter);
    }

    return meta;
}

int main() {
    char str[] = "META1 hello META2 world META3 how META4 are META5 you META6 I'm META7 fine";
    struct metadata *meta = extract_metadata(str);
    int i;

    /* Print metadata */
    for(i = 0; i < 7; i++)
        printf("%s: %s\n", meta[i].key, meta[i].value);

    /* Free memory */
    for(i = 0; i < 7; i++) {
        free(meta[i].key);
        free(meta[i].value);
    }
    free(meta);

    return 0;
}