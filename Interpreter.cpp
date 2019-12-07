#include <stack>
#include "Interpreter.h"

Interpreter::Interpreter(string program)
{
	m_program = program;
	m_tape = new Tape();
	m_jumpTable = new int[program.size()];
}

Interpreter::~Interpreter()
{
	delete m_tape;
	delete m_jumpTable;
}

void Interpreter::InitJumpTable()
{
	auto openingBracketPositions = new std::stack<int>();
	for (int i = 0; i < m_program.length; i++)
	{
		if (m_program.at(i) == '[')
		{
			openingBracketPositions->push(i);
		}
		else if (m_program.at(i) == ']')
		{
			int startBracketPosition = openingBracketPositions->top();
			openingBracketPositions->pop();
			m_jumpTable[startBracketPosition] = i;
			m_jumpTable[i] = startBracketPosition;
		}
	}
}

void Interpreter::Execute()
{
}
