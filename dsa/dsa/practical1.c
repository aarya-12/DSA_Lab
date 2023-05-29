#include <stdio.h>
#include <stdlib.h>
#define MAX 20
void create(int *, int);
void insert(int, int , int *, int );
void delete(int ,int*);
void print(int *,int);
void copy(int *,int,int *);
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void binarySearch(int arr[], int element, int n);
void linearSearch(int arr[], int element, int n);
int length_of_array(int *);
int isFull(int *);
int isEmpty(int *);
void merging(int*, int);

int main()
{  int choice,switchChoice, searchChoice;
  int *arr,*arrb,n,i,n1;
  int element,val,pos,y,pos2,pos3;
  arrb = (int *)calloc(MAX, sizeof(int)); 
 
  while(1)
  {
  printf("Which of the following tasks do you want to execute?\n");
  printf("Enter 1 for Creation.\n");
  printf("Enter 2 for Insertion.\n");
  printf("Enter 3 for Deletion.\n");    
  printf("Enter 4 for Copy.\n");
  printf("Enter 5 for Sorting.\n");
  printf("Enter 6 for Searching.\n");
  printf("Enter 7 for Length of Array.\n");
  printf("Enter 8 for IsEmpty.\n");
  printf("Enter 9 for IsFull.\n");
  printf("Enter 10 for Traversal.\n");
  printf("Enter 11 to Merging.\n");
  printf("Enter 12 for EXIT.\n");

  scanf("%d", &choice);
 
  switch (choice)
  {
   
    case 1:
    arr=(int *)calloc(MAX, sizeof(int));
    printf("Enter the number of elements of the array: ");
    scanf("%d", &n);
    arr[0]=-99;
    create(arr, n);
    break;

    case 2:
    printf("Enter the value you want to insert and its position");
    scanf("%d %d",&val,&y);
    pos=y-1;
    n1= isFull(arr);
    n= length_of_array(arr);
    if(n1==0 || pos>n)
    {
      printf("Not possible");
    }
    else 
    {
    insert(val,pos,arr,n);
    print(arr,length_of_array(arr));
    }
    break;
   
   
    case 3:
    printf("Deletion");
   
    if(isEmpty(arr)==1)
    {   printf("Not possible");
    }
    else
    {
    printf("Enter the position you want to delete");
    scanf("%d",&pos2);
    pos3=pos2-1;
    delete(pos3,arr);
    print(arr,length_of_array(arr));
    }
    break;
   
    case 4:
    printf("Copy \n");
    copy(arr,length_of_array(arr),arrb);  
    break;
   
    case 5:
    printf("Which of the following sorting methods would you like to execute \n");
    printf("Enter 1 for Bubble Sort.\n");
    printf("Enter 2 for Selection Sort.\n");
    scanf("%d", &switchChoice);
    switch (switchChoice)
    {
      case 1:
      printf("Bubble Sort: \n");
      bubbleSort(arr, n);
      print(arr,length_of_array(arr));
      printf("Bubble Sort Complete!\n");
      break;

      case 2:
      printf("Selection Sort: \n");
      selectionSort(arr, n);
      print(arr,length_of_array(arr));
      printf("Selection Sort Complete!\n");
      break;
    }
    break;

    case 6:
    printf("Which of the following searching methods would you like to execute?\n");
    printf("Enter 1 for Linear Search.\n");
    printf("Enter 2 for Binary Search.\n");
    scanf("%d", &searchChoice);
    switch (searchChoice)
    {
      case 1:
      printf("Linear Search: \n");
      printf("Which number do you want to search for? \n");
      scanf("%d", &element);
      linearSearch(arr, element, n);
      printf("Linear Search Complete!");
      break;

      case 2:
      printf("Binary Search Sort: \n");
      printf("Which number do you want to search for? \n");
      scanf("%d", &element);
      binarySearch(arr, element, n);
      printf("Binary Search Complete!");
      break;
    }
    break;
    case 7:
    length_of_array(arr);
    printf("The length of array is %d",length_of_array(arr));
   
    case 8:
    isEmpty(arr);
    if(isEmpty(arr)==1)
     printf("Empty\n");
    else
     printf("Not empty\n");
    break;

    case 9:
    isFull(arr);
    if(isFull(arr)==1)
     printf("Not full\n");
    else
     printf("Full\n");
    break;

    case 10:
    printf("Traversal\n");
    print(arr,length_of_array(arr));
    break;
   
    case 11:
    printf("Merging\n");
    copy(arr,length_of_array(arr),arrb); 
    merging(arrb, length_of_array(arrb)); 
    break;
   
    case 12:
    exit(0);
    break;

    default:
    printf("Invalid Input! Try Again!");
    break;
  }
  }

  return 0;

}



