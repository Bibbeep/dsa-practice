#include <cstddef>
#include <iostream>
#include <unordered_set>
#include <vector>

bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> set;
    for (auto num : nums) {
        if (set.count(num)) {
            return true;
        }

        set.insert(num);
    }

    return false;
}

int main() {
    std::size_t size;
    std::vector<int> nums;

    std::cin >> size;
    int x;
    while (size--) {
        std::cin >> x;
        nums.push_back(x);
    }

    bool result = containsDuplicate(nums);

    if (result) {
        std::cout << "true\n";
    } else {
        std::cout << "false\n";
    }

    return 0;
}
