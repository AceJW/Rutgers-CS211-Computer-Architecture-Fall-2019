#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define BK_SIZE 10000
typedef struct Node{
  int data;
  struct Node* next;
}Node;

typedef struct hashTable{
  int size;
  struct Node** row;
}hashTable;

Node* nf[BK_SIZE + 1];
int numOfCol,numOfIc,numOfSc = 0;
void search(int k, Node* bucks[]);
int check(hashTable* table,int num);
void insert(int k, Node* bucks[]);
void clefBks(int tONIC, Node* tNode[]);
int valueblack(hashTable* table, int num);

int main(int argc, char** argv) {
    FILE *fp;
    int i=0;
    int k;
    char hashCharMe;
    Node* bucks[BK_SIZE + 1];
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("error");
    }
    while(i < BK_SIZE){
      bucks[i] = NULL;
      i++;
    }
     while (fscanf(fp,"%c",&hashCharMe) == 1 && fscanf(fp,"%d\n",&k)==1) {
          if (hashCharMe == 's') {
            search(k, bucks);
          }else if (hashCharMe == 'i') {
             insert(k, bucks);
             ++numOfIc;
          }
        }
        fclose(fp);
        printf("%d\n%d", numOfCol,numOfSc);
        clefBks(numOfIc,nf);
    return 0;
}

void search(int k, Node* bucks[]) {
    int value = k % BK_SIZE;
    if (value < 0) {
        value += 10000;
    }
    if (value > BK_SIZE) {
        return;
    }
    if (bucks[value]) {
        Node* tempH;
        tempH = bucks[value];
        while (tempH != NULL) {
            if (tempH->data == k) {
                ++numOfSc;
            }
            tempH = tempH->next;
        }
    }

}
int check(hashTable* table,int num){
  int k;
  k=valueblack(table,num);
  if(table->row[k]->data==num){
    return 1;
  }
  if(table->row[k]==NULL){
    return 0;
  }
  Node* temp=table->row[k];
  while(temp->next!=NULL){
    if(temp->next->data==num){
      return 1;
    }
    temp=temp->next;
  }
return 0;
}
int valueblack(hashTable* table, int num){
  int rV;
  if(num<0){
    rV=(num*-1)%table->size;
  }else{
    rV=num%table->size;
  }
  return rV;
}

void insert(int k, Node* bucks[]){
    int value = k % BK_SIZE;
    if (value < 0) {
        value += 10000;
    }
    if (value > BK_SIZE) {
      return;
    }
    Node* hNode = (Node *) malloc(sizeof(Node));
    hNode->data = k;
    if (bucks[value] == NULL) {
      hNode->next = NULL;
      bucks[value] = hNode;
      nf[numOfSc] = hNode;
    } else if(bucks[value] != NULL){
      ++numOfCol;
      Node* head = bucks[value];
      while (head) {
          if (head->data == k) {
              free(hNode);
              return;
          }
          if (!(head->next)) {
              head->next = hNode;
              nf[numOfSc] = hNode;
              return;
          }
          head = head->next;
      }
    }
}
void clefBks(int tONIC, Node* tNode[]){
  int s=0;
  while(s<tONIC){
    if(tNode[s]!=NULL){
      free(tNode[s]);
    }
    s++;
  }
}
