//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: configurable
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* key;
    char* value;
    int length;
} MetaData;

typedef struct {
    MetaData* list;
    int size;
} MetaDataList;

MetaDataList extractMetaData(const char* data, const char** keys, int keyCount) {
    MetaDataList results;
    int dataLength = strlen(data);
    results.list = calloc(dataLength, sizeof(MetaData));
    results.size = 0;

    for (int i = 0; i < keyCount; i++) {
        const char* key = keys[i];
        int keyLength = strlen(key);
        const char* position = data;
        while ((position = strstr(position, key))) {
            position += keyLength;
            if (*position != ' ') {
                continue;
            }
            position++;
            const char* lineEnd = strstr(position, "\r\n");
            if (lineEnd == NULL) {
                continue;
            }
            int valueLength = lineEnd - position;
            MetaData data = {
                .key = key, 
                .value = strndup(position, valueLength),
                .length = valueLength
            };
            results.list[results.size] = data;
            results.size++;
            position = lineEnd;
        }
    }

    return results;
}

int main() {
    const char text[] = "HTTP/1.1 200 OK\r\n"
                        "Date: Mon, 27 Jul 2009 12:28:53 GMT\r\n"
                        "Server: Apache/2.2.14 (Win32)\r\n"
                        "Last-Modified: Wed, 22 Jul 2009 19:15:56 GMT\r\n"
                        "Content-Length: 88\r\n"
                        "Content-Type: text/html\r\n"
                        "\r\n";
    
    const char* keys[] = {"Date:", "Server:", "Content-Length:", "Content-Type:"};
    int keyCount = 4;

    MetaDataList results = extractMetaData(text, keys, keyCount);
    for (int i = 0; i < results.size; i++) {
        printf("%s = %s\n", results.list[i].key, results.list[i].value);
    }

    for (int i = 0; i < results.size; i++) {
        free(results.list[i].value);
    }
    free(results.list);

    return 0;
}