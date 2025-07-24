//FormAI DATASET v1.0 Category: Browser Plugin ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This program is a simple C browser plugin that replaces all instances of the word "cat" with "dog" on a webpage. */

void replace_cat_with_dog(char *html);

int main()
{
    char html[1000];

    printf("Enter some HTML code:\n");
    fgets(html, sizeof(html), stdin);

    replace_cat_with_dog(html);

    printf("\nHere's your modified HTML:\n%s", html);

    return 0;
}

void replace_cat_with_dog(char *html)
{
    char *p, *q;
    char *temp = malloc(sizeof(char) * strlen(html));

    if (temp == NULL) {
        printf("Error: Unable to allocate memory\n");
        exit(1);
    }

    p = html;
    q = temp;

    while (*p != '\0') {
        if (strncmp(p, "cat", 3) == 0) {
            strcpy(q, "dog");
            p += 3;
            q += 3;
        } else {
            *q++ = *p++;
        }
    }

    *q = '\0';
    strcpy(html, temp);
    free(temp);
}