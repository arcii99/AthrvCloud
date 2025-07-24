//FormAI DATASET v1.0 Category: System boot optimizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define BOOT_SECTOR_SIZE 512 // Boot Sector size for the file system
#define BYTE_SIZE 8 // Byte size in bits

// Boot sector data structure
typedef struct {
    uint8_t jump[3]; // JMP instruction to boot code
    uint8_t oem_name[8]; // OEM name and version
    uint16_t bytes_per_sector; // Number of bytes per sector
    uint8_t sectors_per_cluster; // Number of sectors per cluster
    uint16_t reserved_sectors; // Number of reserved sectors
    uint8_t number_of_fats; // Number of FAT tables
    uint16_t max_root_entries; // Maximum number of root directory entries
    uint16_t total_sectors; // Total number of sectors in the file system
    uint8_t media_descriptor; // Media descriptor
    uint16_t sectors_per_fat; // Number of sectors per FAT table
    uint16_t sectors_per_track; // Number of sectors per track
    uint16_t number_of_heads; // Number of heads or surfaces
    uint32_t hidden_sectors; // Number of hidden sectors before the partition
    uint32_t total_sectors_big; // Total number of sectors for a large file system
    uint8_t drive_number; // Drive number for BIOS
    uint8_t reserved; // Reserved for Windows NT
    uint8_t boot_signature; // Boot Signature (0x29)
    uint32_t volume_id; // Volume ID number
    uint8_t volume_label[11]; // Volume label
    uint8_t file_system_type[8]; // File system type
    uint8_t boot_code[BOOT_SECTOR_SIZE-62]; // Boot code if needed  
} BootSector;

// Check if the boot signature is valid
bool is_boot_signature_valid(const BootSector* boot_sector) {
    return boot_sector->boot_signature == 0x29;
}

// Convert number of sectors to bytes
uint32_t sectors_to_bytes(const BootSector* boot_sector, uint32_t sectors) {
    return sectors * boot_sector->bytes_per_sector;
}

// Convert number of bytes to sectors
uint32_t bytes_to_sectors(const BootSector* boot_sector, uint32_t bytes) {
    return bytes / boot_sector->bytes_per_sector;
}

// Center the boot code of the boot sector
void center_boot_code(BootSector* boot_sector) {
    uint16_t padding = BOOT_SECTOR_SIZE - 62;
    uint16_t offset = padding/2;
    
    for(uint16_t i=0; i<padding; i++) {
        if(i+offset < BOOT_SECTOR_SIZE-62) {
            boot_sector->boot_code[i+offset] = boot_sector->boot_code[i];
        } else {
            boot_sector->boot_code[i+offset] = 0x00;
        }
    }
}

// Print the boot sector details
void print_boot_sector_details(const BootSector* boot_sector) {
    printf("--- Boot Sector Details ---\n");
    printf("OEM Name: %s\n", boot_sector->oem_name);
    printf("Bytes per sector: %d\n", boot_sector->bytes_per_sector);
    printf("Sectors per cluster: %d\n", boot_sector->sectors_per_cluster);
    printf("Reserved sectors: %d\n", boot_sector->reserved_sectors);
    printf("Number of FATs: %d\n", boot_sector->number_of_fats);
    printf("Max root entries: %d\n", boot_sector->max_root_entries);
    printf("Total sectors: %d\n", boot_sector->total_sectors);
    printf("Media descriptor: 0x%x\n", boot_sector->media_descriptor);
    printf("Sectors per FAT: %d\n", boot_sector->sectors_per_fat);
    printf("Sectors per track: %d\n", boot_sector->sectors_per_track);
    printf("Number of heads: %d\n", boot_sector->number_of_heads);
    printf("Hidden sectors: %d\n", boot_sector->hidden_sectors);
    printf("Total sectors big: %d\n", boot_sector->total_sectors_big);
    printf("Drive number: 0x%x\n", boot_sector->drive_number);
    printf("Reserved: %d\n", boot_sector->reserved);
    printf("Boot signature: 0x%x\n", boot_sector->boot_signature);
    printf("Volume ID: %d\n", boot_sector->volume_id);
    printf("Volume label: %s\n", boot_sector->volume_label);
    printf("File system type: %s\n", boot_sector->file_system_type);
    printf("Boot code: \n");
    for(uint16_t i=0; i<BOOT_SECTOR_SIZE-62; i++) {
        printf("%x ", boot_sector->boot_code[i]);
    }
    printf("\n");
}

int main() {
    // Read from boot sector file
    FILE* file = fopen("boot_sector.bin", "rb");
    if(!file) {
        printf("Error: Cannot open file.\n");
        exit(EXIT_FAILURE);
    }
    BootSector boot_sector;
    fread(&boot_sector, BOOT_SECTOR_SIZE, 1, file);
    fclose(file);

    // Validate boot signature
    if(!is_boot_signature_valid(&boot_sector)) {
        printf("Error: Invalid boot signature.\n");
        exit(EXIT_FAILURE);
    }

    // Center boot code
    center_boot_code(&boot_sector);

    // Print boot sector details after optimization
    print_boot_sector_details(&boot_sector);
 
    return 0;
}