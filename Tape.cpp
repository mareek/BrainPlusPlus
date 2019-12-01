#include "Tape.h"
Tape::Tape()
{
	m_tapeSize = 64;
	m_tape = new char[m_tapeSize];
	m_position = 0;
}

Tape::~Tape()
{
	delete m_tape;
}

void Tape::MoveNext()
{
	m_position++;
	if (m_position >= m_tapeSize)
	{
		delete m_tape;
		m_tapeSize *= 2;
		m_tape = new char[m_tapeSize];
	}
}

void Tape::MovePrevious()
{
	m_position--;
}

void Tape::IncrementCUrrent()
{
	m_tape[m_position] += 1;
}

void Tape::DecrementCurrent()
{
	m_tape[m_position] -= 1;
}

char Tape::GetCurrentValue()
{
	return m_tape[m_position];
}

void Tape::SetCurrentValue(char newValue)
{
	m_tape[m_position] = newValue;
}
