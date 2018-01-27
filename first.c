#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main(int argc, char** argv){
	
	if(argc!=2){
		printf("error\n");
		exit(0);
	}
	int count;
	for(count=0;count<strlen(argv[1]);count++){
		if(isdigit(argv[1][count])==0){
			printf("error\n");
			exit(0);
		}
	}
	int num;
	num = atoi(argv[1]);
	if(num<=0){
		printf("error\n");
		exit(0);
	}
	int i;
	for(i=num-1;i>1;i--){
		if(num%i==0){
			printf("no\n");
			return 0;
		}
	}
	if(num==1){
		printf("no\n");
		return 0;
	}
	else{
		printf("yes\n");
	return 0;
	}
}

