//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: intelligent
#include<stdio.h>
#include<string.h>

int minimum(int x, int y, int z){
    if(x<=y && x<=z){
        return x;
    }
    else if(y<=x && y<=z){
        return y;
    }
    else{
        return z;
    }
}

int levenshtein_distance(char* s1, char* s2, int m, int n){
    if(m==0){
        return n;
    }
    else if(n==0){
        return m;
    }
    else if(s1[m-1]==s2[n-1]){
        return levenshtein_distance(s1,s2,m-1,n-1);
    }
    else{
        return 1+minimum(levenshtein_distance(s1,s2,m-1,n),
        levenshtein_distance(s1,s2,m,n-1),
        levenshtein_distance(s1,s2,m-1,n-1));
    }
}

int main(){
    char s1[100], s2[100];
    printf("Enter first string: ");
    scanf("%s", s1);
    printf("Enter second string: ");
    scanf("%s", s2);
    int m = strlen(s1);
    int n = strlen(s2);
    int distance = levenshtein_distance(s1,s2,m,n);
    printf("Levenshtein distance between %s and %s is %d\n", s1, s2, distance);
    return 0;
}