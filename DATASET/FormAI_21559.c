//FormAI DATASET v1.0 Category: Chess engine ; Style: Cryptic
#include <stdio.h>
#define LOWER 0
#define UPPER 7
int main(){
char board[64];
int n=0,i,a;
 while(n<64){
 board[n]=0;
 n++;
 }
 board[0]='r';board[1]='n';board[2]='b';board[3]='q';
 board[4]='k';board[5]='b';board[6]='n';board[7]='r';
 for(i=LOWER;i<=UPPER;i++){
 board[8+i]='p';
 }
 for(i=48; i<=55; i++){
 board[i]='P';
 }
 board[56]='R';board[57]='N';board[58]='B';board[59]='Q';
 board[60]='K';board[61]='B';board[62]='N';board[63]='R';

 a=1;
 while(a==1){
 printf("\n\n");
 for(i=LOWER;i<=UPPER;i++){
 printf(" %c",97+i);
 }
 n=LOWER;
 while(n<64){
 if(n%8==0){
 printf("\n");
 printf("%d ",n/8+1);
 }
 printf("%c",board[n]);
 n++;
 }
 printf("\n\n");
 printf("enter position of piece: ");
 scanf("%d",&i);

 if(board[i]!='\0'){
 printf("possible moves for %c at position %d are: ",board[i],i);


 if(board[i]=='P'&&board[i+8]=='\0'){
 printf("%d ",i+8);
 if(board[i+16]=='\0'&&i>=8&&i<=15){
 printf("%d ",i+16);
 }
 }
 if(board[i]=='p'&&board[i-8]=='\0'){
 printf("%d ",i-8);
 if(board[i-16]=='\0'&&i>=48&&i<=55){
 printf("%d ",i-16);
 }
 }
 if(board[i]=='R'){
 n=i+8;
 while(n<56){
 if(board[n]=='\0')
 printf("%d ",n);
 else{
 if(board[n-8]>96)
 printf("%d\n",n);
 break;
 }
 n+=8;
 }
 n=i-8;
 while(n>7){
 if(board[n]=='\0')
 printf("%d ",n);
 else{
 if(board[n+8]>96)
 printf("%d ",n);
 break;
 }
 n-=8;
 }
 n=i+1;
 while(n%8!=0){
 if(board[n]=='\0')
 printf("%d ",n);
 else{
 if(board[n-1]>96)
 printf("%d ",n);
 break;
 }
 n+=1;
 }
 n=i-1;
 while(n%8!=7&&n>=0){
 if(board[n]=='\0')
 printf("%d ",n);
 else{
 if(board[n+1]>96)
 printf("%d ",n);
 break;
 }
 n-=1;
 }
 }
 if(board[i]=='B'){
 n=i+9;
 while(n%8!=0&&n<64){
 if(board[n]=='\0')
 printf("%d ",n);
 else{
 if(board[n-9]>96)
 printf("%d ",n);
 break;
 }
 n+=9;
 }
 n=i-9;
 while(n%8!=7&&n>=0){
 if(board[n]=='\0')
 printf("%d ",n);
 else{
 if(board[n+9]>96)
 printf("%d ",n);
 break;
 }
 n-=9;
 }
 n=i+7;
 while(n%8!=7&&n<64){
 if(board[n]=='\0')
 printf("%d ",n);
 else{
 if(board[n-7]>96)
 printf("%d ",n);
 break;
 }
 n+=7;
 }
 n=i-7;
 while(n%8!=0&&n>=0){
 if(board[n]=='\0')
 printf("%d ",n);
 else{
 if(board[n+7]>96)
 printf("%d ",n);
 break;
 }
 n-=7;
 }
 }
 if(board[i]=='N'){
 if(i%8<=5&&i<48){
 if(board[i+17]=='\0'||board[i+17]>96)
 printf("%d ",i+17);
 }
 if(i%8<=5&&i>15){
 if(board[i-15]=='\0'||board[i-15]>96)
 printf("%d ",i-15);
 }
 if(i%8>=2&&i<48){
 if(board[i+15]=='\0'||board[i+15]>96)
 printf("%d ",i+15);
 }
 if(i%8>=2&&i>15){
 if(board[i-17]=='\0'||board[i-17]>96)
 printf("%d ",i-17);
 }
 if(i%8>=1&&i<56){
 if(board[i+10]=='\0'||board[i+10]>96)
 printf("%d ",i+10);
 }
 if(i%8>=1&&i>7){
 if(board[i-6]=='\0'||board[i-6]>96)
 printf("%d ",i-6);
 }
 if(i%8<=6&&i<56){
 if(board[i+6]=='\0'||board[i+6]>96)
 printf("%d ",i+6);
 }
 if(i%8<=6&&i>7){
 if(board[i-10]=='\0'||board[i-10]>96)
 printf("%d ",i-10);
 }
 }
 if(board[i]=='Q'){
 n=i+8;
 while(n<56){
 if(board[n]=='\0')
 printf("%d ",n);
 else{
 if(board[n-8]>96)
 printf("%d ",n);
 break;
 }
 n+=8;
 }
 n=i-8;
 while(n>7){
 if(board[n]=='\0')
 printf("%d ",n);
 else{
 if(board[n+8]>96)
 printf("%d ",n);
 break;
 }
 n-=8;
 }
 n=i+1;
 while(n%8!=0){
 if(board[n]=='\0')
 printf("%d ",n);
 else{
 if(board[n-1]>96)
 printf("%d ",n);
 break;
 }
 n+=1;
 }
 n=i-1;
 while(n%8!=7&&n>=0){
 if(board[n]=='\0')
 printf("%d ",n);
 else{
 if(board[n+1]>96)
 printf("%d ",n);
 break;
 }
 n-=1;
 }
 n=i+9;
 while(n%8!=0&&n<64){
 if(board[n]=='\0')
 printf("%d ",n);
 else{
 if(board[n-9]>96)
 printf("%d ",n);
 break;
 }
 n+=9;
 }
 n=i-9;
 while(n%8!=7&&n>=0){
 if(board[n]=='\0')
 printf("%d ",n);
 else{
 if(board[n+9]>96)
 printf("%d ",n);
 break;
 }
 n-=9;
 }
 n=i+7;
 while(n%8!=7&&n<64){
 if(board[n]=='\0')
 printf("%d ",n);
 else{
 if(board[n-7]>96)
 printf("%d ",n);
 break;
 }
 n+=7;
 }
 n=i-7;
 while(n%8!=0&&n>=0){
 if(board[n]=='\0')
 printf("%d ",n);
 else{
 if(board[n+7]>96)
 printf("%d ",n);
 break;
 }
 n-=7;
 }
 }
 }
 else{
 printf("that's not a piece\n");
 }
 }
return(0);
}