// Todo:
// 1. Input array 1
// 2. Input array 2
// 3. Array 3 = concatenating array 1 and array 2
// 4. Fxn to divide array into even and odd

#include <iostream>
#include <vector>
using namespace std;
class Array{
    vector <int> arr;
    int size;
    public:
    Array(int size, vector<int> arr){
        this->size = size;
        this->arr = arr;
    }
    void display(){
        for(int i=0; i<size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    Array operator+ (Array a2){
        vector<int> arr3;
        for(int i=0; i<size; i++){
            arr3.push_back(arr[i]);
        }
        for(int i=0; i<a2.size; i++){
            arr3.push_back(a2.arr[i]);
        }
        Array a3(arr3.size(), arr3);
        return a3;
    }

    Array print_even(){
        vector<int> even;
        for(int i=0; i<size; i++){
            if(arr[i]%2 == 0){
                even.push_back(arr[i]);
            }
        }
        Array a4(even.size(), even);
        return a4;
    }

    Array print_odd(){
        vector<int> odd;
        for(int i=0; i<size; i++){
            if(arr[i]%2 != 0){
                odd.push_back(arr[i]);
            }
        }
        Array a5(odd.size(), odd);
        return a5;
    }
};

int main(){
    Array a1(5, {1,2,3,4,5});
    Array a2(5, {6,7,8,9,10});
    Array a3 = a1 + a2;
    a3.display();
    a3.print_even().display();
    a3.print_odd().display();
    return 0;
}