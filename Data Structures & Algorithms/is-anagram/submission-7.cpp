#include <unordered_map>

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }

        std::unordered_map<char,int> counts;

        for(std::size_t i = 0; i < s.size(); ++i){
            counts[s[i]]++;
        }
        for(std::size_t i = 0; i < t.size(); ++i){
            counts[t[i]]--;

            if(counts[t[i]] < 0){
                return false;
            }
        }

        return true;
    }
};
