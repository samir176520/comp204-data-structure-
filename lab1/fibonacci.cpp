// docter made factorail example

// program to output fibonacce sum for number
//Fab(0) = 0, Fab(1) = 1, Fab(n) = Fab(n - 1) * Fab(n - 2) V n >= 2;
#include <iostream>

using namespace std;

int fab(int num)
{
if (num == 1)
    return 1;
else if (num == 0)
    return 0;
else 
    return fab(num - 1) + fab(num - 2);
}


int main()
{
    int num;
    cin >> num;
    cout << fab(num);
    return 0;
}