#include<stdio.h>
#include<stdlib.h>
#include"second.h"
#include<string.h>
int main(int argc, char* argv[]){
	//	char file[100];
	//strcpy(file,argv[1]);

	// if no arguments, return error

	FILE *fPointer;
	//fPointer = fopen(file,"r");
	fPointer = fopen(argv[1], "r");
	if(fPointer==NULL){
		printf("error\n");
		exit(0);
	}
	
	char c;
	int num;
	int count;
	head =NULL;
	while(!feof(fPointer)){
	count = fscanf(fPointer,"%c\t%d\n",&c,&num);
	//c = fgetc(fPointer);
	//fgets(s,60,fPointer);
		if(count==2){
		if(c=='i'){
			insert(num);
		}
		else if(c=='d'){
			delete(num);
		}
		else{
			printf("error\n");
			exit(0);
		}
	}
		else{
		if(ftell(fPointer)!=0){
		printf("error\n");
		exit(0);
		}
		else{
		printf("\n");
		return 0;	
	}
	
}
}
	print();
	fclose(fPointer);
	
	return 0;
	}

