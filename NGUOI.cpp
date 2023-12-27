#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;
class NGUOI{
    protected:
        string HoTen;
        int namSinh;
        int MSV;
    public:
        NGUOI(){
            HoTen = "";
            namSinh = 0;
            MSV = 0;
        }
        NGUOI(string nHoTen, int nnamSinh, int nMSV): HoTen(nHoTen),namSinh(nnamSinh),MSV(nMSV){}
        string getHoTen() {
            return HoTen;
        }
        void setHoTen(string value){
            HoTen = value;
        }
        int getnamsinh(){
            return namSinh;
        }
        void setnamsinh(int value){
            namSinh = value ;
        }
        int getMSV(){
            return MSV;
        }
        void setMSV(int value){
            MSV = value;
        }
        void nhap(){
            cout<<"\tNhap ten: ";cin.ignore();
            getline(cin,HoTen);
            cout<<"\tNhap nam sinh: ";
            cin>>namSinh;
            cout<<"\tNhap ma sinh vien: ";
            cin>>MSV;
        }
        void xuat(){
            cout << setw(15) << HoTen << setw(15) << namSinh << setw(15) << MSV << endl;
        }
};
bool SoSanhTheoMSV(NGUOI a,NGUOI b){
    return a.getMSV() < b.getMSV();
}
bool SoSanhTheoTen(NGUOI a,NGUOI b){
    return a.getHoTen() < b.getHoTen();
}
void NhapDanhSachNguoi(vector<NGUOI> &DanhSachNguoi){
    int songuoi;
    cout<<"Nhap so luong nguoi: ";
    cin>>songuoi;
    for(int i = 0;i<songuoi;i++){
        NGUOI temp;
        cout << "Nhap thong tin cho nguoi " << i + 1 << ":" << endl;
        temp.nhap();
        DanhSachNguoi.push_back(temp);
    }
}
void XuatDanhSachNguoi(vector<NGUOI> &DanhSachNguoi){
    cout<<left<<setw(15)<<"Ho ten"<<setw(15)<<"Nam sinh"<<setw(15)<<"MSV"<<endl;
    for(int i = 0;i<DanhSachNguoi.size();i++){
        DanhSachNguoi[i].xuat();
    }
}
void SapXepDanhSachNguoiTheoMSV(vector<NGUOI> &DanhSachNguoi){
    sort(DanhSachNguoi.begin(),DanhSachNguoi.end(),SoSanhTheoMSV);
}
void SapXepDanhSachNguoiTheoTen(vector<NGUOI> &DanhSachNguoi){
    sort(DanhSachNguoi.begin(),DanhSachNguoi.end(),SoSanhTheoTen);
}
int main(){
    vector<NGUOI>DanhSachNguoi;
    NhapDanhSachNguoi(DanhSachNguoi);
    cout<<"Danh sach nguoi:"<<endl;
    XuatDanhSachNguoi(DanhSachNguoi);

    cout<<"Danh sach sau khi sap xep theo ma sinh vien: "<<endl;
    SapXepDanhSachNguoiTheoMSV(DanhSachNguoi);
    XuatDanhSachNguoi(DanhSachNguoi);

    cout<<"Danh sach nguoi sau khi sap xep theo ho ten: "<<endl;
    SapXepDanhSachNguoiTheoTen(DanhSachNguoi);
    XuatDanhSachNguoi(DanhSachNguoi);
    return 0;

}