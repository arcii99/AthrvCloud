//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Metadata {
    int size;
    char* type;
    char* name;
} Metadata;

int main() {
    Metadata metadata1;
    metadata1.size = 10;
    metadata1.type = "int";
    metadata1.name = "foo";

    Metadata metadata2;
    metadata2.size = 20;
    metadata2.type = "char";
    metadata2.name = "bar";

    Metadata metadata3;
    metadata3.size = 30;
    metadata3.type = "float";
    metadata3.name = "baz";

    printf("Metadata 1:\n");
    printf("Size: %d\n", metadata1.size);
    printf("Type: %s\n", metadata1.type);
    printf("Name: %s\n\n", metadata1.name);

    printf("Metadata 2:\n");
    printf("Size: %d\n", metadata2.size);
    printf("Type: %s\n", metadata2.type);
    printf("Name: %s\n\n", metadata2.name);

    printf("Metadata 3:\n");
    printf("Size: %d\n", metadata3.size);
    printf("Type: %s\n", metadata3.type);
    printf("Name: %s\n\n", metadata3.name);

    return 0;
}