#include <stdio.h> 
#include<stdlib.h>

struct node
{
struct node* left; 
int data;
struct node* right;
int height;
};
typedef struct node Tree;

void Inorder_traversal(Tree *root);
void preorder_traversal(Tree *root);
void postorder_traversal(Tree *root);
void levelorder_traversal(Tree *root);
void nodes_level(Tree* root,int level);
int height(Tree *root);
int total_nodes(Tree *root);
int leaf_nodes(Tree *root);
int half_nodes(Tree *root);
int non_leaf_nodes(Tree *root);
void creation(Tree *root, int a[] , int n );
Tree* insert(Tree *root, int val);
Tree* create(int val);
int search(Tree *root, int val);
void printLevel(Tree* root, int val);
int getLevel(Tree* root,int data, int level);
Tree* delete(Tree *root, int val);
Tree* largest_element(Tree *root);
Tree* smallest_element(Tree *root);
Tree* rightRotate(Tree* root);
Tree* leftRotate(Tree* root);
int calculate_bal(Tree *root);

int main()
{
Tree* root = 0;
int n, choice, data;

/*printf("Enter the number of nodes : \n");
scanf("%d",&n);
int a[n];
printf("Enter the elements: \n"); 
for(int i=0;i<n;i++)
{ 
    scanf("%d",&a[i]);
}
creation(*root,a,n);*/
while(1)
 {
 printf("Which operation do you want to perform on the AVL tree?\n");
 printf("Enter 1 for Insert operation.\n");
 printf("Enter 2 for Delete operation.\n");
 printf("Enter 3 for Height.\n");
 printf("Enter 4 for Traversal (Display) operation.\n");
 printf("Enter 5 for Search operation.\n");
 printf("Enter 6 for Counting of nodes.\n");
 printf("Enter 7 for EXIT.\n");
 scanf("%d", &choice);
 switch (choice)
 {
   case 1:
   printf("Insert operation\n");
   printf("Enter the data you want to insert\n");
   scanf("%d",&data);
   root = insert(root, data);
   break;
  
   case 2:
   printf("Delete operation\n");  
   printf("Enter the data you want to delete\n");
   scanf("%d",&data);
   root = delete(root, data);
   break;

   case 3:
   printf("Height of the tree\n");
   int ht  = height(root);
   printf("The height of the tree is %d.\n", ht);
   break;

   case 4:
   printf("Traversal (Display) operation.\n");
   int choice2, check = 1;
   while(check == 1)
   {
   printf("How do you want to traverse?\n");
   printf("Enter 1 to Inorder traversal.\n");
   printf("Enter 2 to Preorder traversal .\n");
   printf("Enter 3 to Postorder traversal.\n");
   printf("Enter 4 to Level order traversal.\n");
   printf("Enter 5 to Exit.\n");
   scanf("%d",&choice2);
   switch (choice2)
   {
   case 1:
   printf("Inorder traversal:\n "); 
   Inorder_traversal(root); 
   break;
  
   case 2:
   printf("Preorder traversal:\n ");
   preorder_traversal(root);
   break;

   case 3:
   printf("Postorder traversal:\n "); 
   postorder_traversal(root);
   break;

   case 4:
   printf("Level order traversal:\n ");
   levelorder_traversal(root);
   break;

   case 5:
   printf("EXIT\n");
   check = 0;
   break;

   default:
   printf("Invalid Input\n");
   break;

}

}
check = 1;
break;
   
case 5:
printf("Search operation\n");
int val;
if(root == NULL)
{
  printf("Tree is empty.\n");
}
else
{printf("Which node do you want to search?\n");
scanf("%d",&val);
int result = search(root,val);
if(result == 1)
{
  printf("Element found.\n");
  printLevel(root,val);
}
if(result == 0)
{
  printf("Element not found.\n");
}
}
break;

case 6:
printf("Counting of nodes\n");
int choice3 ,check1 = 1;
   while(check1 == 1)
  {
   printf("Which nodes do you want to count?\n");
   printf("Enter 1 to Leaf nodes.\n");
   printf("Enter 2 to Non Leaf nodes.\n");
   printf("Enter 3 to All nodes.\n");
   printf("Enter 4 to Exit.\n");
   scanf("%d",&choice3);
   switch (choice3)
  {
   case 1:
   printf("Total number of leaf_nodes : %d\n",leaf_nodes(root));
   break;

   case 2:
   printf("Total number of non leaf nodes : %d\n",non_leaf_nodes(root));
   break;

   case 3:
   printf("All nodes\n");
   printf("Total number of nodes : %d\n",total_nodes(root));
   break;

   case 4:
   printf("EXIT\n");
   check1 = 0;
   break;
  
   default:
   printf("Invalid Input\n");
   break;
}
} 
check1 = 1;
break;

case 7:
printf("EXIT\n");
exit(0);
break;
  
default:
printf("Invalid Input\n");
break;


}
}
}

