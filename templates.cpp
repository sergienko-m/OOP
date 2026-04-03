// ============================================================
// Лабораторна робота
// Тема: Параметричний поліморфізм. Шаблони
// ============================================================
// ВІДПОВІДІ НА ЗАПИТАННЯ З ПРИКЛАДАМИ КОДУ
// ============================================================

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>
using namespace std;


// ============================================================
// ПИТАННЯ 1
// Узагальнене програмування та параметризований клас
// ============================================================
/*
  УЗАГАЛЬНЕНЕ ПРОГРАМУВАННЯ (Generic Programming) — це стиль програмування,
  при якому алгоритми та структури даних записуються у загальному вигляді,
  без прив'язки до конкретного типу даних. Конкретний тип підставляється
  пізніше — при використанні.

  ПАРАМЕТРИЗОВАНИЙ КЛАС (шаблонний клас) — це клас, визначений з одним або
  кількома параметрами-типами. При використанні такого класу параметр-тип
  замінюється конкретним типом (int, double, string тощо), і компілятор
  генерує відповідну версію класу автоматично.
*/

// Приклад параметризованого класу — контейнер для пари значень
template <typename T>
class Pair {
    T first, second;
public:
    Pair(T a, T b) : first(a), second(b) {}
    T getFirst()  const { return first; }
    T getSecond() const { return second; }
    T max()       const { return (first > second) ? first : second; }
};

void question1() {
    cout << "\n=== Питання 1: Узагальнене програмування ===\n";
    Pair<int>    pi(3, 7);
    Pair<double> pd(3.14, 2.71);
    Pair<string> ps("hello", "world");

    cout << "Pair<int>:    max = " << pi.max()    << endl;
    cout << "Pair<double>: max = " << pd.max()    << endl;
    cout << "Pair<string>: max = " << ps.max()    << endl;
}


// ============================================================
// ПИТАННЯ 2
// Шаблонний клас Точка в N-вимірному просторі
// ============================================================

template <typename T, int N>
class PointND {
    T coords[N];
public:
    PointND() {
        for (int i = 0; i < N; i++) coords[i] = T(0);
    }
    PointND(T values[N]) {
        for (int i = 0; i < N; i++) coords[i] = values[i];
    }
    void set(int i, T val) { coords[i] = val; }
    T    get(int i)  const { return coords[i]; }

    // Відстань від початку координат
    double length() const {
        double sum = 0;
        for (int i = 0; i < N; i++) sum += (double)coords[i] * coords[i];
        return sqrt(sum);
    }

    // Відстань до іншої точки
    double distanceTo(const PointND<T,N>& other) const {
        double sum = 0;
        for (int i = 0; i < N; i++) {
            double d = coords[i] - other.coords[i];
            sum += d * d;
        }
        return sqrt(sum);
    }

    void print() const {
        cout << "(";
        for (int i = 0; i < N; i++) {
            cout << coords[i];
            if (i < N-1) cout << ", ";
        }
        cout << ")";
    }
};

void question2() {
    cout << "\n=== Питання 2: Точка в N-вимірному просторі ===\n";

    // 2D точка з int
    PointND<int, 2> p2d;
    p2d.set(0, 3); p2d.set(1, 4);
    cout << "2D int точка: "; p2d.print();
    cout << ", довжина = " << p2d.length() << endl;

    // 3D точка з double
    PointND<double, 3> p3d;
    p3d.set(0, 1.0); p3d.set(1, 2.0); p3d.set(2, 3.0);
    cout << "3D double точка: "; p3d.print();
    cout << ", довжина = " << p3d.length() << endl;

    // 4D точка
    PointND<double, 4> p4a, p4b;
    p4a.set(0,1); p4a.set(1,2); p4a.set(2,3); p4a.set(3,4);
    p4b.set(0,4); p4b.set(1,3); p4b.set(2,2); p4b.set(3,1);
    cout << "Відстань між 4D точками: " << p4a.distanceTo(p4b) << endl;
}


// ============================================================
// ПИТАННЯ 3
// Типи, що можна використовувати як фактичний параметр-тип
// ============================================================
/*
  Як фактичний параметр-тип шаблону можна використовувати:
  1. Вбудовані типи:     int, double, char, bool, float тощо
  2. Вказівники:         int*, double*, char*
  3. Посилання:          int&, const string&
  4. Класи і структури:  будь-який клас (у т.ч. власний)
  5. Інші шаблони:       vector<int>, pair<int,double>
  6. Перелічення (enum)
  7. Цілочисельні константи як нетипові параметри: template<int N>

  ОБМЕЖЕННЯ (залежно від шаблону):
  - Якщо шаблон використовує operator<, тип повинен його підтримувати
  - Якщо шаблон копіює об'єкти, тип повинен мати копіювальний конструктор
*/

