// ============================================================
// Тема: Бібліотека стандартних шаблонів (STL)
// ============================================================
// Завдання 1 (стор. 157):
// Написати шаблонну функцію створення, заповнення,
// сортування і виведення значень динамічного вектора.
// + Самостійна робота (listings 2-34, стор. 158-177)
// ============================================================

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <algorithm>
#include <functional>
#include <iterator>
#include <valarray>
#include <bitset>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
using namespace std;


// ============================================================
// ЗАВДАННЯ 1 (стор. 157)
// Шаблонна функція створення, заповнення, сортування
// і виведення значень динамічного вектора
// ============================================================

// Заповнення вектора випадковими значеннями
template <typename T>
void fillVector(vector<T>& v, int n) {
    v.clear();
    for (int i = 0; i < n; i++)
        v.push_back(static_cast<T>(rand() % 100));
}

// Спеціалізація для double — значення від 0.0 до 1.0
template <>
void fillVector<double>(vector<double>& v, int n) {
    v.clear();
    for (int i = 0; i < n; i++)
        v.push_back(static_cast<double>(rand()) / RAND_MAX * 100.0);
}

// Виведення вектора
template <typename T>
void printVector(const vector<T>& v, const string& label = "") {
    if (!label.empty()) cout << label << ": ";
    for (size_t i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

// Сортування вектора за зростанням
template <typename T>
void sortVector(vector<T>& v) {
    sort(v.begin(), v.end());
}

// Шаблонна функція — повний цикл: створення, заповнення, сортування, виведення
template <typename T>
void processVector(int n) {
    vector<T> v;
    fillVector(v, n);
    printVector(v, "До сортування  ");
    sortVector(v);
    printVector(v, "Після сортування");
    cout << "Мін: " << *min_element(v.begin(), v.end())
         << "  Макс: " << *max_element(v.begin(), v.end()) << endl;
}

void task1() {
    cout << "\n=== ЗАВДАННЯ 1: Шаблонна функція вектора ===\n";

    cout << "\n--- vector<int> (n=8) ---\n";
    processVector<int>(8);

    cout << "\n--- vector<double> (n=6) ---\n";
    processVector<double>(6);

    cout << "\n--- vector<char> (n=8) ---\n";
    vector<char> vc;
    for (int i = 0; i < 8; i++) vc.push_back('a' + rand() % 26);
    printVector(vc, "До сортування  ");
    sortVector(vc);
    printVector(vc, "Після сортування");
}


// ============================================================
// САМОСТІЙНА РОБОТА
// ============================================================

// --- Listing 2: основні операції над векторами ---
void listing2() {
    cout << "\n--- Listing 2: основні операції над векторами ---\n";
    vector<char> v(10);
    unsigned int i;

    cout << "Розмір = " << v.size() << endl;

    for (i = 0; i < 10; i++) v[i] = i + 'a';

    cout << "Поточний вміст:\n";
    for (i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << "\n\n";

    cout << "Розширений вектор\n";
    for (i = 0; i < 10; i++) v.push_back(i + 10 + 'a');

    cout << "Новий розмір = " << v.size() << endl;
    cout << "Поточний вміст:\n";
    for (i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << "\n\n";

    for (i = 0; i < v.size(); i++) v[i] = toupper(v[i]);
    cout << "Модифікований вміст:\n";
    for (i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;
}

// --- Listing 3: доступ до елементів вектора через ітератор ---
void listing3() {
    cout << "\n--- Listing 3: ітератор вектора ---\n";
    vector<char> v(10);
    vector<char>::iterator p;
    int i;

    p = v.begin(); i = 0;
    while (p != v.end()) { *p = i + 'a'; p++; i++; }

    cout << "Початковий вміст:\n";
    p = v.begin();
    while (p != v.end()) { cout << *p << " "; p++; }
    cout << "\n\n";

    p = v.begin();
    while (p != v.end()) { *p = toupper(*p); p++; }

    cout << "Модифікований вміст:\n";
    p = v.begin();
    while (p != v.end()) { cout << *p << " "; p++; }
    cout << endl;
}

// --- Listing 4: функції вставки і вилучення ---
void listing4() {
    cout << "\n--- Listing 4: вставка і вилучення у векторі ---\n";
    vector<char> v(10), v2;
    char str[] = "<Vector>";
    unsigned int i;

    for (i = 0; i < 10; i++) v[i] = i + 'a';
    for (i = 0; str[i]; i++) v2.push_back(str[i]);

    cout << "Початковий вміст v:\n";
    for (i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << "\n\n";

    vector<char>::iterator p = v.begin();
    p += 2;
    v.insert(p, 10, 'X');

    cout << "Розмір після вставки = " << v.size() << endl;
    cout << "Вміст після вставки:\n";
    for (i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << "\n\n";

    p = v.begin(); p += 2;
    v.erase(p, p + 10);

    cout << "Розмір після вилучення = " << v.size() << endl;
    cout << "Вміст після вилучення:\n";
    for (i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << "\n\n";

    p = v.begin(); p += 2;
    v.insert(p, v2.begin(), v2.end());
    cout << "Розмір після вставки вектора v2 = " << v.size() << endl;
    cout << "Вміст після вставки вектора v2:\n";
    for (i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;
}

// --- Listing 5: вектор об'єктів класу ---
class DailyTemp {
    int temp;
public:
    DailyTemp() { temp = 0; }
    DailyTemp(int x) { temp = x; }
    DailyTemp& operator=(int x) { temp = x; return *this; }
    double get_temp() { return temp; }
};
bool operator<(DailyTemp a, DailyTemp b) { return a.get_temp() < b.get_temp(); }
bool operator==(DailyTemp a, DailyTemp b) { return a.get_temp() == b.get_temp(); }

void listing5() {
    cout << "\n--- Listing 5: вектор об'єктів класу DailyTemp ---\n";
    vector<DailyTemp> v;
    unsigned int i;

    for (i = 0; i < 7; i++) v.push_back(DailyTemp(60 + rand() % 30));

    cout << "Температура по Фаренгейту:\n";
    for (i = 0; i < v.size(); i++) cout << v[i].get_temp() << " ";
    cout << endl;

    for (i = 0; i < v.size(); i++)
        v[i] = (int)((v[i].get_temp() - 32) * 5 / 9);

    cout << "Температура в градусах Цельсія:\n";
    for (i = 0; i < v.size(); i++) cout << v[i].get_temp() << " ";
    cout << endl;
}

// --- Listing 6: операції над списком ---
void listing6() {
    cout << "\n--- Listing 6: операції над списком ---\n";
    list<int> lst;
    int i;

    for (i = 0; i < 10; i++) lst.push_back(i);
    cout << "Розмір = " << lst.size() << endl;
    cout << "Вміст: ";
    list<int>::iterator p = lst.begin();
    while (p != lst.end()) { cout << *p << " "; p++; }
    cout << "\n\n";

    p = lst.begin();
    while (p != lst.end()) { *p = *p + 100; p++; }

    cout << "Модифікований вміст: ";
    p = lst.begin();
    while (p != lst.end()) { cout << *p << " "; p++; }
    cout << endl;
}

// --- Listing 8: виведення списку в прямому і зворотньому порядку ---
void listing8() {
    cout << "\n--- Listing 8: список прямо і зворотньо ---\n";
    list<int> lst;
    int i;

    for (i = 0; i < 10; i++) lst.push_back(i);

    cout << "Прямий порядок:\n";
    list<int>::iterator p = lst.begin();
    while (p != lst.end()) { cout << *p << " "; p++; }
    cout << "\n\n";

    cout << "Зворотній порядок:\n";
    p = lst.end();
    while (p != lst.begin()) { p--; cout << *p << " "; }
    cout << endl;
}

// --- Listing 9: push_back і push_front ---
void listing9() {
    cout << "\n--- Listing 9: push_back і push_front ---\n";
    list<int> lst1, lst2;
    int i;

    for (i = 0; i < 10; i++) lst1.push_back(i);
    for (i = 0; i < 10; i++) lst2.push_front(i);

    cout << "Вміст lst1 (push_back):\n";
    list<int>::iterator p = lst1.begin();
    while (p != lst1.end()) { cout << *p << " "; p++; }
    cout << "\n\n";

    cout << "Вміст lst2 (push_front):\n";
    p = lst2.begin();
    while (p != lst2.end()) { cout << *p << " "; p++; }
    cout << endl;
}

// --- Listing 10: сортування списку ---
void listing10() {
    cout << "\n--- Listing 10: сортування списку ---\n";
    list<int> lst;
    int i;

    for (i = 0; i < 10; i++) lst.push_back(rand() % 100);

    cout << "Початковий вміст:\n";
    list<int>::iterator p = lst.begin();
    while (p != lst.end()) { cout << *p << " "; p++; }
    cout << "\n\n";

    lst.sort();

    cout << "Відсортований вміст:\n";
    p = lst.begin();
    while (p != lst.end()) { cout << *p << " "; p++; }
    cout << endl;
}

// --- Listing 11: злиття двох списків ---
void listing11() {
    cout << "\n--- Listing 11: злиття списків ---\n";
    list<int> lst1, lst2;
    int i;

    for (i = 0; i < 10; i += 2) lst1.push_back(i);
    for (i = 1; i < 11; i += 2) lst2.push_back(i);

    cout << "lst1: ";
    list<int>::iterator p = lst1.begin();
    while (p != lst1.end()) { cout << *p << " "; p++; }
    cout << "\nlst2: ";
    p = lst2.begin();
    while (p != lst2.end()) { cout << *p << " "; p++; }
    cout << "\n\n";

    lst1.merge(lst2);
    if (lst2.empty()) cout << "lst2 тепер порожній\n";

    cout << "lst1 після злиття:\n";
    p = lst1.begin();
    while (p != lst1.end()) { cout << *p << " "; p++; }
    cout << endl;
}

// --- Listing 13: асоціативний масив (map) ---
void listing13() {
    cout << "\n--- Listing 13: map<char,int> ASCII-коди ---\n";
    map<char, int> m;
    int i;

    for (i = 0; i < 26; i++) m.insert(pair<char, int>('A' + i, 65 + i));

    char ch = 'F';
    map<char, int>::iterator p = m.find(ch);
    if (p != m.end())
        cout << "ASCII-код '" << ch << "' = " << p->second << endl;
    else
        cout << "Ключ не знайдений.\n";
}

// --- Listing 16: алгоритм count() ---
void listing16() {
    cout << "\n--- Listing 16: алгоритм count() ---\n";
    vector<bool> v;
    unsigned int i;

    for (i = 0; i < 10; i++) {
        if (rand() % 2) v.push_back(true);
        else v.push_back(false);
    }

    cout << "Послідовність:\n";
    for (i = 0; i < v.size(); i++) cout << boolalpha << v[i] << " ";
    cout << endl;

    i = count(v.begin(), v.end(), true);
    cout << "Кількість <true>: " << i << endl;
}

// --- Listing 17: алгоритм count_if() ---
bool dividesBy3(int i) { return (i % 3) == 0; }

void listing17() {
    cout << "\n--- Listing 17: алгоритм count_if() ---\n";
    vector<int> v;
    unsigned int i;

    for (i = 1; i < 20; i++) v.push_back(i);

    cout << "Послідовність:\n";
    for (i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;

    i = count_if(v.begin(), v.end(), dividesBy3);
    cout << "Кратних 3: " << i << endl;
}

// --- Listing 18: remove_copy і replace_copy ---
void listing18() {
    cout << "\n--- Listing 18: remove_copy і replace_copy ---\n";
    char str[] = "Shablony STL mayut veliki mozhlyvosti";
    int i;
    vector<char> v, v2(80);

    for (i = 0; str[i]; i++) v.push_back(str[i]);

    cout << "Початкова послідовність:\n";
    for (i = 0; i < (int)v.size(); i++) cout << v[i];
    cout << endl;

    fill(v2.begin(), v2.end(), '\0');
    remove_copy(v.begin(), v.end(), v2.begin(), ' ');
    cout << "Без пропусків:\n";
    for (i = 0; i < (int)v2.size() && v2[i]; i++) cout << v2[i];
    cout << "\n\n";

    fill(v2.begin(), v2.end(), '\0');
    replace_copy(v.begin(), v.end(), v2.begin(), ' ', ':');
    cout << "Пропуски -> двокрапки:\n";
    for (i = 0; i < (int)v2.size() && v2[i]; i++) cout << v2[i];
    cout << endl;
}

// --- Listing 19: алгоритм reverse ---
void listing19() {
    cout << "\n--- Listing 19: алгоритм reverse ---\n";
    vector<int> v;
    unsigned int i;

    for (i = 0; i < 10; i++) v.push_back(i);

    cout << "Початкова: ";
    for (i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;

    reverse(v.begin(), v.end());

    cout << "Зворотня:  ";
    for (i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;
}

// --- Listing 20: алгоритм transform ---
double reciprocal(double i) { return 1.0 / i; }

void listing20() {
    cout << "\n--- Listing 20: алгоритм transform ---\n";
    list<double> vals;
    int i;

    for (i = 1; i < 10; i++) vals.push_back((double)i);

    cout << "Початковий вміст:\n";
    list<double>::iterator p = vals.begin();
    while (p != vals.end()) { cout << *p << " "; p++; }
    cout << endl;

    transform(vals.begin(), vals.end(), vals.begin(), reciprocal);

    cout << "Після transform (1/x):\n";
    p = vals.begin();
    while (p != vals.end()) { cout << *p << " "; p++; }
    cout << endl;
}

// --- Listing 22: унарний функтор negate ---
void listing22() {
    cout << "\n--- Listing 22: унарний функтор negate ---\n";
    list<double> vals;
    int i;

    for (i = 1; i < 10; i++) vals.push_back((double)i);

    cout << "Початковий вміст:\n";
    list<double>::iterator p = vals.begin();
    while (p != vals.end()) { cout << *p << " "; p++; }
    cout << endl;

    transform(vals.begin(), vals.end(), vals.begin(), negate<double>());

    cout << "Після negate:\n";
    p = vals.begin();
    while (p != vals.end()) { cout << *p << " "; p++; }
    cout << endl;
}

// --- Listing 23: бінарний функтор divides ---
void listing23() {
    cout << "\n--- Listing 23: бінарний функтор divides ---\n";
    list<double> vals, divisors;
    int i;

    for (i = 10; i < 100; i += 10) vals.push_back((double)i);
    for (i = 1; i < 10; i++) divisors.push_back(3.0);

    cout << "Початковий вміст vals:\n";
    list<double>::iterator p = vals.begin();
    while (p != vals.end()) { cout << *p << " "; p++; }
    cout << endl;

    transform(vals.begin(), vals.end(),
              divisors.begin(), vals.begin(),
              divides<double>());

    cout << "Після ділення на 3:\n";
    p = vals.begin();
    while (p != vals.end()) { cout << *p << " "; p++; }
    cout << endl;
}

// --- Listing 30: клас string ---
void listing30() {
    cout << "\n--- Listing 30: клас string ---\n";
    string str1("Alpha"), str2("Beta"), str3("Omega"), str4;

    str4 = str1;
    cout << str1 << "\n" << str3 << "\n";

    str4 = str1 + str2;
    cout << str4 << "\n";

    str4 = str1 + " to " + str3;
    cout << str4 << "\n";

    if (str3 > str1) cout << "str3 > str1\n";

    str1 = "Рядок символів у стилі C++.\n";
    cout << str1;

    string str5(str1);
    cout << str5;
}

// --- Listing 31: insert, erase, replace ---
void listing31() {
    cout << "\n--- Listing 31: insert, erase, replace у string ---\n";
    string str1("1234567 рядки символів.");
    string str2("#POWER STL#");

    cout << "str1: " << str1 << "\nstr2: " << str2 << "\n\n";

    str1.insert(7, str2);
    cout << "Після insert:\n" << str1 << "\n\n";

    str1.erase(7, 11);
    cout << "Після erase:\n" << str1 << "\n\n";

    str1.replace(7, 11, str2);
    cout << "Після replace:\n" << str1 << endl;
}

// --- Listing 32: пошук у рядку ---
void listing32() {
    cout << "\n--- Listing 32: пошук у string ---\n";
    string s1 = "Швидкий думкою Сильний тілом Гарячий серцем";
    string s2;
    int i;

    i = s1.find("Сильний");
    if (i != (int)string::npos) {
        cout << "Знайдено 'Сильний' на позиції " << i << endl;
        s2.assign(s1, i, s1.size());
        cout << "Залишок: " << s2 << "\n\n";
    }

    i = s1.rfind(" ");
    if (i != (int)string::npos) {
        cout << "Остання пробіл на позиції " << i << endl;
        s2.assign(s1, i + 1, s1.size());
        cout << "Останнє слово: " << s2 << endl;
    }
}

// --- Listing 33: string як контейнер ---
void listing33() {
    cout << "\n--- Listing 33: string як контейнер ---\n";
    string str1("Obrobka Strings-ryadkiv v C++ duze prosta");
    string::iterator p;
    unsigned int i;

    for (i = 0; i < str1.size(); i++) cout << str1[i];
    cout << endl;

    p = str1.begin();
    while (p != str1.end()) cout << *p++;
    cout << endl;

    i = count(str1.begin(), str1.end(), 'i');
    cout << "Кількість символів 'i': " << i << endl;

    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    p = str1.begin();
    while (p != str1.end()) cout << *p++;
    cout << endl;
}

// --- Listing 34: map<string,string> телефонна книга ---
void listing34() {
    cout << "\n--- Listing 34: телефонна книга map<string,string> ---\n";
    map<string, string> directory;
    directory.insert(pair<string, string>("Ivan",   "555-4533"));
    directory.insert(pair<string, string>("Petro",  "555-9678"));
    directory.insert(pair<string, string>("Olena",  "555-8195"));
    directory.insert(pair<string, string>("Mykola", "555-0809"));

    string s = "Olena";
    map<string, string>::iterator p = directory.find(s);
    if (p != directory.end())
        cout << "Номер телефону " << s << ": " << p->second << endl;
    else
        cout << "Ім'я не знайдено.\n";

    cout << "Весь довідник:\n";
    for (p = directory.begin(); p != directory.end(); p++)
        cout << "  " << p->first << " -> " << p->second << endl;
}


// ============================================================
// ГОЛОВНА ФУНКЦІЯ
// ============================================================
int main() {
    srand(42); // фіксоване зерно для відтворюваності результатів

    // Завдання 1
    task1();

    // Самостійна робота
    cout << "\n\n=== САМОСТІЙНА РОБОТА (listings) ===";

    listing2();
    listing3();
    listing4();
    listing5();
    listing6();
    listing8();
    listing9();
    listing10();
    listing11();
    listing13();
    listing16();
    listing17();
    listing18();
    listing19();
    listing20();
    listing22();
    listing23();
    listing30();
    listing31();
    listing32();
    listing33();
    listing34();

    cout << "\n=== Програма завершена ===\n";
    return 0;
}


// ============================================================
// ВІДПОВІДІ НА ЗАПИТАННЯ (стор. 157)
// ============================================================
/*
1. Які елементи входять до складу STL?
   Контейнер, ітератор, алгоритм, алокатор, функтор, предикат, адаптор.

2. Контейнер, ітератор, алгоритм. Типи ітераторів.
   Контейнер — об'єкт для зберігання колекції об'єктів (vector, list, map тощо).
   Ітератор — об'єкт для доступу до елементів контейнера, аналог вказівника;
   підтримує операції *, ++, --, ==, !=.
   Методи begin()/end() повертають ітератори на початок та кінець.
   Типи ітераторів: однонапрямлений, двонапрямлений, введення, виведення,
   довільного доступу, зворотний.
   Алгоритм — параметризована функція для обробки елементів контейнерів
   (sort, find, copy, remove, count тощо). Підключається через <algorithm>.

3. Алокатор, функтор, предикат, адаптор.
   Алокатор — керує динамічною пам'яттю STL-об'єктів.
   Функтор — клас з перевантаженим operator(), використовується замість
   вказівника на функцію (negate<T>, divides<T>, greater<T> тощо).
   Предикат — булева функція для перевірки властивостей елементів;
   унарний (один аргумент) або бінарний (два аргументи).
   Адаптор — пристосовує існуючий контейнер до іншого інтерфейсу
   (stack на основі vector, queue на основі deque).

4. Шаблонний клас string і його методи.
   string — спеціалізація basic_string<char> для роботи з рядками символів.
   Основні методи: insert(ofs,s), erase(ofs,n), substr(ofs,n), find(s,ofs),
   append(s), compare(), clear(), length()/size(), replace(ofs,n,s),
   push_back(c), c_str(), resize(n,ch).

5. Переваги і недоліки string.
   Переваги: автоматичне керування пам'яттю, зручне об'єднання через +,
   безпечне порівняння (==, <, >), великий набір методів, відсутність
   переповнення буфера.
   Недоліки: повільніше за char[] через динамічну пам'ять, більший обсяг
   пам'яті, несумісність з С-API без c_str().

6. Шаблонний клас vector і його методи.
   vector<T> — динамічний масив з автоматичним керуванням пам'яттю.
   Методи: push_back(), pop_back(), insert(iter,x), erase(iter),
   size(), capacity(), resize(n,x), reserve(n), clear(), empty(),
   front(), back(), at(i), begin(), end().

7. Алгоритми для роботи з колекціями.
   min_element(), max_element() — пошук мінімуму/максимуму.
   find() — пошук елемента.
   sort() — сортування.
   copy() — копіювання елементів.
   remove(), remove_copy() — вилучення елементів.
   count(), count_if() — підрахунок елементів.
   reverse() — реверс послідовності.
   transform() — перетворення елементів.
   replace_copy() — заміна елементів при копіюванні.

8. Масив значень valarray і його методи.
   valarray<T> — масив для математичних обчислень.
   Підтримує поелементні арифметичні операції (+,-,*,/),
   математичні функції (sin, cos, sqrt, abs тощо).
   Методи: size(), resize(n), min(), max(), sum(),
   shift(ofs), slice(beg,count,end).

9. Стек і його методи.
   stack<T> — LIFO контейнер (за замовчуванням на основі deque).
   Методи: push(x) — занести, pop() — вилучити, top() — прочитати верхній,
   size(), empty().

10. Список і його методи.
    list<T> — двонаправлений список.
    Методи: push_back(), push_front(), pop_back(), pop_front(),
    begin(), end(), insert(iter,x), erase(iter), remove(x),
    clear(), merge(lst), sort(), resize(n), size().

11. Черги, деки та їх методи.
    queue<T> — FIFO черга (на основі deque).
    Методи: push(x), pop(), front(), back(), size(), empty().
    deque<T> — черга з двома кінцями.
    Методи: push_front(x), push_back(x), pop_front(), pop_back(),
    front(), back(), begin(), end(), insert(iter,x), erase(iter),
    clear(), size(), resize(n), empty().

12. Асоціативні відображення.
    map<K,V> — словник пар ключ-значення без повторень, зберігається
    як бінарне дерево. Пара значень — об'єкт pair<K,V> (поля first, second).
    Методи: insert(), find(key), begin(), end(), erase(), clear(),
    count(key), lower_bound(key), upper_bound(key), empty().
    multimap<K,V> — допускає повторення ключів.

13. Множини і множини бітів.
    set<T> — множина унікальних елементів (бінарне дерево).
    Методи: insert(), find(), begin(), end(), erase(), clear(), count(), size().
    multiset<T> — множина з повтореннями.
    bitset<N> — множина бітів фіксованого розміру N.
    Методи: test(n), set(n), reset(), flip(n), any(), none(),
    count(), size(), to_string(), to_ulong().
    Перевантажені операції: &, |, ^, ~, <<, >>, ==, !=, [].
*/
