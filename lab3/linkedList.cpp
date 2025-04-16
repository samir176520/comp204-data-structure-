#include <iostream>

using namespace std;

class list
{
    int * listptr, last, capacity;
public:

    list()
    {
        listptr = new int[100];
        last = -1;
        capacity = 100;
    }

    list(int num)
    {
        listptr = new int[num];
        last = -1;
        capacity = num;
    }

    void insert(int num, int pos) // I insert after specific pos position
    {
        if (last == -1 && pos == last ) // handle first insert
        {
            listptr[0] = num;
            last++;
        }
        else if (pos > last || pos < -1) 
            cout << "Out of boundries\n";

        else if (last + 1 == capacity) 
            cout << "List is Full";

        else
        {
            for(int i = last; i >= pos;i--)
            listptr[i + 1] = listptr[i];

            last++;
            listptr[pos] = num;
        }
        
    }

    void remove(int pos)
    {
        if (pos > last || pos < 0) 
            cout << "Out of range\n"; 

        else
        {
            for(int i = pos; i <= last ;i++) 
                listptr[i] = listptr[i + 1];
            last--;
        }
    }
    void display()
    {
        for (int i = 0; i <= last;i++)
            cout << listptr[i] << "\t";
        cout << endl;
    }

    int first()
    {
        return 0;
    }

    int END()
    {
        return last;
    }

    int size()
    {
        return last + 1;
    }

};

int main()
{
    int size = 5, temp;
    cout << "Enter list size: ";
    cin >> size;

    list obj(size);

    obj.insert(5, obj.END()); // to handle first insertion 
    obj.display();
    obj.insert(3, 0);
    obj.display();
    obj.insert(4, 1);
    obj.display();
    obj.insert(7, 2);
    obj.display();
    obj.insert(6, 3);
    obj.display();
 
    obj.remove(3);
 
    obj.display();
}