#include <iostream>
#include <vector>

#include "sorts.h"
#include "printer.h"

using namespace std;

void shellSort(vector<int>& v) {
    int n = v.size();
    for (int interval = n / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < n; i++) {
            int temp = v[i];
            int j;
            for (j = i; j >= interval && (v[j - interval] > temp); j -= interval)
                v[j] = v[j - interval];
            v[j] = temp;
        }
    }
}



void makeHeap(vector<int>& tree, int n, int root_ind) {
    int min_ind = root_ind;

    int l = root_ind * 2 + 1;
    int r = root_ind * 2 + 2;

    if ((l < n) && (tree[l] > tree[min_ind]))
        min_ind = l;
    if ((r < n) && (tree[r] > tree[min_ind]))
        min_ind = r;

    if (min_ind != root_ind) {
        swap(tree[min_ind], tree[root_ind]);
        makeHeap(tree, n, min_ind);
    }
}

void heapSort(vector<int>& v) {
    int n = v.size();

    for (int i = n / 2; i >= 0; i--)
        makeHeap(v, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(v[i], v[0]);
        makeHeap(v, i, 0);
    }
}