#pragma once

#include <filesystem>
#include <windows.h>
#include <cstdlib>

#include <cnt/loggings.h>
#include <cnt/config.h>

namespace fs = std::filesystem;

bool directoryExists(const LPCWSTR& path) {
    std::error_code ec;
    return fs::is_directory(path, ec) && !ec;
}

LPCWSTR StringConcatenation(LPCWSTR a1, LPCWSTR a2) {
    return ((std::wstring)a1 + (std::wstring)a2).c_str();
}