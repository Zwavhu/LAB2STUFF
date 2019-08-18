 //size_capacity.cpp
 //Vector size versus capacity

#include <vector>
#include <iostream>

using namespace std;

//ANSWER TO QUESTION 2.1:
//Size is the number of elements that a vector currently holds
//Capacity is the number of elements a vector can hold at a maximum
 
int main()
{
    vector<int> vec;
    cout << "vec: size: " << vec.size() 
         << " capacity: " << vec.capacity() << endl;

    for(int i = 0; i < 24; i++) {
        vec.push_back(i);
        cout << "vec: size: " << vec.size() 
             << " capacity: " << vec.capacity() << endl;
    }

    return 0;
}
