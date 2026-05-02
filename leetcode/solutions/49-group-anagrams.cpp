#include <algorithm>
// #include <array>
#include <cstddef>
#include <cstring>
// #include <functional>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> dict;

    for (auto str : strs) {
        string val = str;
        sort(str.begin(), str.end());
        dict[str].push_back(val);
    }

    for (auto it : dict) {
        ans.push_back(it.second);
    }

    return ans;
}

// struct ArrayHasher {
//     template <size_t N> size_t operator()(const array<int, N>& a) const {
//         size_t h = 0;
//
//         for (auto e : a) {
//             h ^= hash<int>{}(e) + 0x9e3779b9 + (h << 6) + (h >> 2);
//         }
//         return h;
//     }
// };
//
// vector<vector<string>> groupAnagrams(vector<string>& strs) {
//     vector<vector<string>> ans;
//     unordered_map<array<int, 26>, vector<string>, ArrayHasher> map;
//
//     for (auto str : strs) {
//         array<int, 26> key = {0};
//         for (size_t ch : str) {
//             key[ch - 'a']++;
//         }
//
//         map[key].push_back(str);
//     }
//
//     for (auto it : map) {
//         ans.push_back(it.second);
//     }
//
//     return ans;
// }

int main() {
    size_t size;
    cin >> size;
    vector<string> strs;

    string s;
    while (size--) {
        cin >> s;
        strs.push_back(s);
    }

    vector<vector<string>> result = groupAnagrams(strs);

    cout << "[";
    for (vector<string> res : result) {
        cout << "[";
        for (string str : res) {
            cout << str << ",";
        }
        cout << "],";
    }
    cout << "]\n";

    return 0;
}
