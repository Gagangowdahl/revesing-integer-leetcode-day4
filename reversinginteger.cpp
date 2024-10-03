
#include <limits>

using namespace std;

class Solution {
public:

    template<typename T>
    bool overflows_upper(int num, int digit) {
        return (num > numeric_limits<T>::max() / 10) ||
            ((num == numeric_limits<T>::max() / 10) && (digit > numeric_limits<T>::max() % 10));
    }

    template<typename T>
    bool overflows_lower(int num, int digit) {
        return (num < numeric_limits<T>::min() / 10) ||
            ((num == numeric_limits<T>::min() / 10) && (digit < numeric_limits<T>::min() % 10));
    }

    int reverse(int x) {
        int reversed = 0;

        while(x != 0) {
            int lsd = x % 10;

            if(overflows_upper<int>(reversed, lsd) || overflows_lower<int>(reversed, lsd))
            {
                return 0;
            }

            reversed *= 10;
            reversed += lsd;
            x /= 10;
        }

        return reversed;
    }
};