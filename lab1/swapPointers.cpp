// wirte a swap function to swap three numbers a, b, c using it's pointers
// a goes to b
// b goes to c
// c goes to a 

#include <iostream>
using namespace std;

void swap(int &a,int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}


void rotate(int *a, int *b, int *c) // using pointers -refrence-
{
    int temp = *b;
    *b = *a;
    *a = *c;
    *c = temp;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    rotate(&a,&b, &c);

    cout << a << "\t" <<  b << "\t" << c  << endl;
    // system("pause");
    return 0;
}