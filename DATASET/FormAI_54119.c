//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void sync_files(const char* dir1, const char* dir2)
{
    DIR *d1, *d2;
    struct dirent *ent1, *ent2;
    
    d1 = opendir(dir1);
    d2 = opendir(dir2);
    
    if (d1 && d2)
    {
        while ((ent1 = readdir(d1)) != NULL)
        {
            char path1[256];
            strcpy(path1, dir1);
            strcat(path1, "/");
            strcat(path1, ent1->d_name);
            
            while ((ent2 = readdir(d2)) != NULL)
            {
                char path2[256];
                strcpy(path2, dir2);
                strcat(path2, "/");
                strcat(path2, ent2->d_name);
                
                if (strcmp(ent1->d_name, ent2->d_name) == 0)
                {
                    FILE *f1, *f2;
                    f1 = fopen(path1, "rb");
                    f2 = fopen(path2, "rb");
                    
                    if (f1 && f2)
                    {
                        fseek(f1, 0L, SEEK_END);
                        int fsize1 = ftell(f1);
                        fseek(f1, 0L, SEEK_SET);
                        
                        fseek(f2, 0L, SEEK_END);
                        int fsize2 = ftell(f2);
                        fseek(f2, 0L, SEEK_SET);
                        
                        if (fsize1 != fsize2)
                        {
                            printf("WARNING: File size mismatch for %s\n", ent1->d_name);
                        }
                        else
                        {
                            char buf1[1024], buf2[1024];
                            int read1, read2;
                            
                            while ((read1 = fread(buf1, 1, sizeof(buf1), f1)) != 0 
                                   && (read2 = fread(buf2, 1, sizeof(buf2), f2)) != 0)
                            {
                                if (memcmp(buf1, buf2, read1) != 0)
                                {
                                    printf("WARNING: File content mismatch for %s\n", ent1->d_name);
                                    break;
                                }
                            }
                        }
                        
                        fclose(f1);
                        fclose(f2);
                    }
                    else
                    {
                        printf("WARNING: Cannot open %s\n", ent1->d_name);
                    }
                }
            }
            
            rewinddir(d2);
        }
    }
    else
    {
        printf("ERROR: Cannot open directories\n");
    }
    
    if (d1) closedir(d1);
    if (d2) closedir(d2);
}

int main()
{
    sync_files("dir1", "dir2");
    return 0;
}