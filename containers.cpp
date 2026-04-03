// ============================================================
// Тема: Параметричний поліморфізм. Контейнери
// Відповіді на контрольні запитання з прикладами коду
// ============================================================

#include <iostream>
#include <complex>
#include <utility>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <iterator>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;


// ============================================================
// ЗАПИТАННЯ 1
// Які складові стандартної бібліотеки С++?
// ============================================================
/*
  Стандартна бібліотека С++ складається з:
  1. Бібліотека введення/виведення (iostream, fstream, sstream)
  2. Бібліотека рядків (string)
  3. Бібліотека контейнерів STL (vector, list, map, set, stack, queue тощо)
  4. Бібліотека алгоритмів (algorithm)
  5. Бібліотека ітераторів (iterator)
  6. Бібліотека функціональних об'єктів (functional)
  7. Бібліотека числових обчислень (complex, valarray, numeric)
  8. Бібліотека підтримки мови (new, typeinfo, exception, limits)
  9. Бібліотека локалізації (locale)
  10. Стандартна бібліотека С (успадкована: cmath, cstring, cstdlib тощо)
*/
void question1() {
    cout << "\n=== Запитання 1: Складові стандартної бібліотеки С++ ===\n";

    // iostream — введення/виведення
    cout << "iostream: " << 42 << endl;

    // string
    string s = "Стандартна бібліотека";
    cout << "string: " << s << endl;

    // algorithm
    vector<int> v = {5, 3, 1, 4, 2};
    sort(v.begin(), v.end());
    cout << "algorithm (sort): ";
    for (int x : v) cout << x << " ";
    cout << endl;

    // numeric (accumulate)
    // complex
    complex<double> c(3.0, 4.0);
    cout << "complex: |" << c << "| = " << abs(c) << endl;
}


// ============================================================
// ЗАПИТАННЯ 2
// Чи можливо в програмі на С++ використати бібліотеку С?
// ============================================================
/*
  Так, можливо. С++ повністю сумісний з С.
  Бібліотеки С доступні у двох варіантах:
  - Старий стиль: <stdio.h>, <math.h>, <string.h>, <stdlib.h>
  - С++ стиль:    <cstdio>, <cmath>, <cstring>, <cstdlib>
  Рекомендується використовувати варіант з префіксом "c" —
  він розміщує всі імена у просторі імен std.
*/
void question2() {
    cout << "\n=== Запитання 2: Використання бібліотеки С у С++ ===\n";

    // C-функція з <cmath>
    double x = sqrt(16.0);
    cout << "cmath sqrt(16) = " << x << endl;

    // C-функція з <cstring>
    char str[] = "Hello";
    cout << "cstring strlen = " << strlen(str) << endl;

    // C-функція з <cstdlib>
    int r = rand() % 100;
    cout << "cstdlib rand % 100 = " << r << endl;

    // C-функція з <cstdio>
    printf("cstdio printf: %d\n", 42);
}


// ============================================================
// ЗАПИТАННЯ 3
// Чим відрізняється клас complex від pair?
// ============================================================
/*
  complex<T>:
  - Призначений для роботи з комплексними числами (дійсна + уявна частина)
  - Має перевантажені арифметичні операції (+, -, *, /)
  - Має математичні функції: abs(), arg(), norm(), conj(), polar()
  - Обидві частини мають однаковий тип T
  - Доступ: real(), imag()

  pair<T1, T2>:
  - Загальна пара двох довільних значень різних типів
  - Немає математичних операцій
  - Використовується як універсальний контейнер двох значень
  - Доступ: first, second
  - Активно використовується у map як елемент (ключ + значення)
*/
void question3() {
    cout << "\n=== Запитання 3: complex vs pair ===\n";

    // complex — математичні операції
    complex<double> c1(3.0, 4.0), c2(1.0, 2.0);
    cout << "c1 = " << c1 << "  c2 = " << c2 << endl;
    cout << "c1 + c2 = " << c1 + c2 << endl;
    cout << "c1 * c2 = " << c1 * c2 << endl;
    cout << "|c1| = " << abs(c1) << endl;
    cout << "real(c1) = " << c1.real() << "  imag(c1) = " << c1.imag() << endl;

    // pair — два довільних значення різних типів
    pair<string, int> p1("вік", 20);
    pair<double, bool> p2(3.14, true);
    cout << "pair<string,int>: " << p1.first << " = " << p1.second << endl;
    cout << "pair<double,bool>: " << p2.first << " / " << p2.second << endl;

    // make_pair — зручне створення
    auto p3 = make_pair("score", 95);
    cout << "make_pair: " << p3.first << " = " << p3.second << endl;
}


