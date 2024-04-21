#include "Functions.hpp"

void InitHashTable(HashTable& HT) {
	for (int i = 0; i < M; i++) {
		HT[i] = NULL;
	}
}

int Hash(string a) {
	int h = 0;
	for (auto c : a) {
		h += c;
	}
	return h % M;
}

Node* MakeNode(Node* a) {
	Node* tmp = new Node();
	tmp->Info1 = a->Info1;
	tmp->Info2 = a->Info2;
	tmp->Next = NULL;
	return tmp;
}

void InsertNode(HashTable& HT, Node* a) {
	int i = Hash(a->Info2.maLop);
	AddTail(HT[i], a);
}

void AddTail(Node*& l, Node* a) {
	Node* tmp = MakeNode(a);
	if (l == NULL) {
		l = tmp;
	}
	else {
		Node* p = l;
		while (p != NULL && p->Next != NULL) {
			p = p->Next;
		}
		p->Next = tmp;
	}
}

void Input_From_File(HashTable& HT) {
	fstream Input1("tre.txt");
	fstream Input2("lophoc.txt");
	int i = 0;
	string str1;
	string str2;
	if (!Input1.is_open()) {
		cout << "\nMở danh sách trẻ thất bại";
		return;
	}
	if (!Input2.is_open()) {
		cout << "\nMở danh sách lớp thất bại";
		return;
	}
	while (std::getline(Input1, str1) && std::getline(Input2, str2)) {
		Node* tmp = new Node();
		stringstream ss1(str1);
		stringstream ss2(str2);
		getline(ss1, tmp->Info1.maLop, ',');
		getline(ss1, tmp->Info1.maTre, ',');
		getline(ss1, tmp->Info1.hoLot, ','); 
		getline(ss1, tmp->Info1.ten, ',');	
		getline(ss1, tmp->Info1.ngay, ',');
		getline(ss1, tmp->Info1.thang, ',');
		getline(ss1, tmp->Info1.nam, ',');
		getline(ss1, tmp->Info1.tenCha, ',');
		getline(ss1, tmp->Info1.sdtCha, ','); 
		getline(ss1, tmp->Info1.tenMe, ',');
		getline(ss1, tmp->Info1.sdtMe, ',');
		getline(ss2, tmp->Info2.maLop, ','); 
		getline(ss2, tmp->Info2.GVCN, ',');
		getline(ss2, tmp->Info2.tenHocPhan, ',');
		InsertNode(HT, tmp);
	}
	Input1.close();
	Input2.close();
	cout << "\nDone!\n";
}

void Input_From_KeyBroad(HashTable& HT) {
	int n;
	cout << "Nhập số lượng trẻ học: "; cin >> n; cin.ignore();
	for (int i = 0; i < n; i++) {
		Node* tmp = new Node;
		cout << "\nNhập thông tin: " << endl;
		cout << "\Nhập mã lớp: "; cin >> tmp->Info1.maLop; cin.ignore();
		cout << "Nhập mã trẻ: "; cin >> tmp->Info1.maTre; cin.ignore();
		cout << "Nhập họ lót: "; getline(cin, tmp->Info1.hoLot);
		cout << "Nhập tên: "; getline(cin, tmp->Info1.ten);
		cout << "Nhập ngày sinh: "; cin >> tmp->Info1.ngay; cin.ignore();
		cout << "Nhập tháng sinh: "; cin >> tmp->Info1.thang; cin.ignore();
		cout << "Nhập năm sinh: "; cin >> tmp->Info1.nam; cin.ignore();
		cout << "Nhập tên cha: "; getline(cin, tmp->Info1.tenCha);
		cout << "Nhập sdt: "; cin >> tmp->Info1.sdtCha; cin.ignore();
		cout << "Nhập tên mẹ: "; getline(cin, tmp->Info1.tenMe);
		cout << "Nhập sdt: "; cin >> tmp->Info1.sdtMe; cin.ignore();
		cout << "Nhập lại mã lớp: "; cin >> tmp->Info2.maLop; cin.ignore();
		cout << "Nhập tên GVCN: "; getline(cin, tmp->Info2.GVCN);
		cout << "Nhập tên học phần: "; getline(cin, tmp->Info2.tenHocPhan);
		InsertNode(HT, tmp);
	}
	cout << "\nDone!\n";
}

