//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 1024
#define MAX_METADATA_SIZE 2048

/* Function Declarations */
char *extract_metadata(const char *filename, const char *config_path);
int is_requested_field(const char *field_name, const char *requested_fields[], int num_requested_fields);

/* Entry point */
int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <filename> <config_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    const char *config_path = argv[2];

    char *metadata = extract_metadata(filename, config_path);

    if (metadata == NULL) {
        fprintf(stderr, "Failed to extract metadata from %s using config file %s\n", filename, config_path);
        return EXIT_FAILURE;
    }

    printf("%s", metadata);
    free(metadata);

    return EXIT_SUCCESS;
}

/* Extract metadata from filename using the config specified in config_path */
char *extract_metadata(const char *filename, const char *config_path) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file %s for reading\n", filename);
        return NULL;
    }

    FILE *config_file = fopen(config_path, "r");
    if (config_file == NULL) {
        fprintf(stderr, "Failed to open config file %s for reading\n", config_path);
        fclose(file);
        return NULL;
    }

    char metadata[MAX_METADATA_SIZE] = {0};
    char line[MAX_FILENAME_SIZE] = {0};
    char temp[MAX_FILENAME_SIZE] = {0};

    while (fgets(line, MAX_FILENAME_SIZE, config_file) != NULL) {
        int num_requested_fields = 0;
        char *requested_fields[MAX_FILENAME_SIZE];

        // parse line in config file
        char *p = strtok(line, ",");
        while (p != NULL) {
            if (num_requested_fields >= MAX_FILENAME_SIZE) {
                fprintf(stderr, "Max num of requested fields reached\n");
                fclose(config_file);
                fclose(file);
                return NULL;
            }
            requested_fields[num_requested_fields++] = p;
            p = strtok(NULL, ",");
        }

        int num_fields = 0;
        char *field_names[MAX_FILENAME_SIZE];
        int field_sizes[MAX_FILENAME_SIZE];

        // get field names and sizes from file
        int c;
        int in_field_name = 1;
        size_t field_name_length = 0;
        size_t current_field_size = 0;

        while ((c = fgetc(file)) != EOF) {
            if (in_field_name && c == '=') {
                in_field_name = 0;
                field_names[num_fields] = strdup(temp);
                temp[0] = '\0';
            } else if (in_field_name && c == ' ') {
                // ignore leading spaces
                continue;
            } else if (in_field_name) {
                temp[field_name_length++] = (char) c;
            } else if (c == '\n') {
                in_field_name = 1;
                field_sizes[num_fields++] = current_field_size;
                current_field_size = 0;
                field_name_length = 0;
                temp[0] = '\0';
            } else {
                current_field_size++;
            }
        }

        rewind(file);

        // create metadata string based on requested fields
        size_t metadata_length = 0;
        for (int i = 0; i < num_fields; i++) {
            if (is_requested_field(field_names[i], requested_fields, num_requested_fields)) {
                metadata_length += snprintf(metadata + metadata_length, MAX_METADATA_SIZE - metadata_length, "%s:", field_names[i]);
                char *field_value = (char *) malloc(field_sizes[i] + 1);
                if (fread(field_value, 1, field_sizes[i], file) != field_sizes[i]) {
                    fprintf(stderr, "Failed to read field %s from file %s\n", field_names[i], filename);
                    fclose(config_file);
                    fclose(file);
                    return NULL;
                }
                field_value[field_sizes[i]] = '\0'; // null terminate
                metadata_length += snprintf(metadata + metadata_length, MAX_METADATA_SIZE - metadata_length, "%s,", field_value);
                free(field_value);
            } else {
                // skip over field
                fseek(file, field_sizes[i], SEEK_CUR);
            }
        }
    }

    fclose(config_file);
    fclose(file);

    return strdup(metadata);
}

/* Check if field_name is one of the requested fields */
int is_requested_field(const char *field_name, const char *requested_fields[], int num_requested_fields) {
    for (int i = 0; i < num_requested_fields; i++) {
        if (strcmp(field_name, requested_fields[i]) == 0) {
            return 1;
        }
    }
    return 0;
}