#pragma once
#include <string>

namespace Ciphers
{
    // 1) Виженер с прогрессивным ключом (RU, CP1251)
    std::string VigenereProg_Encrypt(const std::string& input, const std::string& key);
    std::string VigenereProg_Decrypt(const std::string& shifred, const std::string& key);

    // 2) Столбцовый (EN)
    std::string Columnar_Encrypt(const std::string& input, const std::string& key);
    std::string Columnar_Decrypt(const std::string& shifred, const std::string& key);
}

