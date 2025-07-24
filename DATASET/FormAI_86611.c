//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: happy
#include<stdio.h>
#include<string.h>

int main() {
    char xml[] = "<person><name>John</name><age>32</age></person>";
    int i, j, k;
    char tag[100], content[100];
    printf("Input XML:\n%s\n",xml);
    printf("\nOutput:\n");
    for(i = 0; xml[i] != '\0'; i++) {
        if(xml[i] == '<') {
            k = 0;
            j = i + 1;
            while(xml[j] != '>') {
                tag[k] = xml[j];
                k++;
                j++;
            }
            tag[k] = '\0';
            i = j;
        }
        if(xml[i] == '>') {
            k = 0;
            j = i + 1;
            while(xml[j] != '<') {
                content[k] = xml[j];
                k++;
                j++;
            }
            content[k] = '\0';
            printf("\nTag: %s\n", tag);
            printf("Content: %s\n", content);
            i = j;
        }
    }
    return 0;
}