// ============================================================
// ЗАПИТАННЯ 4
// Які типи символів підтримує клас string?
// ============================================================
/*
  Клас string є спеціалізацією шаблону basic_string<T>.
  Підтримувані типи символів:
  - char         → string    (однобайтні символи, ASCII/UTF-8)
  - wchar_t      → wstring   (широкі символи, Unicode, 2 або 4 байти)
  - char16_t     → u16string (Unicode UTF-16, C++11)
  - char32_t     → u32string (Unicode UTF-32, C++11)
  - char8_t      → u8string  (UTF-8, C++20)
*/
void question4() {
    cout << "\n=== Запитання 4: Типи символів у string ===\n";

    // char — звичайний рядок
    string s1 = "Hello, C++!";
    cout << "string (char):    " << s1 << "  довжина=" << s1.length() << endl;

    // wchar_t — широкі символи
    wstring s2 = L"Wide string";
    cout << "wstring (wchar_t): довжина=" << s2.length() << endl;

    // u16string — UTF-16
    u16string s3 = u"UTF-16 string";
    cout << "u16string: довжина=" << s3.length() << endl;

    // u32string — UTF-32
    u32string s4 = U"UTF-32 string";
    cout << "u32string: довжина=" << s4.length() << endl;
}


// ============================================================
// ЗАПИТАННЯ 5
// Що таке конкатенація?
// ============================================================
/*
  Конкатенація — це операція об'єднання (зчеплення) двох або більше рядків
  в один. У С++ для класу string конкатенація виконується за допомогою:
  - operator+   : str3 = str1 + str2
  - operator+=  : str1 += str2
  - метод append(): str1.append(str2)
  - метод push_back(): додає один символ у кінець
*/
void question5() {
    cout << "\n=== Запитання 5: Конкатенація рядків ===\n";

    string s1 = "Hello";
    string s2 = ", World";
    string s3 = "!";

    // operator+
    string result = s1 + s2 + s3;
    cout << "operator+:  " << result << endl;

    // operator+=
    string s4 = "C++";
    s4 += " is great";
    cout << "operator+=: " << s4 << endl;

    // append
    string s5 = "STL";
    s5.append(" containers");
    cout << "append():   " << s5 << endl;

    // push_back — додає один символ
    string s6 = "AB";
    s6.push_back('C');
    cout << "push_back(): " << s6 << endl;

    // конкатенація з C-рядком
    string s7 = "prefix_";
    s7 += "suffix";
    cout << "з C-рядком: " << s7 << endl;
}


// ============================================================
// ЗАПИТАННЯ 6
// Які відмінності size від capacity у класі vector?
// ============================================================
/*
  size() — поточна кількість елементів у векторі (скільки є зараз).
  capacity() — поточний обсяг виділеної пам'яті (скільки може вміститись
  без перерозподілу пам'яті).

  Завжди: size() <= capacity()

  Коли вектор заповнюється і size() досягає capacity(), відбувається
  автоматичне перерозподілення пам'яті — capacity() зазвичай подвоюється.
  Це дорога операція (копіювання всіх елементів).

  reserve(n) — заздалегідь виділяє пам'ять для n елементів,
  щоб уникнути зайвих перерозподілень.
*/
void question6() {
    cout << "\n=== Запитання 6: size vs capacity у vector ===\n";

    vector<int> v;
    cout << "Початок: size=" << v.size() << " capacity=" << v.capacity() << endl;

    for (int i = 1; i <= 10; i++) {
        v.push_back(i);
        cout << "push_back(" << i << "): size=" << v.size()
             << " capacity=" << v.capacity() << endl;
    }

    // reserve — виділяємо пам'ять наперед
    vector<int> v2;
    v2.reserve(20);
    cout << "\nПісля reserve(20): size=" << v2.size()
         << " capacity=" << v2.capacity() << endl;
    v2.push_back(1);
    cout << "Після push_back:   size=" << v2.size()
         << " capacity=" << v2.capacity() << endl;
}


