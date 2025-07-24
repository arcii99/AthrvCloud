//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>

int main() {
    struct statvfs vfs;
    if (statvfs("C:", &vfs) != 0) {
        perror("Error: Unable to get the disk information.");
        return EXIT_FAILURE;
    }
    else {
        printf("Disk information for C:\n");
        printf("========================\n\n");
        printf("Total disk space: %llu bytes\n", (unsigned long long)vfs.f_frsize * vfs.f_blocks);
        printf("Free disk space: %llu bytes\n\n", (unsigned long long)vfs.f_frsize * vfs.f_bfree);

        printf("Folder-wise disk space allocation:\n");
        printf("========================\n\n");
        printf("Folder Name\tTotal Space(bytes)\tFree Space(bytes)\n");

        FILE *df = popen("dir /s /a:-D /o:n C:", "r");
        if (!df) {
            perror("Error: Unable to fetch the directory information.");
            return EXIT_FAILURE;
        }
        char out[1024];
        while (fgets(out, sizeof(out), df) != NULL) {
            char* split = strtok(out, " ");
            int i = 0;
            char* folder_name;
            long long folder_size;
            while (split != NULL) {
                i++;
                if (i == 1) {
                    folder_name = split;
                }
                if (i == 2) {
                    folder_size = atoll(split);
                    break;
                }
                split = strtok(NULL, " ");
            }
            if (i == 2) {
                if (folder_size > 0) {
                    printf("%s\t%lld\t\t\t%lld\n", folder_name, folder_size, folder_size - ((unsigned long long)vfs.f_frsize * vfs.f_bfree));
                }
            }
        }
        pclose(df);
        return EXIT_SUCCESS;
    }
}