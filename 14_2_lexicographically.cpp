#include <iostream>
using namespace std;
int main()
{
    string a;
    cin>> a;
    int index;
    int flag = 0;
    string temp;
    int br_string;
    for(int i = a.length() - 1 ; i > 0; i--) {
	if(a[i - 1] > a[i]) {
	    int min = a[i - 1] - a[i];
	    index = i;
          br_string = i;
	    for(int j = i + 1; j < a.length(); j++)
	    {
		if(min > (a[i - 1] - a[j]) and (a[i - 1] - a[j] > 0))
		{
		    min = a[i - 1] - a[j];
		    index = j;
		    flag = 1;
		}
	    }
	    char temporary = a[index];
	    a[index] = a[i - 1];
	    a[i - 1] = temporary;
	    break;
	}
    }
    temp = a.substr(br_string);
    if(flag == 1)
    {
        for(int i = 0; i < temp.length() - 1; i++)
        {
	    for(int j = 0; j < temp.length() - 1 - i; j++)
	    {
	        if(temp[j] < temp[j + 1])
	        {
		    char c_temporary = temp[j];
		    temp[j] = temp[j + 1];
		    temp[j + 1] = c_temporary;
	        }
	    }
        }
    }
    cout<< endl<< a.substr(0, br_string) + temp << endl;
    return 0;
}
