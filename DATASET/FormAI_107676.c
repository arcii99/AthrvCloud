//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Struct to store information about XML tags
typedef struct {
    char* name;         //Name of the tag
    int level;          //Level of nesting
    char* attributes;   //Attributes of the tag
    char* content;      //Content of the tag
} xml_tag;

//Function to parse XML and call appropriate functions
void parse_xml(char* xml_data, int data_size);

//Function to handle found tags
void handle_tag(xml_tag* tag) {
    printf("Found tag: %s\n", tag->name);
    printf("Level of nesting: %d\n", tag->level);
    printf("Tag attributes: %s\n", tag->attributes);
    printf("Tag content: %s\n\n", tag->content);
}

//Function to read a tag's attributes
char* read_attributes(char* tag_str) {
    char* attributes = NULL;
    char* start_ptr;
    char* end_ptr;
    int i, attr_len;

    //Check if tag has attributes
    start_ptr = strstr(tag_str, " ");
    if(start_ptr == NULL) { // Tag has no attributes
        return NULL;
    } else {
        end_ptr = strstr(start_ptr, ">"); //End of open tag
        if(end_ptr == NULL) {
            printf("Invalid tag: %s\n", tag_str);
            return NULL;
        }
        attr_len = end_ptr - start_ptr;

        //Copy attribute string into allocated memory
        attributes = (char*) malloc (sizeof(char) * (attr_len+1));
        for(i=0; i<attr_len; i++) {
            attributes[i] = start_ptr[i];
        }
        attributes[attr_len] = '\0';
    }

    return attributes;
}

//Function to read a tag's content
char* read_content(char* tag_str, int tag_len) {
    char* content = NULL;
    char* start_ptr;
    char* end_ptr;
    int i, content_len;

    //Check if tag has content
    start_ptr = strstr(tag_str, ">"); //End of opening tag
    if(start_ptr == NULL) {
        printf("Invalid tag: %s\n", tag_str);
        return NULL;
    }
    start_ptr++; //Skip the '>' character

    end_ptr = strstr(tag_str, "</"); //Start of closing tag
    if(end_ptr == NULL) {
        printf("Invalid tag: %s\n", tag_str);
        return NULL;
    }
    content_len = end_ptr - start_ptr;

    //Copy content string into allocated memory
    content = (char*) malloc (sizeof(char) * (content_len+1));
    for(i=0; i<content_len; i++) {
        content[i] = start_ptr[i];
    }
    content[content_len] = '\0';

    return content;

}

//Function to read and parse individual tags
void read_tag(char* tag_str, int tag_len, int level) {
    xml_tag tag;
    char* start_ptr;
    char* end_ptr;
    int i, name_len;

    //Allocate memory for XML tag
    tag.name = NULL;
    tag.attributes = NULL;
    tag.content = NULL;

    tag.level = level;

    //Check if tag has attributes or content
    start_ptr = tag_str;
    end_ptr = tag_str+tag_len;

    //Read tag name
    if(start_ptr[0] == '<' && start_ptr[1] == '/') { //Closing tag
        start_ptr = start_ptr + 2; //Skip '</'
        name_len = end_ptr - start_ptr - 1; //Skip '>'
    } else { //Opening tag
        start_ptr++; //Skip '<'
        name_len = end_ptr - start_ptr;
    }
    tag.name = (char*) malloc(sizeof(char) * (name_len+1));
    for(i=0; i<name_len; i++) {
        tag.name[i] = start_ptr[i];
    }
    tag.name[name_len] = '\0';

    //Read tag attributes and content
    tag.attributes = read_attributes(tag_str);
    tag.content = read_content(tag_str, tag_len);

    //Call function to handle the tag
    handle_tag(&tag);

    //Free memory allocated for XML tag
    free(tag.name);
    if(tag.attributes != NULL)
        free(tag.attributes);
    if(tag.content != NULL)
        free(tag.content);
}

int main() {
    //Example XML data
    char* xml_data = "<catalog><book id='bk101'><author>Gambardella, Matthew</author><title>XML Developer's Guide</title><genre>Computer</genre><price>44.95</price><publish_date>2000-10-01</publish_date><description>An in-depth look at creating applications with XML.</description></book><book id='bk102'><author>Ralls, Kim</author><title>Midnight Rain</title><genre>Fantasy</genre><price>5.95</price><publish_date>2000-12-16</publish_date><description>A former architect battles corporate zombies, an evil sorceress, and her own childhood to become queen of the world.</description></book></catalog>";

    //Parse XML data
    parse_xml(xml_data, strlen(xml_data));

    return 0;
}

void parse_xml(char* xml_data, int data_size) {
    int i = 0;
    int level = 0;
    char tag_str[100] = ""; //Maximum tag length assumed to be 100 characters

    //Loop through XML data
    while(i<data_size) {
        //Check if a new tag has started
        if(xml_data[i] == '<') {
            //Store the current tag string
            if(tag_str[0] != '\0') { //Check if previous tag is complete
                read_tag(tag_str, strlen(tag_str), level);
                tag_str[0] = '\0';
            }
            level++;
        }

        //Append character to current tag string
        if(tag_str[0] == '\0' && xml_data[i] != '<') { //Skip any text before first tag
            i++;
            continue;
        } else {
            if(xml_data[i] == '>') { //End of tag string
                strcat(tag_str, ">");
            } else {
                strncat(tag_str, &xml_data[i], 1);
            }
        }

        //Check if current tag has ended
        if(xml_data[i] == '>') {
            level--;
        }

        i++;
    }

    //Handle last tag in XML data
    if(tag_str[0] != '\0') {
        read_tag(tag_str, strlen(tag_str), 1);
    }
}