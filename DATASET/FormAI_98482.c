//FormAI DATASET v1.0 Category: Data recovery tool ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <device>\n", argv[0]);
        return 1;
    }
    const char* device = argv[1];
    FILE* fp = fopen(device, "rb");
    if (!fp) {
        perror("fopen");
        return 1;
    }
    char buffer[512];
    ssize_t nread = 0;
    do {
        nread = fread(buffer, 1, sizeof(buffer), fp);
        printf("%zd bytes read\n", nread);
        // Process the buffer here
    } while (nread > 0);
    fclose(fp);
    return 0;
}