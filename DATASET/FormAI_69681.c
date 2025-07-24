//FormAI DATASET v1.0 Category: Audio processing ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function to read audio file
void read_audio_file(char* file_name, int* data_size, int* sample_rate, short** audio_data)  
{
    FILE* fp = fopen(file_name, "rb");       // open the audio file
    fseek(fp, 0L, SEEK_END);                // seek to end of file
    *data_size = ftell(fp);                 // get file size
    fseek(fp, 0L, SEEK_SET);                // seek to beginning of file
  
    // get sample rate
    char header[44];
    fread(header, sizeof(header), 1, fp);
    *sample_rate = header[24] + header[25] * pow(2, 8) + header[26] * pow(2, 16) + header[27] * pow(2, 24);

    // read audio data
    *audio_data = (short*)malloc(sizeof(char) * (*data_size - 44));
    fseek(fp, 44L, SEEK_SET);
    fread(*audio_data, sizeof(char), *data_size - 44, fp);
    fclose(fp);
}

// function to write processed audio to file
void write_audio_file(char* file_name, int sample_rate, short* audio_data, int data_size)  
{
    FILE* fp = fopen(file_name, "wb");      // open the output audio file

    // write header
    char header[44];
    int byte_rate = sample_rate * sizeof(short);
    int block_align = sizeof(short);
    int sub_chunk2_size = data_size * sizeof(short);
    int chunk_size = 36 + sub_chunk2_size;
    header[0] = 'R'; header[1] = 'I'; header[2] = 'F'; header[3] = 'F';
    header[4] = (chunk_size >> 0) & 0xff; header[5] = (chunk_size >> 8) & 0xff; header[6] = (chunk_size >> 16) & 0xff; header[7] = (chunk_size >> 24) & 0xff;
    header[8] = 'W'; header[9] = 'A'; header[10] = 'V'; header[11] = 'E';
    header[12] = 'f'; header[13] = 'm'; header[14] = 't'; header[15] = ' ';
    header[16] = 16; header[17] = 0; header[18] = 0; header[19] = 0;
    header[20] = 1; header[21] = 0; header[22] = 1; header[23] = 0;
    header[24] = (sample_rate >> 0) & 0xff; header[25] = (sample_rate >> 8) & 0xff; header[26] = (sample_rate >> 16) & 0xff; header[27] = (sample_rate >> 24) & 0xff;
    header[28] = (byte_rate >> 0) & 0xff; header[29] = (byte_rate >> 8) & 0xff; header[30] = (byte_rate >> 16) & 0xff; header[31] = (byte_rate >> 24) & 0xff;
    header[32] = (block_align >> 0) & 0xff; header[33] = (block_align >> 8) & 0xff;
    header[34] = 16; header[35] = 0;
    header[36] = 'd'; header[37] = 'a'; header[38] = 't'; header[39] = 'a';
    header[40] = (sub_chunk2_size >> 0) & 0xff; header[41] = (sub_chunk2_size >> 8) & 0xff; header[42] = (sub_chunk2_size >> 16) & 0xff; header[43] = (sub_chunk2_size >> 24) & 0xff;
    fwrite(header, sizeof(header), 1, fp);

    // write audio data
    fwrite(audio_data, sizeof(short), data_size, fp);
    fclose(fp);
}

// function to apply bandpass filter on audio data
void bandpass_filter(short* audio_data, int data_size, float low_cut_freq, float high_cut_freq, int sample_rate)
{
    int i, j;
    float sample_time = 1.0 / sample_rate;
    float* filter = (float*)calloc(data_size, sizeof(float));
    float low_freq = 2 * M_PI * low_cut_freq;
    float high_freq = 2 * M_PI * high_cut_freq;

    // generate filter
    for (i = 0; i < data_size; i++) 
    {
        filter[i] = (sin(high_freq * i * sample_time) - sin(low_freq * i * sample_time)) / (M_PI * i);
    }

    // apply filter on audio data
    float sum = 0;
    for (i = 0; i < data_size; i++) 
    {
        sum = 0;
        for (j = i; j >= 0; j--) 
        {
            sum += audio_data[j] * filter[i - j];
        }
        audio_data[i] = (short)sum;
    }

    free(filter);
}

int main(int argc, char** argv)  
{
    if (argc != 5) 
    {
        printf("Incorrect number of arguments! Usage: ./audio_processor <input_file> <output_file> <low_cut_freq> <high_cut_freq>\n");
        return 1;
    }

    char* input_file_name = argv[1];
    char* output_file_name = argv[2];
    float low_cut_freq = atof(argv[3]);
    float high_cut_freq = atof(argv[4]);

    int data_size, sample_rate;
    short* audio_data;

    // read input audio file
    read_audio_file(input_file_name, &data_size, &sample_rate, &audio_data);

    // apply bandpass filter
    bandpass_filter(audio_data, data_size, low_cut_freq, high_cut_freq, sample_rate);

    // write output audio file
    write_audio_file(output_file_name, sample_rate, audio_data, data_size);

    return 0;
}