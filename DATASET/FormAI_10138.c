//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct to store the metadata extracted */
typedef struct {
    char *title;
    int year;
    char *director;
    char **actors;
    int num_actors;
} Metadata;

/* Function to extract metadata from a file */
Metadata extract_metadata(char *filename) {
    Metadata metadata;
    metadata.title = NULL;
    metadata.year = -1;
    metadata.director = NULL;
    metadata.actors = NULL;
    metadata.num_actors = 0;
    
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        char *key = strtok(line, ":");
        char *value = strtok(NULL, "\n");
        if (key == NULL || value == NULL) {
            continue;
        }
        if (strcmp(key, "Title") == 0) {
            metadata.title = strdup(value);
        } else if (strcmp(key, "Year") == 0) {
            metadata.year = atoi(value);
        } else if (strcmp(key, "Director") == 0) {
            metadata.director = strdup(value);
        } else if (strcmp(key, "Actors") == 0) {
            char *actor = strtok(value, ",");
            while (actor != NULL) {
                metadata.actors = realloc(metadata.actors, (metadata.num_actors + 1) * sizeof(char *));
                metadata.actors[metadata.num_actors] = strdup(actor);
                metadata.num_actors++;
                actor = strtok(NULL, ",");
            }
        }
    }
    
    fclose(file);
    return metadata;
}

/* Function to print metadata */
void print_metadata(Metadata metadata) {
    printf("Title: %s\n", metadata.title);
    printf("Year: %d\n", metadata.year);
    printf("Director: %s\n", metadata.director);
    printf("Actors: ");
    for (int i = 0; i < metadata.num_actors; i++) {
        printf("%s", metadata.actors[i]);
        if (i < metadata.num_actors - 1) {
            printf(", ");
        } else {
            printf("\n");
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    Metadata metadata = extract_metadata(argv[1]);
    print_metadata(metadata);
    
    /* Free memory */
    free(metadata.title);
    free(metadata.director);
    for (int i = 0; i < metadata.num_actors; i++) {
        free(metadata.actors[i]);
    }
    free(metadata.actors);
    
    return 0;
}