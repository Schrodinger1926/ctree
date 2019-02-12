#include <string.h> 
#include "parser.h"

namespace parser{

		char* find_char_option(int argc, char* argv[], const char* key, char* def){
				for(int i = 1 ; i < argc - 1; ++i){
						if(0==strcmp(key, argv[i])){
								def = argv[i+1];
								break;
						}
				}
				return def;
		}
		bool find_bool_option(int argc, char* argv[], const char* key, bool def){
				for(int i = 2 ; i < argc; ++i){
						if(0==strcmp(key, argv[i])){
								def = true;
								break;
						}
				}
				return def;
		}
}
