#include <unordered_set>
#include <vector>

class Solution {
public:
    bool hasDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> unique_set(nums.begin(), nums.end());
        if (unique_set.size() < nums.size()) {
            return true;
        } else {
            return false;
        }
    }
};