void Search_GVCN(HashTable HT) {
	string a;
	cout << "\nNhập tên GVCN: "; getline(cin, a);
	bool Found = false;
	cout << "Các trẻ học GV này là:\n";
	for (int i = 0; i < M; i++) {
		Node* p = HT[i];
		while (p != NULL) {
			if (p->Info2.GVCN.find(a) != string::npos) {
				cout << "\Thông tin của trẻ\n";
				cout << "--------------------------------------------\n";
				cout << "Mã trẻ: " << p->Info1.maTre << endl;
				cout << "Mã lớp: " << p->Info1.maLop << endl;
				cout << "Họ và tên: " << p->Info1.hoLot << " " << p->Info1.ten << endl;
				cout << "Ngày tháng năm sinh: " << p->Info1.ngay << "/" << p->Info1.thang << "/" << p->Info1.nam << endl;
				cout << "Họ tên cha: " << p->Info1.tenCha << endl;
				cout << "Sđt: " << p->Info1.sdtCha << endl;
				cout << "Họ tên Mẹ: " << p->Info1.tenMe << endl;
				cout << "Sđt: " << p->Info1.sdtMe << endl;
				cout << "GVCN: " << p->Info2.GVCN << endl;
				cout << "Học phần: " << p->Info2.tenHocPhan << endl;
				cout << "--------------------------------------------\n";
				Found = true;
			}
			p = p->Next;
		}
	}
	if (!Found) {
		cout << "\nKhông có trẻ nào học giáo viên này\n";
		return;
	}
}

void Search_maTre(HashTable HT) {
	string a;
	bool found = false;
	cout << "\nNhập mã trẻ: "; cin >> a; cin.ignore();
	cout << "Trẻ có mã số này là: \n";
	for (int i = 0; i < M; i++) {
		Node* p = HT[i];
		while (p != NULL) {
			if (p->Info1.maTre == a) {
				cout << "\Thông tin của trẻ\n";
				cout << "--------------------------------------------\n";
				cout << "Mã trẻ: " << p->Info1.maTre << endl;
				cout << "Mã lớp: " << p->Info1.maLop << endl;
				cout << "Họ và tên: " << p->Info1.hoLot << " " << p->Info1.ten << endl;
				cout << "Ngày tháng năm sinh: " << p->Info1.ngay << "/" << p->Info1.thang << "/" << p->Info1.nam << endl;
				cout << "Họ tên cha: " << p->Info1.tenCha << endl;
				cout << "Sđt: " << p->Info1.sdtCha << endl;
				cout << "Họ tên Mẹ: " << p->Info1.tenMe << endl;
				cout << "Sđt: " << p->Info1.sdtMe << endl;
				cout << "GVCN: " << p->Info2.GVCN << endl;
				cout << "Học phần: " << p->Info2.tenHocPhan << endl;
				cout << "--------------------------------------------\n";
				found = true;
			}
			p = p->Next;
		}
	}
	if (!found) {
		cout << "Không tìm thấy trẻ có mã số này\n";
		return;
	}
}

void Search_tenHocPhan(HashTable HT) {
	string a;
	cout << "\nNhập tên học phần: "; getline(cin, a);
	cout << "Những trẻ học môn này là: \n";
	bool Found = false;
	for (int i = 0; i < M; i++) {
		Node* p = HT[i];
		while (p != NULL) {
			if (p->Info2.tenHocPhan.find(a) != string::npos) {
				cout << "\Thông tin của trẻ\n";
				cout << "--------------------------------------------\n";
				cout << "Mã trẻ: " << p->Info1.maTre << endl;
				cout << "Mã lớp: " << p->Info1.maLop << endl;
				cout << "Họ và tên: " << p->Info1.hoLot << " " << p->Info1.ten << endl;
				cout << "Ngày tháng năm sinh: " << p->Info1.ngay << "/" << p->Info1.thang << "/" << p->Info1.nam << endl;
				cout << "Họ tên cha: " << p->Info1.tenCha << endl;
				cout << "Sđt: " << p->Info1.sdtCha << endl;
				cout << "Họ tên Mẹ: " << p->Info1.tenMe << endl;
				cout << "Sđt: " << p->Info1.sdtMe << endl;
				cout << "GVCN: " << p->Info2.GVCN << endl;
				cout << "Học phần: " << p->Info2.tenHocPhan << endl;
				cout << "--------------------------------------------\n";
				Found = true;
			}
			p = p->Next;
		}
	}
	if (!Found) {
		cout << "\nKhông có học phần môn này!\n";
	}
}

