//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: careful
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int a, b, c, n, bits=32;
	printf("Enter IP address in decimal form (xxx.xxx.xxx.xxx): ");
	scanf("%d.%d.%d.%d", &a, &b, &c, &n);
	
	if(a>255 || b>255 || c>255 || n>255){
		printf("Invalid IP address.\n");
		return 0;
	}
	
	char binaryIP[33];
	memset(binaryIP, '0', sizeof(binaryIP));
	binaryIP[32] = '\0';
	for(int i=0; i<n; i++){
		binaryIP[i] = '1';
	}
	
	int subnetMask[4] = {0,0,0,0};
	for(int i=0; i<bits; i++){
		if(i<8) subnetMask[0] += (binaryIP[i] - '0') * pow(2, (7 - i));
		else if(i<16) subnetMask[1] += (binaryIP[i] - '0') * pow(2, (15 - i));
		else if(i<24) subnetMask[2] += (binaryIP[i] - '0') * pow(2, (23 - i));
		else if(i<32) subnetMask[3] += (binaryIP[i] - '0') * pow(2, (31 - i));
	}
	
	printf("Subnet mask: %d.%d.%d.%d\n", subnetMask[0], subnetMask[1], subnetMask[2], subnetMask[3]);
	printf("Number of subnets: %d\n", pow(2, n));
	printf("Number of hosts per subnet: %d\n", pow(2, (bits-n)) - 2);
	
	return 0;
}