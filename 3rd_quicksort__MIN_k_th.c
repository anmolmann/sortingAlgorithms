// find the k(th) minimum element using quicksort algo LOGIC
#include<stdio.h>
int min;
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
void quicksort(int *a, int head, int tail, int k) {
    if(head < tail) {
        long int pivot = choosepivot(head, tail), i;
        swap(&a[pivot], &a[head]);   
        pivot = head;
        for(i = head + 1; i <= tail; i++) {
            if(a[head] > a[i])
                swap(&a[++pivot], &a[i]);
        }
        swap(&a[pivot], &a[head]);
        if(k < pivot + 1)
            quicksort(a, head, pivot, k);
        else if(k > pivot + 1)
                 quicksort(a, pivot + 1, tail, k);
             else 
                 min = a[pivot];
    }
    else {
        min = a[head];
        return;
    }
}
void main() {
    int n, i, k;
    printf("\nEnter SIZE:\t");
    scanf("%d", &n);
    int a[n];
    for(i = 0; i < n; i++) 
        scanf("%d", &a[i]);
    printf("\nEnter the index value:\t");
    scanf("%d", &k);
    quicksort(a, 0, n - 1, k);
    printf("\nk(th) minimum element:  %d\n", min);
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
