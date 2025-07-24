//FormAI DATASET v1.0 Category: System administration ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE); 
    }

    // Get file information
    struct stat fileStat;
    if(stat(argv[1],&fileStat) < 0)    
        exit(EXIT_FAILURE); 

    // Print file information
    printf("Information of the file: %s\n", argv[1]);
    printf("----------------------------------------------\n");
    printf("File size: \t\t%ld bytes\n",fileStat.st_size);
    printf("Number of links: \t%ld\n",fileStat.st_nlink);
    printf("File inode: \t\t%ld\n",fileStat.st_ino);

    // Get owner and group information
    struct passwd *pw = getpwuid(fileStat.st_uid);
    struct group *gr = getgrgid(fileStat.st_gid);
    printf("Owner:\t\t\t%s\n", pw->pw_name);
    printf("Group:\t\t\t%s\n", gr->gr_name);

    // Check if the file is executable
    if(fileStat.st_mode & S_IXUSR)
        printf("Execute permission: \tYes\n");
    else
        printf("Execute permission: \tNo\n");

    return 0;
}