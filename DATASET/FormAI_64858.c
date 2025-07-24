//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1024 //Maximum length of strings that will be extracted

//Structure definition for storing metadata key-value pairs
typedef struct metadata_pair_t {
    char key[MAX_STR_LEN];
    char value[MAX_STR_LEN];
    struct metadata_pair_t *next; //Pointer to next metadata pair in linked list
} metadata_pair;

//Function to create a new metadata pair
metadata_pair* createMetadataPair(char* key, char* value) {
    metadata_pair* pair = (metadata_pair*) malloc(sizeof(metadata_pair));
    strncpy(pair->key, key, MAX_STR_LEN);
    strncpy(pair->value, value, MAX_STR_LEN);
    pair->next = NULL;
    return pair;
}

//Function to add a metadata pair to the linked list
void addMetadataPair(metadata_pair** head, metadata_pair* pair) {
    if (*head == NULL) {
        *head = pair;
    } else {
        metadata_pair* curr = *head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = pair;
    }
}

//Function to extract metadata from a character buffer
metadata_pair* extractMetadata(char* text, char* delimiter) {
    metadata_pair* head = NULL;
    char* line = strtok(text, "\n");
    while (line != NULL) {
        char* key = strtok(line, delimiter);
        char* value = strtok(NULL, delimiter);
        if (key != NULL && value != NULL) {
            metadata_pair* pair = createMetadataPair(key, value);
            addMetadataPair(&head, pair);
        }
        line = strtok(NULL, "\n");
    }
    return head;
}

//Test program
int main() {
    char text[] = "Title: My Cool Video\nAuthor: John Doe\nDuration: 180\n";
    metadata_pair* metadata = extractMetadata(text, ": ");
    metadata_pair* curr = metadata;

    //Print all the key-value pairs
    while (curr != NULL) {
        printf("%s: %s\n", curr->key, curr->value);
        curr = curr->next;
    }

    //Free memory
    curr = metadata;
    while (curr != NULL) {
        metadata_pair* temp = curr;
        curr = curr->next;
        free(temp);
    }
    return 0;
}