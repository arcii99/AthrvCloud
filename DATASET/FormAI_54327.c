//FormAI DATASET v1.0 Category: Audio processing ; Style: Alan Touring
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096 //Size of the buffer.

int main() {
    double frequency = 440.0; //Set frequency 440 Hz.
    double amplitude = 0.5; //Set amplitude 0.5.
    double time = 0.0; //Initial time.
    double frequencyRatio = 2.0 * M_PI / 44100.0; //Calculate the frequency ratio.
    double phase = 0.0; //Initial phase.
    double leftChannel; //Left audio channel.
    double rightChannel; //Right audio channel.
    int i; //Counter variable.
    short int buffer[BUFFER_SIZE]; //Initialize buffer.

    FILE *outputFile = fopen("output.wav", "wb"); //Open binary file for writing.

    for(i = 0; i < 44100; i++) { //Loop through all audio samples.
        leftChannel = (amplitude * sin(phase)); //Calculate left audio channel.
        rightChannel = (amplitude * sin(phase)); //Calculate right audio channel.

        buffer[2 * i] = (short int)(leftChannel * 32767.0); //Convert left audio channel to 16-bit integer.
        buffer[2 * i + 1] = (short int)(rightChannel * 32767.0); //Convert right audio channel to 16-bit integer.

        phase += frequencyRatio * frequency; //Increment phase value.

        if(phase > 2.0 * M_PI) { //Check for overflow.
            phase -= 2.0 * M_PI;
        }

        time += 1.0 / 44100.0; //Increment time value.
    }

    fwrite(&buffer, sizeof(buffer), 1, outputFile); //Write buffer to file.

    fclose(outputFile); //Close file.

    return 0; //Return zero for successful exit.
}