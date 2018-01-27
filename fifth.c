#include<stdio.h>
#include<stdlib.h>
int** Matrix(int r, int c){
	int **Mat;
	Mat = (int**)malloc(sizeof(int*)*r);
	int i;
	for(i=0;i<r;i++){
		Mat[i]=(int*)malloc(sizeof(int)*c);
	}

	int r1;
	int c1;
	for(r1=0;r1<r;r1++){
		for(c1=0;c1<c;c1++){
			Mat[r1][c1] = 0;
			}
	}
	return Mat;
}

int** MultMatrix(int m1,int n1,int m2,int n2,int** mat1, int** mat2){
		if(n1!=m2){
			printf("error\n");
			exit(0);
		}
		
		int **Nmatrix;
		Nmatrix = Matrix(m1,n2);
		int M;
		int N;
	 	int t;
		for(M=0;M<m1;M++){
			for(N=0;N<n2;N++){
				for(t=0;t<n1;t++){
					Nmatrix[M][N]+=mat1[M][t]*mat2[t][N];
				}
			}
		}

	return Nmatrix;
}


void printMatrix(int** Mat, int r, int c){
	int R;
	int C;
	for(R=0;R<r;R++){
		for(C=0;C<c-1;C++){
			printf("%d\t",Mat[R][C]);
			}
		printf("%d\n",Mat[R][C]);
	}

}



int main(int argc, char** argv){
	FILE *fPtr;
	fPtr=fopen(argv[1],"r");
	if(fPtr==NULL){
		printf("error\n");
		return 0;
	}
	
	int m1;
	int n1;
	fscanf(fPtr,"%d\t%d\n",&m1,&n1);
	int** Mat1;
	Mat1 = Matrix(m1,n1);
	int tm1;
	int tn1;
	for(tm1=0;tm1<m1;tm1++){
		for(tn1=0;tn1<n1-1;tn1++){
			fscanf(fPtr,"%d\t",&Mat1[tm1][tn1]);
			}
			fscanf(fPtr,"%d\n",&Mat1[tm1][tn1]);
		}
	fscanf(fPtr,"\n");
	int m2;
	int n2;
	fscanf(fPtr,"%d\t%d\n",&m2,&n2);
	int** Mat2;
	Mat2 = Matrix(m2,n2);
	int tm2;
	int tn2;
	for(tm2=0;tm2<m2;tm2++){
		for(tn2=0;tn2<n2-1;tn2++){
			fscanf(fPtr,"%d\t",&Mat2[tm2][tn2]);
			}
			fscanf(fPtr,"%d\n",&Mat2[tm2][tn2]);
		}

	int** Nmat;
	Nmat = MultMatrix(m1,n1,m2,n2,Mat1,Mat2);
	printMatrix(Nmat,m1,n2);
	

	fclose(fPtr);
	return 0;
}
