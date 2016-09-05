#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
bool isfloat(char **a) {
    for(int i = 0 ; a[0][i] != '\0'; i++) {
        if((!isdigit(a[0][i])) and (a[0][i] != '.'))
            return false;
    }
    return true;
}
void swapping(char **a, int index, int i) {
    char *temp;
    temp = new char[100];
    strcpy(temp, a[index]);
    strcpy(a[index], a[i]);
    strcpy(a[i], temp);
}
int floatcmp(const char *s, const char *s1) {
    float t1 = atof(s);
    float t2 = atof(s1);
    if(t1 > t2)
        return 1;
    else
        return 0;
}
void selection_sort(char **a, int r, int (*compare)(const char *, const char *)) {
    for(int i = 0; i < r; i++) {
        int index = i;
        for(int j = i + 1; j < r; j++) {
            if((*compare)(a[index], a[j]) > 0)
                index = j;
        }
        if(index != i)
            swapping(a, index, i);
    }
}
int main() {
    int r;
    cin >> r;
    char **a = new char*[r];
    for(int i = 0; i < r; i++)
        a[i] = new char[100];

    for(int i = 0; i < r; i++)
        cin >> a[i];

    int (*compare)(const char *, const char *);

    if(isfloat(a))
        selection_sort(a, r, compare = &floatcmp);
    else
        selection_sort(a, r, compare = &strcmp);
    for(int i = 0; i < r; i++)
        cout << a[i] << endl;
    return 0;
}
