//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BITS 32

int main(int argc, char **argv) {
    char addr[20];
    int bits, i, q, r;
    unsigned long ip, mask;

    memset(addr, 0x00, sizeof(addr));
    
    printf("Enter IP address (xxx.xxx.xxx.xxx or xxx.xxx.xxx.xxx/yy): ");
    scanf("%19s", addr);

    if (strchr(addr, '/') != NULL) {
        char *tmp = strchr(addr, '/');
        bits = atoi(++tmp);
        *--tmp = '\0';
    } else {
        bits = MAX_BITS;
    }

    ip = 0;
    q = 3;
    char *ptr = strtok(addr, ".");
    while (ptr != NULL && q >= 0) {
        ip += atol(ptr) << (q << 3);
        q--;
        ptr = strtok(NULL, ".");
    }

    mask = 0xFFFFFFFFL;
    r = MAX_BITS - bits;
    if (bits < MAX_BITS) mask = ~(mask >> bits) & 0xFFFFFFFFL;

    printf("Address: %s/%d\n", addr, bits);
    printf("IP address: %lu.%lu.%lu.%lu\n", (ip >> 24) & 0xFF, (ip >> 16) & 0xFF, (ip >> 8) & 0xFF, ip & 0xFF);
    printf("Subnet mask: %lu.%lu.%lu.%lu\n", (mask >> 24) & 0xFF, (mask >> 16) & 0xFF, (mask >> 8) & 0xFF, mask & 0xFF);
    printf("Number of hosts: %lu\n", mask == 0 ? 0 : (1L << r) - 2);

    return 0;
}