#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int data;
  struct Node* left;
  struct Node* right;
}Node;

typedef struct{
  Node* root;
}Tree;

void insert(Tree* tree, int value){
  Node* node=(Node*)malloc(sizeof(Node));
  node->data=value;
  node->left=NULL;
  node->right=NULL;
  if(tree->root==NULL){
    tree->root=node;
  }else{
    Node* temp=tree->root;
    while(temp!=NULL){
      if(value<temp->data){
        if(temp->left==NULL){
          temp->left=node;
          return;
        }else{
          temp=temp->left;
        }
      }else if(value>temp->data){
        if(temp->right==NULL){
          temp->right=node;
          return;
        }else{
          temp=temp->right;
        }
      }else if(value==temp->data){
        return;
      }
    }
  }
}
void inorder(Node* node){
  if(node!=NULL){
    inorder(node->left);
    printf("%d\t",node->data);
    inorder(node->right);
  }
}
int main(int argc, char ** argv) {
  FILE* fp;
  fp=fopen(argv[1],"r");
  if(fp==NULL){
    printf("error");
    return 0;
  }
  Tree* tree=(Tree*)malloc(sizeof(Node));
  tree->root=NULL;

  int value;
  while(!feof(fp)){
    fscanf(fp,"i\t%d\n", &value);
    insert(tree,value);
  }
  fclose(fp);
  inorder(tree->root);
  return 0;
  free(tree->root);
  free(tree);

}
