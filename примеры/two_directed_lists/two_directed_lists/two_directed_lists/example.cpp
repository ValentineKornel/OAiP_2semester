/*#include <iostream> // ����������� ���������� ��� ����������� �������� �����/������
using namespace std; // ��������� using, ������� ��������� ������������ ������������ ���� std ��� �������� �������� std.

struct node // ����������� ��������� �������� ������
{
    int elem; // �������������� ����
    node* sled; // ��������� �� ��������� �������
    node* pred; // ��������� �� ���������� �������
};
class Spisok // ����� ��� ������ �� �������
{
private:
    node* nsp, * ksp;  // ��������� �� ������ � ����� ������
public:
    Spisok() { nsp = ksp = NULL; } // ����������� ������, ���������������� ������ � ����� ������
    void Postroenie(); // ������� ��� ���������� ������
    void VyvodForward(); // ������� ��� ������ ������ � ������ �����������
    void VyvodBack(); // ������� ��� ������ ������ � �������� �����������
    void Ochistka(); // ������� ��� ������� ������
    void InsAfter(int, node*);// ������� ��� ������� ������ �������� ����� ���������
    void InsBefore(int, node*); // ������� ��� ������� ������ �������� ����� ��������
    void Delete(node*); // ������� ��� �������� ��������� ��������
    void DelAfter(node*); // ������� ��� �������� �������� ����� ���������
    node* PoiskForward(int);// ������� ��� ������ �������� ������ � ������ �����������
    node* PoiskBack(int); // ������� ��� ������ �������� ������ � �������� �����������
};
void main() // ������� ������� ���������
{
    setlocale(LC_ALL, "Rus"); // ��������� ������ �� ������� ����
    Spisok A; // �������� ������� ������ Spisok
    node* Res; // ��������� �� ������� ������
    int el, el1; // ���������� ��� ����� ��������� ������

    A.Postroenie(); // ���������� ������
    A.VyvodForward(); A.VyvodBack(); // ����� ������ � ������ � �������� ������������

    cout << "������� ������� �����, ����� �������� ";
    cout << "�������������� �������: ";
    cin >> el; //���� ��������, ����� �������� ����� ������������ �������
    cout << "������� ������� ������������ �����: ";
    cin >> el1;  //���� ��������, ������� ����� ���������
    Res = A.PoiskForward(el); // ����� �������� ����� �������� ����� ������������ �������
    if (Res != NULL) // ���� ����� ������� ������
    {
        A.InsAfter(el1, Res);  // ������� ������ �������� ����� ��������� ��������
        A.VyvodForward(); A.VyvodBack(); // ����� ������ � ������ � �������� ������������
    }
    else  cout << "����� � �������� ��������� � ������ ���!\n";  // ���� ������� �� ������

    cout << "������� ������� �����, ����� ������� ";
    cout << "�������������� �������: ";
    cin >> el; //���� ��������, ����� ������� ����� ��������� �������
    cout << "������� ������� ������������ �����: ";
    cin >> el1; //���� ��������, ������� ����� ���������
    Res = A.PoiskBack(el); // ����� ��������, ����� ������� ����� ��������� ����� �������
    if (Res != NULL) // ���� ����� ������� ������
    {
        A.InsBefore(el1, Res);  //������� ������ �������� ����� �������� ���������
        A.VyvodForward(); A.VyvodBack(); // ����� ������ � ������ � �������� ������������
    }
    else  cout << "����� � �������� ��������� � ������ ���!\n"; // ���� ����� ������� �� ������

    cout << "������� ������� �����, ����� �������� ";
    cout << "�������������� ��������: ";
    cin >> el; // ���� ��������, ����� �������� ����� ������������� ��������
    Res = A.PoiskForward(el); // ����� ��������, ����� �������� ����� ������������� ��������
    if (Res != NULL) // ���� ����� ������� ������
    {
        A.DelAfter(Res); // �������� �������� ����� ��������� ��������
        A.VyvodForward(); A.VyvodBack(); // ����� ������ � ������ � �������� ������������
    }
    else  cout << "����� � �������� ��������� � ������ ���!\n"; //���� ����� ������� �� ������

    cout << "������� ������� �����, ������� ";
    cout << "���� �������: ";
    cin >> el; // ���� �������� ������� ���������� �������
    Res = A.PoiskForward(el); // ����� ��������, ������� ���������� �������
    if (Res != NULL) //���� ����� ������� ������
    {
        A.Delete(Res); //�������� ��������� ��������
        A.VyvodForward(); A.VyvodBack(); // ����� ������ � ������ � �������� ������������
    }
    else  cout << "����� � �������� ��������� � ������ ���!\n"; //���� ����� ������� �� ������

    A.Ochistka(); //������ ������

    cout << "\n"; // ������� �� ����� ������
    system("PAUSE");//�������� ������� ����� �������
}
void Spisok::Postroenie()
//���������� ���������������� ������ � ��������� ������:
// nsp - ��������� �� ������ ������,
// ksp - ��������� �� ����� ������.
{
    node* rsp; // ��������� �� ������� ����� ������
    int el; // ���������� ��� ����� ���������

    nsp = new(node); // �������� ���������� �����
    rsp = nsp; //������� ����� ��������� �� ������ ������
    (*nsp).pred = NULL; (*nsp).sled = NULL; //��������� ����������
    cout << "������� ������������������:\n";
    cin >> el; //���� �������� ������������������
    while (el != 0) //���� �� ������ ����
    {
        (*rsp).sled = new(node); // �������� ������ �����
        (*((*rsp).sled)).pred = rsp; // ��������� ��������� �� ���������� �����
        rsp = (*rsp).sled; // ����������� ��������� �� ��������� �����
        (*rsp).sled = NULL; (*rsp).elem = el; // ��������� �������� �������� �����
        cin >> el; //���� �������� ������������������
    }
    ksp = rsp; // ��������� ��������� �� ����� ������

}

void Spisok::VyvodForward()
//����� ����������� ���������������� ������ �� ��� ������.
// nsp - ��������� �� ������ ������, ksp - ��������� �� ����� ������.
{
    node* rsp; // ���������� ��������� �� ����� ������
    rsp = (*nsp).sled; // ������������� ��������� �� ������ ������� ������ (����� ������������� �����)
    cout << "��������������� ������ ��������: ";
    while (rsp != NULL)// ���� ��������� �� ��������� �� ������� ���������
    {
        cout << (*rsp).elem << " ";// ����� �������� �������� �� �����
        rsp = (*rsp).sled;// ����������� ��������� �� ��������� �������
    }
    cout << endl; // ����� ������� �������� ������
}

void Spisok::VyvodBack()
//����� ����������� ���������������� ������ �� ��� �����.
// nsp - ��������� �� ������ ������, ksp - ��������� �� ����� ������.
{
    node* rsp; // ���������� ��������� �� ����� ������

    rsp = ksp; // ������������� ��������� �� ��������� ������� ������
    cout << "��������������� ������ � �������� �������: ";
    while ((*rsp).pred != NULL) // ���� ��������� �� ��������� �� ������� ���������
    {
        cout << (*rsp).elem << " "; ;// ����� �������� �������� �� �����
        rsp = (*rsp).pred; // ����������� ��������� �� ��������� �������
    }
    cout << endl; // ����� ������� �������� ������
}

node* Spisok::PoiskForward(int el)
//������� ���������� ��������� �� ��������� ������� el
//���������������� ������, ��������� �����������  nsp
// � ksp, ��� NULL, ���� ������� � ������ �� ������.
{
    node* q;  //������� ���������
    node* Res; //��������� ��� ��������� ��������

    Res = NULL; q = (*nsp).sled; //������������� ��������� �� NULL � ������ ������ � ������� �������� ������
    while (q != NULL && Res == NULL) //���� �� ����� �� ����� ������ � �� ����� ������� el, ���� �� ������
        if ((*q).elem == el) Res = q; // ���� ������� ������, ���������� ��������� � Res
        else  q = (*q).sled; // ��������� � ���������� ��������
    return Res; //���������� ��������� ������� ��� NULL, ���� �� ������
}

node* Spisok::PoiskBack(int el)
//������� ���������� ��������� �� ��������� ������� el
//���������������� ������, ��������� �����������  nsp
// � ksp, ��� NULL, ���� ������� � ������ �� ������.
{
    node* q; //������� ���������
    node* Res; //��������� ��� ��������� ��������

    Res = NULL; q = ksp; //������������� ��������� �� NULL � ������ ������ � ������� �������� ������
    while (q != NULL && Res == NULL) //���� �� ����� �� ����� ������ � �� ����� ������� el, ���� �� ������
        if ((*q).elem == el) Res = q; // ���� ������� ������, ���������� ��������� � Res
        else  q = (*q).pred; // ��������� � ���������� ��������
    return Res; //���������� ��������� ������� ��� NULL, ���� �� ������
}

void Spisok::InsAfter(int el, node* Res)
//������� ����� � �������������� ����� el �
//� ��������������� ������, �������� �����������
// nsp � ksp, ����� �����, �� ������� ��������� Res.
{
    node* q; //������� ���������

    q = new(node); // �������� ������ �����
    (*q).elem = el; // ������������� ��������������� ���� ����� ����� ���������
    if ((*Res).sled != NULL) // ���� Res �� �������� ��������� ������ ������
    {
        (*q).sled = (*Res).sled; // ��������� ��������� ���������� ����� ������ ����� �� ��������� �� Res �������
        (*q).pred = (*(*Res).sled).pred; // ��������� ��������� ����������� ����� ������ ����� �� ���������� �� Res �������
        (*(*Res).sled).pred = q; // ��������� ��������� ����������� ����� ���������� �� Res ����� �� q
        (*Res).sled = q; // ��������� ��������� ���������� ����� Res �� q
    }
    else // ���� Res �������� ��������� ������ ������
    {
        (*q).sled = NULL; // ��������� ��������� ���������� ����� ������ ����� �� NULL
        (*q).pred = Res; // ��������� ��������� ����������� ����� ������ ����� �� Res
        ksp = q; // ��������� ��������� �� ��������� ������� ������ �� q
        (*Res).sled = q; // ��������� ��������� ���������� ����� Res �� q
    }

}

void Spisok::InsBefore(int el, node* Res)
//������� ����� � �������������� ����� el �
//� ��������������� ������, �������� �����������
// nsp � ksp, ����� ������, �� ������� ��������� Res.
{
    node* q; //������� ���������
    q = new(node); // �������� ������ �����
    (*q).elem = el; // ������������� ��������������� ���� ����� ����� ���������
    (*q).sled = (*(*Res).pred).sled; // ����� ������� "�����������" �� ��������� ��������� ����� Res
    (*q).pred = (*Res).pred; // ���������� ������� ����� Res ���������� ���������� ��� ������ ��������
    (*(*Res).pred).sled = q;  // ��������� ��������� ����� ����������� �������� ���������� ����� �������
    (*Res).pred = q; // ������� Res ������ ���������� ��� ������ ��������
}

void Spisok::Delete(node* Res)
//�������� ����� �� ���������������� ������.
// nsp - ��������� �� ������ ������,
// ksp - ��������� �� ����� ������,
// Res - ��������� �� ��������� �����.
{
    if ((*Res).sled != NULL) // ���� ������� �� ���������
    {
        (*(*Res).sled).pred = (*Res).pred; // ���������� ��� ���������� �������� ����� Res ���������� ���������� ������� Res
        (*(*Res).pred).sled = (*Res).sled; // ��������� �� ���������� ��������� ���������� ��������� ������� Res
        delete Res; // �������� ��������
    }
    else // ���� ������� ���������
    {
        (*(*Res).pred).sled = NULL; // ���������� ������� ���������� ���������
        ksp = (*ksp).pred; // �������� ������� ������ ���������� �������������
        delete Res; // �������� ��������
    }
}

void Spisok::DelAfter(node* Res)
//�������� ����� �� ���������������� ������.
// nsp - ��������� �� ������ ������,
// ksp - ��������� �� ����� ������,
// Res - ��������� �� �����, ���������� ����������.
{
    node* q; //������� ���������

    if ((*Res).sled == NULL) // ���������, �������� �� ��������� ����� ��������� ������ � ������.
    {
        cout << "������� ��������� �����!\n";
    }
    else
    {
        if ((*(*Res).sled).sled != NULL) // ���� ��������� ����� �� �������� ���������, �� �������������� ��������� ������ ����.
        {
            q = (*Res).sled; // ��������� ��������� �� ��������� �����.
            (*(*(*Res).sled).sled).pred = Res; // �������������� ��������� �� ���������� �����.
            (*Res).sled = (*(*Res).sled).sled; // �������������� ��������� �� ��������� �����.
            delete q; // ������� �����.
        }
        else // ���� ��������� ����� �������� ���������, �� ������ ������� ��� � �������������� ��������� �� ��������� ����� � ������ �� ���������� �����.
        {
            q = (*Res).sled; // ��������� ��������� �� ��������� �����.
            (*Res).sled = NULL; // �������������� ��������� �� ��������� ����� �� NULL.
            ksp = (*ksp).pred; // �������������� ��������� �� ��������� ����� �� ���������� �����.
            delete q; // ������� �����.
        }
    }

}

void Spisok::Ochistka()
//�������� ���������������� ������ �� ������.
// nsp - ��������� �� ��������� ����� ������,
// ksp - ��������� �� ��������� ����� ������.
{
    node* q, * q1;  // ������� ���������

    q = nsp; // ������������� ��������� q �� ��������� ����� ������.
    q1 = (*q).sled; // ������������� ��������� q1 �� ��������� �����.
    while (q1 != NULL) // ���� �� ��������� ����� ������.
    {
        q = q1; // ���������� ��������� q �� ��������� �����.
        q1 = (*q1).sled; // ���������� ��������� q1 �� ��������� �����.
        delete q; // ������� �����.
    }
    delete nsp; // ������� ��������� ����� ������.
    nsp = ksp = NULL; // ������������� ��������� �� NULL.

}
*/