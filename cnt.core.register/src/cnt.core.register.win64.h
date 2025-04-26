#pragma once

#include <filesystem>
#include <Windows.h>
#include <cstdlib>
#include <vector>

namespace fs = std::filesystem;

bool directoryExists(const LPCWSTR& path) {
    std::error_code ec;
    return fs::is_directory(path, ec) && !ec;
}