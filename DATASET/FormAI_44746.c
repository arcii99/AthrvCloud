//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_SIZE 100

struct list {
    char *name;
    struct list *next;
};

int main() {
    struct list *clusters[26];
    char data[MAX_DATA_SIZE];

    for(int i=0; i<26; i++) {
        clusters[i] = NULL;
    }

    printf("Enter data items one by one (Enter 'done' when finished):\n");

    while(1) {
        printf("Enter data item: ");
        fgets(data, MAX_DATA_SIZE, stdin);
        strtok(data, "\n");

        if(strcmp(data, "done") == 0) {
            break;
        }

        char first_char = data[0];

        struct list *new_node = (struct list*) malloc(sizeof(struct list));
        new_node->name = (char*) malloc(sizeof(char)*(strlen(data)+1));
        strcpy(new_node->name, data);
        new_node->next = NULL;

        if(clusters[first_char-'a'] == NULL) {
            clusters[first_char-'a'] = new_node;
        } else {
            struct list *current_node = clusters[first_char-'a'];
            while(current_node->next != NULL) {
                current_node = current_node->next;
            }
            current_node->next = new_node;
        }
    }

    printf("Clustered data:\n");

    for(int i=0; i<26; i++) {
        if(clusters[i] != NULL) {
            printf("%c: ", i+'a');
            struct list *current_node = clusters[i];
            while(current_node != NULL) {
                printf("%s ", current_node->name);
                current_node = current_node->next;
            }
            printf("\n");
        }
    }

    return 0;
}