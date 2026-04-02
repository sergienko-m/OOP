// ============================================================
// Лабораторна робота № 8
// Тема: Віртуальні функції і поліморфізм
// ============================================================

// ============================================================
// ЗАВДАННЯ 1 (стор. 112)
// Абстрактний базовий клас з віртуальною функцією – площа.
// Похідні класи: Прямокутник, Коло, Прямокутний трикутник, Трапеція.
// Масив вказівників на абстрактний клас для перевірки пізнього зв'язування.
// ============================================================

#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <iomanip>
using namespace std;

// --- Абстрактний базовий клас ---
class Figure {
public:
    virtual double Area() const = 0;   // чиста віртуальна функція
    virtual void   Print() const = 0;  // чиста віртуальна функція виводу
    virtual ~Figure() {}               // віртуальний деструктор
};

// --- Прямокутник: S = a * b ---
class Rectangle : public Figure {
    double a, b;
public:
    Rectangle(double a, double b) : a(a), b(b) {}
    double Area() const override { return a * b; }
    void   Print() const override {
        cout << "Прямокутник (a=" << a << ", b=" << b
             << "): площа = " << Area() << endl;
    }
};

// --- Коло: S = π * r² ---
class Circle : public Figure {
    double r;
public:
    Circle(double r) : r(r) {}
    double Area() const override { return M_PI * r * r; }
    void   Print() const override {
        cout << "Коло (r=" << r
             << "): площа = " << Area() << endl;
    }
};

// --- Прямокутний трикутник: S = (a * b) / 2 ---
class RightTriangle : public Figure {
    double a, b; // катети
public:
    RightTriangle(double a, double b) : a(a), b(b) {}
    double Area() const override { return (a * b) / 2.0; }
    void   Print() const override {
        cout << "Прямокутний трикутник (a=" << a << ", b=" << b
             << "): площа = " << Area() << endl;
    }
};

// --- Трапеція: S = (a + b) * h / 2 ---
class Trapezoid : public Figure {
    double a, b, h; // основи та висота
public:
    Trapezoid(double a, double b, double h) : a(a), b(b), h(h) {}
    double Area() const override { return (a + b) * h / 2.0; }
    void   Print() const override {
        cout << "Трапеція (a=" << a << ", b=" << b << ", h=" << h
             << "): площа = " << Area() << endl;
    }
};

// ============================================================
// САМОСТІЙНА РОБОТА (стор. 114)
// listing 1 — виклик віртуальної функції через вказівник
// listing 3 — виклик через посилання
// listing 4 — успадкування атрибуту virtual
// listing 5 — віртуальна функція не обов'язково заміщується
// listing 6 — якщо не заміщується — викликається попередня версія
// listing 7 — чисто віртуальна функція
// listing 8 — абстрактний клас (конвертації)
// ============================================================

// --- listing 1 ---
namespace Listing1 {
    class base {
    public:
        virtual void vfunc() {
            cout << "Функція vfunc() з базового класу.\n";
        }
    };
    class derived1 : public base {
    public:
        void vfunc() override {
            cout << "Функція vfunc() з класу derived1.\n";
        }
    };
    class derived2 : public base {
    public:
        void vfunc() override {
            cout << "Функція vfunc() з класу derived2.\n";
        }
    };
    void run() {
        cout << "\n--- Listing 1: вказівник на базовий клас ---\n";
        base *p, b;
        derived1 d1;
        derived2 d2;
        p = &b;  p->vfunc();
        p = &d1; p->vfunc();
        p = &d2; p->vfunc();
    }
}

// --- listing 3 ---
namespace Listing3 {
    class base {
    public:
        virtual void vfunc() {
            cout << "Функція vfunc() з класу base.\n";
        }
    };
    class derived1 : public base {
    public:
        void vfunc() override {
            cout << "Функція vfunc() з класу derived1\n";
        }
    };
    class derived2 : public base {
    public:
        void vfunc() override {
            cout << "Функція vfunc() з класу derived2\n";
        }
    };
    void f(base &r) { r.vfunc(); }
    void run() {
        cout << "\n--- Listing 3: виклик через посилання ---\n";
        base b; derived1 d1; derived2 d2;
        f(b); f(d1); f(d2);
    }
}

// --- listing 4 ---
namespace Listing4 {
    class base {
    public:
        virtual void vfunc() {
            cout << "Функція vfunc() з класу base.\n";
        }
    };
    class derived1 : public base {
    public:
        void vfunc() override {
            cout << "Функція vfunc() з класу derived1.\n";
        }
    };
    class derived2 : public derived1 {
    public:
        void vfunc() override {
            cout << "Функція vfunc() з класу derived2.\n";
        }
    };
    void run() {
        cout << "\n--- Listing 4: успадкування атрибуту virtual ---\n";
        base *p, b; derived1 d1; derived2 d2;
        p = &b;  p->vfunc();
        p = &d1; p->vfunc();
        p = &d2; p->vfunc();
    }
}

