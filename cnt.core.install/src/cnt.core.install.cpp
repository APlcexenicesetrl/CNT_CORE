#include "cnt.core.install.console.h"

int main(int argc, char **argv) {
	for (int i = 1; i < argc; ++i)
		cnts.core.install.list.commandList.push_back((LPCWSTR)argv[i]);

	if (cnts.core.install.list.commandList.empty()) {
		std::wcout << cnts.core.install.lang.HelpText;
		exit(0);
	}

	installer inst;
}