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
    void quickSortHelper(vector<Pair>& pairs, int s, int e){
        if(e-s+1 <= 1){
            return;
        }

        int pivot = e;
        int left = s;

        for(int i=s; i<e; i++){
            if(pairs[i].key < pairs[pivot].key){
                swap(pairs[i],pairs[left]);
                left++;
            }
        }

        swap(pairs[pivot],pairs[left]);

        quickSortHelper(pairs, s, left-1);
        quickSortHelper(pairs, left+1, e);
    }

    vector<Pair> quickSort(vector<Pair>& pairs) {
        quickSortHelper(pairs, 0, static_cast<int>(pairs.size())-1);
        return pairs;
    }
};
