#pragma once
#include<string>
#include<sstream>
#include<fstream>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<set>
using namespace std;

#define M 10	


// File Header chỉ dùng để viết các hàm xử lý


// Khai báo cấu trúc
//----------------------------------------------------------------------------------------------

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

// Cấu trúc một node trong bảng băm
struct Node {
	Children Info1;		// Info1: thông tin một đứa trẻ
	Class Info2;		// Info2: thông tin lớp mà đứa trẻ đó đang học
	Node* Next;
};

typedef Node* HashTable[M];	// Bảng băm có M phần tử

//----------------------------------------------------------------------------------------------q


// Khai báo nguyên mẫu hàm
//---------------------------------------------------------------------------------------------------------------------------

void InitHashTable(HashTable& HT);
int Hash(string a);
Node* MakeNode(Node* a);
void InsertNode(HashTable& HT, Node* a);
void AddTail(Node*& l, Node* a);
void Input_From_File(HashTable& HT);
void Input_From_KeyBroad(HashTable& HT);
void Search_GVCN(HashTable HT);
void Search_maTre(HashTable HT);
void Search_tenHocPhan(HashTable HT);
void TraverseHashTable(HashTable HT);
void Search_LopCoNhieuHocSinhNhat(HashTable HT);
void Sapxep_Tangdan(HashTable &HT);
void In_GVCN_HoTran(HashTable HT);
void In_Danhsach_Tre_Thang12(HashTable HT);
void CapNhap(HashTable &HT);
void In_DanhSach_2_Tre_TheoHoc(HashTable HT);
bool CompareChildren(const Node* child1, const Node* child2);
void DisplaySortedChildrenList(HashTable HT);

//---------------------------------------------------------------------------------------------------------------------------


