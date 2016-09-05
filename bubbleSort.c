#include<stdio.h>
#include<sys/time.h>
void bubble_sort(long long int arr[],long long int SIZE)
{
    long long int i, j;
    for(i = 0; i < SIZE - 1; i++){
        for(j = 0; j < SIZE - 1 - i; j++){
            if(arr[j] < arr[j + 1]){
	        int temp = arr[j];
	        arr[j] = arr[j + 1];
	        arr[j + 1] = temp;
            }
        }
    }
}
void main()
{
	long long int arr1[8000];
	long long int i, j = 0;
	for(i = 0; i < 8000; i++){
	    arr1[i] = j;
	    j++;
	}
	long long int arr2[16000];
	j = 0;
	for(i = 0; i < 16000; i++){
	    arr2[i] = j;
	    j++;
	}
	struct timeval start, end;

	gettimeofday(&start,NULL);
	long double start1 = start.tv_sec*1000000 + start.tv_usec;
	bubble_sort(arr1,8000);
	gettimeofday(&end,NULL);
	long double end1 = end.tv_sec*1000000 + end.tv_usec;
	long double t1 = end1 - start1;
	
	gettimeofday(&start,NULL);
	start1= start.tv_sec*1000000 + start.tv_usec;
	bubble_sort(arr2,16000);
	gettimeofday(&end,NULL);
	end1 = end.tv_sec*1000000 + end.tv_usec;	

	long double t2 = end1 - start1;

	printf("%Lf %Lf\n", t2/t1, t1);

}
