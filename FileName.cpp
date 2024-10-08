#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int>rank(score);
        vector<string>res;
        unordered_map<int, string>m{ {0,""}};
        sort(rank.begin(), rank.end(), [](int a, int b) {return a > b; });
        for (int i = 0; i < rank.size(); i++) {
            switch (i)
            {
            case 0:
            {
                m[rank[i]] = "Gold Medal";
                break;
            }
            case 1:
                m[rank[i]] = "Silver Medal";
                break;
            case 2:
                m[rank[i]] = "Bronze Medal";
                break;
            default:
                m[rank[i]] =to_string( i + 1);
            }
             
        }
        for (int i = 0; i < score.size(); i++) {
            res.push_back(m[score[i]]);
        }
        return res;
    }
};