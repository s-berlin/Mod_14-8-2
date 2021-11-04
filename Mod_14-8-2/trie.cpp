#include <iostream>
//#include <bits/stdc++.h>
#include "trie.h"

using namespace std;

// ���������� ���������� 
int j = 1;      // ���������� ����� ������ � �������� ���������
int k = 1;      // ��������� ����� ������ � �������� ���������
string selStr;  // ��������� ������ � �������� ���������

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



// ��������� ����� ���� � ������� ������
TrieNode* getNewNode(void)
{
    // �������� ������ �� ����� ����
    struct TrieNode* pNode = new TrieNode;

    // ������������� ���� ����� ����� � false
    pNode->isEndOfWord = false;

    // �������������� ����� ������� ���������
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = nullptr;

    return pNode;
}


// ��������� ���� � ������, ���� ��� ���, 
// ����� ���� ���� ������� �������� ���� ������ 
// �������� � �������� �������� �.�. ����� �����
void TrieTree::insert(string key)
{
    TrieNode* node = root;

    for (int i = 0; i < key.length(); i++)
    {
        // ��������� ������ � ������ ����� �������� ������������ ������ �����
        int index = key[i] - 'a';

        // ���� ��������� �������, �.�. ����� � ����� ��������� ���
        // ������� ����� ����
        if (!node->children[index])
            node->children[index] = getNewNode();

        node = node->children[index];
    }

    node->word = key;
    // �������� ��������� ����� ��� ����, �.�. ����� �����
    node->isEndOfWord = true;
    node->path++;// ����� ���� ���� ���� ����
}

// ���������� true ���� ���� ���� � ������, ����� false 
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

// ���������� true ���� root ����� ����, ����� false 
bool isEmpty(TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}

// ����������� ������� �������� ����� �� ������ 
//TrieNode* remove(TrieNode* root, string key, int depth)
TrieNode* TrieTree::remove(TrieNode* root, string key, int depth)
{
    // ���� ������ ������ 
   if (!root)
        return nullptr;

    // ���� ����� �� ����� ����� 
    if (depth == key.size()) {

        // ���� ���� ������ �� ����� ����� 
        if (root->isEndOfWord)
            root->isEndOfWord = false;

        // ���� ���� �� �������� ���������, ������� ���
        if (isEmpty(root)) {
            delete (root);
            root = nullptr;
        }

        return root;
    }

    // ���� �� ����� �� ����� �����, ���������� �������� ��� ������� 
    // ���������������� ������� 
    int index = key[depth] - 'a';
    root->children[index] = remove(root->children[index], key, depth + 1);

    // ���� � ����� ��� ��������� ����� 
    // (������ ������ ���� ��� �������� �������), 
    // � �� �� ������������� ������ ������. 
    if (isEmpty(root) && root->isEndOfWord == false) {
        delete (root);
        root = nullptr;
    }

    // ���������� ����� ������
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


