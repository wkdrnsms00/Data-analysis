#include <iostream> // hg19, 1~22 chr, Plink Summary statistic
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int i = 1;
    int CHR1;
    string SNP = "";
    string gar = "";
    int BP;
    vector <int> ac_ch;
    vector <string> ac_snp;
    vector <int> ac_bp;
    ofstream write;
    stringstream ssa;
    ifstream assoc;
    string str1;
    int size = 0;

    write.open("chr21.txt"); // ㄹㅇㄹ
    assoc.open("raw_1079.bim");


    while (!assoc.eof()) {
        getline(assoc, str1);
        ssa.str(str1);
        ssa >> CHR1; ssa >> SNP; ssa >> gar; ssa >> BP;
        ac_ch.push_back(CHR1); ac_snp.push_back(SNP); ac_bp.push_back(BP);
        ssa.clear();
    }

    int max = 46671632;
    int start = 10511353;
    int End = 10511353 + 1000000;
    for (int n = 1; n < 36; n++) {
        write << "Set" << n << endl; /// 변경
        for (int i = 0; i < ac_ch.size(); i++) {
            if (ac_ch[i] == 21) { /// 변경 
                if (ac_bp[i] >= start && ac_bp[i] <= End) {
                    write << ac_snp[i] << endl;

                }
            }
        }
        write << "END" << endl << endl;
        for (int z = 0; z < ac_bp.size(); z++) {
            if (ac_ch[z] == 21) { // 변경
                if (ac_bp[z] > End) {
                    start = ac_bp[z];
                    End = start + 1000000;
                    cout << ac_bp[z] << "          " << start << "             " << End << endl;
                    break;
                }
            }
        }


    }
    assoc.close();
    write.close();
}