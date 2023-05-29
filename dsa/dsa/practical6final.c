#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *RP;
    struct node *LP;
}; struct node typedef List;

List* create_node();
List* Creation(List *s);
void display(List* temp);
List* InsertAtBeg(List *Start, int Data);
List* InsertAtEnd(List *Start, int Data);
List* InsertAtPosition(List *Start, int Data, int pos);
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
 int choice,Data,pos,count,Choice1,Choice2,inputChoice;
 List* Start = 0;
 List* Start2 = 0;
 List* StartS = 0;
 List* StartQ = 0;
 List* p=0;
 List* S1 = 0;
 while(1)
 {
 printf("Which operation do you want to perform on the doubly linked list?\n");
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
 printf("Enter 11 for Stack Operations.\n");
 printf("Enter 12 for Queue Operations.\n");
 printf("Enter 13 for EXIT.\n");
 scanf("%d", &choice);
 switch (choice)
 {
 
   case 1:
   
   printf("Creation of node\n");
   p = create_node();
   if(p != NULL)
   printf("Node created at address %lu | %lu | %lu.\n",(unsigned long)p->LP,(unsigned long)p, (unsigned long)p->RP);
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
   printf("Enter 4 to Display insertion.\n");
   printf("Enter 5 to Exit.\n");
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
   count = length(&Start);
   printf("At which position do you want to insert?\n");
   scanf("%d",&pos);
    if(pos < 1 || pos > count)
   {                  
        printf("Invalid Position!\n");
        break;
    }
    else if(pos == 1)
    {
        printf("What do you want to insert?\n");
        scanf("%d", &Data);
        Start = InsertAtBeg(Start,Data);
        break;
    }
    else if(pos == count)
    {
        printf("What do you want to insert?\n");
        scanf("%d", &Data);
        Start = InsertAtEnd(Start,Data);
        break;
    }
    else
    {
        printf("What do you want to insert?\n");
        scanf("%d", &Data);
        Start = InsertAtPosition(Start,Data,pos);
        break;
    }
   
   case 3:
   printf("At end\n");
   printf("What do you want to insert?\n");
   scanf("%d", &Data);
   Start = InsertAtEnd(Start,Data);
   break;

   case 4:
   printf("Displaying insertion\n");
   display(Start);
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
                        // printf(count);
                        printf("Enter the position:\n");
                        scanf("%d", &pos);
                        if(pos > count)
                        {
                            printf("Invalid Position!\n");
                            break;
                        }
                        else if(pos == 1)
                        {
                            Start = DeleteAtBeg(Start);
                            break;
                        }
                        else if(pos == count)
                        {
                            Start = DeleteAtEnd(Start);
                            break;
                        }
                        else
                        {
                            Start = DeleteAtPosition(Start, pos);
                            break;
                        }
                        //break;

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

    case 12:
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


   case 13:
   printf("EXIT\n");
   exit(0);
   break;
  
   default:
   printf("Invalid Input\n");
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
        while(temp != NULL)
        {
            printf("%lu | %d | %lu -> ", (unsigned long) temp -> LP,temp -> data,(unsigned long) temp -> RP);
            temp = temp -> RP;
        }
        printf("\n");

    }
}

List* InsertAtBeg(List *Start, int Data)
{
    List *NewNode;
    NewNode = create_node();
    NewNode ->data = Data;
    if(Start == NULL) //first node
    {
    NewNode ->LP = NULL;
    NewNode ->RP = NULL;
    Start = NewNode;
    }
    else
    {
        NewNode ->LP = NULL;
        NewNode ->RP = Start;
        Start -> LP = NewNode;
        Start = NewNode;
    }
    return(Start);
}

