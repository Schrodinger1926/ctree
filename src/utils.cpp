#include "utils.h"
#include <unistd.h>
#include <sys/param.h>
#include <string.h> 
#include <sys/stat.h> 
#include <sys/types.h>
#include <iostream>
#include <fstream>

namespace utils{
	std::unique_ptr<char> get_current_dir(){
		std::unique_ptr<char> buff(new char[100]);
		if(getcwd(buff.get(), MAXPATHLEN) == NULL){
			std::cout << "error: unable to retrive current working directory" << std::endl;
			exit(EXIT_FAILURE);
		}
		return buff;
	}

	void make_dir(char* loc){
		std::cout << "Creating directory: " << loc << std::endl; 
		if(mkdir(loc, 0777) == -1){
				std::cerr << "Error: " << strerror(errno) << std::endl;
				exit(EXIT_FAILURE);
		}
	}
	
	void touch(char* filepath){
			std::ofstream outfile(filepath);
			outfile.close();
	}

	std::unique_ptr<char> join(const char* dependy, const char* name){
		std::unique_ptr<char> dir(new char[MAXPATHLEN]);
		strcpy(dir.get(), dependy);
		strcat(dir.get(), "/");
		strcat(dir.get(), name);
		return dir;
	}
}
