#include <iostream>
#include <vector>

using namespace std;

// Implementando uma heap máxima para sempre pegar os maiores valores na heap e realizar 
// a troca/remoção de elementos de forma otimizada com o heapify

class Heap {
    private:
        vector<int> heap;
        
        void heapify(int i) {
            int n = heap.size() -1;
            int k = i; int v = heap[k];
            bool isHeap = false;
            while(!isHeap && 2 * k <= n) {
                int j = 2 * k;  
                if(j < n) {
                    if(heap[j] < heap[j+1]) {
                        j++;
                    }
                }
                if(v >= heap[j]) {
                    isHeap = true;
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
        Heap(const vector<int>& list_nums) {
            heap.push_back(0);
            for(int num : list_nums) {
                heap.push_back(num);
            }
            heap_bottom_up();
        }

        void push(int elem) {
            heap.push_back(elem);
            int n = heap.size() -1;
            while(n > 1 && heap[n/2] < heap[n]) {
                swap(heap[n], heap[n/2]);
                n = n/2;
            }
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
};

int main() {
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        int n; cin >> n;
        vector<int> list_ints(n, 0);
        for(int j = 0; j < n; j++) {
            cin >> list_ints[j];
        }

        Heap heap(list_ints);
        while(heap.size_heap() > 1) {
            int a = heap.top(); heap.pop();
            int b = heap.top(); heap.pop();
            int x = a + b -1;
            heap.push(x);
        }
        cout << heap.top() << "\n";
    }
    return 0;
}