# Given an m x n matrix, return all elements of the matrix in spiral order.


# Example 1:
# Input: matrix = [[1,2,3],
#                  [4,5,6],
#                  [7,8,9]]
# Output: [1,2,3,6,9,8,7,4,5]

# Example 2:
# Input: matrix = [[1,2,3,4],
#                  [5,6,7,8],
#                  [9,10,11,12]]
# Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

# Constraints:
# m == matrix.length
# n == matrix[i].length
# 1 <= m, n <= 10
# -100 <= matrix[i][j] <= 100

# Accepted 05/08/2023 - 47ms beats 9.96% - 16.2MB beats 14.84%

from typing import List

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        spiral = [matrix[0][0]]
        maxI = (len(matrix) - 1)
        maxJ = (len(matrix[0]) - 1)
        i, j, minI, minJ = 0, 0, 0, 0
        size = (len(matrix) * len(matrix[0]))

        while (True):
            if (len(spiral) >= size):
                break
            while (j < maxJ):
                j += 1
                spiral.append(matrix[i][j])
            minI += 1
            
            if (len(spiral) >= size):
                break
            while (i < maxI):
                i += 1
                spiral.append(matrix[i][j])
            maxJ -= 1
            
            if (len(spiral) >= size):
                break
            while (j > minJ):
                j -= 1
                spiral.append(matrix[i][j])
            maxI -= 1

            if (len(spiral) >= size):
                break
            while (i > minI):
                i -= 1
                spiral.append(matrix[i][j])
            minJ += 1

        return spiral