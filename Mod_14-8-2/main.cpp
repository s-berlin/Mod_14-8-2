#include <iostream>
//#include <bits/stdc++.h>
#include "trie.h"

// ���������� ���������� 
extern int j;      // ���������� ����� ������ � �������� ���������
extern int k;      // ��������� ����� ������ � �������� ���������
extern string selStr;  // ��������� ������ � �������� ���������


using namespace std;

int main()
{
    int nf = 1;
    char symb = ' ';
    string word = "";
    string text = "";
    string selWord = "";

    setlocale(LC_ALL, "");

    TrieTree trie;

    //    �������� �������
    string str = "mama";
    //   cout << trie.search(str) << endl;
    trie.insert(str);
    str = "mila";
    trie.insert(str);
    str = "mylo";
    trie.insert(str);
    str = "myla";
    trie.insert(str);
    str = "window";
    trie.insert(str);

    cout << "�������: " << endl;
    j = 1;
    trie.printAll();

    while (nf != 0) {
        cout << "�������� ��������: 1 - �������� �����, 2 - ������� �����, 3 - �������� �������, 4 - ���� ������, 0 - �����)" << endl;
        cin >> nf;
        switch (nf) {
        case 0:
            break;
        case 1:
            cout << "��������: ";
            cin >> str;
            trie.insert(str);
            break;
        case 2:
            cout << "�������: ";
            cin >> str;
            trie.remove(trie.root, str, 0);
            break;
        case 3:
            cout << "�������: " << endl;
            j = 1;
            trie.printAll();
            break;
        case 4:
            cout << endl << "��� ����� ������ ����� ����� ������� ������� ����� ������ Enter" << endl;
            cout << "���� � ������� ���� ���������� ����� � ��������� ���������, �� ��� ��������� ��������������� �������" << endl;
            cout << "����� ��������� ��� ��������� �����, ����� ���������� ���� ��� ������ ����� ���������� �����, ����� �������� ��� �������" << endl;
            cout << "��� ���������� ���� �������� _ (�������), ������� ����� ���������� � ������ �������� " << endl;
            cout << "����� ������� ��������� ������ ������, ���� ������ < Enter" << endl;
            cout << "��� ���������� ������ �������: . Enter" << endl;
            cout << endl << "������� �����: " << endl;

            while (symb != '.')
            {
                cin >> symb;
                if (symb == '<')
                {
                    word.erase(word.size() - 1);
                    j = 1;
                    selStr = "";
                }
                if (symb == '_')
                {
                    text += word;
                    text += " ";
                    word = "";
                    j = 1;
                    selStr = "";
                }

                if (symb > '0' && symb <= '9') {
                    k = symb - '0';
                    j = 1;
                    trie.SelectWord(word);
                    word = selStr;

                }
                if (symb >= 'a' and symb <= 'z') {
                    word += symb;

                    j = 1;
                    trie.printPre(word);
                }
                cout << text << word;

            }
            break;
        default:
            break;
        }
    }



    return 0;
}
