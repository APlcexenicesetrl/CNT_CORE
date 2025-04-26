#pragma once

#include "cnt.core.register.win64.h"

struct {
	struct {
		struct {
			struct {

			} lang;
			
			struct {
				std::vector<LPCWSTR> commandList;
				bool commandFind(LPCWSTR target) {
					auto it = find(commandList.begin(), commandList.end(), target);
					if (it != commandList.end()) return true;
					return false;
				}
			} list;
		} registers;
	} core;
} cnts;