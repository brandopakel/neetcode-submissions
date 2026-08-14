class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        # initalize empty list
        s_list = []
        # first pointer
        #i = 0
        # second pointer
        for c in s:
            if c.isalnum():
                s_list.append(c)
        s = "".join(s_list)
        i = len(s) - 1
        for c in s:
            if c != s[i]:
                return False
            i -= 1
        return True