#include <cstddef>
#include <functional>
#include <iostream>
#include <map>
// #include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

// vector<int> topKFrequent(vector<int>& nums, int k) {
//     vector<int> ans;
//     unordered_map<int, size_t> freq;
//     priority_queue<pair<size_t, int>> q;
//
//     for (int num : nums) {
//         ++freq[num];
//     }
//
//     for (auto f : freq) {
//         q.push(make_pair(f.second, f.first));
//     }
//
//     while (k--) {
//         ans.push_back(q.top().second);
//         q.pop();
//     }
//
//     return ans;
// }

vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> ans;
    unordered_map<int, size_t> u_map;
    multimap<size_t, int, greater<int>> m_map;

    for (auto num : nums) {
        ++u_map[num];
    }

    for (auto u_it : u_map) {
        m_map.insert({u_it.second, u_it.first});
    }

    auto m_it = m_map.begin();
    while (k--) {
        ans.push_back(m_it->second);
        ++m_it;
    }

    return ans;
}

int main() {
    size_t size;
    vector<int> nums;
    cin >> size;

    int x;
    while (size--) {
        cin >> x;
        nums.push_back(x);
    }

    int k;
    cin >> k;

    vector<int> result = topKFrequent(nums, k);
    for (auto res : result) {
        cout << res << ",";
    }
    cout << "\n";

    return 0;
}
