#include<stdio.h>
void swap(int *t1, int *t2) {
    int temp = *t1;
    *t1 = *t2;
    *t2 = temp;
}
void main() {
    int n, i, j, inv = 0;
    printf("\nEnter SIZE:\t");
    scanf("%d", &n);
    int a[n];
    for(i = 0; i < n; i++)
	scanf("%d", &a[i]);
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(a[i] > a[j])
		inv++;
        }
    }
    printf("INVERSION COUNT (1) : %d\n", inv);
    inv = 0;
    for(i = 0; i < n - 1; i++) {
        for(j = i; j >= 0; j--) {
	    if(a[j] > a[j + 1]) {
	        swap(&a[j], &a[j + 1]);
		inv++;
	    }
        }
    }
    printf("\nINVERSION COUNT : %d\n", inv);
}
