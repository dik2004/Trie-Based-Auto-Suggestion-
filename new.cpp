#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>
#include <algorithm> 

using namespace std;

class TrieNode {
public:
    map<char, TrieNode*> children;
    bool isEnd = false;
};

class Trie {
    TrieNode* root;
    int suggestionLimit = 100;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children[ch])
                node->children[ch] = new TrieNode();
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    void suggestions(TrieNode* node, string prefix, vector<string>& result) {
        if (result.size() >= suggestionLimit) return;
        if (node->isEnd) result.push_back(prefix);
        for (auto& it : node->children) {
            if (result.size() >= suggestionLimit) return;
            suggestions(it.second, prefix + it.first, result);
        }
    }

    vector<string> getSuggestions(const string& prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            if (!node->children[ch]) return {};
            node = node->children[ch];
        }
        vector<string> result;
        suggestions(node, prefix, result);
        return result;
    }
};

int main() {

    cout << "Content-type: text/html\n\n";

   
    string query = getenv("QUERY_STRING") ? getenv("QUERY_STRING") : "";
    string prefix = "";
    size_t pos = query.find("=");
    if (pos != string::npos)
        prefix = query.substr(pos + 1);

   
    transform(prefix.begin(), prefix.end(), prefix.begin(), ::tolower);

    Trie trie;
    ifstream file("words.txt");

    if (!file.is_open()) {
        cout << "<p style='color:red;'>Error: Could not open words.txt</p>";
        return 1;
    }

    string word;
    int count = 0;
    while (getline(file, word)) {
        if (!word.empty()) {
            transform(word.begin(), word.end(), word.begin(), ::tolower); 
            trie.insert(word);
            count++;
            if (count > 5000) break; 
        }
    }

    vector<string> suggestions = trie.getSuggestions(prefix);

    if (suggestions.empty()) {
        cout << "<p>No suggestions found for '" << prefix << "'</p>";
    } else {
        cout << "<ul>";
        for (const string& s : suggestions)
            cout << "<li>" << s << "</li>";
        cout << "</ul>";
    }

    cout.flush(); 
    return 0;
}
