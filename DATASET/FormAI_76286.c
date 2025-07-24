//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int main()
{
    char xml[MAX_SIZE]; // stores the entire XML string

    // get the XML string from user input
    printf("Enter the XML string:\n");
    scanf("%[^\n]%*c", xml);

    int len = strlen(xml);
    int i = 0;

    while (i < len) {
        // get the next tag and its contents
        int j = i;
        while (xml[j] != '<' && j < len) j++;
        if (j == len) break;

        int k = j+1;
        while (xml[k] != '>' && k < len) k++;
        if (k == len) break;

        int tag_len = k-j-1;
        char tag[tag_len+1];
        strncpy(tag, &xml[j+1], tag_len);
        tag[tag_len] = '\0';

        int l = k+1;
        while (xml[l] != '<' && l < len) l++;
        if (l == len) break;

        int cont_len = l-k-1;
        char contents[cont_len+1];
        strncpy(contents, &xml[k+1], cont_len);
        contents[cont_len] = '\0';

        // print the tag and its contents
        printf("Tag: %s\n", tag);
        printf("Contents: %s\n", contents);

        i = l+1;
    }

    return 0;
}