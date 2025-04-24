#pragma once

#include "win64.h"

void registryBasicConfigFile() {
	cnt::ConfigManager config;
	config.add("name", "CNT_CORE");
	config.add("namespace", "cnt.core");
	config.add("version", "1.0");
	config.add("description", "CNT in your computer");
	config.saveBinary(".cntconfigbin");
}