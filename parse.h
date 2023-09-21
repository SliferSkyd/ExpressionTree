#ifndef LAB2_PARSE_H
#define LAB2_PARSE_H

#include<iostream>
#include "lexicalAnalyzer.h"
#include "Token.h"
#include "parseException.h"
#include "Tree.h"

class Parse {
    LexicalAnalyzer lex;
private:
    Tree A() {
        Tree sub = B();
        if (lex.curToken != AND && lex.curToken != OR) return sub; 
        Tree cont = APrime();
        return Tree("", {sub, cont});
    }

    Tree B() {
        Tree sub = C();
        if (lex.curToken != XOR) return sub; 
        Tree cont = BPrime();
        return Tree("", {sub, cont});
    }

    Tree APrime() {
        switch (lex.curToken) {
            case OR: {
                std::string tmp = "|";
                lex.nextToken();
                Tree sub = B();
                if (lex.curToken != AND && lex.curToken != OR) return Tree("", {Tree(tmp), sub}); 
                Tree cont = APrime();
                return Tree("", {Tree(tmp), sub, cont});
            }
            case AND: {
                std::string tmp = "&";
                lex.nextToken();
                Tree sub = B();
                if (lex.curToken != AND && lex.curToken != OR) return Tree("", {Tree(tmp), sub}); 
                Tree cont = APrime();
                return Tree("", {Tree(tmp), sub, cont});
            }
            default: {
                throw ParseException("Illegal character. Expected | or &");
            }
        }
    }

    Tree C() {
        switch (lex.curToken) {
            case NOT: {
                lex.nextToken();
                Tree sub = D();
                return Tree("", {Tree("!"), sub});
            }
            default: {
                Tree sub = D();
                return sub;
            }
        }
    }

    Tree BPrime() {
        switch (lex.curToken) {
            case XOR: {
                lex.nextToken();
                Tree sub = C();
                if (lex.curToken != XOR) return Tree("", {Tree("^"), sub}); 
                Tree cont = BPrime();
                return Tree("", {Tree("^"), sub, cont});
            }
            default: {
                throw ParseException("Illegal character. Expected ^");
            }
        }
    }

    Tree D() {
        switch (lex.curToken) {
            case TERMINAL: {
                std::string tmp = std::string(1, lex.getCurChar());
                lex.nextToken();
                return Tree(tmp);
            }
            case LPAREN: {
                lex.nextToken();
                Tree sub = A();
                if (lex.curToken != RPAREN) {
                    throw new ParseException("Illegal character:", lex.curChar, lex.curPos);
                }
                lex.nextToken();
                return Tree("", {Tree("("), sub, Tree(")")});
            }
            default:
                throw new ParseException("Illegal character. Expected terminal and (");
        }
    }
public:
    Parse(std::istream &istr) : lex(istr) {}
    
    Tree parse() {
        Tree result = A();
        if (lex.curToken != END) {
            throw ParseException("Illegal character. Expected EOF");
        }
        return result;
    }
};

#endif //LAB2_PARSE_H
