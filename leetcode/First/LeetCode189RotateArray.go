func rotate(nums []int, k int) {
	k = k % len(nums)
	if k == 0 {
		return
	}
	for indexk := 0; indexk < k; indexk++ {
		var nLast int = nums[len(nums)-1]
		for indexn := len(nums) - 2; indexn >= 0; indexn-- {
			nums[indexn+1] = nums[indexn]
		}
		nums[0] = nLast
	}
}
