//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

char *xml_parser(char *xml){
    char *tag;
    char *attr;
    int len = strlen(xml);
    int idx = 0;
    for(int i = 0; i < len; i++){
        if(xml[i] == '<'){
            i++;
            idx = i;
            while(xml[i] != '>'){
                i++;
            }
            tag = malloc(i - idx + 1);
            strncpy(tag, xml + idx, i - idx);
            tag[i - idx] = '\0';
            idx = i + 1;
            while(xml[i] != '<'){
                i++;
            }
            attr = malloc(i - idx + 1);
            strncpy(attr, xml + idx, i - idx);
            attr[i - idx] = '\0';
            printf("Tag: %s\n", tag);
            printf("Attributes: %s\n", attr);
            free(tag);
            free(attr);
        }
    }
}

int main(){
    char *xml = "<bookstore><book category=\"children\">Harry Potter</book></bookstore>";
    xml_parser(xml);
    return 0;
}