//FormAI DATASET v1.0 Category: File Backup System ; Style: multiplayer
// sample code for the C File Backup System example program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXFILES 100
#define MAXFILENAME 50

struct file {
    char name[MAXFILENAME];
    char data[1024];
};

struct backup {
    int id;
    char name[MAXFILENAME];
    char data[1024];
};

struct backup backups[MAXFILES];
int backup_count = 0;

void backup_file(char* filename, char* data) {
    struct backup new_backup;
    new_backup.id = backup_count++;
    strcpy(new_backup.name, filename);
    strcpy(new_backup.data, data);
    backups[new_backup.id] = new_backup;
    printf("File backed up successfully.\n");
}

void send_backup(int s, char* filename) {
    char* data = "This is the backup data.";
    printf("Client %d is sending backup for %s.\n", s, filename);
    backup_file(filename, data);
}

void request_backup(int s, char* filename) {
    printf("Client %d is requesting backup for %s.\n", s, filename);
    // find the backup with the matching filename
    for (int i = 0; i < backup_count; i++) {
        if (strcmp(backups[i].name, filename) == 0) {
            // send the backup data to the client
            printf("Sending backup data to client %d.\n", s);
            printf("%s\n", backups[i].data);
            return;
        }
    }
    printf("Backup not found.\n");
}

int main() {
    send_backup(1, "example.txt");
    request_backup(2, "example.txt");
    return 0;
}