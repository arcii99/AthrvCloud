//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Person {
    char name[30];
    int age;
    char address[50];
};

void parseXML(char* xml) {
    struct Person p;
    char* token;

    token = strtok(xml, "<>"); // split xml into tokens based on tags

    while(token != NULL) {
        if(strcmp(token, "name") == 0) {
            token = strtok(NULL, "<>");
            strcpy(p.name, token);
        }
        else if(strcmp(token, "age") == 0) {
            token = strtok(NULL, "<>");
            p.age = atoi(token);
        }
        else if(strcmp(token, "address") == 0) {
            token = strtok(NULL, "<>");
            strcpy(p.address, token);
        }

        token = strtok(NULL, "<>");
    }

    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Address: %s\n", p.address);
}

int main() {
    char xml[] = "<person><name>John Doe</name><age>35</age><address>1234 Main Street</address></person>";

    parseXML(xml);

    return 0;
}