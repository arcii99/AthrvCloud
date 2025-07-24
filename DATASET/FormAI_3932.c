//FormAI DATASET v1.0 Category: System administration ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>
#include <sys/stat.h>

/* A program that displays file ownership and permissions */
int main(int argc, char *argv[]) {
    struct stat fileStats;
    struct passwd *pw;
    struct group *gr;
    mode_t mode;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (stat(argv[1], &fileStats) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    /* Print file permissions */
    mode = fileStats.st_mode;
    printf("Permissions: %lo\n", (unsigned long) mode);

    /* Print file owner and group */
    pw = getpwuid(fileStats.st_uid);
    gr = getgrgid(fileStats.st_gid);
    printf("Owner: %s (%u), Group: %s (%u)\n", pw->pw_name, fileStats.st_uid, gr->gr_name, fileStats.st_gid);

    return EXIT_SUCCESS;
}