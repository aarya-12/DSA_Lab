#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
 
void choose_input_queues(int* ,int ,int);
void choose_input_stack(int* ,int );
void push(int* ,int* ,int , int );
void pop(int* ,int* ,int , int );
int top_val(int *, int *);
int isEmpty(int*);
int isFull(int* ,int);
void display(int* ,int*);
void insert(int*, int, int*, int*);
void delete(int*, int, int*, int*);
void Front_val(int*, int*, int*);
void Rear_val(int*, int*, int*);
void IsEmptyQ(int*, int*);
void IsFullQ(int*, int);
void displayQ(int*, int*, int*);
void insertCQ(int*, int, int*, int*);
void deleteCQ(int*, int, int*, int*);
void Rear_valCQ(int*, int*, int*, int);
void IsFullCQ(int*, int*, int);
void displayCQ(int*, int*, int*, int);

int main()
{ 
 int choice,n;
 int* s;
 
 while(1)
 {
 printf("Which linear data structure do you want to execute?\n");
 printf("Enter 1 for Stack.\n");
 printf("Enter 2 for Queue.\n");
 printf("Enter 3 for Circular Queue.\n");
 printf("Enter 4 for EXIT.\n");
 scanf("%d", &choice);
 switch (choice)
 {
 
   case 1:
   printf("Stack \n");
   printf("Enter the number of elements of the stack: ");
   scanf("%d", &n);
   s=(int *)calloc(n, sizeof(int));
   /*printf("Enter %d number of elements: \n", n);
   for(int i=0;i<n;i++)
   {
     s[i+1]=s[i];
     scanf("%d", &s[i]);
   }
   */
   choose_input_stack(s,n);
   break;
  
   case 2:
   printf("Queue \n");
   printf("Enter the size of the Queue:\n");
   scanf("%d", &n);
   int *queue;
   queue = (int *)calloc(n, sizeof(int));
   choose_input_queues(queue,n,choice);
   break;
  
   case 3:
   printf("Circular Queue \n");
   printf("Enter the size of the Circular Queue:\n");
   scanf("%d", &n);
   int *circular;
   circular = (int *)calloc(n, sizeof(int));
   choose_input_queues(circular,n,choice);
   break;
 
   case 4:
   printf("EXIT");
   exit(0);
   break;
  
   default:
   printf("Invalid Input");
   break;
}
}
}
void choose_input_queues(int q[],int n,int choice)
{
   int input,check =1;
   int front = -1;
   int rear = -1;
   while(check==1)
   {
   printf("Enter 1 for Insert operation.\n");
   printf("Enter 2 for Delete operation.\n");
   printf("Enter 3 for Front_val operation.\n");
   printf("Enter 4 for Rear_val operation.\n");
   printf("Enter 5 for IsEmpty operation.\n");
   printf("Enter 6 for IsFull operation.\n");
   printf("Enter 7 for Display operation.\n");
   printf("Enter 8 for EXIT.\n");
   scanf("%d",&input);
 
   switch(input)
   {
   case 1:
   printf("Insert operation \n");
   if (choice == 2)
   {
       
       insert(q, n, &front, &rear);
   }
   else if (choice == 3)
   {
    
    insertCQ(q, n, &front, &rear);
   }
   break;
  
   case 2:
   printf("Delete operation\n");
   if (choice == 2)
   {
    
       
       delete(q, n, &front, &rear);
   }
   else if (choice == 3)
   {
    
    deleteCQ(q, n, &front, &rear);
   }
   break;
  
   case 3:
   printf("Front_val operation\n");
   if (choice == 2)
   {
     
     Front_val(q, &front, &rear);
   }
   else if (choice == 3)
   {
     
     Front_val(q, &front, &rear);
   }
   break;
  
   case 4:
   printf("Rear_val operation\n");
   if (choice == 2)
   {
     
     Rear_val(q, &front, &rear);
   }
   else if (choice == 3)
   {
     
     Rear_valCQ(q, &front, &rear, n);
   }
   break;
   
   case 5:
   printf("IsEmpty operation\n");
   if (choice == 2)
   {
     
     IsEmptyQ(&front, &rear);
   }
   else if (choice == 3)
   {
     
     IsEmptyQ(&front, &rear);
   }
   break;
   
   case 6:
   printf("IsFull operation\n");
   if (choice == 2)
   {
     
     IsFullQ(&rear, n);
   }
   else if (choice == 3)
   {
     
     IsFullCQ(&front, &rear, n);
   }
   break;
   
   case 7:
   printf("Display operation\n");
   if (choice == 2)
   {
     
     displayQ(q, &front, &rear);
   }
   else if (choice == 3)
   {
     
     displayCQ(q, &front, &rear, n);
   }
   break;
 
   case 8:
   printf("EXIT\n");
   check = 0;
   break;
  
   default:
   printf("Invalid Input");
   break;
   }
    }
 
 }
 void choose_input_stack(int s[],int n)
 {
   int item,stack_choice, check =1;
   int top = - 1;
   
    while(check==1)
   {
   printf("Enter 1 for PUSH operation.\n");
   printf("Enter 2 for POP operation.\n");
   printf("Enter 3 for Top_val operation.\n");
   printf("Enter 4 for IsEmpty operation.\n");
   printf("Enter 5 for IsFull operation.\n");
   printf("Enter 6 for Display operation.\n");
   printf("Enter 7 for EXIT.\n");
   scanf("%d",&stack_choice);
   switch(stack_choice)
    {
   case 1:
   printf("PUSH operation \n");
   printf("Which item do you want to insert?");
   scanf("%d",&item);
   push(s,&top,item,n);
   break;
  
   case 2:
   printf("POP operation\n");
   pop(s,&top,item,n);
   break;
   
  
   case 3:
   printf("Top_val operation\n");
   int y = top_val(s, &top);
   printf("%d",y);
   break;
  
   
   case 4:
   printf("IsEmpty operation\n");
   int x = isEmpty(&top);
   if(x == 0)
   printf("Underflow");
   else
   printf("Not empty");
   break;
   
   case 5:
   printf("IsFull operation\n");
   int w = isFull(&top ,n);
   if(w == 0)
   printf("Overflow");
   else
   printf("Not full");
   break;
   
   case 6:
   printf("Display operation\n");
   display(s,&top);
   break;
 
   case 7:
   printf("EXIT\n");
   check = 0;
   break;
  
   default:
   printf("Invalid Input");
   break;
   }
  }
}

