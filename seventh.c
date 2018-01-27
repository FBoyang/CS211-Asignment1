#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char** argv){
	if(argc<2){
		printf("error\n");
		exit(0);
	}
	
	int count;
	int i;
	for(count=1;count<argc;count++){
		i = strlen(argv[count]);
		printf("%c",argv[count][i-1]);
	}

	printf("\n");
	return 0;
}	