template <typename T>
T myMax(T a, T b) { return (a > b) ? a : b; }

void question3() {
    cout << "\n=== Питання 3: Типи як фактичний параметр ===\n";
    cout << "myMax<int>(3,7)        = " << myMax<int>(3, 7)           << endl;
    cout << "myMax<double>(3.1,2.7) = " << myMax<double>(3.1, 2.7)    << endl;
    cout << "myMax<char>('a','z')   = " << myMax<char>('a', 'z')      << endl;
    cout << "myMax<string>(...)     = " << myMax<string>("apple","banana") << endl;
}


// ============================================================
// ПИТАННЯ 4
// Обмеження на класи як фактичні параметри шаблону
// ============================================================
/*
  Формальних обмежень немає — будь-який клас може бути фактичним параметром.
  АЛЕ є неявні вимоги, що визначаються тілом шаблону:

  1. Якщо шаблон викликає конструктор без аргументів — клас повинен його мати.
  2. Якщо шаблон використовує operator<, ==, > — клас повинен їх перевантажити.
  3. Якщо шаблон копіює об'єкти — клас повинен підтримувати копіювання.
  4. Якщо шаблон виводить об'єкти через cout — клас повинен мати operator<<.

  Починаючи з C++20 ці вимоги формалізуються за допомогою концептів (concepts).
*/

class MyPoint {
public:
    double x, y;
    MyPoint(double x=0, double y=0) : x(x), y(y) {}
    bool operator<(const MyPoint& o) const {
        return (x*x + y*y) < (o.x*o.x + o.y*o.y);
    }
    bool operator>(const MyPoint& o) const {
        return (x*x + y*y) > (o.x*o.x + o.y*o.y);
    }
    friend ostream& operator<<(ostream& os, const MyPoint& p) {
        return os << "(" << p.x << "," << p.y << ")";
    }
};

void question4() {
    cout << "\n=== Питання 4: Обмеження на класи як параметри ===\n";
    // MyPoint підтримує operator< та operator<< — тому працює з myMax
    MyPoint p1(3, 4), p2(1, 1);
    cout << "myMax<MyPoint>: " << myMax(p1, p2) << endl;
}


// ============================================================
// ПИТАННЯ 5
// Відмінність звичайного і інстанційованого класу;
// шаблонного і нешаблонного
// ============================================================
/*
  ЗВИЧАЙНИЙ клас — конкретний тип, визначений одразу для певних типів даних.
  ІНСТАНЦІЙОВАНИЙ клас — конкретна версія шаблону, отримана підстановкою
  фактичного типу: Stack<int>, Stack<double> — це два різних класи.

  Відмінності:
  - Звичайний клас існує в одному екземплярі коду.
  - Кожне інстанціювання шаблону породжує окремий клас з власним кодом.
  - Синтаксис: звичайний — Stack s; інстанційований — Stack<int> s;

  ШАБЛОННИЙ клас — узагальнений, без прив'язки до типу, код генерується
  компілятором при кожному новому інстанціюванні.
  НЕШАБЛОННИЙ клас — конкретний, компілюється один раз.
*/

// Шаблонний стек
template <typename T>
class Stack {
    T data[100];
    int top;
public:
    Stack() : top(0) {}
    void push(T val) { data[top++] = val; }
    T    pop()       { return data[--top]; }
    bool empty()     { return top == 0; }
    int  size()      { return top; }
};

void question5() {
    cout << "\n=== Питання 5: Звичайний vs шаблонний клас ===\n";

    Stack<int>    si;  // інстанціювання для int
    Stack<string> ss;  // інстанціювання для string — окремий клас!

    si.push(1); si.push(2); si.push(3);
    cout << "Stack<int>:    " << si.pop() << " " << si.pop() << endl;

    ss.push("hello"); ss.push("world");
    cout << "Stack<string>: " << ss.pop() << " " << ss.pop() << endl;
}


// ============================================================
// ПИТАННЯ 6
// Статичні члени шаблонного класу
// ============================================================
/*
  Статичні члени шаблонного класу ДУБЛЮЮТЬСЯ для кожного інстанціювання.
  Тобто Stack<int>::count і Stack<double>::count — це РІЗНІ змінні,
  кожна зі своїм значенням.

  Якщо потрібен спільний лічильник для всіх типів — треба використовувати
  не статичний член шаблону, а окрему глобальну змінну або базовий нешаблонний клас.
*/

template <typename T>
class Counter {
    T value;
public:
    static int count; // окремий для кожного T
    Counter(T v) : value(v) { count++; }
    static int getCount() { return count; }
};

template <typename T> int Counter<T>::count = 0;

