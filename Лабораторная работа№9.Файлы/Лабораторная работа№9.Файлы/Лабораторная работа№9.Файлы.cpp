#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Vvod(int N1, int N2, int n)
{
    if (N2 - N1 == 1)
    {
        cout << "����� �������� N1 � N2 ��� �����."<<endl;
    }
    else
    {
        ifstream F1("F1.txt");
        ofstream F2("F2.txt");
        if (F1.is_open() && F2.is_open())
        {
            int i = 1;
            while (!F1.eof())
            {
                string str;
                getline(F1, str);
                if (str[0] == '�')
                {
                    if ((i > N1) && (i < N2))
                    {
                        F2 << str << endl;
                    }
                }
                i++;
            }
            F1.close();
            F2.close();
        }
        else
            cout << "�� ������� ������� ����� F1.txt ��� F2.txt ��� �����������."<< endl;
    }
}

void Shet(int i, int j, int k, int num)
{
    ifstream F2("F2.txt");
    if (F2.is_open())
    {
        while (!F2.eof())
        {
            string str;
            getline(F2, str);
            i = 0;
            while (str[i] !=NULL)
            {
                if (str[i] != ' ' && str[i] != '�' && str[i] != '�' && str[i] != '�' && str[i] != '�' &&
                    str[i] != '�' && str[i] != '�' && str[i] != '�' && str[i] != '�' && str[i] != '�')
                    j++;
                i++;
            }
            if (j > k)
            {
                k = j;
                num++;
            }
            j = 0;
        }
        if (k != 0)
            cout << "������ ����� ��������� ���� � ������ ��� � " << num << ", ���������� ��������� ���� = " << k;
        else
            cout << "� ����� F2.txt ��� ����� ��� ��� ����� � ���������� �������.";
    }
    else
        cout<< "�� ������� ������� ���� F2.txt ��� �������� ��������� ����.";
}

int main()
{
    system("color F0");
    setlocale(0, "");
    int n = 0;
    int N1, N2;
    ifstream F1("F1.txt");
    if (F1.is_open())
    {
        while (!F1.eof())
        {
            string str;
            getline(F1, str);
            n++;
        }
    }
    else
        cout << "�� ������� ������� ���� F1.txt ��� �������� �����.";
    F1.close();
    if (n > 2)
    {
        cout << "������� N1: ";
        cin >> N1;
        while ((N1 <= 0) || (N1 > n - 2))
        {
            cout << "������� N1: ";
            cin >> N1;
        }
        cout << "������� N2: ";
        cin >> N2;
        while ((N2 <= N1) || (N2 > n))
        {
            cout << "������� N2: ";
            cin >> N2;
        }
        Vvod(N1, N2, n);
        Shet(0, 0, 0, 0);
    }
    else
        cout << "���� F1 �� ��� ������ ��� � �� ������ ���� �����.";
    return 0;
}

