//FormAI DATASET v1.0 Category: Data recovery tool ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define INODE_SIZE          128
#define NTFS_SIGNATURE      "NTFS"

typedef struct {
    char signature[4];
    int bytes_per_sector;
    int sectors_per_cluster;
    int reserved_sector_count;
    char padding[INODE_SIZE - 16];
} NTFS_HEADER;

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp;

    if ((fp = fopen(argv[1], "rb")) == NULL) {
        printf("Could not open file %s\n", argv[1]);
        return 1;
    }

    NTFS_HEADER header;

    if (fread(&header, sizeof(header), 1, fp) != 1) {
        printf("Could not read from file %s\n", argv[1]);
        fclose(fp);
        return 1;
    }

    if (strncmp(header.signature, NTFS_SIGNATURE, 4) != 0) {
        printf("Invalid NTFS header in file %s\n", argv[1]);
        fclose(fp);
        return 1;
    }

    int sector_size = header.bytes_per_sector;
    int cluster_size = sector_size * header.sectors_per_cluster;
    int reserved_size = header.reserved_sector_count * sector_size;

    // Check if the file size is at least valid
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);

    if (file_size < reserved_size + cluster_size) {
        printf("Invalid file size for NTFS volume\n");
        fclose(fp);
        return 1;
    }

    // Calculate the number of clusters in the file
    int num_clusters = (file_size - reserved_size) / cluster_size;

    // Allocate the cluster map
    char *cluster_map = calloc(num_clusters, 1);

    int i;

    // Mark all reserved clusters as used
    for (i = 0; i < header.reserved_sector_count; i++) {
        cluster_map[i / header.sectors_per_cluster] = 1;
    }

    // Traverse the file and mark each cluster as used
    fseek(fp, reserved_size, SEEK_SET);

    for (i = 0; i < num_clusters; i++) {
        char buffer[sector_size];

        if (fread(buffer, sector_size, 1, fp) != 1) {
            printf("Could not read from file %s\n", argv[1]);
            fclose(fp);
            free(cluster_map);
            return 1;
        }

        cluster_map[i] = 1;
    }

    // Print the list of used clusters
    printf("Used Clusters:\n");

    for (i = 0; i < num_clusters; i++) {
        if (cluster_map[i]) {
            printf("%d ", i);
        }
    }

    printf("\n");

    fclose(fp);
    free(cluster_map);

    return 0;
}