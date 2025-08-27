// Problem: Group Anagrams Together
//  Time Complexity : O(nk)
//  Space Complexity : O(n)
//  Did this code successfully run on Leetcode : Yes
//  Any problem you faced while coding this : No

// Your code here along with comments explaining your approach in three
// sentences only
// 1. We use form factor concept right to save on sorting for each string
// 2. We calculate the prime product of each string and store it in hashmap,
// this makes sure that for  abc, bac, cab we get the same value i.e anagrams of
// each other
// 3. Then we just extract the values from the hashmap and return
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  double calculatePrimeProduct(string str) {
    vector<int> primes = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37,  43,
                          47, 53, 59, 61, 67, 71, 73, 79, 83, 87, 97, 101, 103};
    double result = 1;
    for (char ch : str) {
      result *= primes[ch - 'a'];
    }
    return result;
  }

  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> res;
    unordered_map<double, vector<string>> u;
    for (auto str : strs) {
      double productVal = calculatePrimeProduct(str);
      u[productVal].push_back(str);
    }

    for (auto it : u) {
      res.push_back(it.second);
    }

    return res;
  }
};
