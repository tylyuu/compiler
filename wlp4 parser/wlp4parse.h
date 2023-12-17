#ifndef WLP4PARSE_H
#define WLP4PARSE_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>

// Global constants for WLP4Parse

extern const std::string WLP4_CFG;
extern const std::string WLP4_TRANSITIONS;
extern const std::string WLP4_REDUCTIONS;
extern const std::string WLP4_COMBINED;

// Function declarations for WLP4Parse

std::string checkType(char c);
bool isSymbol(char c);
bool isValid(char c);
void checkNum(const std::string& output);
void idOrNumber(const std::string& s);
int shiftOrReduce(int current, const std::string& next);
int nextState(int current, const std::string& next);
void printTree(int rootNode);
void printLazy();

#endif // WLP4PARSE_H