void Inorder_traversal(Tree *root)
{ 
//Tree* node = *root; 
if(root == NULL)
{
printf("Tree is empty.\n");
return;
}
else 
{
if(root->left!= NULL)
Inorder_traversal(root -> left); 
printf("%d ",root -> data); 
if(root->right!= NULL)
Inorder_traversal(root -> right);
}
}

void preorder_traversal(Tree *root)
{

if(root == NULL)
{ 
printf("Tree is empty.\n");
return;
}
else 
{printf("%d ",root->data); 
if(root->left!= NULL)
preorder_traversal(root->left); 
if(root->right!= NULL)
preorder_traversal(root->right);
}
}

void postorder_traversal(Tree *root)
{

if(root == NULL)
{
printf("Tree is empty.\n");
return;
}
else 
{
if(root->left!= NULL)
  postorder_traversal(root->left); 
if(root-> right!= NULL)
postorder_traversal(root->right); 
printf("%d ",root->data);
}
}

void levelorder_traversal(Tree *root)
{
  int level = 0;
  int h = height(root);
  if(root == NULL)
{
printf("Tree is empty.\n");
return;
}
  else
  {while(level<=h)
  {
    nodes_level(root,level);
    level=level+1;
  }
  }
}

void nodes_level(Tree* root,int level)
{
  if(root != NULL)
  {
    if(level==0)
  {
    printf("%d\t",root->data);
  }
  else
  {
    nodes_level(root->left,level-1);
    nodes_level(root->right,level-1);
  }
  }
}

int total_nodes(Tree *root)
{

if(root == NULL)
{
return 0; 
}
return 1+total_nodes(root->left)+total_nodes(root->right); 
}

int leaf_nodes(Tree *root)
{
if(root == NULL)
{
return 0; 
}
if(root->left==NULL && root->right==NULL)
{
return 1; 
}
else
{
  return leaf_nodes(root->left)+leaf_nodes(root->right);
}
}

int non_leaf_nodes(Tree *root)
{
if(root == NULL)
{
return 0; 
}
if(root->left==NULL && root->right==NULL)
{
return 0; 
}
else
return non_leaf_nodes(root->left)+non_leaf_nodes(root->right)+1;
}


void creation(Tree *root, int a[] , int n )
{ 
    for(int i=0;i<n;i++)
{
Tree* new_node=(Tree *)malloc(sizeof(Tree));
new_node->data=a[i];
if(root==NULL)
{
root=new_node; 
}
else
{
Tree* prev=NULL;
Tree* temp=root;
while(temp!=NULL)
{
prev=temp; 
if(temp->data < new_node->data)
{
temp=temp->right;
}
else
{
     temp=temp->left;
} 
}
if(prev->data < new_node->data)
{
     prev->right=new_node;
}
else
{

prev->left=new_node;
}
} 
}
}

Tree* create(int val)
{
  
    Tree* temp;
    
    temp = (Tree *)malloc(sizeof(Tree));
    if(temp == NULL)
    {
        printf("Node not created.\n");
        return NULL;
    }
    else
    {
        printf("Node created \n");
        return temp;
    }
}

