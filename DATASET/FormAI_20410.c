//FormAI DATASET v1.0 Category: Compression algorithms ; Style: content
/* 
 
Compression Algorithm
 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define DEBUG 0 // set to 1 for debug mode

/* define maximum length for the sequence */
#define MAX_SEQ_LENGTH 255

/* define maximum length of the buffer */
#define BUFFER_SIZE 1024

/* define maximum length of the output */
#define MAX_OUTPUT_SIZE (MAX_SEQ_LENGTH+2)*(BUFFER_SIZE/MAX_SEQ_LENGTH)

/* prototypes */
int compress_seq(unsigned char* in_seq, int in_size, unsigned char* out_seq, int out_size);
int find_match(unsigned char* seq, int seq_len, unsigned char* buf, int buf_len, int buf_pos, int* match_pos, int* match_len);
void print_seq(unsigned char* seq, int seq_len);
void print_compressed_seq(unsigned char* seq, int seq_len);

int main()
{
   unsigned char in_seq[MAX_SEQ_LENGTH+1] = "hello world!!";
   unsigned char buf[BUFFER_SIZE]; 
   unsigned char out_seq[MAX_OUTPUT_SIZE];
   int in_size = strlen(in_seq); // size of input sequence
   int buf_size = 0; // size of buffer
   int i = 0; // loop variable
   int out_size = 0; // size of output sequence
   int bytes_written = 0; // bytes written to output
   int comp_size = 0; // compressed size
   int read_pos = 0; // position for reading from input sequence

   /* compress the input sequence */
   comp_size = compress_seq(in_seq, in_size, out_seq, MAX_OUTPUT_SIZE);

   /* print the compressed sequence */
   print_compressed_seq(out_seq, comp_size);

   return 0;
}

/* Function to compress a given sequence */
int compress_seq(unsigned char* in_seq, int in_size, unsigned char* out_seq, int out_size)
{
   unsigned char buf[BUFFER_SIZE]; // buffer for storing sequence
   int buf_size = 0; // size of the buffer
   int i = 0; // loop variable
   int out_pos = 0; // position in output sequence
   int comp_size = 0; // compressed size
   int match_pos = 0; // position of matching sequence
   int match_len = 0; // length of matching sequence

   /* scan input sequence */
   while(i<in_size)
   {
      /* get the next matching sequence */
      int res = find_match(in_seq, in_size, buf, buf_size, i, &match_pos, &match_len);

      if(match_len > 0) // a match was found
      {
         /* output marker for match */
         out_seq[out_pos++] = (unsigned char)match_pos;
         out_seq[out_pos++] = (unsigned char)match_len;

         /* update compressed size */
         comp_size++;

         /* update input position */
         i += match_len;
      }
      else // no match found
      {
         /* add current character to buffer */
         buf[buf_size++] = in_seq[i++];

         /* if buffer is full, output uncompressed data */
         if(buf_size == BUFFER_SIZE || i == in_size)
         {
            /* output marker for uncompressed sequence */
            out_seq[out_pos++] = 0;
            out_seq[out_pos++] = buf_size;

            /* output uncompressed sequence */
            memcpy(out_seq+out_pos, buf, buf_size);
            out_pos += buf_size;

            /* update compressed size */
            comp_size += buf_size+2;

            /* reset buffer */
            buf_size = 0;
         }
      }
   }

   /* update output size */
   out_size = out_pos;

   return out_size;
}

/* Function to find a matching sequence in the buffer */
int find_match(unsigned char* seq, int seq_len, unsigned char* buf, int buf_len, int buf_pos, int* match_pos, int* match_len)
{
   int i = 0;
   int j = 0;
   int max_match_len = 0;
   int max_match_pos = 0;

   /* search for matching sequence */
   for(i=0; i<buf_len; i++)
   {
      int cur_match_len = 0;
      for(j=0; j<seq_len-buf_pos && j<buf_len-i; j++)
      {
         if(seq[buf_pos+j] == buf[i+j])
         {
            cur_match_len++;
         }
         else
         {
            break;
         }
      }

      if(cur_match_len > max_match_len)
      {
         max_match_len = cur_match_len;
         max_match_pos = i;
      }
   }

   /* set match position and length */
   if(max_match_len > 0)
   {
      *match_pos = max_match_pos;
      *match_len = max_match_len;
   }

   return max_match_len;
}

/* Function to print a sequence for debugging */
void print_seq(unsigned char* seq, int seq_len)
{
   int i=0;
   for(i=0; i<seq_len; i++)
   {
      printf("%c", seq[i]);
   }

   printf("\n");
}

/* Function to print a compressed sequence for debugging */
void print_compressed_seq(unsigned char* seq, int seq_len)
{
   int i=0;
   for(i=0; i<seq_len; i++)
   {
      printf("%02x ", seq[i]);
   }

   printf("\n");
}