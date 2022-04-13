#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv) {
  FILE* fp;
  fp=fopen(argv[1],"r");
  if(fp==NULL){
    printf("error");
    return 0;
  }
  unsigned short x;
  fscanf(fp,"%hd\n",&x);
  char* act=(char*)malloc(sizeof("comp"));
  int n;
  int v;
  int z=1;
  int temp;
  while(!feof(fp)){
    z=1;
    fscanf(fp,"%s\t%d\t%d\n",act,&n,&v);
    if(strcmp(act,"set")==0){
      if(n>0){
        z=z<<n;
      }
      if(v==0){
        x=x|z;
        x=x^z;
        printf("%d\n",x);
      }else{
        x=x|z;
        printf("%d\n",x);
      }
    }else if(strcmp(act,"comp")==0){
      if(n>0){
        z=z<<n;
      }
      x=x^z;
      printf("%d\n",x);
    }else if(strcmp(act,"get")==0){
      if(n>0){
        z=z<<n;
      }
      temp=z&x;
      if(temp==0){
        printf("0\n");
      }else{
        printf("1\n");
      }
    }
  }
  fclose(fp);
  free(act);
  return 0;
  }
