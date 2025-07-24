//FormAI DATASET v1.0 Category: File Synchronizer ; Style: optimized
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

int sync_files(const char* source_dir, const char* dest_dir);

int main(int argc, char** argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <source_dir> <dest_dir>\n", argv[0]);
        return 1;
    }

    const char* source_dir = argv[1];
    const char* dest_dir = argv[2];

    int ret = sync_files(source_dir, dest_dir);

    if (ret == 0) {
        printf("Synchronization successful!\n");
    } else {
        fprintf(stderr, "Synchronization failed with error code %d: %s\n", ret, strerror(errno));
    }

    return 0;
}

int sync_files(const char* source_dir, const char* dest_dir) {

    DIR *source_dp = opendir(source_dir);
    DIR *dest_dp = opendir(dest_dir);

    if (source_dp == NULL || dest_dp == NULL) {
        return 1;
    }

    struct dirent *source_ep, *dest_ep;
    struct stat source_stbuf, dest_stbuf;
    int ret = 0;

    // Iterate over files and folders in source directory
    while ((source_ep = readdir(source_dp)) != NULL) {
        if (strcmp(source_ep->d_name, ".") == 0 || strcmp(source_ep->d_name, "..") == 0) {
            continue;
        }

        char source_path[FILENAME_MAX];
        snprintf(source_path, FILENAME_MAX, "%s/%s", source_dir, source_ep->d_name);

        // Get stats of file in the source directory
        if (stat(source_path, &source_stbuf) == -1) {
            fprintf(stderr, "Error getting stats of %s: %s\n", source_path, strerror(errno));
            continue;
        }

        // Check if file in source directory is a directory
        int is_dir = S_ISDIR(source_stbuf.st_mode);

        // Iterate over files and folders in destination directory
        while ((dest_ep = readdir(dest_dp)) != NULL) {
            if (strcmp(dest_ep->d_name, ".") == 0 || strcmp(dest_ep->d_name, "..") == 0) {
                continue;
            }

            char dest_path[FILENAME_MAX];
            snprintf(dest_path, FILENAME_MAX, "%s/%s", dest_dir, dest_ep->d_name);

            // Get stats of file in the destination directory
            if (stat(dest_path, &dest_stbuf) == -1) {
                fprintf(stderr, "Error getting stats of %s: %s\n", dest_path, strerror(errno));
                continue;
            }

            // Check if file in destination directory is a directory
            int dest_is_dir = S_ISDIR(dest_stbuf.st_mode);

            // Compare file names
            int cmp = strcmp(source_ep->d_name, dest_ep->d_name);

            if (cmp == 0 && is_dir && dest_is_dir) {
                // Synchronize subdirectories recursively
                ret |= sync_files(source_path, dest_path);
                break;
            } else if (cmp == 0 && !is_dir && !dest_is_dir && source_stbuf.st_size == dest_stbuf.st_size) {
                // Compare file contents and update if different
                FILE* source_fp = fopen(source_path, "r");
                FILE* dest_fp = fopen(dest_path, "r");

                if (source_fp == NULL || dest_fp == NULL) {
                    ret |= 1;
                    break;
                }

                int ch1, ch2;
                int diff_flag = 0;

                while ((ch1 = getc(source_fp)) != EOF && (ch2 = getc(dest_fp)) != EOF) {
                    if (ch1 != ch2) {
                        diff_flag = 1;
                        break;
                    }
                }

                if ((ch1 == EOF && ch2 != EOF) || (ch1 != EOF && ch2 == EOF)) {
                    diff_flag = 1;
                }

                fclose(source_fp);
                fclose(dest_fp);

                if (diff_flag) {
                    // Update destination file
                    FILE* fp = fopen(dest_path, "w");

                    if (fp == NULL) {
                        ret |= 1;
                        break;
                    }

                    source_fp = fopen(source_path, "r");
                    if (source_fp == NULL) {
                        fclose(fp);
                        ret |= 1;
                        break;
                    }

                    while ((ch1 = getc(source_fp)) != EOF) {
                        putc(ch1, fp);
                    }

                    fclose(source_fp);
                    fclose(fp);
                }
                break;
            } else if (cmp > 0) {
                // Source file not found in destination directory, copy from source
                FILE* source_fp = fopen(source_path, "r");

                if (source_fp == NULL) {
                    ret |= 1;
                    break;
                }

                FILE* dest_fp = fopen(dest_path, "w");

                if (dest_fp == NULL) {
                    fclose(source_fp);
                    ret |= 1;
                    break;
                }

                int ch;

                while ((ch = getc(source_fp)) != EOF) {
                    putc(ch, dest_fp);
                }

                fclose(dest_fp);
                fclose(source_fp);
                break;
            }
        } // End of inner loop

        if (dest_ep == NULL) {
            // Source file not found in destination directory, copy from source
            char dest_path[FILENAME_MAX];
            snprintf(dest_path, FILENAME_MAX, "%s/%s", dest_dir, source_ep->d_name);

            FILE* source_fp = fopen(source_path, "r");

            if (source_fp == NULL) {
                ret |= 1;
                continue;
            }

            FILE* dest_fp = fopen(dest_path, "w");

            if (dest_fp == NULL) {
                fclose(source_fp);
                ret |= 1;
                continue;
            }

            int ch;

            while ((ch = getc(source_fp)) != EOF) {
                putc(ch, dest_fp);
            }

            fclose(dest_fp);
            fclose(source_fp);
        }

        rewinddir(dest_dp);
    } // End of outer loop

    closedir(source_dp);
    closedir(dest_dp);

    return ret;
}