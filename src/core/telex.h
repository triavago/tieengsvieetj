#include <iostream>

class Telex {
public:
    std::string process(const std::string& context, char key);
private:
    std::string applyTone(char toneKey);
    std::string normalize();
};