Tree* insert( Tree* root, int val)
{
  if(root == NULL)
  {
    root = create(val);
    root -> data = val;
    root -> left = root -> right = NULL;
    root -> height = 0;
    return root;
    }
  else if(val <  root -> data)
  {
       root -> left =insert(root -> left, val);
  }
  else if(val > root -> data)
  {
   root -> right =insert(root -> right, val);
  }
  int b_f = height(root ->left)- height(root ->right);
  if(b_f > 1 && (val < root -> left -> data))
  {
      printf("LL rotation.\n");
      return rightRotate(root);
  }
  if(b_f < -1 && (val > root -> right -> data))
  {
      printf("RR rotation.\n");
      return leftRotate(root);
  }
  if(b_f > 1 && (val > root -> left -> data))
  {
      printf("LR rotation.\n");
      root -> left = leftRotate(root -> left);
      levelorder_traversal(root);
      return rightRotate(root);
  }
  if(b_f < -1 && (val < root -> right -> data))
  {
      printf("RL rotation.\n");
      root -> right= rightRotate(root ->right);
      levelorder_traversal(root);
      return leftRotate(root);
  }
  
  return root;
}
Tree* rightRotate(Tree* root)
{
    Tree *x = root -> left;
    Tree *Z = x -> right;
    x -> right = root;
    root -> left = Z;
    root ->height = height(root);
    x -> height = height(x);
    return x;
}
Tree* leftRotate(Tree* root)
{
    Tree *x = root -> right;
    Tree *Z = x -> left;
    x -> left = root;
    root -> right = Z;
    root ->height = height(root);
    x -> height = height(x);
    return x;
}

int height(Tree *root)
{
  if(root == NULL)
  {
    return -1;
  }
  if(root->left == NULL && root->right == NULL)
  {
    return 0;
  }
  else
  {
    int leftht = height(root->left);
    int rightht = height(root->right);
    if(leftht > rightht)
    {
      return leftht+1;
    }
    else
      return rightht+1;
  }
}

int search(Tree *root, int val)
{
  if(root == NULL)
  {
    return 0;
  }
  if(root->data == val)
  {
    return 1;
  }
  int l = search(root->left,val);
  int r =  search(root->right,val);
  return l||r;

}
int getLevel(Tree* root,int data, int level)
{
    if (root->data == data)
    return level;
 
    int downlevel = getLevel(root->left,data, level+1);
    if (downlevel != 0)
    return downlevel;
 
    downlevel = getLevel(root->right,data, level+1);
    return downlevel;
}
 
void  printLevel(Tree* root, int val)
{
   printf("Level is %d\n",getLevel(root,val,0));
}


Tree* delete(Tree *root, int val)
{
  if(root == NULL)
  {
    printf("Value to be deleted not found.\n");
  }
  else if(val < root->data)
  {
    root->left=delete(root->left,val);
  }
  else if(val > root->data)
  {
    root->right=delete(root->right,val);
  }
  else
  {
    if(root->left && root->right)
    {
      Tree *temp = smallest_element(root->right);//using successor
      root->data = temp->data;
      root->right = delete(root->right,temp->data);
    }
    else
    {
      Tree *temp = root;
      if(root->left == NULL && root->right == NULL)
      {
        root = NULL;
      }
      else if(root->left == NULL)
           root= root->right;
      else if(root->right == NULL)
           root= root->left;
      free(temp);
    }
  }
  int b_f = calculate_bal(root);
  if(b_f > 1 && calculate_bal(root ->left) >= 0)
  {
      printf("LL Case.\n");
      return rightRotate(root);
  }
  if(b_f > 1 && calculate_bal(root ->left) < 0)
  {
      printf("LR Case.\n");
      root ->left = leftRotate(root -> left);
      levelorder_traversal(root);
      return rightRotate(root);
  }
  if(b_f < -1 && calculate_bal(root ->right) <= 0)
  {
      printf("RR Case.\n");
      return leftRotate(root);
  }
  if(b_f < -1 && calculate_bal(root ->right) > 0)
  {
      printf("RL Case.\n");
      root ->right = rightRotate(root -> right);
      levelorder_traversal(root);
      return leftRotate(root);
  }
  return root;
}
int calculate_bal(Tree *root)
{
  int b;
  if(root == NULL)
  {
      return 0;
  }
  else
  b = height(root ->left)- height(root ->right);
  return b;
}
Tree* largest_element(Tree *root)
{
  if(root == NULL || root->right == NULL)
  {
    return root;
  }
  else
  {
    return largest_element(root->right);
  }
}

Tree* smallest_element(Tree *root)
{
  if(root == NULL || root->left == NULL)
  {
    return root;
  }
  else
  {
    return smallest_element(root->left);
  }
}