//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: mathematical
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Metadata {
    char *name;
    int value;
};

struct MetadataList {
    struct Metadata *metadata;
    struct MetadataList *next;
};

void add_metadata(struct MetadataList *list, struct Metadata *metadata) {
    struct MetadataList *current = list;
    while (current->next != NULL) {
        current = current->next;
    }
    struct MetadataList *new_node = (struct MetadataList*) malloc(sizeof(struct MetadataList));
    new_node->metadata = metadata;
    new_node->next = NULL;
    current->next = new_node;
}

void extract_metadata(char *data, int data_size, struct MetadataList *list) {
    int i = 0;
    while (i < data_size) {
        if (data[i] == '<') {
            int j = i + 1;
            while (j < data_size && data[j] != '>') {
                j++;
            }
            if (j < data_size) {
                char *tag = malloc(sizeof(char) * (j - i));
                strncpy(tag, data + i + 1, j - i - 1);
                int value = 0;
                if (j + 2 < data_size && data[j + 1] == '{') {
                    int k = j + 2;
                    while (k < data_size && data[k] != '}') {
                        value = value * 10 + (data[k] - '0');
                        k++;
                    }
                    if (k < data_size && data[k] == '}') {
                        struct Metadata *metadata = (struct Metadata*) malloc(sizeof(struct Metadata));
                        metadata->name = tag;
                        metadata->value = value;
                        add_metadata(list, metadata);
                    }
                }
            }
            i = j + 1;
        } else {
            i++;
        }
    }
}

void print_metadata(struct MetadataList *list) {
    struct MetadataList *current = list->next;
    while (current != NULL) {
        printf("%s: %d\n", current->metadata->name, current->metadata->value);
        current = current->next;
    }
}

int main() {
    char *data = "<apple>{5}</apple><orange>{10}</orange><cherry>{3}</cherry>";
    int data_size = strlen(data);
    struct MetadataList *list = (struct MetadataList*) malloc(sizeof(struct MetadataList));
    list->next = NULL;
    extract_metadata(data, data_size, list);
    print_metadata(list);
    return 0;
}