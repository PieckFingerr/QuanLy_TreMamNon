#include"Functions.h"

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
	string str1;
	while (getline(Input1, str1)) {
		Node* tmp = new Node();
		stringstream ss(str1);
		ss >> tmp->Info1.maLop; ss.ignore();
		ss >> tmp->Info1.maTre; ss.ignore();
		getline(ss, tmp->Info1.hoLot, ',');
		getline(ss, tmp->Info1.ten, ',');
		getline(ss, tmp->Info1.hoLot, ',');
		getline(ss, tmp->Info1.ngay, ',');
		getline(ss, tmp->Info1.thang, ',');
		getline(ss, tmp->Info1.nam, ',');
		getline(ss, tmp->Info1.tenCha, ',');
		ss >> tmp->Info1.sdtCha; ss.ignore();
		getline(ss, tmp->Info1.tenMe, ',');
		ss >> tmp->Info1.sdtMe; ss.ignore();
		
		
	}
}

void Input_From_KeyBroad(HashTable& HT) {
	int n;
	cout << "Nhập số lượng trẻ học: "; cin >> n;
	for (int i = 0; i < n; i++) {
		Node* tmp = new Node();
		cout << "Nhập thông tin: " << endl;
		cout << "\Nhập mã lớp: "; cin >> tmp->Info1.maLop; cin.ignore();
		cout << "\Nhập mã trẻ: "; cin >> tmp->Info1.maTre; cin.ignore();
		cout << "\nNhập họ lót: "; getline(cin, tmp->Info1.hoLot);
		cout << "\nNhập tên: "; getline(cin, tmp->Info1.ten);
		cout << "\nNhập ngày: "; cin >> tmp->Info1.ngay; cin.ignore();
		cout << "\nNhập tháng: "; cin >> tmp->Info1.thang; cin.ignore();
		cout << "\nNhập năm: "; cin >> tmp->Info1.nam; cin.ignore();
		cout << "\nNhập tên cha: "; getline(cin, tmp->Info1.tenCha);
		cout << "\nNhập sdt: "; cin >> tmp->Info1.sdtCha; cin.ignore();
		cout << "\nNhập tên cha: "; getline(cin, tmp->Info1.tenMe);
		cout << "\nNhập sdt: "; cin >> tmp->Info1.sdtMe; cin.ignore();
		cout << "\nNhập lại mã lớp: "; cin >> tmp->Info2.maLop; cin.ignore();
		cout << "\nNhập tên GVCN: "; getline(cin, tmp->Info2.GVCN);
		cout << "\nNhập tên học phần: "; getline(cin, tmp->Info2.tenHocPhan);
		InsertNode(HT, tmp);
	}
}