void create(int a[], int n)
{
  int i;
 
  printf("Enter %d number of elements: \n", n);
  for(i=0;i<n;i++)
  {
    a[i+1]=a[i];
    scanf("%d", &a[i]);
  }
}

void insert(int v, int p, int a[], int n)
{
   int x;
   x=n;
 while(x!=p)
  {
  a[x] = a[x-1]; 
  x--;
  }
a[p]=v;
a[n+1]=-99;

}
void delete(int x1, int a[])
{
    int back;
    int n = length_of_array(a);
    if(x1>n-1 || n==0)
    {
        printf("Not possible");
    }
    else
    back = x1;
    while(back<n)
    {
        a[back]=a[back+1];
        back++;
    }


}

void print(int a[],int n)
{
  int i=0;
 
  printf("Elements of the array are: ");

  while(a[i]!= -99)
  {
    printf("%d\t", a[i]);
    i++;
  }
  printf("\n");
}

void bubbleSort(int arr[], int n)
{
  int c,d,t;

  for(c=0; c<(n-1); c++)
  {
    for(d=0; d<(n-c-1); d++)
    {
      if (arr[d] > arr[d+1])
      {
        t = arr[d];
        arr[d] = arr[d+1];
        arr[d+1] = t;
      }
    }

  }

}

void selectionSort(int arr[], int n)
{
  int i, j, position, swap;

  for(i=0; i<(n-1); i++)
  {
    position = i;

    for(j=(i+1); j<n; j++ )
    {
      if (arr[position]>arr[j])
      position=j;
    }

    if(position != i)
    {
      swap=arr[i];
      arr[i]=arr[position];
      arr[position]=swap;
    }
  }
}

void binarySearch(int arr[], int element, int n)
{
    int f=0, r=n, mid;

    while (f <= r)
    {
        mid = (f+r)/2;

        if(arr[mid] ==  element)
        {
            printf("\nSearch Element  : %d  : Found :  Position : %d.\n", element, mid+1);
            break;
        }

        else if(arr[mid] < element)
        {
            f = mid + 1;
        }

        else
        {
            r = mid - 1;
        }
     }

     if (f > r)
      printf("\nSearch Element : %d  : Not Found \n", element);
}

void linearSearch(int arr[], int element, int n)
{
    int i;

    for(i=0; i<n; i++)
    {
        if (arr[i] == element)
        {
          printf("Linear Search : %d is Found at array : %d.\n", element, i + 1);
          break;  
        }
    }

    if(i==n)
    {
         printf("\nSearch Element : %d  : Not Found \n", element);
    }
}

int length_of_array(int *p)
{
  int count=0;
  while(*p != -99)
  {
    count++;
    p++;
  }
  return count++;
}

int isFull(int a[])
{
int check=length_of_array(a);
if(check==MAX-1)
 return 0;
else
 return 1;
}

int isEmpty(int a[])
{
  int check = length_of_array(a);
  if(check==0)
   return 1;
  else
   return 0;
}
void copy(int a[],int w,int arrb[])
{

   // int* arrb= (int*)calloc(w,sizeof(int));
    //int arrb[w];
    for (int i = 0; i < w; i++)
    {    
        arrb[i] = a[i]; 
       
    }
    arrb[w] =-99;  
    print(arrb,length_of_array(arrb));
    
}


  void merging(int a[], int n)
{
  int temp = n;
  int l2,c;  
  printf("Enter the size of second array: \n"); 
  scanf("%d", &l2);
  c = l2 + n;
  if(c>MAX)
  {
    printf("Merging not possible!\n");
  }
  else
  {
    int *b;
  b = (int *)calloc(MAX, sizeof(int));
  b[0]=-99;
  create(b,l2);
  bubbleSort(a, n);
    for (int i = 0; i < l2; i++)
    {
      int check = 1;
        for (int j = 0; j < temp; j++)
        {
          if (b[i] < a[j])
            {
                insert(b[i], j, a, c);
                check = 0;
                temp++;
                break;
            }
        }
        if (check == 1)
        {
            a[temp] = b[i];
            temp++;
        }
    }
  
    a[temp]=-99; 
   printf("Elements of the array are: \n");
    for (int i = 0; i < c; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
  
 }
}

