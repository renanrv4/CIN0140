#include <iostream>
#include <vector>

using namespace std;

// Exercício Pŕatico sobre Heap

class MinHeap {
    private:
        vector<int> heap;

        void heapify(int i) {
            int n = heap.size()-1;
            int k = i;
            int v = heap[k];
            bool isheap = false;
            while(!isheap && k * 2 <= n) {
                int j = k * 2;
                if(j < n) {
                    if(heap[j] > heap[j+1]) {
                        j++;
                    }
                }
                if(v <= heap[j]) {
                    isheap = true;
                } else {
                    heap[k] = heap[j];
                    k = j;
                }
            }
            heap[k] = v;
        }

        void heap_bottom_up() {
            int n = heap.size() -1;
            for(int i = n/2; i >= 1; i--) {
                heapify(i);
            }
        }

    public:
        MinHeap(vector<int>& vect) {
            heap.push_back(0);
            for(int num : vect) {
                heap.push_back(num);
            }
            heap_bottom_up();
        }

        void pop() {
            int n = heap.size() - 1;
            if (n == 0) { return; }
            heap[1] = heap[n];
            heap.pop_back();
            heapify(1);
        }

        int size_heap() { return heap.size() -1; }
        int top() { return heap[1]; }

        int unqminval() {
            while (size_heap() > 0) {
                int curr = heap[1];
                int count = 0;
                while (size_heap() > 0 && heap[1] == curr) {
                    pop();
                    count++;
                }
                if (count == 1) {
                    return curr;
                }
            }
            return -1;
        }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> numbers(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    MinHeap mhp(numbers);
    int minv = mhp.unqminval();
    cout << minv << "\n";
    return 0;
}