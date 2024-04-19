#include "Functions.hpp"
#include "Process.hpp"

int main() {
	HashTable HT;
	InitHashTable(HT);
	Input_From_KeyBroad(HT);
	Sapxep_Tangdan(HT);
	TraverseHashTable(HT);
	return 0;
}