#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//az alábbi megoldás a szavakat felcseréli, de a betûket is
/*void reverseStr(string& str)
{
    int n = str.length();

    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}


int main()
{
    string s;
    getline(cin, s);
    reverseStr(s);
    cout << s;
    return 0;
}*/
//az alábbi megoldás a betûket felcseréli, de a szavakat nem, azok maradnak a helyükön
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        reverseWordss(s);
        return getString(s);
    }
    string getString(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (s[i] == ' ' && i < s.size()) i++;
        while (j >= 0 && s[j] == ' ') j--;
        string ret = "";
        for (; i <= j; i++) {
            if (ret.size() && ret.back() == ' ' && s[i] == ' ')continue;
            ret += s[i];
        }
        return ret;
    }
    void reverseWordss(string& s) {
        int j = 0;
        for (int i = 0; i < s.size(); i = j) {
            if (s[i] == ' ') {
                j = i + 1;
            }
            else {
                while (j + 1 < s.size() && s[j + 1] != ' ') j++;
                int x = i;
                int y = j;
                while (x < y) {
                    swap(s[x], s[y]);
                    x++;
                    y--;
                }
                j++;
            }
        }
    }
};
int main() {
    Solution ob;
    string s;
    getline(cin, s);
    ob.reverseWordss(s);
    cout << s;
    return 0;
}