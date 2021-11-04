#include <iostream>
//#include <bits/stdc++.h>
#include "trie.h"

using namespace std;

// глобальные переменные 
int j = 1;      // порядковый номер строки с заданным префиксом
int k = 1;      // выбранный номер строки с заданным префиксом
string selStr;  // выбранная строка с заданным префиксом

TrieTree::TrieTree()
{
    root = new TrieNode();
}


TrieTree::~TrieTree()
{
    destory(root);
}

void TrieTree::destory(TrieNode* root)
{
    if (root == nullptr)
        return;
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        destory(root->children[i]);
    }
    delete root;
    root = nullptr;
}



// Возвращет новый узел с пустыми детьми
TrieNode* getNewNode(void)
{
    // Выделяем память по новый узел
    struct TrieNode* pNode = new TrieNode;

    // устанавливаем флаг конца слова в false
    pNode->isEndOfWord = false;

    // инициализируем детей нулевым уазателем
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = nullptr;

    return pNode;
}


// Вставляет ключ в дерево, если его нет, 
// иначе если ключ явлется префксом узла дерева 
// помечает в качестве литового т.е. конец слова
void TrieTree::insert(string key)
{
    TrieNode* node = root;

    for (int i = 0; i < key.length(); i++)
    {
        // вычисляем индекс в алфите через смещение отнситьельно первой буквы
        int index = key[i] - 'a';

        // если указатель пустрой, т.е. детей с таким префиксом нет
        // создаем новый узел
        if (!node->children[index])
            node->children[index] = getNewNode();

        node = node->children[index];
    }

    node->word = key;
    // помечаем последний узлел как лист, т.е. конец слова
    node->isEndOfWord = true;
    node->path++;// Через этот узел есть путь
}

// Возврашает true если ключ есть в дереве, иначе false 
bool search(struct TrieNode* root, string key)
{
    struct TrieNode* node = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!node->children[index])
            return false;

        node = node->children[index];
    }

    return (node != nullptr && node->isEndOfWord);
}

// Вохвращает true если root имеет лист, иначе false 
bool isEmpty(TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}

// Рекурсивная функция удаления ключа из дерева 
//TrieNode* remove(TrieNode* root, string key, int depth)
TrieNode* TrieTree::remove(TrieNode* root, string key, int depth)
{
    // Если дерево пустое 
   if (!root)
        return nullptr;

    // если дошли до конца ключа 
    if (depth == key.size()) {

        // Этот узел больше не конец слова 
        if (root->isEndOfWord)
            root->isEndOfWord = false;

        // Если ключ не евляется префиксом, удаляем его
        if (isEmpty(root)) {
            delete (root);
            root = nullptr;
        }

        return root;
    }

    // Если не дошли до конца ключа, рекурсивно вызываем для ребенка 
    // соответствующего символа 
    int index = key[depth] - 'a';
    root->children[index] = remove(root->children[index], key, depth + 1);

    // Если у корня нет дочернего слова 
    // (удален только один его дочерний элемент), 
    // и он не заканчивается другим словом. 
    if (isEmpty(root) && root->isEndOfWord == false) {
        delete (root);
        root = nullptr;
    }

    // возвращаем новый корень
    return root;
}

void TrieTree::printPre(string str)
{
    int j = 0;
    if (str == "")
        return;
    char buf[sizeof(str)];
    strcpy_s(buf, str.c_str());
    TrieNode* node = root;
    int index = 0;
    for (int i = 0; i < strlen(buf); i++)
    {
        index = buf[i] - 'a';
        if (node->children[index] == nullptr)
        {
            return;
        }
        node = node->children[index];
    }
    Print(node);
}

void TrieTree::Print(TrieNode* node)
{
    if (node == nullptr)
        return;
    if (node->word != "")
    {
        cout << j << "   " << node->word << endl;
        j++;
    }
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        Print(node->children[i]);
    }
}


void TrieTree::printAll()
{
    Print(root);
}

void TrieTree::SelectWord(string str)
{
    if (str == "")
        return;
    char buf[sizeof(str)];
    strcpy_s(buf, str.c_str());
    TrieNode* node = root;
    int index = 0;
    for (int i = 0; i < strlen(buf); i++)
    {
        index = buf[i] - 'a';
        if (node->children[index] == nullptr)
        {
            return;
        }
        node = node->children[index];
    }
    Select(node);
}

void TrieTree::Select(TrieNode* node)
{
    if (node == nullptr)
        return;
    if (node->word != "" && selStr == "")
    {
        if (j == k) {
            selStr = node->word;
            j++;
            return;
        }
        j++;
    }

    if (selStr == "") {
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            Select(node->children[i]);
        }
    }

}


