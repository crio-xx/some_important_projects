#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
void inc(vector<vector<char>> &table)
{
    char c = 'A';
    for(int i=0; i<26; i++)
    {
        for(int j=0; j<26; j++)
        {
            table[i][j]= c+((i+j)%26);
        }
    }
}

string check_the(vector<vector<char>> &table, string chipher_text, int pos)
{
    string ans="   ";
    string word="THE";
    string chipher_word=chipher_text.substr(pos,3);

    for(int i=0; i<3; i++)
    {
        int num = (26+word[i]-'A')%26;
        int c = 0;
        while(table[num][c]!=chipher_word[i])
        {
            c++;
        }
        string s =" ";

        ans[i]=c+'A';
    }
    return ans;
}


int main()
{
    string chipher_text = "VHRMHEUZNFQDEZRWXFIDK";
    vector<vector<char>> table(26,vector<char>(26));
    inc(table);
    /*
    for(int i=0; i<26; i++)
    {
        for(int j=0; j<26; j++)
        {
            std::cout << table[i][j] << " ";
        }
        std::cout << "\n";
    }
    */
    string s;
    for(int i=0; i<chipher_text.size()-2;i++)
    {
        s=check_the(table,chipher_text,i);
        cout.width(3);
        std::cout  << i << ": ";
        for(int j=0; j<i;j++)
        {
            std::cout << "*";
        }
        std::cout << s;
        for(int j=i+3; j<chipher_text.size();j++)
        {
            std::cout << "*";
        }
        std::cout <<"\n";
    }

    return 0;
}
