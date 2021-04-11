#include <iostream>
#include <string>
#define T 6

using namespace std;

class Weather
{
public:
    string place;
    string data;

public:
    Weather() {}
    ~Weather() {}
    void SetPlace(string p)
    {
        place = p;
    }

    void SetDate(string d)
    {
        data = d;
    }
    string GetPlace() { return place; }
    string GetDate() { return data; }
};

class Water : public Weather
{
private:
    double wave;
    double temp;
public:

    Water() {}
    ~Water() {}
    void SetWater(double speed)
    {
        wave = speed;
    }

    void SetTemp(double t)
    {
        temp = t;
    }
    double GetWater() { return wave; }
    double GetTemp() { return temp; }
    friend istream& operator>>(istream& g, Water& ob)
    {
        cout << "Input place : ";
        g >> ob.place;
        cout << "Input date : ";
        g >> ob.data;
        cout << "Input temp of water : ";
        g >> ob.temp;
        cout << "Input speed of wave :";
        g >> ob.wave;
        return g;
    }

    friend ostream& operator<<(ostream& out, Water& ob)
    {
        out << "Date :  " << ob.data << "  Place : " << ob.place << "  Temp : " << ob.temp << "  Wave : " << ob.wave;
        return out;
    }

};
void LowerTemp(Water* arr, int n, double average);
void HighestWave(Water* arr, int n);

int main()
{
    Water arr[T];
    int n;
    double sum = 0, average;
    cout << "Input number of days : ";
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        sum += arr[i].GetTemp();
    }
    average = sum / n;
    cout << "\nAverage temp of water : " << average << endl;
    LowerTemp(arr, n, average);
    HighestWave(arr, n);
    return 0;
}

void LowerTemp(Water* arr, int n, double average)
{
    cout << "\n Days with the higher temp of water than average : \n\n";
    for (int t = 0; t < n; ++t)
    {
        if (arr[t].GetTemp() > average)
            cout << arr[t] << endl;
    }
}

void HighestWave(Water* arr, int n)
{
    Water copy[T];
    int i = 0;
    int lich = 0;
    double max;
    max = arr[i].GetWater();
    for (i; i < n; ++i)
    {
        if (arr[i].GetWater() > max)
        {
            lich = i;
        }
        else continue;
    }
    cout << "\nDay with the highest speed of wave : \n\n" << arr[lich];
}

//творити базовий клас ПРОГНОЗ ПОГОДИ (задаються місце та дата). 
//Створити похідний клас ПРОГНОЗ ЩОДО ВОДИ (задаються температура, швидкість хвилі).
//Для введених даних про прогноз погоди визначити середню температуру води, дні зі найвищою швидкістю хвилі та кількість днів з температурою води, 
//вищою за середнє значення.