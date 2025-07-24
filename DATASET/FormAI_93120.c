//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

int get_size(char* path);

int main(int argc, char **argv) {
    if(argc<=1) {
        printf("Please provide a path to analyze!\n");
        return 1;
    }
    int size = get_size(argv[1]);
    printf("Total size of %s: %d bytes\n", argv[1], size);
    return 0;
}

int get_size(char* path) {
    int size = 0;
    DIR *d = opendir(path);
    if(!d) {
        printf("%s does not exist!\n", path);
        return -1;
    }
    struct dirent *dir;
    while((dir = readdir(d)) != NULL) {
        if(dir->d_type == DT_DIR && strcmp(dir->d_name,".")!=0 &&
           strcmp(dir->d_name,"..")!=0){
            char subpath[1000];
            sprintf(subpath, "%s/%s", path, dir->d_name);
            size += get_size(subpath);
        }
        else {
            struct stat buf;
            char filepath[1000];
            sprintf(filepath, "%s/%s", path, dir->d_name);
            stat(filepath, &buf);
            size += buf.st_size;
        }
    }
    closedir(d);
    return size;
}