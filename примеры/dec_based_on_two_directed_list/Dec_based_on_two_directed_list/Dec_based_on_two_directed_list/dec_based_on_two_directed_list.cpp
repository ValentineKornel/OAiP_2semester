#include <iostream>// ����������� ����������� ���������� �����-������.
using namespace std;// ������������� ������������ ���� std.

struct node// ����������� ��������� ����� ������.
{
    int elem; // �������������� ���� �����.
    node* sled; // ��������� �� ��������� ������� ������.
    node* pred; // ��������� �� ���������� ������� ������.
};

class Spisok// ����������� ������ ����.
{
private:
    node* nd; // ��������� �� ������ ����.
    node* kd; // ��������� �� ����� ����.
    int klad; // �������������� ���� ���������� ��������.
public:
    void BuiltDeck(); // �������� ����.
    void VyvodDeck(); // ����� ����.
    void InsLeft(int); // ������� �������� �����.
    void InsRight(int); // ������� �������� ������.
    void DelLeft(); // �������� �������� �����.
    void DelRight(); // �������� �������� ������.
    int Get_Klad() { return klad; } // ��������� �������� ���������� ��������.
    void Ochistka(); // ������� ����.
};

void main() // ������� ������� ���������.  
{
    setlocale(LC_ALL, "Rus"); // ��������� ������ ��� ������ �� ���������.
    Spisok A;// �������� ������� ������ ����.
    int el;// ���������� ���������� ��� ����� ��������� ����.

    A.BuiltDeck();// �������� ����;
    A.VyvodDeck();// ����� ���� �� �����
    cout << "������� ������� �����, ������������ ������: ";
    cin >> el; A.InsRight(el); A.VyvodDeck();// ������� �������� ������ � ����� ���� �� �����
    cout << "������� ������� �����, ������������ �����: ";
    cin >> el; A.InsLeft(el); A.VyvodDeck();// ������� �������� ����� � ����� ���� �� �����
    cout << "������ ����� ������: \n";
    A.DelRight(); A.VyvodDeck();// �������� �������� ����� � ����� ���� �� �����
    cout << "��� ������ �������: " << A.Get_Klad() << endl;//����� �������� ���������� ��������
    cout << "������ ����� �����: \n";
    A.DelLeft(); A.VyvodDeck();// �������� �������� ������ � ����� ���� �� �����
    cout << "��� ������ �������: " << A.Get_Klad() << endl;//����� �������� ���������� ��������
    A.Ochistka(); //������� ����

    cout << "\n";
    system("PAUSE");// �������� ����� �������������.
}

void Spisok::BuiltDeck()
// ���������� ���� �� ���� ����������������
// ������ � ��������� ������.
// nd - ��������� �� ������ ����,
// *kd - ��������� �� ����� ����.
{
    node* q;// ���������� ���������� �� ���� ��������� node � ���������� el, ���������� �������
    node* z;
    int  el;

    nd = new(node);// �������� ������������� ���� ���� � ��� �������������
    z = nd;
    (*nd).pred = (*nd).sled = NULL;
    cout << "������� ������������������: \n"; // ������������ ������ ������������������ ���������, ������� ����� �������� � ���
    cin >> el;
    while (el != 0)// ���� ������������ �� ������ 0
    {
        (*z).sled = new (node);// ������� ����� ���� � ��������� ��� � ���������� �����
        (*((*z).sled)).pred = z;
        z = (*z).sled; // �������� ��������� �� ����� ����
        (*z).sled = NULL;
        (*z).elem = el;// �������������� ������� ����
        cin >> el;// ��������� ����� �������
    }
    if ((*nd).sled != NULL)// ���� � ���� ���� ���� �� ���� �������, �� ��������� ��������� nd � kd, ������� ������������ ����
    {
        q = nd; nd = (*nd).sled; (*nd).pred = NULL;
        kd = z; delete q;
    }
    else // ���� � ���� ��� ���������, �� ������� ������������ ���� � �������� ��������� nd � kd
    {
        delete nd; nd = kd = NULL;
    }
}

