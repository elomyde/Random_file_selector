#include <filesystem>
#include <vector>

using namespace std;
namespace fs = std::filesystem;
int main(void){
	srand(time(NULL));
	vector<fs::path> file_list;
	fs::path to("./Selected/");
	fs::create_directory(to);
	fs::directory_iterator itr(fs::current_path());

	while (itr != fs::end(itr)) {
		
		file_list.push_back(*itr);
		itr++;
	}

	int rand_itr = rand() % file_list.size();
	fs::path filename = file_list[rand_itr].filename();
	fs::copy_file(file_list[rand_itr], to/filename, fs::copy_options::overwrite_existing);
}
