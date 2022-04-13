#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
  char sdata[10];
  int data;
  struct Node* next;
  struct Node* intNext;
}Node;

Node* createList(){
  struct Node* headNode=(Node*)malloc(sizeof(Node));
  headNode->next=NULL;
  return headNode;
}

int main(int argc, char ** argv) {
  FILE* fp;
  fp=fopen(argv[1],"r");
  if(fp==NULL){
    printf("error");
    return 0;
  }
  Node* aList=createList();
  int numOfIn;
  int numOfOut;
  fscanf(fp,"INPUTVAR\t%d",&numOfIn);
  int tempIn=numOfIn;
  int inLen=2;
  while(tempIn>1){
    inLen=inLen*2;
    tempIn--;
  }
  int x;
  int lowCount=inLen;
  int indexLow=0;
  int indexTemp=0;
  int n=0;
  Node* og=aList;
  while(n<numOfIn){
      Node* nPew=(Node*)malloc(sizeof(Node));
      fscanf(fp,"%s",nPew->sdata);
      nPew->data=666;
      aList->next=nPew;
      nPew->next=NULL;
      nPew->intNext=NULL;
      aList=aList->next;
      Node* ogt=aList;
      indexLow=lowCount/2;
      for(x=0;x<inLen;x++){
        Node* nnPew=(Node*)malloc(sizeof(Node));
        if(indexTemp<indexLow&&indexTemp<lowCount)
        {
          nnPew->data=0;
          strcpy(nnPew->sdata,"Yes-0");
          aList->intNext=nnPew;
          nnPew->intNext=NULL;
          nnPew->next=NULL;
          aList=nnPew;
          indexTemp++;
        }else if(indexTemp>=indexLow&&indexTemp<lowCount){
          nnPew->data=1;
          strcpy(nnPew->sdata,"Yes-1");
          aList->intNext=nnPew;
          nnPew->intNext=NULL;
          nnPew->next=NULL;
          aList=nnPew;
          indexTemp++;
          if(indexTemp==lowCount){
            indexTemp=0;
          }
        }
      }
      lowCount=lowCount/2;
      aList=ogt;
      n++;
  }

  fscanf(fp,"\nOUTPUTVAR\t%d",&numOfOut);
  n=0;
  while(n<numOfOut){
    Node* nPew=(Node*)malloc(sizeof(Node));
    fscanf(fp,"%s",nPew->sdata);
    nPew->data=666;
    nPew->next=NULL;
    nPew->intNext=NULL;
    aList->next=nPew;
    aList=nPew;
    n++;
  }
  aList=og;
  char k[10];
  char temp[10];
  Node* cker=og;
  int eIndex=0;
  Node* aa;
  Node* bb;
  Node* cc;
  while(fscanf(fp,"%s",k)==1) {
    if(strcmp(k,"NOT")==0){
      fscanf(fp,"%s",k);
      while(cker->next!=NULL){
        cker=cker->next;
        if(strcmp(cker->sdata,k)==0){
          aa=cker;
          break;
        }
      }
      cker=og;
      fscanf(fp,"%s",k);
      while(cker->next!=NULL){
        cker=cker->next;
        if(strcmp(cker->sdata,k)==0){
          bb=cker;
          eIndex++;
          break;
        }
      }
      cker=og;
      if(eIndex==0){
        while(cker->next!=NULL){
          cker=cker->next;
        }
        Node* xPew=(Node*)malloc(sizeof(Node));
        strcpy(xPew->sdata,k);
        xPew->data=1234;
        xPew->next=NULL;
        xPew->intNext=NULL;
        cker->next=xPew;
        cker=xPew;
        bb=xPew;
      }
      cker=og;
      while(aa->intNext!=NULL){
        aa=aa->intNext;
        Node* yPew=(Node*)malloc(sizeof(Node));
        if(aa->data==1){
          yPew->data=0;
        }else{
          yPew->data=1;
        }
        strcpy(yPew->sdata,"No");
        yPew->intNext=NULL;
        yPew->next=NULL;
        bb->intNext=yPew;
        bb=yPew;
      }
      cker=og;
    }else if(strcmp(k,"AND")==0||strcmp(k,"OR")==0||strcmp(k,"NAND")==0||strcmp(k,"NOR")==0||strcmp(k,"XOR")==0){
      strcpy(temp,k);
      fscanf(fp,"%s",k);
      while (cker->next!=NULL) {
        cker=cker->next;
        if(strcmp(cker->sdata,k)==0){
          aa=cker;
          break;
        }
      }
      cker=og;
      fscanf(fp,"%s",k);
      while (cker->next!=NULL) {
        cker=cker->next;
        if(strcmp(cker->sdata,k)==0){
          bb=cker;
          break;
        }
      }
      cker=og;
      fscanf(fp,"%s",k);
      while(cker->next!=NULL){
        cker=cker->next;
        if(strcmp(cker->sdata,k)==0){
          cc=cker;
          eIndex++;
          break;
        }
      }
      cker=og;
      if(eIndex==0){
        while(cker->next!=NULL){
          cker=cker->next;
        }
        Node* xPew=(Node*)malloc(sizeof(Node));
        strcpy(xPew->sdata,k);
        xPew->data=1234;
        xPew->next=NULL;
        xPew->intNext=NULL;
        cker->next=xPew;
        cker=xPew;
        cc=xPew;
      }
      cker=og;
      if(strcmp(temp,"AND")==0){
        while(aa->intNext!=NULL){
          aa=aa->intNext;
          bb=bb->intNext;
          Node* yPew=(Node*)malloc(sizeof(Node));
          if(aa->data==0&&bb->data==0){
            yPew->data=0;
          }else if(aa->data==0&&bb->data==1){
            yPew->data=0;
          }else if(aa->data==1&&bb->data==0){
            yPew->data=0;
          }else if(aa->data==1&&bb->data==1){
            yPew->data=1;
          }
          strcpy(yPew->sdata,"No");
          yPew->intNext=NULL;
          yPew->next=NULL;
          cc->intNext=yPew;
          cc=yPew;
        }
        cker=og;
      }else if(strcmp(temp,"OR")==0){
        while(aa->intNext!=NULL){
          aa=aa->intNext;
          bb=bb->intNext;
          Node* yPew=(Node*)malloc(sizeof(Node));
          if(aa->data==0&&bb->data==0){
            yPew->data=0;
          }else if(aa->data==0&&bb->data==1){
            yPew->data=1;
          }else if(aa->data==1&&bb->data==0){
            yPew->data=1;
          }else if(aa->data==1&&bb->data==1){
            yPew->data=1;
          }
          strcpy(yPew->sdata,"No");
          yPew->intNext=NULL;
          yPew->next=NULL;
          cc->intNext=yPew;
          cc=yPew;
        }
        cker=og;
      }else if(strcmp(temp,"NAND")==0){
        while(aa->intNext!=NULL){
          aa=aa->intNext;
          bb=bb->intNext;
          Node* yPew=(Node*)malloc(sizeof(Node));
          if(aa->data==0&&bb->data==0){
            yPew->data=1;
          }else if(aa->data==0&&bb->data==1){
            yPew->data=1;
          }else if(aa->data==1&&bb->data==0){
            yPew->data=1;
          }else if(aa->data==1&&bb->data==1){
            yPew->data=0;
          }
          strcpy(yPew->sdata,"No");
          yPew->intNext=NULL;
          yPew->next=NULL;
          cc->intNext=yPew;
          cc=yPew;
        }
        cker=og;
      }else if(strcmp(temp,"NOR")==0){
        while(aa->intNext!=NULL){
          aa=aa->intNext;
          bb=bb->intNext;
          Node* yPew=(Node*)malloc(sizeof(Node));
          if(aa->data==0&&bb->data==0){
            yPew->data=1;
          }else if(aa->data==0&&bb->data==1){
            yPew->data=0;
          }else if(aa->data==1&&bb->data==0){
            yPew->data=0;
          }else if(aa->data==1&&bb->data==1){
            yPew->data=0;
          }
          strcpy(yPew->sdata,"No");
          yPew->intNext=NULL;
          yPew->next=NULL;
          cc->intNext=yPew;
          cc=yPew;
        }
        cker=og;
      }else if(strcmp(temp,"XOR")==0){
        while(aa->intNext!=NULL){
          aa=aa->intNext;
          bb=bb->intNext;
          Node* yPew=(Node*)malloc(sizeof(Node));
          if(aa->data==0&&bb->data==0){
            yPew->data=0;
          }else if(aa->data==0&&bb->data==1){
            yPew->data=1;
          }else if(aa->data==1&&bb->data==0){
            yPew->data=1;
          }else if(aa->data==1&&bb->data==1){
            yPew->data=0;
          }
          strcpy(yPew->sdata,"No");
          yPew->intNext=NULL;
          yPew->next=NULL;
          cc->intNext=yPew;
          cc=yPew;
        }
        cker=og;
      }
    }
  }
  int e;
  int w;
  int upp=numOfIn+numOfOut;
  aList=aList->next;
  Node* oga=aList;
  for(e=0;e<inLen;e++){
    for(w=0;w<upp;w++){
      printf("%d ",aList->intNext->data);
      aList->intNext=aList->intNext->intNext;
      aList=aList->next;
    }
    printf("\n");
    aList=oga;
  }
  free(aList);
  return 0;
}
