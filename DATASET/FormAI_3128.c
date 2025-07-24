//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold our parsed XML data
typedef struct {
    char tag[50];
    char attributes[100][2][50];
    int num_attrs;
    char content[1000];
    int has_content;
} xml_data;

// Function to parse an XML string and fill our data struct
xml_data parse_xml(char* xml) {
    xml_data data;
    int i = 0;
    int attrs_count = 0;

    // Get opening tag
    while (xml[i] != ' ' && xml[i] != '>') {
        data.tag[i] = xml[i];
        i++;
    }
    data.tag[i] = '\0';

    // Get attributes
    while (xml[i] != '>') {
        if (xml[i] == ' ') {
            i++;
            int name_start = i;
            int name_end;
            int val_start;
            int val_end;

            // Get attribute name
            while (xml[i] != '=') {
                i++;
            }
            name_end = i - 1;
            memcpy(data.attributes[attrs_count][0], &xml[name_start], name_end - name_start + 1);
            data.attributes[attrs_count][0][name_end - name_start + 1] = '\0';

            // Get attribute value
            i++; // Skip the equals sign
            if (xml[i] == '"') {
                i++;
                val_start = i;
                while (xml[i] != '"') {
                    i++;
                }
                val_end = i - 1;
                memcpy(data.attributes[attrs_count][1], &xml[val_start], val_end - val_start + 1);
                data.attributes[attrs_count][1][val_end - val_start + 1] = '\0';
            }
            attrs_count++;
        }
        i++;
    }
    data.num_attrs = attrs_count;

    // Check if there's content
    int content_start = i + 1;
    int content_end = strlen(xml) - 3; // Account for "</" + tag + ">"

    if (content_end > content_start) {
        memcpy(data.content, &xml[content_start], content_end - content_start + 1);
        data.has_content = 1;
    } else {
        data.content[0] = '\0';
        data.has_content = 0;
    }

    return data;
}

// Test the parser
int main() {
    char* xml = "<person name=\"John\" age=\"25\">Hello, world!</person>";
    xml_data data = parse_xml(xml);

    printf("Tag: %s\n", data.tag);
    printf("Attributes:\n");
    for (int i = 0; i < data.num_attrs; i++) {
        printf("  %s: %s\n", data.attributes[i][0], data.attributes[i][1]);
    }
    if (data.has_content) {
        printf("Content: %s\n", data.content);
    } else {
        printf("No content.\n");
    }

    return 0;
}