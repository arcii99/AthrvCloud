//FormAI DATASET v1.0 Category: Modern Encryption ; Style: single-threaded
#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE 16
#define ROUND_COUNT 10

void print_hex(const char* data, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%02X", (unsigned char)data[i]);
    }
    printf("\n");
}

void sub_bytes(char* data)
{
    for (int i = 0; i < BLOCK_SIZE; i++)
    {
        data[i] = data[i] ^ 0x55;
        data[i] = ((data[i] >> 1) & 0x55) | ((data[i] << 1) & 0xAA);
        data[i] = ((data[i] >> 2) & 0x33) | ((data[i] << 2) & 0xCC);
        data[i] = ((data[i] >> 4) & 0x0F) | ((data[i] << 4) & 0xF0);
    }
}

void shift_rows(char* data)
{
    char tmp[BLOCK_SIZE];
    memcpy(tmp, data, BLOCK_SIZE);
    data[1] = tmp[5];
    data[5] = tmp[9];
    data[9] = tmp[13];
    data[13] = tmp[1];
    data[2] = tmp[10];
    data[6] = tmp[14];
    data[10] = tmp[2];
    data[14] = tmp[6];
    data[3] = tmp[15];
    data[7] = tmp[3];
    data[11] = tmp[7];
    data[15] = tmp[11];
}

void mix_columns(char* data)
{
    for (int i = 0; i < BLOCK_SIZE; i += 4)
    {
        char a[4];
        char b[4];
        memcpy(a, &data[i], 4);
        for (int j = 0; j < 4; j++)
        {
            b[j] = a[j] << 1;
            if (a[j] & 0x80) b[j] ^= 0x1B;
        }
        data[i] = b[0] ^ a[3] ^ a[2] ^ b[1] ^ a[1];
        data[i + 1] = b[1] ^ a[0] ^ a[3] ^ b[2] ^ a[2];
        data[i + 2] = b[2] ^ a[1] ^ a[0] ^ b[3] ^ a[3];
        data[i + 3] = b[3] ^ a[2] ^ a[1] ^ b[0] ^ a[0];
    }
}

void add_round_key(char* data, const char* key)
{
    for (int i = 0; i < BLOCK_SIZE; i++)
    {
        data[i] ^= key[i];
    }
}

void expand_key(const char* key, char* sub_keys)
{
    memcpy(sub_keys, key, BLOCK_SIZE);
    for (int i = BLOCK_SIZE; i < BLOCK_SIZE * (ROUND_COUNT + 1); i += BLOCK_SIZE)
    {
        char tmp[4];
        memcpy(tmp, &sub_keys[i - BLOCK_SIZE], 4);
        if (i / BLOCK_SIZE % 4 == 0)
        {
            char t = tmp[0];
            tmp[0] = tmp[1];
            tmp[1] = tmp[2];
            tmp[2] = tmp[3];
            tmp[3] = t;
            for (int j = 0; j < 4; j++)
            {
                tmp[j] = ((tmp[j] >> 4) & 0x0F) | ((tmp[j] << 4) & 0xF0);
                tmp[j] = ((tmp[j] >> 2) & 0x33) | ((tmp[j] << 2) & 0xCC);
                tmp[j] = ((tmp[j] >> 1) & 0x55) | ((tmp[j] << 1) & 0xAA);
            }
            tmp[0] ^= 0x63;
        }
        else if (i / BLOCK_SIZE % 4 == 4)
        {
            for (int j = 0; j < 4; j++)
            {
                tmp[j] = ((tmp[j] >> 4) & 0x0F) | ((tmp[j] << 4) & 0xF0);
                tmp[j] = ((tmp[j] >> 2) & 0x33) | ((tmp[j] << 2) & 0xCC);
                tmp[j] = ((tmp[j] >> 1) & 0x55) | ((tmp[j] << 1) & 0xAA);
            }
        }
        for (int j = 0; j < BLOCK_SIZE; j++)
        {
            sub_keys[i + j] = sub_keys[i - BLOCK_SIZE + j] ^ tmp[j % 4];
        }
    }
}

void encrypt(char* data, const char* key)
{
    char sub_keys[BLOCK_SIZE * (ROUND_COUNT + 1)];
    expand_key(key, sub_keys);
    add_round_key(data, &sub_keys[0]);
    for (int i = BLOCK_SIZE; i < BLOCK_SIZE * ROUND_COUNT; i += BLOCK_SIZE)
    {
        sub_bytes(data);
        shift_rows(data);
        mix_columns(data);
        add_round_key(data, &sub_keys[i]);
    }
    sub_bytes(data);
    shift_rows(data);
    add_round_key(data, &sub_keys[BLOCK_SIZE * ROUND_COUNT]);
}

int main()
{
    char data[BLOCK_SIZE] = { 'h', 'e', 'l', 'l', 'o', 'w', 'o', 'r', 'l', 'd', 't', 'e', 's', 't', '1', '2' };
    char key[BLOCK_SIZE] = { 's', 'e', 'c', 'r', 'e', 't', 'k', 'e', 'y', '1', '2', '3', '4', '5', '6', '7' };
    printf("Original data: ");
    print_hex(data, BLOCK_SIZE);
    encrypt(data, key);
    printf("Encrypted data: ");
    print_hex(data, BLOCK_SIZE);
    return 0;
}