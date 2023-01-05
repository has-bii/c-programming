#include <stdio.h>
#define MAX_QUEUE 10

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
        for (int i = 1; i < MAX_QUEUE; i++)
            printf("%4d", p->A[i]);
    }
}

int delete(pqueue *p){
    if (p->cnt == 0)
        printf("Queue is empty.");
    else {
        int temp = p->A[1];

        p->A[1] = p->A[p->cnt];

        int iter = 1;
        while (iter*2 <= p->cnt && (p->A[iter] > p->A[iter*2] || p->A[iter] > p->A[iter*2+1])){

            if (p->A[iter*2] < p->A[iter*2+1])
            {
                swap(&p->A[iter*2], p->A[iter]);
                iter = iter*2;
            } else {
                swap(&p->A[iter*2+1], p->A[iter]);
                iter = iter*2+1;
            }

        }

        return temp;
    }
}