//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: interoperable
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_LENGTH 100 // maximum length of each tag

// structure to hold information about each XML tag
typedef struct {
    char tag_name[MAX_LENGTH];
    char tag_value[MAX_LENGTH];
} xml_tag;

// function to parse the XML string and store tags in an array
int parse_xml(char *xml, xml_tag *tags) {
    char *start, *end, *ptr;
    int num_tags = 0;
    
    start = strchr(xml, '<'); // find first opening tag
    while (start) {
        end = strchr(start, '>'); // find corresponding closing tag
        if (!end) {
            return -1; // error: no closing tag found
        }
        ptr = strchr(start, '='); // check if tag has a value
        if (ptr && ptr < end) {
            // tag has a value
            strncpy(tags[num_tags].tag_name, start+1, ptr-start-1);
            strncpy(tags[num_tags].tag_value, ptr+2, end-ptr-3);
        }
        else {
            // tag is empty
            strncpy(tags[num_tags].tag_name, start+1, end-start-1);
            tags[num_tags].tag_value[0] = '\0';
        }
        num_tags++;
        start = strchr(end, '<'); // find next opening tag
    }
    return num_tags;
}

int main() {
    char xml[] = "<greeting>Hello world!</greeting><name value=\"John\">Doe</name><age>42</age>";
    xml_tag *tags = malloc(sizeof(xml_tag) * MAX_LENGTH);
    int num_tags = parse_xml(xml, tags);
    
    for (int i=0; i<num_tags; i++) {
        printf("Tag %d: Name='%s', Value='%s'\n", i+1, tags[i].tag_name, tags[i].tag_value);
    }
    
    free(tags);
    return 0;
}