//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BLOCK_SIZE 64

typedef unsigned int uint32;
typedef unsigned long long uint64;

typedef struct sha256_ctx {
	uint32 state[8];
	uint64 count;
	unsigned char block[BLOCK_SIZE];
} sha256_ctx_t;

#define rol(x, n) (((x) << (n)) | ((x) >> (32 - (n))))
#define ror(x, n) (((x) >> (n)) | ((x) << (32 - (n))))
#define ENDIAN_SWAP_U32(x) ((rol((x) & 0x000000ff, 24) | rol((x) & 0x0000ff00, 8) | ror((x) & 0x00ff0000, 8) | ror((x) & 0xff000000, 24)))

static const uint32 k[64] = {
	0x428a2f98,0x71374491,0xb5c0fbcf,0xe9b5dba5,
	0x3956c25b,0x59f111f1,0x923f82a4,0xab1c5ed5,
	0xd807aa98,0x12835b01,0x243185be,0x550c7dc3,
	0x72be5d74,0x80deb1fe,0x9bdc06a7,0xc19bf174,
	0xe49b69c1,0xefbe4786,0x0fc19dc6,0x240ca1cc,
	0x2de92c6f,0x4a7484aa,0x5cb0a9dc,0x76f988da,
	0x983e5152,0xa831c66d,0xb00327c8,0xbf597fc7,
	0xc6e00bf3,0xd5a79147,0x06ca6351,0x14292967,
	0x27b70a85,0x2e1b2138,0x4d2c6dfc,0x53380d13,
	0x650a7354,0x766a0abb,0x81c2c92e,0x92722c85,
	0xa2bfe8a1,0xa81a664b,0xc24b8b70,0xc76c51a3,
	0xd192e819,0xd6990624,0xf40e3585,0x106aa070,
	0x19a4c116,0x1e376c08,0x2748774c,0x34b0bcb5,
	0x391c0cb3,0x4ed8aa4a,0x5b9cca4f,0x682e6ff3,
	0x748f82ee,0x78a5636f,0x84c87814,0x8cc70208,
	0x90befffa,0xa4506ceb,0xbef9a3f7,0xc67178f2,
};

static uint32 sigma0(uint32 x)
{
	return (ror(x, 7) ^ ror(x, 18) ^ (x >> 3));
}

static uint32 sigma1(uint32 x)
{
	return (ror(x, 17) ^ ror(x, 19) ^ (x >> 10));
}

static uint32 Ch(uint32 x, uint32 y, uint32 z)
{
	return ((x & y) ^ ((~x) & z));
}

static uint32 Maj(uint32 x, uint32 y, uint32 z)
{
	return ((x & y) ^ (x & z) ^ (y & z));
}

static void sha256_transform(sha256_ctx_t *ctx, const unsigned char *data, uint32 len)
{
	uint32 a, b, c, d, e, f, g, h, i, j, t1, t2, m[64];

	while (len >= BLOCK_SIZE) {
		for (i = 0; i < 16; ++i)
			m[i] = (data[i*4] << 24) | (data[i*4+1] << 16) | (data[i*4+2] << 8) | data[i*4+3];
		for (; i < 64; ++i)
			m[i] = sigma1(m[i-2]) + m[i-7] + sigma0(m[i-15]) + m[i-16];

		a = ctx->state[0]; b = ctx->state[1]; c = ctx->state[2]; d = ctx->state[3];
		e = ctx->state[4]; f = ctx->state[5]; g = ctx->state[6]; h = ctx->state[7];

		for (i = 0; i < 64; ++i) {
			t1 = h + Ch(e, f, g) + sigma1(e) + m[i] + k[i];
			t2 = sigma0(a) + Maj(a, b, c);
			h = g; g = f; f = e; e = d + t1; d = c; c = b; b = a; a = t1 + t2;
		}

		ctx->state[0] += a; ctx->state[1] += b; ctx->state[2] += c; ctx->state[3] += d;
		ctx->state[4] += e; ctx->state[5] += f; ctx->state[6] += g; ctx->state[7] += h;

		data += BLOCK_SIZE;
		len -= BLOCK_SIZE;
	}
}

