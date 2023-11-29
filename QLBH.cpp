#include<iostream>
#include<string>
using namespace std;
class NVBH{
	private:
		int manv;
 		string ten;
		string diachi;
		int sdt;
		string nkhd;
	public:
		void nhap();
		void xuat();
};
class MH{
	private:
		int mahang;
		string tenhang;
		string nhomhang;
		long long giaban;
		int soluong;
	public:
		void nhap();
		void xuat()
;};
class BDSBH{
	
};
void NVBH::nhap(){
	cout << "MaNV:";cin >> manv;
	cin.ignore();
	cout << "Hoten:";getline(cin,ten);
	cout << "Diachi:";getline(cin,diachi);
	cout << "Sdt:";cin >> sdt;
	cin.ignore();
	cout << "Ngay ki hop dong:";getline(cin,nkhd);
}
void NVBH::xuat(){
	cout << manv << "-" << ten << "-" << diachi << "-" << sdt << "-" << nkhd;
}
void MH::nhap(){
	cin.ignore();
	cout << "Ma hang:";cin >> mahang;
	cin.ignore();
	cout << "Ten hang:";getline(cin,tenhang);
	cout << "Nhom hang:";getline(cin,nhomhang);
	cout << "Gia ban:";cin >> giaban;
	cout << "So luong:";cin >> soluong;
}
void MH::xuat(){
	cout << mahang << "-" << tenhang << "-" << nhomhang << "-" << giaban << "-" << soluong;
}

int main()
{
	int n,m;
	NVBH a[1000];
	MH b[1000];
	cout << "So luong danh sach mat hang moi:";cin >> n;
	cout << "Nhap danh sach mat hang moi:" << endl;
	for(int i=0;i<n;i++)
	{
		b[i].nhap();
	}
	cout << "Cac mat hang:" << endl;
	for(int i=0;i<n;i++)
	{
		b[i].xuat();
		cout << endl;
	}
	cout << "So luong nhan vien:";cin >> m;
	cout << "Nhap danh sach nhan vien:" << endl;
	for(int i=0;i<m;i++)
	{
		a[i].nhap();
	}
	cout << "Danh sach nhan vien:" << endl;
	for(int i=0;i<m;i++)
	{
		a[i].xuat();
		cout << endl;
	}
	return 0;
}
