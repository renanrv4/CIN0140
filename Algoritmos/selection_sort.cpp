#include <bits/stdc++.h>

using namespace std;

// Busca o menor elemento do array e insere o valor no começo do array não ordenado
void selection_sort(vector<int> v) {
    for(int i = 0; i < v.size()-1; i++) {
        int min = i;
        for(int j = i+1; j < v.size(); j++) {
            if(v[j] < v[min]) {
                min = j;
            }
        }
        swap(v[i], v[min]);
    }
    for(int num : v) {
        cout << num << " ";
    }
    cout << "\n";
}

int main() {
    vector<int> arr = {89, 45, 68, 90, 29, 34, 17};
    selection_sort(arr);
    return 0;
}