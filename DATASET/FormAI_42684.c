//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int byte_size;
    char data_type[10];
} Metadata;

int main() {
    char metadata_size_str[20];
    printf("Enter the size of metadata in bytes: ");
    fgets(metadata_size_str, 20, stdin);
    int metadata_size = atoi(metadata_size_str);

    char metadata_buffer[metadata_size];
    printf("Enter the metadata: ");
    fgets(metadata_buffer, metadata_size, stdin);

    int num_fields;
    printf("Enter the number of fields in the metadata: ");
    scanf("%d", &num_fields);

    Metadata metadata[num_fields];
    for (int i = 0; i < num_fields; i++) {
        char field_str[50];
        printf("Enter the size and data type of field %d in the format <size><space><data_type>: ", i+1);
        scanf("%s", field_str);
        char *size_str = strtok(field_str, " ");
        char *data_type_str = strtok(NULL, " ");
        metadata[i].byte_size = atoi(size_str);
        strcpy(metadata[i].data_type, data_type_str);
    }

    printf("\nMetadata fields and data:\n");
    int byte_offset = 0;
    for (int i = 0; i < num_fields; i++) {
        char field_data[metadata[i].byte_size+1];
        memcpy(field_data, &metadata_buffer[byte_offset], metadata[i].byte_size);
        field_data[metadata[i].byte_size] = '\0';
        printf("%s: %s\n", metadata[i].data_type, field_data);
        byte_offset += metadata[i].byte_size;
    }

    return 0;
}