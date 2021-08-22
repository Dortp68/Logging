#include "Log.h"

Log* Log::_instance = nullptr;
ofstream* Log::fl = nullptr;

Log::Log()
{
	fl = new std::ofstream();
	fl->open(LOG_FILE_PATH);
	if (!fl->is_open())
	{
		throw ("Can't open log file!\n");
		delete fl;
		return;
	}
}

Log::~Log()
{
	if (this->_instance != nullptr)
	{
		delete this->_instance;
	}

	if (this->fl != nullptr)
	{
		fl->close();
		delete fl;
	}
}

Log* Log::Instance()
{
	if (_instance == nullptr)
		_instance = new Log();

	return _instance;
}

void Log::Print(std::string msg)
{
	*fl << msg << endl;
}
