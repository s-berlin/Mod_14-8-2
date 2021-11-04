#ifndef TRIE_H
#define TRIE_H

#include <string>
using namespace std;

const int ALPHABET_SIZE = 26;

// ��������� ���� ������ 
struct TrieNode
{
    string word;
    int path;
    struct TrieNode* children[ALPHABET_SIZE];
    // isEndOfWord - true, ���� ���� �������� ������ �����
    bool isEndOfWord;
    TrieNode()
    {
        word = "";
        path = 0;
        isEndOfWord = false;
        memset(children, NULL, sizeof(TrieNode*) * ALPHABET_SIZE);
    }
};

TrieNode* getNewNode(void);
//bool search(TrieNode*, string);
bool isEmpty(TrieNode*);

class TrieTree {
public:
    TrieNode* root;
    TrieTree();
    ~TrieTree();
    // ���������� ����� � �������
    void insert(string str);
    // ����� ���� � ��������� str � �������
    int search(TrieNode* root, string str);
    // ������� ������ str
    void destory(TrieNode* root);
    // ������������� ��� ���� � ������
    void printAll();
    // ������� ����� � ��������� str
    void printPre(string str);
    // ������� ������������ ������ ���� � ��������� str
    void SelectWord(string str);
    // ������� ��� ����� � ������ � ������������������ �������
    void Print(TrieNode* root);
    // ����� �����
    void Select(TrieNode* root);
     // ������� �����
    TrieNode* remove(TrieNode* root, string str, int debth);

};


#endif
