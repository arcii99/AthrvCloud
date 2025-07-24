//FormAI DATASET v1.0 Category: Firewall ; Style: recursive
#include <stdio.h>

void firewall(int n) {
  if(n<=0) {
    printf("Firewall stopped!\n");
    return;
  }
  printf("Incoming packet with source IP address: ");
  char ip[20];
  scanf("%s", ip);
  if(ip[0] == '1' && ip[1] == '0' && ip[2] == '.') {
    printf("Blocked!\n");
  } else {
    printf("Allowed!\n");
  }
  firewall(n-1);
}

int main() {
  printf("Firewall started!\n");
  printf("Please enter the number of packets to be checked: ");
  int n;
  scanf("%d", &n);
  firewall(n);
  return 0;
}