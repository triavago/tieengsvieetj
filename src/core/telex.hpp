#include <iostream>
#include <algorithm>
#include <vector>

class Telex {
public:
    std::string process(const std::string& context, char key);
    void reset();
private:
    std::string buffer;
    bool isToneKey(char key);
    char applyTone(char toneKey, char base);
    std::string normalize();
    std::vector<char> mVowels = {'a','e','i','o','u'};
};