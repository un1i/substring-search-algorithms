#include <string>
#include <vector>

size_t kmp(const std::string& text, const std::string& sample, std::vector<int>& res);

std::vector<int> get_prefix(const std::string& str);