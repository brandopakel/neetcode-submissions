class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        s_list = [c for c in s if c.isalnum()]
        i = len(s_list) - 1
        for c in s_list:
            if c != s_list[i]:
                return False
            i -= 1
        return True