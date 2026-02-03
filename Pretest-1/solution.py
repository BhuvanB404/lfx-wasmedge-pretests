"""
WasmEdge LFX Mentorship Pre-test 1
Author: BhuvanB
Date: 02/03/2026

Problem: Computation and comparision of threshold against given list of numbers and updating threshold dynamically.
 
Explanation:
number list are : [1, 3, 4, 2, 4, 7] and intital threshold is 3.
Loops 1: 1 < 3, skip
Loops 2: 3 = 3, no change, threshold=3, result += 0, result= 0 
Loops 3: 4 >  3, threshold=4, result += 2 *4 = 8, result= 8
Loops 4: 2 < 4, skip  
Loops 5: 4 = 4, skip threshold=4, result = 8,
Loops 6: 7 > 4, threshold=7, result += 2 * 7 += 14, result=22

List ends and we end up with result of 22.

Answer:22
"""

def collectNums(lists, threshold):
    result = 0
    for x in lists:
        if x > threshold:
            threshold = x
            result += 2 *x
    return result

print(collectNums([1, 3, 4, 2, 4, 7], 3)) # Output is 22
