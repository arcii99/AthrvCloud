//FormAI DATASET v1.0 Category: File Backup System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 10

// Define struct to hold file information
typedef struct {
    char name[256];
    long size;
    time_t modified;
} file_entry;

void backup_file(char* filename);
void shift_entries();
void add_entry(char* filename);

file_entry entries[MAX_ENTRIES];
int num_entries = 0;

int main(int argc, char** argv) {
    // Check for filename argument
    if (argc < 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        return 1;
    }

    // Backup the file
    backup_file(argv[1]);

    // Print the entries
    printf("File Backup System\n");
    printf("==================\n");
    printf("Filename\tSize\tModified\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%ld\t%s", entries[i].name, entries[i].size, ctime(&entries[i].modified));
    }

    return 0;
}

// Copies the given file to a backup file with a timestamp
void backup_file(char* filename) {
    // Generate backup filename
    char backup_name[512];
    sprintf(backup_name, "%s.%ld.bak", filename, time(NULL));

    // Open input file
    FILE* input_file = fopen(filename, "r");
    if (input_file == NULL) {
        printf("Error: could not open input file '%s'\n", filename);
        return;
    }

    // Open output file
    FILE* output_file = fopen(backup_name, "w");
    if (output_file == NULL) {
        printf("Error: could not create backup file '%s'\n", backup_name);
        fclose(input_file);
        return;
    }

    // Copy data from input to output
    int ch;
    while ((ch = fgetc(input_file)) != EOF) {
        fputc(ch, output_file);
    }

    // Close files
    fclose(input_file);
    fclose(output_file);

    // Add entry to list of backups
    add_entry(backup_name);
}

// Shift the entries down one, overwriting the first entry
void shift_entries() {
    for (int i = 0; i < num_entries - 1; i++) {
        memcpy(&entries[i], &entries[i+1], sizeof(file_entry));
    }
    num_entries--;
}

// Add an entry for the given file
void add_entry(char* filename) {
    // Create new entry
    file_entry new_entry;
    strcpy(new_entry.name, filename);
    new_entry.size = 0;
    new_entry.modified = time(NULL);

    // Add entry to list
    if (num_entries == MAX_ENTRIES) {
        shift_entries();
    }
    memcpy(&entries[num_entries], &new_entry, sizeof(file_entry));
    num_entries++;
}