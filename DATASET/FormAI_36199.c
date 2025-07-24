//FormAI DATASET v1.0 Category: File Synchronizer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

#define MAX_SIZE 100

void sync_files(char *path1, char *path2);

int main(int argc, char *argv[]) {
    char path1[MAX_SIZE], path2[MAX_SIZE];

    printf("Enter the path of the first directory: ");
    scanf("%s", path1);

    printf("Enter the path of the second directory: ");
    scanf("%s", path2);

    sync_files(path1, path2);

    return 0;
}

void sync_files(char *path1, char *path2) {
    DIR *dir1, *dir2;
    struct dirent *entry1, *entry2;
    struct stat st1, st2;
    char path_buf1[MAX_SIZE], path_buf2[MAX_SIZE], tmp_path1[MAX_SIZE], tmp_path2[MAX_SIZE];
    int result;

    // open the first directory
    if ((dir1 = opendir(path1)) == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    // open the second directory
    if ((dir2 = opendir(path2)) == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    // read the first directory
    while ((entry1 = readdir(dir1)) != NULL) {
        if (entry1->d_name[0] == '.') continue; // skip hidden files

        snprintf(path_buf1, MAX_SIZE, "%s/%s", path1, entry1->d_name);
        snprintf(path_buf2, MAX_SIZE, "%s/%s", path2, entry1->d_name);

        // get the stats of the file in the first directory
        if (stat(path_buf1, &st1) != 0) {
            perror("stat");
            exit(EXIT_FAILURE);
        }

        // check if the file exists in the second directory
        if (stat(path_buf2, &st2) != 0) {
            // if it doesn't exist, copy the file over
            printf("Copying %s to %s\n", path_buf1, path_buf2);
            result = rename(path_buf1, path_buf2);
            if (result != 0) {
                perror("rename");
            }
            continue;
        }

        // if the file is a directory, recurse
        if (S_ISDIR(st1.st_mode)) {
            printf("Found directory %s, recursing\n", path_buf1);
            sync_files(path_buf1, path_buf2);
            continue;
        }

        // if the file has a different size, copy it over
        if (st1.st_size != st2.st_size) {
            printf("Copying %s to %s\n", path_buf1, path_buf2);
            result = rename(path_buf1, path_buf2);
            if (result != 0) {
                perror("rename");
            }
            continue;
        }

        // compare the files byte by byte
        FILE *file1, *file2;
        char byte1, byte2;
        int num_bytes = 0;

        file1 = fopen(path_buf1, "rb");
        file2 = fopen(path_buf2, "rb");

        while (!feof(file1) && !feof(file2)) {
            byte1 = fgetc(file1);
            byte2 = fgetc(file2);

            if (byte1 != byte2) {
                printf("Copying %s to %s\n", path_buf1, path_buf2);

                // create temporary paths to preserve original files
                snprintf(tmp_path1, MAX_SIZE, "%s.tmp", path_buf1);
                snprintf(tmp_path2, MAX_SIZE, "%s.tmp", path_buf2);
                result = rename(path_buf1, tmp_path1);
                if (result != 0) {
                    perror("rename");
                }
                result = rename(path_buf2, tmp_path2);
                if (result != 0) {
                    perror("rename");
                }

                // copy the new file over
                result = rename(tmp_path1, path_buf1);
                if (result != 0) {
                    perror("rename");
                }
                result = rename(tmp_path2, path_buf2);
                if (result != 0) {
                    perror("rename");
                }

                break;
            }

            num_bytes++;
        }

        if (feof(file1) != feof(file2)) {
            printf("Copying %s to %s\n", path_buf1, path_buf2);
            result = rename(path_buf1, path_buf2);
            if (result != 0) {
                perror("rename");
            }
        }

        fclose(file1);
        fclose(file2);
    }

    closedir(dir1);
    closedir(dir2);
}