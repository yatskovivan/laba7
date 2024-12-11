#include <iostream>
#include <list>
#include <deque>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace chrono;
const int n = 1000000;
template <typename Container>
void testPerformance(const string& containerName) {
    Container container;
    auto start = high_resolution_clock::now();
    for (int i = 0; i < n; ++i) {
        container.push_back(i);
    }
    auto end = high_resolution_clock::now();
    cout << containerName << " - Добавление в конец: "
        << duration_cast<milliseconds>(end - start).count() << " ms" << endl;
    start = high_resolution_clock::now();
    auto it = find(container.begin(), container.end(), n / 2);
    end = high_resolution_clock::now();
    cout << containerName << " - Поиск элемента: "
        << duration_cast<milliseconds>(end - start).count() << " ms" << endl;
    start = high_resolution_clock::now();
    for (int i = 0; i < n; ++i) {
        container.pop_front();
    }
    end = high_resolution_clock::now();
    cout << containerName << " - Удаление с начала: "
        << duration_cast<milliseconds>(end - start).count() << " ms" << endl;
}
int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Сравнение производительности list и deque:" << endl;
    testPerformance<list<int>>("list");
    testPerformance<deque<int>>("deque");
    cout << "Отсюда можно сделать вывод о том, что добавление в конец у desque быстрее. Поиск элемента у list быстрее. Удаление с начала у desque быстрее.";
    return 0;
}