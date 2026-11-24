class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int best = high;

        while(low<=high){
            int k = low + (high-low) / 2;
            if(hoursNeeded(piles, k) <= h){
                best = k;
                high = k-1;
            } else{
                low = k+1;
            }
        }

        return best;
    }

private:
    long long hoursNeeded(const vector<int>& piles, int k){
        long long total = 0;
        for(int p: piles){
            total += (p+k-1)/k;
        }
        return total;
    }
};
