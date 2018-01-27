#include<stdio.h>
#include<stdlib.h>
#include"third.h"
int main(int argc, char** argv){
	FILE *fPtr;
	fPtr = fopen(argv[1],"r");
	if(fPtr==NULL){
		printf("error\n");
		return 0;
	}
	


else{
		char is;
		struct hashtable *Nhash = Hcreate(10000);
		int num;
		int key;
		int count;
		
	if(feof(fPtr)){
		printf("\n");
		return 0;
	}
	while(!feof(fPtr)){
		count = fscanf(fPtr, "%c\t%d\n",&is,&num);
		if(count==2){
			if(is=='i')
				{
				if(num<0){
					key = num*(-1);
				}
				else if(num==0){
					key=num;
					num=1;
				}
				else{
					key = num;
					}
				if(search(num,Nhash->table[key%10000])=='y'){
					printf("duplicate\n");
						}
				else{
					insert(num,Nhash->table[key%10000]);
					printf("inserted\n");
					}
				}
				
			else if(is=='s'){
				if(num<0){
					key = num*(-1);
					}
				else if(num==0){
					key=num;
					num=1;
				}
				else{
					key = num;
					}
				if(search(num,Nhash->table[key%10000])=='y'){
					printf("present\n");
					}
				else{
					printf("absent\n");
					}
				}
			else{
				printf("error\n");
				}
			}
		else{
			if(ftell(fPtr)!=0){
			printf("error\n");
			exit(0);
			}
			else{
			printf("\n");
			return 0;
			}
}		
}	
		int count1;
		for(count1=0;count1<10000;count1++){
			free(Nhash->table[count1]);
		}
		free(Nhash);
	}		
		fclose(fPtr);
	
			return 0;
	}	
