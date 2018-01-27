#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
	};


char search(int, struct node*);


struct hashtable{
	int size;
	struct node** table;};

struct hashtable* Hcreate(int);

struct hashtable* Hcreate(int size){
	struct hashtable *Htable = (struct hashtable*)malloc(sizeof(struct hashtable));
	Htable->size = size;
	Htable->table = (struct node**)malloc(sizeof(struct node*)*size);
	int i;
	for(i=0;i<size;i++){
		Htable->table[i]=(struct node*)malloc(sizeof(struct node));
		Htable->table[i]->data=0;
	}return Htable;
}





char search(int data,struct node* head){
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	ptr = head;
	while(ptr!=NULL){
		if(ptr->data==data){
			return 'y';
		}
		ptr = ptr->next;
		
	
	}
	return 'n';
	}




void insert(int data,struct node* head){
	
	struct node *link = (struct node*)malloc(sizeof(struct node));
	link->data = data;
	link->next = NULL;
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	ptr = head;
	if(ptr==NULL){
		head=link;
	}
	else{
	while(ptr->next!=NULL){
		ptr=ptr->next;
		}
	ptr->next = link;

	
	}
}
		