void push(int s[],int* top,int item, int max)
{  
    if(isFull(&(*top), max)== 0)
  { 
      printf("Overflow.\n");
  }
   else 
   {
      *top = *top + 1;   
      s[*top] = item;
  
   }
}

void pop(int s[],int* top,int item, int max)
{
   if(isEmpty(&(*top))== 0) 
   {
     printf("Underflow.\n");
      
   }
    else 
    {
        item = s[*top];
        *top = *top - 1; 
   }
}

int top_val(int s[], int* top)
{
   return s[*top];
}

int isEmpty(int *top)
{
 if(*top == -1)
 return 0;
 else
 return 1;
 }
 
int isFull(int* top ,int max)
 {
  if(*top == max - 1)
  return 0;
  else 
  return 1;
 }


 void display(int s[], int* top)
 {
   if(*top == -1)
   printf("Stack is empty");
   else
   for(int i= *top; i>=0 ; i--)
   {
    printf("%d", s[i]);
   }
 }

void insert(int queue[], int n, int *front, int *rear)
{
    int item;
   
    printf("What element do you want to insert?\n");
    scanf("%d", &item);

    if(*rear == n-1)
    {
        printf("Overflow\n");
    }
    else if(*front == -1 && *rear == -1)
    {
        *front = 0;
        *rear = 0;
        queue[*rear] = item;
    }
    else
    {
        *rear+=1;
        queue[*rear] = item;
    }
}

void delete(int queue[], int n, int *front, int *rear)
{
    int item;
    if(*front == -1 && *rear == -1)
    {
        printf("Underflow\n");
    }
   else if(*front == *rear)
    {
        printf(" %d deleted.\n", queue[*front]);
        *front = -1;
        *rear = -1;
    }
    else
    {
        item = queue[*front];
        printf(" %d deleted.\n", item);
        *front+=1;
    }
}

void Front_val(int queue[], int *front, int *rear)
{
    if(*front == -1 && *rear == -1)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("%d\n", queue[*front]);
    }
}

void Rear_val(int queue[], int *front, int *rear)
{
    /*if(*front == -1 && *rear == -1)
    {
        printf("Underflow\n");
    }
    else*/
    {
        printf("%d", queue[*rear]);
    }
}

void IsEmptyQ(int *front, int *rear)
{
   if(*front == -1 && *rear == -1)
   {
       printf("Underflow\n");
   }
   else
   {
       printf("Queue is not empty.\n");
   }
}

void IsFullQ(int *rear, int n)
{
    if(*rear == n-1)
    {
        printf("Overflown");
    }
    else
    {
        printf("Queue is not full.\n");
    }
}

void displayQ(int queue[], int *front, int *rear)
{
    if(*front == -1 && *rear == -1)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("The queue is\n");
        for(int i=*front; i<(*rear+1); i++)
        {
            printf("%d\t", queue[i]);
        }
        printf("\n");

    }
}

void insertCQ(int circular[], int n, int *front, int *rear)
{
    int item;
   
    printf("What element do you want to insert?\n");
    scanf("%d", &item);

    if(*rear == *front - 1)
    {
        printf("Overflow\n");
    }
    else if(*front == -1 && *rear == -1)
    {
        *front = 0;
        *rear = 0;
        circular[*rear] = item;
    }
    else
    {
        *rear = (*rear + 1) % n;
        circular[*rear] = item;
    }
}

void deleteCQ(int circular[], int n, int *front, int *rear)
{
    if(*front == -1 && *rear == -1)
    {
        printf("Underflow\n");
    }
    else if(*front == *rear)
    {
        printf(" %d deleted.\n", circular[*front]);
        *front = -1;
        *rear = -1;
    }
    else
    {
        printf("%d deleted.\n", circular[*front]);
        *front = (*front + 1) % n;
    }
}


void Rear_valCQ(int queue[], int *front, int *rear, int n)
{
    /*if(((*rear+1)%n) == *front)
    {
        printf("Overflow\n");
    }
    else*/
    {
        printf("%d\n", queue[*rear]);
    }
}


void IsFullCQ(int *front, int *rear, int n)
{
    if(((*rear+1)%n) == *front)
    {
        printf("Overflow\n");
    }
    else
    {
        printf("Queue is not Full.\n");
    }
}

void displayCQ(int circular[], int *front, int *rear, int n)
{
    int i = *front;

    if(*front == -1 && *rear == -1)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("The queue is:\n");
        while(i != *rear)
        {
            printf("%d\t", circular[i]);
            i = (i+1) % n;
        }
        printf("%d\n", circular[*rear]);
    }
}



