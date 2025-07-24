//FormAI DATASET v1.0 Category: System administration ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    struct stat st;
    int result = stat("/var/log/syslog", &st);
    
    if (result == 0) {
        printf("syslog file exists!\n");
        printf("size of syslog file: %ld bytes\n", st.st_size);
        printf("permissions of syslog file: %o\n", st.st_mode);
        
        if (S_ISREG(st.st_mode)) {
            printf("syslog file is a regular file.\n");
        } else if (S_ISDIR(st.st_mode)) {
            printf("syslog file is a directory.\n");
        }
        
        if (st.st_mode & S_IRUSR) {
            printf("owner can read the syslog file.\n");
        }
        if (st.st_mode & S_IWUSR) {
            printf("owner can write to the syslog file.\n");
        }
        if (st.st_mode & S_IXUSR) {
            printf("owner can execute the syslog file.\n");
        }
    } else {
        printf("syslog file does not exist.\n");
    }
    
    return 0;
}