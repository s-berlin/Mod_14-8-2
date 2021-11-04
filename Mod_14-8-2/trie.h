#ifndef TRIE_H
#define TRIE_H

#include <string>
using namespace std;

const int ALPHABET_SIZE = 26;

// Структура узла дерева 
struct TrieNode
{
    string word;
    int path;
    struct TrieNode* children[ALPHABET_SIZE];
    // isEndOfWord - true, если ключ является концом слова
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
    // Добавление слова в словарь
    void insert(string str);
    // Поиск слов с префиксом str в словаре
    int search(TrieNode* root, string str);
    // Удаляем строку str
    void destory(TrieNode* root);
    // Распечатываем все узлы в дереве
    void printAll();
    // Вывести слова с префиксом str
    void printPre(string str);
    // Вывести нумерованный список слов с префиксом str
    void SelectWord(string str);
    // Выводим все слова с корнем в лексикографическом порядке
    void Print(TrieNode* root);
    // Выбор слова
    void Select(TrieNode* root);
     // Удаляем слово
    TrieNode* remove(TrieNode* root, string str, int debth);

};


#endif
