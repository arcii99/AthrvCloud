//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARACTERS 1000

typedef struct{
    char tag[20];
    char attribute[20];
    char value[50];
} tag_t;

int main(){
    char xml_data[MAX_CHARACTERS];
    FILE *fp;
    tag_t tags[MAX_CHARACTERS];
    int tag_ctr = 0;
    int i = 0;
    
    fp = fopen("example.xml", "r");

    if(fp == NULL){
        printf("Error opening file\n");
        return -1;
    }

    while(fgets(xml_data, MAX_CHARACTERS, fp) != NULL){
        char *pos1, *pos2;
        char tag_value[20];
        char attribute_value[20];
        char value_value[50];

        // Check for start tag
        if(strstr(xml_data, "<") != NULL && strstr(xml_data, "<") == xml_data){
            pos1 = strstr(xml_data, "<") + 1;
            pos2 = strstr(xml_data, ">");
            if(pos1 == pos2){
                printf("Error: Invalid tag\n");
                return -1;
            }
            strncpy(tag_value, pos1, pos2 - pos1);
            tag_value[pos2 - pos1] = '\0';
            strcpy(tags[tag_ctr].tag, tag_value);
            
            // Check for attributes
            if(strstr(xml_data, " ") != NULL && strstr(xml_data, " ") < pos2){
                char *pos3 = strstr(xml_data, " ");
                char *pos4;
                while(pos3 < pos2){
                    pos3 += 1;
                    pos4 = strstr(pos3, "=");
                    if(pos4 < pos2){
                        strncpy(attribute_value, pos3, pos4 - pos3);
                        attribute_value[pos4 - pos3] = '\0';
                        strcpy(tags[tag_ctr].attribute, attribute_value);
                        pos4 += 1;
                        pos3 = strchr(pos4, '"') + 1;
                        strcpy(value_value, pos4);
                        value_value[strchr(pos4, '"') - pos4] = '\0';
                        strcpy(tags[tag_ctr].value, value_value);
                    }
                    pos3 = strchr(pos3, ' ');
                }
            }
            tag_ctr++;
        }
        // Check for end tag
        if(strstr(xml_data, "</") != NULL){
            pos1 = strstr(xml_data, "</") + 2;
            pos2 = strstr(xml_data, ">");
            strncpy(tag_value, pos1, pos2 - pos1);
            tag_value[pos2 - pos1] = '\0';
            if(strcmp(tags[tag_ctr - 1].tag, tag_value) == 0){
                tag_ctr--;
            }
            else{
                printf("Error: Invalid end tag\n");
                return -1;
            }
        }
    }
    
    fclose(fp);
    
    // Print out the tag values
    for(i = 0; i < tag_ctr; i++){
        printf("Tag: %s\n", tags[i].tag);
        printf("Attribute: %s\n", tags[i].attribute);
        printf("Value: %s\n\n", tags[i].value);
    }
    
    return 0;
}