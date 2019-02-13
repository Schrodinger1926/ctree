#include <memory>

namespace utils{
		std::unique_ptr<char> get_current_dir();
		std::unique_ptr<char> join(const char*, const char*);
		void make_dir(char*);
		void touch(const char*, const char*);
}
