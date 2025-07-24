//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct metadata {
    char type[50];
    char name[50];
    struct metadata* next;
} metadata_t;

metadata_t* head = NULL;

void add_metadata(char* type, char* name) {
    metadata_t* new_metadata = (metadata_t*) malloc(sizeof(metadata_t));
    strcpy(new_metadata->type, type);
    strcpy(new_metadata->name, name);
    new_metadata->next = NULL;
    if (head == NULL) {
        head = new_metadata;
    } else {
        metadata_t* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new_metadata;
    }
}

int main(int argc, char** argv) {
    char* filename = argv[1];
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Could not open file: %s\n", filename);
        return 1;
    }
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, "int ") != NULL) {
            char name[50];
            sscanf(line, "%*s %s", name);
            add_metadata("int", name);
        } else if (strstr(line, "float ") != NULL) {
            char name[50];
            sscanf(line, "%*s %s", name);
            add_metadata("float", name);
        } else if (strstr(line, "char ") != NULL) {
            char name[50];
            sscanf(line, "%*s %s", name);
            add_metadata("char", name);
        } else if (strstr(line, "double ") != NULL) {
            char name[50];
            sscanf(line, "%*s %s", name);
            add_metadata("double", name);
        }
    }
    fclose(fp);
    metadata_t* curr = head;
    while (curr != NULL) {
        printf("%s %s\n", curr->type, curr->name);
        curr = curr->next;
    }
    return 0;
}