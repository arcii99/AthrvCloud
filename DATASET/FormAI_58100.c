//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

struct json_object {
    char *key;
    char *value;
    bool is_string;
};

void *parse_json(void *file) {
    char *filename = (char *)file;
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        pthread_exit(NULL);
    }

    char buffer[BUFFER_SIZE];
    int i, j = 0;
    char c;
    bool in_string = false;
    struct json_object object;
    object.key = NULL;
    object.value = NULL;
    object.is_string = false;
    bool valid_json = true;

    while (fgets(buffer, BUFFER_SIZE, fp) != NULL && valid_json) {
        int len = strlen(buffer);

        for (i = 0; i < len; i++) {
            c = buffer[i];
            if (c == '{') {
                printf("Starting object\n");
            } else if (c == '}') {
                printf("Ending object\n");
                if (object.key != NULL && object.value != NULL) {
                    printf("Object: %s=%s\n", object.key, object.value);
                    free(object.key);
                    free(object.value);
                    object.key = NULL;
                    object.value = NULL;
                }
            } else if (in_string) {
                if (c == '"') {
                    in_string = false;

                    if (object.key == NULL) {
                        object.key = (char *)malloc((j + 1) * sizeof(char));
                        strncpy(object.key, &buffer[i - j], j);
                        object.key[j] = '\0';
                        j = 0;
                    } else {
                        object.value = (char *)malloc((j + 1) * sizeof(char));
                        strncpy(object.value, &buffer[i - j], j);
                        object.value[j] = '\0';
                        j = 0;
                    }
                } else {
                    j++;
                }
            } else if (c == ':') {
            } else if (c == '"') {
                in_string = true;
                object.is_string = true;
            } else if (c == ',' || c == '\n') {
                if (object.key != NULL && object.value != NULL) {
                    if (object.is_string) {
                        printf("String: %s=%s\n", object.key, object.value);
                    } else {
                        printf("Number: %s=%s\n", object.key, object.value);
                    }

                    free(object.key);
                    free(object.value);
                    object.key = NULL;
                    object.value = NULL;
                    object.is_string = false;
                }
            } else if (c == ' ' || c == '\t') {
                // Ignore white space
            } else {
                j++;
            }
        }
    }

    fclose(fp);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    pthread_t threads[argc - 1];
    int i, rc;

    for (i = 1; i < argc; i++) {
        rc = pthread_create(&threads[i - 1], NULL, parse_json, argv[i]);

        if (rc) {
            printf("Error creating thread\n");
            exit(-1);
        }
    }

    pthread_exit(NULL);
    return 0;
}