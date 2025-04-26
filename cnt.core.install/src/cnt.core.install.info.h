#pragma once

#include "cnt.core.install.win64.h"

struct {
	struct {
		struct {
            struct {
				LPCWSTR HelpText = L"Use cnt.core.install to install the cnt program\nExample: cnt install[String:Install files path<Directory / URL>]\n";
            } lang;
			struct {
				bool Exists(const LPCWSTR& path) {
					std::error_code ec;
					return fs::is_directory(path, ec) && !ec;
				}
			} directory;
			struct {
				LPCWSTR StringConcatenation(LPCWSTR a1, LPCWSTR a2) {
					return (a1 + (std::wstring)a2).c_str();
				}
				LPCWSTR TempString(int length) {
					LPCWSTR toReturn = L"";
					for (int i = 0; i < length; ++i) {
						int randomNumber = rand() % 62;
						if (randomNumber < 10) toReturn += (char)(randomNumber + '0');
						else if (randomNumber < 36) toReturn += (char)(randomNumber + 'A');
						else toReturn += (char)(randomNumber + 'a');
					}
                    return toReturn;
				}
                bool is_url(LPCWSTR path) {
                    std::wstring wpath(path);
                    return wpath.find(L"http://") == 0 || wpath.find(L"https://") == 0;
                }

			} string;
			struct {
                bool DownloadFile(const std::wstring& url, const std::wstring& outputPath) {
                    try {
                        // �� std::wstring ת��Ϊ std::string
                        std::string urlStr(url.begin(), url.end());

                        // ���� URL
                        size_t protocolEnd = urlStr.find("://");
                        if (protocolEnd == std::string::npos) {
                            return false; // ��Ч�� URL
                        }

                        std::string protocol = urlStr.substr(0, protocolEnd);
                        std::string hostAndPath = urlStr.substr(protocolEnd + 3);
                        size_t pathStart = hostAndPath.find('/');
                        std::string host = hostAndPath.substr(0, pathStart);
                        std::string path = (pathStart != std::string::npos) ? hostAndPath.substr(pathStart) : "/";

                        // ���� httplib �ͻ���
                        httplib::Client client(host.c_str());
                        if (protocol == "https") {
                            client.enable_server_certificate_verification(false); // �����Ҫ֧�� HTTPS
                        }

                        // ���� GET ����
                        auto res = client.Get(path.c_str());
                        if (!res || res->status != 200) {
                            return false; // ����ʧ��
                        }

                        // ����Ӧ����д���ļ�
                        std::ofstream outFile(outputPath, std::ios::binary);
                        if (!outFile.is_open()) {
                            return false; // �ļ���ʧ��
                        }
                        outFile.write(res->body.c_str(), res->body.size());
                        outFile.close();

                        return true; // ���سɹ�
                    }
                    catch (...) {
                        return false; // ���������쳣
                    }
                }
			} net;
			struct {
				int TempStringLength = 16;
				LPCWSTR InstallTempNamespace;
			} config;
            struct {
				std::vector<LPCWSTR> commandList;
                bool commandFind(LPCWSTR target) {
                    auto it = find(commandList.begin(), commandList.end(), target);
                    if (it != commandList.end()) return true;
                    return false;
                }
            } list;
            struct {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            } console;
		} install;
	} core;
} cnts;