// --- listing 5 ---
namespace Listing5 {
    class base {
    public:
        virtual void vfunc() {
            cout << "Функція vfunc() з класу base.\n";
        }
    };
    class derived1 : public base {
    public:
        void vfunc() override {
            cout << "Функція vfunc() з класу derived1.\n";
        }
    };
    class derived2 : public base {
        // vfunc() не заміщується — використовується версія з base
    };
    void run() {
        cout << "\n--- Listing 5: функція не обов'язково заміщується ---\n";
        base *p, b; derived1 d1; derived2 d2;
        p = &b;  p->vfunc();
        p = &d1; p->vfunc();
        p = &d2; p->vfunc(); // викличе base::vfunc()
    }
}

// --- listing 6 ---
namespace Listing6 {
    class base {
    public:
        virtual void vfunc() {
            cout << "Функція vfunc() з класу base.\n";
        }
    };
    class derived1 : public base {
    public:
        void vfunc() override {
            cout << "Функція vfunc() з класу derived1.\n";
        }
    };
    class derived2 : public derived1 {
        // vfunc() не заміщується — викличеться derived1::vfunc()
    };
    void run() {
        cout << "\n--- Listing 6: викликається попередня версія ---\n";
        base *p, b; derived1 d1; derived2 d2;
        p = &b;  p->vfunc();
        p = &d1; p->vfunc();
        p = &d2; p->vfunc(); // викличе derived1::vfunc()
    }
}

// --- listing 7 ---
namespace Listing7 {
    class number {
    protected:
        int val;
    public:
        void setval(int i) { val = i; }
        virtual void show() = 0; // чисто віртуальна
    };
    class hextype : public number {
    public:
        void show() override { cout << hex << val << " "; }
    };
    class dectype : public number {
    public:
        void show() override { cout << dec << val << " "; }
    };
    class octtype : public number {
    public:
        void show() override { cout << oct << val << "\n"; }
    };
    void run() {
        cout << "\n--- Listing 7: чисто віртуальна функція ---\n";
        dectype d; hextype h; octtype o;
        d.setval(20); d.show();
        h.setval(20); h.show();
        o.setval(20); o.show();
        cout << dec; // скидаємо формат
    }
}

// --- listing 8 ---
namespace Listing8 {
    class convert {
    protected:
        double val1, val2;
    public:
        convert(double i) : val1(i), val2(0) {}
        double getconv() { return val2; }
        double getinit() { return val1; }
        virtual void compute() = 0;
    };
    class l_to_g : public convert {
    public:
        l_to_g(double i) : convert(i) {}
        void compute() override { val2 = val1 / 3.7854; }
    };
    class f_to_c : public convert {
    public:
        f_to_c(double i) : convert(i) {}
        void compute() override { val2 = (val1 - 32) / 1.8; }
    };
    void run() {
        cout << "\n--- Listing 8: абстрактний клас (конвертації) ---\n";
        convert *p;
        l_to_g lgob(4);
        f_to_c fcob(70);
        p = &lgob;
        cout << p->getinit() << " літри = ";
        p->compute();
        cout << p->getconv() << " галонів\n";
        p = &fcob;
        cout << p->getinit() << " по Фаренгейту = ";
        p->compute();
        cout << p->getconv() << " по Цельсію\n";
    }
}

// ============================================================
// ГОЛОВНА ФУНКЦІЯ
// ============================================================
int main() {
    cout << fixed << setprecision(2);

    // --- Завдання 1: масив вказівників на абстрактний клас ---
    cout << "=== Завдання 1: Площі фігур (пізнє зв'язування) ===\n";
    Figure* figures[4] = {
        new Rectangle(4, 6),
        new Circle(5),
        new RightTriangle(3, 7),
        new Trapezoid(4, 8, 5)
    };

    for (int i = 0; i < 4; ++i) {
        figures[i]->Print();
        delete figures[i];
    }

    // --- Самостійна робота ---
    cout << "\n=== Самостійна робота ===";
    Listing1::run();
    Listing3::run();
    Listing4::run();
    Listing5::run();
    Listing6::run();
    Listing7::run();
    Listing8::run();

    return 0;
}

