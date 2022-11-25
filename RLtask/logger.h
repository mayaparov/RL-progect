#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <experimental/filesystem>
#include <windows.h>
#include <stdio.h>
#include <string>
#include "message.h"

namespace fs = std::experimental::filesystem;
class Logger
{
		SYSTEMTIME Log_time;
		std::ofstream os;
		std::set <std::string> type_set = { "ERROR", "WARNING", "MESSAGE", "" };

	public:

		Logger();
		~Logger();
		bool print_msg(report &message);
	
};

