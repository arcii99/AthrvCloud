//FormAI DATASET v1.0 Category: Compression algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 256
#define MAX_CODES 256

typedef struct {
    unsigned int code;
    unsigned char length;
} Code;

typedef struct {
    Code codes[MAX_CODES];
    unsigned int num_codes;
} Codes;

void print_codes(Codes *codes) {
    printf("codes:\n");
    for (int i = 0; i < codes->num_codes; i++) {
        printf("%02x %d\n", codes->codes[i].code, codes->codes[i].length);
    }
}

void init_codes(Codes *codes) {
    codes->num_codes = 0;
    for (int i = 0; i < MAX_CODES; i++) {
        codes->codes[i].code = 0;
        codes->codes[i].length = 0;
    }
}

Code get_code(Codes *codes, unsigned char ch) {
    for (int i = 0; i < codes->num_codes; i++) {
        if (codes->codes[i].code == ch) {
            return codes->codes[i];
        }
    }

    Code new_code = {
        .code = ch,
        .length = 1,
    };
    codes->codes[codes->num_codes++] = new_code;

    return new_code;
}

void encode(FILE *infile, FILE *outfile, Codes *codes) {
    unsigned char inbuf[MAX_CHARS];
    unsigned char outbuf[MAX_CHARS * 2];
    int inlen;
    int outlen;
    int pos;

    while ((inlen = fread(inbuf, 1, MAX_CHARS, infile)) > 0) {
        pos = 1;
        outlen = 1;

        while (pos <= inlen) {
            Code code = get_code(codes, inbuf[pos-1]);
            memcpy(outbuf + outlen, &code.code, code.length);
            pos++;
            outlen += code.length;
        }

        fwrite(outbuf, 1, outlen, outfile);
    }
}

void decode(FILE *infile, FILE *outfile, Codes *codes) {
    unsigned char inbuf[MAX_CHARS * 2];
    unsigned char outbuf[MAX_CHARS];
    int inlen;
    int outlen;
    int pos;

    while ((inlen = fread(inbuf, 1, MAX_CHARS*2, infile)) > 0) {
        pos = 0;
        outlen = 0;

        while (pos < inlen) {
            unsigned char ch = 0;
            unsigned char mask = 0x80;
            int length = 0;

            while (mask > 0 && pos < inlen) {
                if (inbuf[pos++] & mask) {
                    ch |= mask;
                }
                mask >>= 1;
                length++;
            }

            Code code = get_code(codes, ch);
            outbuf[outlen++] = code.code;
        }

        fwrite(outbuf, 1, outlen, outfile);
    }
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s encode|decode infile outfile\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *infile = fopen(argv[2], "rb");
    if (!infile) {
        fprintf(stderr, "Could not open input file: %s\n", argv[2]);
        return EXIT_FAILURE;
    }

    FILE *outfile = fopen(argv[3], "wb");
    if (!outfile) {
        fprintf(stderr, "Could not open output file: %s\n", argv[3]);
        fclose(infile);
        return EXIT_FAILURE;
    }

    Codes codes;
    init_codes(&codes);

    if (strcmp(argv[1], "encode") == 0) {
        encode(infile, outfile, &codes);
    } else if (strcmp(argv[1], "decode") == 0) {
        decode(infile, outfile, &codes);
    } else {
        fprintf(stderr, "Invalid command: %s\n", argv[1]);
        fclose(infile);
        fclose(outfile);
        return EXIT_FAILURE;
    }

    fclose(infile);
    fclose(outfile);

    return EXIT_SUCCESS;
}