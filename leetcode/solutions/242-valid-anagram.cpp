#include <cstddef>
#include <iostream>
#include <unordered_map>

// O(n) solution
bool isAnagram(std::string s, std::string t) {
    std::unordered_map<char, std::size_t> s_freq;
    std::unordered_map<char, std::size_t> t_freq;

    for (std::size_t i = 0; i < s.length(); ++i) {
        s_freq[s[i]]++;
    }

    for (std::size_t i = 0; i < t.length(); ++i) {
        t_freq[t[i]]++;
    }

    if (s_freq == t_freq) {
        return true;
    }

    return false;
}

int main() {
    std::string s, t;
    std::cin >> s >> t;

    bool result = isAnagram(s, t);
    std::cout << result << "\n";

    return 0;
}
