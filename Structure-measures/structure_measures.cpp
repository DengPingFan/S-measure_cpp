#include "structure_measures.h"

void main(int argc, char* argv[]){
	
	//File Path
	string GT_path = "../Demo/GT";
	string SM_path = "../Demo/SM";
	string Results_path = "../Demo/Result";

	//file extension
	string GT_extension = ".bmp";
	string SM_extension = ".png";

	//method
	vector<string> method = { "CA", "CB", "PCA", "RC", "SVO" };

	printf("\nArguments list:\r\n\nGT_path:\t%s\r\nGT_extention:\t%s\r\n\nSM_path:\t %s\r\nSM_extention:\t%s \r\n\nResults_path:\t %s\r\n\nmethods:\r\n", GT_path.data(), GT_extension.data(), SM_path.data(), SM_extension.data(), Results_path.data());
	for (int i = 0; i < method.size(); i++){
		printf("\tmethod %d : %s \n ", i + 1, method[i].data());
	}
	cout << endl;

	init();

	demo(GT_path, GT_extension, SM_path, SM_extension, Results_path, method);

	getchar();
};

