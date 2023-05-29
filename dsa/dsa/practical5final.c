#include <stdio.h>
#include <stdlib.h>
 struct Node
{
    int data;
    struct node* next;
}; struct Node typedef List;

List* create_node();
List* Creation(List *s);
void display(List* temp);
List* InsertAtBeg(List *Start, int Data);
List* InsertAtEnd(List *Start, int Data);
List* InsertAtPosition(List *Start, int Data, int pos);
List* insertOrder(List*, int);
int length(List**);
List* concatenate(List*, List*);
List* DeleteAtBeg(List*);
List* DeleteAtEnd(List*);
List* DeleteAtPosition(List*, int);
void Search(List *Start, int Data);
void Sort(List *Start);
List* Copy(List *S1);
List* Reverse(List* Start);

int main()
{ 
 int choice,count,inputChoice,check,Data,pos,Choice1, Choice2;
 int* s;
 List* p = 0;
 List* Start2 = 0;
 List* Start = 0;
 List* S1 =0;
 List* StartS = 0;
 List* StartQ = 0;
 while(1)
 {
 printf("Which operation do you want to perform on the linked list?\n");
 printf("Enter 1 for Creation of node.\n");
 printf("Enter 2 for Insert operation.\n");
 printf("Enter 3 for Delete operation.\n");
 printf("Enter 4 for Traversal (Display) operation.\n");
 printf("Enter 5 for Search operation.\n");
 printf("Enter 6 for Concatenation operation.\n");
 printf("Enter 7 for Sorting operation.\n");
 printf("Enter 8 for Copying operation.\n");
 printf("Enter 9 for Reverse operation.\n");
 printf("Enter 10 for Length operation.\n");
 printf("Enter 11 for Creation of List.\n");
 printf("Enter 12 for Stack Operations.\n");
 printf("Enter 13 for Queue Operations.\n");
 printf("Enter 14 for EXIT.\n");
 scanf("%d", &choice);
 switch (choice)
 {
 
   case 1:
   
   printf("Creation of node\n");
   p = create_node();
   if(p != NULL)
   printf("Node created at address %lu.\n",(unsigned long)p);
  
   break;
  
   case 2:
   printf("Insert operation\n");
   int insert_choice,check = 1;
   while(check == 1)
 {
 printf("Where do you want to insert?\n");
 printf("Enter 1 to insert at the beginning.\n");
 printf("Enter 2 to insert at specified position.\n");
 printf("Enter 3 to insert at the end.\n");
 printf("Enter 4 to insert in an ordered linked list.\n");
 printf("Enter 5 to Display insertion.\n");
 printf("Enter 6 to Exit.\n");
 scanf("%d",&insert_choice);
switch (insert_choice)
{
   case 1:
   printf("At beginning\n");
   printf("What do you want to insert?\n");
   scanf("%d", &Data);
   Start = InsertAtBeg(Start,Data);
   break;
  
   case 2:
   printf("At specified position\n");
   printf("At which position do you want to insert?\n");
   scanf("%d",&pos);
   printf("What do you want to insert?\n");
   scanf("%d", &Data);
   Start = InsertAtPosition(Start,Data,pos);
   break;
  
   case 3:
   printf("At end\n");
   printf("What do you want to insert?\n");
   scanf("%d", &Data);
   Start = InsertAtEnd(Start,Data);
   break;

   case 4:
   printf("Insertion in an ordered linked list:\n");
   printf("Enter the number you want to insert:\n");
   scanf("%d", &Data);
   Start = insertOrder(Start, Data);
   break;
   
   case 5:
   printf("Displaying insertion\n");
   display(Start);
   break;

   case 6:
   printf("EXIT");
   check = 0;
   break;
  
   default:
   printf("Invalid Input");
   break;
}
}check = 1;
   break;
  
   case 3:
   printf("Delete operation\n");
       check = 1;
                while(check == 1)
                {
                    printf("Deletion:\n");
                    printf("Enter 1 for deletion at the beginning.\n");
                    printf("Enter 2 for deletion at the end.\n");
                    printf("Enter 3 for deletion of a specific position.\n");
                    printf("Enter 4 for displaying the linked list.\n");
                    printf("Enter 5 for Exit.\n");
                    scanf("%d", &inputChoice);

                    switch(inputChoice)
                    {
                        case 1:
                        printf("Deletion at beginning:\n");
                        Start = DeleteAtBeg(Start);
                        break;

                        case 2:
                        printf("Deletion at end:\n");
                        Start = DeleteAtEnd(Start);
                        break;

                        case 3:
                        printf("Deletion at a specific position:\n");
                        count = length(&Start);
                        printf("Enter the position:\n");
                        scanf("%d", &pos);
                        if(pos > count)
                        {
                            printf("Invalid Position!\n");
                            break;
                        }
                        else
                        {
                            Start = DeleteAtPosition(Start, pos);
                            break;
                        }

                        case 4:
                        printf("Display\n");
                        display(Start);
                        break;

                        case 5:
                        check = 0;
                        break;

                        default:
                        printf("Invalid Input:\n");
                        break;

                    }
                }
                check = 1;
                break;

   case 4:
   printf("Traversal (Display) operation\n");
   display(Start);
   break;

   case 5:
   printf("Search operation\n");
   printf("Which element do you want to search?\n");
   scanf("%d",&Data);
   Search(Start,Data);
   break;

   case 6:
   printf("Concatenation operation\n");
   printf("Enter details for the other linked list.\n");
   Start2 = Creation(Start2);
   Start = concatenate(Start, Start2);
   break;

   case 7:
   printf("Sorting operation\n");
   Sort(Start);
   printf("The sorted list is:\n");
   display(Start);
   break;

   case 8:
   printf("Copying operation\n");
   S1 = Copy(Start);
   printf("The copied list is:\n");
   display(S1);
   break;

   case 9:
   printf("Reverse operation\n");
    Start = Reverse(Start);
   printf("The reversed list is:\n");
   display(Start);
   break;
   
   case 10:
   printf("Length operation\n");
   count= length(&Start);
   printf("The length of the list is %d.\n", count);
   break;

   case 11:
   printf("Creation of List\n");
   Start= Creation(Start);
   display(Start);
   break;

   case 12:
   check = 1;
   while(check == 1)
    {
                    printf("Stack Operations:\n");
                    printf("Enter 1 for Push.\n");
                    printf("Enter 2 for Pop.\n");
                    printf("Enter 3 for Top Value.\n");
                    printf("Enter 4 for Display.\n");
                    printf("Enter 5 for Exit.\n");
                    scanf("%d", &Choice1);

                    switch(Choice1)
                    {
                        case 1:
                        printf("Push operation:\n");
                        printf("Enter number you want to insert:\n");
                        scanf("%d", &Data);
                        StartS = InsertAtBeg(StartS,Data);
                        break;

                        case 2:
                        printf("Pop operation:\n");
                        StartS = DeleteAtBeg(StartS);
                        break;

                        case 3:
                        printf("Top Value operation:\n");
                        if(StartS == NULL)
                        {printf("List is empty\n");}
                        else
                        {printf("The top value is, %d\n", StartS -> data);}
                        break;
                       
                        case 4:
                        printf("Traversal operation:\n");
                        display(StartS);
                        break;

                        case 5:
                        printf("EXIT\n");
                        check = 0;
                        break;

                        default:
                        printf("Invalid Input:\n");
                        break;

                    }
                }
    check = 1;
    break;

    case 13:
    check = 1;
    while(check == 1)
     {
                    printf("Queue Operations:\n");
                    printf("Enter 1 for Insertion.\n");
                    printf("Enter 2 for Deletion.\n");
                    printf("Enter 3 for Display.\n");
                    printf("Enter 4 for Exit.\n");
                    scanf("%d", &Choice2);

                    switch(Choice2)
                    {
                        case 1:
                        printf("Insertion operation:\n");
                        printf("Enter number you want to insert:\n");
                        scanf("%d", &Data);
                        StartQ = InsertAtEnd(StartQ,Data);
                        break;

                        case 2:
                        printf("Deletion operation:\n");
                        StartQ = DeleteAtBeg(StartQ);
                        break;
                       
                        case 3:
                        printf("Traversal operation:\n");
                        display(StartQ);
                        break;

                        case 4:
                        printf("EXIT\n");
                        check = 0;
                        break;

                        default:
                        printf("Invalid Input:\n");
                        break;

                    }
                }
                check = 1;
                break;

   case 14:
   printf("EXIT");
   exit(0);
   break;
  
   default:
   printf("Invalid Input");
   break;
}
}
}


