//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct to store the parsed data */
typedef struct {
    char* name;
    char* description;
    int quantity;
} Item;

/* Parse an XML element */
int parseElement(char* element, char* data, Item* item) {
    if (strcmp(element, "name") == 0) {
        item->name = strdup(data);
    } else if (strcmp(element, "description") == 0) {
        item->description = strdup(data);
    } else if (strcmp(element, "quantity") == 0) {
        item->quantity = atoi(data);
    } else {
        return 0;
    }
    return 1;
}

/* Parse an XML file */
int parseXML(char* filename, Item** items, int* itemCount) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        return 0;
    }

    char line[1000];
    char* element;
    char* data;
    int parsingElement = 0;
    int parsingCloseElement = 0;
    int itemIndex = -1;

    while (fgets(line, sizeof(line), file)) {
        /* Ignore whitespace at the beginning and end of the line */
        char* start = line;
        while (*start == ' ' || *start == '\t' || *start == '\n' || *start == '\r') {
            start++;
        }
        char* end = start + strlen(start) - 1;
        while (*end == ' ' || *end == '\t' || *end == '\n' || *end == '\r') {
            *end-- = 0;
        }

        if (*start == '<' && *(end - 1) == '/' && *(end - 2) == '>') {
            /* Close element tag */
            if (parsingElement) {
                parsingCloseElement = 1;
            }
        } else if (*start == '<' && *(end - 1) == '>') {
            /* Open element tag */
            element = strdup(start + 1);
            *(end - 1) = 0;
            if (*(end - 2) == '/') {
                /* Self-closing element tag */
                if (parsingElement) {
                    parsingCloseElement = 1;
                }
            } else {
                parsingElement = 1;
                parsingCloseElement = 0;
            }
        } else {
            /* Data */
            if (parsingElement) {
                data = strdup(start);
                if (parseElement(element, data, &((*items)[itemIndex]))) {
                    free(element);
                    free(data);
                    parsingElement = 0;
                    if (parsingCloseElement) {
                        parsingCloseElement = 0;
                    } else {
                        itemIndex++;
                        *items = (Item*)realloc(*items, (itemIndex + 1) * sizeof(Item));
                        memset(&((*items)[itemIndex]), 0, sizeof(Item));
                    }
                }
            }
        }
    }

    *itemCount = itemIndex + 1;
    fclose(file);
    return 1;
}

/* Main function */
int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s xmlfile\n", argv[0]);
        return 1;
    }

    Item* items = NULL;
    int itemCount = 0;

    if (!parseXML(argv[1], &items, &itemCount)) {
        printf("Failed to parse XML file: %s\n", argv[1]);
        return 1;
    }

    printf("Parsed %d items from %s:\n", itemCount, argv[1]);
    for (int i = 0; i < itemCount; i++) {
        printf("  Item %d:\n", i + 1);
        printf("    Name: %s\n", items[i].name);
        printf("    Description: %s\n", items[i].description);
        printf("    Quantity: %d\n", items[i].quantity);
    }

    /* Cleanup */
    for (int i = 0; i < itemCount; i++) {
        free(items[i].name);
        free(items[i].description);
    }
    free(items);

    return 0;
}