void CapNhap(HashTable &HT) {
	system("cls");
	fstream Output("log.txt", ios::app);	// ios::app dùng để ghi vào file mà lần cập nhập sau không bị ghi đè lên lần cập nhập trước
	string a;
	cout << "\nNhập mã trẻ: "; cin >> a; cin.ignore();
	for (int i = 0; i < M; i++) {
		Node* p = HT[i];
		while (p != NULL) {
			if (p->Info1.maTre == a) {
				int key;
				system("cls");
				cout << "Bạn muốn cập nhập thông tin gì:\n ";
				cout << "----------------------------------------------------------------\n";
				cout << "1/ Mã lớp\n";
				cout << "2/ Họ Lót\n";
				cout << "3/ Tên\n";
				cout << "4/ Ngày tháng năm sinh\n";
				cout << "5/ Tên phụ huynh\n";
				cout << "6/ Sđt phụ huynh\n";
				cout << "7/ Tên GVCN\n";
				cout << "8/ Học phần\n";
				cout << "----------------------------------------------------------------\n";
				cout << "Lựa chọn: "; cin >> key; cin.ignore();
				switch (key) {
				case 1:
					Output << "---------------------------------------------------------------------------------------------------------" << endl;
					cout << "Nhập mã lớp muốn đổi: "; cin >> p->Info1.maLop; Output << "Thay đổi mã lớp của em: " << p->Info1.hoLot << p->Info1.ten << "thành: " << p->Info1.maLop << endl; cin.ignore();
					
					break;
				case 2:
					Output << "---------------------------------------------------------------------------------------------------------" << endl;
					cout << "Nhập họ lót muốn đổi: "; getline(cin, p->Info1.hoLot); Output << "Thay đổi họ lót của em: " << p->Info1.hoLot << p->Info1.ten << " thành: " << p->Info1.hoLot << endl;
					Output << "---------------------------------------------------------------------------------------------------------" << endl;
					break;
				case 3:
					Output << "---------------------------------------------------------------------------------------------------------" << endl;
					cout << "Nhập tên muốn đổi: "; getline(cin, p->Info1.ten);  Output << "Thay đổi tên của em: " << p->Info1.hoLot << p->Info1.ten << " thành: " << p->Info1.ten << endl;
					Output << "---------------------------------------------------------------------------------------------------------" << endl;
					break;
				case 4:
					cout << "Nhập ngày tháng năm sinh muốn đổi: \n";
					Output << "---------------------------------------------------------------------------------------------------------\n" << endl;
					cout << "Ngày: "; cin >> p->Info1.ngay; getline(cin, p->Info1.ngay); Output << "Thay đổi ngày sinh của em: " << p->Info1.hoLot << p->Info1.ten << " thành: " << p->Info1.ngay << endl;
					cout << "Tháng: "; cin >> p->Info1.thang;  getline(cin, p->Info1.thang); Output << "Thay đổi tháng sinh của em: " << p->Info1.hoLot << p->Info1.ten << " thành: " << p->Info1.thang << endl;
					cout << "Năm: "; cin >> p->Info1.nam; getline(cin, p->Info1.nam); Output << "Thay đổi năm sinh của em: " << p->Info1.hoLot << p->Info1.ten << " thành: " << p->Info1.nam << endl;
					Output << "---------------------------------------------------------------------------------------------------------" << endl;
					break;
				case 5:
					cout << "Nhập họ tên muốn đổi: \n";
					Output << "---------------------------------------------------------------------------------------------------------" << endl;
					cout << "Cha: "; getline(cin, p->Info1.tenCha);  Output << "Thay đổi tên cha của em: " << p->Info1.hoLot << p->Info1.ten << " thành: " << p->Info1.tenCha << endl;
					cout << "Mẹ: "; getline(cin, p->Info1.tenMe);  Output << "Thay đổi tên mẹ của em: " << p->Info1.hoLot << p->Info1.ten << " thành: " << p->Info1.tenMe << endl;
					Output << "---------------------------------------------------------------------------------------------------------" << endl;
					break;
				case 6:
					cout << "Nhập sđt\n";
					Output << "---------------------------------------------------------------------------------------------------------" << endl;
					cout << "Sđt cha: "; getline(cin, p->Info1.sdtCha);  Output << "Thay đổi sđt cha của em: " << p->Info1.hoLot << p->Info1.ten << " thành: " << p->Info1.sdtCha << endl;
					cout << "Sđt mẹ: "; getline(cin, p->Info1.sdtMe);  Output << "Thay đổi sđt mẹ của em: " << p->Info1.hoLot << p->Info1.ten << " thành: " << p->Info1.sdtMe << endl;
					Output << "---------------------------------------------------------------------------------------------------------" << endl;
					break;
				case 7:
					Output << "---------------------------------------------------------------------------------------------------------" << endl;
					cout << "Nhập GVCN: "; getline(cin, p->Info2.GVCN);  Output << "Thay đổi GVCN của em: " << p->Info1.hoLot << p->Info1.ten << " thành: " << p->Info2.GVCN << endl;
					Output << "---------------------------------------------------------------------------------------------------------" << endl;
					break;
				case 8:
					Output << "---------------------------------------------------------------------------------------------------------" << endl;
					cout << "Nhập tên học phần: "; getline(cin, p->Info2.tenHocPhan); Output << "Thay đổi học phần của em: " << p->Info1.hoLot << p->Info1.ten << " thành: " << p->Info2.tenHocPhan << endl;
					Output << "---------------------------------------------------------------------------------------------------------" << endl;
					break;
				}
				Output.close();
			}
		p = p->Next;
		}
	}
	cout << "\nDone!\n";
	Output.close();
}

