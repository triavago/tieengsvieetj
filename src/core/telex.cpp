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
    const std::unordered_map<char, std::unordered_map<char, char>> toneMap =
    {
        {'a', {{'s', 'á'}, {'f', 'à'}, {'r', 'ả'}, {'x', 'ã'}, {'j', 'ạ'}}},
        {'e', {{'s', 'é'}, {'f', 'è'}, {'r', 'ẻ'}, {'x', 'ẽ'}, {'j', 'ẹ'}}},
        {'o', {{'s', 'ó'}, {'f', 'ò'}, {'r', 'ỏ'}, {'x', 'õ'}, {'j', 'ọ'}}},
        {'i', {{'s', 'í'}, {'f', 'ì'}, {'r', 'ỉ'}, {'x', 'ĩ'}, {'j', 'ị'}}},
        {'u', {{'s', 'ú'}, {'f', 'ù'}, {'r', 'ủ'}, {'x', 'ũ'}, {'j', 'ụ'}}},
        {'y', {{'s', 'ý'}, {'f', 'ỳ'}, {'r', 'ỷ'}, {'x', 'ỹ'}, {'j', 'ỵ'}}}
    };

    auto it = toneMap.find(base);
    if(it != toneMap.end()) {
        auto toneIt = it->second.find(tone);
        if(toneIt != it->second.end()) {
            return toneIt->second;
        }
    }
    return base;
}