#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"

// https://leetcode.com/problems/shortest-completing-word/

// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:

    bool hasN(string& s, char c, int num) {
        unsigned long it = 0;
        for (int i = 0; i < num; ++i) {
            it = s.find(c, it);
            if (it == string::npos)
                return false;
            ++it;
        }
        return true;
    }

    string shortestCompletingWord(string licensePlate, vector<string> &words) {
        map<char,int> m;
        for (auto& c : licensePlate) {
            if (isalpha(c)) {
                if (c <= 'Z')
                    ++m[c - 'A' + 'a'];
                else
                    ++m[c];
            }
        }
        string shortest = "";
        for (auto& w : words) {
            bool found = true;
            for (auto& p : m) {
                if (! hasN(w, p.first, p.second)) {
                    found = false;
                    break;
                }
            }
            if (found && (shortest.empty() || shortest.length() > w.length()))
                shortest = w;
        }
        return shortest;
    }
};

void test1() {
//    vector<string> words{"step", "steps", "stripe", "stepple"};
//    string licensePlate = "1s3 PSt";
//
//    cout << " ? " << Solution().shortestCompletingWord(licensePlate, words) << endl;

    // "1s3 456"
    //["looks","pest","stew","show"]
    vector<string> w2{"looks","pest","stew","show"};
    string l2 = "1s3 456";

    cout << "pest ? " << Solution().shortestCompletingWord(l2, w2) << endl;

}

void test2() {

}

void test3() {

}