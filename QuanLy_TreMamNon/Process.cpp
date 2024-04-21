#include "Process.hpp"
#include "Functions.hpp"

void Menu() {
	cout << setw(35) << "MENU\n";
	cout << "------------------------------------------------------------------------\n";
	cout << "1/ Nhập thông tin từ bàn phím\n";
	cout << "2/ Nhập thông tin từ File\n";
	cout << "3/ Tìm kiếm trẻ\n";
	cout << "4/ Tìm lớp học có số lượng trẻ đông nhất\n";
	cout << "5/ Sắp xếp\n";
	cout << "6/ In thông tin\n";
	cout << "7/ Cập nhập thông tin\n";
	cout << "0/ Thoát chương trình\n";
	cout << "------------------------------------------------------------------------\n";
	cout << "Nhập lựa chọn: ";
}

void process() {
	int key;
	HashTable HT;
	InitHashTable(HT);
	do {
		Menu();
		cin >> key; cin.ignore();
		switch (key) {
		case 1:
			system("cls");
			Input_From_KeyBroad(HT);
			system("pause");
			system("cls");
			break;
		case 2:
			Input_From_File(HT);
			system("pause");
			system("cls");
			break;
		case 3:
			int key3;
			system("cls");
			cout << "Nhập tiêu chí tìm kiếm: \n";
			cout << "-------------------------------------------------------\n";
			cout << "1/ Theo họ tên GVCN\n";
			cout << "2/ Theo mã trẻ\n";
			cout << "3/ Theo tên lớp\n";
			cout << "-------------------------------------------------------\n";
			cout << "Lựa chọn: "; cin >> key3; cin.ignore();
			switch (key3) {
			case 1:
				system("cls");
				Search_GVCN(HT);
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				Search_maTre(HT);
				system("pause");
				system("cls");
				break;
			case 3:
				system("cls");
				Search_tenHocPhan(HT);
				system("pause");
				system("cls");
				break;
			default:
				cout << "\nNhập sai, xin hãy nhập lại\n";
				system("pause");
				system("cls");
				break;
			}
			break;
		case 4:
			system("cls");
			Search_LopCoNhieuHocSinhNhat(HT);
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			Sapxep_Tangdan(HT);
			cout << "\n Đã sắp xếp xong";
			system("pause");
			system("cls");
			break;
		case 6:
			int key6;
			system("cls");
			cout << "Lựa chọn các tiêu chí in sau:\n";
			cout << "-----------------------------------------------------------------------------\n";
			cout << "1. In danh sách tất cả trẻ đang học\n";
			cout << "2. In thông tin các trẻ do GVCN họ Trần giảng dạy\n";
			cout << "3. In thông tin các trẻ sinh tháng 12\n";
			cout << "4. In danh sách các phụ huynh có 2 trẻ đang theo học\n";
			cout << "-----------------------------------------------------------------------------\n";
			cout << "Lựa chọn: "; cin >> key6; cin.ignore();
			switch (key6) {
			case 1:
				TraverseHashTable(HT);
				system("pause");
				system("cls");
				break;
			case 2:
				In_GVCN_HoTran(HT);
				system("pause");
				system("cls");
				break;
			case 3:
				In_Danhsach_Tre_Thang12(HT);
				system("pause");
				system("cls");
				break;
			case 4:
				In_DanhSach_2_Tre_TheoHoc(HT);
				system("pause");
				system("cls");
				break;
			}
			break;
		case 7:
			CapNhap(HT);
			system("pause");
			system("cls");
			break;
		}
	}while (key != 0);
} 