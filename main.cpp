#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <cctype>

using namespace std;

int romanToInteger(const string &s) {
// map each roman numeral to its integer value
static const unordered_map <char, int> values {
    {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
};

int total = 0;
for(size_t i = 0; i < s.size(); ++i) {
    int v = values.at(s[i]);
    //if this is followed by a larger one, subtract it
    if(i + 1 < s.size() && values.at(s[i+1]) > v) {
        total -= v;
    } else{
        total += v;
    }
}
return total;
}

int main(){
    string roman;
    cout << "Enter a roman numeral: ";
    getline(cin, roman);
//convert string input to uppercase    
transform (
  roman.begin(), roman.end(), roman.begin(),
  [](unsigned char c){ return toupper(c); }
);
    int result = romanToInteger(roman);
    cout << "Integer value: " << result << endl;
    return 0;
    }
