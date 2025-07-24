//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: Linus Torvalds
#include <stdio.h>

#define MAX_SIZE 100

int main() {
    char xml_data[MAX_SIZE] = "<book><title>The Lord of the Rings</title><author>J.R.R. Tolkien</author></book>";
    char element[MAX_SIZE], content[MAX_SIZE];
    int i = 0, j = 0;

    printf("Parsing XML data:\n%s\n", xml_data);

    printf("Parsed elements:\n");

    while (xml_data[i] != '\0') {
        if (xml_data[i] == '<') {
            j = 0;
            i++;

            while (xml_data[i] != '>') {
                if (xml_data[i] == '/')
                    j = -1;
                else if (j >= 0) 
                    element[j++] = xml_data[i];

                i++;
            }

            element[j] = '\0';

            if (j > 0 && element[0] != '/') {
                printf("\t%s\n", element);
            }
        }

        i++;
    }

    return 0;
}