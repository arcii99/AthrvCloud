//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* One-way hash function, also known as a cryptographic hash function
 * This uses the SHA-1 algorithm.
 * This function takes in a string and returns a 160-bit hash that is unique to the input
 */

// algorithm specific constants
#define K_0_19 0x5a827999
#define K_20_39 0x6ed9eba1
#define K_40_59 0x8f1bbcdc
#define K_60_79 0xca62c1d6
#define H0 0x67452301
#define H1 0xefcdab89
#define H2 0x98badcfe
#define H3 0x10325476
#define H4 0xc3d2e1f0

/* Data Structures */

typedef struct{
	uint32_t h0, h1, h2, h3, h4;
}hash_info;

typedef struct{
	uint32_t value;
	uint32_t index;
}word_info;

/* Function Prototypes */

void get_word_info(word_info *words, const char *input);
void hash_update(hash_info *hash, word_info *words);
void digest_output(uint32_t *digest, hash_info *hash);

/* Helper Functions */

// Left Circular Shift defined by the algorithm
static inline uint32_t lcs(uint32_t value, int bits)
{
	return ((value << bits) | (value >> (32 - bits)));
}

// Function to break up the input into 512-bit blocks
// Also appends the message length as the last 64 bits of the last block
void get_word_info(word_info *words, const char *input)
{
	int idx = 0;
	int blocks = strlen(input) / 64;
	
	// break message into 512-bit blocks
	for(int i = 0; i < blocks; i++)
	{
		// get 16 32-bit words for each 512-bit block
		for(int j = 0; j < 16; j++)
		{
			// concatenate 4 characters at a time for the word
			words[idx].value = ((uint32_t)(input[i*64 + j*4])) << 24;
			words[idx].value |= ((uint32_t)(input[i*64 + j*4 + 1])) << 16;
			words[idx].value |= ((uint32_t)(input[i*64 + j*4 + 2])) << 8;
			words[idx].value |= ((uint32_t)(input[i*64 + j*4 + 3]));
			words[idx].index = idx;
			idx++;
		}
	}
	
	// append message length in the last 64 bits of the last block
	for(int i = 0; i < 16; i++)
	{
		if(idx == 0)
			words[idx].value = 0;
		
		if(i == 14)
			words[idx].value = strlen(input) >> 29;
		else if(i == 15)
			words[idx].value = strlen(input) << 3;
		words[idx].index = idx;
		idx++;
	}
}

// Hash update: processing the 512-bit block
void hash_update(hash_info *hash, word_info *words)
{
	uint32_t temp;
	uint32_t a = hash->h0;
	uint32_t b = hash->h1;
	uint32_t c = hash->h2;
	uint32_t d = hash->h3;
	uint32_t e = hash->h4;
	
	for(int i = 0; i < 80; i++)
	{
		// Process function determined based on i
		if(i < 20)
			temp = lcs(a, 5) + ((b & c) | ((~b) & d)) + e + words[i].value + K_0_19;
		else if(i < 40)
			temp = lcs(a, 5) + (b ^ c ^ d) + e + words[i].value + K_20_39;
		else if(i < 60)
			temp = lcs(a, 5) + ((b & c) | (b & d) | (c & d)) + e + words[i].value + K_40_59;
		else
			temp = lcs(a, 5) + (b ^ c ^ d) + e + words[i].value + K_60_79;
		
		e = d;
		d = c;
		c = lcs(b, 30);
		b = a;
		a = temp;
	}
	
	hash->h0 += a;
	hash->h1 += b;
	hash->h2 += c;
	hash->h3 += d;
	hash->h4 += e;
}

// Function to output the hash, as 5 32-bit values
void digest_output(uint32_t *digest, hash_info *hash)
{
	digest[0] = hash->h0;
	digest[1] = hash->h1;
	digest[2] = hash->h2;
	digest[3] = hash->h3;
	digest[4] = hash->h4;
}

/* Main Function */

int main()
{
	// Input message to hash
	char input[1000];

	printf("Enter a message to hash using SHA-1 algorithm: ");
	fgets(input, 1000, stdin);

	hash_info hash = {H0, H1, H2, H3, H4};
	word_info words[80];

	get_word_info(words, input);
	
	// Hash update for each 512-bit block
	for(int i = 0; i < strlen(input)/64 + 1; i++)
	{
		hash_update(&hash, &words[i*16]);
	}
	
	uint32_t digest[5];
	digest_output(digest, &hash);
	
	printf("The SHA-1 hash for \"%s\" is: %08x%08x%08x%08x%08x\n", input, digest[0], digest[1], digest[2], digest[3], digest[4]);
	
	return 0;
}