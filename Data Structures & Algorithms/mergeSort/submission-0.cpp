#include <vector>

// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<Pair> mergeSort(vector<Pair>& pairs) {
        sortRange(pairs, 0, static_cast<int>(pairs.size())-1);
        return pairs;
    }

    void sortRange(vector<Pair>& pairs, int s, int e){
        if(e-s+1<=1){
            return;
        }
        int m = (s+e)/2;
        sortRange(pairs, s, m);
        sortRange(pairs,m+1,e);
        merge(pairs, s, m, e);
    }

    void merge(vector<Pair>& arr, int s, int m, int e) {
    // Copy the sorted left & right halfs to temp arrays
    vector<Pair> L = {arr.begin() + s, arr.begin() + m + 1};
    vector<Pair> R = {arr.begin() + m + 1, arr.begin() + e + 1}; 

    int i = 0; // index for L
    int j = 0; // index for R
    int k = s; // index for arr

    while (i < L.size() && j < R.size()) {
        if (L[i].key <= R[j].key) {
            arr[k] = L[i++];
        } else {
            arr[k] = R[j++];
        }
        k++;
    }

    // One of the halfs will have elements remaining
    while (i < L.size()) {
        arr[k++] = L[i++];
    }
    while (j < R.size()) {
        arr[k++] = R[j++];
    }
}
};
