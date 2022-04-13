#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
  int x=atoi(argv[1]);
  int z=1;
  int temp;
  int index=0;
  int indexPar=0;
  int twoCoun=0;
  while(z<=x){
    temp=z;
    temp=temp&x;
    if(temp>0){
      twoCoun++;
      index++;
      if(twoCoun==2){
        indexPar++;
        twoCoun=0;
      }
    }else{
      if(twoCoun<=1){
        twoCoun=0;
      }
    }
    z=z<<1;
  }
  if(index%2==0){
    printf("Even-Parity\t%d\n",indexPar);
  }else{
    printf("Odd-Parity\t%d\n",indexPar);
  }
  return 0;
}
