#pragma once

#include "win64.h"
#include "program_fixed.h"

class client {
private:
	cnt::Logging logs;
	std::vector<LPCWSTR> commandList;
	cnt::ConfigManager Basic_Config;
	std::vector<LPCWSTR> errList;
public:
	client(std::vector<LPCWSTR>& com) : commandList(com), logs(&cnt::Logger("root"))
	{
		if (vectorFind(commandList, L"--debug")) logs.getLogger().setLevel(cnt::LogLevel::DEBUG);
		if (vectorFind(commandList, L"--fixed")) {
			try { Basic_Config.loadBinary(".cntconfigbin"); }
			catch (std::exception &err) {
				errList.push_back(LPCWSTR(err.what()));
				registryBasicConfigFile();
			}

			if (!CreateDirectory(L"Config", nullptr)) errList.push_back(L"The directory 'Config' does not exist");
			if (!CreateDirectory(L"Program", nullptr)) errList.push_back(L"The directory 'Program' does not exist");
			if (!CreateDirectory(L"Temp", nullptr)) errList.push_back(L"The directory 'Temp' does not exist");
			if (!CreateDirectory(L"Assets", nullptr)) {
				errList.push_back(L"The directory 'Assets' does not exist");
			}

			exit(200);
		}

		logs.info("CNT.CORE is running");
		logs.info("Basic stage inspection...");
		logs.info("Get config file");
		initBasic();
	}
private:
	// Init
	void initBasic() {
		try {
			Basic_Config.loadBinary(".cntconfigbin");
		}
		catch (std::exception& err) {
			logs.critical("Error: {%s}", err.what());
		}
	}

	// 
	template<typename _T>
	bool vectorFind(std::vector<_T>& vec, _T target) {
		auto it = find(vec.begin(), vec.end(), target);
		if (it != vec.end()) return true;
		return false;
	}
};