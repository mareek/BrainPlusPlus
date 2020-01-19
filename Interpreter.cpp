#include <stack>
#include <iostream>
#include <conio.h>
#include "Interpreter.h"

Interpreter::Interpreter(string program)
{
	m_program = program;
	m_programSize = program.size();
	m_tape = new Tape();
	m_jumpTable = new int[m_programSize];
}

Interpreter::~Interpreter()
{
	delete m_tape;
	delete m_jumpTable;
}

void Interpreter::InitJumpTable()
{
	auto openingBracketPositions = new std::stack<int>();
	for (int i = 0; i < m_programSize; i++)
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
	this->InitJumpTable();
	int position = 0;
	while (position < m_programSize)
	{
		auto instruction = m_program.at(position);
		switch (instruction)
		{
		case '>': //  >  Increment the pointer.
			m_tape->MoveNext();
			position++;
			break;
		case '<': //  <  Decrement the pointer
			m_tape->MovePrevious();
			position++;
			break;
		case '+': //  +  Increment the byte at the pointer.
			m_tape->IncrementCurrent();
			position++;
			break;
		case '-': //  -  Decrement the byte at the pointer.
			m_tape->DecrementCurrent();
			position++;
			break;
		case'.': //  .  Output the byte at the pointer.
			OutputValue(m_tape->GetCurrentValue());
			position++;
			break;
		case',': //  ,  Input a byte and store it in the byte at the pointer.
			m_tape->SetCurrentValue(_getch());
			position++;
			break;
		case '[': //  [  Jump forward past the matching ] if the byte at the pointer is zero.
			position = (m_tape->GetCurrentValue() == 0) ? m_jumpTable[position] + 1 : position + 1;
			break;
		case ']': //  ]  Jump backward to the matching [ unless the byte at the pointer is zero.
			position = m_jumpTable[position];
			break;
		default:
			position++;
			break;
		}
	}
}

void Interpreter::OutputValue(char value)
{
	switch (value)
	{
	case 13:
		break;
	case 10:
		cout << endl;
		break;
	default:
		cout << value;
		break;
	}
}
