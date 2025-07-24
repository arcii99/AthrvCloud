//FormAI DATASET v1.0 Category: File system simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Constants */
#define MAX_FILENAME_SIZE 50
#define MAX_DISK_SPACE 1024
#define MAX_FILE_COUNT 50
#define SECTOR_SIZE 16
#define MAX_SECTORS (MAX_DISK_SPACE / SECTOR_SIZE)

/* Used to store file information */
struct file {
    char name[MAX_FILENAME_SIZE];
    int size;
    int sectors[MAX_SECTORS];
};

/* Global Variables */
struct file files[MAX_FILE_COUNT];
int disk[MAX_DISK_SPACE];

/* Function Prototypes */
void init_disk();
void format_disk();
void create_file(char *name, int size);
void delete_file(char *name);
void read_file(char *name);
void write_file(char *name);
void list_files();
int find_empty_sector();
int find_file_index(char *name);

/*
 * Initializes the simulated disk space with random values.
 */
void init_disk() {
    int i;
    for (i = 0; i < MAX_DISK_SPACE; i++) {
        disk[i] = rand() % 256;
    }
}

/*
 * Clears all files from the simulated disk space.
 */
void format_disk() {
    int i, j;
    for (i = 0; i < MAX_FILE_COUNT; i++) {
        memset(files[i].name, 0, MAX_FILENAME_SIZE);
        files[i].size = 0;
        for (j = 0; j < MAX_SECTORS; j++) {
            files[i].sectors[j] = -1;
        }
    }
    memset(disk, 0, MAX_DISK_SPACE);
}

/*
 * Creates a new file on the simulated disk space.
 */
void create_file(char *name, int size) {
    int i;
    int index = find_file_index(name);
    if (index != -1) {
        printf("File already exists.\n");
        return;
    }
    index = find_empty_sector();
    if (index == -1) {
        printf("Disk is full.\n");
        return;
    }
    int sectors_needed = (size / SECTOR_SIZE) + ((size % SECTOR_SIZE) ? 1 : 0);
    if (sectors_needed > (MAX_SECTORS - 1)) {
        printf("File is too large.\n");
        return;
    }
    int sectors[sectors_needed];
    for (i = 0; i < sectors_needed; i++) {
        int sector = find_empty_sector();
        if (sector == -1) {
            printf("Disk is full.\n");
            return;
        }
        sectors[i] = sector;
    }
    struct file new_file;
    strcpy(new_file.name, name);
    new_file.size = size;
    memcpy(new_file.sectors, sectors, sizeof(sectors));
    files[index] = new_file;
    printf("File created.\n");
}

/*
 * Deletes a file from the simulated disk space.
 */
void delete_file(char *name) {
    int index = find_file_index(name);
    if (index == -1) {
        printf("File does not exist.\n");
        return;
    }
    int i, j;
    int *sectors = files[index].sectors;
    for (i = 0; i < MAX_SECTORS; i++) {
        if (sectors[i] == -1) {
            break;
        }
        for (j = 0; j < SECTOR_SIZE; j++) {
            disk[(sectors[i] * SECTOR_SIZE) + j] = 0;
        }
    }
    memset(&files[index], 0, sizeof(struct file));
    printf("File deleted.\n");
}

/*
 * Reads a file from the simulated disk space and prints its contents to stdout.
 */
void read_file(char *name) {
    int index = find_file_index(name);
    if (index == -1) {
        printf("File does not exist.\n");
        return;
    }
    int i, j;
    int *sectors = files[index].sectors;
    for (i = 0; i < MAX_SECTORS; i++) {
        if (sectors[i] == -1) {
            break;
        }
        for (j = 0; j < SECTOR_SIZE; j++) {
            putchar(disk[(sectors[i] * SECTOR_SIZE) + j]);
        }
    }
    putchar('\n');
}

/*
 * Writes to a file on the simulated disk space.
 */
void write_file(char *name) {
    int index = find_file_index(name);
    if (index == -1) {
        printf("File does not exist.\n");
        return;
    }
    int i, j;
    int *sectors = files[index].sectors;
    for (i = 0; i < MAX_SECTORS; i++) {
        if (sectors[i] == -1) {
            break;
        }
        for (j = 0; j < SECTOR_SIZE; j++) {
            disk[(sectors[i] * SECTOR_SIZE) + j] = getchar();
        }
    }
    printf("File saved.\n");
}

/*
 * Lists all files on the simulated disk space.
 */
void list_files() {
    int i, j;
    printf("Name\tSize (bytes)\n");
    for (i = 0; i < MAX_FILE_COUNT; i++) {
        if (strlen(files[i].name) == 0) {
            continue;
        }
        int size = files[i].size;
        printf("%s\t%d\n", files[i].name, size);
    }
}

/*
 * Helper function to find the first empty sector on the simulated disk space.
 * Returns the index of the sector, or -1 if no sectors are empty.
 */
int find_empty_sector() {
    int i, j;
    for (i = 0; i < MAX_SECTORS; i++) {
        if (disk[i * SECTOR_SIZE] == 0) {
            return i;
        }
    }
    return -1;
}

/*
 * Helper function to find the index of a file on the simulated disk space.
 * Returns the index of the file, or -1 if the file is not found.
 */
int find_file_index(char *name) {
    int i, j;
    for (i = 0; i < MAX_FILE_COUNT; i++) {
        if (strcmp(files[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

/*
 * Main function to handle user input and execute file system commands.
 */
int main() {
    srand(42); /* Seed the random number generator */
    init_disk();
    format_disk();
    while (1) {
        printf("> ");
        char command[10];
        scanf("%s", command);
        if (strcmp(command, "create") == 0) {
            char name[MAX_FILENAME_SIZE];
            int size;
            scanf("%s %d", name, &size);
            create_file(name, size);
        } else if (strcmp(command, "delete") == 0) {
            char name[MAX_FILENAME_SIZE];
            scanf("%s", name);
            delete_file(name);
        } else if (strcmp(command, "read") == 0) {
            char name[MAX_FILENAME_SIZE];
            scanf("%s", name);
            read_file(name);
        } else if (strcmp(command, "write") == 0) {
            char name[MAX_FILENAME_SIZE];
            scanf("%s", name);
            write_file(name);
        } else if (strcmp(command, "list") == 0) {
            list_files();
        } else if (strcmp(command, "format") == 0) {
            format_disk();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}