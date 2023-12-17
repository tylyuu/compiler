#ifndef WLP4SCAN_H
#define WLP4SCAN_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

// Global constants and functions declarations for WLP4Scan

extern const std::string WLP4_CFG;
extern std::vector<std::string> tokenName;
extern std::vector<std::string> tokenSymbol;
extern std::vector<std::string> symbol;
extern const int int_max;

class ScanningError : public std::exception {
private:
    std::string message;

public:
    ScanningError();
    const char* what() const throw() override;
};

std::string checkType(char c);
bool isSymbol(char c);
bool isValid(char c);
void checkNum(const std::string& output);
void idOrNumber(const std::string& s);

#endif // WLP4SCAN_H
