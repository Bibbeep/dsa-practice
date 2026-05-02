#include <algorithm>
#include <cstddef>
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
