#include <cstddef>
#include <iostream>
#include <vector>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::vector<int> ans(2);
    for (std::size_t i = 0; i < nums.size() - 1; i++) {
        for (std::size_t j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                ans[0] = i;
                ans[1] = j;
                return ans;
            }
        }
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
