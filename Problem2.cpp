// Time Complexity : O(n)
// Space Complexity : O(1)
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this :  No

// Your code here along with comments explaining your approach in three
// sentences only
// 1. First check if a mapping exists in sMap, if yes check if current char maps
// to the same value
// 2. If first time entry, then check in set if the t[i] is already mapped
// 3. then only create a entry in hashmap and the set, return true if the loop
// ends successfully
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isIsomorphic(string s, string t) {
    unordered_map<char, char> sMap;
    unordered_set<char> tSet;

    for (int i = 0; i < s.size(); i++) {
      if (sMap.count(s[i])) {
        if (sMap[s[i]] != t[i])
          return false;
      } else {
        if (tSet.count(t[i]))
          return false;
        sMap[s[i]] = t[i];
        tSet.insert(t[i]);
      }
    }

    return true;
  }
};
