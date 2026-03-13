#pragma once
#include <System.hpp>
#include <Windows.h>
#include <string>

inline std::string UnicodeStringToCP1251(const System::UnicodeString& s)
{
    if (s.IsEmpty()) return std::string();

    int lenW = s.Length();
    int bytes = WideCharToMultiByte(1251, 0, s.c_str(), lenW, nullptr, 0, nullptr, nullptr);

    std::string out(bytes, '\0');
    WideCharToMultiByte(1251, 0, s.c_str(), lenW, out.data(), bytes, nullptr, nullptr);
    return out;
}

inline System::UnicodeString CP1251ToUnicodeString(const std::string& s)
{
    if (s.empty()) return System::UnicodeString();

    int chars = MultiByteToWideChar(1251, 0, s.data(), (int)s.size(), nullptr, 0);

    System::UnicodeString out;
    out.SetLength(chars);
    MultiByteToWideChar(1251, 0, s.data(), (int)s.size(), out.c_str(), chars);
    return out;
}

