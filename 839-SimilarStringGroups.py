# Two strings X and Y are similar if we can swap two letters (in different positions) 
# of X, so that it equals Y. Also two strings X and Y are similar if they are equal.

# For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and 
# "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".

# Together, these form two connected groups by similarity: {"tars", "rats", "arts"} 
# and {"star"}.  Notice that "tars" and "arts" are in the same group even though they 
# are not similar.  Formally, each group is such that a word is in the group if and only 
# if it is similar to at least one other word in the group.

# We are given a list strs of strings where every string in strs is an anagram of every 
# other string in strs. How many groups are there?


# Example 1:
# Input: strs = ["tars","rats","arts","star"]
# Output: 2

# Example 2:
# Input: strs = ["omv","ovm"]
# Output: 1
 

# Constraints:
# 1 <= strs.length <= 300
# 1 <= strs[i].length <= 300
# strs[i] consists of lowercase letters only.
# All words in strs have the same length and are anagrams of each other.

# Accepted: 4/28/2023 - 273ms beats 70.49% - 16.6MB beats 10.16%

from typing import List

class Solution:
    def numSimilarGroups(self, strs: List[str]) -> int:
        groups = [[strs[0]]]
        strs = strs[1:]
        i = 0

        while i < strs.__len__() - 1:
            flag = True
            for group in groups:
                for word in group:
                    num_diff = 0

                    for n in range(word.__len__()):
                        if strs[i][n] != word[n]:
                            num_diff += 1
                            if num_diff > 2:
                                break

                    if num_diff == 2 or num_diff == 0:
                        if flag:
                            group.append(strs[i])
                            flag = False
                            break
                        else:
                            strs.extend(group)
                            groups.remove(group)
                            break

            if flag:
                groups.append([strs[i]])
            
            i += 1

        return groups.__len__()