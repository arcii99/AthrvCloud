//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: rigorous
#include <stdio.h>  
#include <dirent.h>  
#include <string.h>  
#include <sys/stat.h>  
  
void analyzeDisk(char *path, int depth) {  
    DIR *dir;  
    struct dirent *entry;  
    struct stat fileStat;  
    
    if (!(dir = opendir(path)))  
        return;  
    
    while ((entry = readdir(dir)) != NULL) {  
        if (entry->d_type == DT_DIR) {  
            char new_path[1024];  
            int len = snprintf(new_path, sizeof(new_path)-1, "%s/%s", path, entry->d_name);  
            new_path[len] = 0;  
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)  
                continue;  
            printf("%*s[%s]\n", depth, "", entry->d_name);  
            analyzeDisk(new_path, depth + 2);  
        } else {  
            char filePath[1024];  
            sprintf(filePath, "%s/%s", path, entry->d_name);  
            if (stat(filePath, &fileStat) < 0)  
                continue;  
            printf("%*s- %s (size: %d bytes)\n", depth, "", entry->d_name, fileStat.st_size);  
        }  
    }  
    closedir(dir);  
}  

int main(int argc, char** argv) {  
    char *path;  
    if (argc < 2) {  
        path = ".";  
    } else {  
        path = argv[1];  
    }  
    
    printf("Analyzing disk space for path: %s\n", path);  
    analyzeDisk(path, 0);  

    return 0;  
}