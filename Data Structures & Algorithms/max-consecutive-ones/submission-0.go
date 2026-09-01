func findMaxConsecutiveOnes(nums []int) int {
	var resp, current int = 0, 0
    for i := 0; i < len(nums) ; i++{
        if nums[i] == 1{
            current++
            resp = max(resp, current)
        } else {
            current = 0
            resp = max(resp, current)
        }
    }

    return resp
}
