#include <vector>
#include <string>

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
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        std::vector<vector<Pair>> returnList;
        for(int i=0; i<static_cast<int>(pairs.size()); ++i){
            int j=i-1;
            while(j>=0 && pairs[j+1].key < pairs[j].key){
                Pair tmp = pairs[j+1];
                pairs[j+1] = pairs[j];
                pairs[j] = tmp;
                --j;
            }
            returnList.push_back(pairs);
        }
        return returnList;
    }
};
