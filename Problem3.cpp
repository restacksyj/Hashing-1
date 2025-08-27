// Problem: Word Pattern
// Time Complexity : O(n)
// Space Complexity : O(1)
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this :  No

// Your code here along with comments explaining your approach in three
// sentences only
// 1. This is Similar to Isomorphic strings problem
// 2. We first split the sentence by space and then check if a mapping exists,
// if yes check if the value is same as the pattern[i];
// 3. if no entry check if pattern[i] is not already mapped, if yes return false
// otherwise continue The other approach, return true if loop ends
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool wordPattern(string pattern, string s) {
    unordered_map<string, char> u;
    unordered_set<char> se;

    stringstream ss(s);
    string word;
    vector<string> words;
    while (ss >> word) {
      words.push_back(word);
    }

    if (words.size() != pattern.size())
      return false;

    for (int i = 0; i < pattern.size(); i++) {
      if (u.count(words[i])) {
        if (u[words[i]] != pattern[i])
          return false;
      } else {
        if (se.count(pattern[i]))
          return false;
        u[words[i]] = pattern[i];
        se.insert(pattern[i]);
      }
    }

    return true;
  }
};
