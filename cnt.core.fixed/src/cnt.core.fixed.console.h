#pragma once

#include "cnt.core.fixed.info.h"

auto checkDirectory = [] {
	if (!directoryExists(L"Assets")) cnts.core.fixed.list.addErrorLog(1001, L"Assets");
	if (!directoryExists(L"Config")) cnts.core.fixed.list.addErrorLog(1001, L"Config");
	if (!directoryExists(L"Program")) cnts.core.fixed.list.addErrorLog(1001, L"Program");
	if (!directoryExists(L"Temp")) cnts.core.fixed.list.addErrorLog(1001, L"Temp");
};

auto configFilesCheck = [] {
	try { cnts.core.fixed.config.basic.loadBinary(".cntconfig"); }
	catch (std::exception& err) { cnts.core.fixed.list.addErrorLog(1001, L".cntconfig"); }

	try { cnts.core.fixed.config.basic.loadBinary("Config/config.cntconfigbin"); }
	catch (std::exception& err) { cnts.core.fixed.list.addErrorLog(1001, L"Config/config.cntconfigbin"); }

	try { cnts.core.fixed.config.basic.loadBinary("Config/console.cntconfigbin"); }
	catch (std::exception& err) { cnts.core.fixed.list.addErrorLog(1001, L"Config/console.cntconfigbin"); }

	try { cnts.core.fixed.config.basic.loadBinary("Config/gui.cntconfigbin"); }
	catch (std::exception& err) { cnts.core.fixed.list.addErrorLog(1001, L"Config/gui.cntconfigbin"); }

};

int runConsole() {
	// Check
	
	/* Check List (Development)
	 * Directory 'Assets'
	 * Directory 'Config'
	 * Directory 'Program'
	 * Directory 'Temp'
	 * Config file '.cntconfigbin'
	 * Config file 'Config/config.cntconfigbin'
	 * Config file 'Config/console.cntconfigbin'
	 * Config file 'Config/gui.cntconfigbin'
	 */

	checkDirectory();
	configFilesCheck();

	// Fixed
	if (cnts.core.fixed.list.commandList.empty() ||
		cnts.core.fixed.list.commandFind(L"all") || 
		!cnts.core.fixed.list.commandFind(L"check")) {
		return 0;
	}
}