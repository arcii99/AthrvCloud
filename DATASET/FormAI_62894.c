//FormAI DATASET v1.0 Category: File Synchronizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void synchronize(char *src_path, char *dst_path){
    struct dirent *entry_src, *entry_dst;
    DIR *dir_src, *dir_dst;
    struct stat buf_src, buf_dst;
    char *src_file_path, *dst_file_path;
    int match_found = 0;
    
    // Open source directory
    if((dir_src = opendir(src_path)) == NULL){
        printf("Error opening source directory.\n");
        return;
    }
    
    // Open destination directory
    if((dir_dst = opendir(dst_path)) == NULL){
        printf("Error opening destination directory.\n");
        return;
    }
    
    // Traverse through files in source directory
    while((entry_src = readdir(dir_src)) != NULL){
        if(entry_src->d_name[0] == '.'){
            continue;
        }
        
        // Construct source file path
        src_file_path = (char *)malloc(sizeof(char) * (strlen(src_path) + strlen(entry_src->d_name) + 2));
        sprintf(src_file_path, "%s/%s", src_path, entry_src->d_name);
        
        // Get source file properties
        if(stat(src_file_path, &buf_src) == -1){
            printf("Error getting source file properties.\n");
            continue;
        }
        
        match_found = 0;
        
        // Traverse through files in destination directory
        rewinddir(dir_dst);
        while((entry_dst = readdir(dir_dst)) != NULL){
            if(entry_dst->d_name[0] == '.'){
                continue;
            }
            
            // Construct destination file path
            dst_file_path = (char *)malloc(sizeof(char) * (strlen(dst_path) + strlen(entry_dst->d_name) + 2));
            sprintf(dst_file_path, "%s/%s", dst_path, entry_dst->d_name);
            
            // Get destination file properties
            if(stat(dst_file_path, &buf_dst) == -1){
                printf("Error getting destination file properties.\n");
                continue;
            }
            
            // Check if source and destination files match
            if(strcmp(entry_src->d_name, entry_dst->d_name) == 0){
                if(buf_src.st_mtime > buf_dst.st_mtime){
                    // Source file is newer, copy to destination
                    printf("Copying %s to %s\n", entry_src->d_name, dst_path);
                    copy_file(src_file_path, dst_file_path);
                }else if(buf_src.st_mtime < buf_dst.st_mtime){
                    // Destination file is newer, copy to source
                    printf("Copying %s to %s\n", entry_dst->d_name, src_path);
                    copy_file(dst_file_path, src_file_path);
                }
                match_found = 1;
                free(dst_file_path);
                break;
            }
            
            free(dst_file_path);
        }
        
        if(!match_found){
            // File doesn't exist in destination directory, copy it
            printf("Copying %s to %s\n", entry_src->d_name, dst_path);
            dst_file_path = (char *)malloc(sizeof(char) * (strlen(dst_path) + strlen(entry_src->d_name) + 2));
            sprintf(dst_file_path, "%s/%s", dst_path, entry_src->d_name);
            copy_file(src_file_path, dst_file_path);
            free(dst_file_path);
        }
        
        free(src_file_path);
    }
    
    // Traverse through files in destination directory
    rewinddir(dir_dst);
    while((entry_dst = readdir(dir_dst)) != NULL){
        if(entry_dst->d_name[0] == '.'){
            continue;
        }
        
        match_found = 0;
        
        // Traverse through files in source directory
        rewinddir(dir_src);
        while((entry_src = readdir(dir_src)) != NULL){
            if(entry_src->d_name[0] == '.'){
                continue;
            }
            
            // Check if destination file exists in source directory
            if(strcmp(entry_dst->d_name, entry_src->d_name) == 0){
                match_found = 1;
                break;
            }
        }
        
        if(!match_found){
            // File doesn't exist in source directory, delete it
            printf("Deleting %s from %s\n", entry_dst->d_name, dst_path);
            dst_file_path = (char *)malloc(sizeof(char) * (strlen(dst_path) + strlen(entry_dst->d_name) + 2));
            sprintf(dst_file_path, "%s/%s", dst_path, entry_dst->d_name);
            remove(dst_file_path);
            free(dst_file_path);
        }
    }
    
    // Close directories
    closedir(dir_src);
    closedir(dir_dst);
}

void copy_file(char *src_path, char *dst_path){
    FILE *src_file, *dst_file;
    char buffer[1024];
    int bytes_read;
    
    // Open source file
    if((src_file = fopen(src_path, "rb")) == NULL){
        printf("Error opening source file.\n");
        return;
    }
    
    // Open destination file
    if((dst_file = fopen(dst_path, "wb")) == NULL){
        printf("Error opening destination file.\n");
        fclose(src_file);
        return;
    }
    
    // Copy file contents
    while((bytes_read = fread(buffer, 1, 1024, src_file)) > 0){
        fwrite(buffer, 1, bytes_read, dst_file);
    }
    
    // Close files
    fclose(src_file);
    fclose(dst_file);
}

int main(int argc, char **argv){
    if(argc != 3){
        printf("Usage: ./sync <src_path> <dst_path>\n");
        return 0;
    }
    
    synchronize(argv[1], argv[2]);
    
    return 0;
}