void sha256_init(sha256_ctx_t *ctx)
{
	ctx->state[0] = 0x6a09e667;
	ctx->state[1] = 0xbb67ae85;
	ctx->state[2] = 0x3c6ef372;
	ctx->state[3] = 0xa54ff53a;
	ctx->state[4] = 0x510e527f;
	ctx->state[5] = 0x9b05688c;
	ctx->state[6] = 0x1f83d9ab;
	ctx->state[7] = 0x5be0cd19;
	ctx->count = 0;
}

void sha256_update(sha256_ctx_t *ctx, const unsigned char *data, uint32 len)
{
	uint32 index = (uint32)(ctx->count & (BLOCK_SIZE-1));

	ctx->count += len;
	while (len--) {
		ctx->block[index++] = *data++;

		if (index == BLOCK_SIZE) {
			sha256_transform(ctx, ctx->block, BLOCK_SIZE);
			index = 0;
		}
	}
}

void sha256_final(sha256_ctx_t *ctx, unsigned char *digest)
{
	uint32 i;
	uint64 bcnt = ctx->count << 3;
	uint32 index = (uint32)(ctx->count & (BLOCK_SIZE-1));

	ctx->block[index++] = 0x80;

	if (index > 56) {
		while (index < BLOCK_SIZE)
			ctx->block[index++] = 0;
		sha256_transform(ctx, ctx->block, BLOCK_SIZE);
		index = 0;
	}

	while (index < 56)
		ctx->block[index++] = 0;

#ifdef __BIG_ENDIAN__
	ctx->block[56] = (bcnt >> 56) & 0xff;
	ctx->block[57] = (bcnt >> 48) & 0xff;
	ctx->block[58] = (bcnt >> 40) & 0xff;
	ctx->block[59] = (bcnt >> 32) & 0xff;
	ctx->block[60] = (bcnt >> 24) & 0xff;
	ctx->block[61] = (bcnt >> 16) & 0xff;
	ctx->block[62] = (bcnt >> 8) & 0xff;
	ctx->block[63] = bcnt & 0xff;
#else
	ctx->block[56] = bcnt & 0xff;
	ctx->block[57] = (bcnt >> 8) & 0xff;
	ctx->block[58] = (bcnt >> 16) & 0xff;
	ctx->block[59] = (bcnt >> 24) & 0xff;
	ctx->block[60] = (bcnt >> 32) & 0xff;
	ctx->block[61] = (bcnt >> 40) & 0xff;
	ctx->block[62] = (bcnt >> 48) & 0xff;
	ctx->block[63] = (bcnt >> 56) & 0xff;
#endif
	sha256_transform(ctx, ctx->block, BLOCK_SIZE);

	for (i = 0; i < 8; ++i) {
#ifdef __BIG_ENDIAN__
		uint32 w = ctx->state[i];
		digest[i*4] = (w >> 24) & 0xff;
		digest[i*4+1] = (w >> 16) & 0xff;
		digest[i*4+2] = (w >> 8) & 0xff;
		digest[i*4+3] = w & 0xff;
#else
		uint32 w = ENDIAN_SWAP_U32(ctx->state[i]);
		memcpy(digest + i * 4, &w, 4);
#endif
	}
}

int main()
{
    sha256_ctx_t ctx;
    unsigned char digest[32];
    char *msg = "Hello World!";
    uint32 msg_len = strlen(msg);

    sha256_init(&ctx);
    sha256_update(&ctx, (unsigned char*)msg, msg_len);
    sha256_final(&ctx, digest);

    printf("Input message: %s\n", msg);
    printf("SHA-256 Digest: ");
    for (int i = 0; i < 32; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");

    return 0;
}