func removeElement(nums []int, val int) int {
    var k int = 0
    for _, num := range nums{
        if num != val{
            nums[k] = num
            k++
        } else{
            continue
        }
    }

    return k
}
