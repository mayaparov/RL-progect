#include "message.h"

void to_upper(char& ch) 
{
	ch = toupper(static_cast<unsigned char>(ch));
}

report::report(std::string msg_type, const char* msg_text)
{
	std::for_each(msg_type.begin(), msg_type.end(), to_upper);
	report::type = msg_type;
	report::text = msg_text;
}

report::report(std::string msg_text)
{
	report::text = msg_text.c_str();
	report::type = "";
}

report::report()
{
	report::text = "";
	report::type = "";
}

bool report::set_type(std::string msg_type)
{
	std::for_each(msg_type.begin(), msg_type.end(), to_upper);
	report::type = msg_type;
	return 0;
}

void report::set_text(std::string msg_text)
{
	report::text = msg_text.c_str();
}



std::string report::get_text()
{
	return report::text;
}

std::string report::get_type()
{
	return report::type;
}

bool report::is_emtpy()
{
	if(report::text[0] == '\0')	return 1;
	return 0;
}
