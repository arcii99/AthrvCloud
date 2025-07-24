//FormAI DATASET v1.0 Category: System boot optimizer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BOOT_SECTOR_SIZE 512
#define MBR_SIGNATURE_OFFSET 510

typedef struct boot_sector {
    char data[BOOT_SECTOR_SIZE];
} BootSector;

typedef struct mbr_partition_entry {
    char boot_flag; // 0x80 if bootable, 0x00 otherwise
    char chs_start[3]; // Cylinder-head-sector start
    char partition_type;
    char chs_end[3]; // Cylinder-head-sector end
    int lba_start; // Logical block address start
    int num_sectors;
} MBRPartitionEntry;

typedef struct mbr {
    char bootstrap[446];
    MBRPartitionEntry partitions[4];
    short signature; // Should be 0xAA55
} MBR;

bool is_optimized(BootSector* boot_sector) {
    // Check if boot sector header is valid
    if (boot_sector->data[0] != 0xEB && boot_sector->data[0] != 0xE9) {
        return false;
    }
    // Check if volume label is present
    if (strncmp(&boot_sector->data[43], "NO NAME", 7) != 0) {
        return false;
    }
    // Check if file system type is FAT16 or FAT32
    if (strncmp(&boot_sector->data[54], "FAT16", 5) != 0 && strncmp(&boot_sector->data[54], "FAT32", 5) != 0) {
        return false;
    }
    return true;
}

int main(int argc, char *argv[]) {
    // Load boot sector from file
    FILE *boot_sector_file;
    BootSector boot_sector;
    boot_sector_file = fopen("boot_sector.bin", "rb");
    if (boot_sector_file == NULL) {
        perror("Error opening boot sector file ");
        exit(EXIT_FAILURE);
    }
    fread(&boot_sector, sizeof(boot_sector), 1, boot_sector_file);
    fclose(boot_sector_file);

    // Check if boot sector is already optimized
    if (is_optimized(&boot_sector)) {
        printf("Boot sector is already optimized\n");
        exit(EXIT_SUCCESS);
    }

    // Load MBR from file
    FILE *mbr_file;
    MBR mbr;
    mbr_file = fopen("mbr.bin", "rb");
    if (mbr_file == NULL) {
        perror("Error opening MBR file ");
        exit(EXIT_FAILURE);
    }
    fread(&mbr, sizeof(mbr), 1, mbr_file);
    fclose(mbr_file);

    // Modify boot sector
    boot_sector.data[0] = 0xEB; // Set jump instruction to short jump
    memset(&boot_sector.data[3], 0x90, 10); // Add NOP instructions
    boot_sector.data[13] = 0x10; // Set number of sectors per cluster to 16
    boot_sector.data[36] = 0x04; // Set number of FATs to 2
    boot_sector.data[38] = 0x20; // Set number of root directory entries to 32
    boot_sector.data[43] = 'N'; // Set volume label to "NO NAME"

    // Modify MBR partition entry
    mbr.partitions[0].boot_flag = 0x00; // Set first partition as non-bootable

    // Save modified boot sector and MBR to file
    boot_sector_file = fopen("boot_sector_opt.bin", "wb");
    if (boot_sector_file == NULL) {
        perror("Error opening boot sector file ");
        exit(EXIT_FAILURE);
    }
    fwrite(&boot_sector, sizeof(boot_sector), 1, boot_sector_file);
    fclose(boot_sector_file);

    mbr_file = fopen("mbr_opt.bin", "wb");
    if (mbr_file == NULL) {
        perror("Error opening MBR file ");
        exit(EXIT_FAILURE);
    }
    fwrite(&mbr, sizeof(mbr), 1, mbr_file);
    fclose(mbr_file);

    // Add MBR signature
    unsigned short* signature = (unsigned short*) &mbr;
    signature[MBR_SIGNATURE_OFFSET / sizeof(unsigned short)] = 0xAA55;

    printf("Boot sector and MBR optimized successfully\n");

    return 0;
}