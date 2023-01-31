// Goal: Return the index of all the occurrences of an item in an array

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool myCompare(pair<int,int>p1, pair<int,int>p2){
    return p1.first < p2.first;
}

vector<int> linear_search(vector <pair<int,int>> v, int n, int item){
    vector<int> index;
    for(int i=0; i<n; i++){
        if(v[i].first == item){
            index.push_back(v[i].second);
        }
    }
    return index;
}

vector<int> binary_search(vector<pair<int,int>> v, int n, int item){
    vector<int> index;
    int low = 0, high = n-1, mid;
    while(low <= high){
        mid = (low + high)/2;
        if(v[mid].first == item){
            int mid_forward = mid;
            int mid_backward = mid - 1;
            while(v[mid_forward].first == item){
                index.push_back(v[mid_forward].second);
                mid_forward++;
            }
            while(v[mid_backward].first == item){
                index.push_back(v[mid_backward].second);
                mid_backward--;
            }
            return index;
        }
        else if(v[mid].first > item){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return index;
}

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout << "Enter the item to be searched: ";
    int item;
    cin>>item;
    cout << endl;

    vector <pair<int,int>> v;
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
        v.push_back(make_pair(arr[i], i));
    }

    sort(v.begin(), v.end(), myCompare);

    vector<int> index_through_linear_search = linear_search(v, sizeof(arr)/sizeof(arr[0]), item);
    
    cout << "Index through linear search: ";
    if(index_through_linear_search.size() == 0){
        cout << "Item not found" << endl;
    }
    else{
        for(int i=0; i<index_through_linear_search.size(); i++){
            cout << index_through_linear_search[i] << " ";
        }
        cout << endl;
    }

    vector<int> index_through_binary_search = binary_search(v, sizeof(arr)/sizeof(arr[0]), item);
    
    cout << "Index through binary search: ";
    if(index_through_binary_search.size() == 0){
        cout << "Item not found" << endl;
        return 0;
    }
    else{
        sort(index_through_binary_search.begin(),index_through_binary_search.end());
        for(int i=0; i<index_through_binary_search.size(); i++){
            cout << index_through_binary_search[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
