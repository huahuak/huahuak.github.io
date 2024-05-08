#include <algorithm>
#include <cstddef>
#include <iostream>
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
};