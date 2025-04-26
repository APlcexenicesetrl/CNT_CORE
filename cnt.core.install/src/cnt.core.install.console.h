#pragma once

#include "cnt.core.install.info.h"

class installer {
public:
	installer() {
		cnts.core.install.config.InstallTempNamespace =
			cnts.core.install.string.TempString(
				cnts.core.install.config.TempStringLength);

		CreateDirectory(cnts.core.install.string.StringConcatenation
			(L"Temp/", cnts.core.install.config.InstallTempNamespace), nullptr);

		if (cnts.core.install.string.is_url(
			cnts.core.install.list.commandList[0])) {
			if (!cnts.core.install.net.DownloadFile(
				cnts.core.install.list.commandList[0],
				L"Temp")) {
				std::wcout << L"\033[31mError: Failed to download file from URL.\033[0m\n";
			}
		}
	}
};