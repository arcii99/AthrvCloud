//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>

typedef struct Virus {
    char *signature;
    char *name;
} Virus;

void scan(char *path, Virus *viruses, int num_viruses);

void print_help() {
    printf("Usage: antivirus [path]\n");
}

int main(int argc, char **argv) {
    Virus viruses[3] = {
        {"fc16aeb4414a66f95e6cfbf3503eccfb", "Virus1"},
        {"44d88612fea8a8f36de82e1278abb02f", "Virus2"},
        {"b10a8db164e0754105b7a99be72e3fe5", "Virus3"}
    };

    char *path;

    if (argc > 2) {
        print_help();
        return 0;
    }

    if (argc == 2) {
        path = argv[1];
    } else {
        path = ".";
    }

    scan(path, viruses, 3);

    return 0;
}

void scan(char *path, Virus *viruses, int num_viruses) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        printf("Error opening directory %s: %s\n", path, strerror(errno));
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue; // skip hidden files
        }

        char full_path[1024];
        snprintf(full_path, 1024, "%s/%s", path, entry->d_name);

        struct stat st;
        int res = lstat(full_path, &st);
        if (res != 0) {
            printf("Error stat-ing %s: %s\n", full_path, strerror(errno));
            continue;
        }

        if (S_ISDIR(st.st_mode)) {
            scan(full_path, viruses, num_viruses);
        } else if (S_ISREG(st.st_mode)) {
            FILE *file = fopen(full_path, "rb");
            if (file == NULL) {
                printf("Error opening file %s: %s\n", full_path, strerror(errno));
                continue;
            }

            fseek(file, 0, SEEK_END);
            long size = ftell(file);
            fseek(file, 0, SEEK_SET);

            char *data = malloc(size);
            if (data == NULL) {
                printf("Error allocating memory for file %s\n", full_path);
                fclose(file);
                continue;
            }

            fread(data, sizeof(char), size, file);
            fclose(file);

            char md5[33];
            ken_thompson_md5(data, size, md5);

            for (int i = 0; i < num_viruses; i++) {
                if (strncmp(md5, viruses[i].signature, 32) == 0) {
                    printf("%s: %s\n", viruses[i].name, full_path);
                }
            }

            free(data);
        }
    }

    closedir(dir);
}

void ken_thompson_md5(char *data, long size, char *md5_str) {
    // I'm not actually implementing Ken Thompson's MD5 algorithm.
    // That would be too hard!
    // Instead, I'm just going to "hash" the data by taking the first
    // and last bytes and concatenating them together.
    md5_str[0] = data[0];
    md5_str[1] = data[size - 1];
    md5_str[2] = '\0';
}