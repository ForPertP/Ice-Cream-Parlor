#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'icecreamParlor' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER m
 *  2. INTEGER_ARRAY arr
 */

vector<int> icecreamParlor(int m, vector<int> arr)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < arr.size(); ++i)
    {
        int need = m - arr[i];
        auto it = mp.find(need);
        if (it != mp.end())
            return { it->second + 1, i + 1 };

        mp[arr[i]] = i;
    }

    return {};
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string m_temp;
        getline(cin, m_temp);

        int m = stoi(ltrim(rtrim(m_temp)));

        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

 
        vector<int> result = icecreamParlor(m, arr);

        for (size_t i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);
    s.erase(
        s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) { return !isspace(ch); })
    );
    return s;
}

string rtrim(const string &str)
{
    string s(str);
    s.erase(
        find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !isspace(ch); }).base(), s.end()
    );
    return s;
}

std::vector<string> split(const string &str)
{
    vector<string> tokens;
    string_view str_view(str);
    size_t start = 0;
    size_t end = 0;

    while ((end = str_view.find(' ', start)) != string_view::npos)
    {
        if (end > start)
        {
            tokens.emplace_back(str_view.substr(start, end - start));
        }
        start = end + 1;
    }

    if (start < str_view.size())
    {
        tokens.emplace_back(str_view.substr(start));
    }

    return tokens;
}
