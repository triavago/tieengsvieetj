#include "telex.hpp"

std::string Telex::process(const std::string& context, char key) {
    buffer = context;
    if(isToneKey(key)) {
        if(!buffer.empty()) {
            std::string::iterator vowelIt;
            for(auto &it : mVowels) {
                vowelIt = std::find(buffer.begin(), buffer.end(), it);
            }
            char tonedChar = *vowelIt;
            tonedChar = applyTone(key, tonedChar);
            std::string restBuf(vowelIt, buffer.end());
            buffer.erase(buffer.begin(), vowelIt);
            return buffer + restBuf;
        }
        if (key == ' ' || key == '\n' || ispunct(key)) {
            std::string res = buffer + key;
            reset();
            return res;
        }

        buffer += key;
        return buffer;
    }
}

void Telex::reset() {
    buffer.clear();
}

bool Telex::isToneKey(char c) {
    return (c == 's' || c == 'f' || c == 'r' || c == 'j' || c == 'x');
}

char Telex::applyTone(char tone, char base) {
    
}