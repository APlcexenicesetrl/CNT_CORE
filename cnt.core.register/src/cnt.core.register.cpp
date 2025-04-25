#include "cnt.core.register.console.h"
#include "cnt.core.register.gui.h"

int main(int argc, char **argv) {
	for (int i = 1; i < argc; ++i)
		cnts.core.registers.list.commandList.push_back((LPCWSTR)argv[i]);

}