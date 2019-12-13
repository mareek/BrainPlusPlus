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
		auto newSize = m_tapeSize * 2;
		auto newTape = new char[newSize];

		//copy old tape to new tape
		for (int i = 0; i < m_tapeSize; i++)
		{
			newTape[i] = m_tape[i];
		}

		//init newTape to 0;
		for (int i = m_tapeSize; i < newSize; i++)
		{
			newTape[i] = 0;
		}
		
		delete m_tape;
		m_tape = newTape;
		m_tapeSize = newSize;
	}
}

void Tape::MovePrevious()
{
	m_position--;
}

void Tape::IncrementCurrent()
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
