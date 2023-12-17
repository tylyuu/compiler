#ifndef WLP4TYPE_H
#define WLP4TYPE_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>

// Procedure class definition
class Procedure {
    std::string name;
    std::vector<std::string> signature;
    std::map<std::string, std::string> table;

public:
    Procedure(std::string name, std::vector<std::string> signature, std::map<std::string, std::string> table);

    void insert(std::string var, std::string type);
    bool inTable(std::string var);
    std::string getType(std::string name);
    void addSignature(std::string type);
    int getArgSize();
    void checkArglis(std::vector<std::string> input);
};

// Function Declarations
void initProcedure(std::string name);
std::pair<std::string, std::string> checkDecl(int declIndex);
void checkDecls(std::string procedure, int index);
void checkStatement(std::string procedure, int index);
void checkStatements(std::string procedure, int index);
void checkTest(std::string procedure, int index);
std::string checkLvalue(std::string procedure, int index);
std::pair<std::string, std::string> checkID(std::string procedure, int index);
std::string checkFactor(std::string procedure, int index);
void checkArg(std::string procedure, std::string name, int index, std::vector<std::string> arg);
std::string checkExpression(std::string procedure, int index);
std::string checkTerm(std::string procedure, int index);
void checkParamlist(std::string procedure, int index);
void checkWain(int nodeIndex);
void treeTraversal(int root);
void treeConstruct(std::vector<std::pair<std::string, std::vector<std::string>>> &input, std::vector<int> &node);
std::string printPair(std::pair<std::string, std::vector<std::string>> pair);

// Global Constants
extern const std::string WLP4_CFG;
extern const std::string ptrType;
extern const std::string intType;

#endif
