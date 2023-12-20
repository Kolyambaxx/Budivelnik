// Budivelnik.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

class Product {
public:
    void addPart(const std::string& part) {
        description += part + " ";
    }

    void show() const {
        std::cout << "Product Parts: " << description << std::endl;
    }

private:
    std::string description;
};

class Builder {
public:
    virtual ~Builder() = default;
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual Product getResult() const = 0;
};

class ConcreteBuilderA : public Builder {
public:
    void buildPartA() override {
        product.addPart("PartA");
    }

    void buildPartB() override {
        product.addPart("PartB");
    }

    Product getResult() const override {
        return product;
    }

private:
    Product product;
};

class ConcreteBuilderB : public Builder {
public:
    void buildPartA() override {
        product.addPart("PartX");
    }

    void buildPartB() override {
        product.addPart("PartY");
    }

    Product getResult() const override {
        return product;
    }

private:
    Product product;
};

class Director {
public:
    Director(Builder* builder) : builder(builder) {}

    void construct() {
        builder->buildPartA();
        builder->buildPartB();
    }

private:
    Builder* builder;
};

int main() {
    ConcreteBuilderA builderA;
    ConcreteBuilderB builderB;

    Director directorA(&builderA);
    directorA.construct();
    Product productA = builderA.getResult();
    productA.show();

    Director directorB(&builderB);
    directorB.construct();
    Product productB = builderB.getResult();
    productB.show();

    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
