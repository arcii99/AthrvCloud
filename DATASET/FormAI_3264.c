//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: shocked
#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<unistd.h>

#define KB 1024
#define MB (1024*KB)
#define GB (1024*MB)

/*Function to calculate Total size of a directory*/
long long calculate_directory_size(const char *directory_path)
{
    long long directory_size = 0;
    DIR *dir;
    struct dirent *dir_entry;
    struct stat file_stat;

    dir = opendir(directory_path);

    if(dir == NULL)
    {
        printf("Error opening directory\n");
        return -1;
    }

    while((dir_entry = readdir(dir)) != NULL)
    {
        if(dir_entry->d_type == DT_DIR)   /*If entry is Directory*/
        {
            char new_path[1000];
            sprintf(new_path, "%s/%s", directory_path, dir_entry->d_name);
            if(strcmp(dir_entry->d_name, ".") == 0 || strcmp(dir_entry->d_name, "..") == 0)
            {
                continue;
            }
            directory_size += calculate_directory_size(new_path);

        }
        else if(dir_entry->d_type == DT_REG)  /*If entry is Regular File*/
        {
            char new_path[1000];
            sprintf(new_path, "%s/%s", directory_path, dir_entry->d_name);
            stat(new_path, &file_stat);
            directory_size += file_stat.st_size;
        }
    }
    closedir(dir);

    return directory_size;
}

int main(int argc, char **argv)
{
    char *dir_path;
    long long total_size = 0;
    int opt;
    while((opt = getopt(argc, argv, "d:")) != -1)
    {
        switch(opt)
        {
            case 'd':
            {
                dir_path = optarg;
                total_size = calculate_directory_size(dir_path);
                break;
            }
            default:
            {
                printf("Invalid option\n");
            }
        }
    }

    /*Printing Results*/
    printf("\nTotal Size of %s: \n", dir_path);
    if(total_size > GB)
    {
        printf("%lld GB\n", total_size/GB);
    }
    else if(total_size > MB)
    {
        printf("%lld MB\n", total_size/MB);
    }
    else
    {
        printf("%lld KB\n", total_size/KB);
    }
    return 0;
}