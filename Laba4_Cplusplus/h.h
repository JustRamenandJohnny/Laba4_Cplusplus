#include <iostream>
#include <stdexcept>
#include <vector>

    using namespace std;

        string vos_ = "!";
        string vos_1 = "+";
        string vos_2 = "*";
        string vos_5 = "^";

        string vos_22 = ":";

        string vos_3 = "/+/";
        string vos_4 = "/*/";
        string vos_6 = "/^/";

        string err_len_ = "[" + vos_ + "]" + " Индекс вне диапазона";
        string err_len_1 = "[" + vos_ + "]" + " Размеры векторов должны совпадать";
        string err_len_2 = "[" + vos_ + "]" + " Размеры матриц должны совпадать";

        string err_len_3 = "[" + vos_ + "]" + " Разные размеры массива";

        string err_len_4 = "[" + vos_1 + "]" + " Складываем матрицы...";
        string err_len_5 = "[" + vos_2 + "]" + " Умножаем матрицу...";
        string err_len_8 = "[" + vos_5 + "]" + " Степень матриц...";

        string err_len_55 = "[" + vos_22 + "]" + " Транспонируем матрицу...";

        string err_len_6 = "[" + vos_3 + "]" + " Складываем вектор...";
        string err_len_7 = "[" + vos_4 + "]" + " Умножаем вектор...";
        string err_len_9 = "[" + vos_6 + "]" + " Степень вектора...";


        string n_ = "\n";

    template<typename T>
    class Vec {
    private:
        vector<T> arr;

    public:

        Vec(size_t size) : arr(size) {}

        // Оператор индексации
        T& operator[](size_t index) {
            if (index >= arr.size()) {
                cout << err_len_ << endl;
                throw out_of_range(err_len_);

            }
            return arr[index];
        }

        const T& operator[](size_t index) const {
            if (index >= arr.size()) {
                cout << err_len_ << endl;
                throw out_of_range(err_len_);
            }
            return arr[index];
        }

        // Скалярное произведение
        T dot(const Vec& other) const {
            if (arr.size() != other.arr.size()) {
                cout << err_len_3 << endl;
                throw invalid_argument(err_len_1);
            }
            T ans = T();
            for (size_t i = 0; i < arr.size(); ++i) {
                ans += arr[i] * other[i];
            }

            cout << n_ << err_len_7 << endl;
            return ans;
        }


        // Оператор сложения векторов
        Vec operator+(const Vec& other) const {
            if (arr.size() != other.arr.size()) {
                cout << err_len_3 << endl;
                throw invalid_argument(err_len_1);
            }
            Vec ans(arr.size());
            for (size_t i = 0; i < arr.size(); ++i) {
                ans[i] = arr[i] + other[i];
            }

            cout << n_ << err_len_6 << endl;
            return ans;
        }



        // Печать вектора
        void print() const {
            for (const auto& el : arr) {
                cout << el << " ";
            }
            cout << endl;
        }
    };

    template<typename T>
    class Matr {
    private:
        vector<vector<T>> arr;

    public:
        Matr(size_t rows, size_t cols) : arr(rows, vector<T>(cols)) {}

        // Оператор индексации
        T& operator()(size_t row, size_t col) {
            if (row >= arr.size() || col >= arr[row].size()) {
                cout << err_len_ << endl;
                throw out_of_range(err_len_);
            }
            return arr[row][col];
        }

        const T& operator()(size_t row, size_t col) const {
            if (row >= arr.size() || col >= arr[row].size()) {
                throw out_of_range(err_len_);
            }
            return arr[row][col];
        }

        // Оператор сложения матриц
        Matr operator+(const Matr& other) const {
            if (arr.size() != other.arr.size() || arr[0].size() != other.arr[0].size()) {
                throw invalid_argument(err_len_2);
            }
            Matr ans(arr.size(), arr[0].size());
            for (size_t i = 0; i < arr.size(); ++i) {
                for (size_t j = 0; j < arr[i].size(); ++j) {
                    ans(i, j) = arr[i][j] + other(i, j);
                }
            }

            cout << n_ << err_len_4 << endl;
            return ans;
        }

        // Оператор умножения матриц
        Matr dot(const Matr& other) const {
            if (arr[0].size() != other.arr.size()) {
                throw invalid_argument(err_len_2);
            }

            Matr ans(arr.size(), other.arr[0].size()); 
           

            for (size_t i = 0; i < arr.size(); ++i) { 
                for (size_t j = 0; j < other.arr[0].size(); ++j) { 
                    ans(i, j) = 0;

                    
                    for (size_t k = 0; k < arr[0].size(); ++k) {
                        ans(i, j) += arr[i][k] * other.arr[k][j];
                    }
                }
            }

            cout << n_ << err_len_5 << endl;

            return ans;
        }

        // Оператор степень матриц
        Matr st(int st_) const {
            Matr ans(arr.size(), arr[0].size());


            for (size_t i = 0; i < arr.size(); ++i) {
                for (size_t k = 0; k < arr[0].size(); ++k) {
                    ans(i, k) = 0;
                    ans(i, k) = pow(arr[i][k],st_);
                }

            }

            cout << n_ << err_len_8 << endl;

            return ans;
        }


        // Транспонирование матрицы
        Matr transpose() const {
            Matr ans(arr[0].size(), arr.size());
            for (size_t i = 0; i < arr.size(); ++i) {
                for (size_t j = 0; j < arr[i].size(); ++j) {
                    ans(j, i) = arr[i][j];
                }
            }
            cout << n_ << err_len_55 << endl;

            return ans;
        }

        // Печать матрицы
        void print() const {
            for (const auto& row : arr) {
                for (const auto& el : row) {
                    cout << el << " ";
                }
                cout << endl;
            }
        }
    };