//FormAI DATASET v1.0 Category: Digital signal processing ; Style: scalable
#include<stdio.h>

//function to normalize the signal between -1 to 1
void normalize(float* signal, int len){
    float max=0;
    for(int i=0;i<len;i++){
        if(signal[i]>max) max=signal[i];
    }
    for(int i=0;i<len;i++){
        signal[i]/=max;
    }
}

//function to add two signals
void add_signal(float* s1, float* s2, int len){
    for(int i=0;i<len;i++){
        s1[i]+=s2[i];
    }
}

int main(){
    int len=10;
    float signal1[]={0.2,0.6,0.1,-0.3,-0.4,0.5,0.3,-0.2,-0.9,0.2};
    float signal2[]={-0.1,0.3,0.2,-0.2,-0.4,0.3,0.2,-0.1,-0.1,-0.2};
    
    //normalize signal1
    normalize(signal1,len);
    
    //add signal1 and signal2
    add_signal(signal1,signal2,len);
    
    //print the result
    for(int i=0;i<len;i++){
        printf("%f ",signal1[i]);
    }
    return 0;
}