// ============================================================
// ЗАПИТАННЯ 7
// Як запрограмувати двовимірний масив на основі vector?
// ============================================================
/*
  Двовимірний масив реалізується як vector<vector<T>> —
  вектор, елементами якого є вектори.
  Кожен рядок — окремий вектор, що може мати різну довжину.
  Доступ до елементу: matrix[i][j]
*/
void question7() {
    cout << "\n=== Запитання 7: Двовимірний масив на основі vector ===\n";

    int rows = 3, cols = 4;

    // Спосіб 1: ініціалізація нулями
    vector<vector<int>> matrix(rows, vector<int>(cols, 0));

    // Заповнення
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = i * cols + j + 1;

    // Виведення
    cout << "Матриця " << rows << "x" << cols << ":\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }

    // Спосіб 2: push_back рядків
    vector<vector<int>> m2;
    for (int i = 0; i < 3; i++) {
        vector<int> row;
        for (int j = 0; j < 3; j++)
            row.push_back(i * 3 + j);
        m2.push_back(row);
    }

    cout << "Матриця через push_back:\n";
    for (auto& row : m2) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }
}


// ============================================================
// ЗАПИТАННЯ 8
// Які недоліки контейнерів типу vector?
// ============================================================
/*
  Недоліки vector:
  1. Повільне вставлення/видалення в середині або на початку — O(n),
     бо треба зсувати всі наступні елементи.
  2. При перевищенні capacity відбувається перерозподіл пам'яті —
     всі елементи копіюються, всі ітератори стають недійсними.
  3. Неефективний для частих вставок/видалень не в кінці.
  4. Займає неперервний блок пам'яті — може бути проблемою
     при великих розмірах та фрагментованій пам'яті.

  Переваги (для порівняння):
  - Швидкий доступ до будь-якого елемента за індексом — O(1)
  - Ефективне додавання в кінець — амортизовано O(1)
  - Хороша кеш-локальність (елементи розміщені поряд у пам'яті)
*/
void question8() {
    cout << "\n=== Запитання 8: Недоліки vector ===\n";

    vector<int> v = {1, 2, 3, 4, 5};

    // Вставка на початку — O(n), всі елементи зсуваються
    auto start = v.begin();
    v.insert(start, 0);
    cout << "Після insert на початку: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    // Видалення з початку — теж O(n)
    v.erase(v.begin());
    cout << "Після erase початку:    ";
    for (int x : v) cout << x << " ";
    cout << endl;

    // Для частих вставок у середину — краще list
    list<int> lst = {1, 2, 3, 4, 5};
    auto it = lst.begin();
    advance(it, 2);
    lst.insert(it, 99); // O(1) після знаходження позиції
    cout << "list insert O(1): ";
    for (int x : lst) cout << x << " ";
    cout << endl;
}


// ============================================================
// ЗАПИТАННЯ 9
// Чим контейнер list відрізняється від vector?
// ============================================================
/*
  vector:
  - Неперервний блок пам'яті
  - Швидкий доступ за індексом O(1)
  - Повільне вставлення/видалення в середині O(n)
  - Ітератори стають недійсними при перерозподілі пам'яті

  list (двонаправлений список):
  - Елементи розкидані по пам'яті, з'єднані вказівниками
  - Немає доступу за індексом (тільки через ітератор — O(n))
  - Швидке вставлення/видалення в будь-якому місці O(1)
    (якщо є ітератор на позицію)
  - Ітератори залишаються дійсними після вставки/видалення
  - Більше пам'яті на елемент (два вказівника: prev і next)
*/
void question9() {
    cout << "\n=== Запитання 9: list vs vector ===\n";

    // vector — швидкий доступ за індексом
    vector<int> v = {10, 20, 30, 40, 50};
    cout << "vector[2] = " << v[2] << " (O(1))\n";

    // list — немає operator[]
    list<int> lst = {10, 20, 30, 40, 50};
    auto it = lst.begin();
    advance(it, 2); // O(n) — треба пройти по вказівниках
    cout << "list advance(2) = " << *it << " (O(n))\n";

    // list — швидке вставлення в середину
    lst.insert(it, 99);
    cout << "list після insert: ";
    for (int x : lst) cout << x << " ";
    cout << endl;

    // list — методи яких немає у vector
    lst.push_front(0);   // додати на початок
    lst.sort();          // вбудоване сортування
    lst.unique();        // видалити дублікати
    cout << "list після sort+unique: ";
    for (int x : lst) cout << x << " ";
    cout << endl;
}


