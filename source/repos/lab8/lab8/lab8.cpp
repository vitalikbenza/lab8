#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <gtest/gtest.h>

class Algorithms {
public:
    // 1. Пошук мінімального елементу масиву позитивних чисел
    static int findMinPositive(const std::vector<int>& arr) {
        int min = INT_MAX;
        bool found = false;
        for (int num : arr) {
            if (num > 0 && num < min) {
                min = num;
                found = true;
            }
        }
        if (!found) throw std::invalid_argument("No positive numbers in the array.");
        return min;
    }

    // 2. Розрахунок суми елементів масиву, який може складатися лише з від’ємних чисел
    static int sumNegative(const std::vector<int>& arr) {
        int sum = 0;
        for (int num : arr) {
            if (num >= 0) throw std::invalid_argument("Array contains non-negative numbers.");
            sum += num;
        }
        return sum;
    }

    // 3. Алгоритм розрахунку N-го елементу послідовності Фібоначчі
    static int fibonacci(int n) {
        if (n < 0) throw std::invalid_argument("N must be non-negative.");
        if (n == 0) return 0;
        if (n == 1) return 1;
        int a = 0, b = 1, c;
        for (int i = 2; i <= n; ++i) {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }

    // 4. Алгоритм розрахунку сили струму на ділянці кола
    static double calculateCurrent(double voltage, double resistance) {
        if (resistance <= 0) throw std::invalid_argument("Resistance must be positive.");
        return voltage / resistance;
    }
};

// Модульні тести
TEST(AlgorithmsTest, FindMinPositive) {
    EXPECT_EQ(Algorithms::findMinPositive({ 3, 5, 1, 7 }), 1);
    EXPECT_EQ(Algorithms::findMinPositive({ 10, 20, 30 }), 10);
    EXPECT_THROW(Algorithms::findMinPositive({ -1, -2, -3 }), std::invalid_argument);
}

TEST(AlgorithmsTest, SumNegative) {
    EXPECT_EQ(Algorithms::sumNegative({ -3, -5, -1, -7 }), -16);
    EXPECT_EQ(Algorithms::sumNegative({ -10, -20, -30 }), -60);
    EXPECT_THROW(Algorithms::sumNegative({ -1, 2, -3 }), std::invalid_argument);
}

TEST(AlgorithmsTest, Fibonacci) {
    EXPECT_EQ(Algorithms::fibonacci(0), 0);
    EXPECT_EQ(Algorithms::fibonacci(1), 1);
    EXPECT_EQ(Algorithms::fibonacci(5), 5);
    EXPECT_EQ(Algorithms::fibonacci(10), 55);
    EXPECT_THROW(Algorithms::fibonacci(-1), std::invalid_argument);
}

TEST(AlgorithmsTest, CalculateCurrent) {
    EXPECT_DOUBLE_EQ(Algorithms::calculateCurrent(10, 5), 2.0);
    EXPECT_DOUBLE_EQ(Algorithms::calculateCurrent(12, 4), 3.0);
    EXPECT_THROW(Algorithms::calculateCurrent(10, 0), std::invalid_argument);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
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
