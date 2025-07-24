//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int calculate_ip(int mask) {
    int number_of_ones = pow(2, (32 - mask)) - 1;
    return number_of_ones;
}

void calculate_subnet(int first_IP[], int subnet[]) {
    int i;
    for (i = 0; i < 4; i++) {
        subnet[i] = first_IP[i];
    }
}

void recursive_subnet(int mask, int *first_IP, int *subnet, int depth) {
    int i, j, mask_copy = mask;

    if (depth > 0) {
        memcpy(subnet, first_IP, sizeof(int)*4);
    }

    mask_copy--;

    if (mask_copy == -1) {
        return;
    } else {
        int number_of_ones = calculate_ip(mask_copy), number_of_zeros = pow(2, mask_copy);
        int subnet_first_IP[4];

        memcpy(subnet_first_IP, subnet, sizeof(int)*4);

        for (i = 0; i < 256; i+=number_of_zeros) {
            for (j = 0; j < number_of_zeros; j++) {
                subnet_first_IP[3] += 1;

                if (subnet_first_IP[3] > 255) {
                    subnet_first_IP[3] = 0;
                    subnet_first_IP[2] += 1;
                }

                if (subnet_first_IP[2] > 255) {
                    subnet_first_IP[2] = 0;
                    subnet_first_IP[1] += 1;
                }

                if (subnet_first_IP[1] > 255) {
                    subnet_first_IP[1] = 0;
                    subnet_first_IP[0] += 1;
                }

                recursive_subnet(mask_copy, subnet_first_IP, subnet + (i+j)*4, depth+1);
            }
        }
    }
}

int main() {
    int mask = 24, i, j, subnet[256][4];
    int first_IP[] = {192, 168, 1, 0};

    recursive_subnet(mask, first_IP, subnet[0], 0);

    for (i = 0; i < 256; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ", subnet[i][j]);
        }
        printf("\n");
    }

    return 0;
}