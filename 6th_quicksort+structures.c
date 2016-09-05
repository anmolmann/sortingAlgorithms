#include<stdio.h>
#include<string.h>
struct temp {
    char name[10];
    int age;
    float sal;
};
void swap(struct temp *t1, struct temp *t2) {
    struct temp t3 = *t1;
    *t1 = *t2;
    *t2 = t3;
}
void quicksort(struct temp *arr, int head, int tail) {
    if(head < tail) {
        int pivot = head, i;
        for(i = head + 1; i <= tail; i++) {
            if(arr[head].age > arr[i].age)
                swap(&arr[++pivot], &arr[i]);
            else if((arr[head].age == arr[i].age) && (arr[head].sal > arr[i].sal))
                    swap(&arr[head], &arr[i]);
                 else if((arr[head].sal == arr[i].sal) && (strcmp(arr[head].name, arr[i].name) > 0))
                    swap(&arr[head], &arr[i]);
        }
        swap(&arr[head], &arr[pivot]);
        quicksort(arr, head, pivot);
        quicksort(arr, pivot + 1, tail);
    }
    else
        return;
}
void main() {
    int i, SIZE;
    printf("\nEnter SIZE:\t");
    scanf("%d", &SIZE);
    printf("\nEnter respective name, age and salary of the person ->\n");
    struct temp arr[SIZE];
    for(i = 0; i < SIZE; i++) {
        scanf("%s %d %f", arr[i].name, &arr[i].age, &arr[i].sal);
    }
    //int (* compare)(const void *, const void *);
    quicksort(arr, 0, SIZE - 1);
    printf("\n------------------------------\n------------RESULT------------\n------------------------------\n");
    for(i = 0; i < SIZE; i++) {
        printf("%12s %6d %10.2f\n", arr[i].name, arr[i].age, arr[i].sal);
    }
}
