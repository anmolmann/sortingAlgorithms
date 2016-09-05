#include<iostream>
#include<cstring>
using namespace std;
void swapping(char *a[100], int index, int i) {
    char *temp;
    temp = new char[100];
    strcpy(temp, a[index]);
    strcpy(a[index], a[i]);
    strcpy(a[i], temp);
}
int main() {
    int r, c;
    cin >> r;
    char **a = new char*[r];
    cin >> c;
    for(int i = 0; i < r; i++)
        a[i] = new char[c];
    for(int i = 0; i < r; i++)
        cin >> a[i];

    for(int i = 0; i < r; i++) {
        int index = i;
        for(int j = i + 1; j < r; j++) {
            if(strcmp(a[index], a[j])  > 0)
                index = j;
        }
        if(index != i)
            swapping(a, index, i);
    }

    for(int i = 0; i < r; i++)
        cout << a[i] << endl;
    return 0;
}
