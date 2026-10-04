class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        ans = [0] * len(temperatures) # solves default 0 at the end of the list
        stack = []

        for i, t in enumerate(temperatures):
            # today is warmer than the waiting day(s) on top of the stack
            while stack and t > temperatures[stack[-1]]:
                j = stack.pop()
                ans[j] = i - j
            stack.append(i)
        return ans