void question6() {
    cout << "\n=== Питання 6: Статичні члени шаблонного класу ===\n";
    Counter<int>    a(1), b(2), c(3);
    Counter<double> x(1.1), y(2.2);

    cout << "Counter<int>::count    = " << Counter<int>::getCount()    << endl; // 3
    cout << "Counter<double>::count = " << Counter<double>::getCount() << endl; // 2
    // Різні лічильники для різних інстанціювань!
}


// ============================================================
// ПИТАННЯ 7
// Успадкування шаблонів
// ============================================================
/*
  1. Шаблон МОЖЕ бути похідним від звичайного класу:
     template<T> class Child : public Base { ... };

  2. Шаблон МОЖЕ бути похідним від іншого шаблону:
     template<T> class Child : public Base<T> { ... };

  3. Звичайний клас МОЖЕ походити від інстанційованого шаблону:
     class MyClass : public Stack<int> { ... };
     Але не від самого шаблону (лише від конкретної його версії).
*/

class Animal {
public:
    virtual void speak() const { cout << "..."; }
    virtual ~Animal() {}
};

// Шаблон, похідний від звичайного класу
template <typename T>
class TypedAnimal : public Animal {
    T sound;
public:
    TypedAnimal(T s) : sound(s) {}
    void speak() const override { cout << sound << endl; }
};

// Шаблон, похідний від іншого шаблону
template <typename T>
class BigAnimal : public TypedAnimal<T> {
public:
    BigAnimal(T s) : TypedAnimal<T>(s) {}
    void speak() const override {
        cout << "BIG: ";
        TypedAnimal<T>::speak();
    }
};

// Звичайний клас, похідний від інстанційованого шаблону
class Dog : public TypedAnimal<string> {
public:
    Dog() : TypedAnimal<string>("Гав!") {}
};

void question7() {
    cout << "\n=== Питання 7: Успадкування шаблонів ===\n";
    Animal* a1 = new TypedAnimal<string>("Няв!");
    Animal* a2 = new BigAnimal<string>("Рррр!");
    Animal* a3 = new Dog();

    a1->speak();
    a2->speak();
    a3->speak();

    delete a1; delete a2; delete a3;
}


// ============================================================
// ПИТАННЯ 8
// Коли генерується виконуваний код для шаблону
// ============================================================
/*
  Код для версії шаблону класу або функції-члена генерується компілятором
  НЕ при оголошенні шаблону, а при його ПЕРШОМУ ВИКОРИСТАННІ (інстанціюванні)
  з конкретним типом.

  Тобто:
  - template<T> class Stack { ... };  — код НЕ генерується
  - Stack<int> s;                     — компілятор генерує Stack<int>
  - Stack<double> d;                  — компілятор генерує Stack<double>

  Для функцій-членів: код генерується лише для тих методів,
  які реально викликаються. Якщо метод не використовується —
  компілятор може не генерувати для нього код взагалі.

  Саме тому шаблони зазвичай розміщуються у заголовних файлах (.h),
  а не у файлах реалізації (.cpp).
*/

void question8() {
    cout << "\n=== Питання 8: Коли генерується код шаблону ===\n";
    // Stack<int> — код генерується тут, при першому використанні
    Stack<int> s1;
    s1.push(42);
    cout << "Stack<int> pop: " << s1.pop() << endl;

    // Stack<float> — це вже ІНША версія, генерується окремо
    Stack<float> s2;
    s2.push(3.14f);
    cout << "Stack<float> pop: " << s2.pop() << endl;
}


// ============================================================
// ПИТАННЯ 9
// Переваги і недоліки string
// ============================================================
/*
  ПЕРЕВАГИ string порівняно з char[]:
  1. Автоматичне керування пам'яттю (не потрібен delete[])
  2. Зручне об'єднання рядків через operator+
  3. Безпечне порівняння через ==, <, > (не strcmp)
  4. Багато вбудованих методів: find, substr, replace, length тощо
  5. Немає проблеми переповнення буфера
  6. Легко передавати та повертати з функцій

  НЕДОЛІКИ:
  1. Повільніше за char[] через динамічну пам'ять та копіювання
  2. Більший обсяг пам'яті (службові поля об'єкта)
  3. Не сумісний з С-рядками без c_str()
  4. Деякі старі API вимагають char*, а не string
*/

void question9() {
    cout << "\n=== Питання 9: Переваги і недоліки string ===\n";

    string s1 = "Hello";
    string s2 = ", World!";
    string s3 = s1 + s2;           // легке об'єднання
    cout << s3 << endl;

    cout << "Довжина: " << s3.length() << endl;
    cout << "Позиція 'World': " << s3.find("World") << endl;
    cout << "Підрядок: " << s3.substr(7, 5) << endl;

    // Порівняння
    string a = "apple", b = "banana";
    cout << "apple < banana: " << (a < b ? "так" : "ні") << endl;
}


