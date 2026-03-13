#include <vcl.h>
#pragma hdrstop

#include "Ciphers.h"
#include <vector>
#include <utility>
#include <string>

#pragma package(smart_init)

using namespace std;

namespace Ciphers
{
	// Âèæåíåğ (RU)
    std::string VigenereProg_Encrypt(const std::string& input, const std::string& key)
    {
        string clean_key, full_key, output;
        string rualph    = "ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞß";
        string rualphmin = "àáâãäå¸æçèéêëìíîïğñòóôõö÷øùúûüışÿ";

        for (int i = 0; i < (int)key.size(); i++)
        {
            char ch = key[i];
            size_t p = rualphmin.find(ch);
            if (p != string::npos) ch = rualph[p];

            if (rualph.find(ch) != string::npos)
            {
                clean_key.push_back(ch);
            }
		}

        int n = (int)clean_key.size();
        if (n == 0)
			return "Key has no À..ß letters after cleaning.\n";

		// Øèôğàòîğ
		full_key.clear();
		output.clear();

        int rus_count = 0;
        for (int i = 0; i < (int)input.size(); i++)
        {
            char ch = input[i];
            size_t p = rualphmin.find(ch);
            if (p != string::npos) ch = rualph[p];

            if (rualph.find(ch) != string::npos)
                rus_count++;
        }

        for (int i = 0; i < rus_count; i++)
        {
            int basic_pos = (int)rualph.find(clean_key[i % n]);
            int new_pos = (basic_pos + (i / n)) % (int)rualph.size();
            full_key.push_back(rualph[new_pos]);
		}

		int k = 0;
		for (int i = 0; i < (int)input.size(); i++)
        {
            char ch = input[i];
            size_t p = rualphmin.find(ch);
            if (p != string::npos) ch = rualph[p];

            if (rualph.find(ch) != string::npos)
            {
                int shifred_pos = ((int)rualph.find(full_key[k]) + (int)rualph.find(ch)) % (int)rualph.size();
                output.push_back(rualph[shifred_pos]);
                k++;
            }
            else
            {
				output.push_back(input[i]);
            }
        }

        return output;
    }

	//Äåøèôğàòîğ
	std::string VigenereProg_Decrypt(const std::string& shifred, const std::string& key)
    {
		string clean_key, full_key, output;
        string rualph    = "ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞß";
        string rualphmin = "àáâãäå¸æçèéêëìíîïğñòóôõö÷øùúûüışÿ";

        for (int i = 0; i < (int)key.size(); i++)
        {
            char ch = key[i];
            size_t p = rualphmin.find(ch);
            if (p != string::npos) ch = rualph[p];

            if (rualph.find(ch) != string::npos)
            {
                clean_key.push_back(ch);
            }
        }

        int n = (int)clean_key.size();
        if (n == 0)
			return "Key has no À..ß letters after cleaning.\n";

        full_key.clear();
        output.clear();

        int rus_count = 0;
        for (int i = 0; i < (int)shifred.size(); i++)
        {
            char ch = shifred[i];
            size_t p = rualphmin.find(ch);
            if (p != string::npos) ch = rualph[p];

            if (rualph.find(ch) != string::npos)
                rus_count++;
        }

        for (int i = 0; i < rus_count; i++)
        {
            int basic_pos = (int)rualph.find(clean_key[i % n]);
			int new_pos = (basic_pos + (i / n)) % (int)rualph.size();
            full_key.push_back(rualph[new_pos]);
        }

		int k = 0;
		for (int i = 0; i < (int)shifred.size(); i++)
        {
            char ch = shifred[i];
            size_t p = rualphmin.find(ch);
            if (p != string::npos) ch = rualph[p];

            if (rualph.find(ch) != string::npos)
            {
				int deshifred_pos = ((int)rualph.size() + ((int)rualph.find(ch) - (int)rualph.find(full_key[k]))) % (int)rualph.size();

                output.push_back(rualph[deshifred_pos]);
                k++;
            }
            else
			{
				output.push_back(shifred[i]);
            }
        }

        return output;
    }