List* create_node()
{
    List* q;
    q = (List*)malloc(sizeof(List));
    if(q == NULL)
    {
        printf("Node not created.\n");
        return NULL;
    }
    else
    {
        printf("Node created \n");
        return q;
    }
}

List* Creation(List *s)
{
    int n,d;
    printf("How many nodes do you want to create? \n");
    scanf("%d",&n);
    for(int i = 0; i<n; i++)
    {
        printf("Enter data:\n");
        scanf("%d",&d);
        s = InsertAtBeg(s,d);
    }
    return s;
}

void display(List* temp) 
{
    if(temp == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("Start address is %lu \n",(unsigned long)temp);
        while((temp -> next) != NULL)
        {
            printf("%d | %lu -> ", temp -> data,(unsigned long) temp -> next);
            temp = temp -> next;
        }

        printf("%d | %lu \n ", temp -> data,(unsigned long) temp -> next);
    }
}

int length(List **Start)
{
    List *newNode, *temp;
    int count=0;

    temp = *Start;

     if(*Start == 0)
    {
        printf("The linked list is empty.\n");
    }
    else
    {
            while(temp != 0)
        {
            count++;
            temp = temp -> next;
        }

    }

    return count;
}

List* InsertAtBeg(List *Start, int Data)
{
    List *NewNode,*temp;
    NewNode = create_node();
    if(NewNode == NULL)
    {
        return Start;
    }
    NewNode ->data = Data;
    if(Start == NULL)
    NewNode ->next = NULL;
    else
    NewNode ->next = Start;

    Start = NewNode;
    return(Start);
}
List* InsertAtEnd(List *Start, int Data)
{
    List *NewNode,*temp;
    NewNode = create_node();
    if(NewNode == NULL)
    {
        return Start;
    }
    NewNode ->data = Data;
    NewNode ->next = NULL;
    if(Start == NULL)
    Start = NewNode;
    else
    {temp = Start;
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = NewNode;}
    return(Start);

}
List* InsertAtPosition(List *Start, int Data, int pos)
{
    List* NewNode;
    List* temp = Start;
    int k = 0;
    int count = length(&Start); 
    if(pos > count)
    {
      printf("Invalid Position!\n");
      return Start;
    }
    
    else
    {
    while(k < pos - 1)
     {
      temp = temp -> next;
      if(temp == NULL)
      {
          printf("Nodes present are less than position\n");
          return Start;
      }
      k=k+1;
      }
    NewNode = create_node();  
    if(NewNode == NULL)
    {
    return Start;
    }
    else
    {
    NewNode ->data = Data;
    NewNode ->next = temp -> next;
    temp -> next = NewNode;
    }
    }

return Start;

}

