#include <iostream>

bool isSingleDigit(long long a)
{
    if (a % 10 == a) {
        return true;
    }
    return false;
}

bool endsInZero(long long a) {
    if (a % 10 == 0) {
        return true;
    }
    return false;
}

long long numLength(long long a) {
    long long len = 1;
    while (a % 10 != a) {
        len++;
        a /= 10;
    }
    return len;
}

long long power(long long base, long long exponent) {
    return static_cast<long long>(std::pow(base, exponent));
}

bool isPalindrome(long long num) {
    if (num < 0) {
        return false;
    }
    if (isSingleDigit(num)) {
        return true;
    }
    if (endsInZero(num)) {
        return false;
    }
    long long num_cp = num;
    long long result = 0;
    while (num_cp) {
        result *= 10;
        result += num_cp % 10;
        num_cp /= 10;
    }

    if (result == num) {
        return true;
    }
    return false;
}

long long main()
{
    std::cout << isPalindrome(-121) << std::endl;
    // std::cout << 91019/10000;
    return 0;
}