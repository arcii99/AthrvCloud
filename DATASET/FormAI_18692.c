//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: expert-level
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define ROTL(x,n) (((x) << (n)) | ((x) >> (32 - (n))))
#define ROTR(x,n) (((x) >> (n)) | ((x) << (32 - (n))))

#define little_endian_swap(x) \
    (((x) << 24) | (((x) << 8) & 0xff0000) | (((x) >> 8) & 0xff00) | ((x) >> 24))

#define FF(a,b,c,d,x,s,t) \
  (a) += ((b) & (c)) | ((~b) & (d)) | (x);\
  (a) = ROTL((a), (s));           \
  (a) += (t);                     \
  (b) = ROTR((b), (s))

typedef struct {
    uint32_t state[4];
    uint32_t count[2];
    unsigned char buffer[64];
} Hash;

void transform(Hash *context, const unsigned char *block) {
    uint32_t a = context->state[0], b = context->state[1],
             c = context->state[2], d = context->state[3],
             data[16];
    memcpy(data, block, 64);
    a = little_endian_swap(a);
    b = little_endian_swap(b);
    c = little_endian_swap(c);
    d = little_endian_swap(d);
    FF(a, b, c, d, data[0], 7, 0xD76AA478);
    FF(d, a, b, c, data[1], 12, 0xE8C7B756);
    FF(c, d, a, b, data[2], 17, 0x242070DB);
    FF(b, c, d, a, data[3], 22, 0xC1BDCEEE);
    FF(a, b, c, d, data[4], 7, 0xF57C0FAF);
    FF(d, a, b, c, data[5], 12, 0x4787C62A);
    FF(c, d, a, b, data[6], 17, 0xA8304613);
    FF(b, c, d, a, data[7], 22, 0xFD469501);
    FF(a, b, c, d, data[8], 7, 0x698098D8);
    FF(d, a, b, c, data[9], 12, 0x8B44F7AF);
    FF(c, d, a, b, data[10], 17, 0xFFFF5BB1);
    FF(b, c, d, a, data[11], 22, 0x895CD7BE);
    FF(a, b, c, d, data[12], 7, 0x6B901122);
    FF(d, a, b, c, data[13], 12, 0xFD987193);
    FF(c, d, a, b, data[14], 17, 0xA679438E);
    FF(b, c, d, a, data[15], 22, 0x49B40821);
    FF(a, b, c, d, (data[1]), 5, 0xF61E2562);
    FF(d, a, b, c, (data[6]), 9, 0xC040B340);
    FF(c, d, a, b, (data[11]), 14, 0x265E5A51);
    FF(b, c, d, a, (data[0]), 20, 0xE9B6C7AA);
    FF(a, b, c, d, (data[5]), 5, 0xD62F105D);
    FF(d, a, b, c, (data[10]), 9, 0x02441453);
    FF(c, d, a, b, (data[15]), 14, 0xD8A1E681);
    FF(b, c, d, a, (data[4]), 20, 0xE7D3FBC8);
    FF(a, b, c, d, (data[9]), 5, 0x21E1CDE6);
    FF(d, a, b, c, (data[14]), 9, 0xC33707D6);
    FF(c, d, a, b, (data[3]), 14, 0xF4D50D87);
    FF(b, c, d, a, (data[8]), 20, 0x455A14ED);
    FF(a, b, c, d, (data[13]), 5, 0xA9E3E905);
    FF(d, a, b, c, (data[2]), 9, 0xFCEFA3F8);
    FF(c, d, a, b, (data[7]), 14, 0x676F02D9);
    FF(b, c, d, a, (data[12]), 20, 0x8D2A4C8A);
    FF(a, b, c, d, (data[5]), 4, 0xFFFA3942);
    FF(d, a, b, c, (data[8]), 11, 0x8771F681);
    FF(c, d, a, b, (data[11]), 16, 0x6D9D6122);
    FF(b, c, d, a, (data[14]), 23, 0xFDE5380C);
    FF(a, b, c, d, (data[1]), 4, 0xA4BEEA44);
    FF(d, a, b, c, (data[4]), 11, 0x4BDECFA9);
    FF(c, d, a, b, (data[7]), 16, 0xF6BB4B60);
    FF(b, c, d, a, (data[10]), 23, 0xBEBFBC70);
    FF(a, b, c, d, (data[13]), 4, 0x289B7EC6);
    FF(d, a, b, c, (data[0]), 11, 0xEAA127FA);
    FF(c, d, a, b, (data[3]), 16, 0xD4EF3085);
    FF(b, c, d, a, (data[6]), 23, 0x04881D05);
    FF(a, b, c, d, (data[9]), 4, 0xD9D4D039);
    FF(d, a, b, c, (data[12]), 11, 0xE6DB99E5);
    FF(c, d, a, b, (data[15]), 16, 0x1FA27CF8);
    FF(b, c, d, a, (data[2]), 23, 0xC4AC5665);
    FF(a, b, c, d, (data[0]), 6, 0xF4292244);
    FF(d, a, b, c, (data[7]), 10, 0x432AFF97);
    FF(c, d, a, b, (data[14]), 15, 0xAB9423A7);
    FF(b, c, d, a, (data[5]), 21, 0xFC93A039);
    FF(a, b, c, d, (data[12]), 6, 0x655B59C3);
    FF(d, a, b, c, (data[3]), 10, 0x8F0CCC92);
    FF(c, d, a, b, (data[10]), 15, 0xFFEFF47D);
    FF(b, c, d, a, (data[1]), 21, 0x85845DD1);
    FF(a, b, c, d, (data[8]), 6, 0x6FA87E4F);
    FF(d, a, b, c, (data[15]), 10, 0xFE2CE6E0);
    FF(c, d, a, b, (data[6]), 15, 0xA3014314);
    FF(b, c, d, a, (data[13]), 21, 0x4E0811A1);
    FF(a, b, c, d, (data[4]), 6, 0xF7537E82);
    FF(d, a, b, c, (data[11]), 10, 0xBD3AF235);
    FF(c, d, a, b, (data[2]), 15, 0x2AD7D2BB);
    FF(b, c, d, a, (data[9]), 21, 0xEB86D391);
    context->state[0] += a;
    context->state[1] += b;
    context->state[2] += c;
    context->state[3] += d;
    memset(data, 0, sizeof(data));
}

