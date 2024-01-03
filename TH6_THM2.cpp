#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

class Nguoi {
protected:
    string HoTen;
    int namSinh;

public:
    Nguoi() {
        HoTen = "";
        namSinh = 0;
    }

    Nguoi(string nHoTen, int nnamSinh) : HoTen(nHoTen), namSinh(nnamSinh) {}

    string getHoTen() {
        return HoTen;
    }

    int getTuoi() {
        return 2024 - namSinh;
    }

    void nhap() {
        cout << "\tNhap ten: ";
        cin.ignore();
        getline(cin, HoTen);
        cout << "\tNhap nam sinh: ";
        cin >> namSinh;
    }

    void xuat() {
    cout<<"Ho Ten: " << HoTen << " | " << "Tuoi: " << getTuoi() << " | " <<" ";    
    }
};

class BenhNhan : public Nguoi {
private:
    string tenBenhAn;
    int soNgayNamVien;
    float giaVienPhiNgay;

public:
    BenhNhan() : Nguoi() {
        tenBenhAn = "";
        soNgayNamVien = 0;
        giaVienPhiNgay = 0.0;
    }

    BenhNhan(string nHoTen, int nnamSinh, string nTenBenhAn, int nSoNgayNamVien, float nGiaVienPhiNgay)
        : Nguoi(nHoTen, nnamSinh), tenBenhAn(nTenBenhAn), soNgayNamVien(nSoNgayNamVien), giaVienPhiNgay(nGiaVienPhiNgay) {}

    void nhapThongTin() {
        Nguoi::nhap();
        cout << "\tNhap ten benh an: ";
        cin.ignore();
        getline(cin, tenBenhAn);
        cout << "\tNhap so ngay nam vien: ";
        cin >> soNgayNamVien;
        cout << "\tNhap gia vien phi/ngay: ";
        cin >> giaVienPhiNgay;
    }

    float TienVienPhi() {
        return soNgayNamVien * giaVienPhiNgay;
    }

    void xuatThongTin() {
        Nguoi::xuat();
        cout << "Ten benh an: " << tenBenhAn << " | " <<"So ngay nam vien: " << soNgayNamVien << " | " << "Gia vien phi: "<<giaVienPhiNgay<< " | " <<"Tien vien phi: " << TienVienPhi() ;    
};

class BacSi : public Nguoi {
private:
    string MaBS;
    float soNgayLamViec;
    float tienCongNgay;

public:
    BacSi() : Nguoi() {
        MaBS = "";
        soNgayLamViec = 0.0;
        tienCongNgay = 0.0;
    }

    BacSi(string nHoTen, int nnamSinh, string nMaBS, float nSoNgayLamViec, float nTienCongNgay)
        : Nguoi(nHoTen, nnamSinh), MaBS(nMaBS), soNgayLamViec(nSoNgayLamViec), tienCongNgay(nTienCongNgay) {}

    void nhapThongTin() {
        Nguoi::nhap();
        cout << "\tNhap ma bac si: ";
        cin.ignore();
        getline(cin, MaBS);
        cout << "\tNhap so ngay lam viec: ";
        cin >> soNgayLamViec;
        cout << "\tNhap tien cong/ngay: ";
        cin >> tienCongNgay;
    }

    float TienCongThang() {
        return soNgayLamViec * tienCongNgay;
    }

    void xuatThongTin() {
        Nguoi::xuat();
        cout << "Ma bac si: " << MaBS << " | " <<"So ngay lam viec: " << soNgayLamViec << " | " <<"Tien cong ngay: " << tienCongNgay << " | "<<"Tien cong thang: " << TienCongThang();
    }
};

void XuatBangBenhNhan(vector<BenhNhan> &DanhSachBN) {
    cout << left << setw(15) << "Ho ten" << setw(15) << "Tuoi"
        << setw(25) << "Ten benh an" << setw(20) << "So ngay nam vien"
        << setw(20) << "Gia vien phi/ngay" << setw(20) << "Tien vien phi" << endl;

    for (int i = 0; i < DanhSachBN.size(); i++) {
        DanhSachBN[i].xuatThongTin();
        cout << endl;
    }
}

void XuatBangBacSi(vector<BacSi> &DanhSachBS) {
    cout << left << setw(15) << "Ho ten" << setw(15) << "Nam sinh"
        << setw(15) << "MaBS" << setw(15) << "So ngay lam viec"
        << setw(15) << "Tien cong/ngay" << setw(15) << "Tien cong thang" << endl;

    for (int i = 0; i < DanhSachBS.size(); i++) {
        DanhSachBS[i].xuatThongTin();
        cout << endl;
    }
}

int main() {
    int nBenhNhan, nBacSi;

    vector<BenhNhan> DanhSachBN;
    vector<BacSi> DanhSachBS;

    cout << "Nhap so luong benh nhan: ";
    cin >> nBenhNhan;
    for (int i = 0; i < nBenhNhan; i++) {
        BenhNhan temp;
        cout << "Nhap thong tin cho benh nhan thu " << i + 1 << ":" << endl;
        temp.nhapThongTin();
        DanhSachBN.push_back(temp);
    }

    cout << "Nhap so luong bac si: ";
    cin >> nBacSi;
    for (int i = 0; i < nBacSi; i++) {
        BacSi temp;
        cout << "Nhap thong tin cho bac si thu " << i + 1 << ":" << endl;
        temp.nhapThongTin();
        DanhSachBS.push_back(temp);
    }

    cout << "\t===== BANG THONG TIN BENH NHAN =====" << endl;
    XuatBangBenhNhan(DanhSachBN);

    cout << "\t===== BANG THONG TIN BAC SI =====" << endl;
    XuatBangBacSi(DanhSachBS);

    return 0;
}