// ============================================================
// ЗАПИТАННЯ 10
// Що таке асоціативний контейнер?
// ============================================================
/*
  Асоціативний контейнер — це контейнер, що зберігає елементи
  у відсортованому вигляді та забезпечує швидкий пошук за ключем.
  Зберігається як збалансоване бінарне дерево (зазвичай червоно-чорне).
  Пошук, вставка, видалення — O(log n).

  Асоціативні контейнери STL:
  - set<K>         — множина унікальних ключів
  - multiset<K>    — множина з повтореннями
  - map<K,V>       — словник унікальних пар ключ-значення
  - multimap<K,V>  — словник з повтореннями ключів

  На відміну від vector/list — елементи завжди відсортовані,
  немає доступу за числовим індексом.
*/
void question10() {
    cout << "\n=== Запитання 10: Асоціативний контейнер ===\n";

    // set — унікальні відсортовані елементи
    set<int> s = {5, 3, 8, 1, 3, 5, 9};
    cout << "set (унікальні, відсортовані): ";
    for (int x : s) cout << x << " ";
    cout << endl;

    // пошук у set — O(log n)
    if (s.find(8) != s.end())
        cout << "8 знайдено у set\n";

    // map — ключ → значення
    map<string, int> m;
    m["один"] = 1;
    m["два"]  = 2;
    m["три"]  = 3;
    cout << "map: ";
    for (auto& p : m) cout << p.first << "=" << p.second << " ";
    cout << endl;
}


// ============================================================
// ЗАПИТАННЯ 11
// Навіщо у контейнерах map зберігаються пари?
// ============================================================
/*
  У map кожен елемент — це пара pair<const Key, Value>,
  де Key — ключ для пошуку, Value — асоційоване значення.

  Причини зберігання саме пар:
  1. Забезпечує зв'язок між ключем і даними в одному елементі.
  2. Ключ використовується для сортування та пошуку (const — незмінний).
  3. Значення можна читати і змінювати через ітератор (it->second).
  4. Пара дозволяє зберігати різнотипні ключі та значення.

  Доступ: it->first (ключ), it->second (значення)
  Або через operator[]: m["ключ"] = значення
*/
void question11() {
    cout << "\n=== Запитання 11: Пари у map ===\n";

    map<string, double> prices;

    // Вставка через пару
    prices.insert(pair<string, double>("яблуко", 25.5));
    prices.insert(make_pair("банан", 18.0));
    prices["апельсин"] = 32.0;

    // Виведення пар
    cout << "Ціни:\n";
    for (auto& p : prices)
        cout << "  " << p.first << " -> " << p.second << " грн\n";

    // Пошук і зміна значення
    auto it = prices.find("банан");
    if (it != prices.end()) {
        cout << "Ціна банана: " << it->second << endl;
        it->second = 20.0; // змінюємо значення (не ключ!)
        cout << "Нова ціна:   " << it->second << endl;
    }
}


// ============================================================
// ЗАПИТАННЯ 12
// Що означає суфікс _if?
// ============================================================
/*
  Суфікс _if в назвах алгоритмів STL означає, що алгоритм приймає
  предикат (функцію або функціональний об'єкт, що повертає bool)
  і застосовує операцію тільки до тих елементів, для яких
  предикат повертає true.

  Приклади:
  - find()     — шукає конкретне значення
  - find_if()  — шукає перший елемент, для якого предикат = true
  - count()    — рахує елементи рівні значенню
  - count_if() — рахує елементи, для яких предикат = true
  - remove_if()   — видаляє елементи, для яких предикат = true
  - copy_if()     — копіює елементи, для яких предикат = true
  - replace_if()  — замінює елементи, для яких предикат = true
*/
void question12() {
    cout << "\n=== Запитання 12: Суфікс _if ===\n";

    vector<int> v = {1, 5, 3, 8, 2, 9, 4, 7, 6};

    // find — шукає конкретне значення
    auto it1 = find(v.begin(), v.end(), 8);
    cout << "find(8): " << *it1 << endl;

    // find_if — шукає перший елемент > 6
    auto it2 = find_if(v.begin(), v.end(), [](int x){ return x > 6; });
    cout << "find_if(x>6): " << *it2 << endl;

    // count — скільки елементів == 5
    int c1 = count(v.begin(), v.end(), 5);
    cout << "count(5): " << c1 << endl;

    // count_if — скільки парних
    int c2 = count_if(v.begin(), v.end(), [](int x){ return x % 2 == 0; });
    cout << "count_if(парних): " << c2 << endl;

    // copy_if — копіюємо тільки елементи > 5
    vector<int> result;
    copy_if(v.begin(), v.end(), back_inserter(result),
            [](int x){ return x > 5; });
    cout << "copy_if(x>5): ";
    for (int x : result) cout << x << " ";
    cout << endl;
}


