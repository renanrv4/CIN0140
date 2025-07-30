#include <bits/stdc++.h>

using namespace std;

void all_subsets(vector<bool>& set, int p) {
    cout << "{ ";
    for(int i = 0; i < set.size(); i++) {
        if(i == set.size()-1) {
            cout << set[i] << " }\n";
        } else {
            cout << set[i] << ", ";
        }
    }
    for(int j = p; j < set.size(); j++) {
        set[j] = true;
        all_subsets(set, j+1);
        set[j] = false;
    }
}

int main() {
    int n; cin >> n;
    vector<bool> set(n, false);
    all_subsets(set, 0);
    return 0;
}

/*
#include <bits/stdc++.h>

using namespace std;

bool exist = false;

void exist_subset(vector<int>& numbers, int j, int k, int& sum) {
    if(sum != k) {
        for(int i = j; i < numbers.size(); i++) {
            sum += numbers[i];
            exist_subset(numbers, i+1, k, sum);
            sum -= numbers[i];
        }
    } else {
        exist = true;
    }
}

int main() {
    int n, k; cin >> n >> k;
    vector<int> numbers(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    int sum = 0;
    exist_subset(numbers, 0, k, sum);
    if(exist) {
        cout << "EXISTE" << "\n";
    } else {
        cout << "N EXISTE" << "\n";
    }
    return 0;
}
*/