//FormAI DATASET v1.0 Category: File Synchronizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void sync_files(const char* dir1, const char* dir2) {
    DIR* dp1 = opendir(dir1);
    DIR* dp2 = opendir(dir2);
    if(dp1 == NULL || dp2 == NULL) {
        printf("Error opening directories\n");
        return;
    }
    struct dirent *entry1, *entry2; 
    struct stat stat1, stat2;
    while((entry1 = readdir(dp1)) != NULL) {
        char file1[1000], file2[1000];
        strcpy(file1, dir1);
        strcat(file1, "/");
        strcat(file1, entry1->d_name);
        if(stat(file1, &stat1) == -1) continue;
        if(S_ISDIR(stat1.st_mode)) continue;
        while((entry2 = readdir(dp2)) != NULL) {
            strcpy(file2, dir2);
            strcat(file2, "/");
            strcat(file2, entry2->d_name);
            if(stat(file2, &stat2) == -1) continue;
            if(S_ISDIR(stat2.st_mode)) continue;
            if(strcmp(entry1->d_name, entry2->d_name) == 0 && 
               stat1.st_size == stat2.st_size) {
                FILE* fp1 = fopen(file1, "rb");
                FILE* fp2 = fopen(file2, "rb");
                if(fp1 == NULL || fp2 == NULL) {
                    printf("Error opening files for read\n");
                    return;
                }
                char buffer1[1024], buffer2[1024];
                long long int n1, n2;
                do {
                    n1 = fread(buffer1, 1, 1024, fp1);
                    n2 = fread(buffer2, 1, 1024, fp2);
                    if(n1 != n2 || memcmp(buffer1, buffer2, n1)) {
                        fclose(fp1); fclose(fp2);
                        printf("File '%s' and '%s' are not in sync\n", 
                               file1, file2);
                        return;
                    }
                } while(n1 > 0);
                fclose(fp1); fclose(fp2);
            }
        }
        rewinddir(dp2);
    }
    closedir(dp1);
    closedir(dp2);
    printf("All files in '%s' and '%s' are in sync\n", dir1, dir2);
}

int main() {
    sync_files("dir1", "dir2");
    return 0;
}