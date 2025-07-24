//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{

    int a, b, c, d = 0, numeric_ip = 0, prefix = 0, i;
    char ip_address[15];

    printf("Welcome to the Mind-Bending C Subnet Calculator!\n\n");

    while (d == 0) {
        printf("Please enter a valid IP Address: ");
        scanf("%s", ip_address);

        // Splitting input string into octets
        if (sscanf(ip_address, "%d.%d.%d.%d", &a, &b, &c, &d) == 4) {
            if (a >= 0 && a <= 255 && b >= 0 && b <= 255 && c >= 0 && c <= 255 && d >= 0 && d <= 255) {
                numeric_ip = a * pow(256, 3) + b * pow(256, 2) + c * pow(256, 1) + d * pow(256, 0);
                // Getting subnet prefix length
                for (i = 1; i <= 32; i++) {
                    if ((numeric_ip & ((unsigned long) pow(2, 32 - i))) == 0) {
                        prefix = i;
                        break;
                    }
                }
                d = 1;
            }
        }
        if (d == 0) {
            printf("Invalid IP Address!\n");
        }
    }

    printf("\nIP Address: %d.%d.%d.%d\n", a, b, c, d);
    printf("Numeric IP Address: %lu\n", numeric_ip);
    printf("Subnet Prefix: %d\n\n", prefix);

    return 0;
}