//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1024

unsigned short checksum(char *buf, int len) {
    unsigned int sum = 0;

    // sum up the entire buffer
    while (len > 1) {
        sum += *((unsigned short*) buf);
        buf += 2;
        len -= 2;
    }

    // add left-over byte if length is odd
    if (len == 1) {
        sum += *((unsigned char*) buf);
    }

    // add carry bits to lower 16 bits
    while (sum >> 16) {
        sum = (sum & 0xffff) + (sum >> 16);
    }

    return (unsigned short) ~sum;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Failed to open %s\n", argv[1]);
        return 1;
    }

    char buf[BUF_SIZE];
    int len;
    unsigned short cksum = 0;

    // read file into buffer and add up checksum
    while ((len = fread(buf, 1, sizeof(buf), fp)) > 0) {
        cksum += checksum(buf, len);
    }

    fclose(fp);

    // print checksum in hexadecimal format
    printf("Checksum for %s: 0x%04x\n", argv[1], cksum);

    return 0;
}