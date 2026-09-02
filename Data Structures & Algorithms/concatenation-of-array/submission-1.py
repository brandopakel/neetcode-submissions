class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        n = len(nums)
        self.ans = [0] * (2*n)
        for i,num in enumerate(nums):
            self.ans[i] = self.ans[i+n] = num
        return self.ans