func replaceElements(arr []int) []int {
    var n int = len(arr)
    var ans []int = make([]int, n)
    var rightMax int = -1
    for i:=len(arr) - 1; i >= 0 ; i--{
        ans[i] = rightMax
        rightMax = max(arr[i], rightMax)
    }
    return ans
}
