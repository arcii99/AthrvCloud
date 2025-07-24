//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//Statistical Cryptographic Hash Function
//This function treats the input string as a sequence of numbers and calculates their statistical properties to generate a hash value

unsigned long int stat_hash(char *str){

    int len = strlen(str);
    int i;
    double sum=0, avg, var=0, std_dev, skewness=0, kurtosis=0;

    for(i=0; i<len; i++){
        sum += (int)str[i];
    }

    avg = sum/len;

    for(i=0; i<len; i++){
        var += pow((int)str[i]-avg, 2);
    }

    var /= len;
    std_dev = sqrt(var);

    for(i=0; i<len; i++){
        skewness += pow(((int)str[i]-avg)/std_dev, 3)/len;
        kurtosis += pow(((int)str[i]-avg)/std_dev, 4)/len;
    }

    //combine the statistical measures to generate a hash value
    unsigned long int hash = (unsigned long int)(sum + var*1000 + std_dev*1000000 + skewness*1000000000 + kurtosis*1000000000000);

    return hash;
}

int main(){

    char str[100];
    printf("Enter a string: ");
    scanf("%[^\n]s", str);

    unsigned long int hash_val = stat_hash(str);
    printf("The hash value of '%s' is %lu\n", str, hash_val);

    return 0;
}