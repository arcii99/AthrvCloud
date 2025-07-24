//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ATTRIBUTES 16

/* Struct to hold parsed XML element data */
typedef struct {
    char *name;
    char *value;
    int num_attributes;
    char *attribute_names[MAX_ATTRIBUTES];
    char *attribute_values[MAX_ATTRIBUTES];
} XmlElement;

/* Function prototypes */
char *trim_whitespace(char *str);
int parse_xml(char *xml_str, XmlElement **elements, int max_elements);
int parse_element(char *element_str, XmlElement *element);
int parse_attributes(char *attr_str, XmlElement *element);

/* Main program */
int main() {
    char xml_input[] = "<person name=\"John Smith\"><address><street>123 Main St</street><city>Anytown</city><state>CA</state><zip>12345</zip></address><phone type=\"home\">555-1234</phone><phone type=\"work\">555-4321</phone></person>";
    XmlElement *elements[10]; // Maximum of 10 elements allowed
    int num_elements;

    // Parse the XML input
    num_elements = parse_xml(xml_input, elements, 10);

    // Print out the parsed elements
    for (int i = 0; i < num_elements; i++) {
        printf("<%s", elements[i]->name);
        for (int j = 0; j < elements[i]->num_attributes; j++) {
            printf(" %s=\"%s\"", elements[i]->attribute_names[j], elements[i]->attribute_values[j]);
        }
        printf(">");

        if (elements[i]->value) {
            printf("%s", elements[i]->value);
        }

        printf("</%s>\n", elements[i]->name);
    }

    // Free memory allocated for XmlElement structs
    for (int i = 0; i < num_elements; i++) {
        free(elements[i]->name);
        free(elements[i]->value);
        for (int j = 0; j < elements[i]->num_attributes; j++) {
            free(elements[i]->attribute_names[j]);
            free(elements[i]->attribute_values[j]);
        }
        free(elements[i]);
    }

    return 0;
}

/**
 * Parses an XML string and returns an array of parsed elements.
 * @param xml_str The XML string to parse.
 * @param elements A pointer to an array of XmlElement pointers to be filled in by this function.
 * @param max_elements The maximum number of elements to parse.
 * @return The number of elements parsed.
 */
int parse_xml(char *xml_str, XmlElement **elements, int max_elements) {
    char *p = xml_str;
    char *q;

    int num_elements = 0;

    // Loop through the XML string, looking for elements
    while (*p && num_elements < max_elements) {
        if (*p == '<' && *(p+1) != '/') {
            q = strchr(p+1, '>');
            if (q) {
                // Create a new XmlElement struct and parse the element
                elements[num_elements] = malloc(sizeof(XmlElement));
                if (parse_element(p, elements[num_elements]) == 0) {
                    num_elements++;
                } else {
                    free(elements[num_elements]);
                }
                p = q+1;
            } else {
                p++;
            }
        } else {
            p++;
        }
    }

    return num_elements;
}

/**
 * Parses an XML element string and fills in an XmlElement struct with the parsed data.
 * @param element_str The XML element string to parse.
 * @param element A pointer to an XmlElement struct to fill in with the parsed data.
 * @return 0 if successful, non-zero if there was an error.
 */
int parse_element(char *element_str, XmlElement *element) {
    char *p = element_str;
    char *q;

    // Parse the element name
    p++;
    q = strchr(p, ' ');

    if (!q) {
        q = strchr(p, '>');
    }

    if (q) {
        element->name = malloc((q-p+1)*sizeof(char));
        strncpy(element->name, p, q-p);
        element->name[q-p] = '\0';
    } else {
        return -1;
    }

    // Parse the attributes
    if (parse_attributes(q+1, element) != 0) {
        return -1;
    }

    // Find the element value (if any)
    p = strchr(q, '>') + 1;
    q = strstr(p, "</");
    if (q) {
        *q = '\0'; // Null-terminate the element value
        element->value = trim_whitespace(p);
        *q = '<';
    } else {
        element->value = NULL;
    }

    return 0;
}

/**
 * Parses an XML attribute string and fills in an XmlElement struct with the parsed attribute data.
 * @param attr_str The XML attribute string to parse.
 * @param element A pointer to an XmlElement struct to fill in with the parsed attribute data.
 * @return 0 if successful, non-zero if there was an error.
 */
int parse_attributes(char *attr_str, XmlElement *element) {
    char *p = attr_str;
    char *q;

    element->num_attributes = 0;

    // Loop through the attribute string, looking for attributes
    while (*p && *p != '>') {
        while (isspace(*p)) p++; // Skip whitespace

        if (*p == '/') return 0; // No attributes

        if (*p == '<' || *p == '>') {
            return -1;
        }

        q = strchr(p, '=');
        if (!q) {
            return -1;
        }

        element->attribute_names[element->num_attributes] = malloc((q-p+1)*sizeof(char));
        strncpy(element->attribute_names[element->num_attributes], p, q-p);
        element->attribute_names[element->num_attributes][q-p] = '\0';

        p = q+1;
        while (isspace(*p) || *p == '\"') p++; // Skip quotes and whitespace

        q = strchr(p, '\"');
        if (!q) {
            return -1;
        }

        element->attribute_values[element->num_attributes] = malloc((q-p+1)*sizeof(char));
        strncpy(element->attribute_values[element->num_attributes], p, q-p);
        element->attribute_values[element->num_attributes][q-p] = '\0';

        element->num_attributes++;

        p = q+1;
    }

    return 0;
}

/**
 * Trims leading and trailing whitespace from a string and returns a pointer to the trimmed string.
 * @param str The string to trim.
 * @return A pointer to the trimmed string.
 */
char *trim_whitespace(char *str) {
    // Trim leading whitespace
    while (isspace(*str)) {
        str++;
    }

    // Trim trailing whitespace
    char *p = str + strlen(str)-1;
    while (isspace(*p)) {
        *p = '\0';
        p--;
    }

    return str;
}