#pragma once
class Tape
{
private:
	int m_tapeSize;
	int m_position;
	char* m_tape;
public:
	Tape();
	~Tape();

	void MoveNext();
	void MovePrevious();
	void IncrementCUrrent();
	void DecrementCurrent();
	char GetCurrentValue();
	void SetCurrentValue(char newValue);
};

