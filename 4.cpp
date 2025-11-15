#include <iostream>

float dayAverage(float* row, int h) {
    float sum = 0.0f;
    for (int j = 0; j < h; ++j)
        sum += *(row + j);
    return sum / h;
}

float overallAverage(float** p, int d, int h) {
    float sum = 0.0f;
    for (int i = 0; i < d; ++i)
        for (int j = 0; j < h; ++j)
            sum += *(*(p + i) + j);
    return sum / (d * h);
}

void showHotDays(float** p, int d, int h) {
    float overallAvg = overallAverage(p, d, h);
    std::cout << "Теплые дни:" << std::endl;
    for (int i = 0; i < d; ++i) {
        float dayAvg = dayAverage(*(p + i), h);
        if (dayAvg > overallAvg)
            std::cout << "День " << (i + 1) << " (среднее = " << dayAvg << ")" << std::endl;
    }
}

int main() {
    int d, h;
    std::cout << "Введите количество дней: ";
    std::cin >> d;
    std::cout << "Введите количество измерений в дне: ";
    std::cin >> h;

    float** data = new float*[d];
    for (int i = 0; i < d; ++i)
        data[i] = new float[h];

    for (int i = 0; i < d; ++i) {
        std::cout << "День " << (i + 1) << ": ";
        for (int j = 0; j < h; ++j)
            std::cin >> *(*(data + i) + j);
    }

    float overallAvg = overallAverage(data, d, h);
    std::cout << "Общая средняя температура: " << overallAvg << std::endl;
    showHotDays(data, d, h);

    for (int i = 0; i < d; ++i)
        delete[] data[i];
    delete[] data;
    return 0;
}
