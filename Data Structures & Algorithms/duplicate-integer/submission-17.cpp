#include <unordered_set>
#include <vector>

class Solution {
public:
    bool hasDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> unique_set;
        for (int num: nums){
            if (unique_set.find(num) != unique_set.end()){
                return true;
            }
            unique_set.insert(num);
        }
        return false;
    }
};