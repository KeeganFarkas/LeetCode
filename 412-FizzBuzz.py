# Given an integer n, return a string array answer (1-indexed) where:

# answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
# answer[i] == "Fizz" if i is divisible by 3.
# answer[i] == "Buzz" if i is divisible by 5.
# answer[i] == i (as a string) if none of the above conditions are true.


# Example 1:
# Input: n = 3
# Output: ["1","2","Fizz"]

# Example 2:
# Input: n = 5
# Output: ["1","2","Fizz","4","Buzz"]

# Example 3:
# Input: n = 15
# Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz",
#          "13","14","FizzBuzz"]


# Constraints:
# 1 <= n <= 10^4

# Accepted: 12/16/2022 - 37ms beats 91.91% - 15MB beats 73.45%

from typing import List

class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        def convert(n: int) -> str:
            if n % 3 == 0 and n % 5 == 0:
                return "FizzBuzz"
            elif n % 3 == 0:
                return "Fizz"
            elif n % 5 == 0:
                return "Buzz"
            else:
                return str(n)

        return [convert(num) for num in range(1, n + 1)]
