#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
void swap(int *t1, int *t2) {
    int temp = *t1;
    *t1 = *t2;
    *t2 = temp;
}
int choosepivot(long int head, long int tail) {
    long int temp = tail - head + 1;
    long int r = rand() % temp;
    return r + head;
}
void quicksort(int *a, long int head, long int tail) {
    if(head < tail) {
        long int pivot = choosepivot(head, tail), i;
        swap(&a[pivot], &a[head]);   
        pivot = head;
        for(i = head + 1; i <= tail; i++) {
            if(a[head] >= a[i])
                swap(&a[++pivot], &a[i]);
        }
        swap(&a[pivot], &a[head]);
        quicksort(a, head, pivot - 1);
        quicksort(a, pivot + 1, tail);
    }
    else
        return;
}
void main() {
    long int i;
    int a[16000];
    for(i = 0; i < 16000; i++) 
        a[i] = rand() % 200;
    struct timeval start, end;
    gettimeofday(&start, NULL);
    long double start1 = start.tv_sec * 1000000 + start.tv_usec;
    quicksort(a, 0, 15999);
    gettimeofday(&end, NULL);
    long double end1 = end.tv_sec * 1000000 + end.tv_usec;
    long double t1 = end1 - start1;


    int sorted[32000];
    for(i = 0; i < 32000; i++) 
        sorted[i] = i;
    gettimeofday(&start, NULL);
    start1 = start.tv_sec * 1000000 + start.tv_usec;
    quicksort(sorted, 0, 31999);
    gettimeofday(&end, NULL);
    end1 = end.tv_sec * 1000000 + end.tv_usec;
    long double t2 = end1 - start1;
    printf("%Lf, t1 :%Lf", t2/t1, t1);
    printf("\n");  
}
