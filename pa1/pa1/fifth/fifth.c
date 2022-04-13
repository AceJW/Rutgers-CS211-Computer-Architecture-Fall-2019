#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv){
  int n;
  int index=0;
  for(n=1;n<argc;n++){
    index=0;
    while(argv[n][index]!='\0'){
        if(argv[n][index]=='a'||argv[n][index]=='e'||argv[n][index]=='i'||argv[n][index]=='o'||argv[n][index]=='u'||argv[n][index]=='A'||argv[n][index]=='E'||argv[n][index]=='O'||argv[n][index]=='I'||argv[n][index]=='U'){
          printf("%c",argv[n][index]);
        }
        index++;
    }
  }
  return 0;
}
