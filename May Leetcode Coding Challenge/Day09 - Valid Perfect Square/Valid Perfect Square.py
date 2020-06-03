'''

Problem Statement:
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Examples:

Input: num = 16
Output: true

Input: num = 14
Output: false

'''
# Solution using binary search
class Solution(object):
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        
        left = 1
        right = num

        while left <= right:
            mid = left + (right - left) // 2
            square = mid * mid
            if square < num:
                left = mid + 1
            elif square > num:
                right = mid - 1
            else:
                return True

        return False
        