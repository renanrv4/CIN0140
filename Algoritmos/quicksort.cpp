#include <bits/stdc++.h>

using namespace std;

// Versão que eu consegui realizar o quicksort corretamente
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

// Versão corrigida
/*
int partition(vector<int>& vect, int l, int r) {
    int p = vect[l];  // pivô
    int i = l + 1;
    int j = r;
    while(i <= j) {
        while(i <= r && vect[i] <= p) i++;
        while(j >= l && vect[j] > p) j--;
        if(i < j) {
            swap(vect[i], vect[j]);
        }
    }
    swap(vect[l], vect[j]);
    return j;
}
*/

void quick_sort(vector<int>& vect, int l, int r) {
    if(l < r) {
        int split_pos = partition(vect, l, r);
        quick_sort(vect, l, split_pos-1);
        quick_sort(vect, split_pos+1, r);
    }
}

int main() {
    vector<int> arr = {5, 3, 1, 9, 8, 2, 4, 7};
    quick_sort(arr, 0, arr.size()-1);
    for(int num : arr) {
        cout << num << " ";
    }
    cout << "\n";
    return 0;
}