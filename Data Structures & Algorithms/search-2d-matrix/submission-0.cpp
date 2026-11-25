class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // 1) Find the row that could hold the target
        int top = 0, bottom = rows - 1;
        int row = -1; // -1 means no row can hold it
        while(top <= bottom){
            int mid = top + (bottom - top) / 2;
            if(target < matrix[mid][0]){
                // target is above this row: move one bound
                bottom = mid - 1;
            } else if(target > matrix[mid][cols-1]){
                // target is below this row: move the other bound
                top = mid + 1;
            } else{
                row = mid;
                break;
            }
        }

        if (row == -1) return false;

        // 2) search inside matrix[row]
        int left = 0, right = cols - 1;
        while(left <= right){
            int mid = left + (right-left) / 2;
            if(target < matrix[row][mid]){
                right = mid - 1;
            } else if(target > matrix[row][mid]){
                left = mid + 1;
            } else{
                return true;
            }
        }
        return false;
    }
};