	// Ñòîëáöîâûé (EN)
    std::string Columnar_Encrypt(const std::string& input, const std::string& key)
    {
        string clean_input, output;
        string ealph    = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string ealphmin = "abcdefghijklmnopqrstuvwxyz";
        int lowl_index;
        char lowl;

        vector<pair<char, int>> key_items;
		key_items.reserve(key.size());

        for (int i = 0; i < (int)key.size(); i++)
        {
            char ch = key[i];
            size_t p = ealphmin.find(ch);
            if (p != string::npos) ch = ealph[p];

            if (ealph.find(ch) != string::npos)
            {
				key_items.push_back({ ch, (int)key_items.size() });
			}
        }

        int n = (int)key_items.size();
        if (n == 0)
            return "Key has no A..Z letters after cleaning.\n";

        vector<int> mas(n);

        for (int i1 = 0; i1 < n; i1++)
        {
            lowl = 'Z' + 1;
            lowl_index = -1;

            for (int i = 0; i < (int)key_items.size(); i++)
            {
                if (key_items[i].first < lowl)
                {
                    lowl = key_items[i].first;
                    lowl_index = i;

                    if (lowl == 'A')
                        break;
                }
            }

            mas[i1] = key_items[lowl_index].second;
            key_items.erase(key_items.begin() + lowl_index);
        }

        vector<int> rankOfPos(n);
        for (int r = 0; r < n; r++)
            rankOfPos[mas[r]] = r;

        for (int i = 0; i < (int)input.size(); i++)
        {
            char ch = input[i];
            size_t p = ealphmin.find(ch);
            if (p != string::npos) ch = ealph[p];

            if (ealph.find(ch) != string::npos)
                clean_input.push_back(ch);
        }

        vector<int> mas_input;
        mas_input.reserve(input.size());
        mas_input.resize(clean_input.size());

        for (int i = 0; i < (int)clean_input.size(); i++)
        {
            int pos0 = i % n;
            mas_input[i] = rankOfPos[pos0];
        }

        string cipher_letters;
        cipher_letters.reserve(clean_input.size());

        for (int r = 0; r < n; r++)
        {
            for (int i = 0; i < (int)clean_input.size(); i++)
            {
                if (mas_input[i] == r)
                    cipher_letters.push_back(clean_input[i]);
            }
        }

        string cipher_full;
        cipher_full.reserve(input.size());

        int k = 0;
        for (int i = 0; i < (int)input.size(); i++)
        {
            char ch = input[i];
            size_t p = ealphmin.find(ch);
            if (p != string::npos) ch = ealph[p];

            if (ealph.find(ch) != string::npos)
                cipher_full.push_back(cipher_letters[k++]);
            else
                cipher_full.push_back(input[i]);
        }

        return cipher_full;
	}

	//Äåøèôğîâàíèå
    std::string Columnar_Decrypt(const std::string& shifred, const std::string& key)
    {
        string clean_shifred;
        string ealph    = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string ealphmin = "abcdefghijklmnopqrstuvwxyz";
        int lowl_index;
		char lowl;

        vector<pair<char, int>> key_items;
        key_items.reserve(key.size());

        for (int i = 0; i < (int)key.size(); i++)
        {
            char ch = key[i];
            size_t p = ealphmin.find(ch);
            if (p != string::npos) ch = ealph[p];

            if (ealph.find(ch) != string::npos)
            {
				key_items.push_back({ ch, (int)key_items.size() });
            }
        }

        int n = (int)key_items.size();
        if (n == 0)
            return "Key has no A..Z letters after cleaning.\n";

        vector<int> mas(n);

        for (int i1 = 0; i1 < n; i1++)
        {
            lowl = 'Z' + 1;
            lowl_index = -1;

            for (int i = 0; i < (int)key_items.size(); i++)
            {
                if (key_items[i].first < lowl)
                {
                    lowl = key_items[i].first;
                    lowl_index = i;

                    if (lowl == 'A')
                        break;
                }
            }

            mas[i1] = key_items[lowl_index].second;
            key_items.erase(key_items.begin() + lowl_index);
        }

        for (int i = 0; i < (int)shifred.size(); i++)
        {
            char ch = shifred[i];
            size_t p = ealphmin.find(ch);
            if (p != string::npos) ch = ealph[p];

            if (ealph.find(ch) != string::npos)
                clean_shifred.push_back(ch);
        }

        int L = (int)clean_shifred.size();

        vector<int> colLenByPos(n, L / n);
        int rem = L % n;
        for (int pos = 0; pos < rem; pos++)
            colLenByPos[pos]++;

        vector<string> colByPos(n);
        int idx = 0;
        for (int r = 0; r < n; r++)
        {
            int pos = mas[r];
            int len = colLenByPos[pos];
            colByPos[pos] = clean_shifred.substr(idx, len);
            idx += len;
        }

        vector<int> taken(n, 0);
        string decrypted;
        decrypted.reserve(L);

        int rows = (L + n - 1) / n;
        for (int row = 0; row < rows; row++)
        {
            for (int pos = 0; pos < n; pos++)
            {
                if (taken[pos] < (int)colByPos[pos].size())
                {
                    decrypted.push_back(colByPos[pos][taken[pos]]);
                    taken[pos]++;
                }
            }
        }

        string decrypted_full;
        decrypted_full.reserve(shifred.size());

        int kd = 0;
        for (int i = 0; i < (int)shifred.size(); i++)
        {
            char ch = shifred[i];
            size_t p = ealphmin.find(ch);
            if (p != string::npos) ch = ealph[p];

            if (ealph.find(ch) != string::npos)
                decrypted_full.push_back(decrypted[kd++]);
            else
                decrypted_full.push_back(shifred[i]);
        }

        return decrypted_full;
    }
}

