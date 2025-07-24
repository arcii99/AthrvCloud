//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: creative
// This is a unique C Metadata Extractor example program that extracts metadata from a given file and prints it out

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 256

// Struct to hold metadata extracted
typedef struct {
    char* key;
    char* value;
} Metadata;

// Returns a pointer to a newly allocated Metadata struct
Metadata* Metadata_new() {
    return (Metadata*)malloc(sizeof(Metadata));
}

// Frees a Metadata instance
void Metadata_free(Metadata* meta) {
    free(meta->key);
    free(meta->value);
    free(meta);
}

// Extracts metadata from file and stores in array of Metadata structs
Metadata** extract_metadata(char* filename, int* count) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: Failed to open file '%s'\n", filename);
        return NULL;
    }
    
    Metadata** metadata = (Metadata**)malloc(sizeof(Metadata*) * MAX_LINE_LEN);
    char line[MAX_LINE_LEN];
    int i = 0;

    while (fgets(line, MAX_LINE_LEN, fp)) { // Read file line-by-line
        char* key = strtok(line, ":\n"); // Split line into key and value components
        char* value = strtok(NULL, ":\n");

        if (key && value) { // If the line has both key and value components
            metadata[i] = Metadata_new(); // Allocate new Metadata struct and add to array
            metadata[i]->key = strdup(key); // Copy key and value strings to new Memory and assign to Metadata struct
            metadata[i]->value = strdup(value);
            i++;
        }
    }
    
    fclose(fp);
    *count = i;
    return metadata; // Return array of Metadata structs
}

// Prints metadata from array of Metadata structs
void print_metadata(Metadata** metadata, int count) {
    printf("%d Metadata Entries Found:\n", count);
    for (int i = 0; i < count; i++) {
        printf("%s: %s\n", metadata[i]->key, metadata[i]->value);
    }
}


int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Error: Usage: metadata_extractor <filename>\n");
        return 1;
    }

    int count;
    Metadata** metadata = extract_metadata(argv[1], &count);
    if (!metadata) {
        return 1;
    }
    print_metadata(metadata, count);

    // Free Metadata entries and array
    for (int i = 0; i < count; i++) {
        Metadata_free(metadata[i]);
    }
    free(metadata);
    
    return 0;
}