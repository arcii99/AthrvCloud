//FormAI DATASET v1.0 Category: Audio processing ; Style: Dennis Ritchie
#include <stdio.h>

//function declaration
void processAudio(char audio_data[], int data_size, int process_type);

int main()
{
    char audio_data[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    int data_size = sizeof(audio_data)/sizeof(audio_data[0]);
    int process_type = 2;

    processAudio(audio_data, data_size, process_type);

    return 0;
}

//function definition
void processAudio(char audio_data[], int data_size, int process_type)
{
    switch(process_type)
    {
        case 1:
            for(int i=0; i<data_size; i++)
            {
                audio_data[i]+=1; //incrementing each data element by 1
            }
            break;
        case 2:
            for(int i=0; i<data_size; i++)
            {
                if(audio_data[i]>='a' && audio_data[i]<='z')
                {
                    audio_data[i]-=32; //converting the data element to uppercase
                }
            }
            break;
        case 3:
            for(int i=0; i<data_size; i++)
            {
                if(audio_data[i]>='a' && audio_data[i]<='z')
                {
                    audio_data[i]+=1; //incrementing each lowercase data element by 1
                }
                else if(audio_data[i]>='A' && audio_data[i]<='Z')
                {
                    audio_data[i]-=1; //decrementing each uppercase data element by 1
                }
            }
            break;
        default:
            printf("Invalid process type!");
    }

    //printing the processed audio data
    printf("Processed audio data:\n");
    for(int i=0; i<data_size; i++)
    {
        printf("%c ", audio_data[i]);
    }
}