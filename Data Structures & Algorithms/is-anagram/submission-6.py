class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t) : return False
        dict1 = {}
        dict2 = {}
        for x in s:
            dict1[x] = dict1.get(x, 0) + 1
        for y in t:
            dict2[y] = dict2.get(y, 0) + 1
        if dict1 == dict2:
            return True
        return False