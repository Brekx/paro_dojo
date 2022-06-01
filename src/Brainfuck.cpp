#include "Brainfuck.hpp"
#include "Memory.hpp"
#include "stringConverter.hpp"

std::string Brainfuck::interpret(Code const &code, Input const &input) const {
  Memory memory;
  std::string result = "";
	int code_it = 0, input_it = 0;

  int x = reader(code, input, code_it, input_it, &memory, &result) == code.size();
  return result;
}

int reader(Code const &code, Input const &input, int code_it, int input_it, Memory *memory, std::string *result) {
	int end;
  for(; code_it < code.size(); code_it++)
	switch (code[code_it]) {
    case '+':
      memory->increment();
      break;
    case '-':
      memory->decrement();
      break;
    case '>':
      memory->moveRight();
      break;
    case '<':
      memory->moveLeft();
      break;
		case ',':
			memory->set(input[input_it]);
			input_it++;
			break;
		case '.':
			(*result) += memory->get();
			break;
		case '[':
			while(memory->get() != 0){
				end = reader(code, input, code_it + 1, input_it, memory, result);
      }
			code_it = end;
			break;
		case ']':
			return code_it;
    }
		return code_it;
}
