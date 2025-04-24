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
		bool isFixed;
		if (vectorFind<LPCWSTR>(com, L"--fixed")) {
			logs.info("Check the file check");
			logs.info("This may take some time");
			logs.info("Please wait...");
		} else {
			logs.info("CNT.CORE is running");
			logs.info("Basic stage inspection...");
			logs.info("Get config file");
		}

		initBasic(isFixed);
	}
private:
	// Init
	void initBasic(bool isFixed) {
		try {
			Basic_Config.loadBinary(".cntconfigbin");
		}
		catch (std::exception& err) {
			if (isFixed) {
				logs.error("Error: {%s}", err.what());
				errList.push_back(LPCWSTR(err.what()));
				logs.warning("Fix...");
				registryBasicConfigFile();
				return;
			}
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