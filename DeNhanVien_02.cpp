#include<iostream>
#include<vector>
#include<string>
using namespace std;
class NhanVien{
    protected:
        string Ten;
        int NamSinh;
        string GioiTinh;
        float Luong;
    public:
        //ham tao ko tham so
        NhanVien():Ten("0"),NamSinh(0),GioiTinh("0"),Luong(0.0){};
        //ham tao voi 4 tham so
        NhanVien(string nTen,int nNamSinh,string nGioiTinh,float nLuong):Ten(nTen),NamSinh(nNamSinh),GioiTinh(nGioiTinh),Luong(nLuong){};

        virtual void Nhap(){
            cout<<"Nhap ho ten: ";
            cin.ignore();
            getline(cin,Ten);
            cout<<"Nhap nam sinh: ";
            cin>>NamSinh;
            cout<<"Nhap gioi tinh: ";
            cin.ignore();
            getline(cin,GioiTinh);
            cout<<"Nhap luong: ";
            cin>>Luong;
        }
        virtual void Xuat(){
            cout<<"Ho Ten: "<<Ten<<" | "<<"Nam Sinh: "<<NamSinh<<" | "<<"Gioi Tinh: "<<GioiTinh<<" | "<<"Luong: "<<Luong<<" | ";
        }
        string getTen() const { 
            return Ten; 
        }
};

class LapTrinhVien:public NhanVien{
    private:
        string NgonNguLT;
    public:
        LapTrinhVien(): NgonNguLT("0"){};
        LapTrinhVien(string nTen,int nNamSinh,string nGioiTinh,float nLuong,string nNgonNguLT):NhanVien(nTen,nNamSinh,nGioiTinh,nLuong),NgonNguLT(nNgonNguLT){}

        void Nhap() override{
            NhanVien::Nhap();
            cin.ignore();
            cout<<"Nhap ngon ngu lap trinh: ";
            getline(cin,NgonNguLT);
        }

        void Xuat()override{
            NhanVien::Xuat();
            cout<<"Ngon Ngu Lap Trinh: "<<NgonNguLT;
        }
};

class KiemThu:public NhanVien{
    private:
        string ChuyenMon;
    public:
    KiemThu():ChuyenMon("0"){};
    KiemThu(string nTen,int nNamSinh,string nGioiTinh,float nLuong,string nChuyenMon):NhanVien(nTen,nNamSinh,nGioiTinh,nLuong),ChuyenMon(nChuyenMon){}

    void Nhap() override{
        NhanVien::Nhap();
        cin.ignore();
        cout<<"Nhap chuyen mon(giao dien/chuc nang): ";
        getline(cin,ChuyenMon);
    }

    void Xuat() override{
        NhanVien::Xuat();
        cout<<"Chuyen Mon: "<<ChuyenMon;
    }
};
void ChuongTrinhChinh(){
    int n;
    vector<NhanVien*> DanhSachNV;
    do{
    cout << "Nhap so luong nhan vien (0 < n < 10): ";
    cin >> n;
    cin.ignore(); 
    if (n < 1 || n > 10) {
        cout << "So luong nhan vien khong hop le.Vui long nhap lai!" << endl;
     }
    }while (n < 1 || n > 10);

    for (int i = 0; i < n; ++i) {
        cout << "Chon loai nhan vien: " << endl;
        //cout << "1. Nhan Vien" << endl;
        cout << "1. Lap Trinh Vien" << endl;
        cout << "2. Kiem Thu" << endl;

        int choice;
        cout << "Nhap lua chon: ";
        cin >> choice;
        cin.ignore();

        switch (choice){
            case 1:{
                LapTrinhVien* ltv = new LapTrinhVien();
                ltv->Nhap();
                DanhSachNV.push_back(ltv);
                break;
            }
            case 2:{
                KiemThu* kt = new KiemThu();
                kt->Nhap();
                DanhSachNV.push_back(kt);
                break;
            }
            default:
                cout << "Lua chon khong hop le!" << endl;
                break;
        }
    }

    cout << "\n===== DANH SACH NHAN VIEN =====" << endl;
    for (int i = 0; i < DanhSachNV.size(); ++i) {
        DanhSachNV[i]->Xuat();
        cout << endl;
    }

    // Tìm kiếm nhân viên theo họ tên
    string searchName;
    cout << "\nNhap ten nhan vien can tim kiem: ";
    cin.ignore();
    getline(cin, searchName);

    cout << "\n===== KET QUA TIM KIEM =====" << endl;
    bool found = false;
    for (int i = 0; i < DanhSachNV.size(); ++i) {
        if (DanhSachNV[i]->getTen() == searchName) {
            DanhSachNV[i]->Xuat();
            cout << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Khong tim thay nhan vien co ten \"" << searchName << "\"" << endl;
    }
}

int main(){
    ChuongTrinhChinh();

    return 0;
}