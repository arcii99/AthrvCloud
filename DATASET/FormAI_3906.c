//FormAI DATASET v1.0 Category: System administration ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <directory to chmod>\n", argv[0]);
        return 1;
    }

    const char* dir_path = argv[1];

    // Change directory permissions to 755
    if (chmod(dir_path, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH) == -1) {
        perror("chmod");
        return 1;
    }

    printf("Permissions for %s set to 755.\n", dir_path);

    // Change file ownership to root
    if (chown(dir_path, 0, 0) == -1) {
        perror("chown");
        return 1;
    }

    printf("Ownership for %s set to root.\n", dir_path);

    return 0;
}