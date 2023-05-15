// https://www.codewars.com/kata/58e24788e24ddee28e000053

#include <string>
#include <unordered_map>
#include <vector>

std::unordered_map<std::string, int> assembler(const std::vector<std::string> &program)
{
    std::unordered_map<std::string, int> registers;

    auto getReg = [&](std::string name) -> int &
    {
        if (registers.find(name) == registers.end())
        {
            registers[name] = 0;
        }
        return registers[name];
    };

    int instructionPointer = 0;
    int programSize = program.size();

    while (instructionPointer < programSize)
    {
        std::string instruction = program[instructionPointer];
        size_t spacePos = instruction.find(' ');
        std::string opCode = instruction.substr(0, spacePos);
        std::string operands = instruction.substr(spacePos + 1);

        if (opCode == "mov")
        {
            size_t spacePos2 = operands.find(' ');
            std::string dest = operands.substr(0, spacePos2);
            std::string src = operands.substr(spacePos2 + 1);

            if (isdigit(src[0]) || (src[0] == '-' && isdigit(src[1])))
            {
                getReg(dest) = std::stoi(src);
            }
            else
            {
                getReg(dest) = getReg(src);
            }
        }
        else if (opCode == "inc")
        {
            getReg(operands)++;
        }
        else if (opCode == "dec")
        {
            getReg(operands)--;
        }
        else if (opCode == "jnz")
        {
            size_t spacePos2 = operands.find(' ');
            std::string condition = operands.substr(0, spacePos2);
            std::string offsetStr = operands.substr(spacePos2 + 1);
            int offset = 0;

            if (isdigit(condition[0]) || (condition[0] == '-' && isdigit(condition[1])))
            {
                if (std::stoi(condition) != 0)
                {
                    offset = std::stoi(offsetStr);
                    instructionPointer += offset;
                    continue;
                }
            }
            else
            {
                if (getReg(condition) != 0)
                {
                    offset = std::stoi(offsetStr);
                    instructionPointer += offset;
                    continue;
                }
            }
        }

        ++instructionPointer;
    }

    return registers;
}