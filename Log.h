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
	//Скрываем контруктор класса, что бы избежать создания
	Log();
	~Log();

	static Log* _instance;
	static ofstream* fl;

public:

	//Убираем все методы которые могли бы клонировать данный класс
	Log(Log& other) = delete;
	void operator=(const Log&) = delete;

	//Функция для получения единственного экземпляра
	static Log* Instance();

	//Функция отправки сообщения в файл
	void Print(std::string msg);
};