#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int partition(vector<int>& vect, int l, int r) {
    int p = vect[l];
    int i = l-1;
    int j = r+1;
    while(true) {
        do {
            i++;
        } while(i <= p && vect[i] <= p);
        do {
            j--;
        } while(vect[j] > p);
        if(i >= j) {
            break;
        }
        swap(vect[i], vect[j]);
    }
    swap(vect[l], vect[j]);
    return j;
}

void quick_sort(vector<int>& vect, int l, int r) {
    if(l < r) {
        int split_pos = partition(vect, l, r);
        quick_sort(vect, l, split_pos-1);
        quick_sort(vect, split_pos+1, r); 
    }
}

int main() {
    int n, k; cin >> n >> k;
    int pairs = 0;
    vector<int> arr(n), comp(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    quick_sort(arr, 0, n-1);
    for(int num = 0; num < n; num++) {
        int l = 0;
        int r = arr.size()-1;
        while(l <= r) {
            int mid_arr = floor((l + r)/2);
            if(arr[mid_arr] == arr[num] + k) {
                pairs++;
                break;
            } else if(arr[mid_arr] < arr[num] + k) {
                l = mid_arr + 1;
            } else {
                r = mid_arr - 1;
            }
        }
    }
    cout << pairs << "\n";
    return 0;
}