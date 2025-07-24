//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    //Conspiracy Theories Array
    char* conspiracyTheories[] = {"The moon landing was faked by NASA", "The government is controlling our minds with chemtrails", "The earth is flat and everyone is lying to us", "Aliens are among us and the government is hiding it", "The Illuminati control everything in the world", "The world is ending in 2020 and only the elite will survive", "9/11 was an inside job by the government", "The Titanic never really sank and was swapped with its sister ship"};

    //Random Seed
    srand(time(NULL));

    //Unique Number Generator
    int uniqueNum;
    int* uniqueNums = malloc(sizeof(int) * 8); //8 conspiracy theories
    int i, j, existed;

    //Random Conspiracy Theories Generator
    for(i=0; i<8; i++){
        do{
            existed = 0;
            uniqueNum = rand() % 8;
            for(j=0; j<i; j++){
                if(uniqueNum == uniqueNums[j]){
                    existed = 1;
                    break;
                }
            }
        } while(existed == 1);
        uniqueNums[i] = uniqueNum;
        printf("Conspiracy Theory #%d: %s\n", i+1, conspiracyTheories[uniqueNums[i]]);
    }

    //Free Memory
    free(uniqueNums);

    return 0;
}