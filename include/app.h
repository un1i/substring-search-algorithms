#include <string>


class App {
private:
	enum str_types {txt, smp};
	size_t alph_size;
	std::string text;
	std::string sample;
	void menu();
	void enter_string(str_types type);
	void standard_enter(std::string& str);
	void random_enter(std::string& str);
	void repeat_enter(std::string& str);
	void run_algorithms();
	void print_input_data();
	void change_input_data();
public:
	void run();
};