/******************************************************************************
 * Họ và tên: [Nguyễn Thanh Long]
 * MSSV:      [PS49311]
 * Lớp:       [CS21301]
 *****************************************************************************/

// Tạo file asm2.c và hoàn thiện nội dung Assignment từ nội dung file asm1.c


// Danh sách các chức năng trong ASM1:
// 1. Chức năng số 1: Kiểm tra số nguyên
// 2. Chức năng số 2. Tìm Ước số chung và bội số chung của 2 số 
// 3. Chức năng số 3: Chương trình tính tiền cho quán Karaoke
// 4. Chức năng số 4: Tính tiền điện 
// 5. Chức năng số 5: Chức năng đổi tiền 
// 6. Chức năng số 6: Xây dựng chức năng tính lãi suất vay ngân hàng vay trả góp 
// 7. Chức năng số 7: Xây dựng chương trình vay tiền mua xe
// 8. Chức năng số 8: Sắp xếp thông tin sinh viên
// 9. Chức năng số 9: Xây dựng game FPOLY-LOTT
// 10. Chức năng số 10: Xây dựng chương trình tính toán phân số 
// Viết chương trình C thực hiện các chức năng trên

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
void Chucnangtimsonguyen(){
    float a;
    int laSoNguyenTo(int x);
    int laSoChinhPhuong(int x);
    printf("Nhap so can kiem tra: ");
    scanf("%f", &a);
    if(a == (int)a){
        printf("%.2f la so nguyen\n", a);
        if(laSoNguyenTo((int)a)){
            printf("%d la so nguyen to\n", (int)a);
        } else {
            printf("%d KHONG la so nguyen to\n", (int)a);
        }
        if(laSoChinhPhuong((int)a)){
            printf("%d la so chinh phuong\n", (int)a);
        } else {
            printf("%d KHONG la so chinh phuong\n", (int)a);
        }
    } else {
        printf("%.2f khong phai la so nguyen\n", a);
    }
}

