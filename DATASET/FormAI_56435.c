//FormAI DATASET v1.0 Category: File system simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 1024
#define MAX_BLOCKS 512

typedef struct {
    char filename[256];
    int size;
    int offset;
} file_t;

typedef struct {
    int used;
    char data[BLOCK_SIZE];
} block_t;

typedef struct {
    block_t blocks[MAX_BLOCKS];
    int num_files;
    file_t files[MAX_BLOCKS];
} disk_t;

void init_disk(disk_t *disk) {
    int i;
    disk->num_files = 0;
    for (i = 0; i < MAX_BLOCKS; i++) {
        disk->blocks[i].used = 0;
        memset(disk->blocks[i].data, 0, BLOCK_SIZE);
    }
}

int alloc_block(disk_t *disk) {
    int i;
    for (i = 0; i < MAX_BLOCKS; i++) {
        if (!disk->blocks[i].used) {
            disk->blocks[i].used = 1;
            return i;
        }
    }
    return -1;
}

void free_block(disk_t *disk, int block_num) {
    disk->blocks[block_num].used = 0;
    memset(disk->blocks[block_num].data, 0, BLOCK_SIZE);
}

int create_file(disk_t *disk, char *filename) {
    int i;
    if (disk->num_files == MAX_BLOCKS) {
        printf("Error: too many files\n");
        return -1;
    }
    for (i = 0; i < disk->num_files; i++) {
        if (strcmp(disk->files[i].filename, filename) == 0) {
            printf("Error: file already exists\n");
            return -2;
        }
    }
    strncpy(disk->files[disk->num_files].filename, filename, 255);
    disk->files[disk->num_files].size = 0;
    disk->files[disk->num_files].offset = -1;
    disk->num_files++;
    return 0;
}

int delete_file(disk_t *disk, char *filename) {
    int i, j, found = 0;
    for (i = 0; i < disk->num_files; i++) {
        if (strcmp(disk->files[i].filename, filename) == 0) {
            found = 1;
            if (disk->files[i].offset != -1) {
                free_block(disk, disk->files[i].offset);
            }
            for (j = i; j < disk->num_files - 1; j++) {
                disk->files[j] = disk->files[j+1];
            }
            disk->num_files--;
            break;
        }
    }
    if (!found) {
        printf("Error: file not found\n");
        return -1;
    }
    return 0;
}

int write_file(disk_t *disk, char *filename, char *data, int size) {
    int i, j, found = 0, offset, block_num, bytes_left;
    for (i = 0; i < disk->num_files; i++) {
        if (strcmp(disk->files[i].filename, filename) == 0) {
            found = 1;
            if (disk->files[i].offset == -1) {
                offset = alloc_block(disk);
                if (offset == -1) {
                    printf("Error: not enough space\n");
                    return -2;
                }
                disk->files[i].offset = offset;
            } else {
                offset = disk->files[i].offset;
            }
            bytes_left = size;
            while (bytes_left > 0) {
                block_num = offset + (disk->files[i].size / BLOCK_SIZE);
                if (block_num >= MAX_BLOCKS) {
                    printf("Error: not enough space\n");
                    return -3;
                }
                if (disk->blocks[block_num].used == 0) {
                    offset = alloc_block(disk);
                    if (offset == -1) {
                        printf("Error: not enough space\n");
                        return -2;
                    }
                    disk->blocks[block_num].used = 1;
                    disk->files[i].size += BLOCK_SIZE;
                }
                j = disk->files[i].size % BLOCK_SIZE;
                if ((j + bytes_left) > BLOCK_SIZE) {
                    memcpy(&disk->blocks[block_num].data[j], data, BLOCK_SIZE - j);
                    bytes_left -= (BLOCK_SIZE - j);
                    data += (BLOCK_SIZE - j);
                    disk->files[i].size += (BLOCK_SIZE - j);
                } else {
                    memcpy(&disk->blocks[block_num].data[j], data, bytes_left);
                    bytes_left = 0;
                    disk->files[i].size += bytes_left;
                }
            }
            break;
        }
    }
    if (!found) {
        printf("Error: file not found\n");
        return -1;
    }
    return 0;
}

int read_file(disk_t *disk, char *filename, char *data, int size) {
    int i, j, found = 0, offset, block_num, bytes_left;
    for (i = 0; i < disk->num_files; i++) {
        if (strcmp(disk->files[i].filename, filename) == 0) {
            found = 1;
            if (disk->files[i].size > size) {
                printf("Error: buffer too small\n");
                return -2;
            }
            if (disk->files[i].offset == -1) {
                memset(data, 0, size);
                return 0;
            } else {
                offset = disk->files[i].offset;
            }
            bytes_left = disk->files[i].size;
            while (bytes_left > 0) {
                block_num = offset + (disk->files[i].size / BLOCK_SIZE);
                if (block_num >= MAX_BLOCKS) {
                    printf("Error: not enough space\n");
                    return -3;
                }
                j = disk->files[i].size % BLOCK_SIZE;
                if ((j + bytes_left) > BLOCK_SIZE) {
                    memcpy(data, &disk->blocks[block_num].data[j], BLOCK_SIZE - j);
                    bytes_left -= (BLOCK_SIZE - j);
                    data += (BLOCK_SIZE - j);
                } else {
                    memcpy(data, &disk->blocks[block_num].data[j], bytes_left);
                    bytes_left = 0;
                    data += bytes_left;
                }
            }
            break;
        }
    }
    if (!found) {
        printf("Error: file not found\n");
        return -1;
    }
    return 0;
}

int main() {
    disk_t disk;
    char data[1024];
    int ret;

    init_disk(&disk);

    create_file(&disk, "test1.txt");
    create_file(&disk, "test2.txt");

    ret = write_file(&disk, "test1.txt", "hello world", strlen("hello world"));
    if (ret != 0) {
        printf("Error: write_file failed\n");
        exit(1);
    }
    ret = write_file(&disk, "test2.txt", "1234567890", strlen("1234567890"));
    if (ret != 0) {
        printf("Error: write_file failed\n");
        exit(1);
    }

    ret = read_file(&disk, "test1.txt", data, 1024);
    if (ret != 0) {
        printf("Error: read_file failed\n");
        exit(1);
    }
    printf("test1.txt contents: %s\n", data);

    ret = read_file(&disk, "test2.txt", data, 1024);
    if (ret != 0) {
        printf("Error: read_file failed\n");
        exit(1);
    }
    printf("test2.txt contents: %s\n", data);

    delete_file(&disk, "test1.txt");
    delete_file(&disk, "test2.txt");

    return 0;
}