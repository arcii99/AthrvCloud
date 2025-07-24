//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

void main() {
    char folder[] = "C:\\";
    unsigned long long totalSize = 0;
    unsigned long long totalFiles = 0;
    unsigned long long totalFolders = 0;
    unsigned long long foldersize;
    char file[260];
    char cmd[260];
    sprintf(cmd, "dir %s /s > foldersize.txt", folder);
    system(cmd);
    FILE *fp = fopen("foldersize.txt", "r");
    while (fgets(file, 260, fp)) {
        sscanf(file, "%lld File(s) %lld bytes", &totalFiles, &foldersize);
        if (totalFiles == 0) {
            sscanf(file, " Directory of %s", file);
            printf("Folder: %s\n", file);
            totalFolders++;
        }
        else {
            totalSize += foldersize;
        }
    }
    fclose(fp);
    remove("foldersize.txt");
    printf("Total Files: %lld\n", totalFiles);
    printf("Total Folders: %lld\n", totalFolders);
    printf("Total Size: %lld bytes\n", totalSize);
}