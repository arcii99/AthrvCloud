//FormAI DATASET v1.0 Category: File Synchronizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILENAME 50

struct file {
    char* filename;
    int size;
    char* content;
};

struct client {
    char* name;
    int num_files;
    struct file files[MAX_FILES];
};

void sync_files(struct client* client1, struct client* client2) {
    int i, j;
    int match_found = 0;
    
    // Check for matching files
    for (i = 0; i < client1->num_files; i++) {
        for (j = 0; j < client2->num_files; j++) {
            if (strcmp(client1->files[i].filename, client2->files[j].filename) == 0) {
                // Match found, check file size
                if (client1->files[i].size == client2->files[j].size) {
                    // Same size, check contents
                    if (strcmp(client1->files[i].content, client2->files[j].content) != 0) {
                        // Contents are different, update client2's file
                        free(client2->files[j].content);
                        client2->files[j].content = strdup(client1->files[i].content);
                        printf("%s's %s was updated with %s's version\n", client2->name, client2->files[j].filename, client1->name);
                        match_found = 1;
                    }
                } else {
                    // Different size, update client2's file
                    free(client2->files[j].content);
                    client2->files[j].content = strdup(client1->files[i].content);
                    client2->files[j].size = client1->files[i].size;
                    printf("%s's %s was updated with %s's version\n", client2->name, client2->files[j].filename, client1->name);
                    match_found = 1;
                }
                break;
            }
        }
        if (match_found) {
            // Match found, move to next file
            match_found = 0;
        } else {
            // No match found, add file to client2's list
            client2->files[client2->num_files] = client1->files[i];
            client2->num_files++;
            printf("%s's %s was added to %s's list\n", client1->name, client1->files[i].filename, client2->name);
        }
    }
}

int main() {
    // Create two clients
    struct client client1 = { "Client1", 3, {{"File1.txt", 10, "Hello"}, {"File2.txt", 12, "This is file 2"}, {"File3.txt", 8, "Byebye"}} };
    struct client client2 = { "Client2", 2, {{"File1.txt", 8, "Hola"}, {"File4.txt", 20, "New file for client 2"}} };
    
    // Sync client1's files with client2's
    sync_files(&client1, &client2);

    // Sync client2's files with client1's
    sync_files(&client2, &client1);
    
    return 0;
}