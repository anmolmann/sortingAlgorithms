// mergesort
#include<stdio.h>
#include<stdlib.h>
int merge(int *, int, int, int, int *);
int mergesort(int *a, int head, int tail, int *aux) {
    int inv = 0;
    if(tail <= head)
        return inv;
    int mid = (head + tail) / 2;
    inv += mergesort(a, head, mid, aux);
    inv += mergesort(a, mid + 1, tail, aux);
    inv += merge(a, head, mid, tail, aux);
    return inv;
}
int merge(int *a, int head, int mid, int tail, int *aux) {
        int i = head, j = mid + 1, z, inv = 0;
        for(z = head; z < tail + 1; z++) {
	       if(i > mid) 
		      aux[z] = a[j++];
	        else { 
	            if(j > tail)
		           aux[z] = a[i++];
                  else {
		           if(a[i] > a[j]) {
		               aux[z] = a[j++];
			         inv += mid + 1 - i;
		           }
	                else 
		               aux[z] = a[i++];
		   }
	    }
     }
	for(z = head; z < tail + 1; z++)
	    a[z] = aux[z]; 
	return inv;
}
void main() {
    int n, i;
    printf("\nEnter SIZE : \t");
    scanf("%d", &n);
    int a[n];
    int *aux = (int *)calloc(1000, sizeof(int));
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("%d\n", mergesort(a, 0, n - 1, aux));
    for(i = 0; i < n; i++)
        printf("%d ", aux[i]);
    printf("\n");
}