// ============================================================
// ПИТАННЯ 10
// Шаблонний клас string та його методи
// ============================================================
/*
  std::string — це насправді typedef для std::basic_string<char>.
  basic_string<T> — шаблонний клас для рядків будь-якого символьного типу.

  ОСНОВНІ МЕТОДИ:
  length() / size()    — довжина рядка
  empty()              — чи порожній рядок
  clear()              — очистити рядок
  append() / +=        — додати рядок
  insert(pos, str)     — вставити рядок
  erase(pos, n)        — видалити n символів з позиції pos
  replace(pos,n,str)   — замінити n символів
  find(str)            — знайти підрядок, повертає string::npos якщо не знайдено
  substr(pos, n)       — підрядок з pos довжиною n
  compare()            — порівняти рядки
  c_str()              — отримати const char* для C-функцій
  at(i) / operator[]  — доступ до символу
  begin() / end()      — ітератори
*/

void question10() {
    cout << "\n=== Питання 10: Методи класу string ===\n";

    string s = "Параметричний поліморфізм";
    cout << "Рядок: " << s << endl;
    cout << "Довжина: " << s.length() << endl;
    cout << "Порожній: " << (s.empty() ? "так" : "ні") << endl;

    // find та substr
    size_t pos = s.find("поліморфізм");
    if (pos != string::npos)
        cout << "Знайдено 'поліморфізм' на позиції: " << pos << endl;

    cout << "Підрядок [0,13]: " << s.substr(0, 13) << endl;

    // insert та erase
    string t = "Hello World";
    t.insert(5, " Beautiful");
    cout << "Після insert: " << t << endl;
    t.erase(5, 10);
    cout << "Після erase:  " << t << endl;

    // replace
    string r = "I like cats";
    r.replace(r.find("cats"), 4, "dogs");
    cout << "Після replace: " << r << endl;

    // c_str для С-функцій
    cout << "c_str: " << s.c_str() << endl;

    // wstring — для широких символів
    wstring ws = L"Широкий рядок";
    cout << "wstring довжина: " << ws.length() << endl;
}


// ============================================================
// ПИТАННЯ 11
// Шаблонний клас vector та його методи
// ============================================================
/*
  std::vector<T> — динамічний масив з автоматичним керуванням пам'яттю.
  Є частиною STL (Standard Template Library).

  ОСНОВНІ МЕТОДИ:
  push_back(val)   — додати елемент в кінець
  pop_back()       — видалити останній елемент
  insert(it, val)  — вставити елемент перед ітератором
  erase(it)        — видалити елемент за ітератором
  size()           — кількість елементів
  capacity()       — поточна ємність (виділена пам'ять)
  resize(n)        — змінити розмір
  reserve(n)       — зарезервувати пам'ять
  clear()          — очистити вектор
  empty()          — чи порожній
  front() / back() — перший / останній елемент
  at(i) / []       — доступ до елемента
  begin() / end()  — ітератори
  sort(v.begin(), v.end()) — сортування (з <algorithm>)
*/

void question11() {
    cout << "\n=== Питання 11: Методи класу vector ===\n";

    vector<int> v = {5, 3, 8, 1, 9, 2, 7};
    cout << "Початковий вектор: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    cout << "size=" << v.size() << " capacity=" << v.capacity() << endl;

    // push_back
    v.push_back(4);
    cout << "Після push_back(4): back=" << v.back() << ", size=" << v.size() << endl;

    // pop_back
    v.pop_back();
    cout << "Після pop_back: size=" << v.size() << endl;

    // insert
    v.insert(v.begin() + 2, 99);
    cout << "Після insert(pos=2, 99): ";
    for (int x : v) cout << x << " ";
    cout << endl;

    // erase
    v.erase(v.begin() + 2);
    cout << "Після erase(pos=2): ";
    for (int x : v) cout << x << " ";
    cout << endl;

    // sort
    sort(v.begin(), v.end());
    cout << "Після сортування: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    // front / back / at
    cout << "front=" << v.front() << " back=" << v.back()
         << " at(3)=" << v.at(3) << endl;

    // reserve
    vector<int> v2;
    v2.reserve(100);
    cout << "Після reserve(100): capacity=" << v2.capacity() << " size=" << v2.size() << endl;

    // vector рядків
    vector<string> words = {"шаблон", "поліморфізм", "клас"};
    sort(words.begin(), words.end());
    cout << "Відсортовані слова: ";
    for (const string& w : words) cout << w << " ";
    cout << endl;

    // 2D вектор
    vector<vector<int>> matrix(3, vector<int>(3, 0));
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            matrix[i][j] = i * 3 + j + 1;

    cout << "Матриця 3x3:\n";
    for (auto& row : matrix) {
        for (int x : row) cout << x << "\t";
        cout << endl;
    }
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

    cout << "\n=== Програма завершена ===\n";
    return 0;
}
