//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// A structure to hold the XML tag information
struct XMLTag 
{
    int level; // The level of this tag in the document
    char* name; // The name of this tag
    char** attributes; // Array of attribute name-value pairs
    int num_attributes; // The number of attributes for this tag
    char* text; // The text (content) of this tag
    struct XMLTag* parent; // Pointer to the parent tag
    struct XMLTag** children; // Array of pointers to child tags
    int num_children; // The number of child tags for this tag
};

// Function to parse an XML string and return a root tag
struct XMLTag* parseXML(char* xml_string) 
{
    // Initialize variables
    int len = strlen(xml_string);
    int i = 0;
    int level = 0;
    int num_tags = 0;
    int capacity = 10; // Capacity for children array
    char tag_name[100];
    char attr_name[100];
    char attr_value[100];
    char text[1000];
    struct XMLTag* root = NULL;
    struct XMLTag** stack = malloc(sizeof(struct XMLTag*) * capacity);

    // Loop through the XML string
    while (i < len) 
    {
        // Check for start tag
        if (xml_string[i] == '<' && xml_string[i+1] != '/') 
        {
            // Allocate memory for new tag
            struct XMLTag* tag = malloc(sizeof(struct XMLTag));
            
            // Initialize tag attributes
            tag->level = level;
            tag->parent = stack[level-1];
            tag->num_attributes = 0;
            tag->text = NULL;
            tag->num_children = 0;
            tag->children = malloc(sizeof(struct XMLTag*) * capacity);
            
            // Parse tag name
            int j = 0;
            i++; // Skip '<'
            while (xml_string[i] != ' ' && xml_string[i] != '>') 
            {
                tag_name[j++] = xml_string[i++];
            }
            tag_name[j] = '\0';
            tag->name = strdup(tag_name);

            // Parse attributes
            while (xml_string[i] != '>') 
            {
                if (xml_string[i] == '/') 
                {
                    tag->text = "";
                    break;
                }
                if (isalpha(xml_string[i])) 
                {
                    j = 0;
                    while (xml_string[i] != '=') 
                    {
                        attr_name[j++] = xml_string[i++];
                    }
                    attr_name[j] = '\0';
                    i++; // Skip '='
                    j = 0;
                    while (xml_string[i] != '\"') 
                    {
                        i++;
                    }
                    i++; // Skip '\"'
                    while (xml_string[i] != '\"') 
                    {
                        attr_value[j++] = xml_string[i++];
                    }
                    attr_value[j] = '\0';

                    // Add attribute to tag
                    tag->attributes = realloc(tag->attributes, sizeof(char*) * (tag->num_attributes+1));
                    char* attr_str = malloc(strlen(attr_name) + strlen(attr_value) + 4);
                    sprintf(attr_str, "%s=\"%s\"", attr_name, attr_value);
                    tag->attributes[tag->num_attributes++] = attr_str;
                }
                i++;
            }

            // Add tag to parent
            if (stack[level-1] != NULL) 
            {
                stack[level-1]->children = realloc(stack[level-1]->children, sizeof(struct XMLTag*) * (stack[level-1]->num_children+1));
                stack[level-1]->children[stack[level-1]->num_children++] = tag;
            }

            // Push tag onto stack
            stack[level++] = tag;

            // Increase number of tags
            num_tags++;

            if (num_tags == 1) 
            {
                root = tag;
            }

            // Increase capacity if necessary
            if (level >= capacity) 
            {
                capacity *= 2;
                stack = realloc(stack, sizeof(struct XMLTag*) * capacity);
            }
        }
        // Check for end tag
        else if (xml_string[i] == '<' && xml_string[i+1] == '/') 
        {
            level--;
            i += 2; // Skip '</'
            int j = 0;
            while (xml_string[i] != '>') 
            {
                tag_name[j++] = xml_string[i++];
            }
            tag_name[j] = '\0';
            
            if (strcmp(tag_name, stack[level]->name) != 0) 
            {
                printf("Error: End tag '%s' does not match start tag '%s'\n", tag_name, stack[level]->name);
                exit(1);
            }
            
            // Set tag text
            if (stack[level]->text == NULL) 
            {
                int start = (stack[level-1]->children[stack[level-1]->num_children-1] == stack[level]) ? 0 : 1; // Check if tag has no attributes
                int end = (start == 0) ? i-2 : i-1; // Remove '>' or '/>' at end
                int len = end - start + 1;
                strncpy(text, xml_string+start, len);
                text[len] = '\0';
                stack[level]->text = strdup(text);
            }

            // Pop tag from stack
            free(stack[level]);

            // Decrease number of tags
            num_tags--;
        }
        // Check for text node
        else if (level > 0 && xml_string[i] != '\n') 
        {
            // Set tag text
            if (stack[level]->text == NULL) 
            {
                int start = i;
                while (xml_string[i] != '<') 
                {
                    i++;
                }
                int end = i-1;
                int len = end - start + 1;
                strncpy(text, xml_string+start, len);
                text[len] = '\0';
                stack[level]->text = strdup(text);
                i--; // Go back one character so the '<' is processed properly
            }
        }
        i++;
    }

    // Free stack memory
    free(stack);

    return root;
}

// A function to print an XML tag and all its children
void printXML(struct XMLTag* tag) 
{
    // Print tag and attributes
    for (int i = 0; i < tag->level; i++) 
    {
        printf("    ");
    }
    printf("<%s", tag->name);
    for (int i = 0; i < tag->num_attributes; i++) 
    {
        printf(" %s", tag->attributes[i]);
    }
    if (tag->text != NULL) 
    {
        printf(">%s</%s>", tag->text, tag->name);
    }
    else if (tag->num_children == 0) 
    {
        printf("/>");
    }
    else 
    {
        printf(">\n");
    }

    // Print children
    for (int i = 0; i < tag->num_children; i++) 
    {
        printXML(tag->children[i]);
    }

    // Print closing tag if necessary
    if (tag->num_children > 0 && tag->text == NULL) 
    {
        for (int i = 0; i < tag->level; i++) 
        {
            printf("    ");
        }
        printf("</%s>\n", tag->name);
    }
}

int main(void) 
{
    char* xml = "<document>\n"
                "    <header>\n"
                "        <title>Example Document</title>\n"
                "    </header>\n"
                "    <body>\n"
                "        <p>This is an example document.</p>\n"
                "        <ul>\n"
                "            <li>Item 1</li>\n"
                "            <li>Item 2</li>\n"
                "            <li>Item 3</li>\n"
                "        </ul>\n"
                "    </body>\n"
                "</document>\n";

    // Parse XML string
    struct XMLTag* root = parseXML(xml);

    // Print XML tree
    printXML(root);

    return 0;
}