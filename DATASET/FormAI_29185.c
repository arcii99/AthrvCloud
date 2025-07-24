//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: sophisticated
#include<stdio.h>
#include<string.h>

int min(int a, int b, int c){
    if(a<b && a<c)
        return a;
    else if(b<a && b<c)
        return b;
    else
        return c;
}

int lev_dis(char* str1, char* str2, int len1, int len2){
    int lev[len1+1][len2+1];
    int i,j;
    for(i=0;i<=len1;i++){
        for(j=0;j<=len2;j++){
            if(i==0)
                lev[i][j] = j;
            else if(j==0)
                lev[i][j] = i;
            else if(str1[i-1]==str2[j-1])
                lev[i][j] = lev[i-1][j-1];
            else
                lev[i][j] = 1+min(lev[i-1][j],lev[i][j-1],lev[i-1][j-1]);
        }
    }
    return lev[len1][len2];
}

int main(){
    char str1[100],str2[100];
    printf("Enter first string: ");
    scanf("%s",str1);
    printf("Enter second string: ");
    scanf("%s",str2);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int lev_distance = lev_dis(str1,str2,len1,len2);
    printf("Levenshtein distance between %s and %s is %d\n",str1,str2,lev_distance);
    return 0;
}