#ifndef WLP4GEN_H
#define WLP4GEN_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <stack>
#include <set>

// Constants
extern const std::string WLP4_CFG;
extern const std::string ptrType;
extern const std::string intType;

// Function Declarations
std::string ternaryOp(std::string name, int dest, int s, int t);
std::string binaryOp(std::string name, int s, int t);
std::string binaryJump(std::string name, int s, int t, std::string dest);
std::string mult(int s, int t);
std::string divide(int s, int t);
std::string mfhi(int reg)
std::string mflo(int reg);
std::string add(int dest, int s, int t);
std::string sub(int dest, int s, int t);
std::string slt(int dest, int s, int t);
std::string sltu(int dest, int s, int t);
std::string beq(int s, int t, std::string dest);
std::string bne(int s, int t, std::string dest);
std::string jalr(int reg);
std::string jr(int reg);
std::string updatesp();
std::string subtractsp();
std::string sw(int t, int offset, int s);
std::string lw(int t, int offset, int s);
std::string generateLabel();
std::string generateComment(std::string s);
void prologue(std::string procedure);
void epilogue(std::string procedure);
void storeRegister(int reg, std::string content);
void setFramePointer();
void initProcedure(std::string name);
void processWain(int index);
void processDecls(std::string procedure, int index);
void processDecl(std::string procedure, int index, int reg, bool store);
void processPrintln(std::string procedure, int index);
void processExpression(std::string procedure, int index);
void processTerm(std::string procedure, int index);
void processFactor(std::string procedure, int index);
int processArg(std::string procedure, int index, int count);
void processTest(std::string procedure, int index);
void processID(std::string procedure, int index, int reg);
void processNum(std::string procedure, int index, int reg);
void processStatement(std::string procedure, int index);
void processStatements(std::string procedure, int index);
int processLvalue(std::string procedure, int index); // return the offset
std::pair<std::string, int> getIdInfo(std::string procedure, int index); // return (name, offset)
std::string getNum(int index);
void processWain(int index);
void processProcedures(int index);
void processProcedure(int index);
void popRegisters(std::string procedure);
void processParams(std::string procedure, int index, bool store);
void processParamlist(std::string procedure, int index, bool store);
int getParamcount(std::string procedure, int index, int count);
int paramCountHelp(std::string procedure, int index, int count);
void storeID(std::string procedure, int index, int reg, bool store);
void pushVar(std::string procedure, std::string var, int reg);
void code(std::string procedure, std::string var); // equiv code(a): load a into $3
void push(int reg); // push from stack to $reg
void pop(int reg);
void call(std::string procedure);

class Procedure {
    string name;
    map<string, pair<string, int>> symbolTable;
    int offset;

public:
    Procedure(string name);
    void insert(string var, string type);
    bool varExist(string var);
    void updateOffset(int count);
    int getOffset(string name);
    int getTableSize();
    void popRegister();
};

struct Statement {
    string lhs;
    vector<string> rhs;
    string type;

public:
    Statement(string lhs, vector<string>rhs, string type = "");
    string print();
    bool isEmpty();
};


#endif
