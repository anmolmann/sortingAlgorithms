#include<stdio.h>
void swap(int *t1, int *t2) {
    int temp = *t1;
    *t1 = *t2;
    *t2 = temp;
}
void quicksort(int *a, int head, int tail) {
    if(head < tail) {
        int pivot = head, i;   // worst case complexity = O(n * n)
        for(i = head + 1; i <= tail; i++) {
            if(a[head] > a[i])
                swap(&a[++pivot], &a[i]);
        }
        swap(&a[pivot], &a[head]);
        quicksort(a, head, pivot);
        quicksort(a, pivot + 1, tail);
    }
    else
        return;
}
void main() {
    int n, i;
    printf("\nEnter SIZE:\t");
    scanf("%d", &n);
    int a[n];
    for(i = 0; i < n; i++) 
        scanf("%d", &a[i]);
    quicksort(a, 0, n - 1);
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");  
}
