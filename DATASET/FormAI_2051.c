//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENT 100
#define MAX_ATTR 10
#define MAX_LENGTH 100

// Structure for the attribute
typedef struct {
    char name[MAX_LENGTH]; 
    char value[MAX_LENGTH]; 
} Attribute;

// Structure for the element
typedef struct{
    char type; // '0' for text, '1' for opening tag, '2' for closing tag
    union {
        char text[MAX_LENGTH]; // text data
        char name[MAX_LENGTH]; // tag name
    };
    Attribute attr[MAX_ATTR]; // array of attributes
    int num_attr; // number of attributes
} Element;

// Function to parse the XML file
void parse(Element *e, char *fileName){
    FILE *f;
    char buffer[MAX_LENGTH];
    char temp[MAX_LENGTH];
    int i=0, j=0, k=0, l=0, m=0;

    // Open the file
    f = fopen(fileName, "r");

    // Read the file character by character
    while((buffer[i] = fgetc(f)) != EOF){
        
        // Check if we have encountered a tag
        if(buffer[i] == '<'){
            
            // Check if it is an opening tag
            if(buffer[i+1] != '/'){
                
                // Set the type of the element to opening tag
                e[j].type = '1';

                // Move to the next character after the '<'
                i++;

                // Get the name of the tag
                while(buffer[i] != ' ' && buffer[i] != '>'){
                    e[j].name[k] = buffer[i];
                    i++;
                    k++;
                }

                // Null terminate the name string
                e[j].name[k] = '\0';

                // Reset the attribute and attribute count
                e[j].num_attr = 0;
                k = 0;
                m = 0;

                // Parse the attributes of the tag
                while(buffer[i] != '>'){
                    if(buffer[i] != ' '){

                        // Get the attribute name
                        while(buffer[i] != '='){
                            temp[l] = buffer[i];
                            i++;
                            l++;
                        }
                        temp[l] = '\0';
                        strcpy(e[j].attr[m].name, temp);
                        l = 0;

                        // Move past the equal sign
                        i++;

                        // Get the attribute value
                        while(buffer[i] != '"' && buffer[i] != '\''){
                            i++;
                        }
                        i++;
                        while(buffer[i] != '"' && buffer[i] != '\''){
                            e[j].attr[m].value[l] = buffer[i];
                            i++;
                            l++;
                        }
                        e[j].attr[m].value[l] = '\0';
                        l = 0;
                        m++;
                        e[j].num_attr++;
                    }
                    i++;
                }

                // Move to the next element
                j++;
                k = 0;
            }
            
            // Check if it is a closing tag
            else {
                
                // Set the type of the element to closing tag
                e[j].type = '2';

                // Move past the '<' and '/'
                i += 2;

                // Get the name of the closing tag
                while(buffer[i] != '>'){
                    e[j].name[k] = buffer[i];
                    i++;
                    k++;
                }

                // Null terminate the name string
                e[j].name[k] = '\0';

                // Move to the next element
                j++;
                k = 0;
            }
        }
        
        // Check if we have encountered text
        else if(buffer[i] != '\n' && buffer[i] != ' ' && buffer[i] != '\t'){
            
            // Set the type of the element to text
            e[j].type = '0';

            // Get the text data
            while(buffer[i] != '<'){
                e[j].text[k] = buffer[i];
                i++;
                k++;
            }

            // Null terminate the text string
            e[j].text[k] = '\0';

            // Move to the next element
            j++;
            k = 0;
        }

        // Move to the next character
        i++;
    }

    // Close the file
    fclose(f);
}

// Function to print the parsed XML data
void print(Element *e, int numElements){
    int i, j;

    for(i=0; i<numElements; i++){
        printf("Type: %c\n", e[i].type);
        printf("Name: %s\n", e[i].name);

        for(j=0; j<e[i].num_attr; j++){
            printf("Attribute Name: %s\n", e[i].attr[j].name);
            printf("Attribute Value: %s\n", e[i].attr[j].value);
        }

        if(e[i].type == '0'){
            printf("Text Data: %s\n", e[i].text);
        }

        printf("\n");
    }
}

// Main function
int main(){
    Element elements[MAX_ELEMENT];
    int numElements = 0;

    // Parse the XML file
    parse(elements, "example.xml");

    // Count the number of elements
    while(elements[numElements].type != '\0'){
        numElements++;
    }

    // Print the parsed data
    print(elements, numElements);

    return 0;
}