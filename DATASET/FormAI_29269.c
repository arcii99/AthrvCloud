//FormAI DATASET v1.0 Category: File system simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DISK_SIZE 10240
#define SECTOR_SIZE 512
#define MAX_FILES 128
#define MAX_FILENAME 16

struct inode {
    int type;
    int size;
    int start_sector;
};

struct directory_entry {
    char name[MAX_FILENAME];
    int inode_idx;
};

char disk[DISK_SIZE];
struct inode inodes[MAX_FILES];
struct directory_entry directory[MAX_FILES];
int free_sectors_offset = 0;
int free_inodes_offset = 0;
int directory_count = 0;

void clear_sector(int sector_idx) {
    int start = sector_idx * SECTOR_SIZE;
    int end = start + SECTOR_SIZE;

    for (int i = start; i < end; i++) {
        disk[i] = 0;
    }
}

int find_free_sector() {
    int sector_idx = free_sectors_offset;
    free_sectors_offset++;
    clear_sector(sector_idx);
    return sector_idx;
}

int find_free_inode() {
    int inode_idx = free_inodes_offset;
    free_inodes_offset++;
    inodes[inode_idx].size = 0;
    return inode_idx;
}

int create_file(char* name, int type) {
    if (directory_count == MAX_FILES) {
        return -1;
    }

    int inode_idx = find_free_inode();
    if (inode_idx == -1) {
        return -1;
    }

    int sector_idx = find_free_sector();
    if (sector_idx == -1) {
        return -1;
    }

    inodes[inode_idx].type = type;
    inodes[inode_idx].start_sector = sector_idx;

    strcpy(directory[directory_count].name, name);
    directory[directory_count].inode_idx = inode_idx;

    directory_count++;

    return inode_idx;
}

int write_to_file(int inode_idx, char* data, int size) {
    if (inodes[inode_idx].type != 1) {
        return -1;
    }

    int start_sector = inodes[inode_idx].start_sector;
    int offset = inodes[inode_idx].size;
    int sector_offset = offset % SECTOR_SIZE;
    int data_offset = 0;
    int bytes_written = 0;

    while (bytes_written < size) {
        int sector_idx = start_sector + (offset / SECTOR_SIZE);
        int bytes_left = size - bytes_written;
        int bytes_to_write = bytes_left < SECTOR_SIZE ? bytes_left : SECTOR_SIZE - sector_offset;
        memcpy(&disk[sector_idx * SECTOR_SIZE + sector_offset], &data[data_offset], bytes_to_write);
        
        bytes_written += bytes_to_write;
        data_offset += bytes_to_write;
        offset += bytes_written;
        
        if (sector_offset + bytes_to_write == SECTOR_SIZE) {
            sector_offset = 0;
            start_sector++;
        }
        inodes[inode_idx].size += bytes_written;
    }

    return bytes_written;
}

int read_from_file(int inode_idx, char* data, int size, int offset) {
    if (inodes[inode_idx].type != 1) {
        return -1;
    }

    int start_sector = inodes[inode_idx].start_sector;
    int sector_offset = offset % SECTOR_SIZE;
    int data_offset = 0;
    int bytes_read = 0;

    while (bytes_read < size && start_sector < DISK_SIZE / SECTOR_SIZE) {
        int sector_idx = start_sector + (offset / SECTOR_SIZE);
        int bytes_left = size - bytes_read;
        int bytes_to_read = bytes_left < SECTOR_SIZE ? bytes_left : SECTOR_SIZE - sector_offset;
        memcpy(&data[data_offset], &disk[sector_idx * SECTOR_SIZE + sector_offset], bytes_to_read);

        bytes_read += bytes_to_read;
        data_offset += bytes_to_read;
        offset += bytes_to_read;

        if (sector_offset + bytes_to_read == SECTOR_SIZE) {
            sector_offset = 0;
            start_sector++;
        }
    }

    return bytes_read;
}

int main() {
    int file1_inode_idx = create_file("file1.txt", 1);
    int file2_inode_idx = create_file("file2.txt", 1);
    int dir_inode_idx = create_file("dir1", 2);

    char* data1 = "This is the content of file1.txt";
    write_to_file(file1_inode_idx, data1, strlen(data1));

    char* data2 = "This is the content of file2.txt";
    write_to_file(file2_inode_idx, data2, strlen(data2));

    int sub_dir_inode_idx = create_file("sub_dir1", 2);
    int sub_dir_file_inode_idx = create_file("file3.txt", 1);
    char* sub_dir_file_data = "This is the content of file3.txt";
    write_to_file(sub_dir_file_inode_idx, sub_dir_file_data, strlen(sub_dir_file_data));

    char buf[1024];
    read_from_file(file2_inode_idx, buf, 1024, 0);
    printf("Read from file2.txt: %s\n", buf);

    read_from_file(sub_dir_file_inode_idx, buf, 1024, 0);
    printf("Read from sub_dir1/file3.txt: %s\n", buf);

    return 0;
}