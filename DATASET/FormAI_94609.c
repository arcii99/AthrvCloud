//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct subnet {
    unsigned char octet1;
    unsigned char octet2;
    unsigned char octet3;
    unsigned char octet4;
    unsigned int cidr;
};

void print_subnet(struct subnet s) {
    printf("%d.%d.%d.%d/%d\n", s.octet1, s.octet2, s.octet3, s.octet4, s.cidr);
}

int calc_bitmask(int cidr) {
    unsigned int bitmask = 0;
    for (int i = 0; i < cidr; i++) {
        bitmask |= 1 << (31 - i);
    }
    return bitmask;
}

void calc_subnet(struct subnet *s, int num_subnets) {
    int bit_shift = 32 - s->cidr - (int) round(log(num_subnets) / log(2));
    unsigned int bitmask = calc_bitmask(s->cidr);
    unsigned int npf = htonl((bitmask << bit_shift));
    unsigned int hosts_per_subnet = pow(2, 32 - s->cidr - bit_shift) - 2;
    unsigned int offset = 0;
    for (int i = 1; i <= num_subnets; i++) {
        s[i - 1].octet1 = ((ntohl(npf) + offset) >> 24) & 0xff;
        s[i - 1].octet2 = ((ntohl(npf) + offset) >> 16) & 0xff;
        s[i - 1].octet3 = ((ntohl(npf) + offset) >> 8) & 0xff;
        s[i - 1].octet4 = ((ntohl(npf) + offset)) & 0xff;
        s[i - 1].cidr = s->cidr + (int) round(log(hosts_per_subnet + 2) / log(2));
        offset += hosts_per_subnet;
    }
}

int main() {
    struct subnet s1 = {192, 168, 1, 0, 24};
    printf("Original Subnet:\n");
    print_subnet(s1);
    int num_subnets = 8;
    struct subnet *subnets = malloc(num_subnets * sizeof(struct subnet));
    calc_subnet(subnets, num_subnets);
    printf("New Subnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        print_subnet(subnets[i]);
    }
    free(subnets);
    return 0;
}