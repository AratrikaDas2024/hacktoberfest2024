#include <stdio.h>
#define max 6

struct node
{
    int f, r;
    int queue[max];
} q;

void enqueue(int data)
{
    if (q.f == -1 && q.r == -1)
    {
        q.f = q.r = 0;
        q.queue[q.r] = data;
    }
    else if ((q.r + 1)%max == q.f)
    {
        printf("Queue Overflow\n");
    }
    else
    {
       q.r = (q.r + 1) % max;
       q.queue[q.r] = data;
    }
}

int dequeue ()
{
    int del;
    if (q.f == -1 && q.r == -1)
    {
        printf("queue Underflow\n");
    }
    else if (q.f == q.r)
    {
        del = q.queue[q.f];
        q.f = q.r = -1;
    }
    else 
    {
        del = q.queue[q.f];
        q.f = (q.f + 1) % max;
    }

    return del;
}

void display ()
{
    if (q.f == -1 && q.r == -1)
    {
        printf("Empty Queue\n");
        return;
    }
    int i = q.f;
    while (i != q.r)
    {
        printf("%d\t",q.queue[i]);
        i = (i+1)%max;
    }
    printf("%d ",q.queue[q.r]);
}

int main ()
{
    q.f = q.r = -1;
    int op,i,cont=1,n,item,del;
    while (cont == 1)
    {
        printf("Enter 1 for enqueue operation\nEnter 2 for dequeue operation\nEnter 3 for display\nEnter 4 to exit\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1 : printf("Enter the number of elements to be inserted in the queue : ");
            scanf("%d",&n);
            for (i=0;i<n;i++)
            {
                printf("Enter item : ");
                scanf("%d",&item);
                enqueue(item);
            }
            break;
            case 2 :
            del = dequeue();
            printf("%d is deleted from the qeueue\n",del);
            break;
            case 3 : printf("The queue is as follows : \n");
            display();
            break;
        }
        printf("\nDo you want to continue ? (1 for yes and 0 for no)");
        scanf("%d",&cont);
    }
    return 0;
}
