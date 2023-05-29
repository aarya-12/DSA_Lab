/*  int matrix[5][5] = {
       0 1 1 1 0
       1 0 1 0 0 
       1 1 0 0 1
       1 0 0 0 0
       0 0 1 0 0

    };
    
        0______3
        | \
        |   2
        | /  \
        1      4
               */
#include <stdio.h>
#include <stdlib.h>


void BFS(int n, int G[][n], int visited[], int x);
void DFS(int n, int G[][n], int visited[], int x);


int main()
{
    int node, i, j, n, choice;

    printf("Enter the number of nodes:\n");
    scanf("%d", &n);
    int A[n][n];
    printf("Enter the Adjacency Matrix: \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    printf("\n");
    /*int node, n=5, choice;

    int A[5][5] = {
        {0,1,1,1,0},
        {1,0,1,0,0},
        {1,1,0,0,1},
        {1,0,0,0,0},
        {0,0,1,0,0}
    };*/

    printf("The Adjacency Matrix is:\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }

    while(1)
    {
        int *visited, x;
        visited = (int *)calloc(n, sizeof(int));

        printf("\nGraph Traversals\n");
        printf(" 1 for BFS.\n");
        printf(" 2 for DFS.\n");
        printf(" 3 for EXIT.\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            printf("BFS.\n");
            printf("Enter the source node:\n");
            scanf("%d", &x);
            BFS(n, A, visited, x);
            break;

            case 2:
            printf("DFS\n");
            printf("Enter the source node:\n");
            scanf("%d", &x);
            DFS(n, A, visited, x);
            break;

            case 3:
            printf("EXIT\n");
            exit(0);
            break;

            default:
            printf("Invalid Input\n");
            break;

        }
    }

    return 0;
}

void BFS(int n, int G[][n], int visited[], int x)
{
    int front = -1, rear = -1, q[100], vcount=0;

    printf("%d\t", x);

    visited[x] = 1;
    front += 1; //since insertion
    rear += 1;
    q[rear] = x;
    //q[front] = x;

    while(front <= rear)
    {
        x = q[front];
        front += 1;
        vcount = 0; 

        while(vcount < n)
        {
            if(G[x][vcount] && visited[vcount]!=1)
            {
                visited[vcount] = 1;
                printf("%d\t", vcount);
                rear += 1;
                q[rear] = vcount;
            }

            vcount += 1;
        } 

    }

    printf("\n");
}

void DFS(int n, int G[][n], int visited[], int x)
{
    int vcount = 0;
    printf("%d\t", x);
    visited[x] = 1;
    
    for(int vcount = 0; vcount < n; vcount++)
    {
        if(G[x][vcount]==1 && visited[vcount] != 1)
        {
            DFS(n, G, visited, vcount);
        }
    }
}