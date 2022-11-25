#pragma once
#include <string>
#include <set>
#include <cctype>
#include <algorithm>

class report
{
	std::string type;
	const char* text;
	

public:

	report(std::string msg_type, const char* msg_text);
	report(std::string msg_text);
	report();
	bool set_type(std::string msg_type);
	void set_text(std::string msg_text);
	std::string get_text();
	std::string get_type();
	bool is_emtpy();


};

