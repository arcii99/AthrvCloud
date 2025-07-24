//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void sync_files(char *src_dir, char *dest_dir);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s source_directory destination_directory\n", argv[0]);
        exit(1);
    }

    char *src_dir = argv[1];
    char *dest_dir = argv[2];

    sync_files(src_dir, dest_dir);

    return 0;
}

void sync_files(char *src_dir, char *dest_dir) {
    DIR *src_dp = opendir(src_dir);
    DIR *dest_dp = opendir(dest_dir);

    if (!src_dp || !dest_dp) {
        printf("Error: directories could not be opened.\n");
        exit(1);
    }

    struct dirent *src_ep, *dest_ep;

    while ((src_ep = readdir(src_dp)) != NULL) {
        if ((strcmp(src_ep->d_name, ".") == 0) || (strcmp(src_ep->d_name, "..") == 0)) {
            continue;
        }

        char src_path[100];
        sprintf(src_path, "%s/%s", src_dir, src_ep->d_name);

        struct stat src_info;
        if (stat(src_path, &src_info) != 0) {
            printf("Error: could not get file information of %s.\n", src_path);
            exit(1);
        }

        int exists_in_dest = 0;

        while ((dest_ep = readdir(dest_dp)) != NULL) {
            if ((strcmp(dest_ep->d_name, ".") == 0) || (strcmp(dest_ep->d_name, "..") == 0)) {
                continue;
            }

            char dest_path[100];
            sprintf(dest_path, "%s/%s", dest_dir, dest_ep->d_name);

            struct stat dest_info;
            if (stat(dest_path, &dest_info) != 0) {
                printf("Error: could not get file information of %s.\n", dest_path);
                exit(1);
            }

            if (strcmp(src_ep->d_name, dest_ep->d_name) == 0) {
                exists_in_dest = 1;
                if (src_info.st_mtime > dest_info.st_mtime) {
                    // source file has been modified; update destination file
                    FILE *src_fp = fopen(src_path, "r");
                    FILE *dest_fp = fopen(dest_path, "w");

                    if (!src_fp || !dest_fp) {
                        printf("Error: could not open file.\n");
                        exit(1);
                    }

                    char buffer[100];
                    while (fgets(buffer, sizeof(buffer), src_fp)) {
                        fputs(buffer, dest_fp);
                    }

                    fclose(src_fp);
                    fclose(dest_fp);

                    printf("File %s updated.\n", dest_path);
                }
            }
        }

        rewinddir(dest_dp);

        if (!exists_in_dest) {
            // file does not exist in destination; copy it
            char cp_command[200];
            sprintf(cp_command, "cp %s %s", src_path, dest_dir);
            system(cp_command);

            printf("File %s copied to %s.\n", src_path, dest_dir);
        }
    }

    closedir(src_dp);
    closedir(dest_dp);

    printf("Synchronization complete.\n");
}