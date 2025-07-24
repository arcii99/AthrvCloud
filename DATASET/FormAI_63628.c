//FormAI DATASET v1.0 Category: File Backup System ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define MAX_FILE_NAME_SIZE 256
#define MAX_BACKUP_FILE_NAME_SIZE 512

void create_backup(char *file_name, char *backup_file_name) {
    char cmd[1024];
    sprintf(cmd, "cp %s %s", file_name, backup_file_name);
    system(cmd);
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Please pass the filename as an argument\n");
        return 1;
    }
    char *file_name = argv[1];
    char backup_file_name[MAX_BACKUP_FILE_NAME_SIZE];

    time_t current_time;
    char backup_path[256];
    getcwd(backup_path, sizeof(backup_path));
    sprintf(backup_file_name, "%s/%s.bak", backup_path, file_name);

    create_backup(file_name, backup_file_name);

    return 0;
}