//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Romeo and Juliet
#include <stdio.h>

/* Oh lovely maid with lips of red */
/* I bring to thee a code ahead */
/* A checksum calc in C I wrote */
/* With love and care, this code I quote */

/* Forsooth, please tell me what you need */
/* A buffer and a length, indeed */
/* And I will do my very best */
/* To give you back the sum with zest */

int calculate_checksum(char *buffer, int length) {
    int checksum = 0;
    for (int i = 0; i < length; i++) {
        checksum += buffer[i];
    }
    return checksum;
}

/* Oh joyous code, how sweet thou art */
/* To calculate a sum with heart */
/* And make computers sing with glee */
/* Thank thee, thank thee, graciously */

int main() {
    char buffer[] = "Oh Romeo, Romeo, wherefore art thou Romeo?";
    int length = sizeof(buffer) / sizeof(buffer[0]);
    int checksum = calculate_checksum(buffer, length);
    printf("The checksum is: %d\n", checksum);
    return 0;
}