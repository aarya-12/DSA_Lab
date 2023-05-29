#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void choose_input(int* ,int,int);
void bestcase(int* , int);
void worstCase(int* , int);
void avgCase(int* , int);
void almostSorted(int* , int);
void bestcase_CS(int a[], int n);
void avgcase_CS(int a[], int n);
void worstcase_CS(int a[], int n);
void selectionsort(int* , int, int);
void bubbleSort(int* , int, int); 
void insertionsort(int* , int, int);
void shellSort(int array[], int n, int input);
void countSort(int* , int , int);

int main()
{  
  int choice,n,input;
   
  int* arr;
  printf("Enter the number of elements of the array: "); 
  scanf("%d", &n);
  arr=(int *)calloc(n, sizeof(int));

  while(1)
  {
  printf("Which of the following sorts do you want to execute?\n");
  printf("Enter 1 for Selection Sort.\n");
  printf("Enter 2 for Bubble Sort.\n");
  printf("Enter 3 for Insertion Sort.\n");
  printf("Enter 4 for Shell Sort.\n");    
  printf("Enter 5 for Counting Sort.\n");
  printf("Enter 6 for EXIT.\n");
  scanf("%d", &choice);
 
  switch (choice)
  {
   
    case 1:
    printf("Selection Sort \n");
    while(1)
   {
    choose_input(arr,n,choice);
   }
    break;
    
    case 2:
    printf("Bubble Sort \n");
    while(1)
    {
    choose_input(arr,n,choice);
    }
    break;
    
    case 3:
    printf("Insertion Sort \n");
    while(1)
    {
    choose_input(arr,n,choice);
    }
    break;
    
    case 4:
    printf("Shell Sort \n");
    while(1)
    {
     choose_input(arr,n,choice);
    }
    break;
    
    case 5:
    printf("Counting Sort \n");
    while(1) 
    {
     choose_input(arr,n,choice);
     }
    break;
    
    case 6:
    printf("EXIT");
    exit(0);
    break;
    
    default:
    printf("Invalid Input");
    break;
 }
 }
 }
 
 void choose_input(int a[],int n,int choice)
 {
    int input;
    printf("%d",choice);
    printf("Which input do you want?\n");
    printf("Enter 1 for Best case.\n");
    printf("Enter 2 for Worst case.\n");
    printf("Enter 3 for Average case.\n"); 
    printf("Enter 4 for Almost sorted case.\n"); 
    printf("Enter 5 for EXIT.\n");
    scanf("%d",&input);
   
    switch(input)
    {
    case 1:
    printf("Best Case\n");
    bestcase(a,n);
    if (choice == 1)
    {
        
        selectionsort(a,n,input);
    }
    else if (choice == 2)
    {
       
        bubbleSort(a,n,input);
    }
    else if (choice == 3)
    {
       
        insertionsort(a,n,input);
    }
    else if (choice == 4)
    {
        
        shellSort(a,n,input);
    }
    else if (choice == 5)
    {
       
        bestcase_CS(a,n);
        countSort(a,n,input);
    }
    break;
    
    case 2:
    printf("Worst case\n");
    worstCase(a,n);
    if (choice == 1)
    {
       
        selectionsort(a,n,input);
    }
    else if (choice == 2)
    {
     
        bubbleSort(a,n,input);
    }
    else if (choice == 3)
    {
        insertionsort(a,n,input);
    }
    else if (choice == 4)
    {
        shellSort(a,n,input);
    }
    else if (choice == 5)
    {
        worstcase_CS(a, n);
        countSort(a,n,input);
    }
    break;
    
    case 3:
    printf("Average case \n");
    avgCase(a,n);
    if (choice == 1)
    {
       
        selectionsort(a,n,input);
    }
    else if (choice == 2)
    {
        bubbleSort(a,n,input);
    }
    else if (choice == 3)
    {
        insertionsort(a,n,input);
    }
    else if (choice == 4)
    {
        shellSort(a,n,input);
    }
    else if (choice == 5)
    {
        avgcase_CS( a, n);
        countSort(a,n,input);
    }
    break;
    
    case 4:
    printf("Almost sorted case \n");
    almostSorted(a,n);
    if (choice == 1)
    {
        selectionsort(a,n,input);
    }
    else if (choice == 2)
    {
        bubbleSort(a,n,input);
    }
    else if (choice == 3)
    {
        insertionsort(a,n,input);
    }
    else if (choice == 4)
    {
        shellSort(a,n,input);
    }
    else if (choice == 5)
    {
        countSort(a,n,input);
    }
    break;
    case 5:
    printf("EXIT\n");
    main();
    break;
    
    default:
    printf("Invalid Input");
    break;
    }
}
void bestcase(int a[], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        a[i] = i + 1;
       // printf("%d  ", a[i]);
    }

}
void worstCase(int a[], int n)
{
    int i;
    int size = n;

    for(i=0; i < size; i++, n-- )
    {
        a[i] = n;
      //  printf("%d  ", a[i]);
    }
}

