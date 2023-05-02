# There is a function signFunc(x) that returns:

# 1 if x is positive.
# -1 if x is negative.
# 0 if x is equal to 0.
# You are given an integer array nums. Let product be the product of all 
# values in the array nums.

# Return signFunc(product).


# Example 1:
# Input: nums = [-1,-2,-3,-4,3,2,1]
# Output: 1
# Explanation: The product of all values in the array is 144, and 
# signFunc(144) = 1

# Example 2:
# Input: nums = [1,5,0,2,-3]
# Output: 0
# Explanation: The product of all values in the array is 0, and signFunc(0) = 0

# Example 3:
# Input: nums = [-1,1,-1,1,-1]
# Output: -1
# Explanation: The product of all values in the array is -1, and 
# signFunc(-1) = -1
 

# Constraints:
# 1 <= nums.length <= 1000
# -100 <= nums[i] <= 100

# Accepted: 05/01/2022 - 74ms beats 6.38% - 16.4MB beats 7.53%
# I think that this one was so simple it didn't matter how you did it, the 
# runtime/memory was going to be the same. I can copy code that is said to be
# faster, but it is the same as mine when I run it.

from typing import List

class Solution:
    def arraySign(self, nums: List[int]) -> int:
        numNegatives = 1

        for num in nums:
            if num < 0:
                numNegatives *= -1
            elif num == 0:
                return 0
        
        return numNegatives