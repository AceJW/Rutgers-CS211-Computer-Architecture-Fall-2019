#include<stdio.h>
#include<stdlib.h>

void ffreeMat(int** mat,int r);
int** getMat(FILE* fp,int i,int j);
void printMat(int** mat,int i, int j);
int** multiply(int** mat1,int i,int j,int** mat2,int a, int b);

int main(int argc, char ** argv) {
  FILE* fp;
  fp=fopen(argv[1], "r");
  if(fp==NULL) {
    printf("error");
    return 0;
  }
  int i,j;
  fscanf(fp,"%d\t%d\t\n",&i,&j);
  int ** mat1;
  mat1=getMat(fp,i,j);

  int a,b;
  fscanf(fp,"%d\t%d\t\n", &a, &b);
  int ** mat2;
  mat2=getMat(fp,a,b);
  fclose(fp);

  int** matP;
  if(j!=a){
    printf("bad-matrices");
    return 0;
  }else{
    matP=multiply(mat1,i,j,mat2,a,b);
  }

  int x;
  int y;
  for(x=0;x<i;x++){
    for(y=0;y<b;y++){
      printf("%d\t",matP[x][y]);
    }
    printf("\n");
  }

  ffreeMat(mat1,i);
  ffreeMat(matP,i);
  ffreeMat(mat2,a);
  return 0;
}
void ffreeMat(int** mat,int r){
  int n;
  for(n=0;n<r;n++){
    free(mat[n]);
  }
  free(mat);
}
int** getMat(FILE* fp,int row,int col){
  int ** mat;
  int i;
  int j;
  mat = (int **) malloc(row*sizeof(int *));
  for (i = 0; i < row; i++) {
      mat[i] = (int *) malloc(col*sizeof(int));
      for (j = 0; j < col; j++) {
          fscanf(fp, "%d", &mat[i][j]);
      }
  }
  return mat;
}
int** multiply(int** mat1,int i,int j,int** mat2,int a, int b){
  int r,c,x;
  int** reMP;
  int tpSum;
  reMP=(int**)malloc(i*sizeof(int*));
  for(r=0;r<i;r++){
    reMP[r]=(int*)malloc(b*sizeof(int));
    for(c=0;c<b;c++){
      tpSum=0;
      for(x=0;x<j;x++){
        tpSum=tpSum+mat1[r][x]*mat2[x][c];
      }
      reMP[r][c]=tpSum;
    }
  }
  return reMP;
}
