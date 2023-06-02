#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int r;
    int f;
    int size;
    int *arr;
};
int isFull(struct Queue *q)
{
    if(q->r==q->size-1)
        return 1;
    return 0;
}

int isEmpty(struct Queue *q)
{
    if(q->r==q->f)
        return 1;
    return 0;
}

void  Enqueue(struct Queue *q, int val)
{
    if(isFull(q))
    {
        printf("Queue is full");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int  Dequeue(struct Queue *q)
{
    int a =-1;
    if( q->f == q->r)
    {
        printf("no element to deque");
    }
    else
    {
        q->f++;
        a= q->arr[q->f];
    }
    return a;
    
}
int main()
{
    struct Queue q;
    q.size=400;
    q.r=-1;
    q.f=-1;
    q.arr = (int *) malloc (q.size*sizeof(int));



    //IMPLIMENTATION OF BFS
    int visited[4]={-1,-1,-1,-1};
    int matrix[7][7] = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {1, 0, 0, 0}
    };

    int node;   // to take dequeued element
    int i =0;  // STARTING ELEMENT YOU WANT TO VISIT
    visited[i] = 0;
    printf("%d",i);
    Enqueue(&q,i);
    int flag =0;
    while(!isEmpty(&q))
    {
        int node = Dequeue(&q);
         visited[node] = 1;
        for(int j=0; j<4;j++)
        {
            if(matrix[node][j]==1 && visited[j]==0)
            {
                printf("\n");
                printf("cycle exists");
                flag =1;
            }

            if(matrix[node][j]==1 && visited[j]==-1)  // node = deque and queue has only indexes if in that index any other element is connected and not visited than we need to explore that element.
            {
                printf("%d",j);
                visited[j]=0;
                Enqueue(&q,j);
            }
        }
    }
    if (flag==0)
    {
       printf("\n");
       printf("cycle does not exists");
    }
    
     

    return 0;
}