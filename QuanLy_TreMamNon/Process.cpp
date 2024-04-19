//#include "Process.hpp"
//#include "Functions.hpp"
//
//void Menu() {
//	cout << setw(35) << "MENU\n";
//	cout << "------------------------------------------------------------------------\n";
//	cout << "1/ Nhập thông tin từ bàn phím\n";
//	cout << "2/ Nhập thông tin từ File\n";
//	cout << "3/ Tìm kiếm trẻ\n";
//	cout << "4/ Tìm lớp học có số lượng trẻ đông nhất\n";
//	cout << "5/ Sắp xếp\n";
//	cout << "6/ In thông tin\n";
//	cout << "7/ Cập nhập thông tin\n";
//	cout << "------------------------------------------------------------------------\n";
//}
//
//void Process() {
//	int key;
//	HashTable HT;
//	InitHashTable(HT);
//	cout << "Nhập lựa chọn: "; cin >> key; cin.ignore();
//	do {
//		switch (key){
//		case 1:
//			system("cls");
//			Input_From_KeyBroad(HT);
//			break;
//		case 2:
//			Input_From_File(HT);
//			break;
//		case 3:
//			system("cls");
//			int key3;
//			cout << "Nhập tiêu chí tìm kiếm: \n";
//			cout << "1/ Theo họ tên GVCN\n";
//			cout << "2/ Theo mã trẻ\n";
//			cout << "3/ Theo tên lớp\n";
//			cout << "Lựa chọn: "; cin >> key3; cin.ignore();
//			switch (key3){
//				case 1:
//					system("cls");
//					string a;
//					cout << "Nhập tên GVCN: "; getline(cin, a);
//					cout << Search_GVCN(HT);
//					break;
//				case 2:
//
//
//			}
//
//
//
//
//
//		default:
//			break;
//		}
//
//	} while (key != 0);
//}