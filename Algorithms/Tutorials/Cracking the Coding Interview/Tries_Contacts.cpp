// https://www.hackerrank.com/challenges/ctci-contacts

#include <map>
#include <iostream>

using namespace std;

struct Node {
    Node() : useCount(0) {}
    
    map<char, Node> children;
    int useCount;
};

void addWord(Node &node, const string &word, int index) {
    node.useCount++;
    
    if (index < word.size())
        addWord(node.children[word[index]], word, index + 1);
}

int getWordCount(Node &node, const string &prefix, int index) {
    if (index < prefix.size()) {
        if (node.children.find(prefix[index]) != node.children.cend()) {
            return getWordCount(node.children[prefix[index]], prefix, index + 1);
        }
        else {
            return 0;
        }
    }
    else {
        return node.useCount;
    }
}

int main(){
    int n;
    cin >> n;
    
    Node root;

    for(int a0 = 0; a0 < n; a0++){
        string op;
        string contact;
        cin >> op >> contact;
        
        if (op == "add") {
            addWord(root, contact, 0);
        }
        else {
            cout << getWordCount(root, contact, 0) << endl;
        }
    }
    return 0;
}
