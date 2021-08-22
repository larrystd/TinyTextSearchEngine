#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <cstring>
#include "ftse_env.h"
#include "encoding.h"
#include "token.h"
#include "global.h"

using namespace std;

int main() {
    std::string str("全文搜索引擎");
    
    ftse::UTF32Char* ustr;
    //unsigned int32_t ustr_len = 0;
    int ustr_len = 0;
    ftse::Encoding::utf8toutf32(str.c_str(), strlen(str.c_str()), &ustr, &ustr_len);
    cout << "ustr and ustr_len" <<endl;
    cout << *ustr << endl;
    cout << ustr_len << endl;
    const ftse::UTF32Char* start;;
    int n = ftse::Token::ngram_next(ustr, ustr+ustr_len, 2, &start); 
    //cout << "n: " << n << endl << " start: " << *start << endl;;

    cout << "*****搜索引擎*******"<<endl;
    ftse::FullTextSearchEngineEnv ftse_env(N_GRAM, 0, true);

    /// title body
    ftse_env.add_document("搜索", str.c_str());

    /*
    token 全文 文搜 搜索 索引 引擎 擎

    检索：
    引擎 索引 搜索 全文 文搜
    */
    //ftse::Token token;
    //token.text_to_postings_lists(ftse_env, 333, ustr, ustr_len, 2);
    //token.text_to_postings_lists(ftse_env, 444, ustr, ustr_len, 2);
    return 0;
}
