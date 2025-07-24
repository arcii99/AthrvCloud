//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 512
#define MAX_NAME_LENGTH 32

/* Structure to hold metadata information */
typedef struct {
    char name[MAX_NAME_LENGTH];
    int line_number;
} metadata_t;

/* Function to extract metadata from C source file */
int extract_metadata(const char *filename, metadata_t *metadata_list)
{
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    int line_number = 0;
    int num_metadata = 0;

    /* Open the file */
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return -1;
    }

    /* Read each line of the file */
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        line_number++;

        /* Check if the line contains metadata */
        if (strstr(line, "/* metadata:")) {
            char *name_start, *name_end;
            metadata_t metadata;

            /* Extract the metadata name */
            name_start = strstr(line, ":") + 2;
            name_end = strstr(line, " */");
            strncpy(metadata.name, name_start, name_end - name_start);
            metadata.name[name_end - name_start] = '\0';

            /* Save the metadata information */
            metadata.line_number = line_number;
            metadata_list[num_metadata++] = metadata;
        }
    }

    /* Close the file */
    fclose(fp);

    return num_metadata;
}

int main(int argc, char **argv)
{
    metadata_t metadata_list[1024];
    int num_metadata;
    int i;

    /* Check command line arguments */
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    /* Extract metadata from file */
    num_metadata = extract_metadata(argv[1], metadata_list);
    if (num_metadata < 0) {
        printf("Error extracting metadata from file %s\n", argv[1]);
        return 1;
    }

    /* Print metadata information */
    printf("%d metadata entries found in file %s\n", num_metadata, argv[1]);
    for (i = 0; i < num_metadata; i++) {
        printf("Metadata %d: Name=%s, Line=%d\n", i + 1, metadata_list[i].name, metadata_list[i].line_number);
    }

    return 0;
}