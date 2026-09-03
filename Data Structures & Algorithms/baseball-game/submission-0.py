class Solution:
    def calPoints(self, operations: List[str]) -> int:
        stack = []
        res = 0
        for opp in operations:
            match opp:
                case "+":
                    sum_of_two = stack[-1] + stack[-2]
                    stack.append(sum_of_two)
                    res = res + sum_of_two
                case "D":
                    new_score = stack[-1] * 2
                    stack.append(new_score)
                    res = res + new_score
                case "C":
                    popped = stack.pop()
                    res = res - popped
                case _:
                    stack.append(int(opp))
                    res += int(opp)
        return res
