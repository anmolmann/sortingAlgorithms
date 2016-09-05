#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void swap(char *a[], int index, int i) {
    char *temp;
    temp = (char *)malloc(1000 * sizeof(char));
    strcpy(temp, a[index]);
    strcpy(a[index], a[i]);
    strcpy(a[i], temp);
}
int numeric_comp(const char *a, const char *b) {
    int t1, t2;
    sscanf(a, "%d", &t1);
    sscanf(b, "%d", &t2);
    if(t1 >= t2)
        return 1;
    else
        return 0;
}
int choosepivot(int head, int tail) {
    int temp = tail - head + 1;
    int r = rand() % temp;
    return r + head;
}
void quicksort(char *a[], int head, int tail, int (* comp)(const char *, const char *)) {
    if(head < tail) {
        int pivot = choosepivot(head, tail), i;   
        swap(a, pivot, head);   
        pivot = head;
        for(i = head + 1; i <= tail; i++) {
            if((* comp)(a[head], a[i]) > 0)
                swap(a, ++pivot, i);
        }
        swap(a, pivot, head);
        quicksort(a, head, pivot, (*comp));
        quicksort(a, pivot + 1, tail, (*comp));
    }
    else
        return;
}
int main(int argv, char *argc[]) {
    int n, i;
    scanf("%d", &n);
    char *str[10];
    for(i = 0; i < n; i++) 
        str[i] = (char *)malloc(1000 * sizeof(char));
    for(i = 0; i < n; i++) 
        scanf("%s", str[i]);
    int (*comp)(const char *, const char *);

    if(strcmp(argc[1], "-n") == 0)
        quicksort(str, 0, n - 1, comp = &numeric_comp);
    else if(strcmp(argc[1], "-r") == 0) {
            quicksort(str, 0, n - 1, comp = &numeric_comp);
            for(i = n - 1; i >= 0; i--)
                printf("%s\n", str[i]);
            printf("\n");
            exit(0);
         }
         else
            quicksort(str, 0, n - 1, comp = &strcmp);
    for(i = 0; i < n; i++)
         printf("%s\n", str[i]);
    printf("\n");
    return 0;
}
