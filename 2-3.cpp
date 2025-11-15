#include <iostream>

void inputData(float* p, int n) {
    for (int i = 0; i < n; ++i)
        std::cin >> *(p + i);
}

float average(const float* p, int n) {
    float sum = 0.0f;
    for (int i = 0; i < n; ++i)
        sum += *(p + i);
    return sum / n;
}

float minValue(const float* p, int n) {
    float minVal = *(p + 0);
    for (int i = 1; i < n; ++i)
        if (*(p + i) < minVal) minVal = *(p + i);
    return minVal;
}

float maxValue(const float* p, int n) {
    float maxVal = *(p + 0);
    for (int i = 1; i < n; ++i)
        if (*(p + i) > maxVal) maxVal = *(p + i);
    return maxVal;
}

float* filterAboveAverage(float* p, int n, int& newCount) {
    float avg = average(p, n);
    newCount = 0;
    for (int i = 0; i < n; ++i)
        if (*(p + i) > avg) ++newCount;
    float* result = new float[newCount];
    int idx = 0;
    for (int i = 0; i < n; ++i)
        if (*(p + i) > avg) *(result + idx++) = *(p + i);
    return result;
}

int main() {
    int n;
    std::cout << "=== Анализ сенсора ===" << std::endl << "Введите количество измерений: ";
    std::cin >> n;
    float* data = new float[n];
    std::cout << "Введите значения: ";
    inputData(data, n);

    float avg = average(data, n);
    float minVal = minValue(data, n);
    float maxVal = maxValue(data, n);

    std::cout << "Среднее значение: " << avg << 
    std::endl << "Минимум: " << minVal << 
    std::endl << "Максимум: " << maxVal << 
    std::endl;

    int countAbove;
    float* above = filterAboveAverage(data, n, countAbove);
    std::cout << "Значения выше среднего:";
    for (int i = 0; i < countAbove; ++i)
        std::cout << " " << *(above + i);
    std::cout << std::endl;

    delete[] data;
    delete[] above;
    return 0;
}
