#include<iostream> 
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class CongNhan{
    private:
        int maCN;
        string hoTen;
        string diaChi;
        int sdt;
        string caSX;    
    public:
        static int soLuongCN;
        CongNhan(string hoTen, string diaChi,int sdt, string caSX) {
        this->maCN = ++soLuongCN + 10000; //tăng biến đếm
        this->hoTen = hoTen;
        this->diaChi = diaChi;
        this->sdt = sdt;
        this->caSX = caSX;
        }
        int layMaCN() const{ 
            return maCN;
        }
        string layHoTen() const {
            return hoTen;
        }
        int laysdt() const{
            return sdt;
        }
        string layCaSX() const{
            return caSX;
        }
        void nhap();
        void xuat() const {
            cout<<"Ma CN: "<<maCN<<"\nHo ten: "<<hoTen<<"\nDia chi: "<<diaChi<<"\nSDT: "<<sdt<<"\nCa SX: "<<caSX<<endl;
        }
};
int CongNhan::soLuongCN =0;

class SanPham{
    private:
        int maSP;
        string tenSP;
        double donGia;
        static int soLuongSP;
    public:    

        SanPham(string tenSP, double donGia) {
        this->maSP = ++soLuongSP + 10000;
        this->tenSP = tenSP;
        this->donGia = donGia;
    }
        int layMaSP() const{
            return maSP;
        }
        string layTenSP() const{
            return tenSP;
        }        
        double layDonGia()const{
            return donGia;
        }
}; 
int SanPham::soLuongSP=0;

class BangTinhCong{
    private:
        const CongNhan * congNhan;
        const SanPham* sanPham;
        int soluong;
        vector<pair<const SanPham*,int>>danhSachSanPham;
    public:
        BangTinhCong(const CongNhan* congNhan) : congNhan(congNhan) {}
        BangTinhCong(const SanPham* sanPham, int soLuong) {
        this->congNhan = congNhan;
        this->sanPham = sanPham;
        this->soluong = soluong;
    }
        const CongNhan* layCongNhan() const {
            return congNhan;
        }
        const SanPham* laySanPham() const{
            return sanPham;
        }
        int laySoLuong()const{
            return soluong;
        }
        void themSanPham(const SanPham* sanPham, int soLuong) {
            danhSachSanPham.push_back(make_pair(sanPham, soLuong));
        }
        //khai báo 
        void xuat() const {
            cout << "Cong nhan: " << congNhan->layHoTen() << endl;
            cout << "Bang tinh cong:" << endl;
            for (const auto& sp : danhSachSanPham) {
                cout << sp.first->layTenSP() << " - So luong: " << sp.second << endl;
            }
            cout << "-----------------------------------" << endl;
        }
    
