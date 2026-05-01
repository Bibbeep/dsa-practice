#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <vector>

// O(n^2) solution
// std::vector<int> twoSum(std::vector<int>& nums, int target) {
//     std::vector<int> ans(2);
//     for (std::size_t i = 0; i < nums.size() - 1; i++) {
//         for (std::size_t j = i + 1; j < nums.size(); j++) {
//             if (nums[i] + nums[j] == target) {
//                 ans[0] = i;
//                 ans[1] = j;
//                 return ans;
//             }
//         }
//     }
//
//     return ans;
// }

// O(n) solution
std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::vector<int> ans;
    std::unordered_map<int, int> map; // Ai -> i, Ai = value, i = index

    for (auto it = nums.begin(); it != nums.end(); ++it) {
        auto it2 = map.find(target - *it);

        if (it2 != map.end()) {
            ans.push_back(it - nums.begin());
            ans.push_back(it2->second);
            break;
        }

        map[*it] = it - nums.begin();
    }

    return ans;
}

int main() {
    std::size_t length;
    std::vector<int> nums;
    int target;

    std::cin >> length;

    int x;
    while (length--) {
        std::cin >> x;
        nums.push_back(x);
    }

    std::cin >> target;

    std::vector<int> result = twoSum(nums, target);
    std::cout << result[0] << " " << result[1] << "\n";

    return 0;
}
