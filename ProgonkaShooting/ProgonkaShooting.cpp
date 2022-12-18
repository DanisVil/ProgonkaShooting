#include <iostream>
#include <math.h>
#include <vector>
#include <stack>
#include <map>

using namespace std;

void matrix89() {
    const int m = 10;
    int matrix[m][m];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % 10;
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "--------------------\n";

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

void arr70() {
    const int n = 8;
    int nums[n];
    for (int i = 0; i < n; i++) {
        nums[i] = rand() % 100;
        cout << nums[i] << " ";
    }
    cout << "\n--------------------\n";
    for (int i = 0; i < n / 2; i++) {
        int temp = nums[i];
        nums[i] = nums[i + n /2];
        nums[i + n / 2] = temp;
    }
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
}

bool is_palindrom(int num) {
    int reverse = 0;
    for (int i = num; i != 0; i = i / 10) {
        reverse = i % 10 + reverse * 10;
    }
    if (num == reverse) return true;
    return false;
}

void ab563() {
    vector<int> palindroms;
    for (int i = 0; i < 100; i++) { //a
        if (is_palindrom(i * i)) {
            palindroms.push_back(i);
            cout << i << " ";
        }
    }
    cout << "\n";
    for (int i = 0; i < palindroms.size(); i++) {
        if (is_palindrom(palindroms[i])) {
            cout << palindroms[i] << " ";
        }
    }
}

bool str98n3() {
    string seq = "[(){}[]{()[]}]";
    stack<char> s; // тут  хранятся только открывающиеся скобки
    for (int i = 0; i < seq.size(); i++) {
        if (s.size() == 0 && (seq[i] == ')' || seq[i] == ']' || seq[i] == '}')) {
            cout << "not right";
            return false;
        }
        if (seq[i] == '(' || seq[i] == '[' || seq[i] == '{')
            s.push(seq[i]);
        else if (seq[i] == ')' && s.top() == '(')
            s.pop();
        else if (seq[i] == ']' && s.top() == '[')
            s.pop();
        else if (seq[i] == '}' && s.top() == '{')
            s.pop();
        else {
            cout << "not right";
            return false;
        }
    }
    cout << "right";
    return true;
}

struct Node {
    string val;
    Node* previous;

    Node(string _val) : val(_val), previous(nullptr) {}
};

struct list {
private:
    Node* first;
    Node* last;
public:

    list() : first(nullptr), last(nullptr) {}

    bool is_empty() {
        return first == nullptr;
    }

    void push(string _val) {
        Node* p = new Node(_val);
        if (is_empty()) {
            first = p;
            last = p;
            return;
        }
        p->previous = last;
        last = p;
    }
    string top() {
        if (is_empty()) return NULL;
        return last->val;
    }

    void pop() {
        if (is_empty()) return;
        Node* p = last;
        if (first == last) {
            first = nullptr;
        }
        last = p->previous;
        delete p;
    }

    vector<string> to_string() {
        vector<string> out;
        if (is_empty()) return out;
        Node* p = last;
        while (p) {
            out.push_back(p->val);
            p = p->previous;
        }
        delete p;
        return out;
    }
};

void str93n12() {
    list s;
    s.push("Students");
    s.push("of");
    s.push("the");
    s.push("group");
    s.push("TE");
    vector<string> ans = s.to_string();
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i][0] == 't')
            cout << ans[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    s.pop();
    cout << "\n";
    ans = s.to_string();
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

void a808() {
    string text = "slovo slovo slovo petya popugai computer petya animal pink machine animal petya petya";

    map<string, int> count;

    size_t pos = 0;
    string token;
    string delimiter = " ";
    while ((pos = text.find(delimiter)) != std::string::npos) {
        token = text.substr(0, pos);
        if (token != "" && count.find(token) == count.end()) {
            count.insert(make_pair(token, 1));
        }
        else if (token != "" && count.find(token) != count.end()) {
            count[token]++;
        }
        text.erase(0, pos + delimiter.length());
    }
    token = text;
    if (token != "" && count.find(token) == count.end()) {
        count.insert(make_pair(token, 1));
    }
    else if (token != "" && count.find(token) != count.end()) {
        count[token]++;
    }
    map <string, int> ::iterator it = count.begin();
    for (map <string, int> ::iterator it = count.begin(); it != count.end(); it++) {  // выводим их
        cout << it->first << ": " << it->second << endl;
    }
}

void spirale(int matrix[][7]) {
    int i, j;
    static int m_max = 7, n_max = 7;
    static int m_min = 1, n_min = 0;
    static int i_save = 0, j_save = 0;
    static int value = 1;

    for (i = i_save, j = j_save; j < n_max; j++) {
        matrix[i][j] = value++;
    }
    j_save = --j;
    ++i_save;
    for (i = i_save, j = j_save; i < m_max; i++) {
        matrix[i][j] = value++;
    }
    i_save = --i;
    --j_save;
    for (i = i_save, j = j_save; j >= n_min; j--) {
        matrix[i][j] = value++;
    }
    j_save = ++j;
    --i_save;
    for (i = i_save, j = j_save; i >= m_min; i--) {
        matrix[i][j] = value++;
    }
    i_save = ++i;
    ++j_save;

    --m_max;
    --n_max;
    ++m_min;
    ++n_min;

    if (value <= 49) {
        spirale(matrix);
    }
}

void t689() {
    const int n = 7;
    int matrix[n][n];
    spirale(matrix);
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 7; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

}

int main()
{
    t689();
}