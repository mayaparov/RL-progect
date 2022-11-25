#include "Logger.h"

Logger::Logger()
{
	SYSTEMTIME kostyl;
	GetLocalTime(&kostyl);
	Logger::Log_time = kostyl;
	std::string filename = "Log\\" + std::to_string(Log_time.wYear) +
		'-' + std::to_string(Log_time.wMonth) +
		'-' + std::to_string(Log_time.wDay) +
		'-' + std::to_string(Log_time.wHour) +
		'-' + std::to_string(Log_time.wMinute) +
		'-' + std::to_string(Log_time.wSecond) +
		'-' + std::to_string(Log_time.wMilliseconds) + "-log.txt";

	if (std::filesystem::exists(filename))
	{
		filename.erase(filename.length() - 4, 4);
		filename = filename + "_1.txt";
	}

	for(int i = 2; std::filesystem::exists(filename); i++)
	{
		filename.erase(filename.length() - 6, 6);
		filename = filename + '_' + std::to_string(i) + ".txt";
	}

	Logger::os.open(filename.c_str(), std::ios::out);
	if (!(Logger::os.is_open()))
	{
		fs::create_directory("Log");
		Logger::os.open(filename.c_str(), std::ios::out);
	}
	if (Logger::os.is_open())
	{
		filename.erase(0, 4);
		filename.erase(filename.length() - 8, 8);
		os << "[LOG FILE START]" << '\n' << '[' << filename << "]\n";
	}
}

Logger::~Logger()
{
	
	os << "[LOG FILE END]";
	os.close();
}

bool Logger::print_msg(report &message)
{
	if (type_set.find(message.get_type()) != type_set.end())
	{
		if (Logger::os.is_open())
		{
			SYSTEMTIME msg_time;
			FILETIME ft1, ft, ft_res;
			GetLocalTime(&msg_time);
			SystemTimeToFileTime(&Log_time, &ft);
			SystemTimeToFileTime(&msg_time, &ft1);
			*(_int64*)&ft_res = (*(__int64*)&ft1) - (*(__int64*)&ft);
			FileTimeToSystemTime(&ft_res, &msg_time);
			msg_time.wYear = msg_time.wYear - 1601;
			msg_time.wMonth = msg_time.wMonth - 1;
			msg_time.wDay = msg_time.wDay - 1;
			Logger::os << '[' << std::to_string(Log_time.wYear) << '-'
				<< std::to_string(Log_time.wMonth) << '-'
				<< std::to_string(Log_time.wDay) << '-'
				<< std::to_string(Log_time.wHour) << '-'
				<< std::to_string(Log_time.wMinute) << '-'
				<< std::to_string(Log_time.wSecond) << '-'
				<< std::to_string(Log_time.wMilliseconds) << ']'
				<< "\t[" << message.get_type() << "]\t" << message.get_text() << '\n';
			return 0;
		}
	}
	return 1;
}