void Search_LopCoNhieuHocSinhNhat(HashTable HT){
	unordered_map<string, int> ClassCnt;
	for (int i = 0; i < M; i++) {
		Node* p = HT[i];
		while (p != NULL) {
			ClassCnt[p->Info1.maLop]++;
			p = p->Next;
		}
	}
	string maxClass;
	int maxCount = 0;
	for (auto it = ClassCnt.begin(); it != ClassCnt.end(); ++it) {
		if (it->second > maxCount) {
			maxClass = it->first;
			maxCount = it->second;
		}
	}
	cout << "\nLớp có nhiều học sinh nhất là lớp " << maxClass << " với " << maxCount << " học sinh\n";
}

bool Compare(const Children &child1, const Children &child2) {	// Hàm so sánh tên giữa 2 đứa trẻ
	if (child1.hoLot < child2.hoLot) {
		return true;
	}
	if (child1.hoLot == child2.hoLot) {
		return child1.ten < child2.ten;
	}
	return false;
}

void Sapxep_Tangdan(HashTable &HT) {
	for (int i = 0; i < M; i++) {
		Node* p = HT[i];
		vector<Children> children; // Lưu trữ thông tin của trẻ trong lớp
		while (p != NULL) {
			children.push_back(p->Info1);
			p = p->Next;
		}
		// Sắp xếp danh sách trẻ trong lớp
		sort(children.begin(), children.end(), [](const Children& child1, const Children& child2) {
			// Đầu tiên sắp xếp theo lớp
			if (child1.maLop != child2.maLop) {
				return child1.maLop < child2.maLop;
			}
			// Nếu cùng một lớp thì so sánh tên
			return child1.hoLot + child1.ten < child2.hoLot + child2.ten;
		});
		// Cập nhật danh sách trẻ trong lớp đã sắp xếp
		int index = 0;
		while (p != NULL && index < children.size()) {
			p->Info1 = children[index];
			p = p->Next;
			index++;
		}
	}
}

void In_GVCN_HoTran(HashTable HT) {
	string a = "Tran";
	bool Found = false;
	cout << "Các trẻ học GV này là:\n";
	for (int i = 0; i < M; i++) {
		Node* p = HT[i];
		while (p != NULL) {
			if (p->Info2.GVCN.find(a) != string::npos) {
				cout << "\nThông tin của trẻ\n";
				cout << "--------------------------------------------\n";
				cout << "Mã trẻ: " << p->Info1.maTre << endl;
				cout << "Mã lớp: " << p->Info1.maLop << endl;
				cout << "Họ và tên: " << p->Info1.hoLot << " " << p->Info1.ten << endl;
				cout << "Ngày tháng năm sinh: " << p->Info1.ngay << "/" << p->Info1.thang << "/" << p->Info1.nam << endl;
				cout << "Họ tên cha: " << p->Info1.tenCha << endl;
				cout << "Sđt: " << p->Info1.sdtCha << endl;
				cout << "Họ tên Mẹ: " << p->Info1.tenMe << endl;
				cout << "Sđt: " << p->Info1.sdtMe << endl;
				cout << "GVCN: " << p->Info2.GVCN << endl;
				cout << "Học phần: " << p->Info2.tenHocPhan << endl;
				cout << "--------------------------------------------\n";
				Found = true;
			}
			p = p->Next;
		}
	}
	if (!Found) {
		cout << "\nKhông có giáo viên nào họ Trần\n";
	}
}

