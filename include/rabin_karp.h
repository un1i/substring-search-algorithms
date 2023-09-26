#include <string>
#include <unordered_map>

const int MOD = 1000097;

size_t rabin_karp(const std::string& text, const std::string& sample, std::unordered_map<char, int>& alphabet);