        //Tinh thu nhap cua cong nhan tu bang tinh cong
        double tinhThuNhap()const{
            double thuNhap = 0.0;
            for(const auto& sp: danhSachSanPham){
                //tinh tong thu nhap tu tung san pham
                thuNhap+= sp.first->layDonGia()* sp.second;
            }
            return thuNhap;
        }
        vector<pair<const SanPham*, int>> layDanhSachSanPham() const {
            return danhSachSanPham;
    }
};
int main(){
    int n,m;
    vector<CongNhan> danhSachCongNhan;
    vector<SanPham> danhSachSanPham;
    vector<BangTinhCong> bangTinhCong;
//Câu 1:Bang danh sach cong nhan
    cout<<"So luong cong nhan: ";cin>>n;
    cin.ignore();
    cout<<"Nhap danh sach cong nhan:"<<endl;
    for(int i=0;i<n;i++){
        string hoTen, diaChi, caSanXuat;
        int sdt;
        cout << "Ho ten cong nhan "<<i+1<<": ";
        getline(cin, hoTen);
        if (hoTen == "end") break;

        cout << "Dia chi: ";
        getline(cin, diaChi);

        cout << "So dien thoai: ";cin>>sdt;
        cin.ignore();

        cout << "Ca san xuat: ";
        getline(cin, caSanXuat);

        CongNhan newCongNhan(hoTen, diaChi, sdt, caSanXuat);
        danhSachCongNhan.push_back(newCongNhan);
    }
    //In danh sach
    cout << "\nDANH SACH CONG NHAN DA CO:\n";
    for (const auto& congNhan : danhSachCongNhan) {
        congNhan.xuat();
        cout << "-----------------------------------" << endl;

    }
//Câu 2:Danh sach san pham
    cout<<"So luong san pham: ";cin>>m;
    cin.ignore();
    cout<<"Nhap danh sach san pham: "<<endl;
    for(int i=0;i<m;i++){
        string tenSP;
        double donGia;
        cout<<"Ten san pham thu "<<i+1<<": ";
        getline(cin,tenSP);
        cout<<"Don gia: ";
        cin>>donGia;
        cin.ignore();

        SanPham newSanPham(tenSP,donGia);
        danhSachSanPham.push_back(newSanPham);
    }
    //In danh sach
    cout << "\nDanh sach san pham da co:\n";
    for (const auto &sanPham : danhSachSanPham) {
        cout <<"Ma SP:" << sanPham.layMaSP()<<"\nTen SP: " << sanPham.layTenSP() << "\nDon gia: " << sanPham.layDonGia() << endl;
        cout << "-----------------------------------" << endl;
    }
//Câu 3:Bang tinh cong theo san pham
    for (const auto& cn : danhSachCongNhan) {
        BangTinhCong bgn(&cn);

        cout << "Thong tin san pham cho cong nhan " << cn.layHoTen() << ":" << endl;
        for (const auto& sp : danhSachSanPham) {
            int soLuong;
            cout << "So luong san pham " << sp.layTenSP() << " ma " << cn.layHoTen() << " da san xuat: ";
            cin >> soLuong;

            if (soLuong > 0) {
                bgn.themSanPham(&sp, soLuong);
            }
        }
        bangTinhCong.push_back(bgn);
    }
    //In danh sach
    cout << "\nDanh sach bang tinh cong:" << endl;
    for (const auto& bgn : bangTinhCong) {
        bgn.xuat();
    }
//Câu 4:Sap xep bang tinh cong
//a, Theo ho ten
    sort(bangTinhCong.begin(),bangTinhCong.end(), [](const BangTinhCong&a,const BangTinhCong&b){
        return a.layCongNhan()->layHoTen() < b.layCongNhan()->layHoTen();
    });
    cout<<"Danh sach bang tinh cong sap xep theo Ho ten:"<<endl;
    for(const auto& bgn :bangTinhCong){
        bgn.xuat();
    }
//b, Theo so luong giam dan
    sort(bangTinhCong.begin(),bangTinhCong.end(),[](const BangTinhCong&a,const BangTinhCong&b){
        return a.layDanhSachSanPham().size() > b.layDanhSachSanPham().size();
    });
    cout<<"Danh sach bang tinh cong sap xep theo So luong:"<<endl;
    for(const auto& bgn :bangTinhCong){
        bgn.xuat();
    }
//Câu 5:Lap bang thu nhap cua moi cong nhan
    for(const auto &cn : danhSachCongNhan) {
        BangTinhCong bgn(&cn);

        cout<<"Thong tin san pham cho cong nhan "<<cn.layHoTen()<<" : "<<endl;
        for (const auto &sp : danhSachSanPham){
            int soLuong;
            cout<< "So luong san pham "<<sp.layTenSP()<<" ma "<<cn.layHoTen()<< " da san xuat: ";
            cin>>soLuong;

            if(soLuong>0){
                bool daTonTai = false;
                for (const auto &item : bangTinhCong){
                    if(item.layCongNhan() == &cn){
                        for(const auto &p :item.layDanhSachSanPham()){
                            if (p.first->layTenSP() == sp.layTenSP()){
                                daTonTai = true;
                                break;
                            }
                        }
                    }
                }
                if(!daTonTai){
                    bgn.themSanPham(&sp, soLuong);
                } else {
                    cout<<"San pham  da ton tai!"<<endl;
                }
            }
        }
        bangTinhCong.push_back(bgn);
    }
    cout << "\nDanh sách bảng tính công:" << endl;
    for (const auto& bgn : bangTinhCong) {
        bgn.xuat();
    }
    return 0;
}