void avgCase(int a[], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        a[i] = rand()%10000;
      //  printf("%d  ", a[i]);
    }
}
void almostSorted(int a[], int n)
{
   int i, t=99;
    for(i = 0; i < n; i++)
    {
        if(i%5==0)
        {
         a[i]=t;
         t++;
        // printf("%d  ", a[i]);
        }
        else
        {
         a[i] = i + 1;
        // printf("%d  ", a[i]);
        }
        
      
    } 
    
}
void bestcase_CS(int a[], int n)
{
    printf("hello");
    int i;

    for(i = 0; i < n; i++)
    {
        a[i] = 3;
       // printf("%d  ", a[i]);
    }

}
void avgcase_CS(int a[], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        a[i] = i + 1;
       // printf("%d  ", a[i]);
    }

}

void worstcase_CS(int a[], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        a[i] = rand()%10000;
      //  printf("%d  ", a[i]);
    }
    a[n-1] = 99;
}
void selectionsort(int a[], int n,int input)
{
  int i, j, position, swap;
  double cputime;
   clock_t t1,t2;
  t1= clock();
  for(i=0; i<(n-1); i++)
  {
    position = i;

    for(j=(i+1); j<n; j++ )
    {
      if (a[position]>a[j])
      position=j;
    }

    if(position != i)
    {
      swap=a[i];
      a[i]=a[position];
      a[position]=swap;
    }
  }
  t2 = clock();

  cputime = (double)(t2-t1)/CLOCKS_PER_SEC;
  printf("Time for selection sort for case %d is %lf\n",input,cputime);
}
void insertionsort(int a[], int n, int input)
{
    int i, j, key;
    double cputime;
     clock_t t1,t2;
    t1 = clock();

    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        while(j >= 0 && a[j] > key)
        {
            a[j+1] = a[j];
            j = j-1;
        }

        a[j+1] = key;

    }


    t2 = clock();

    cputime = (double)(t2-t1)/CLOCKS_PER_SEC;

    printf("Time for insertion sort for case %d is %lf\n", input, cputime);

}

void bubbleSort(int a[], int n, int input)
{
  int i,j,t;
  double cputime;
   clock_t t1,t2;
  t1 = clock();
  for(i=0; i<(n-1); i++)
  {
    for(j=0; j<(n-i-1); j++)
    {
      if (a[j] > a[j+1])
      {
        t = a[j];
        a[j] = a[j+1];
        a[j+1] = t;
      }
    }

  }
  t2 = clock();
  
  cputime = (double)(t2-t1)/CLOCKS_PER_SEC;

  printf("Time for bubble sort for case %d is %lf\n", input, cputime);
}

void shellSort(int array[], int n,int input)
 {
 
 double cputime;
 clock_t t1,t2;
  t1 = clock();
  for (int gap_size = n / 2; gap_size > 0; gap_size /= 2)
   {
    for (int i = gap_size; i < n;  i++) 
    {
      int key = array[i];
      int j;
      for (j = i; j >= gap_size && array[j - gap_size] > key; j -= gap_size) 
      {
        array[j] = array[j - gap_size];
      }
      array[j] = key;
    }
  }
  t2 = clock();
  
  cputime = (double)(t2-t1)/CLOCKS_PER_SEC;

  printf("Time for shell sort for case %d is %lf\n", input, cputime);
}

void countSort(int a[] , int n, int input)
{   
    int i;
    double cputime;
    int max = a[0];
    clock_t t1,t2;
    t1 = clock();
    int *count;
    count = (int *)calloc(max+1, sizeof(int));

    int *output;
    output = (int *)calloc(n, sizeof(int));
    
    for (int i = 0; i < n; i++) 
    {
    if (a[i] > max)
      max = a[i];
    }
    for(i=0;i<n-1 ;i++)
    {
      count[a[i]]=count[a[i]]+1;
    }
    for (int i = 1; i <= max; i++) 
    {
    count[i] = count[i] + count[i - 1]; //modified count array
    }
    for (int i = n - 1; i >= 0; i--)
    {
    output[count[a[i]] - 1] = a[i];
    count[a[i]]--;
    }
    t2 = clock();
  
    cputime = (double)(t2-t1)/CLOCKS_PER_SEC;

    printf("Time for count sort for case %d is %lf\n", input, cputime);
}