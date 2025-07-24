//FormAI DATASET v1.0 Category: File Encyptor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

void crypt(int key, const char* source_path, const char* out_path) {
    FILE* in_file = fopen(source_path, "rb");
    if (in_file == NULL) {
        printf("Cannot open source file.\n");
        exit(1);
    }
	
    FILE* out_file = fopen(out_path, "wb");
    if (out_file == NULL) {
        fclose(in_file);
        printf("Cannot create destination file.\n");
        exit(1);
    }
	
    const int buffer_size = 1024;
    char buffer[buffer_size];
    while (!feof(in_file)) {
        int bytes_read = fread(buffer, 1, buffer_size, in_file);
        for (int i = 0; i < bytes_read; ++i) {
            char c = buffer[i] ^ key;
            fwrite(&c, 1, 1, out_file);
        }
    }
	
    fclose(in_file);
    fflush(out_file);
    fclose(out_file);
}

int main() {
    int key = 42;
    const char* source_path = "input.txt";
    const char* out_path = "output.txt";
    crypt(key, source_path, out_path);
    printf("File %s has been encrypted with the key %d to the file %s", source_path, key, out_path);
    return 0;
}