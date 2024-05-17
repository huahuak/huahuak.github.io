#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

#include "define.h"

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> num2index(0);
    for (int i = 0; i < nums.size(); i++) {
      auto it = num2index.find(target - nums[i]);
      if (it == num2index.end()) {
        num2index[nums[i]] = i;
        continue;
      }
      return {it->second, i};
    }
    return {};
  }

  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode dummy;
    ListNode *p = &dummy;
    ListNode *pl1 = l1;
    ListNode *pl2 = l2;
    auto tmp = 0;
    auto add = [&tmp, &p](int sum) {
      sum += tmp;
      tmp = sum / 10;
      p->next = new ListNode(sum % 10);
      p = p->next;
    };
    while (pl1 != nullptr && pl2 != nullptr) {
      add(pl1->val + pl2->val);
      pl1 = pl1->next;
      pl2 = pl2->next;
    }
    while (pl1 != nullptr) {
      add(pl1->val);
      pl1 = pl1->next;
    }
    while (pl2 != nullptr) {
      add(pl2->val);
      pl2 = pl2->next;
    }
    if (tmp > 0) {
      add(0);
    }
    return dummy.next;
  }

  int lengthOfLongestSubstring(string s) {
    int maxLength = 0;
    int bitmap[256] = {};
    int lhs = 0;
    int rhs = 0;
    for (char ch : s) {
      if (bitmap[ch] == 1) {
        int p = lhs;
        while (s[p] != ch) {
          bitmap[s[p]] = 0;
          p++;
        }
        lhs = p + 1;
      }
      bitmap[ch] = 1;
      rhs += 1;
      if (rhs - lhs > maxLength) {
        maxLength = rhs - lhs;
      }
    }
    return maxLength;
  }

  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    auto searchFirstLagerThanTarget = [](vector<int> arr, int target) -> int {
      // arr is sorted.
      // arr[r] must larger than target.
      int l = 0;
      int r = arr.size();
      while (r - l > 0) {
        int m = (l + r) / 2;
        if (arr[m] < target) {
          l = m;
        } else {
          r = m;
        }
      };
      return r;
    };

    int cnt = (nums1.size() + nums2.size()) / 2;
    int l1 = 0, l2 = 0, r1 = nums1.size(), r2 = nums2.size();
    


    return 0;
  }
};

int main() {
  vector<int> a1 = {1, 5};
  vector<int> a2 = {7, 8};
  cout << Solution().findMedianSortedArrays(a1, a2);
}