#include <stdio.h>
#define MAX_QUEUE 10

// PRIORITY QUEUE by using an Array

struct priority_queue{
    int A[MAX_QUEUE];
    int cnt;
};

typedef struct priority_queue pqueue;

void initialize(pqueue *p){
    p->cnt = 0;
}

void swap(int *a, int *b){
    int temp = *a;

    *a = *b;
    *b = temp;
}

void insert(pqueue *p, int x){
    if (p->cnt == MAX_QUEUE)
        printf("Queue is full");
    else {
        p->cnt++;
        p->A[p->cnt] = x;

        int iter = p->cnt;
        while(iter != 1 && p->A[iter] < p->A[iter/2])
        {
            swap(&p->A[iter], &p->A[iter/2]);
            iter /= 2;
        }
    }
}

void print(pqueue *p){
    if (p->cnt == 0)
        printf("Queue is empty.");
    else {
        printf("\n");

        for (int i = 1; i <= p->cnt; i++)
            printf("%4d", p->A[i]);

        printf("\n");
    }
}

int delete(pqueue *p){
    if (p->cnt == 0)
        printf("Queue is empty.");
    else {
        int temp = p->A[1];

        p->A[1] = p->A[p->cnt];

        p->cnt--;

        int iter = 1;
        while (iter*2 <= p->cnt && (p->A[iter] > p->A[iter*2] || p->A[iter] > p->A[iter*2+1])){

            if (p->A[iter*2] < p->A[iter*2+1])
            {
                swap(&p->A[iter*2], &p->A[iter]);
                iter = iter*2;
            } else {
                swap(&p->A[iter*2+1], &p->A[iter]);
                iter = iter*2+1;
            }

        }

        return temp;
    }
}

int main(){

    pqueue p;

    initialize(&p);

    insert(&p, 1);
    insert(&p, 2);
    insert(&p, 3);
    insert(&p, 4);
    insert(&p, 5);
    insert(&p, 6);
    insert(&p, 7);
    insert(&p, 8);
    insert(&p, 9);

    print(&p);

    printf("\nDeleted Key: %d", delete(&p));

    print(&p);

    return 0;
}