#include <iostream>
//#include <bits/stdc++.h>
#include "trie.h"

// глобальные переменные 
extern int j;      // порядковый номер строки с заданным префиксом
extern int k;      // выбранный номер строки с заданным префиксом
extern string selStr;  // выбранная строка с заданным префиксом


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

    //    Создание словаря
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

    cout << "Словарь: " << endl;
    j = 1;
    trie.printAll();

    while (nf != 0) {
        cout << "Выберите действие: 1 - добавить слово, 2 - удалить слово, 3 - показать словарь, 4 - ввод текста, 0 - выход)" << endl;
        cin >> nf;
        switch (nf) {
        case 0:
            break;
        case 1:
            cout << "Добавить: ";
            cin >> str;
            trie.insert(str);
            break;
        case 2:
            cout << "Удалить: ";
            cin >> str;
            trie.remove(trie.root, str, 0);
            break;
        case 3:
            cout << "Словарь: " << endl;
            j = 1;
            trie.printAll();
            break;
        case 4:
            cout << endl << "При вводе текста после ввода каждого символа нужно нажать Enter" << endl;
            cout << "Если в словаре есть подходяшие слова с введенным префиксом, то они выводятся пронумерованным списком" << endl;
            cout << "Затем выводится уже введенный текст, можно продолжить ввод или ввести номер выбранного слова, чтобы добавить его целиком" << endl;
            cout << "Для разделения слов вводится _ (подчерк), который затем заменяется в тексте пробелом " << endl;
            cout << "Можно удалить последний символ текста, если ввести < Enter" << endl;
            cout << "Для завершения работы введите: . Enter" << endl;
            cout << endl << "Вводите текст: " << endl;

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
