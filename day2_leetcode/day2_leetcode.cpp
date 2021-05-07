#include <iostream>
#include<vector>
#include <string>
#include <bitset>
#include <map>
#include <deque>
// except  Best Time to Buy and Sell Stock II
using namespace std;
int Binary_search(std::vector<int>& nums, int target) 
    {
        int pivot;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            pivot = left + (right - left) / 2;
            if (nums[pivot] == target)
                return pivot;
            if (target < nums[pivot])
                right = pivot - 1;
            else left = pivot + 1;
        }
        return -1;
    }


    int removeDuplicates(std::vector<int>&nums)
    {
        if (nums.empty()) 
            return 0;
        int i = 0;
        for (int j = 1; j < nums.size(); j++) 
        {
            if (nums[i] != nums[j]) 
            {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }

    void reverseString(std::vector<char>& s)
    {
        char left = 0;
        char right = s.size() - 1;
        char tmp;
        while (left < right)
        {
            tmp = s[left];
            s[left++] = s[right];
            s[right--] = tmp;
        }
    }

    int reverse(int x) {
        int result = 0;

        while (x != 0)
        {
            int last = x % 10;
            x /= 10;
            if (result > INT_MAX / 10) return 0;
            if (result < INT_MIN / 10) return 0;
            result = result * 10 + last;

        }
        return result;
    }

    int strStr(std::string haystack, std::string needle) 
    {
        return   haystack.find(needle);
    }

    bool containsDuplicate(vector<int>& nums) 
    {
        map<char, bool> unique;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (unique.find(nums[i]) == unique.end())
                unique.insert({ nums[i], 0 });
            else return true;
        }

        return false;
    }

    bool isNumericChar(char x)
    {
        return (x >= '0' && x <= '9') ? true : false;
    }
    int myAtoi(string str) {

        if (str == "")
            return 0;
        int i = 0;
        while (str[i] == ' ')
        {
            str.erase(str.begin());
        }
        long  int res = 0;
        int sign = 1;
        i = 0;

        if (str[0] == '-')
        {
            sign = -1;

            i++;
        }
        for (; str[i] != '\0'; ++i)
        {
            if (isNumericChar(str[i]) == false)
                return res;

            res = res * 10 + str[i] - '0';
        }
        return sign * res;
    }

    bool check(vector<int>& nums) // Check if Array Is Sorted and Rotated
    {
        int i = 0;
        int count = 0;
        while (i < nums.size()) {
            if (nums[i] > nums[(i + 1) % nums.size()]) {

                ++count;
            }
            ++i;
        }
        if (count <= 1) {
            return true;
        }

        return false;
    }

    void rotate(vector<int>& nums, int k) // bad solution
    {
        deque<int> deq;
        int size = nums.size() - k;
        for (int i = 0; i < size; i++)
        {
            deq.push_back(nums[i]);
        }
        for (size_t i = 0; i < k; i++)
        {
            deq.push_front(nums[size+i]);
        }
        for (int i = 0; i < deq.size(); i++)
        {
            nums[i] = deq[i];
        }
    }

    void moveZeroes(vector<int>& nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            if (nums[left] == 0)
            {
                nums[left++] = nums[right];
                nums[right--] = 0;
            }
            left++;
        }
    }
int main()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(0);
    vec.push_back(3);
    vec.push_back(0);
    vec.push_back(12);
  
    std::string s1 = "helloe";
    std::string s2 = "hel";
    strStr(s1, s2);
     moveZeroes        (vec);
}
