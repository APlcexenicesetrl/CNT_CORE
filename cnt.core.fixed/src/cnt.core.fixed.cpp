#include "cnt.core.fixed.console.h"
#include "cnt.core.fixed.gui.h"

int main(int argc, char **argv) {
	// Init
	for (int i = 1; i < argc; ++i)
		cnts.core.fixed.list.commandList.push_back((LPCWSTR)argv[i]);

	cnts.core.fixed.logs.getLogger().enableConsoleOutput(false);

	if (cnts.core.fixed.list.commandFind(L"--gui")) startGUI();
	else if (cnts.core.fixed.list.commandList.empty()) std::wcout << cnts.core.fixed.lang.help_text;
	else {
		std::wcout << cnts.core.fixed.lang.start_fixed;
		
		switch (runConsole())
		{
		std::wcout << cnts.core.fixed.lang.end_fixed;
		case 0:
			std::wcout << cnts.core.fixed.lang.end_fixed_NoResults;
			if (cnts.core.fixed.list.commandFind(L"report"))
				cnts.core.fixed.list.reportError();
			break;
		case 1:
			std::wcout << cnts.core.fixed.lang.end_fixed_RepairSuccessful;
			if (cnts.core.fixed.list.commandFind(L"report"))
				cnts.core.fixed.list.reportError();
			break;
		case 2:
			std::wcout << cnts.core.fixed.lang.end_fixed_FixSomeFiles;
			if (cnts.core.fixed.list.commandFind(L"report"))
				cnts.core.fixed.list.reportError();
			break;
		case 3:
			std::wcout << cnts.core.fixed.lang.end_fixed_FixNotCompleted;
			if (cnts.core.fixed.list.commandFind(L"report"))
				cnts.core.fixed.list.reportError();
			break;
		default:
			break;
		}

	}
}