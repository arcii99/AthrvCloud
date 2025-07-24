//FormAI DATASET v1.0 Category: Data recovery tool ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1048576  // 1 MB

typedef struct {
    char filename[256];
    char data[MAX_FILE_SIZE];
    int size;
} recovered_file;

void recover_file(FILE *f, recovered_file *rec_files, int *num_files) {
    char buf[MAX_FILE_SIZE];
    int size;

    fseek(f, 0, SEEK_END);
    size = ftell(f);
    fseek(f, 0, SEEK_SET);

    if (size > MAX_FILE_SIZE) {
        printf("Error: file too large to recover\n");
        return;
    }

    fread(buf, size, 1, f);

    if (buf[0] != 'C' || buf[1] != 'D') {
        printf("Error: file is not a C Data file\n");
        return;
    }

    int num_to_recover = buf[2];
    int current_pos = 3;
    
    for (int i = 0; i < num_to_recover; i++) {
        int name_len = buf[current_pos++];
        strncpy(rec_files[*num_files].filename, buf + current_pos, name_len);
        current_pos += name_len;
        int file_size = ((unsigned char)buf[current_pos++]) << 24 | ((unsigned char)buf[current_pos++]) << 16 
                        | ((unsigned char)buf[current_pos++]) << 8 | ((unsigned char)buf[current_pos++]);
        memcpy(rec_files[*num_files].data, buf + current_pos, file_size);
        rec_files[*num_files].size = file_size;
        current_pos += file_size;
        (*num_files)++;
    }
}

void save_file(FILE *f, char *filename, char *data, int size) {
    char header[] = "CDS";  // C Data Save
    char num_files = 1;
    char name_len = strlen(filename);
    fwrite(header, 1, sizeof(header), f);
    fwrite(&num_files, 1, sizeof(num_files), f);
    fwrite(&name_len, 1, sizeof(name_len), f);
    fwrite(filename, 1, name_len, f);
    fwrite(&size, 1, sizeof(size), f);
    fwrite(data, size, 1, f);
}

int main() {
    char data[] = "Hello, world!";
    FILE *f = fopen("test.cds", "wb");
    save_file(f, "hello.txt", data, sizeof(data));
    fclose(f);

    f = fopen("test.cds", "rb");
    recovered_file rec_files[10];
    int num_files = 0;
    recover_file(f, rec_files, &num_files);
    fclose(f);

    f = fopen("recovered.txt", "wb");
    fwrite(rec_files[0].data, rec_files[0].size, 1, f);
    fclose(f);

    printf("File recovered and saved as 'recovered.txt'\n");

    return 0;
}