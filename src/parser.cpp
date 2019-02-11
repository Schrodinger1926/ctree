#include <string.h> 
#include "parser.h"

namespace parser{

	char* find_char_option(int argc, char* argv[], const char* key, char* def){
		for(int i = 0 ; i < argc - 1; ++i){
			if(0==strcmp(key, argv[i])){
				def = argv[i+1];
				break;
			}
		}
		return def;
	}
}
