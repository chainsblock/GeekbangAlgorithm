class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        set<int> column, p , q;
        vector<int> item;
        solve(0, n, item, column, p, q);
        return formatRest();
    }

    void solve(int row, int n, vector<int> &item, set<int> &column, set<int> &p, set<int> &q) {
        if (row == n) {
            rest.push_back(item);
        }

        for (int i = 0; i < n; ++i) {
            if (column.count(i) > 0) {
                continue;
            }
            if (p.count(row + i) > 0) {
                continue;
            }
            if (q.count(row - i) > 0) {
                continue;
            }

            item.push_back(i);
            column.insert(i);
            p.insert(row + i);
            q.insert(row - i);

            solve(row + 1, n, item, column, p, q);

            item.pop_back();
            column.erase(i);
            p.erase(row + i);
            q.erase(row - i);
        }
    }

    vector<vector<string>> formatRest() {
        vector<vector<string>> ans;
        for (vector<int> &item : rest) {
            vector<string> ans_item;
            for (int &i : item) {
                string line;
                for (int j = 0; j < item.size(); ++j) {
                    if (j == i) {
                        line.push_back('Q');
                    } else {
                        line.push_back('.');
                    }
                }
                ans_item.push_back(line);
            }
            ans.push_back(ans_item);
        }
        return ans;
    }

private:
    vector<vector<int>> rest;
};