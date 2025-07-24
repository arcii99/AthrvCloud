//FormAI DATASET v1.0 Category: Data recovery tool ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct file {
    char name[20];
    int size;
};

struct file files[10];

void recoverData() {
    FILE *fp = fopen("backup.bin", "rb");
    int count;
    fread(&count, sizeof(int), 1, fp);
    fread(&files, sizeof(struct file), count, fp);
    printf("Recovered %d files:\n", count);
    for(int i=0; i<count; i++) {
        printf("%s (%d bytes)\n", files[i].name, files[i].size);
    }
    fclose(fp);
}

void saveData() {
    FILE *fp = fopen("backup.bin", "wb");
    int count = 0;
    for(int i=0; i<10; i++) {
        if(files[i].size > 0) count++;
    }
    fwrite(&count, sizeof(int), 1, fp);
    fwrite(&files, sizeof(struct file), count, fp);
    fclose(fp);
}

void printMenu() {
    printf("\n=====================\n");
    printf("C DATA RECOVERY TOOL\n");
    printf("=====================\n");
    printf("1. Create file\n");
    printf("2. Delete file\n");
    printf("3. Recover data from backup\n");
    printf("4. Exit\n");
}

int main() {
    char input[20];
    memset(&files, 0, sizeof(files));
    while(1) {
        printMenu();
        printf("Enter command: ");
        fgets(input, 20, stdin);
        if(strcmp(input, "1\n") == 0) {
            int found = 0;
            for(int i=0; i<10; i++) {
                if(files[i].size == 0) {
                    printf("Enter file name: ");
                    fgets(files[i].name, 20, stdin);
                    files[i].name[strcspn(files[i].name, "\n")] = 0;
                    printf("Enter file size: ");
                    fgets(input, 20, stdin);
                    files[i].size = atoi(input);
                    found = 1;
                    break;
                }
            }
            if(found==0) printf("No more space available!\n");
        }
        else if(strcmp(input, "2\n") == 0) {
            printf("Enter file name to be deleted: ");
            char name[20];
            fgets(name, 20, stdin);
            name[strcspn(name, "\n")] = 0;
            int found = 0;
            for(int i=0; i<10; i++) {
                if(strcmp(files[i].name, name) == 0) {
                    memset(&files[i], 0, sizeof(struct file));
                    printf("Deleted file %s\n", name);
                    found = 1;
                    break;
                }
            }
            if(found==0) printf("File not found!\n");
        }
        else if(strcmp(input, "3\n") == 0) {
            recoverData();
        }
        else if(strcmp(input, "4\n") == 0) {
            printf("Exiting program...\n");
            saveData();
            break;
        }
        else {
            printf("Invalid command\n");
        }
    }
    return 0;
}