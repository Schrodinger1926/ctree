/*

Copyright (c) 2019 Sidharth Sindhra

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

*/
#include <iostream>
#include <string.h> 
#include <sys/param.h>
#include <memory>
#include "utils.h"
#include "parser.h"

void init_db(){
	std::cout << "Initializing database ..\n" << std::endl;
	auto cwd     = utils::get_current_dir();
	utils::touch(utils::join(cwd.get(), "CTREE").get());
}

void add_lib(const char* dependy, const char* name){
	std::cout << "Adding library .. " << std::endl;
	utils::make_dir(utils::join(dependy, name).get());
}

void add_exec(const char* dependy, const char* name){
	std::cout << "Adding executable .. " << std::endl;
	utils::make_dir(utils::join(dependy, name).get());
}

void add_node(int argc , char* argv[]){
	if(argc < 3){
		printf("[USAGE] %s %s [lib/exec (options)]\n", argv[0], argv[1]);
	}
	
	auto cwd     = utils::get_current_dir();
	auto dependy = parser::find_char_option(argc, argv, "--dependy", cwd.get());
	auto name    = parser::find_char_option(argc, argv, "--name", "untitled");
	
	//DEBUG
	std::cout << "dependy: " << dependy << '\n'
			  << "name:    " << name << std::endl;
	
	if(0==strcmp(argv[2], "lib"))
		add_lib(dependy, name);
	
	else if(0==strcmp(argv[2], "exec"))
		add_exec(dependy, name);

	else
		printf("[USAGE] %s %s [lib/exec (options)]\n", argv[0], argv[1]);
}

void clean_db(){
	std::cout << "cleaning database .." << std::endl;
}

void clean(int argc, char* argv[]){
	if(argc < 3){
		std::cout << "[USAGE] printing usage ..\n" << std::endl;
		return;
	}

	auto is_clean_db = parser::find_bool_option(argc, argv, "db", false);
	
	if(is_clean_db)
		clean_db();
}

int main(int argc, char* argv[])
{
	if(argc < 2){
		std::cout << "[USAGE] printing usage ..\n" << std::endl;
		return 0;
	}

	if(strcmp(argv[1], "init") == 0){
		init_db();
		return 0;
	}

	if(strcmp(argv[1], "add") == 0){
		add_node(argc, argv);
		return 0;
	}
	
	if(strcmp(argv[1], "clean") == 0){
		clean(argc, argv);
		return 0;
	}

	/* mem cleanup */

	return 0;
}
