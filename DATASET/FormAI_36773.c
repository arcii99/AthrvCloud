//FormAI DATASET v1.0 Category: System administration ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        exit(1);
    }

    char* directory = argv[1];
    int status = chdir(directory);

    if (status == -1) {
        printf("Error: cannot change directory to %s\n", directory);
        exit(1);
    }

    struct stat st;
    stat(".", &st);

    printf("Permissions for %s:\n", directory);

    printf("User (owner) permissions:\n");
    printf("Read: %s\n", (st.st_mode & S_IRUSR) ? "Yes" : "No");
    printf("Write: %s\n", (st.st_mode & S_IWUSR) ? "Yes" : "No");
    printf("Execute: %s\n", (st.st_mode & S_IXUSR) ? "Yes" : "No");

    printf("Group permissions:\n");
    printf("Read: %s\n", (st.st_mode & S_IRGRP) ? "Yes" : "No");
    printf("Write: %s\n", (st.st_mode & S_IWGRP) ? "Yes" : "No");
    printf("Execute: %s\n", (st.st_mode & S_IXGRP) ? "Yes" : "No");

    printf("Other permissions:\n");
    printf("Read: %s\n", (st.st_mode & S_IROTH) ? "Yes" : "No");
    printf("Write: %s\n", (st.st_mode & S_IWOTH) ? "Yes" : "No");
    printf("Execute: %s\n", (st.st_mode & S_IXOTH) ? "Yes" : "No");

    return 0;
}