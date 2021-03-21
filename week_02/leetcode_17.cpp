class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return rest;
        map<char, string> book;
        book['2'] = "abc";
        book['3'] = "def";
        book['4'] = "ghi";
        book['5'] = "jkl";
        book['6'] = "mno";
        book['7'] = "pqrs";
        book['8'] = "tuv";
        book['9'] = "wxyz";

        string item;
        recursion(digits, book, 0, item);
        return rest;
    }

    void recursion(string &digits, map<char, string> &book, int idx, string &item) {
        if (idx == digits.size()) {
            rest.push_back(item);
        }

        string letters = book[digits[idx]];
        for (char c : letters) {
            item.push_back(c);
            recursion(digits, book, idx + 1, item);
            item.pop_back();
        }
    }

private:
    vector<string> rest;
};