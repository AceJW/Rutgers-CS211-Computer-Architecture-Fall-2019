#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
  int x=atoi(argv[1]);
  int s=1;
  int z=1;
  int tempS;
  int tempZ;
  s=s<<8;
  z=z<<7;
  while(z>=1){
    tempZ=z&x;
    tempS=s&x;
    if((tempZ==0&&tempS!=0)||(tempZ!=0&&tempS==0)){
      printf("Not-Palindrome\n");
      return 0;
    }
    s=s<<1;
    z=z>>1;
  }
  printf("Is-Palindrome\n");
  return 0;
}
