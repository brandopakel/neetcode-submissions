func calPoints(operations []string) int {
    res := 0
    var stack []int
    for _, o := range operations{
        switch o{
        case "+":
            newScore := stack[len(stack)-1] + stack[len(stack)-2]
            stack = append(stack, newScore)
            res = res + newScore
        case "D":
            newScore := stack[len(stack)-1] * 2
            stack = append(stack, newScore)
            res = res + newScore
        case "C":
            oldScore := stack[len(stack)-1]
            stack = stack[:len(stack)-1]
            res = res - oldScore
        default:
            v, _ := strconv.Atoi(o)
            stack = append(stack, v)
            res = res + v
        }
    }

    return res
}
