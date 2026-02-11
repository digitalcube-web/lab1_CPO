#include <iostream>
using namespace std;

//В одной школе в 11 классе учится мальчик Вася.Как - то раз Вася решил посмотреть матч своей любимой хоккейной команды.А поскольку мальчик очень любит хоккей, даже больше, чем физику, он забыл сделать уроки.В частности, забыл сделать задачки по физике.На следующий день учитель очень разозлился на Васю, и решил его проучить.Он дал нерадивому ученику, казалось бы, простую задачку : дано покоящееся тело в пространстве, и даны силы, действующие на него.Тело можно считать материальной точкой с координатами(0; 0; 0).Васе нужно было ответить, находится ли оно в равновесии.«Ерунда!» — подумал Вася, нужно лишь проверить, что сумма всех векторов равна 0, и принялся решать задачу.Но впоследствии оказалось, что этих сил может быть очень - очень много, и Вася не справится без вашей помощи.Помогите ему.Напишите программу, которая определяет по заданным векторам сил, покоится тело или движется.
//
//Входные данные
//В первой строке задано натуральное число n(1 ≤ n ≤ 100), далее следует n строк по три целых числа в каждой : координата xi, координата yi и координата zi вектора силы, приложенной к телу(-100 ≤ xi, yi, zi ≤ 100).
//
//Выходные данные
//Выведите слово "YES" если тело находится в равновесии, или слово "NO" если не находится.


struct Coord {
    int x, y, z;
};

int InputCoord(char coord_name);
bool SumCoordX(int size, Coord* arr);
bool SumCoordY(int size, Coord* arr);
bool SumCoordZ(int size, Coord* arr);

int main()
{
    // test
    setlocale(LC_ALL, "ru");
    int n;

    do {
        cout << "Введите колличество сил, действующих на тело: ";
        cin >> n;
    } while (n < 1 || n > 100);

    Coord *f = new Coord [n];

    for (int i = 0; i < n; i++) {
        cout << "Сила " << i + 1 << endl;
        f[i] = { InputCoord('x'), InputCoord('y'), InputCoord('z') };
        cout << endl;
    }

    if (SumCoordX(n, f) && SumCoordY(n, f) && SumCoordZ(n, f)) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;
}

int InputCoord(char coord_name) {
    int coord;
    do {
        cout << "Ввкдите " << coord_name << " ";
        cin >> coord;
    } while (coord < -100 || coord > 100);
    return coord;
}

bool SumCoordX(int size, Coord *arr) {
    int res = 0;
    for (int i = 0; i < size; i++) {
        res += arr[i].x;
    }
    return res == 0 ? 1 : 0;
}

bool SumCoordY(int size, Coord* arr) {
    int res = 0;
    for (int i = 0; i < size; i++) {
        res += arr[i].y;
    }
    return res == 0 ? 1 : 0;
}

bool SumCoordZ(int size, Coord* arr) {
    int res = 0;
    for (int i = 0; i < size; i++) {
        res += arr[i].z;
    }
    return res == 0 ? 1 : 0;
}