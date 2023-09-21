#include <bits/stdc++.h>
#include "Token.h"
#include "parseException.h"

#ifndef LAB2_LEXICALANALYZER_H
#define LAB2_LEXICALANALYZER_H

class LexicalAnalyzer {
public:
    std::istream &is;
    int curChar;
    int curPos;
    Token curToken;

    bool isBlank(int c) {
        return c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32;
    }

    void nextChar() {
        if (is.peek() == EOF) {
            curChar = '\0';
            return;
        }
        curPos++;
        curChar = is.get();
    }
    void skipBlank(){
        while(isBlank(curChar)){
            nextChar();
        }
    }

    void nextToken(){
        nextChar();
        skipBlank();
        switch((char)curChar){
            case '(':
                curToken = LPAREN;
                break;
            case ')':
                curToken = RPAREN;
                break;
            case '&':
                curToken = AND;
                break;
            case '|':
                curToken = OR;
                break;
            case '^':
                curToken = XOR;
                break;
            case '!':
                curToken = NOT;
                break;
            case '\0':
                curToken = END;
                break; 
            default:
                if(curChar >= 'a' && curChar <= 'z'){
                    curToken = TERMINAL;
                    break;
                }else{
                    throw ParseException("Illegal character: " + std::string(1, curChar), curChar, curPos);
                }
        }
    }
    Token getCurToken() {
        return curToken;
    }
    int getCurPos(){
        return curPos;
    }
    int getCurChar(){
        return curChar;
    }
    
    LexicalAnalyzer(std::istream &istr) : is(istr) {
        curPos = 0;
        nextToken();
    }
};

#endif //LAB2_LEXICALANALYZER_H
