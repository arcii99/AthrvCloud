//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: inquisitive
#include<stdio.h>
#include<string.h>

int main() {
    char data[100];
    int checksum = 0;
    int choice = 0;

    printf("********** C Checksum Calculator **********\n");

    while (1) {
        printf("Please enter the data (Type 'exit' to quit): ");
        scanf("%s", data);
        if (strcmp(data, "exit") == 0) {
            break;
        }
        else {
            printf("Please select a checksum method:\n");
            printf("1. Simple Checksum\n");
            printf("2. Fletcher's Checksum\n");
            printf("3. Adler-32 Checksum\n");
            printf(">>Your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    //Simple Checksum
                    for (int i = 0; i < strlen(data); i++) {
                        checksum += (int)data[i];
                    }
                    printf("Simple Checksum: %d\n", checksum);
                    break;
                case 2:
                    //Fletcher's Checksum
                    int sum1 = 0;
                    int sum2 = 0;
                    for (int i = 0; i < strlen(data); i++) {
                        sum1 = (sum1 + (int)data[i]) % 255;
                        sum2 = (sum2 + sum1) % 255;
                    }
                    checksum = (sum2 << 8) + sum1;
                    printf("Fletcher's Checksum: %d\n", checksum);
                    break;
                case 3:
                    //Adler-32 Checksum
                    int s1 = 1;
                    int s2 = 0;
                    for (int i = 0; i < strlen(data); i++) {
                        s1 = (s1 + (int)data[i]) % 65521;
                        s2 = (s2 + s1) % 65521;
                    }
                    checksum = (s2 << 16) + s1;
                    printf("Adler-32 Checksum: %d\n", checksum);
                    break;
                default:
                    printf("Invalid choice! Please try again.\n");
                    break;
            }
        }
    }
    printf("Thank you for using the C Checksum Calculator!\n");
    return 0;
}