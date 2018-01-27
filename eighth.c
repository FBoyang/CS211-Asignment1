#include<stdio.h>
#include<stdlib.h>

struct TreeNode{
	int key;
	struct TreeNode *right;
	struct TreeNode *left;
};
	
		

struct TreeNode* insert(int key,struct TreeNode* tree,int level){
		if(tree==NULL){
			struct TreeNode* node=(struct TreeNode*)malloc(sizeof(struct TreeNode));
			node->key = key;
			node->right=NULL;
			node->left = NULL;
			tree = node;
			printf("inserted %d\n",level);
			return tree;
		}
		
		else{
			if(tree->key ==key){
				printf("duplicate\n");
				return tree;
			}
		
			else if(tree->key>key){
					tree->left = insert(key,tree->left,level+1);
				}
				else{
					tree->right = insert(key,tree->right,level+1);
				}
			}
	return tree;
	}




void search(int key, struct TreeNode* tree,int level){
	struct TreeNode* ptr = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	ptr=tree;
	
	if(ptr==NULL){
		printf("absent\n");
		return;
	}

	else if(ptr->key==key){
		printf("present %d\n",level);
		return;
	}

	else{
		if(ptr->key>key){
			search(key,ptr->left,level+1);
		}
		else{
			search(key,ptr->right,level+1);
		}
	}
}

void freeTree(struct TreeNode **tree){
	if(*tree==NULL){
		free(*tree);
		return;
	}
	struct TreeNode *Lptr = (*tree)->left;
	struct TreeNode *Rptr = (*tree)->right;
	freeTree(&Lptr);
	freeTree(&Rptr);
	}
	
	
	
int main(int argc, char** argv){
	if(argc!=2){
		printf("error\n");
		return 0;
	}

	FILE *fPtr;
	fPtr = fopen(argv[1],"r");
	int check;
	int key;
	int level;
	char c;
	struct TreeNode* tree = NULL;
	while(!feof(fPtr)){
		check=fscanf(fPtr,"%c\t%d\n",&c,&key);
		if(check==2){
			level=1;
			if(c=='i'){
				tree = insert(key,tree,level);
			}
			else if(c=='s'){
				search(key,tree,level);
			}

			else{
				printf("error\n");
			}
		}
		else{
			printf("error\n");
			return 0;
		}
	}
	freeTree(&tree);	
	fclose(fPtr);
		return 0;
}
		


