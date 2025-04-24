#include "client.h"

int main(int argc, char **argv) {
	std::vector<LPCWSTR> args;
	for (int i = 1; i < argc; ++i)
		args.push_back(LPCWSTR(argv[i]));

	client winx(args);
}