//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: active
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* name;
    char* value;
} Metadata;

int main() {
    char fileData[] = "filename:example.txt\ndate-created:2021/06/23\ntype:text";
    Metadata metadata[3];
    int metaDataCount = 0;
    char* cursor = fileData;
    
    while (*cursor != '\0') {
        char* startKey = cursor;
        while (*cursor != ':' && *cursor != '\0') {
            cursor++;
        }
        if (*cursor == '\0') { break; }
        char* endKey = cursor;
        cursor++;
        char* startValue = cursor;
        while (*cursor != '\n' && *cursor != '\0') {
            cursor++;
        }
        char* endValue = cursor;
        if (*cursor == '\n') { cursor++; }
        Metadata data = {NULL, NULL};
        data.name = (char*)malloc(endKey - startKey + 1);
        if (data.name != NULL) {
            for (int i = 0; i < (endKey - startKey); i++) {
                data.name[i] = startKey[i];
            }
            data.name[endKey - startKey] = '\0';
        }
        data.value = (char*)malloc(endValue - startValue + 1);
        if (data.value != NULL) {
            for (int i = 0; i < (endValue - startValue); i++) {
                data.value[i] = startValue[i];
            }
            data.value[endValue - startValue] = '\0';
        }
        metadata[metaDataCount++] = data;
    }
    
    for (int i = 0; i < metaDataCount; i++) {
        printf("%s:%s\n", metadata[i].name, metadata[i].value);
        free(metadata[i].name);
        free(metadata[i].value);
    }

    return 0;
}