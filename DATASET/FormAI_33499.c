//FormAI DATASET v1.0 Category: QR code reader ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define QR_CODE_SIZE 21 // QR Code Size - 21x21 Square

typedef struct {
    char data[QR_CODE_SIZE][QR_CODE_SIZE];
    int version;
    int mode;
    int error_correction_level;
} QRCode;

typedef struct {
    char name[100];
    int size;
    int num_entries;
    QRCode **entries;
} QRCodeDatabase;

void initialize_database(QRCodeDatabase *db) {
    strcpy(db->name, "Super Cool QR Code Database");
    db->num_entries = 0;
    db->size = 10;
    db->entries = (QRCode **)malloc(sizeof(QRCode *) * db->size);
}

void add_entry(QRCodeDatabase *db, QRCode *qr_code) {
    if (db->num_entries == db->size) {
        db->size *= 2;
        db->entries = (QRCode **)realloc(db->entries, sizeof(QRCode *) * db->size);
    }
    db->entries[db->num_entries++] = qr_code;
}

void print_qr_code(QRCode *qr_code) {
    printf("QR Code:\n\tVersion: %d\n\tMode: %d\n\tError Correction Level: %d\n\n", qr_code->version, qr_code->mode, qr_code->error_correction_level);
    printf("Data:\n");
    for (int i = 0; i < QR_CODE_SIZE; i++) {
        for (int j = 0; j < QR_CODE_SIZE; j++) {
            printf("%c", qr_code->data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int read_qr_code(FILE *file, QRCode *qr_code) {
    char size_buffer[5] = "\0";
    char mode_buffer[2] = "\0";
    char version_buffer[3] = "\0";
    char ecl_buffer[2] = "\0";
    char data_buffer[QR_CODE_SIZE * QR_CODE_SIZE + 1] = "\0";
    bool reading_data = false;
    int data_pos = 0;

    while (!feof(file)) {
        char c = fgetc(file);
        if (!reading_data) {
            if (c == ':') {
                if (strncmp(size_buffer, "21x21", 5) == 0) {
                    qr_code->version = atoi(version_buffer);
                    qr_code->mode = atoi(mode_buffer);
                    qr_code->error_correction_level = atoi(ecl_buffer);

                    for (int i = 0; i < QR_CODE_SIZE; i++) {
                        for (int j = 0; j < QR_CODE_SIZE; j++) {
                            qr_code->data[i][j] = data_buffer[data_pos++];
                        }
                    }

                    return 0; // Success
                } else {
                    return 1; // Invalid QR Code
                }
            } else if (isdigit(c)) {
                if (strlen(size_buffer) == 0) {
                    size_buffer[0] = c;
                } else if (strlen(size_buffer) == 1) {
                    size_buffer[1] = c;
                }
                if (strlen(version_buffer) < 2) {
                    version_buffer[strlen(version_buffer)] = c;
                } else if (strlen(mode_buffer) < 1) {
                    mode_buffer[strlen(mode_buffer)] = c;
                } else if (strlen(ecl_buffer) < 1) {
                    ecl_buffer[strlen(ecl_buffer)] = c;
                }
            } else if (c == ',') {
                reading_data = true;
            }
        } else if (data_pos < QR_CODE_SIZE * QR_CODE_SIZE) {
            data_buffer[data_pos++] = c;
        }
    }

    return 2; // Invalid Format
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: qr_reader <filename>\n");
        exit(1);
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file: %s\n", filename);
        exit(1);
    }

    QRCodeDatabase db;
    initialize_database(&db);

    while (!feof(file)) {
        QRCode *qr_code = (QRCode *)malloc(sizeof(QRCode));
        int result = read_qr_code(file, qr_code);

        if (result == 0) {
            add_entry(&db, qr_code);
            printf("Read QR Code Successfully!\n");
            print_qr_code(qr_code);
        } else if (result == 1) {
            printf("Invalid QR Code Format!\n");
        } else if (result == 2) {
            printf("Invalid File Format!\n");
        }
    }

    printf("\nQR Code Database: %s\n\n", db.name);
    printf("Number of Entries: %d\n", db.num_entries);
    printf("Size of Database: %d\n", db.size);

    for (int i = 0; i < db.num_entries; i++) {
        printf("\nQR Code Entry %d:\n", i + 1);
        print_qr_code(db.entries[i]);
    }

    fclose(file);
    return 0;
}