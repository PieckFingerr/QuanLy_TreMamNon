#pragma once
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<sstream>
#include<fstream>
using namespace std;

#define M 100	// M tượng trưng cho 100
typedef Node* HashTable[M];


// File Header chỉ dùng để viết các hàm xử lý


// Khai báo cấu trúc
//----------------------------------------------------------------------------------------------

// Cấu trúc một node trong bảng băm
struct Node {
	Children Info1;		// Info1: thông tin một đứa trẻ
	Class Info2;		// Info2: thông tin lớp mà đứa trẻ đó đang học
	Node* Next;
};


// Thông tin của một đứa bé
struct Children {
	string maTre, maLop;
	string hoLot, ten;
	string ngay, thang, nam;
	string tenCha, sdtCha;
	string tenMe, sdtMe;
};


// Thông tin một lớp học
struct Class {
	string maLop;
	string GVCN;
	string tenHocPhan;
};

//----------------------------------------------------------------------------------------------





// Khai báo nguyên mẫu hàm
//---------------------------------------------------------------------------------------------------------------------------
void InitHashTable(HashTable& HT);
int Hash(string a);
Node* MakeNode(Node* a);
void InsertNode(HashTable& HT, Node* a);
void AddTail(Node*& l, Node* a);
void Input_From_File(HashTable& HT);
void Input_From_KeyBroad(HashTable& HT);
Node* Search_GVCN(HashTable HT, string a);
Node* Search_maTre(HashTable HT, string a);
Node* Search_tenHocPhan(HashTable HT, string a);
void Search_LopCoNhieuHocSinhNhat(HashTable HT);
void Sapxep_Tangdan(HashTable HT);
void In_GVCN_HoTran(HashTable HT);
void CapNhap(HashTable HT);
void In_DanhSach_2_Tre_TheoHoc(HashTable HT);

//---------------------------------------------------------------------------------------------------------------------------


