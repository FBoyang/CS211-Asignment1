#include<stdio.h>
#include<stdlib.h>
int main(int argc, char** argv){
	if(argc<2){
		printf("error\n");
		return 0;
	}
	int num;
	char* acr;
	acr= (char*)malloc(sizeof(char)*(argc-1));
	for(num=1;num<argc;num++){
		acr[num]=argv[num][0];
		printf("%c",acr[num]);
		}
	printf("\n");
	//printf("%s\n", acr);
	free(acr);
	return 0;
}
