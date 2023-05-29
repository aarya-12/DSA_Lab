//Q1
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    int priority;
    struct node* next;
}; struct node typedef List;

List* create_node();
List* insertOrder(List *Start, int Data, int Priority);
void display(List* temp);
List* DeleteAtBeg(List *Start);
int length(List**);

int main()
{
    int Choice, data, priority;
    List* Start = 0;
    int count;

    while(1)
    {
        printf("Enter 1 for Insertion operation.\n");
        printf("Enter 2 for Deletion operation.\n");
        printf("Enter 3 for Traversal operation.\n");
        printf("Enter 4 for Length of the List.\n");
        printf("Enter 5 to exit.\n");
        scanf("%d", &Choice);

        switch(Choice)
        {
            case 1:
            printf("Insertion:\n");
            printf("Enter the data:\n");
            scanf("%d", &data);
            printf("Enter its priority:\n");
            scanf("%d", &priority);
            Start = insertOrder(Start, data, priority);
            break;

            case 2:
            printf("Deletion:\n");
            Start = DeleteAtBeg(Start);
            break;

            case 3:
            printf("Traversal(Display):\n");
            display(Start);
            break;

            case 4:
            printf("Length operation\n");
            count= length(&Start);
            printf("The length of the list is %d.\n", count);
            break;

            case 5:
            printf("EXIT\n");
            exit(0);
            break;

            default:
            printf("Invalid input\n");
            break;
        }
    }

    return 0;
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
        printf("Node created. \n");
        return q;
    }
}

List* insertOrder(List *Start, int Data, int Priority)
{
    List *NewNode, *temp;
    NewNode = create_node();
    if(NewNode == NULL)
    {
        return Start;
    }
    NewNode-> data = Data;
    NewNode -> priority = Priority; 
    if(Start == NULL || Priority < (Start -> priority))
    {
      NewNode -> next = Start;
      Start = NewNode;
      return Start;
    }
    else
    {
    temp = Start;
    while((temp ->next != NULL) && ((temp -> next -> priority) <=  Priority))
    {
        temp = temp -> next;
    }

    NewNode -> next = temp -> next;
    temp -> next = NewNode;
    }
    return Start;

}

void display(List* temp) 
{
    if(temp == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while((temp -> next) != NULL)
        {
            printf("%d | %d -> ", temp -> data, temp -> priority);
            temp = temp -> next;
        }

        printf("%d | %d \n ", temp -> data,temp -> priority);
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
//Q3
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
}; struct node typedef List;

List* Creation(List *s, int n);
void display(List* temp);
List* InsertAtBeg(List *Start, int Data);
List* create_node();
void find_middle(List *Start, int n);

int main()
{ 
   List* Start = 0;
   int n;
   printf("Creation of List\n");
   printf("How many nodes do you want to create? \n");
    scanf("%d",&n);
   Start= Creation(Start,n);
   display(Start);
   printf("To find the middle of the given Linked List:\n");
   find_middle(Start, n);
}
List* Creation(List *s,int n)
{
    int d;
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
        printf("List is empty.\n");
    }
    else
    {
        // printf("Start address is %lu \n",(unsigned long)temp);
        while((temp -> next) != NULL)
        {
            printf("%d | %lu -> ", temp -> data,(unsigned long) temp -> next);
            temp = temp -> next;
        }

        printf("%d | %lu \n ", temp -> data,(unsigned long) temp -> next);
    }
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
        printf("Node created. \n");
        return q;
    }
}

void find_middle(List *Start, int n)
{
    int middle;
    middle = n/2;
    if(Start == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
    for(int i=0; i<middle; i++) // traversing the list till the middle element
    {
        Start = Start->next;
    } 
    printf("The middle of the linked list is %d.\n",Start -> data);
    }
    
}


