//FormAI DATASET v1.0 Category: Audio processing ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

main(){
    printf("Enter the name of the audio file you want to process.\n");
    char filename[50];
    scanf("%s",filename);

    FILE* file=fopen(filename,"rb");  
    int buf[1024];

    printf("Processing audio file...\n");

    int count=0;
    while(!feof(file)){
        fread(buf,sizeof(int),1024,file);
        //apply some audio processing here (FIR filter, FFT, etc...)
        count++;
    }

    fclose(file);
    printf("%d samples processed.\n",count);
}