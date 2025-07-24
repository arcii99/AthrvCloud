//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char* argv[]){
    if(argc != 2){ //check if input folder is provided
        printf("Please enter folder path as input.\n");
        exit(1);
    }
    DIR *folder;
    struct dirent *entry;
    struct stat file_info;
    char path[1024]; //array to store the path of each file
    long long total_size = 0; //variable to store total size
    int file_count = 0; //variable to store total number of files
    if(folder = opendir(argv[1])){ //open the folder
        while(entry = readdir(folder)){ //read files in the folder
            sprintf(path, "%s/%s", argv[1], entry->d_name); //create the path of the file
            if(stat(path, &file_info) == 0){ //get information about the file
                if(S_ISREG(file_info.st_mode)){ //check if the file is regular
                    printf("File %s : size %lld bytes.\n", entry->d_name, file_info.st_size); //print file name and size
                    total_size += file_info.st_size; //add file size to total size
                    file_count++; //increment file count
                }
                else if(S_ISDIR(file_info.st_mode)){ //check if the file is a directory
                    printf("Directory %s\n", entry->d_name); //print directory name
                }
                else{ //if neither file nor directory
                    printf("%s is neither file nor directory.\n", entry->d_name); //print error message
                }
            }
            else{ //if cannot get information about file
                printf("Cannot get information about file %s.\n", entry->d_name); //print error message
            }
        }
        printf("\nTotal number of files : %d\n", file_count); //print total number of files
        printf("Total size of all regular files : %lld bytes.\n", total_size); //print total size of all regular files
        closedir(folder); //close the folder
    }
    else{ //if cannot open the folder
        printf("Error opening folder.\n"); //print error message
    }
    return 0;
}