//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: portable
#include <stdio.h>
#include <string.h>
#include <dirent.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [directory]\n", argv[0]);
        return 1;
    }
    DIR *dir;
    struct dirent *entry;
    char buf[BUFSIZE];
    dir = opendir(argv[1]);
    if (!dir) {
        printf("Cannot open directory '%s'\n", argv[1]);
        return 2;
    }
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            sprintf(buf, "%s/%s", argv[1], entry->d_name);
            FILE *f = fopen(buf, "rb");
            if (!f) continue;
            fseek(f, 0, SEEK_END);
            long fsize = ftell(f);
            fseek(f, 0, SEEK_SET);
            char *data = malloc(fsize + 1);
            fread(data, fsize, 1, f);
            fclose(f);
            data[fsize] = '\0';
            if(strstr(data, "virus")) {
                printf("'%s' is infected\n", entry->d_name);
            } else {
                printf("'%s' is clean\n", entry->d_name);
            }
            free(data);
        }
    }
    closedir(dir);
    return 0;
}