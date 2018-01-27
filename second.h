#include<stdio.h>
#include<stdlib.h>
void insert(int);
void delete(int);
void print();
struct node{
	int data;
	struct node *next;
	};

struct node *head;



void insert(int data){
	struct node *link = (struct node*)malloc(sizeof(struct node));
	if(head==NULL){
		link->data = data;
		link->next = head;
		head = link;
		return;
	}
	else{
		
		struct node *pre = (struct node*)malloc(sizeof(struct node));
		pre=head;
		link = pre->next;
		if(head->data<data){
		while(link!=NULL){
			if(link->data<data){
				pre = link;
				link = link->next;
				}
			else if(link->data==data){
				return;
			}
			else{
				struct node *target = (struct node*)malloc(sizeof(struct node));
				target->data = data;
				target->next = link;
				pre->next = target;
				return;
				}
			}
		if(link==NULL){
			struct node *link2 = (struct node*)malloc(sizeof(struct node));
			link2->data = data;
			link2->next = NULL;
			pre->next = link2;
		return;	
		}
		}
		else if(head->data==data){
			return;
		}
		else{
			struct node *link3 = (struct node*)malloc(sizeof(struct node));
			link3->data = data;
			link3->next = head;
			head = link3;
			return;	}
	return;	}
}

void delete(int data){
	struct node *pre = (struct node*)malloc(sizeof(struct node));
	pre = head;
	if(pre == NULL){
		return;
	}
	if(pre->data == data){
		head = pre->next;
		free(pre);
		return;
	}
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp = pre->next;
	while(temp!=NULL){
		if(temp->data==data){
			pre->next = temp->next;
			free(temp);
			return;
	}
		else{

		temp=temp->next;
	}
	
	
	}
	return;
}
			
			 
			


void print(){
	struct node *ptr = head;
	while(ptr!=NULL){
		printf("%d\t", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}
	
