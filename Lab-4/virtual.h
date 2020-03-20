#pragma once

class IGeoFig {
public:
// Площадь.
    virtual double square() = 0;
// Периметр.
    virtual double perimeter() = 0;
};
// Вектор
class CVector2D {
public:
    double x, y;
};
// Интерфейс "Физический объект".
class IPhysObject: public IGeoFig {
public:
// Масса, кг.
    [[nodiscard]] virtual double mass() const = 0;
// Координаты центра масс, м.
    virtual CVector2D position() = 0;
// Сравнение по массе.
    virtual bool operator== ( const IPhysObject& ob ) const = 0;
// Сравнение по массе.
    virtual bool operator< ( const IPhysObject& ob ) const = 0;
};
// Интерфейс "Отображаемый"
class IPrintable {
public:
// Отобразить на экране
// (выводить в текстовом виде параметры фигуры).
    virtual void draw() = 0;
};
// Интерфейс для классов, которые можно задать через диалог с пользователем.
class IDialogInitiable {
// Задать параметры объекта с помощью диалога с пользователем.
    virtual void initFromDialog() = 0;
};
// Интерфейс "Класс"
class BaseCObject {
public:
// Имя класса (типа данных).
    virtual const char* classname() = 0;
// Размер занимаемой памяти.
    virtual const char * size() = 0;
};

class Array : public IPhysObject {
public:
    Array() = default;
    [[nodiscard]] double square() override;
    [[nodiscard]] double perimeter() override;
    [[nodiscard]] double mass() const override;
    [[nodiscard]] CVector2D position() override;
    void Add(IPhysObject*);
    void Resize(unsigned n);
    void Remove(unsigned n);
    IPhysObject* operator[](unsigned n);
    bool operator==( const IPhysObject& ob) const override;
    bool operator<( const IPhysObject& ob) const override;
private:
    unsigned capasity_ = 0, size_ = 10;
    IPhysObject** arr = new IPhysObject*[10];
};


class Circle : public IPhysObject, public IPrintable, public BaseCObject {
public:
    explicit Circle(CVector2D, double, double);
    [[nodiscard]] double square() override;
    [[nodiscard]] double perimeter() override;
    [[nodiscard]] double mass() const override;
    [[nodiscard]] CVector2D position() override;
    bool operator==( const IPhysObject& ob) const override;
    bool operator<( const IPhysObject& ob) const override;
    const char* classname() override;
    const char* size() override;
    void draw() override;
private:
    CVector2D Center;
    double Radius, mass_;
};

class Parallelogram : public IGeoFig, public IPhysObject, public IPrintable, public BaseCObject {
public:
    explicit Parallelogram(CVector2D, CVector2D, CVector2D, double);
    [[nodiscard]] double square() override;
    [[nodiscard]] double perimeter() override;
    [[nodiscard]] double mass() const override;
    [[nodiscard]] CVector2D position() override;
    bool operator==(const IPhysObject& ob) const override;
    bool operator<(const IPhysObject& ob) const override;
    const char* classname() override;
    const char* size() override;
    void draw() override;
private:
    double mass_;
    CVector2D A, B, C;
};
