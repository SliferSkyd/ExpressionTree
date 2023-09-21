#ifndef _PARSEEXCEPTION_H
#define _PARSEEXCEPTION_H
#include <iostream>
#include <stdexcept>

class ParseException : public std::runtime_error {
public:
    ParseException(const std::string& message, char character, int position)
            : std::runtime_error(message), illegalCharacter(character), errorPosition(position) {}
    ParseException(const std::string& message) : std::runtime_error(message)  {}

    char getIllegalCharacter() const {
        return illegalCharacter;
    }

    int getErrorPosition() const {
        return errorPosition;
    }

private:
    char illegalCharacter;
    int errorPosition;
};
#endif //_PARSEEXCEPTION_H
