#pragma once
#include <string>

#include "Memory.hpp"

using Code = std::string;
using Input = std::string;

struct Brainfuck final {
    std::string interpret(Code const& code, Input const& input) const;

    Brainfuck() = default;
    Brainfuck(Brainfuck const&) = delete;
    Brainfuck& operator=(Brainfuck const&) = delete;

};

int reader(Code const &code, Input const &input, int code_it, int input_it, Memory *memory, std::string *result);