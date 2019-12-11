#include "Interpreter.h"
#include <fstream>

int main(int argc, char* argv[])
{
	string program;
	if (argc > 1)
	{
		auto programPath = argv[1];
		ifstream iFileStream(programPath);
		if (!iFileStream.good())
		{
			throw std::runtime_error("File not found");
		}
		program.assign((istreambuf_iterator<char>(iFileStream)), istreambuf_iterator<char>());
	}
	else
	{
		const string outputFortyTwoProgram = "[-]>[-]<>+++++++[<+++++++>-]<+++.--.";
		program = outputFortyTwoProgram;
	}

	Interpreter* interpreter = new Interpreter(program);
	interpreter->Execute();
	delete interpreter;
}