// ============================================================
// ЗАПИТАННЯ 13
// Що таке ітератор? Наведіть приклади.
// ============================================================
/*
  Ітератор — це об'єкт, що надає уніфікований спосіб доступу
  до елементів контейнера незалежно від його типу.
  Ітератор поводиться як вказівник: підтримує операції
  *, ++, --, ==, !=, а для деяких типів — +, -, [].

  Типи ітераторів:
  - Input iterator        — тільки читання, однонапрямлений
  - Output iterator       — тільки запис, однонапрямлений
  - Forward iterator      — читання/запис, однонапрямлений (forward_list)
  - Bidirectional iterator — читання/запис, двонапрямлений (list, map, set)
  - Random access iterator — повний доступ + арифметика (vector, deque)
  - Reverse iterator      — обхід у зворотньому напрямку
*/
void question13() {
    cout << "\n=== Запитання 13: Ітератори ===\n";

    vector<int> v = {10, 20, 30, 40, 50};

    // Звичайний ітератор
    cout << "Прямий обхід: ";
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    cout << endl;

    // Зворотній ітератор
    cout << "Зворотній обхід: ";
    for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
        cout << *it << " ";
    cout << endl;

    // Константний ітератор (тільки читання)
    cout << "const_iterator: ";
    for (vector<int>::const_iterator it = v.cbegin(); it != v.cend(); ++it)
        cout << *it << " ";
    cout << endl;

    // Арифметика ітераторів (random access)
    auto it = v.begin();
    it += 2;
    cout << "begin() + 2 = " << *it << endl;
    cout << "end() - begin() = " << (v.end() - v.begin()) << endl;

    // Ітератор списку (bidirectional — немає +)
    list<int> lst = {1, 2, 3, 4, 5};
    list<int>::iterator lit = lst.begin();
    ++lit; ++lit;
    cout << "list iterator (advance 2): " << *lit << endl;

    // auto — спрощений синтаксис
    cout << "auto iterator: ";
    for (auto it2 = v.begin(); it2 != v.end(); ++it2)
        cout << *it2 << " ";
    cout << endl;
}


// ============================================================
// ЗАПИТАННЯ 14
// Що таке функціональний об'єкт (функтор)?
// ============================================================
/*
  Функціональний об'єкт (функтор) — це об'єкт класу, у якого
  перевантажено operator(). Завдяки цьому він може викликатись
  як звичайна функція, але при цьому може зберігати стан.

  Переваги функторів над звичайними функціями:
  1. Можуть зберігати стан між викликами (через поля класу)
  2. Можуть бути параметризовані через конструктор
  3. Компілятор може їх краще оптимізувати (inline)

  Стандартні функтори STL (у <functional>):
  - negate<T>      — унарний мінус
  - plus<T>        — додавання
  - minus<T>       — віднімання
  - multiplies<T>  — множення
  - divides<T>     — ділення
  - greater<T>     — порівняння >
  - less<T>        — порівняння <
*/

// Власний функтор — множення на константу
class MultiplyBy {
    int factor;
public:
    MultiplyBy(int f) : factor(f) {}
    int operator()(int x) const { return x * factor; }
};

// Функтор — підрахунок викликів
class Counter {
    int count;
public:
    Counter() : count(0) {}
    void operator()(int) { count++; }
    int getCount() const { return count; }
};

void question14() {
    cout << "\n=== Запитання 14: Функціональний об'єкт ===\n";

    vector<int> v = {1, 2, 3, 4, 5};

    // Власний функтор
    MultiplyBy times3(3);
    cout << "MultiplyBy(3)(5) = " << times3(5) << endl;

    // Використання з transform
    vector<int> result(v.size());
    transform(v.begin(), v.end(), result.begin(), MultiplyBy(10));
    cout << "transform з MultiplyBy(10): ";
    for (int x : result) cout << x << " ";
    cout << endl;

    // Стандартний функтор greater<int> для сортування за спаданням
    vector<int> v2 = {5, 3, 8, 1, 9};
    sort(v2.begin(), v2.end(), greater<int>());
    cout << "sort(greater<int>): ";
    for (int x : v2) cout << x << " ";
    cout << endl;

    // negate — заперечення
    transform(v.begin(), v.end(), result.begin(), negate<int>());
    cout << "transform(negate): ";
    for (int x : result) cout << x << " ";
    cout << endl;

    // Лямбда як функтор (C++11)
    auto square = [](int x) { return x * x; };
    transform(v.begin(), v.end(), result.begin(), square);
    cout << "transform(lambda x^2): ";
    for (int x : result) cout << x << " ";
    cout << endl;
}