List* insertOrder(List *Start, int Data)
{
     List *NewNode, *temp, *m;

    NewNode = create_node();
    if(NewNode == NULL)
    {
        return Start;
    }
    NewNode-> data = Data;

    if(Start == NULL)
    {
        return NewNode;
    }

    if((Start -> data) >= (NewNode -> data))
    {
        NewNode -> next = Start;
        return NewNode;
    }
    temp = Start;
    m = temp -> next ;
    while((temp != NULL) && ((m -> data) <= (NewNode -> data)))
    {
        temp = temp -> next;
    }

    NewNode -> next = temp -> next;
    temp -> next = NewNode;
    return Start;

}

List* concatenate(List* a, List* b)
{
    if(a != 0 && b != 0)
    {
        if(a -> next == 0)
        {
            a -> next = b;
        }
        else
        {
            concatenate(a -> next, b);
        }

        return a;
    }
    else
    {
        printf("The linked list is empty!\n");
        return a;
    }  
}

List* DeleteAtBeg(List *Start)
{
    List *temp;
    if(Start == NULL)
    {
      printf("List is empty, deletion not possible\n");
      return Start;
    }
    temp = Start;
    Start = Start -> next;
    printf("The deleted element %d.\n",temp -> data);
    free(temp);

    return Start;
}

List* DeleteAtEnd(List* Start)
{
    List *Hold, *temp, *n;
    if(Start == NULL)
    {
      printf("List is empty, deletion not possible\n");
      return Start;
    }
    temp = Start;
    // n = temp -> next;
    while((temp -> next)!= NULL)
    {
        temp = temp -> next;
    }
    Hold = temp -> next;
    free(Hold);
    temp -> next = NULL;
    printf("The deleted node had the element %d.\n",temp -> data);
    return Start;

}

List* DeleteAtPosition(List* Start, int pos)
{
    List *temp, *Hold, *n;
    int k = 0;
    if(Start == NULL)
    {
      printf("List is empty, deletion not possible\n");
      return Start;
    }
    temp = Start;
    if(pos == 0)
    {
        Start = temp -> next;
        free(temp);
        return (Start);
    }
    while(k < pos-1)
    {
        temp = temp -> next;
        if(temp == NULL)
        {
            printf("Nodes in the list less than position\n");
        }
        k = k+ 1;
    }
    n = temp -> next;
    Hold = n  -> next;
    
    free(n);
    temp -> next = Hold;

    printf("The deleted node is %d.\n", n -> data);
    return Start;
}

void Search(List *Start, int Data)
{
  List *temp = Start;
  int pos = 0,check =0;
  while(temp != NULL)
  {
      if( temp -> data == Data) 
      {
          printf("Data found at position %d\n", pos+1);
          check =1;
      }
      temp = temp -> next;
      pos = pos +1;
      
  }
 
 if (temp == NULL && check == 0)
  {
      printf("Data not found\n");
  }
}

void Sort(List *Start)
{
    List *Hold = Start;
    List *temp, *k, *l;
    int count = 0, i =0;
    while(Hold != NULL)
    {
        Hold = Hold ->next;
        count = count + 1;
    }
    while(i<(count - 1))
    {
        temp = Start;
        while((temp -> next != NULL))
        {
            l = temp ->next ;
            if((temp ->data) > ( l -> data))
            {
               k = temp ->data;
               temp ->data = l -> data;
               l -> data = k;
            }
            temp = temp ->next;
        }
        i++;
    }
}

List* Copy(List *S1)
{
   List *temp;
   List *s2=NULL;
   temp=S1;
while (temp!=NULL)
{
s2 = InsertAtEnd(s2,temp->data);
temp=temp->next;
}
return s2; 
}

List* Reverse(List* Start)
{
List* prev = NULL;
List* current = Start;
List* next = NULL;
while (current != NULL)
{
next = current->next;
current->next = prev;
prev = current;
current = next;
}
Start = prev;
return Start;
}