void In_Danhsach_Tre_Thang12(HashTable HT) {
	string a = "12";
	bool Found = false;
	cout << "Các trẻ sinh tháng 12 là:\n";
	for (int i = 0; i < M; i++) {
		Node* p = HT[i];
		while (p != NULL) {
			if (p->Info1.thang == a) {
				cout << "\nThông tin của trẻ\n";
				cout << "--------------------------------------------\n";
				cout << "Mã trẻ: " << p->Info1.maTre << endl;
				cout << "Mã lớp: " << p->Info1.maLop << endl;
				cout << "Họ và tên: " << p->Info1.hoLot << " " << p->Info1.ten << endl;
				cout << "Ngày tháng năm sinh: " << p->Info1.ngay << "/" << p->Info1.thang << "/" << p->Info1.nam << endl;
				cout << "Họ tên cha: " << p->Info1.tenCha << endl;
				cout << "Sđt: " << p->Info1.sdtCha << endl;
				cout << "Họ tên Mẹ: " << p->Info1.tenMe << endl;
				cout << "Sđt: " << p->Info1.sdtMe << endl;
				cout << "GVCN: " << p->Info2.GVCN << endl;
				cout << "Học phần: " << p->Info2.tenHocPhan << endl;
				cout << "--------------------------------------------\n";
				Found = true;
			}
			p = p->Next;
		}
	}
	if (!Found) {
		cout << "\nKhông có trẻ nào sinh tháng 12\n";
	}
}

void TraverseHashTable(HashTable HT) {
	system("cls");
	for (int i = 0; i < M; i++) {
		Node* p = HT[i];
		while (p != NULL) {
			cout << "\nThông tin của trẻ\n";
			cout << "--------------------------------------------\n";
			cout << "Mã trẻ: " << p->Info1.maTre << endl;
			cout << "Mã lớp: " << p->Info1.maLop << endl;
			cout << "Họ và tên: " << p->Info1.hoLot << p->Info1.ten << endl;
			cout << "Ngày tháng năm sinh: " << p->Info1.ngay << "/" << p->Info1.thang << "/" << p->Info1.nam << endl;
			cout << "Họ tên cha: " << p->Info1.tenCha << endl;
			cout << "Sđt: " << p->Info1.sdtCha << endl;
			cout << "Họ tên Mẹ: " << p->Info1.tenMe << endl;
			cout << "Sđt: " << p->Info1.sdtMe << endl;
			cout << "GVCN: " << p->Info2.GVCN << endl;
			cout << "Học phần: " << p->Info2.tenHocPhan << endl;
			cout << "--------------------------------------------\n";
			p = p->Next;
		}
	}
}

void In_DanhSach_2_Tre_TheoHoc(HashTable HT) {
	// Sử dụng unordered map để lưu trữ thông tin phụ huynh với số lg con của họ
	unordered_map<string, int> phuHuynhvoi2con;

	// Duyệt 
	for (int i = 0; i < M; i++) {
		Node* p = HT[i];
		while (p != NULL) {
			// Tạo key để xác định phụ huynh
			string parentKey = p->Info1.tenCha + ", " + p->Info1.tenMe;
			// Tăng số lượng trẻ của phụ huynh lên 
			phuHuynhvoi2con[parentKey]++;
			p = p->Next;
		}
	}
	// In ra danh sách phụ huynh có hai trẻ
	cout << "Danh sach phu huynh co hai tre:" << endl;
	for (auto it = phuHuynhvoi2con.begin(); it != phuHuynhvoi2con.end(); it++) {
		if (it->second == 2) {
			cout << it->first << endl;
		}
	}
}


