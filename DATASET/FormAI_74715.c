//FormAI DATASET v1.0 Category: System administration ; Style: accurate
#include <stdio.h>  
#include <stdlib.h>  
#include <sys/types.h>  
#include <sys/stat.h>  
#include <unistd.h>  

int main(void) {  
    int result;  
    struct stat buf;  
    
    /* Get the file status */  
    result = stat("/var/log/syslog", &buf);  
    
    /* Print the file access and modification times */  
    printf("Access time: %s", ctime(&buf.st_atime));  
    printf("Modification time: %s", ctime(&buf.st_mtime));  
    
    /* Display whether the file is a directory */  
    if(S_ISDIR(buf.st_mode))  
        printf("This is a directory.\n");  
    else  
        printf("This is not a directory.\n");  
    
    /* Change the file permissions */  
    result = chmod("/var/log/syslog", S_IRUSR|S_IWUSR);  
    
    /* Display the new file permissions */  
    result = stat("/var/log/syslog", &buf);  
    printf("New permissions: %o", buf.st_mode & 0777);  
    
    /* Create a new hard link */  
    result = link("/var/log/syslog", "/root/syslog");  
    
    /* Print success or failure */  
    if(result == 0)  
        printf("Hard link created successfully.\n");  
    else  
        printf("Failed to create hard link.\n");  
    
    return 0;  
}