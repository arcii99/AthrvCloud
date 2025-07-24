//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Structure for storing XML tag attributes
typedef struct {
    char *name;
    char *value;
} Attribute;

// Structure for storing XML tags
typedef struct {
    char *name;
    Attribute *attributes;
    int attribute_count;
    char *value;
} Tag;

// Function to parse XML file and store tags in an array
Tag* parseXML(char *xml, int *count) {
    Tag *tags = malloc(MAX_SIZE * sizeof(Tag));
    int tag_count = 0;
    
    char *token = strtok(xml, "<");
    
    while(token != NULL) {
        if(token[0] != '/') {
            Tag tag;
            tag.name = strtok(token, " >");
            
            Attribute attributes[MAX_SIZE];
            int attribute_count = 0;
            char *attribute = strtok(NULL, " >");
            while(attribute != NULL) {
                char *equals = strchr(attribute, '=');
                if(equals != NULL) {
                    equals[0] = '\0'; // to separate attribute name and value
                    Attribute attr;
                    attr.name = attribute;
                    attr.value = equals + 1;
                    attributes[attribute_count] = attr;
                    attribute_count++;
                }
                attribute = strtok(NULL, " >");
            }
            tag.attributes = malloc(attribute_count * sizeof(Attribute));
            memcpy(tag.attributes, attributes, attribute_count * sizeof(Attribute));
            tag.attribute_count = attribute_count;
            
            char *value = strstr(token, ">");
            if(value != NULL) {
                value += 1; // to skip > character
                tag.value = value;
            }
            tags[tag_count] = tag;
            tag_count++;
        }
        token = strtok(NULL, "<");
    }
    *count = tag_count;
    return tags;
}

int main() {
    char xml[] = "<person name=\"John Smith\" age=\"30\" gender=\"male\">Hello World</person>";
    
    int count;
    Tag *tags = parseXML(xml, &count);
    
    for(int i = 0; i < count; i++) {
        printf("Tag: %s\n", tags[i].name);
        for(int j = 0; j < tags[i].attribute_count; j++) {
            printf("\t%s: %s\n", tags[i].attributes[j].name, tags[i].attributes[j].value);
        }
        printf("\tValue: %s\n", tags[i].value);
    }
    
    return 0;
}