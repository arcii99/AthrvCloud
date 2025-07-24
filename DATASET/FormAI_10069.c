//FormAI DATASET v1.0 Category: File Backup System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char *src_dir, *dest_dir;
    char command[BUFFER_SIZE];
    int backup_count;
    
    if(argc != 3) {
        printf("Usage: %s [source directory] [destination directory]\n", argv[0]);
        exit(1);
    }
    
    src_dir = argv[1];
    dest_dir = argv[2];
    
    // create destination directory if it doesn't exist
    sprintf(command, "mkdir -p %s", dest_dir);
    system(command);
    
    // get number of backups in dest_dir
    sprintf(command, "ls %s | grep -c 'backup-'", dest_dir);
    FILE *fp = popen(command, "r");
    fgets(command, sizeof(command), fp);
    backup_count = atoi(command);
    pclose(fp);
    
    // create backup directory in dest_dir
    char backup_dir[BUFFER_SIZE];
    sprintf(backup_dir, "%s/backup-%d", dest_dir, backup_count+1);
    sprintf(command, "mkdir %s", backup_dir);
    system(command);
    
    // backup files from source directory
    sprintf(command, "cp -r %s %s", src_dir, backup_dir);
    system(command);
    
    // print success message
    printf("Backup of %s successful. %d backups now exist in %s.\n", src_dir, backup_count+1, dest_dir);
    
    return 0;
}