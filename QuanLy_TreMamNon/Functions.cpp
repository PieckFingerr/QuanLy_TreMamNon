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
		cout << "Nhập thông tin: " << endl;
		cout << "\Nhập mã lớp: "; cin >> tmp->Info1.maLop; cin.ignore();
		cout << "\Nhập mã trẻ: "; cin >> tmp->Info1.maTre; cin.ignore();
		cout << "\nNhập họ lót: "; std::getline(cin, tmp->Info1.hoLot);
		cout << "\nNhập tên: "; std::getline(cin, tmp->Info1.ten);
		cout << "\nNhập ngày: "; cin >> tmp->Info1.ngay; cin.ignore();
		cout << "\nNhập tháng: "; cin >> tmp->Info1.thang; cin.ignore();
		cout << "\nNhập năm: "; cin >> tmp->Info1.nam; cin.ignore();
		cout << "\nNhập tên cha: "; std::getline(cin, tmp->Info1.tenCha);
		cout << "\nNhập sdt: "; cin >> tmp->Info1.sdtCha; cin.ignore();
		cout << "\nNhập tên cha: "; std::getline(cin, tmp->Info1.tenMe);
		cout << "\nNhập sdt: "; cin >> tmp->Info1.sdtMe; cin.ignore();
		cout << "\nNhập lại mã lớp: "; cin >> tmp->Info2.maLop; cin.ignore();
		cout << "\nNhập tên GVCN: "; std::getline(cin, tmp->Info2.GVCN);
		cout << "\nNhập tên học phần: "; std::getline(cin, tmp->Info2.tenHocPhan);
		InsertNode(HT, tmp);
	}
	cout << "\nDone!";
}

Node* Search_GVCN(HashTable HT, string a) {
	int i = Hash(a);
	Node* p = HT[i];
	while (p != NULL && p->Info2.GVCN != a) {
		p = p->Next;
	}
	if (p == NULL) {
		cout << "Không tìm thấy trẻ học GV này !\n";
		return NULL;
	}
	return p;

}

Node* Search_maTre(HashTable HT, string a) {
	int i = Hash(a);
	Node* p = HT[i];
	while (p != NULL && p->Info1.maTre != a) {
		p = p->Next;
	}
	if (p == NULL) {
		cout << "Không tìm thấy trẻ có mã này !\n";
		return NULL;
	}
	return p;

}

Node* Search_tenHocPhan(HashTable HT, string a) {
	int i = Hash(a);
	Node* p = HT[i];
	while (p != NULL && p->Info2.tenHocPhan != a) {
		p = p->Next;
	}
	if (p == NULL) {
		cout << "Không tìm thấy trẻ học môn này !\n";
		return NULL;
	}
	return p;

}

void TraverseHashTable(HashTable HT) {
	for (int i = 0; i < M; i++) {
		cout << HT[i] << " ";
		TraverseHashTable(HT);
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