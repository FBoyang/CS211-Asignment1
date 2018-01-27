#include<stdio.h>
#include<stdlib.h>
int** Matrix(int r, int c);

int** addMatrix(int** mat1,int** mat2,int r,int c);
int main(int argc, char** argv){
	FILE *fPtr;
	fPtr = fopen(argv[1],"r");
	if(fPtr==NULL){
		printf("error\n");
		return 0;
	}
	
	int r;
	int c;
	int check;
	check=fscanf(fPtr,"%d\t%d\n",&r,&c);
	if(check!=2){
		printf("error\n");
	}
	int** mat1;
	int** mat2;
	mat1 =Matrix(r,c);
	mat2 =Matrix(r,c);
	int countr;
	int countc;
	for(countr=0;countr<r;countr++){
		for(countc=0;countc<c-1;countc++){
			fscanf(fPtr,"%d\t",&mat1[countr][countc]);
		}
		fscanf(fPtr,"%d\n",&mat1[countr][countc]);
		}
	fscanf(fPtr,"\n");
	
	for(countr=0;countr<r;countr++){
		for(countc=0;countc<c-1;countc++){
			fscanf(fPtr,"%d\t",&mat2[countr][countc]);
		}
		fscanf(fPtr,"%d\n",&mat2[countr][countc]);
	}


	int** Nmat;
	Nmat = addMatrix(mat1,mat2,r,c);
	int r1;
	int c1;
	for(r1=0;r1<r;r1++){
		for(c1=0;c1<c-1;c1++){
			printf("%d\t",Nmat[r1][c1]);
		}
		printf("%d\n",Nmat[r1][c1]);
	}
	
	fclose(fPtr);
	return 0;
	}









int** Matrix(int m, int n){
	int **mat = (int**)malloc(sizeof(int*)*m);
	int i;
	for(i=0;i<m;i++){
		mat[i] = (int*)malloc(sizeof(int)*n);
			}
	int i1;
	int j1;
	for(i1=0;i1<m;i1++){
		for(j1=0;j1<n;j1++){
			mat[i1][j1]=0;
			}
	}
	return mat;
}

int** addMatrix(int** mat1, int** mat2, int r, int c){
	int i;
	int j;
	int** newMat;
	newMat = Matrix(r,c);
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			newMat[i][j] = mat1[i][j]+mat2[i][j];
		}
	}
	return newMat;
}	
