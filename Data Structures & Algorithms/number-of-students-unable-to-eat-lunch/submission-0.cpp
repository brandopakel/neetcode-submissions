#include <queue>

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        std::queue<int> line;
        std::size_t sandwichIndex = 0;
        std::size_t rejected = 0;
        
        for(int preference : students){
            line.push(preference);
        }

        while(!line.empty() && rejected < line.size()){
            int preference = line.front();

            if(preference == sandwiches[sandwichIndex]){
                line.pop();
                ++sandwichIndex;
                rejected = 0;
            } else{
                line.pop();
                line.push(preference);
                ++rejected;
            }
        }

        return static_cast<int>(line.size());
    }
};