#include <string>
#include <unordered_map>


class App {
private:
	enum str_types {txt, smp};
	std::unordered_map<char, int> alphabet;
	std::string text;
	std::string sample;
	void menu();
	void enter_string(str_types type);
	void enter_alphabet();
	bool check_str(const std::string& str);
	void standard_enter(std::string& str);
	void random_enter(std::string& str);
	void repeat_enter(std::string& str);
	void run_algorithms();
	void print_input_data();
	void print_alphabet();
	void change_input_data();
public:
	void run();
};