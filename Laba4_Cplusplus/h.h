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

        string err_len_ = "[" + vos_ + "]" + " ������ ��� ���������";
        string err_len_1 = "[" + vos_ + "]" + " ������� �������� ������ ���������";
        string err_len_2 = "[" + vos_ + "]" + " ������� ������ ������ ���������";

        string err_len_3 = "[" + vos_ + "]" + " ������ ������� �������";

        string err_len_4 = "[" + vos_1 + "]" + " ���������� �������...";
        string err_len_5 = "[" + vos_2 + "]" + " �������� �������...";
        string err_len_8 = "[" + vos_5 + "]" + " ������� ������...";

        string err_len_55 = "[" + vos_22 + "]" + " ������������� �������...";

        string err_len_6 = "[" + vos_3 + "]" + " ���������� ������...";
        string err_len_7 = "[" + vos_4 + "]" + " �������� ������...";
        string err_len_9 = "[" + vos_6 + "]" + " ������� �������...";


        string n_ = "\n";

    template<typename T>
    class Vec {
    private:
        vector<T> arr;

    public:

        Vec(size_t size) : arr(size) {}

        // �������� ����������
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

        // ��������� ������������
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


        // �������� �������� ��������
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



        // ������ �������
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

        // �������� ����������
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

        // �������� �������� ������
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

        // �������� ��������� ������
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

        // �������� ������� ������
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


        // ���������������� �������
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

        // ������ �������
        void print() const {
            for (const auto& row : arr) {
                for (const auto& el : row) {
                    cout << el << " ";
                }
                cout << endl;
            }
        }
    };