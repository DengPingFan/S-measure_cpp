#include <vector>
#include "io.h"
#include <fstream>  

class GetFileNameFormDisk
{
public:
	GetFileNameFormDisk(string path, string search_file_type, bool find_child_folder = true, bool add_path_before_name = false,int set_max_num=0){
		GetFileNameFormDisk::getAllFileNameFromDisk(path, search_file_type, this->files, find_child_folder, add_path_before_name, set_max_num);
	}
	~GetFileNameFormDisk();

	
	/*get file's name int selected folder and The specified type,
	GongCheng
	@path£ºfile_path
	@search_file_extension:file extension ,like this: .jpg
	@files:return files name vector
	@find_child_folder:Whether recursively searching for subfolders, default=true
	@add_path_before_name:add the file path before the file name before return, default=false
	@set_mat_num:Limit the maximum number of file's name to get, default=0, does not limit
	*/
	static void getAllFileNameFromDisk(string path, string search_file_type, vector<string>& files, bool find_child_folder = true, bool add_path_before_name = true,int set_mat_num=0)
	{
		//file handle
		intptr_t  hFile = 0;
		//file infomation
		struct _finddata_t fileinfo;
		string p;
	
		if ((hFile = _findfirst((p.assign(path).append("\\*") + search_file_type).c_str(), &fileinfo)) != -1)
		{
			do
			{
				if (set_mat_num>0 && files.size()>=set_mat_num){
					return;
				}
				//if this is folder
				if (!(fileinfo.attrib &  _A_SUBDIR))
				{
					//return path + file name
					if (add_path_before_name)
						files.push_back(p.assign(path).append("\\").append(fileinfo.name));
					else//return file name
						files.push_back(p.assign(fileinfo.name));
				}
			} while (_findnext(hFile, &fileinfo) == 0);
		}
		//If you want to find subfolders
		if (find_child_folder){
			if ((hFile = _findfirst((p.assign(path).append("\\*")).c_str(), &fileinfo)) != -1)
			{
				do
				{
					//If it is a directory, iterate it
					//If not, find the next one
					if ((fileinfo.attrib &  _A_SUBDIR))
					{
						if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
							getAllFileNameFromDisk(p.assign(path).append("\\").append(fileinfo.name), search_file_type, files, find_child_folder);
					}
				} while (_findnext(hFile, &fileinfo) == 0);
			}
		}
		_findclose(hFile);
	}

	vector<string>& getFiles(){
		return this->files;
	}
	friend ostream& operator<<(ostream& out, GetFileNameFormDisk& Files){
		vector<string> files = Files.getFiles();
		for (int i = 0; i < files.size(); i++){
			out << " files " << i + 1 << "  name:" << files[i] << endl;
		}
		return out;
	}
private:
	vector<string> files;
};

GetFileNameFormDisk::~GetFileNameFormDisk()
{

}

bool writeString(string file_path, string content, bool append = false){

	ofstream resultsfile(file_path);
	if (!resultsfile.is_open()){
		cout << "Unable to open file(" << file_path << ")" << endl;;
		return false;
	}
	resultsfile << content;
	resultsfile.close();
	return true;

}