//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *extract_metadata(char *file_content, int filesize) {
    char *metadata = (char*) malloc(filesize * sizeof(char));
    memset(metadata, 0, filesize);
    int i = 0;
    int j = 0;
    int inside_metadata = 0;
    int metadata_size = 0;

    for ( ; i < filesize; i++) {
        char ch = file_content[i];
        if (ch == '{') {
            inside_metadata = 1;
        } else if (ch == '}') {
            inside_metadata = 0;
            break;
        } else {
            if (inside_metadata == 1) {
                metadata[j] = ch;
                j++;
            }
        }
    }

    metadata_size = strlen(metadata);

    printf("Metadata size is %d\n", metadata_size);
    printf("Metadata: %s\n", metadata);

    return metadata;
}

int main() {
    char *file_content = "{\n\t\"title\": \"My Awesome Metadata\",\n\t\"author\": \"John Doe\",\n\t\"creation_date\": \"2022-02-02\"\n}\nThis is the actual content of the file.";
    int filesize = strlen(file_content);

    char *metadata = extract_metadata(file_content, filesize);

    return 0;
}