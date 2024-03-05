#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<unsigned long long > multiply(vector<unsigned long long>& numbers, unsigned long long multiplier) {
    vector<unsigned long long > result;
     unsigned long long  carry = 0;

    // ضرب از اخرین دیتا
    for (int i = numbers.size() - 1; i >= 0; --i) {
        unsigned long long product = numbers[i] * multiplier + carry;


        // اضافه کردن عدد به اخر vdctor
        result.push_back(product % 10);
        carry = product / 10;
    }

    // Add final carry as most significant digit if non-zero
    if (carry) {
        result.push_back(carry);
    }

    // برعکس کردن vector
    reverse(result.begin(), result.end());

    return result;
}


int main() {
    int n;

    cout << "Enter a number for factorial: ";
    cin >> n;


    vector<unsigned long long > number = {1};
    for (int i = 2; i <= n; ++i) {
        number = multiply(number, i);
    }

    cout << "Factorial of " << n << " is: ";
    for (int i = 0; i < number.size(); ++i) {
        cout << number[i];
    }
    cout << endl;

    return 0;
}
