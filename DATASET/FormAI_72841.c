//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// XML tag structure
typedef struct {
    char name[32];
    char content[128];
} xmltag;

int main() {
    // XML input string
    char xml[] = "<?xml version=\"1.0\" encoding=\"UTF-8\"?><root><tag1>content1</tag1><tag2>content2</tag2></root>";

    // Parse XML tags and contents
    xmltag tags[10];
    int tagcount = 0;
    int contentcount = 0;

    char* ptr = xml;
    while (*ptr != '\0') {
        // Check for opening tag
        if (*ptr == '<') {
            xmltag tag;
            char* end = strstr(ptr, ">");
            if (end == NULL) {
                printf("Error: Invalid tag\n");
                return 1;
            }
            int len = end - ptr - 1;
            strncpy(tag.name, ptr+1, len);
            tag.name[len] = '\0';
            ptr = end + 1;

            // Check for content
            end = strstr(ptr, "<");
            if (end != NULL) {
                len = end - ptr;
                strncpy(tag.content, ptr, len);
                tag.content[len] = '\0';
                ptr = end;
            }
            else {
                len = strlen(ptr);
                strncpy(tag.content, ptr, len);
                tag.content[len] = '\0';
                ptr += len;
            }

            tags[tagcount++] = tag;
        }
        else {
            ptr++;
        }
    }

    // Print XML tags and contents
    for (int i = 0; i < tagcount; i++) {
        printf("Tag %d: %s\nContent %d: %s\n", i+1, tags[i].name, i+1, tags[i].content);
    }

    return 0;
}