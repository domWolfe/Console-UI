#include "math.hpp"

int Math::clamp(int val, int minimum, int maximum) {
    return max(min(val, maximum), minimum);
}

int Math::wrap(int val, int minimum, int maximum) {
        return val > maximum ? minimum : val;
}

int Math::menu_wrap(int val, int minimum, int maximum) {
    if (minimum == maximum)
        return maximum;

    if (minimum < maximum)
        return val > maximum ? minimum : val;
    else
        return val < maximum ? minimum : val;
}

std::vector<std::string> Util::splitString(std::string str, char splitter) {
    std::vector<std::string> result;
    std::string current = "";
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == splitter) {
            if (current != "") {
                result.push_back(current);
                current = "";
            }
            continue;
        }
        current += str[i];
    }
    if (current.size() != 0)
        result.push_back(current);
    return result;
}