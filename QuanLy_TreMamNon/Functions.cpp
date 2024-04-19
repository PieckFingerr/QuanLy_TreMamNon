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
		ss1 >> tmp->Info1.maLop; ss1.ignore();
		ss1 >> tmp->Info1.maTre; ss1.ignore();
		std::getline(ss1, tmp->Info1.hoLot, ','); 
		std::getline(ss1, tmp->Info1.ten, ',');	
		std::getline(ss1, tmp->Info1.ngay, ',');
		std::getline(ss1, tmp->Info1.thang, ',');
		std::getline(ss1, tmp->Info1.nam, ',');
		std::getline(ss1, tmp->Info1.tenCha, ',');
		ss1 >> tmp->Info1.sdtCha; ss1.ignore();
		std::getline(ss1, tmp->Info1.tenMe, ',');
		ss1 >> tmp->Info1.sdtMe; ss1.ignore();
		ss2 >> tmp->Info2.maLop; ss2.ignore();
		std::getline(ss2, tmp->Info2.GVCN, ',');
		std::getline(ss2, tmp->Info2.tenHocPhan, ',');
		InsertNode(HT, tmp);
	}
	Input1.close();
	Input2.close();
}

void Input_From_KeyBroad(HashTable& HT) {
	int n;
	cout << "Nhập số lượng trẻ học: "; cin >> n;
	for (int i = 0; i < n; i++) {
		Node* tmp = new Node;
		cout << "\nNhập thông tin: " << endl;
		cout << "\Nhập mã lớp: "; cin >> tmp->Info1.maLop; cin.ignore();
		cout << "Nhập mã trẻ: "; cin >> tmp->Info1.maTre; cin.ignore();
		cout << "Nhập họ lót: "; std::getline(cin, tmp->Info1.hoLot);
		cout << "Nhập tên: "; std::getline(cin, tmp->Info1.ten);
		cout << "Nhập ngày sinh: "; cin >> tmp->Info1.ngay; cin.ignore();
		cout << "Nhập tháng sinh: "; cin >> tmp->Info1.thang; cin.ignore();
		cout << "Nhập năm sinh: "; cin >> tmp->Info1.nam; cin.ignore();
		cout << "Nhập tên cha: "; std::getline(cin, tmp->Info1.tenCha);
		cout << "Nhập sdt: "; cin >> tmp->Info1.sdtCha; cin.ignore();
		cout << "Nhập tên mẹ: "; std::getline(cin, tmp->Info1.tenMe);
		cout << "Nhập sdt: "; cin >> tmp->Info1.sdtMe; cin.ignore();
		cout << "Nhập lại mã lớp: "; cin >> tmp->Info2.maLop; cin.ignore();
		cout << "Nhập tên GVCN: "; std::getline(cin, tmp->Info2.GVCN);
		cout << "Nhập tên học phần: "; std::getline(cin, tmp->Info2.tenHocPhan);
		InsertNode(HT, tmp);
	}
	cout << "\nDone!";
}

void Search_GVCN(HashTable HT) {
	string a;
	cout << "\nNhập tên GVCN: "; getline(cin, a);
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
				cout << "--------------------------------------------\n";
			}
			p = p->Next;
		}
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
			if (p->Info1.maTre.find(a) != string::npos) {
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
				cout << "--------------------------------------------\n";
			}
			p = p->Next;
		}
	}

}

//void CapNhap(HashTable HT, string a) {
//	int i = Hash(a);
//	Node* p = HT[i];
//	while (p != NULL && p->Info1.maTre != a) {
//		p = p->Next;
//	}
//	int key;
//	system("cls");
//	cout << "Bạn muốn cập nhập thông tin gì: ";
//	do {
//		cout << "1/ Mã lớp\n";
//		cout << "2/ Họ Lót\n";
//		cout << "3/ Tên\n";
//		cout << "4/ Ngày tháng năm sinh\n";
//
//	}
//
//
//	
//
//}

void Search_LopCoNhieuHocSinhNhat(HashTable HT){
	int Max = 0;
	Node* p;
	string a;
	for (int i = 0; i < M; i++) {
		p = HT[i];
		int cnt = 0;
		while (p != NULL) {
			cnt++;
			p = p->Next;
		}
		if (cnt > Max) {
			Max = cnt;
			a = p->Info1.maLop;
		}
	}
	cout << "Lớp có nhiều học sinh nhất là lớp có mã: " << a << " với: " << Max << " học sinh\n";
}

bool CompareChildren(const Children &child1, const Children &child2) {	// Hàm so sánh tên giữa 2 đứa trẻ
	return (child1.hoLot + child1.ten) < (child2.hoLot + child2.ten) ? child1 : child2;									// Còn không thì trả về false
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
		sort(children.begin(), children.end(), CompareChildren);
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
	string a = "Trần";
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
				cout << "--------------------------------------------\n";
			}
			p = p->Next;
		}
	}
}

void In_Danhsach_Tre_Thang12(HashTable HT) {
	string a = "12";
	cout << "Các trẻ sinh tháng 12 là:\n";
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
				cout << "--------------------------------------------\n";
			}
			p = p->Next;
		}
	}
}

void TraverseHashTable(HashTable HT) {
	for (int i = 0; i < M; i++) {
		Node* p = HT[i];
		cout << "Lớp có mã: " << p->Info1.maLop << endl;
		cout << "----------------------------------------------------------------------------\n";
		while (p != NULL) {
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
			cout << "--------------------------------------------\n";
		}
	}
}

