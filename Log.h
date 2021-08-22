#pragma once
#define LOG_FILE_PATH "log.txt"
#define LOG_PRINT(a) Log::Instance()->Print(a)

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Log
{

protected:
	//�������� ���������� ������, ��� �� �������� ��������
	Log();
	~Log();

	static Log* _instance;
	static ofstream* fl;

public:

	//������� ��� ������ ������� ����� �� ����������� ������ �����
	Log(Log& other) = delete;
	void operator=(const Log&) = delete;

	//������� ��� ��������� ������������� ����������
	static Log* Instance();

	//������� �������� ��������� � ����
	void Print(std::string msg);
};