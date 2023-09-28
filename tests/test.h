#include <array>
class Test {
private:
	static void test_repeat_input1();
	static void test_random_input();
	static void test_repeat_input2();
	static std::array<clock_t, 2> get_time(std::string& text, std::string& sample);
public:
	static void run_tests();
};