int laSoNguyenTo(int x){
    if(x < 2) return 0;
    for(int i = 2; i <= sqrt(x); i++){
        if(x % i == 0) return 0;
    }
    return 1;
}
int laSoChinhPhuong(int x){
    int sqrtX = (int)sqrt(x);
    return (sqrtX * sqrtX == x);
}
void chucNang2() {
    int a, b, ucln, bcnn;
    printf("Nhap a, b: ");
    scanf("%d%d", &a, &b);

    int x = a, y = b;
    while (y != 0) {
        int r = x % y;
        x = y;
        y = r;
    }
    ucln = x;
    bcnn = (a * b) / ucln;

    printf("UCLN = %d\n", ucln);
    printf("BCNN = %d\n", bcnn);
}
void chucNang3() {
    int gioBatDau, gioKetThuc;
    int soGio;
    float tien = 0;

    printf("Nhap gio bat dau: ");
    scanf("%d", &gioBatDau);
    printf("Nhap gio ket thuc: ");
    scanf("%d", &gioKetThuc);

    // KIEM TRA HOP LE
    if (gioBatDau < 12 || gioKetThuc > 23 || gioBatDau >= gioKetThuc) {
        printf("Gio khong hop le!\n");
        return;
    }

    soGio = gioKetThuc - gioBatDau;

    // TINH TIEN
    if (soGio <= 3) {
        tien = 150000 * soGio;
    } else {
        tien = 150000 * 3; // Tien cho 3 gio dau
        tien += (soGio - 3) * 150000 * 0.3; // giam 30% tu gio thu 4
    }

    // GIAM THEM 10% NEU GIO BAT DAU TU 14 -> 17
    if (gioBatDau >= 14 && gioBatDau <= 17) {
        tien = tien - (tien * 0.1);
    }

    printf("So gio hat: %d\n", soGio);
    printf("Tien can thanh toan: %.0f VND\n", tien);
}
void chucNang4() {
    int kWh;
    float tien = 0;
    printf("Nhap so dien: ");
    scanf("%d", &kWh);

    if (kWh <= 50)
        tien = kWh * 1678;
    else if (kWh <= 100)
        tien = 50 * 1678 + (kWh - 50) * 1734;
    else if (kWh <= 200)
        tien = 50 * 1678 + 50 * 1734 + (kWh - 100) * 2014;
    else if (kWh <=300)
        tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + (kWh - 200) * 2536;
    else if (kWh <=400)
    tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + (kWh - 300) * 2834;
    else
        tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + (kWh - 400) * 2927;

    printf("Tien dien: %.0f VND\n", tien);
}
void chucNang5() {
    int tien;
    int menhGia[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    int soTo;
    int viTri = -1;

    printf("Nhap menh gia to tien can doi: ");
    scanf("%d", &tien);

    // Tim vi tri menh gia vua nhap (VD 500 -> viTri ở mảng 0)
    for (int i = 0; i < 9; i++) {
        if (tien == menhGia[i]) {
            viTri = i;
            break;
        }
    }

    if (viTri == -1) {
        printf("Menh gia khong hop le!\n");
        return;
    }

    printf("Doi thanh tien le:\n");

    // Bat dau doi tu menh gia nho hon (viTri + 1 tức là nhap mệnh giá 500 thì sẽ bắt đầu đổi từ mảng 1 tức là từ 200)
    for (int i = viTri + 1; i < 9; i++) {
        soTo = tien / menhGia[i];
        if (soTo > 0) {
            printf("%d to %d\n", soTo, menhGia[i]);
            tien %= menhGia[i];
        }
    }
}
void chucNang6() {
    float tienVay;
    printf("Nhap so tien vay: ");
    scanf("%f", &tienVay);

    float goc = tienVay / 12;
    float lai;
    for (int i = 1; i <= 12; i++) {
        lai = tienVay * 0.05;
        float Sotienconlai = tienVay - goc;
        printf("Thang %d: Goc=%.0f Lai=%.0f So tien con lai = %.0f\n", i, goc, lai, Sotienconlai);
        tienVay = Sotienconlai;
    }
}
void chucNang7() {
    // vi du: 80 - là tra trước 20%, vay 80%
    // tien vay cố định 500.000.000
    float phanTramVay;
    float giaXe = 500000000;
    int thoiHan = 24 * 12;          // 288 thang
    float laiSuatThang = 0.072 / 12;

    printf("Nhap phan tram vay: "); // phần trăm số tiền mình muốn vay trong giới hạn 500trieu
    scanf("%f", &phanTramVay);

    if (phanTramVay <= 0 || phanTramVay > 100) {
        printf("Phan tram vay khong hop le!\n");
        return;
    }

    float tienVay = giaXe * phanTramVay / 100; // số tiền minh vay theo phần trăm mình chọn trong giới hạn 500trieu
    float traTruoc = giaXe - tienVay; // số tiền trả trước
    float gocHangThang = tienVay / thoiHan;

    printf("Tien tra lan dau: %.0f VND\n", traTruoc);
    printf("Tien tra hang thang:\n");

    for (int i = 1; i <= thoiHan; i++) {
        float lai = tienVay * laiSuatThang;
        float tongThang = gocHangThang + lai;

        printf("Thang %3d: %.0f VND\n", i, tongThang);

        tienVay -= gocHangThang;
    }
}
void chucNang8() {
    struct SinhVien {
        char hoTen[50];
        float diem;
    }; // hàm struct dùng để gộp nhiều họ tên và điểm vào một kiểu dữ liệu SinhVien

    struct SinhVien sv[50]; // lưu tối đa 50 sinh viên 
    int n;

    printf("Nhap so sinh vien: ");
    scanf("%d", &n);
    getchar(); // xoa ky tu xuong dong của scanf

    // NHAP DU LIEU
    for (int i = 0; i < n; i++) {
        printf("Nhap ho ten SV %d: ", i + 1);
        fgets(sv[i].hoTen, sizeof(sv[i].hoTen), stdin); // dùng fgets để nhập chuỗi có dấu và khoảng trắng
    

        printf("Nhap diem: ");
        scanf("%f", &sv[i].diem);
        getchar();
    }

    // SAP XEP GIAM DAN THEO DIEM
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (sv[i].diem < sv[j].diem) {
                struct SinhVien temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }

    // HIEN THI KET QUA
    printf("\nDANH SACH SINH VIEN SAU SAP XEP:\n");
    for (int i = 0; i < n; i++) {
        printf("Ho ten: %s | Diem: %.2f | Hoc luc: ", sv[i].hoTen, sv[i].diem);

        if (sv[i].diem >= 9.0)
            printf("Xuat sac");
        else if (sv[i].diem >= 8.0)
            printf("Gioi");
        else if (sv[i].diem >= 6.5)
            printf("Kha");
        else if (sv[i].diem >= 5.0)
            printf("Trung binh");
        else
            printf("Yeu");

        printf("\n");
    }
}
void chucNang9() {
    int so;
    printf("Nhap so du doan (1-15): ");
    scanf("%d", &so);

    int ketQua = rand() % 15 + 1; // nếu % 15 thì kết quả từ 0-14, +1 để nhảy cóc kết quả từ 1-15
    if (so == ketQua)
        printf("Chuc mung trung thuong!\n");
    else
        printf("Khong trung. So dung la %d\n", ketQua);
}
void chucNang10() {
    int a, b, c, d;
    printf("Nhap phan so 1 (a/b): ");
    scanf("%d/%d", &a, &b);
    printf("Nhap phan so 2 (c/d): ");
    scanf("%d/%d", &c, &d);

    int tu = a * d + b * c;
    int mau = b * d;
    printf("Tong = %d/%d\n", tu, mau);
}
int main() {
    int chonChucNang;

    do {
        printf("Chon chuc nang:\n");
        printf("1. Kiem tra so nguyen\n");
        printf("2. Tim Uoc so chung va boi so chung cua 2 so\n");
        printf("3. Tinh tien cho quan Karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("5. Chuc nang doi tien\n");
        printf("6. Tinh lai suat vay ngan hang vay tra gop\n");
        printf("7. Vay tien mua xe\n");
        printf("8. Sap xep thong tin sinh vien\n");
        printf("9. Game FPOLY-LOTT\n");
        printf("10. Tinh toan phan so\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &chonChucNang);

        switch (chonChucNang) {
            case 1:
                // Gọi hàm kiểm tra số nguyên
                printf("DA CHON CHUC NANG 1: KIEM TRA SO NGUYEN\n");
                Chucnangtimsonguyen();
                break;
            case 2:
                // Gọi hàm tìm Ước số chung và bội số chung
                printf("DA CHON CHUC NANG 2: TIM UOC SO CHUNG VA BOI SO CHUNG CUA 2 SO\n");
                chucNang2();
                break;
            case 3:
                // Gọi hàm tính tiền cho quán Karaoke
                printf("DA CHON CHUC NANG 3: TINH TIEN CHO QUAN KARAOKE\n");
                chucNang3();
                break;
            case 4:
                // Gọi hàm tính tiền điện
                printf("DA CHON CHUC NANG 4: TINH TIEN DIEN\n");
                chucNang4();
                break;
            case 5:
                // Gọi hàm đổi tiền
                printf("DA CHON CHUC NANG 5: DOI TIEN\n");
                chucNang5();
                break;
            case 6:
                // Gọi hàm tính lãi suất vay ngân hàng
                printf("DA CHON CHUC NANG 6: TINH LAI SUAT VAY NGAN HANG VAY TRA GOP\n");
                chucNang6();
                break;
            case 7:
                // Gọi hàm vay tiền mua xe
                printf("DA CHON CHUC NANG 7: VAY TIEN MUA XE\n");
                chucNang7();
                break;
            case 8:
                // Gọi hàm sắp xếp thông tin sinh viên
                printf("DA CHON CHUC NANG 8: SAP XEP THONG TIN SINH VIEN\n");
                chucNang8();
                break;
            case 9:
                // Gọi hàm game FPOLY-LOTT
                printf("DA CHON CHUC NANG 9: GAME FPOLY-LOTT\n");
                chucNang9();
                break;
            case 10:
                // Gọi hàm tính toán phân số
                printf("DA CHON CHUC NANG 10: TINH TOAN PHAN SO\n");
                chucNang10();
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (chonChucNang != 0);

    return 0;
}