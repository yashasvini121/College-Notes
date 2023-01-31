#include<iostream>
#include<set>
using namespace std;

int* sort_array(int arr[], int n){
    int temp;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i] < arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}

int binary_search(int arr[], int n, int item){
    int item_count = 0;
    int low = 0, high = n-1, mid;
    while(low <= high){
        mid = (low + high)/2;
        if(arr[mid] == item){
            int mid_forward = mid;
            int mid_backward = mid - 1;
            while(arr[mid_forward] == item){
                item_count++;
                mid_forward++;
            }
            while(arr[mid_backward] == item){
                item_count++;
                mid_backward--;
            }

            return item_count;
        }
        else if(arr[mid] > item){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return item_count;
}

int linear_search(int arr[], int n, int item){
    int item_count = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == item){
            item_count++;
        }
    }
    return item_count;
}

int main(){
    int n=10,
        arr[n] = {1, 2, 8, 4, 5, 6, 8, 8, 8, 10},
        *sorted_array = sort_array(arr, n),
        item = 8,
        item_count = binary_search(sorted_array, n, item);

    cout << "Ans using binary search:" << item_count << endl
         << "Ans using linear search:" << linear_search(arr, n, item) << endl;
    return 0;
}
