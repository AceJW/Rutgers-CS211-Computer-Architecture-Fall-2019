#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[]) {
  int getLength(FILE* tempFp);
  void creatArrWithNum(int arr[],FILE* tempFp, int tempLen);
  void sort(int arr[],int len);
  FILE* fp;
  fp=fopen(argv[1],"r");

  int arrLength=getLength(fp);
  int arr[arrLength];
  creatArrWithNum(arr,fp,arrLength);
  sort(arr,arrLength);
  int n;
  for(n=0;n<arrLength;n++){
    printf("%d\t",arr[n]);
  }
  fclose(fp);
}
void sort(int arr[],int len){
  int n;
  for(n=0;n<len;n++){
    arr[n]=arr[n]+1000;
    if(arr[n]%2==1){
      arr[n]=arr[n]*-1;
    }
  }
  int cMax;
  int temp;
  int x;
  int y;
  for(x=0;x<len-1;x++){
    cMax=x;
    for(y=x+1;y<len;y++){
      if(arr[cMax]>arr[y]){
        cMax=y;
      }
    }
    if(cMax!=x){
      temp=arr[x];
      arr[x]=arr[cMax];
      arr[cMax]=temp;
    }
  }
  int tempp[len];
  int indexc=0;
  int z;
  for(z=0;z<len;z++){
    if(arr[z]%2==0){
      tempp[indexc]=arr[z];
      indexc++;
    }
  }
  int r;
  for(r=0;r<len;r++){
    if(arr[r]%2!=0){
      tempp[indexc]=arr[r];
      indexc++;
    }
  }
  for(n=0;n<len;n++){
    if(tempp[n]%2==-1){
      tempp[n]=tempp[n]*-1;
    }
    tempp[n]-=1000;
  }
  int u;
  for(u=0;u<len;u++){
    arr[u]=tempp[u];
  }
}
int getLength(FILE* tempFp){
  int units;
  fscanf(tempFp,"%d",&units);
  return units;
}
void creatArrWithNum(int arr[],FILE* tempFp, int tempLen){
    int n;
    for(n=0;n<tempLen;n++){
        fscanf(tempFp,"%d",&arr[n]);
    }
}