// ============================================================
// ЗАПИТАННЯ 15
// Чим відрізняється count_if від find_if?
// ============================================================
/*
  count_if(first, last, pred):
  - Повертає КІЛЬКІСТЬ елементів, для яких предикат = true
  - Завжди проходить весь діапазон
  - Повертає тип ptrdiff_t (ціле число)
  - Використовується: "скільки елементів відповідають умові?"

  find_if(first, last, pred):
  - Повертає ІТЕРАТОР на ПЕРШИЙ елемент, для якого предикат = true
  - Зупиняється одразу після знаходження першого елемента
  - Повертає end() якщо нічого не знайдено
  - Використовується: "знайти перший елемент, що відповідає умові"
*/
void question15() {
    cout << "\n=== Запитання 15: count_if vs find_if ===\n";

    vector<int> v = {1, 7, 3, 9, 2, 8, 4, 6, 5};
    auto isEven = [](int x) { return x % 2 == 0; };
    auto isBig  = [](int x) { return x > 6; };

    // count_if — кількість
    int cnt = count_if(v.begin(), v.end(), isEven);
    cout << "count_if(парних): " << cnt << endl;

    cnt = count_if(v.begin(), v.end(), isBig);
    cout << "count_if(x>6):    " << cnt << endl;

    // find_if — перший елемент
    auto it1 = find_if(v.begin(), v.end(), isEven);
    if (it1 != v.end())
        cout << "find_if(перший парний): " << *it1
             << " на позиції " << distance(v.begin(), it1) << endl;

    auto it2 = find_if(v.begin(), v.end(), isBig);
    if (it2 != v.end())
        cout << "find_if(перший x>6):   " << *it2
             << " на позиції " << distance(v.begin(), it2) << endl;

    // find_if_not — перший що НЕ відповідає
    auto it3 = find_if_not(v.begin(), v.end(), isBig);
    cout << "find_if_not(x>6):      " << *it3 << endl;
}


// ============================================================
// ЗАПИТАННЯ 16
// Що робить алгоритм for_each?
// ============================================================
/*
  for_each(first, last, func) — застосовує функцію func до кожного
  елемента в діапазоні [first, last).

  Відмінності від звичайного циклу for:
  - Більш лаконічний запис
  - Функція може бути функтором зі збереженням стану
  - for_each повертає функцію (func) після завершення —
    можна отримати накопичений стан функтора

  Відмінності від transform:
  - transform створює новий результат (запис у інший контейнер)
  - for_each тільки застосовує функцію, не змінює контейнер
    (хоча функція може модифікувати елементи через посилання)
*/
void question16() {
    cout << "\n=== Запитання 16: Алгоритм for_each ===\n";

    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // for_each для виведення
    cout << "for_each (виведення): ";
    for_each(v.begin(), v.end(), [](int x){ cout << x << " "; });
    cout << endl;

    // for_each для модифікації
    for_each(v.begin(), v.end(), [](int& x){ x *= 2; });
    cout << "for_each (x*=2):      ";
    for (int x : v) cout << x << " ";
    cout << endl;

    // for_each з функтором — накопичення суми
    struct Summer {
        int sum = 0;
        void operator()(int x) { sum += x; }
    };

    Summer s = for_each(v.begin(), v.end(), Summer());
    cout << "for_each (сума):      " << s.sum << endl;

    // for_each тільки для парних елементів (через copy_if + for_each)
    vector<int> evens;
    copy_if(v.begin(), v.end(), back_inserter(evens),
            [](int x){ return x % 4 == 0; });
    cout << "for_each (кратні 4):  ";
    for_each(evens.begin(), evens.end(), [](int x){ cout << x << " "; });
    cout << endl;
}


// ============================================================
// ГОЛОВНА ФУНКЦІЯ
// ============================================================
int main() {
    question1();
    question2();
    question3();
    question4();
    question5();
    question6();
    question7();
    question8();
    question9();
    question10();
    question11();
    question12();
    question13();
    question14();
    question15();
    question16();

    cout << "\n=== Програма завершена ===\n";
    return 0;
}
