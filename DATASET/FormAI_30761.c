//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: high level of detail
#include<stdio.h>
#include<string.h>

int main()
{
    char message[100], checksum[10];
    int msg_len, check_sum = 0;

    printf("Enter message: ");
    scanf("%s", message);

    msg_len = strlen(message);

    for(int i=0; i<msg_len; i++)
    {
        check_sum += message[i];
    }

    sprintf(checksum, "%X", check_sum);
    printf("Checksum: %s\n", checksum);

    return 0;
}