/*
============================================================
ВІДПОВІДІ НА ЗАПИТАННЯ
============================================================

1. Що таке поліморфізм і які є його типи?
   Поліморфізм — використання одного імені для різних функцій, що опрацьовують
   дані різних типів. Типи:
   - Статичний: перевантаження функцій/операцій, шаблони. Вирішується під час компіляції.
   - Динамічний: перевизначення віртуальних функцій. Вирішується під час виконання.

2. Що таке раннє і пізнє зв'язування?
   - Раннє (статичне): компілятор визначає яку функцію викликати під час компіляції.
     Застосовується при виклику через об'єкт.
   - Пізнє (динамічне): функція визначається під час виконання програми.
     Застосовується при виклику через вказівник або посилання на базовий клас,
     що вказує на об'єкт похідного класу. Реалізується через таблицю віртуальних методів (ТВМ).

3. Який метод називається віртуальним і які його особливості?
   Віртуальний метод — метод класу, оголошений з ключовим словом virtual.
   Особливості:
   - Може бути тільки членом класу (не другом).
   - Не може бути статичним.
   - virtual достатньо вказати лише в першому оголошенні.
   - Для пізнього зв'язування потрібен виклик через вказівник або посилання.
   - У межах поліморфічного кластера не змінює сигнатуру.

4. Як виключити поліморфізм віртуальних методів?
   Вказати явно ім'я класу при виклику:
     вказівник->НазваКласу::назва_методу();
     посилання.НазваКласу::назва_методу();
   Наприклад: p->A::f(); — викличе A::f() незважаючи на те, що p вказує на об'єкт B.

5. Які віртуальні методи є коваріантними?
   Коваріантні — це віртуальні методи, що відрізняються типом результату в ієрархії
   успадкування, але ці типи узгоджені між собою (один є нащадком іншого).
   Наприклад, базовий клас повертає A*, а похідний — B* (де B : public A).

6. Що таке віртуальні операторні методи?
   Операторні функції (operator) класу можуть бути оголошені як virtual.
   Тоді при виклику оператора через вказівник/посилання на базовий клас,
   буде викликаний оператор відповідного похідного класу (пізнє зв'язування).
   Наприклад: virtual A& operator++() у базовому та virtual B& operator++() у похідному.

7. Як реалізувати вказівники на віртуальні методи?
   Синтаксис оголошення: void (A::*pf)() = &A::Get;
   Виклик: (p->*pf)(); — еквівалентно p->Get().
   При цьому пізнє зв'язування зберігається — буде викликаний метод реального об'єкта.

8. Динамічні віртуальні методи.
   Підклас віртуальних методів, що оголошуються з індексом: virtual void f()=[100];
   Зберігаються в окремій таблиці динамічних методів (ТДВМ), яка займає менше пам'яті
   ніж ТВМ, але пошук адреси займає більше часу.
   Примітка: у компіляторі g++ не підтримуються.

9. Особливості застосування віртуальних деструкторів.
   Якщо базовий клас має невіртуальний деструктор і вказівник на базовий клас
   вказує на об'єкт похідного класу — при delete викличеться лише деструктор базового класу,
   що призведе до витоку пам'яті похідного класу.
   Якщо деструктор ~Base() є virtual — при delete спочатку викличеться ~Derived(),
   а потім ~Base(), що забезпечує коректне знищення об'єкта.

10. Що таке чисті віртуальні методи і для чого вони використовуються?
    Чистий віртуальний метод — метод з = 0: virtual void f() = 0;
    Він не має реалізації в базовому класі. Використовується для:
    - оголошення інтерфейсу, який зобов'язані реалізувати похідні класи;
    - створення абстрактних класів.
    Не може бути викликаний з конструктора.

11. Що таке абстрактний і чистий абстрактний класи?
    - Абстрактний клас: містить хоча б один чистий віртуальний метод.
      Не можна створити об'єкт такого класу, але можна оголосити вказівник/посилання на нього.
    - Чистий абстрактний клас: складається ВИКЛЮЧНО з чистих віртуальних методів.
      Використовується як інтерфейс.

12. Пояснення прикладу програми застосування абстрактних класів (стор. 111):
    Оголошено абстрактний клас Figure з чистим віртуальним методом Area().
    Похідні класи Triangle, Rectangle, Circle визначають власні реалізації Area().
    У main() створено масив вказівників Figure* p[3] на об'єкти похідних класів.
    Через допоміжну функцію GetArea(Figure* f) викликається f->Area() —
    завдяки пізньому зв'язуванню викликається правильна реалізація Area()
    для кожного конкретного об'єкта (трикутника, прямокутника або круга).
    Результат: площі обчислюються поліморфно через єдиний інтерфейс Figure*.
============================================================
*/
