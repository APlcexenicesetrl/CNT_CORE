#pragma once

#include "cnt.core.fixed.win64.h"

struct {
	struct {
		struct {
			struct {
				LPCWSTR help_text = L"\nScan the integrity of all CNT files and replace them with the correct CNT version\n\ncnt fixed [Parameters] or cnt.core.fixed [Parameters]\n\nParameter List: \nall (Default option) - Scan the integrity of all CNT files and attempt to repair any problematic files as much as possible.\ncheck - Scan the integrity of all CNT files without performing repair operations.\n\n";
				LPCWSTR start_fixed = L"Start repairing the CNT file that is in bad condition...\n";
				LPCWSTR end_fixed = L"Work on repairing CNT is completed\n";
				LPCWSTR end_fixed_NoResults = L"In this fix, there is no damage to any CNT files\n";
				LPCWSTR end_fixed_RepairSuccessful = L"Files with damaged CNT found, repair of damaged files completed\n";
				LPCWSTR end_fixed_FixNotCompleted = L"A damaged CNT file was found, but the repair was not completed\n";
				LPCWSTR end_fixed_FixSomeFiles = L"A damaged CNT file has been found, and repairs have been completed for some files\n";
				LPCWSTR end_fixed_ReportFixRepair = L"Here are some known issues for the repair: \n";
			} lang;

			struct {
				cnt::ConfigManager basic;
			} config;

			struct {
				std::vector<LPCWSTR> commandList;
				std::vector<LPCWSTR> errList;
				std::vector<LPCWSTR> FixProcessingEvent;

				bool commandFind(LPCWSTR target) {
					auto it = find(commandList.begin(), commandList.end(), target);
					if (it != commandList.end()) return true;
					return false;
				}

				void addErrorLog(unsigned short errorID, LPCWSTR resName) {
					switch (errorID) {
					case 1001:
						errList.push_back(StringConcatenation(L"Target file or folder does not exist: ", resName));
						commandList.push_back(StringConcatenation(L"mkdir ", resName));
						break;
					default:
						break;
					}
				}

				void reportError() {
					std::wcout << cnts.core.fixed.lang.end_fixed_ReportFixRepair;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
					for (int i = 0; i < errList.size(); ++i)
						std::wcout << i << L": " << errList[i] << std::endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				}
			} list;

			struct {
				void setConsoleColor(int colors) {
				}
			} Windows;

			cnt::Logging logs = cnt::Logging(new cnt::Logger("root"));

			LPCWSTR namespaces = L"cnt.core.fixed";
		} fixed;
	} core;
} cnts;