List* InsertAtEnd(List *Start, int Data)
{
    List *NewNode,*temp;
    NewNode = create_node();
    NewNode ->data = Data;
    NewNode ->RP = NULL;
    if(Start == NULL) //first node
    {
    NewNode ->LP = NULL;
    NewNode ->RP = NULL;
    Start = NewNode;
    }
    else
    {
    temp = Start;
    while(temp -> RP != NULL)
    {
        temp = temp -> RP;
    }
    temp -> RP = NewNode;
    NewNode -> LP = temp;
    }
    return(Start);

}

List* InsertAtPosition(List *Start, int Data, int pos)
{
    List* NewNode;
    List* Hold;
    List* temp = Start;
    int k = 0;
    
    
    while(k < pos - 1 && temp != NULL)
     {
      temp = temp -> RP;
      k=k+1;
      }
     if(temp != NULL && (k=pos-1))
    {
        NewNode = create_node();  
        NewNode ->data = Data;
        NewNode ->RP = temp -> RP;
        NewNode -> LP = temp;
        Hold = (temp -> RP);
        Hold -> LP = NewNode;
        (temp -> RP) = NewNode;

    }
    else
    {
    printf("Position not found");
    }

return Start;

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
            temp = temp -> RP;
        }

    }

    return count;
}

List* DeleteAtBeg(List *Start)
{
    List *temp;
    int key;
    if(Start == NULL)
    {
      printf("List is empty, deletion not possible\n");
      return Start;
    }
    if(Start -> RP == NULL)
    {
        free(Start);
        printf("The deleted element %d.\n",Start -> data);
        return NULL;
    }
    temp = Start;
    key = temp -> data;
    Start = Start -> RP;
    Start -> LP = NULL;
    free(temp);
    printf("The deleted element %d.\n",key);
    return Start;
}

List* DeleteAtEnd(List* Start)
{
    List *temp;
    int key;
    if(Start == NULL)
    {
      printf("List is empty, deletion not possible\n");
      return Start;
    }
    else if(Start -> RP == NULL)
    {
        free(Start);
        printf("The deleted element %d.\n",Start -> data);
        return NULL;
    }
    else
    {
    temp = Start;
    while((temp -> RP)!= NULL)
    {
        temp = temp -> RP;
    }
    key = temp -> data;
    temp -> LP -> RP = NULL;
    free(temp);
    printf("The deleted element %d.\n",key);
    }
    return Start;

}


List* DeleteAtPosition(List* Start, int pos)
{

    List *temp, *hold;
    int k = 1;
    temp = Start;
    if(temp == NULL)
    {
        printf("List is empty, deletion not possible\n");
        return NULL;
    }
    
    while(k < pos)
    {
        temp = temp -> RP;
        k = k + 1;
    }
    temp -> LP -> RP = temp -> RP;
    temp -> RP -> LP = temp -> LP; 

    printf("The deleted node is %d.\n", temp -> data);

    free(temp);

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
      temp = temp -> RP;
      pos = pos +1;
      
  }
 
 if (temp == NULL && check == 0)
  {
      printf("Data not found\n");
  }
}

List* concatenate(List* a, List* b)
{
    if(a != 0 && b != 0)
    {
        if(a -> RP == 0)
        {
            a -> RP = b;
        }
        else
        {
            concatenate(a -> RP, b);
        }

        return a;
    }
    else
    {
        printf("The linked list is empty!\n");
        return a;
    }  
}

void Sort(List *Start)
{
    List *Hold = Start;
    List *temp, *l;
    int count = 0, i =0, k;
    while(Hold != NULL)
    {
        Hold = Hold ->RP;
        count = count + 1;
    }
    while(i<(count - 1))
    {
        temp = Start;
        while((temp -> RP != NULL))
        {
            l = temp ->RP ;
            if((temp ->data) > ( l -> data))
            {
               k = temp -> data;
               temp ->data = l -> data;
               l -> data = k;
            }
            temp = temp ->RP;
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
temp=temp->RP;
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
next = current-> RP;
current-> RP = prev;
prev = current;
current = next;
}
Start = prev;
return Start;
}