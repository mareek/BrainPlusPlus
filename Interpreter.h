#pragma once
#include <string>
#include "Tape.h"
using namespace std;

class Interpreter
{
private:
	string m_program;
	int m_programSize;
	Tape* m_tape;
	int* m_jumpTable;

	void InitJumpTable();
	void OutputValue(char value);
public:
	Interpreter(string program);
	~Interpreter();

	void Execute();
};