void Spisok::VyvodDeck()
// ����� ����������� ����.
// nd - ��������� �� ������ ����.
{
    node* z;

    z = nd; // ���������� ��������� z ���������� ������ ����.
    cout << "���������� ����: "; // ����� ��������� � ���������� ����.
    if (z != NULL) // �������� �� ������� ����.
        while (z != NULL) // ���� ��� ������ ������� �������� ����.
        {
            cout << (*z).elem << " "; // ����� �������� �������� ��������.
            z = (*z).sled; // ������� � ���������� ��������.
        }
    else  cout << "�� ����!\n"; // ����� ���������, ���� ��� ������.
    cout << endl; // ������� ������ ����� ������ ����������� ����.

}
void Spisok::InsLeft(int el)
// ���������� �����, ����������� ������� el, � ��� �����.
// nd - ��������� �� ������ ����,
// kd - ��������� �� ����� ����.
{
    node* q;

    q = new(node); // �������� ������ ��� ����� ����
    (*q).elem = el; // ����������� ������� ������ ����
    if (nd == NULL) // ���� ��� ����
    {
        nd = q; (*q).sled = (*q).pred = NULL; kd = q; // ��������� ������ ������� � ��������� �� ���� nd � kd
    }
    else
    {
        (*q).sled = nd; (*q).pred = NULL; // ����� ���� ���������� ������ � �� ����� �����������
        (*nd).pred = q; nd = q; // ���������� ���� ���������� ������, � ��������� �� ������ ������� �����������
    }

}

void Spisok::InsRight(int el)
// ���������� �����, ����������� ������� el, � ��� ������.
// nd - ��������� �� ������ ����,
// kd - ��������� �� ����� ����.
{
    node* q;
    q = new(node); // �������� ������ ����� � ������������ ��� �������� el.
    (*q).elem = el;
    if (kd == NULL) // ���� ��� ����, �� ����� ������� ���������� ������� � ������ ����.
    {
        nd = q; (*q).sled = (*q).pred = NULL; kd = q;
    }
    else // ����� ���������� ����� � ����� ����.
    {
        (*q).sled = NULL; (*q).pred = kd;
        (*kd).sled = q; kd = q;
    }
}

void Spisok::DelLeft()
// �������� ����� �� ���� ����� � ����������
// �������� ���������� ����� � ���������� klad.
// nd - ��������� �� ������ ����,
// kd - ��������� �� ����� ����.
{
    node* q;

    if ((*nd).sled != NULL)// ���� � ���� ���� ������ ������ ��������, �� ������� ������ �������.
    {
        q = nd;// q - ��������� �� ������ �������
        klad = (*q).elem;// ���������� ������� ���������� �����
        nd = (*nd).sled; // ��������� ��������� �� ������ �������
        (*nd).pred = NULL;// �������� ��������� �� ���������� �������
        delete q;// ������� ������ �������
    }
    else// ���� � ���� ������ ���� �������, �� ������� ��� � �������� ���������.
    {
        q = nd;// q - ��������� �� ������������ ������� � ����
        klad = (*q).elem;// ���������� ������� ���������� �����
        nd = kd = NULL;  // �������� ��������� �� ������ � ����� ����
        delete q;// ������� ������� �� ����
        cout << "��� ����!\n"; // ������� ��������� � ���, ��� ��� ���� ������
    }
}

void Spisok::DelRight()
// �������� ����� �� ���� ������ � ����������
// �������� ���������� ����� � ���������� klad.
// nd - ��������� �� ������ ����,
// kd - ��������� �� ����� ����.
{
    node* q;

    if ((*kd).pred != NULL) // ���� � ���� ������ ������ ��������
    {
        q = kd; // q - ��������� �� ��������� �������
        klad = (*q).elem; // ���������� ������� ���������� �����
        kd = (*kd).pred; // ��������� ��������� �� ��������� �������
        (*kd).sled = NULL; // �������� ��������� �� ��������� �������
        delete q; // ������� ��������� �������
    }
    else // ���� � ���� ������ ���� �������
    {
        q = kd; // q - ��������� �� ������������ ������� � ����
        klad = (*q).elem; // ���������� ������� ���������� �����
        nd = kd = NULL; // �������� ��������� �� ������ � ����� ����
        delete q; // ������� ������� �� ����
        cout << "��� ����!\n"; // ������� ��������� � ���, ��� ��� ���� ������
    }

}

void Spisok::Ochistka()
{
    node* q, * q1;

    q = nd;  // ������������� ��������� �� ������ ����.
    q1 = (*q).sled;  // ������������� ��������� �� ������ ������� ����.
    while (q1 != NULL)
    { // ������� ��� �������� ����, ������� �� ������� �� ����������.
        delete q; q = q1; q1 = (*q).sled;
    }
    delete q; // ������� ��������� �������.
    nd = kd = NULL; // ������������� ��������� ������ � ����� ���� � NULL, ��� ��� ��� ����.

}
