#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
  int data;
  struct Node* next;
}Node;

Node* createList(){
  struct Node* headNode=(Node*)malloc(sizeof(Node));
  headNode->next=NULL;
  return headNode;
}

void printAllNode(Node* P){
  Node* og=P;
  P=P->next;
  while(P!=NULL){
    printf("%d\t",P->data);
    P=P->next;
  }
  P=og;
}

int count(Node* P){
  int total=0;
  P=P->next;
  while(P!=NULL){
    total++;
    P=P->next;
  }
  return total;
}

void dubdel(Node* P){
  Node* cur = P;
  Node* find = NULL;
  Node *tmp;
  while(cur != NULL){
    find = cur;
    while (find->next != NULL) {
      if (find->next->data != cur->data)
        find = find->next;
      else {
        tmp = find->next;
        find->next = find->next->next;
        free(tmp);
      }
    }
    cur = cur->next;
  }
}
Node* addNewNode(Node* P,int num);
Node* deleteNode(Node* P,int num);
int main (int argc, char** argv) {
  char act;
  int num;
  Node* aList=createList();
  Node* pog=aList;
  FILE* fp;

  fp=fopen(argv[1],"r");
  if(fp==NULL){
    printf("error");
    return 0;
  }
  while(fscanf(fp,"%c",&act) == 1 && fscanf(fp,"%d\n",&num)==1){
    aList=pog;
    if(act=='i'){
      aList=addNewNode(aList,num);
    }else if(act=='d'){
      aList=deleteNode(aList,num);
    }
  }
  aList=pog;
  int nodeCheck=count(aList);
  if(nodeCheck==0){
      printf("0");
    return 0;
  }else{
    printf("%d\n",nodeCheck);
  }
  dubdel(aList);
  printAllNode(aList);
  return 0;
}
Node* deleteNode(Node* P,int num){
  Node* tP=P;
  Node* ogc=P;
  P=P->next;
  if(P!=NULL){
    while(P!=NULL){
      if(P->data==num){
        tP->next=P->next;
        free(P);
        return ogc;
      }else{
        P=P->next;
        tP=tP->next;
      }
    }
  }
  return P;
}
Node* addNewNode(Node* P,int num){
  Node* pNew=NULL;
  Node* pogc=P;
  pNew=(Node*)malloc(sizeof(Node));
  pNew->data=num;
  if(P->next==NULL){
    pNew->next=NULL;
    P->next=pNew;
  }else{
    P=P->next;
    while(P!=NULL){
      if(pNew->data<P->data){
        pogc->next=pNew;
        pNew->next=P;
        break;
      }else if(pNew->data<=P->data){
        pNew->next=P->next;
        P->next=pNew;
        break;
      }else if(pNew->data>P->data){
        if(P->next==NULL){
          pNew->next=P->next;
          P->next=pNew;
          break;
        }else{
          if(pNew->data<=P->next->data){
            pNew->next=P->next;
            P->next=pNew;
            break;
          }else if(pNew->data>P->next->data){
            P=P->next;
            pogc=pogc->next;
          }
        }
      }
    }
  }
  return P;
}
