#include <iostream>
#include <vector>

using namespace std;

// Exercício Prático de Backtracking para descobrir a quantidade de subconjuntos que formam uma soma "n"

int qtd = 0;

void subset_sum(vector<int>& nums, int j, int sum, int k) {
    if(sum == k) {
        qtd++;
    }
    for(int i = j; i < nums.size(); i++) {
        sum += nums[i];
        subset_sum(nums, i+1, sum, k);
        sum -= nums[i];
    }
}

int main() {
    int n, k; cin >> n >> k;
    vector<int> nums(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    subset_sum(nums, 0, 0, k);
    cout << qtd << "\n";
    return 0;
}