#include <iostream>

bool isValid(std::string s)
{
    if (s.length() % 2 != 0) {
        return false;
    }

    int par = 0;
    int square = 0;
    int curly = 0;
    typedef enum BracketType
    {
        PARENTHESIS,
        CURLY,
        SQUARE,
        NONE,
    } BracketType;
    std::vector<BracketType> bt;

    for (auto iter : s) {
        switch (iter)
        {
        case '(':
            par++;
            bt.push_back(PARENTHESIS);
            break;

        case ')':
            par--;
            if (bt.empty() || bt.back() != PARENTHESIS) {
                return false;
            }
            bt.pop_back();
            break;

        case '{':
            curly++;
            bt.push_back(CURLY);
            break;

        case '}':
            curly--;
            if (bt.empty() || bt.back() != CURLY) {
                return false;
            }
            bt.pop_back();
            break;

        case '[':
            square++;
            bt.push_back(SQUARE);
            break;

        case ']':
            square--;
            if (bt.empty() || bt.back() != SQUARE) {
                return false;
            }
            bt.pop_back();
            break;

        default:
            break;
        }
    }

    if (!par && !curly && !square) { 
        return true; 
    }
    return false;
}

int main()
{
    //std::string a = "([])";
    std::string a = "){";
    std::cout << isValid(a) << std::endl;
}