void update(Hash *context, const unsigned char *input, const size_t length) {
    uint32_t i = 0;
    uint32_t index = 0, part = 0;
    index = (uint32_t)((context->count[0] >> 3) & 0x3f);
    context->count[0] += ((uint32_t)length << 3);
    if (context->count[0] < ((uint32_t)length << 3)) context->count[1]++;
    context->count[1] += ((uint32_t)length >> 29);
    part = 64 - index;
    if (length >= part) {
        memcpy(&context->buffer[index], input, part);
        transform(context, context->buffer);
        for (i = part; i + 63 < length; i += 64)
            transform(context, &input[i]);
        index = 0;
    } else {
        i = 0;
    }
    memcpy(&context->buffer[index], &input[i], length - i);
}

void finalize(Hash *context, unsigned char digest[16]) {
    uint32_t i = 0, index = 0, padlen = 0;
    unsigned char bits[8];
    index = (uint32_t)((context->count[0] >> 3) & 0x3f);
    padlen = (index < 56) ? (56 - index) : (120 - index);
    memset(bits, 0, sizeof(bits));
    memcpy(bits, &context->count, 8);
    update(context, (unsigned char *)"A", 1);
    while (index < 56) {
        update(context, (unsigned char *)"\0", 1);
        index++;
    }
    update(context, bits, 8);
    memcpy(digest, context->state, 16);
    memset(context, 0, sizeof(*context));
}

void hash(Hash *context, const unsigned char *input, const size_t length, unsigned char digest[16]) {
    update(context, input, length);
    finalize(context, digest);
}

int main(int argc, char *argv[]) {
    Hash context;
    unsigned char digest[16];
    unsigned char *input = (unsigned char *)"Hello World!";
    hash(&context, input, strlen((char *)input), digest);
    for (int i = 0; i < sizeof(digest); i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");
    return 0;
}