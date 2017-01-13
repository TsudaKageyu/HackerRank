// https://www.hackerrank.com/domains/data-structures/trie

#include <iostream>
#include <memory>
#include <unordered_map>

using namespace std;

struct Node {
    unordered_map<char, shared_ptr<Node>> next;
};

bool addString(shared_ptr<Node> root, string s) {
    const char Termination = '*';
    
    auto node = root;
    bool nodeCreated = false;
    for (auto c : s) {
        if (!node->next[c]) {
            node->next[c] = make_shared<Node>();
            nodeCreated = true;
        }
        node = node->next[c];
        if (node->next.find(Termination) != node->next.end())
            return false;
    }
    node->next[Termination];
    
    return nodeCreated;
}

int main() {
    int n;
    cin >> n;
    
    auto root = make_shared<Node>();
    string badString;
    while (n--) {
        string s;
        cin >> s;
        
        if (!addString(root, s)) {
            badString = s;
            break;
        }
    }
    
    if (badString.empty())
        cout << "GOOD SET" << endl;
    else
        cout << "BAD SET" << endl << badString << endl;
    
    return 0;
}
