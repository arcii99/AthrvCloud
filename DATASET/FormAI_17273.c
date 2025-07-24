//FormAI DATASET v1.0 Category: Compression algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIN_SIZE 1024
#define MATCH_LIMIT 65535

unsigned char window[WIN_SIZE];
unsigned short match_pos[WIN_SIZE];
unsigned short match_len[WIN_SIZE];
int win_idx, last_idx, num_match;

void flush_window()
{
    fwrite(&window[0], 1, WIN_SIZE, stdout);
    memset(&window[0], 0, WIN_SIZE);
}

void flush_match()
{
    if (num_match > 0)
    {
        for (int i = 0; i < num_match; i++)
        {
            unsigned char len = match_len[i] - 1;
            unsigned char out_byte = (match_pos[i] >> 8) & 0xFF;
            out_byte |= (len << 3);
            fwrite(&out_byte, 1, 1, stdout);
            fwrite(&match_pos[i], 2, 1, stdout);
        }
        memset(&match_pos[0], 0, WIN_SIZE * 2);
        memset(&match_len[0], 0, WIN_SIZE * 2);
        num_match = 0;
    }
}

void slide_window(int bytes)
{
    memcpy(&window[0], &window[bytes], WIN_SIZE - bytes);
    win_idx -= bytes;
    last_idx -= bytes;
}

void add_match(unsigned short pos, unsigned short len)
{
    if (num_match >= MATCH_LIMIT)
    {
        flush_match();
        return;
    }
    match_pos[num_match] = pos;
    match_len[num_match] = len;
    num_match++;
}

void find_matches()
{
    int best_len = 0;
    int num_bytes = 0;
    int start_idx = last_idx;
    for (int i = start_idx; i < start_idx + 256; i++)
    {
        if (window[i] == window[win_idx])
        {
            int j;
            for (j = 1; j < WIN_SIZE - win_idx && i + j < WIN_SIZE && window[i+j] == window[win_idx+j] && j < 256; j++)
                ;
            if (j > best_len)
            {
                best_len = j;
                num_bytes = i - start_idx;
            }
        }
    }
    if (best_len >= 3)
    {
        add_match(num_bytes, best_len);
        win_idx += best_len;
        last_idx = win_idx - 1;
    }
    else
    {
        last_idx = win_idx;
    }
}

int main()
{
    int in_byte;
    while ((in_byte = fgetc(stdin)) != EOF)
    {
        window[win_idx] = (unsigned char)in_byte;
        find_matches();
        if (win_idx == WIN_SIZE - 1)
        {
            flush_match();
            flush_window();
            win_idx = 0;
            last_idx = 0;
        }
        else
        {
            win_idx++;
        }
    }
    flush_match();
    flush_window();
    return 0;
}