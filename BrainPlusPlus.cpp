#include "Interpreter.h"

int main()
{
	string outputFortyTwoProgram = "[-]>[-]<>+++++++[<+++++++>-]<+++.--.";
	auto interpreter = new Interpreter(outputFortyTwoProgram);
	interpreter->Execute();
}