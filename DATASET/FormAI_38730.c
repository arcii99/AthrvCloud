//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// A structure for storing the XML element
struct XML_Element {
  char tag[50];
  int num_attributes;
  char** attribute_key;
  char** attribute_value;
  char content[100];
  struct XML_Element* child;
  struct XML_Element* sibling;
};

// A utility function to create a new XML_Element
struct XML_Element* createXMLElement(char* tag) {
  struct XML_Element* new_element = (struct XML_Element*)malloc(sizeof(struct XML_Element));
  strcpy(new_element->tag, tag);
  new_element->num_attributes = 0;
  new_element->attribute_key = NULL;
  new_element->attribute_value = NULL;
  new_element->child = NULL;
  new_element->sibling = NULL;
  return new_element;
}

// A utility function to add an attribute to an XML_Element
void addAttribute(struct XML_Element* element, char* key, char* value) {
  int num_attributes = element->num_attributes;
  element->num_attributes++;
  element->attribute_key = (char**)realloc(element->attribute_key, sizeof(char*)*element->num_attributes);
  element->attribute_value = (char**)realloc(element->attribute_value, sizeof(char*)*element->num_attributes);
  element->attribute_key[num_attributes] = (char*)malloc(sizeof(char)*strlen(key));
  element->attribute_value[num_attributes] = (char*)malloc(sizeof(char)*strlen(value));
  strcpy(element->attribute_key[num_attributes], key);
  strcpy(element->attribute_value[num_attributes], value);
}

// A utility function to parse the XML file and build the XML tree
struct XML_Element* parseXML(char* xml_string) {
  struct XML_Element* root_element = NULL;
  struct XML_Element* current_element = NULL;
  char* token;

  // strtok() function is used to split a string into tokens based on the given delimiter
  token = strtok(xml_string, "<>"); // Tokenize the first element

  while (token != NULL) {
    if (token[0] == '?') { // Skip the processing instructions
      token = strtok(NULL, "<>");
      continue;
    }
    if (token[0] == '!') { // Skip the comments
      token = strtok(NULL, "<>");
      continue;
    }
    if (token[0] == '/') { // End of an element
      current_element = current_element->sibling;
      token = strtok(NULL, "<>");
      continue;
    }
    if (root_element == NULL) { // Create the root element
      root_element = createXMLElement(token);
      current_element = root_element;
    }
    else { // Create a child element
      struct XML_Element* child_element = createXMLElement(token);
      if (current_element->child == NULL) {
        current_element->child = child_element;
      }
      else {
        struct XML_Element* sibling_element = current_element->child;
        while (sibling_element->sibling != NULL) {
          sibling_element = sibling_element->sibling;
        }
        sibling_element->sibling = child_element;
      }
      current_element = child_element;
    }
    // Tokenize the attributes
    token = strtok(NULL, "<>");
    while (strcmp(token, "/") != 0 && strcmp(token, "?") != 0 && strcmp(token, "!") != 0) {
      char* key = token;
      token = strtok(NULL, "<>");
      char* value = token;
      addAttribute(current_element, key, value);
      token = strtok(NULL, "<>");
    }
    // Tokenize the content
    token = strtok(NULL, "<>");
    strcpy(current_element->content, token);
    token = strtok(NULL, "<>");
  }

  return root_element;
}

// A utility function to print an XML_Element
void printXMLElement(struct XML_Element* element) {
  printf("<%s", element->tag);
  for (int i = 0; i < element->num_attributes; i++) {
    printf(" %s=\"%s\"", element->attribute_key[i], element->attribute_value[i]);
  }
  printf(">");
  if (strlen(element->content) > 0) {
    printf("%s", element->content);
  }
  if (element->child != NULL) {
    printf("\n");
    struct XML_Element* child_element = element->child;
    while (child_element != NULL) {
      printXMLElement(child_element);
      child_element = child_element->sibling;
    }
    printf("</%s>", element->tag);
  }
  else {
    printf("</%s>\n", element->tag);
  }
}

int main() {
  // An example XML string
  char xml_string[] = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
                      "<root>"
                        "<element key1=\"value1\" key2=\"value2\">Content1</element>"
                        "<element key1=\"value1\" key2=\"value2\">Content2</element>"
                      "</root>";

  // Parse the XML string and build the XML tree
  struct XML_Element* root_element = parseXML(xml_string);

  // Print the XML tree
  printXMLElement(root_element);

  // Free the memory used for the XML tree
  free(root_element);

  return 0;
}