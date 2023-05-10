# Given a positive integer n, generate an n x n matrix filled with elements 
# from 1 to n2 in spiral order.


# Example 1:
# Input: n = 3
# Output: [[1,2,3],[8,9,4],[7,6,5]]

# Example 2:
# Input: n = 1
# Output: [[1]]


# Constraints:
# 1 <= n <= 20

# Accepted 05/09/2023 - 42ms beats 18.40% - 16.3MB beats 5.62%

from typing import List

class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        spiral = []
        for i in range(n):
            spiral.append([])
            for j in range(n):
                spiral[i].append(0)

        maxI, maxJ = n - 1, n - 1
        i , j, minI, minJ = 0, 0, 0, 0

        spiral[0][0] = 1
        num = 2

        while (True):
            if (num > n**2):
                break
            while (j < maxJ):
                j += 1
                spiral[i][j] = num
                num += 1
            minI += 1
            
            if (num > n**2):
                break
            while (i < maxI):
                i += 1
                spiral[i][j] = num
                num += 1
            maxJ -= 1
            
            if (num > n**2):
                break
            while (j > minJ):
                j -= 1
                spiral[i][j] = num
                num += 1
            maxI -= 1

            if (num > n**2):
                break
            while (i > minI):
                i -= 1
                spiral[i][j] = num
                num += 1
            minJ += 1

        return spiral