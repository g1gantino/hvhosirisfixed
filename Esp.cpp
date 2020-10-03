#define NOMINMAX

#include <sstream>
#include <locale>
#include <iostream>

#include "Esp.h"
#include "../Config.h"
#include "../Interfaces.h"
#include "../Memory.h"
#include "../Hooks.h"

#include "../SDK/ConVar.h"
#include "../SDK/Entity.h"
#include "../SDK/GlobalVars.h"
#include "../SDK/Localize.h"
#include "../SDK/Surface.h"
#include "../SDK/Vector.h"
#include "../SDK/WeaponData.h"

static constexpr bool worldToScreen(const Vector& in, Vector& out) noexcept
{
    const auto& matrix = interfaces->engine->worldToScreenMatrix();
    float w = matrix._41 * in.x + matrix._42 * in.y + matrix._43 * in.z + matrix._44;

    if (w > 0.001f) {
        const auto [width, height] = interfaces->surface->getScreenSize();
        out.x = width / 2 * (1 + (matrix._11 * in.x + matrix._12 * in.y + matrix._13 * in.z + matrix._14) / w);
        out.y = height / 2 * (1 - (matrix._21 * in.x + matrix._22 * in.y + matrix._23 * in.z + matrix._24) / w);
        out.z = 0.0f;
        return true;
    }
    return false;
}

static void renderSnaplines(Entity* entity, const Config::Esp::Shared& config) noexcept
{
    if (!config.snaplines.enabled)
        return;

    Vector position;
    if (!worldToScreen(entity->getAbsOrigin(), position))
        return;

    if (config.snaplines.rainbow)
        interfaces->surface->setDrawColor(rainbowColor(memory->globalVars->realtime, config.snaplines.rainbowSpeed));
    else
        interfaces->surface->setDrawColor(config.snaplines.color);

    const auto [width, height] = interfaces->surface->getScreenSize();
    interfaces->surface->drawLine(width / 2, height, static_cast<int>(position.x), static_cast<int>(position.y));
}
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class psdmzym {
public:
    bool hfqapumvrnntces;
    string cmzsgrluu;
    string fgvkwlqeldcje;
    string pksdykquanoz;
    int dwoirvmluvuut;
    psdmzym();
    bool rqhypmgsgveadytxasabnm();
    string vdtloolxlpxrrg(string tbmmobv, int czhnrporajdq, string jdzopilw, int ykwrrwmt, string ifmkyruxchhgcza, int aclotkj);
    string mahbqrjqknbq(bool xcecvzgrp, string iircigquj, int wvomvyq, double ilxei, int xlgwbib, double qwldazzxqkkj, int eqpdwltws);
    string fswuxarteedhikxstw(bool cueklis, string pjtff, double azqscmjvudmslt, string owbihwzmt, int axwgqrz, int rwthklvznbmz, double uehhlunayjxdzaf);
    void glmnaphmckvyqmd(double fdbkbfudscsae, bool mhtcdoq, double aetjas, string mfzjtclfc, bool gmsmouheyjpyeu, int yhkzxogk, int rfscjxmsrlgadok, string yxhavnjz, bool twpbinczemagp, int xdbevyj);
    string ssqimupdry();
    int tpndzbcgtyjccavurocb(bool oevvuygarxpciu);
    int dvwslpligyzcx(bool pqofxjavtknr, double jkxyfnxuk, string qhoeryhr);
    double qsoxuvydgfn(int bznfdhatrmafuxq, bool fckhlbkz, bool bfgktk, double pxnenbmecsorbf, bool rywjj, bool tsyvvw, string xvbtg, double lbinieojdia, int cudyszhw, int mxrtcsziz);

protected:
    int qpadwgnzslgwjzz;
    string dyzcwzgnyb;

    bool kjwtuwkupledwzjjfstujebc(bool dtoezya, double jdblvgzh, bool qsndmk);
    string ukcyiksksa(string scxvrdhphjaot, int ukubiuxerqab, string astvjmao, int xhennewqoghz, string jlggdmcnri, double ficaiuzrbk, bool rctvdjvvo, int axpvcuekvyd, bool hjxqqokdqnedpk, string hvkahgdpzxvvjfr);
    void txjiqzyxjpixrwnr(string jbfdfrlsao, double yhnuatpoqt, bool uwgootftrmss, int cqpfpiujecgxmw);
    string rdbnxwyohluwvqcc(int lodiegdrw, bool cdtdasobyu, double amrkdwu, bool xystvyhaqrugznt);
    bool udzqfhgqbddhjfuqp(bool reyjz, int uclhnngo, int kljwhtiazs, string ktkqgvjnhu, double fjwtbvelvmnhar, string swwkcs, string svlaupbrpmrlbuo, string bbkaixjwus, double tmfbtlthglxtw);
    double gziytqpujbnooxdp(bool mbjabcozfrzfz);
    int ocqfyiymfk(double axpmchpxbeh, string vmcwurx, double helyaozckrko, int fsiqyb, bool wkvvynlclqya, string wfufnufqirxhqg, string nncqjcizlzrw, string skszhkseonvtgo, double fkesypvbyvt, int rgpaxqwktfc);
    void hmeentnhmcmigbbqj(string ytorqswjtedw, double fkzgkgjswumjlp, double sqtwhjrfwmz, int ggwcsbhuqfgn, string nsvxshs, double xsbqpgg, string lbryjndnocgd, double fgkfc, bool tfgfxkigty, double nmmzwadpmbtssh);
    int bolbjxxsyfsbbmja(bool khupsgxehmnbqi, double phfnohxxsxng);

private:
    string abrbvsbboffwcp;

    int tubnkifpbosmum(bool bhgzfxveozwyun, string mpxmhruo, string tbllezi, double rhgyvzm, bool jsbrctmsnqc, int redlny, double oynykhqu, string apohllauheycw, string zvzhgxxc);
    double oojbhxgfarmkc(string oxntije);
    string mqjuvxuqabohgthdrrwlntgvl(int ypdvbcwj, bool wydnaktitiv, bool gbswisbvhv, double oyzdqaqvajzxfkr, string gnulyw, bool sbvjxshguh, string ounkkkrb, bool aadoj);
    int ufyvqtrkit(bool vyupnadlynmlvf, int madbgdqy, int yvtqjpcvwszhe, int logmhb, double lvdhucrxzs, int gpymifzkoeslrzx, string vrdpsdzfshf, string mbwetjraohaixub, int wcubegncwktm, string jnwoljffpc);
    bool ibgfjdybqitgtnswvktt(string tfbdocljgyub, int arxayddhdyoosty, double nzdlffcv);
    double bzqmzpgzsp(int xjmjvwqh, int ngkhxlvlt, string pufud, string hexplolehd, bool fsymkvliit, double wopbmlsz, int vfjzaarnvzxhgz, bool brjchjlrf, bool gonpup);
    void idkhxgekop(int jzyazthqkuhvbt);
    double stddnvxwdwwjd(int pvbgoavnwizf);
    bool gdeimvhsumdqemjgtlwmt(int cmwmlyygz, int ngdzevgvsrrc, int bamwfessjtd, int amuyxzrz);

};


int psdmzym::tubnkifpbosmum(bool bhgzfxveozwyun, string mpxmhruo, string tbllezi, double rhgyvzm, bool jsbrctmsnqc, int redlny, double oynykhqu, string apohllauheycw, string zvzhgxxc) {
    string rpgwqt = "jsnymgwwpyqbjysdqcapelznrldcljehidkaksfahozvwanujirrtykrnwydvwuzrdszxuwtujdum";
    string jxmmzagvqhzndgb = "lacwlznxvhrzzflwpgvrehaxxetvkarplzvnaaecywfemwungisjnykozxoawnfrgxtvympdz";
    string qtscb = "ozljfvqtqutzavpmyqfyssaexhdhxnlzyczamgcqumlczptdilivwqmsqiwcldqjatedtbxpymmhtsfqodkqilalxuemvfel";
    string puhbemaybhpy = "rjxgynmtldfypbickusvwnzfqxjrbxcdlqjpcqwnfldkwsxkp";
    string inlgoerb = "deunzoowhkcobjwumhsbfbdojkqvlcubnjyvwbkmngkkihxrqbfihxqtpeorrbseqamwifuip";
    double gvwqnx = 9773;
    bool zdhcllh = false;
    double earkjidnlim = 53100;
    string qhhjzraclo = "gupbhcjftjuofhxhmkje";
    if (string("rjxgynmtldfypbickusvwnzfqxjrbxcdlqjpcqwnfldkwsxkp") == string("rjxgynmtldfypbickusvwnzfqxjrbxcdlqjpcqwnfldkwsxkp")) {
        int unueexmuc;
        for (unueexmuc = 82; unueexmuc > 0; unueexmuc--) {
            continue;
        }
    }
    if (string("lacwlznxvhrzzflwpgvrehaxxetvkarplzvnaaecywfemwungisjnykozxoawnfrgxtvympdz") != string("lacwlznxvhrzzflwpgvrehaxxetvkarplzvnaaecywfemwungisjnykozxoawnfrgxtvympdz")) {
        int wlfchwmvwx;
        for (wlfchwmvwx = 52; wlfchwmvwx > 0; wlfchwmvwx--) {
            continue;
        }
    }
    if (string("lacwlznxvhrzzflwpgvrehaxxetvkarplzvnaaecywfemwungisjnykozxoawnfrgxtvympdz") != string("lacwlznxvhrzzflwpgvrehaxxetvkarplzvnaaecywfemwungisjnykozxoawnfrgxtvympdz")) {
        int glr;
        for (glr = 56; glr > 0; glr--) {
            continue;
        }
    }
    if (string("lacwlznxvhrzzflwpgvrehaxxetvkarplzvnaaecywfemwungisjnykozxoawnfrgxtvympdz") == string("lacwlznxvhrzzflwpgvrehaxxetvkarplzvnaaecywfemwungisjnykozxoawnfrgxtvympdz")) {
        int ruikq;
        for (ruikq = 67; ruikq > 0; ruikq--) {
            continue;
        }
    }
    if (53100 != 53100) {
        int wrem;
        for (wrem = 52; wrem > 0; wrem--) {
            continue;
        }
    }
    return 22833;
}

double psdmzym::oojbhxgfarmkc(string oxntije) {
    string dkwcc = "yovdcgaqopnjrbjecukvduneoypnnvzfdewcwuiavroezjivf";
    int fztxelwtu = 5524;
    double bgnhz = 52178;
    string gguefnxtmrwtsv = "mgocjbuklloqqmggaypfsaouuzrdvtvbfgvrnyhnoeyujbwfinffgtpgmqoxlxcwrusuqilmnjooc";
    string prhgigpsruyfet = "qvsswnbytfkgtdztuuxwvmuixnbdcudkzztmbyosunhvc";
    double kptcdvtuxbfipd = 18399;
    double gyofcehtwdd = 28224;
    int obuahokvbjss = 7676;
    bool pjurzfkiiaa = true;
    if (28224 == 28224) {
        int lmwkwyhoo;
        for (lmwkwyhoo = 24; lmwkwyhoo > 0; lmwkwyhoo--) {
            continue;
        }
    }
    if (52178 != 52178) {
        int dtlx;
        for (dtlx = 34; dtlx > 0; dtlx--) {
            continue;
        }
    }
    return 4579;
}

string psdmzym::mqjuvxuqabohgthdrrwlntgvl(int ypdvbcwj, bool wydnaktitiv, bool gbswisbvhv, double oyzdqaqvajzxfkr, string gnulyw, bool sbvjxshguh, string ounkkkrb, bool aadoj) {
    double jxvor = 18789;
    int lcdutnr = 7064;
    bool mobhklbu = false;
    string pludj = "tjtjaczmfjiihd";
    double hlrstahytbizti = 52012;
    string oofmlzukhjnpz = "puffjdppqwgthxvlxztjnkhsrdcohwg";
    int xyargmnqexuogf = 2118;
    string cwoebsawnxxw = "funbwnapgnsjlwbnuxiamjnyoaghdqsvhtftbamxqqwscbiiamqnbbtdiuydtwgeckcsnao";
    if (52012 == 52012) {
        int rvfegvg;
        for (rvfegvg = 17; rvfegvg > 0; rvfegvg--) {
            continue;
        }
    }
    return string("nfxolglnshckzllvojtf");
}

int psdmzym::ufyvqtrkit(bool vyupnadlynmlvf, int madbgdqy, int yvtqjpcvwszhe, int logmhb, double lvdhucrxzs, int gpymifzkoeslrzx, string vrdpsdzfshf, string mbwetjraohaixub, int wcubegncwktm, string jnwoljffpc) {
    int uewbxqtjotqnrdl = 5517;
    string ibqtzhmvahb = "wzlzzcvmqqvcnaeqtdwmrvpizhsihudqtasuicizjxtqwszubtfvpzquwbbrjtaayrqjnoqyephv";
    int rixicreaiusut = 7999;
    int epnhfgwoygbcq = 4573;
    double tbqvrzcanjtnlja = 13368;
    bool fcwufbapznng = false;
    double gjztlsvehflcqg = 146;
    string rkcscswmz = "jndhbaoekhxjhqoydimcghahtylnjhrnbzymlgpilohjbeoagxtyyriiagyunlqdkc";
    string shwfmkhrtlb = "fvvqkmvqvuxpbrwxhtzpsvgaecjsitaeufxkwepgvkkopqofkkhhmvlkksfzrgskmbcwlvtmjrlnuksuunvrkzvgfdnkijb";
    double qbjjnempqeg = 6114;
    if (6114 != 6114) {
        int iwulkifjen;
        for (iwulkifjen = 59; iwulkifjen > 0; iwulkifjen--) {
            continue;
        }
    }
    if (7999 != 7999) {
        int fuf;
        for (fuf = 23; fuf > 0; fuf--) {
            continue;
        }
    }
    if (string("fvvqkmvqvuxpbrwxhtzpsvgaecjsitaeufxkwepgvkkopqofkkhhmvlkksfzrgskmbcwlvtmjrlnuksuunvrkzvgfdnkijb") == string("fvvqkmvqvuxpbrwxhtzpsvgaecjsitaeufxkwepgvkkopqofkkhhmvlkksfzrgskmbcwlvtmjrlnuksuunvrkzvgfdnkijb")) {
        int ctqj;
        for (ctqj = 51; ctqj > 0; ctqj--) {
            continue;
        }
    }
    return 90915;
}

bool psdmzym::ibgfjdybqitgtnswvktt(string tfbdocljgyub, int arxayddhdyoosty, double nzdlffcv) {
    int nprmokwxmur = 1494;
    double neboks = 10714;
    int qjflxlxrzhposg = 753;
    string jcltt = "nqvhqlpdjmiklutthhszvcpvonbigqkplkktcauythiwflbflvwffxykvzieggmrpeuiiegrnuaghuhcqnjc";
    bool jmshztdseu = true;
    double urggimhxylv = 10830;
    string lvnfxpyoq = "h";
    int sghvrkcj = 145;
    string xooyxmpucryjk = "prbwnmhplnmhdulkjtiryepqjgpdzscczjijjcutoojaxbgngxdyzhgdgjtnemdn";
    if (string("nqvhqlpdjmiklutthhszvcpvonbigqkplkktcauythiwflbflvwffxykvzieggmrpeuiiegrnuaghuhcqnjc") == string("nqvhqlpdjmiklutthhszvcpvonbigqkplkktcauythiwflbflvwffxykvzieggmrpeuiiegrnuaghuhcqnjc")) {
        int bv;
        for (bv = 29; bv > 0; bv--) {
            continue;
        }
    }
    if (string("prbwnmhplnmhdulkjtiryepqjgpdzscczjijjcutoojaxbgngxdyzhgdgjtnemdn") != string("prbwnmhplnmhdulkjtiryepqjgpdzscczjijjcutoojaxbgngxdyzhgdgjtnemdn")) {
        int dsffkn;
        for (dsffkn = 60; dsffkn > 0; dsffkn--) {
            continue;
        }
    }
    return false;
}

double psdmzym::bzqmzpgzsp(int xjmjvwqh, int ngkhxlvlt, string pufud, string hexplolehd, bool fsymkvliit, double wopbmlsz, int vfjzaarnvzxhgz, bool brjchjlrf, bool gonpup) {
    bool ggtwl = true;
    double uygswpcrn = 8144;
    string exucutplahh = "pintbtzzvhfuhxqsatknejszwspqfvucilhfwdbuibroiuujfn";
    double nfvydab = 9667;
    bool mjtprvrsd = false;
    bool jpqdpnxl = true;
    double bxiex = 32227;
    double wjgyvuigotdu = 42050;
    double lrnvniq = 47008;
    return 39265;
}

void psdmzym::idkhxgekop(int jzyazthqkuhvbt) {
    int qfhxnlmbk = 4753;
    if (4753 != 4753) {
        int fjd;
        for (fjd = 37; fjd > 0; fjd--) {
            continue;
        }
    }
    if (4753 == 4753) {
        int zuxokgk;
        for (zuxokgk = 36; zuxokgk > 0; zuxokgk--) {
            continue;
        }
    }
    if (4753 == 4753) {
        int qpw;
        for (qpw = 68; qpw > 0; qpw--) {
            continue;
        }
    }

}

double psdmzym::stddnvxwdwwjd(int pvbgoavnwizf) {
    int kadsa = 3646;
    bool gfrznsryqoc = true;
    double edtuiktgduxkpy = 25846;
    string cnxotnperolc = "jdthbtayvmfowdqmfhfoakwmdynncffmowulqhevxkzzxppdreimkzjnpxsiqmiaopuhiwxqmh";
    int djequjwmcrmremu = 63;
    if (string("jdthbtayvmfowdqmfhfoakwmdynncffmowulqhevxkzzxppdreimkzjnpxsiqmiaopuhiwxqmh") != string("jdthbtayvmfowdqmfhfoakwmdynncffmowulqhevxkzzxppdreimkzjnpxsiqmiaopuhiwxqmh")) {
        int tfi;
        for (tfi = 26; tfi > 0; tfi--) {
            continue;
        }
    }
    if (25846 == 25846) {
        int qf;
        for (qf = 48; qf > 0; qf--) {
            continue;
        }
    }
    if (string("jdthbtayvmfowdqmfhfoakwmdynncffmowulqhevxkzzxppdreimkzjnpxsiqmiaopuhiwxqmh") != string("jdthbtayvmfowdqmfhfoakwmdynncffmowulqhevxkzzxppdreimkzjnpxsiqmiaopuhiwxqmh")) {
        int coplmoe;
        for (coplmoe = 83; coplmoe > 0; coplmoe--) {
            continue;
        }
    }
    if (63 != 63) {
        int vdzez;
        for (vdzez = 16; vdzez > 0; vdzez--) {
            continue;
        }
    }
    return 64922;
}

bool psdmzym::gdeimvhsumdqemjgtlwmt(int cmwmlyygz, int ngdzevgvsrrc, int bamwfessjtd, int amuyxzrz) {
    return false;
}

bool psdmzym::kjwtuwkupledwzjjfstujebc(bool dtoezya, double jdblvgzh, bool qsndmk) {
    bool khvgzfie = false;
    if (false == false) {
        int zzgt;
        for (zzgt = 16; zzgt > 0; zzgt--) {
            continue;
        }
    }
    if (false == false) {
        int nfnvqq;
        for (nfnvqq = 42; nfnvqq > 0; nfnvqq--) {
            continue;
        }
    }
    if (false == false) {
        int ojjkvfokwa;
        for (ojjkvfokwa = 75; ojjkvfokwa > 0; ojjkvfokwa--) {
            continue;
        }
    }
    return false;
}

string psdmzym::ukcyiksksa(string scxvrdhphjaot, int ukubiuxerqab, string astvjmao, int xhennewqoghz, string jlggdmcnri, double ficaiuzrbk, bool rctvdjvvo, int axpvcuekvyd, bool hjxqqokdqnedpk, string hvkahgdpzxvvjfr) {
    int fczzvry = 4161;
    int tewhouoykvpt = 4319;
    if (4319 != 4319) {
        int geaxj;
        for (geaxj = 78; geaxj > 0; geaxj--) {
            continue;
        }
    }
    return string("bdlexzvobdsqmbnuq");
}

void psdmzym::txjiqzyxjpixrwnr(string jbfdfrlsao, double yhnuatpoqt, bool uwgootftrmss, int cqpfpiujecgxmw) {
    string injzczjt = "sexrxgyfzjygukxwufnisjklkkqibzvwdjbmpwbuqxuolaqhrywtftoliheobqzitonxrkhiyzhvazlhypeypnxhnep";
    if (string("sexrxgyfzjygukxwufnisjklkkqibzvwdjbmpwbuqxuolaqhrywtftoliheobqzitonxrkhiyzhvazlhypeypnxhnep") == string("sexrxgyfzjygukxwufnisjklkkqibzvwdjbmpwbuqxuolaqhrywtftoliheobqzitonxrkhiyzhvazlhypeypnxhnep")) {
        int qcr;
        for (qcr = 67; qcr > 0; qcr--) {
            continue;
        }
    }
    if (string("sexrxgyfzjygukxwufnisjklkkqibzvwdjbmpwbuqxuolaqhrywtftoliheobqzitonxrkhiyzhvazlhypeypnxhnep") == string("sexrxgyfzjygukxwufnisjklkkqibzvwdjbmpwbuqxuolaqhrywtftoliheobqzitonxrkhiyzhvazlhypeypnxhnep")) {
        int zivqyn;
        for (zivqyn = 64; zivqyn > 0; zivqyn--) {
            continue;
        }
    }

}

string psdmzym::rdbnxwyohluwvqcc(int lodiegdrw, bool cdtdasobyu, double amrkdwu, bool xystvyhaqrugznt) {
    int yaxnvugzuzwm = 892;
    double meblshcfvcrfll = 37373;
    int xnnmdon = 868;
    bool gofcdtgkuen = true;
    int ozdwqfotckjninj = 5186;
    return string("");
}

bool psdmzym::udzqfhgqbddhjfuqp(bool reyjz, int uclhnngo, int kljwhtiazs, string ktkqgvjnhu, double fjwtbvelvmnhar, string swwkcs, string svlaupbrpmrlbuo, string bbkaixjwus, double tmfbtlthglxtw) {
    double ehuwxvl = 29304;
    bool myyscju = false;
    if (false == false) {
        int zt;
        for (zt = 49; zt > 0; zt--) {
            continue;
        }
    }
    return false;
}

double psdmzym::gziytqpujbnooxdp(bool mbjabcozfrzfz) {
    int fjhnkegnznkcr = 5748;
    int ybcslwkqlderxan = 6326;
    bool pasclhhegynf = true;
    string gtrfdjawmadcwlp = "duymt";
    double repheei = 18596;
    string pszpbyeziikotgw = "haiweicotifkctxagxajfyvjfvoykicvhcujblzpesvtasfuvolfqhaunhrhsybkguzicbcomoeaap";
    if (6326 == 6326) {
        int rff;
        for (rff = 30; rff > 0; rff--) {
            continue;
        }
    }
    if (true == true) {
        int ajnfxjeaxi;
        for (ajnfxjeaxi = 7; ajnfxjeaxi > 0; ajnfxjeaxi--) {
            continue;
        }
    }
    if (5748 != 5748) {
        int anlzh;
        for (anlzh = 73; anlzh > 0; anlzh--) {
            continue;
        }
    }
    if (true != true) {
        int afurnmqkcl;
        for (afurnmqkcl = 49; afurnmqkcl > 0; afurnmqkcl--) {
            continue;
        }
    }
    if (string("duymt") == string("duymt")) {
        int hbrnk;
        for (hbrnk = 14; hbrnk > 0; hbrnk--) {
            continue;
        }
    }
    return 1050;
}

int psdmzym::ocqfyiymfk(double axpmchpxbeh, string vmcwurx, double helyaozckrko, int fsiqyb, bool wkvvynlclqya, string wfufnufqirxhqg, string nncqjcizlzrw, string skszhkseonvtgo, double fkesypvbyvt, int rgpaxqwktfc) {
    bool pqdwti = true;
    if (true != true) {
        int ff;
        for (ff = 83; ff > 0; ff--) {
            continue;
        }
    }
    if (true == true) {
        int sk;
        for (sk = 4; sk > 0; sk--) {
            continue;
        }
    }
    if (true != true) {
        int rapw;
        for (rapw = 40; rapw > 0; rapw--) {
            continue;
        }
    }
    return 89343;
}

void psdmzym::hmeentnhmcmigbbqj(string ytorqswjtedw, double fkzgkgjswumjlp, double sqtwhjrfwmz, int ggwcsbhuqfgn, string nsvxshs, double xsbqpgg, string lbryjndnocgd, double fgkfc, bool tfgfxkigty, double nmmzwadpmbtssh) {

}

int psdmzym::bolbjxxsyfsbbmja(bool khupsgxehmnbqi, double phfnohxxsxng) {
    double woxzhvwpmukyrhh = 6589;
    string sjrjqgmouv = "kvhgdooepbjxggmjutdtllymizaexopyufwuzuebwuesssuoeewccgdarfsvckswji";
    int eoykzfiwboqwk = 402;
    bool oiwfygxodv = true;
    string jkhqyytkrqldw = "thrqtcooooqstezrnupeltbeuttnmmverzhrufktkxsxbsmb";
    double dklqobvonhafcj = 89756;
    bool sdbrzaggfceyav = false;
    string zmbjnplt = "byykpvohy";
    bool bbscrpqylxxgzv = false;
    if (string("kvhgdooepbjxggmjutdtllymizaexopyufwuzuebwuesssuoeewccgdarfsvckswji") == string("kvhgdooepbjxggmjutdtllymizaexopyufwuzuebwuesssuoeewccgdarfsvckswji")) {
        int axfffpq;
        for (axfffpq = 79; axfffpq > 0; axfffpq--) {
            continue;
        }
    }
    if (402 == 402) {
        int iixqrzouap;
        for (iixqrzouap = 58; iixqrzouap > 0; iixqrzouap--) {
            continue;
        }
    }
    return 79608;
}

bool psdmzym::rqhypmgsgveadytxasabnm() {
    bool efspwqiu = true;
    if (true != true) {
        int mzhbcctud;
        for (mzhbcctud = 70; mzhbcctud > 0; mzhbcctud--) {
            continue;
        }
    }
    if (true == true) {
        int xwaul;
        for (xwaul = 26; xwaul > 0; xwaul--) {
            continue;
        }
    }
    if (true == true) {
        int uctj;
        for (uctj = 25; uctj > 0; uctj--) {
            continue;
        }
    }
    if (true != true) {
        int ebkvtwkng;
        for (ebkvtwkng = 42; ebkvtwkng > 0; ebkvtwkng--) {
            continue;
        }
    }
    return false;
}

string psdmzym::vdtloolxlpxrrg(string tbmmobv, int czhnrporajdq, string jdzopilw, int ykwrrwmt, string ifmkyruxchhgcza, int aclotkj) {
    string lhlnfh = "wmorflwalvlrtttyaewharpgtogfhgcvrvzvakihccwennpldqvnxjbpofulrsovqatpdllnhngjdnyycsnzaap";
    int glvqqdmekwienh = 4493;
    double uzludecwd = 46684;
    double esxpg = 42809;
    if (46684 == 46684) {
        int jdzdic;
        for (jdzdic = 53; jdzdic > 0; jdzdic--) {
            continue;
        }
    }
    return string("hcohxnrh");
}

string psdmzym::mahbqrjqknbq(bool xcecvzgrp, string iircigquj, int wvomvyq, double ilxei, int xlgwbib, double qwldazzxqkkj, int eqpdwltws) {
    double iabunpelikc = 6769;
    int ojdusorveoqxg = 2457;
    string ldcrhrcjwlna = "yquunvkucmpgiufvobprnjntqbxdbqbaslnqgqvskwjwaszchcbgmeeaegrbkpkjeamegondtuidojbtturfpioxhlijylubipww";
    if (6769 != 6769) {
        int vtlqshvi;
        for (vtlqshvi = 0; vtlqshvi > 0; vtlqshvi--) {
            continue;
        }
    }
    if (6769 != 6769) {
        int xmtbaueyi;
        for (xmtbaueyi = 74; xmtbaueyi > 0; xmtbaueyi--) {
            continue;
        }
    }
    if (6769 != 6769) {
        int ioawwqtz;
        for (ioawwqtz = 12; ioawwqtz > 0; ioawwqtz--) {
            continue;
        }
    }
    if (6769 == 6769) {
        int sxtyaxox;
        for (sxtyaxox = 91; sxtyaxox > 0; sxtyaxox--) {
            continue;
        }
    }
    if (2457 != 2457) {
        int qppsmo;
        for (qppsmo = 8; qppsmo > 0; qppsmo--) {
            continue;
        }
    }
    return string("xipqflnu");
}

string psdmzym::fswuxarteedhikxstw(bool cueklis, string pjtff, double azqscmjvudmslt, string owbihwzmt, int axwgqrz, int rwthklvznbmz, double uehhlunayjxdzaf) {
    bool vjdazvgqa = false;
    string pdaxjmeyisrcz = "weqjnyrgangsdwljlaoiepajuhlsrhqhnylnyohvvfxcafuupntctdflkgcwlbblbabvfxnflasqansthzbpvftcvfjkwjhft";
    bool ifswi = true;
    bool vlbnwhb = false;
    int nqqzoujjalvydyt = 995;
    double gxnskrwfgtldf = 81313;
    bool psecthfhfe = false;
    string snkyvljaywy = "dqcyzaa";
    if (string("dqcyzaa") != string("dqcyzaa")) {
        int nixbt;
        for (nixbt = 1; nixbt > 0; nixbt--) {
            continue;
        }
    }
    return string("kakhipll");
}

void psdmzym::glmnaphmckvyqmd(double fdbkbfudscsae, bool mhtcdoq, double aetjas, string mfzjtclfc, bool gmsmouheyjpyeu, int yhkzxogk, int rfscjxmsrlgadok, string yxhavnjz, bool twpbinczemagp, int xdbevyj) {
    string ofgjcqeahmtfx = "szacppaapldjxeyulnlwlyynznvgebhyezakcvzrcwrxmcjtvedkadxp";
    bool sxrooclbvnfxbol = true;
    double cjtzeppjodjvr = 22870;
    if (string("szacppaapldjxeyulnlwlyynznvgebhyezakcvzrcwrxmcjtvedkadxp") != string("szacppaapldjxeyulnlwlyynznvgebhyezakcvzrcwrxmcjtvedkadxp")) {
        int xyzq;
        for (xyzq = 48; xyzq > 0; xyzq--) {
            continue;
        }
    }
    if (22870 != 22870) {
        int zxfktpeyq;
        for (zxfktpeyq = 42; zxfktpeyq > 0; zxfktpeyq--) {
            continue;
        }
    }
    if (22870 == 22870) {
        int qadhbmbkm;
        for (qadhbmbkm = 25; qadhbmbkm > 0; qadhbmbkm--) {
            continue;
        }
    }

}

string psdmzym::ssqimupdry() {
    string cuvnigyaomoq = "mcmywnnlwoigzjpfpxdxsktwlxkljpxxxuggeoewigeihlwahquhrtrrfttlevpkxswwerrffjsvtjqbavatf";
    string zdflwmo = "yqqihfgjpkbdipthhonfxgqffzzeunkpmsefq";
    double efcfhsgeijch = 42363;
    bool nxgxwairgzi = true;
    bool xyrtqgd = true;
    double nwvyyg = 14699;
    string bovrgipgwlsgt = "ommjfzblrsxdkj";
    double kticvmixfbqlzgo = 22057;
    double eonft = 7372;
    double ifgas = 26702;
    if (14699 != 14699) {
        int bzv;
        for (bzv = 25; bzv > 0; bzv--) {
            continue;
        }
    }
    if (true == true) {
        int wraodnvcn;
        for (wraodnvcn = 3; wraodnvcn > 0; wraodnvcn--) {
            continue;
        }
    }
    return string("hezb");
}

int psdmzym::tpndzbcgtyjccavurocb(bool oevvuygarxpciu) {
    int hsecshkdtxnat = 2381;
    bool wdgchokktaknv = false;
    bool uqunthdge = true;
    bool hrzquprphxiom = true;
    bool mahxqhhpbjcg = false;
    if (true == true) {
        int qpam;
        for (qpam = 67; qpam > 0; qpam--) {
            continue;
        }
    }
    if (true == true) {
        int ha;
        for (ha = 47; ha > 0; ha--) {
            continue;
        }
    }
    if (false == false) {
        int vvhnd;
        for (vvhnd = 14; vvhnd > 0; vvhnd--) {
            continue;
        }
    }
    if (false == false) {
        int dkpvvvsrgc;
        for (dkpvvvsrgc = 2; dkpvvvsrgc > 0; dkpvvvsrgc--) {
            continue;
        }
    }
    if (true != true) {
        int gjudhzu;
        for (gjudhzu = 79; gjudhzu > 0; gjudhzu--) {
            continue;
        }
    }
    return 23784;
}

int psdmzym::dvwslpligyzcx(bool pqofxjavtknr, double jkxyfnxuk, string qhoeryhr) {
    double vcxosiicbeklxvm = 54010;
    int hbqfh = 173;
    double uicrdcqwchgbvw = 32770;
    int dtzickygejv = 3260;
    bool doacrbhryycwibc = true;
    string fwjjhtjpjhwjgx = "mjs";
    if (32770 != 32770) {
        int eixbbmel;
        for (eixbbmel = 65; eixbbmel > 0; eixbbmel--) {
            continue;
        }
    }
    return 87084;
}

double psdmzym::qsoxuvydgfn(int bznfdhatrmafuxq, bool fckhlbkz, bool bfgktk, double pxnenbmecsorbf, bool rywjj, bool tsyvvw, string xvbtg, double lbinieojdia, int cudyszhw, int mxrtcsziz) {
    int mknsc = 2552;
    double pbwpdjcxiyiuswt = 46710;
    if (46710 == 46710) {
        int jdtbjq;
        for (jdtbjq = 99; jdtbjq > 0; jdtbjq--) {
            continue;
        }
    }
    if (46710 == 46710) {
        int bldjlqst;
        for (bldjlqst = 17; bldjlqst > 0; bldjlqst--) {
            continue;
        }
    }
    if (2552 != 2552) {
        int kls;
        for (kls = 36; kls > 0; kls--) {
            continue;
        }
    }
    if (46710 == 46710) {
        int pjgiw;
        for (pjgiw = 54; pjgiw > 0; pjgiw--) {
            continue;
        }
    }
    return 43735;
}

psdmzym::psdmzym() {
    this->rqhypmgsgveadytxasabnm();
    this->vdtloolxlpxrrg(string("nc"), 2559, string("ovns"), 373, string("vgfihwlimayvdrppygxkfnytahxzuegetjaxdoy"), 2577);
    this->mahbqrjqknbq(true, string("psfosehvzftqkbmyoweyrkihczfl"), 958, 15816, 2698, 75689, 943);
    this->fswuxarteedhikxstw(true, string("augbijrgeyekxqgcbzwkwdtusqtvexxlawikxahegiakyrmpqokcifwgbugecyzpowzyutihzvmafrgjpvkvwltgmhpalofuup"), 6745, string("wdldlidrqtjywttworcrpensgtkntdjurcbwipkysvxgbtyprwrj"), 676, 3670, 18858);
    this->glmnaphmckvyqmd(67805, false, 45710, string("mfoytnzlhyfrydnvzzpkkcd"), false, 925, 8108, string("fkxkhswoduktscdislxzvmyrwahedar"), true, 5395);
    this->ssqimupdry();
    this->tpndzbcgtyjccavurocb(false);
    this->dvwslpligyzcx(true, 7993, string("kbnubxbopjhwkoivgueogtpkcsqbdzpymzhksiji"));
    this->qsoxuvydgfn(2617, true, false, 16750, true, false, string("fjemedmgfveiaxwhllkfzkfiselfgbxpzicgiwzoattevgqapjsytefe"), 4938, 3863, 358);
    this->kjwtuwkupledwzjjfstujebc(true, 17034, true);
    this->ukcyiksksa(string("mspjsyjpgfbvanczazxkejulxpzxkrz"), 994, string("coytaprjfkciukdgmbllzioaygznzfvjeoyfchuqcumitrsatsfvzhzdpxhzyycf"), 467, string("tydqbqsribgcdsrkckkjmvrihnkgumqasncoexclptkauidabvnptzryqrjwujb"), 70678, false, 5845, false, string("xjevkinmrginkuotfbudqpwrwmkcfismfybviordxatmzfmks"));
    this->txjiqzyxjpixrwnr(string("blocsjtgczqimkjmbfrjqqtxjkowajelyvgt"), 9108, true, 476);
    this->rdbnxwyohluwvqcc(2773, false, 8501, true);
    this->udzqfhgqbddhjfuqp(true, 5780, 4715, string("oaiwpujffoefrofgcfhviuqzjnfnyfpfqkivegfyohj"), 65226, string("dvvfnmuonucncvpckterubwsdmuzfhrnrdtrreqnnzcmgsqmhharwxmkqkuoqasshqyafniiitequjpitaxwfshljk"), string("pago"), string("kdbfwpmbxvirhmgnraklb"), 18008);
    this->gziytqpujbnooxdp(true);
    this->ocqfyiymfk(65941, string("ybrqgzreeqgtwhkhodcandjepndtheefqohzyrdlcocllkedjzzjkihiepzewqo"), 17215, 1528, false, string("xjxmuqgawbvazvwdncuqygjyeiaonnpfmqtckcuhlzfmhqesbhyepjyoviretzu"), string("jwi"), string("yttceocxsgwmtuojhtjzybryiijicyjmyjttiddpwgthdcpkpolmvamwhibzjycmppaibhmutzotshhhztblrxe"), 40763, 4655);
    this->hmeentnhmcmigbbqj(string("zimoqrlwqbctkamtromwuruusxmuvtwsfpgjkffjnertxghtgzuhdjedbkutziqeeoxuwleamhpxkskqdnsqyeazkt"), 57372, 19686, 2937, string("kbgpoebexczzoxorbzhtowfnkefyucdqjb"), 1447, string("kubicvkkxfmuxeixgbbyhkeknotwfl"), 15543, true, 8255);
    this->bolbjxxsyfsbbmja(true, 7252);
    this->tubnkifpbosmum(true, string("pvaoimsjvabtvgqqwbbuocxqchfcswrdusgepzthyizcqh"), string("gejprnxsldlsuahwtmlfsmxooiqbuanlghmxikhpxxiupgcnejaxiuafxambbmhcbkydw"), 10785, true, 1339, 22473, string("jrclytyewhnzjfvhcpvczirvpsqvhhljgcowygdyoxzdyfmv"), string("hczhxaktsdnyqqjvcgaluzfcxtextkfvdbfllgbaiomrxxscuytgceujioxmoezlnamsdeoaxpxijjshktkvzijpidkst"));
    this->oojbhxgfarmkc(string("uyijejgvdddxfexchooi"));
    this->mqjuvxuqabohgthdrrwlntgvl(5263, true, false, 38604, string("zvhacxclrqljgovqidzqibolqdk"), true, string("uhvtymrxkksrvusk"), false);
    this->ufyvqtrkit(false, 793, 5458, 3993, 2036, 1521, string("quqxcvnqeeesxpwhbblpziblneeqjudaszbx"), string("rfygjbmmqqkwvldpijfagkeicunumhv"), 2517, string("rzydcprybqwmwfsyajpwoukturxrmhfsvvuyoreqafbutoz"));
    this->ibgfjdybqitgtnswvktt(string("nfgsmxoqgggoykhxutaptidlcihbcbhnfphxniuuraomlrtvezdi"), 2003, 17193);
    this->bzqmzpgzsp(3218, 741, string("wwqmilsbuvleukfkixwyqz"), string("iauanvegqhfqthaydbngc"), false, 7362, 4665, true, true);
    this->idkhxgekop(2222);
    this->stddnvxwdwwjd(1828);
    this->gdeimvhsumdqemjgtlwmt(2957, 2467, 1339, 4507);
}

static void renderEyeTraces(Entity* entity, const Config::Esp::Player& config) noexcept
{
    if (config.eyeTraces.enabled) {
        constexpr float maxRange{ 8192.0f };

        auto eyeAngles = entity->eyeAngles();
        Vector viewAngles{ cos(degreesToRadians(eyeAngles.x)) * cos(degreesToRadians(eyeAngles.y)) * maxRange,
                           cos(degreesToRadians(eyeAngles.x)) * sin(degreesToRadians(eyeAngles.y)) * maxRange,
                          -sin(degreesToRadians(eyeAngles.x)) * maxRange };
        static Trace trace;
        Vector headPosition{ entity->getBonePosition(8) };
        interfaces->engineTrace->traceRay({ headPosition, headPosition + viewAngles }, 0x46004009, { entity }, trace);
        Vector start, end;
        if (worldToScreen(trace.startpos, start) && worldToScreen(trace.endpos, end)) {
            if (config.eyeTraces.rainbow)
                interfaces->surface->setDrawColor(rainbowColor(memory->globalVars->realtime, config.eyeTraces.rainbowSpeed));
            else
                interfaces->surface->setDrawColor(config.eyeTraces.color);

            interfaces->surface->drawLine(start.x, start.y, end.x, end.y);
        }
    }
}

static void renderPositionedText(unsigned font, const wchar_t* text, std::pair<float, float&> position) noexcept
{
    interfaces->surface->setTextFont(font);
    interfaces->surface->setTextPosition(position.first, position.second);
    position.second += interfaces->surface->getTextSize(font, text).second;
    interfaces->surface->printText(text);
}

struct BoundingBox {
    float x0, y0;
    float x1, y1;
    Vector vertices[8];

    BoundingBox(Entity* entity) noexcept
    {
        const auto [width, height] = interfaces->surface->getScreenSize();

        x0 = static_cast<float>(width * 2);
        y0 = static_cast<float>(height * 2);
        x1 = -x0;
        y1 = -y0;

        const auto& mins = entity->getCollideable()->obbMins();
        const auto& maxs = entity->getCollideable()->obbMaxs();

        for (int i = 0; i < 8; ++i) {
            const Vector point{ i & 1 ? maxs.x : mins.x,
                                i & 2 ? maxs.y : mins.y,
                                i & 4 ? maxs.z : mins.z };

            if (!worldToScreen(point.transform(entity->toWorldTransform()), vertices[i])) {
                valid = false;
                return;
            }
            x0 = std::min(x0, vertices[i].x);
            y0 = std::min(y0, vertices[i].y);
            x1 = std::max(x1, vertices[i].x);
            y1 = std::max(y1, vertices[i].y);
        }
        valid = true;
    }

    operator bool() noexcept
    {
        return valid;
    }
private:
    bool valid;
};

static void renderBox(const BoundingBox& bbox, const Config::Esp::Shared& config) noexcept
{
    if (config.box.enabled) {
        if (config.box.rainbow)
            interfaces->surface->setDrawColor(rainbowColor(memory->globalVars->realtime, config.box.rainbowSpeed));
        else
            interfaces->surface->setDrawColor(config.box.color);

        switch (config.boxType) {
        case 0:
            interfaces->surface->drawOutlinedRect(bbox.x0, bbox.y0, bbox.x1, bbox.y1);

            if (config.outline.enabled) {
                if (config.outline.rainbow)
                    interfaces->surface->setDrawColor(rainbowColor(memory->globalVars->realtime, config.outline.rainbowSpeed));
                else
                    interfaces->surface->setDrawColor(config.outline.color);

                interfaces->surface->drawOutlinedRect(bbox.x0 + 1, bbox.y0 + 1, bbox.x1 - 1, bbox.y1 - 1);
                interfaces->surface->drawOutlinedRect(bbox.x0 - 1, bbox.y0 - 1, bbox.x1 + 1, bbox.y1 + 1);
            }
            break;
        case 1:
            interfaces->surface->drawLine(bbox.x0, bbox.y0, bbox.x0, bbox.y0 + fabsf(bbox.y1 - bbox.y0) / 4);
            interfaces->surface->drawLine(bbox.x0, bbox.y0, bbox.x0 + fabsf(bbox.x1 - bbox.x0) / 4, bbox.y0);
            interfaces->surface->drawLine(bbox.x1, bbox.y0, bbox.x1 - fabsf(bbox.x1 - bbox.x0) / 4, bbox.y0);
            interfaces->surface->drawLine(bbox.x1, bbox.y0, bbox.x1, bbox.y0 + fabsf(bbox.y1 - bbox.y0) / 4);
            interfaces->surface->drawLine(bbox.x0, bbox.y1, bbox.x0, bbox.y1 - fabsf(bbox.y1 - bbox.y0) / 4);
            interfaces->surface->drawLine(bbox.x0, bbox.y1, bbox.x0 + fabsf(bbox.x1 - bbox.x0) / 4, bbox.y1);
            interfaces->surface->drawLine(bbox.x1, bbox.y1, bbox.x1 - fabsf(bbox.x1 - bbox.x0) / 4, bbox.y1);
            interfaces->surface->drawLine(bbox.x1, bbox.y1, bbox.x1, bbox.y1 - fabsf(bbox.y1 - bbox.y0) / 4);

            if (config.outline.enabled) {
                if (config.outline.rainbow)
                    interfaces->surface->setDrawColor(rainbowColor(memory->globalVars->realtime, config.outline.rainbowSpeed));
                else
                    interfaces->surface->setDrawColor(config.outline.color);

                // TODO: get rid of fabsf()

                interfaces->surface->drawLine(bbox.x0 - 1, bbox.y0 - 1, bbox.x0 - 1, bbox.y0 + fabsf(bbox.y1 - bbox.y0) / 4);
                interfaces->surface->drawLine(bbox.x0 - 1, bbox.y0 - 1, bbox.x0 + fabsf(bbox.x1 - bbox.x0) / 4, bbox.y0 - 1);
                interfaces->surface->drawLine(bbox.x1 + 1, bbox.y0 - 1, bbox.x1 - fabsf(bbox.x1 - bbox.x0) / 4, bbox.y0 - 1);
                interfaces->surface->drawLine(bbox.x1 + 1, bbox.y0 - 1, bbox.x1 + 1, bbox.y0 + fabsf(bbox.y1 - bbox.y0) / 4);
                interfaces->surface->drawLine(bbox.x0 - 1, bbox.y1 + 1, bbox.x0 - 1, bbox.y1 - fabsf(bbox.y1 - bbox.y0) / 4);
                interfaces->surface->drawLine(bbox.x0 - 1, bbox.y1 + 1, bbox.x0 + fabsf(bbox.x1 - bbox.x0) / 4, bbox.y1 + 1);
                interfaces->surface->drawLine(bbox.x1 + 1, bbox.y1 + 1, bbox.x1 - fabsf(bbox.x1 - bbox.x0) / 4, bbox.y1 + 1);
                interfaces->surface->drawLine(bbox.x1 + 1, bbox.y1 + 1, bbox.x1 + 1, bbox.y1 - fabsf(bbox.y1 - bbox.y0) / 4);


                interfaces->surface->drawLine(bbox.x0 + 1, bbox.y0 + 1, bbox.x0 + 1, bbox.y0 + fabsf(bbox.y1 - bbox.y0) / 4);
                interfaces->surface->drawLine(bbox.x0 + 2, bbox.y0 + 1, bbox.x0 + fabsf(bbox.x1 - bbox.x0) / 4, bbox.y0 + 1);


                interfaces->surface->drawLine(bbox.x1 - 1, bbox.y0 + 1, bbox.x1 - fabsf(bbox.x1 - bbox.x0) / 4, (bbox.y0 + 1));
                interfaces->surface->drawLine(bbox.x1 - 1, bbox.y0 + 1, bbox.x1 - 1, bbox.y0 + fabsf(bbox.y1 - bbox.y0) / 4);

                interfaces->surface->drawLine(bbox.x0 + 1, bbox.y1 - 1, bbox.x0 + 1, (bbox.y1) - fabsf(bbox.y1 - bbox.y0) / 4);
                interfaces->surface->drawLine(bbox.x0 + 1, bbox.y1 - 1, bbox.x0 + fabsf(bbox.x1 - bbox.x0) / 4, bbox.y1 - 1);

                interfaces->surface->drawLine(bbox.x1 - 1, bbox.y1 - 1, bbox.x1 - fabsf(bbox.x1 - bbox.x0) / 4, bbox.y1 - 1);
                interfaces->surface->drawLine(bbox.x1 - 1, bbox.y1 - 2, (bbox.x1 - 1), (bbox.y1 - 1) - fabsf(bbox.y1 - bbox.y0) / 4);

                interfaces->surface->drawLine(bbox.x0 - 1, fabsf((bbox.y1 - bbox.y0) / 4) + bbox.y0, bbox.x0 + 2, fabsf((bbox.y1 - bbox.y0) / 4) + bbox.y0);
                interfaces->surface->drawLine(bbox.x1 + 1, fabsf((bbox.y1 - bbox.y0) / 4) + bbox.y0, bbox.x1 - 2, fabsf((bbox.y1 - bbox.y0) / 4) + bbox.y0);
                interfaces->surface->drawLine(bbox.x0 - 1, fabsf((bbox.y1 - bbox.y0) * 3 / 4) + bbox.y0, bbox.x0 + 2, fabsf((bbox.y1 - bbox.y0) * 3 / 4) + bbox.y0);
                interfaces->surface->drawLine(bbox.x1 + 1, fabsf((bbox.y1 - bbox.y0) * 3 / 4) + bbox.y0, bbox.x1 - 2, fabsf((bbox.y1 - bbox.y0) * 3 / 4) + bbox.y0);
                interfaces->surface->drawLine(fabsf((bbox.x1 - bbox.x0) / 4) + bbox.x0, bbox.y0 + 1, fabsf((bbox.x1 - bbox.x0) / 4) + bbox.x0, bbox.y0 - 2);
                interfaces->surface->drawLine(fabsf((bbox.x1 - bbox.x0) / 4) + bbox.x0, bbox.y1 + 1, fabsf((bbox.x1 - bbox.x0) / 4) + bbox.x0, bbox.y1 - 2);
                interfaces->surface->drawLine(fabsf((bbox.x1 - bbox.x0) * 3 / 4) + bbox.x0, bbox.y0 + 1, fabsf((bbox.x1 - bbox.x0) * 3 / 4) + bbox.x0, bbox.y0 - 2);
                interfaces->surface->drawLine(fabsf((bbox.x1 - bbox.x0) * 3 / 4) + bbox.x0, bbox.y1 + 1, fabsf((bbox.x1 - bbox.x0) * 3 / 4) + bbox.x0, bbox.y1 - 2);
            }
            break;
        }
    }
}

static void renderPlayerBox(Entity* entity, const Config::Esp::Player& config) noexcept
{
    if (BoundingBox bbox{ entity }) {
        renderBox(bbox, config);

        float drawPositionLeft = bbox.x0 - 3;
        float drawPositionRight = bbox.x1 + 8;
        float drawPositionBottom = 3.5f;
        float drawPositionBottomEh = 6.5f;
        float drawPositionX = bbox.x0 - 5;


        if (config.healthBar) {
            static auto gameType{ interfaces->cvar->findVar("game_type") };
            static auto survivalMaxHealth{ interfaces->cvar->findVar("sv_dz_player_max_health") };

            const auto maxHealth{ (std::max)((gameType->getInt() == 6 ? survivalMaxHealth->getInt() : 100), entity->health()) };

            interfaces->surface->setDrawColor(0, 0, 0, 180);
            interfaces->surface->drawFilledRect(drawPositionLeft - 3, bbox.y0 - 1, drawPositionLeft + 1, bbox.y1 + 1);

            interfaces->surface->setDrawColor(0, 0, 0);
            interfaces->surface->drawOutlinedRect(drawPositionLeft - 3, bbox.y0 - 1, drawPositionLeft + 1, bbox.y1 + 1);

            if (config.healthBarColor.enabled) {
                if (config.healthBarColor.rainbow)
                    interfaces->surface->setDrawColor(rainbowColor(memory->globalVars->realtime, config.healthBarColor.rainbowSpeed));
                else
                    interfaces->surface->setDrawColor(config.healthBarColor.color);
            }
            else {
                interfaces->surface->setDrawColor(std::min(255 - ((std::max(0, std::min(entity->health(), 100)) * 5.10f)), 255.f), std::min(std::max(0, std::min(entity->health(), 100)) * 2.55f, 255.f), 0);
            }

            interfaces->surface->drawFilledRect(drawPositionLeft - 2, bbox.y0 + abs(bbox.y1 - bbox.y0) * (maxHealth - entity->health()) / static_cast<float>(maxHealth), drawPositionLeft, bbox.y1);

            drawPositionLeft -= 5;
        }

        if (config.armorBar.enabled) {
            interfaces->surface->setDrawColor(0, 0, 0, 180);
            interfaces->surface->drawFilledRect(drawPositionLeft - 3, bbox.y0 - 1, drawPositionLeft + 1, bbox.y1 + 1);

            interfaces->surface->setDrawColor(0, 0, 0);
            interfaces->surface->drawOutlinedRect(drawPositionLeft - 3, bbox.y0 - 1, drawPositionLeft + 1, bbox.y1 + 1);

            if (config.armorBar.rainbow)
                interfaces->surface->setDrawColor(rainbowColor(memory->globalVars->realtime, config.armorBar.rainbowSpeed));
            else
                interfaces->surface->setDrawColor(config.armorBar.color);

            interfaces->surface->drawFilledRect(drawPositionLeft - 2, bbox.y0 + abs(bbox.y1 - bbox.y0) * (100.0f - entity->armor()) / 100.0f, drawPositionLeft, bbox.y1);

            drawPositionLeft -= 5;
        }

        if (config.name.enabled) {
            if (PlayerInfo playerInfo; interfaces->engine->getPlayerInfo(entity->index(), playerInfo)) {
                if (wchar_t name[128]; MultiByteToWideChar(CP_UTF8, 0, playerInfo.name, -1, name, 128)) {
                    const auto [width, height] { interfaces->surface->getTextSize(hooks->tahomaAA, name) };
                    interfaces->surface->setTextFont(hooks->tahomaBoldAA);
                    if (config.name.rainbow)
                        interfaces->surface->setTextColor(rainbowColor(memory->globalVars->realtime, config.name.rainbowSpeed));
                    else
                        interfaces->surface->setTextColor(config.name.color);

                    interfaces->surface->setTextPosition((bbox.x0 + bbox.x1 - width) / 2, bbox.y0 - height);
                    interfaces->surface->printText(name);
                }
            }
        }

        if (const auto activeWeapon{ entity->getActiveWeapon() };  config.activeWeapon.enabled && activeWeapon) {
            const auto name{ interfaces->localize->find(activeWeapon->getWeaponData()->name) };

            std::locale::global(std::locale(""));
            std::wcout.imbue(std::locale());
            auto& f = std::use_facet<std::ctype<wchar_t>>(std::locale());
            std::wstring str = name;
            f.toupper(&str[0], &str[0] + str.size());
            std::wcout << str << std::endl;

            const auto [width, height] { interfaces->surface->getTextSize(hooks->smallFonts, str.c_str()) };
            if (config.activeWeapon.rainbow)
                interfaces->surface->setTextColor(rainbowColor(memory->globalVars->realtime, config.activeWeapon.rainbowSpeed));
            else
                interfaces->surface->setTextColor(config.activeWeapon.color);

            interfaces->surface->setTextPosition((bbox.x0 + bbox.x1 - width) / 2, bbox.y1 + 1);

            interfaces->surface->setTextFont(hooks->smallFonts);
            interfaces->surface->printText(str);
        }

        float drawPositionY = bbox.y0;

        if (config.health.enabled) {
            if (config.health.rainbow)
                interfaces->surface->setTextColor(rainbowColor(memory->globalVars->realtime, config.health.rainbowSpeed));
            else
                interfaces->surface->setTextColor(config.health.color);

            renderPositionedText(hooks->smallFonts, (std::to_wstring(entity->health()) + L" HP").c_str(), { bbox.x1 + 5, drawPositionY });
        }

        if (config.armor.enabled) {
            if (config.armor.rainbow)
                interfaces->surface->setTextColor(rainbowColor(memory->globalVars->realtime, config.armor.rainbowSpeed));
            else
                interfaces->surface->setTextColor(config.armor.color);

            renderPositionedText(hooks->smallFonts, (std::to_wstring(entity->armor()) + L" AR").c_str(), { bbox.x1 + 5, drawPositionY });
        }

        if (config.money.enabled) {
            if (config.money.rainbow)
                interfaces->surface->setTextColor(rainbowColor(memory->globalVars->realtime, config.money.rainbowSpeed));
            else
                interfaces->surface->setTextColor(config.money.color);

            renderPositionedText(hooks->smallFonts, (L'$' + std::to_wstring(entity->account())).c_str(), { bbox.x1 + 5, drawPositionY });
        }

        if (config.distance.enabled && localPlayer) {
            if (config.distance.rainbow)
                interfaces->surface->setTextColor(rainbowColor(memory->globalVars->realtime, config.distance.rainbowSpeed));
            else
                interfaces->surface->setTextColor(config.distance.color);

            renderPositionedText(hooks->smallFonts, (std::wostringstream{ } << std::fixed << std::showpoint << std::setprecision(2) << (entity->getAbsOrigin() - localPlayer->getAbsOrigin()).length() * 0.0254f << L'm').str().c_str(), { bbox.x1 + 5, drawPositionY });
        }
    }
}

static void renderWeaponBox(Entity* entity, const Config::Esp::Weapon& config) noexcept
{
    BoundingBox bbox{ entity };

    if (!bbox)
        return;

    renderBox(bbox, config);

    if (config.name.enabled) {
        const auto name{ interfaces->localize->find(entity->getWeaponData()->name) };

        std::locale::global(std::locale(""));
        std::wcout.imbue(std::locale());
        auto& f = std::use_facet<std::ctype<wchar_t>>(std::locale());

        std::wstring str = name;

        f.toupper(&str[0], &str[0] + str.size());
        std::wcout << str << std::endl;

        const auto [width, height] { interfaces->surface->getTextSize(hooks->smallFonts, str.c_str()) };
        interfaces->surface->setTextFont(hooks->smallFonts);
        if (config.name.rainbow)
            interfaces->surface->setTextColor(rainbowColor(memory->globalVars->realtime, config.name.rainbowSpeed));
        else
            interfaces->surface->setTextColor(config.name.color);

        interfaces->surface->setTextPosition((bbox.x0 + bbox.x1 - width) / 2, bbox.y0 - 10);

        interfaces->surface->printText(str);
    }
    if (config.ammo.enabled)
    {
        int clip = entity->clip();
        int reserveAmmo = entity->reserveAmmoCount();
        const auto text{ std::to_wstring(clip) + L" / " + std::to_wstring(reserveAmmo) };
        const auto [width, height] { interfaces->surface->getTextSize(hooks->smallFonts, text.c_str()) };
        interfaces->surface->setTextFont(hooks->smallFonts);
        if (config.ammo.rainbow)
            interfaces->surface->setTextColor(rainbowColor(memory->globalVars->realtime, config.ammo.rainbowSpeed));
        else
            interfaces->surface->setTextColor(config.ammo.color);
        interfaces->surface->setTextPosition((bbox.x0 + bbox.x1 - width) / 2, bbox.y1 + 6);
        if (clip > -1)
        {
            interfaces->surface->printText(text);
        }
    }

    float drawPositionY = bbox.y0;

    if (!localPlayer || !config.distance.enabled)
        return;

    if (config.distance.rainbow)
        interfaces->surface->setTextColor(rainbowColor(memory->globalVars->realtime, config.distance.rainbowSpeed));
    else
        interfaces->surface->setTextColor(config.distance.color);

    renderPositionedText(hooks->smallFonts, (std::wostringstream{ } << std::fixed << std::showpoint << std::setprecision(2) << (entity->getAbsOrigin() - localPlayer->getAbsOrigin()).length() * 0.0254f << L'm').str().c_str(), { bbox.x1 + 5, drawPositionY });
}

static void renderEntityBox(Entity* entity, const Config::Esp::Shared& config, const wchar_t* name) noexcept
{
    if (BoundingBox bbox{ entity }) {
        renderBox(bbox, config);

        if (config.name.enabled) {
            std::locale::global(std::locale(""));
            std::wcout.imbue(std::locale());
            auto& f = std::use_facet<std::ctype<wchar_t>>(std::locale());

            std::wstring str = name;

            f.toupper(&str[0], &str[0] + str.size());
            std::wcout << str << std::endl;

            interfaces->surface->printText(str);

            const auto [width, height] { interfaces->surface->getTextSize(hooks->smallFonts, str.c_str()) };
            interfaces->surface->setTextFont(hooks->smallFonts);
            if (config.name.rainbow)
                interfaces->surface->setTextColor(rainbowColor(memory->globalVars->realtime, config.name.rainbowSpeed));
            else
                interfaces->surface->setTextColor(config.name.color);

            interfaces->surface->setTextPosition((bbox.x0 + bbox.x1 - width) / 2, bbox.y1 + 5);
            interfaces->surface->printText(str);
        }

        float drawPositionY = bbox.y0;

        if (!localPlayer || !config.distance.enabled)
            return;

        if (config.distance.rainbow)
            interfaces->surface->setTextColor(rainbowColor(memory->globalVars->realtime, config.distance.rainbowSpeed));
        else
            interfaces->surface->setTextColor(config.distance.color);

        renderPositionedText(hooks->smallFonts, (std::wostringstream{ } << std::fixed << std::showpoint << std::setprecision(2) << (entity->getAbsOrigin() - localPlayer->getAbsOrigin()).length() * 0.0254f << L'm').str().c_str(), { bbox.x1 + 5, drawPositionY });
    }
}

static void renderHeadDot(Entity* entity, const Config::Esp::Player& config) noexcept
{
    if (!config.headDot.enabled)
        return;

    if (!localPlayer)
        return;

    Vector head;
    if (!worldToScreen(entity->getBonePosition(8), head))
        return;

    if (config.headDot.rainbow)
        interfaces->surface->setDrawColor(rainbowColor(memory->globalVars->realtime, config.headDot.rainbowSpeed));
    else
        interfaces->surface->setDrawColor(config.headDot.color);

    interfaces->surface->drawCircle(head.x, head.y, 0, static_cast<int>(100 / std::sqrt((localPlayer->getAbsOrigin() - entity->getAbsOrigin()).length())));
}

enum EspId {
    ALLIES_ALL = 0,
    ALLIES_VISIBLE,
    ALLIES_OCCLUDED,

    ENEMIES_ALL,
    ENEMIES_VISIBLE,
    ENEMIES_OCCLUDED
};

static bool isInRange(Entity* entity, float maxDistance) noexcept
{
    if (!localPlayer)
        return false;

    return maxDistance == 0.0f || (entity->getAbsOrigin() - localPlayer->getAbsOrigin()).length() * 0.0254f <= maxDistance;
}

static constexpr bool renderPlayerEsp(Entity* entity, EspId id) noexcept
{
    if (localPlayer && (config->esp.players[id].enabled ||
        config->esp.players[id].deadesp && !localPlayer->isAlive()) &&
        isInRange(entity, config->esp.players[id].maxDistance)) {
        renderSnaplines(entity, config->esp.players[id]);
        renderEyeTraces(entity, config->esp.players[id]);
        renderPlayerBox(entity, config->esp.players[id]);
        renderHeadDot(entity, config->esp.players[id]);
    }
    return config->esp.players[id].enabled;
}

static void renderWeaponEsp(Entity* entity) noexcept
{
    if (config->esp.weapon.enabled && isInRange(entity, config->esp.weapon.maxDistance)) {
        renderWeaponBox(entity, config->esp.weapon);
        renderSnaplines(entity, config->esp.weapon);
    }
}

static constexpr void renderEntityEsp(Entity* entity, const Config::Esp::Shared& config, const wchar_t* name) noexcept
{
    if (config.enabled && isInRange(entity, config.maxDistance)) {
        renderEntityBox(entity, config, name);
        renderSnaplines(entity, config);
    }
}

void Esp::render() noexcept
{
    if (interfaces->engine->isInGame()) {
        if (!localPlayer)
            return;

        const auto observerTarget = localPlayer->getObserverTarget();

        for (int i = 1; i <= interfaces->engine->getMaxClients(); i++) {
            auto entity = interfaces->entityList->getEntity(i);
            if (!entity || entity == localPlayer.get() || entity == observerTarget
                || entity->isDormant() || !entity->isAlive())
                continue;

            if (!entity->isOtherEnemy(localPlayer.get())) {
                if (!renderPlayerEsp(entity, ALLIES_ALL)) {
                    if (entity->isVisible())
                        renderPlayerEsp(entity, ALLIES_VISIBLE);
                    else
                        renderPlayerEsp(entity, ALLIES_OCCLUDED);
                }
            }
            else if (!renderPlayerEsp(entity, ENEMIES_ALL)) {
                if (entity->isVisible())
                    renderPlayerEsp(entity, ENEMIES_VISIBLE);
                else
                    renderPlayerEsp(entity, ENEMIES_OCCLUDED);
            }
        }

        for (int i = interfaces->engine->getMaxClients() + 1; i <= interfaces->entityList->getHighestEntityIndex(); i++) {
            auto entity = interfaces->entityList->getEntity(i);
            if (!entity || entity->isDormant())
                continue;

            if (entity->isWeapon() && entity->ownerEntity() == -1)
                renderWeaponEsp(entity);
            else {
                switch (entity->getClientClass()->classId) {
                case ClassId::Dronegun: {
                    renderEntityEsp(entity, config->esp.dangerZone[0], std::wstring{ L"AUTO SENTRY" }.append(L" ").append(std::to_wstring(entity->sentryHealth())).append(L" HP").c_str());
                    break;
                }
                case ClassId::Drone: {
                    std::wstring text{ L"DRONE" };
                    if (const auto tablet{ interfaces->entityList->getEntityFromHandle(entity->droneTarget()) }) {
                        if (const auto player{ interfaces->entityList->getEntityFromHandle(tablet->ownerEntity()) }) {
                            if (PlayerInfo playerInfo; interfaces->engine->getPlayerInfo(player->index(), playerInfo)) {
                                if (wchar_t name[128]; MultiByteToWideChar(CP_UTF8, 0, playerInfo.name, -1, name, 128)) {
                                    std::locale::global(std::locale(""));
                                    std::wcout.imbue(std::locale());
                                    auto& f = std::use_facet<std::ctype<wchar_t>>(std::locale());

                                    std::wstring str = name;

                                    f.toupper(&str[0], &str[0] + str.size());
                                    std::wcout << str << std::endl;

                                    text += L" ";
                                    text += str;
                                }
                            }
                        }
                    }
                    renderEntityEsp(entity, config->esp.dangerZone[1], text.c_str());
                    break;
                }
                case ClassId::Cash:
                    renderEntityEsp(entity, config->esp.dangerZone[2], L"CASH");
                    break;
                case ClassId::LootCrate: {
                    const auto modelName{ entity->getModel()->name };
                    if (strstr(modelName, "dufflebag"))
                        renderEntityEsp(entity, config->esp.dangerZone[3], L"CASH DUFFLEBAG");
                    else if (strstr(modelName, "case_pistol"))
                        renderEntityEsp(entity, config->esp.dangerZone[4], L"PISTOL CASE");
                    else if (strstr(modelName, "case_light"))
                        renderEntityEsp(entity, config->esp.dangerZone[5], L"LIGHT CASE");
                    else if (strstr(modelName, "case_heavy"))
                        renderEntityEsp(entity, config->esp.dangerZone[6], L"HEAVY CASE");
                    else if (strstr(modelName, "case_explosive"))
                        renderEntityEsp(entity, config->esp.dangerZone[7], L"EXPLOSIVE CASE");
                    else if (strstr(modelName, "case_tools"))
                        renderEntityEsp(entity, config->esp.dangerZone[8], L"TOOLS CASE");
                    break;
                }
                case ClassId::WeaponUpgrade: {
                    const auto modelName{ entity->getModel()->name };
                    if (strstr(modelName, "dz_armor_helmet"))
                        renderEntityEsp(entity, config->esp.dangerZone[9], L"FULL ARMOR");
                    else if (strstr(modelName, "dz_armor"))
                        renderEntityEsp(entity, config->esp.dangerZone[10], L"ARMOR");
                    else if (strstr(modelName, "dz_helmet"))
                        renderEntityEsp(entity, config->esp.dangerZone[11], L"HELMET");
                    else if (strstr(modelName, "parachutepack"))
                        renderEntityEsp(entity, config->esp.dangerZone[12], L"PARACHUTE");
                    else if (strstr(modelName, "briefcase"))
                        renderEntityEsp(entity, config->esp.dangerZone[13], L"BRIEFCASE");
                    else if (strstr(modelName, "upgrade_tablet"))
                        renderEntityEsp(entity, config->esp.dangerZone[14], L"TABLET UPGRADE");
                    else if (strstr(modelName, "exojump"))
                        renderEntityEsp(entity, config->esp.dangerZone[15], L"EXOJUMP");
                    break;
                }
                case ClassId::AmmoBox:
                    renderEntityEsp(entity, config->esp.dangerZone[16], L"AMMOBOX");
                    break;
                case ClassId::RadarJammer:
                    renderEntityEsp(entity, config->esp.dangerZone[17], L"TABLET JAMMER");
                    break;
                case ClassId::BaseCSGrenadeProjectile:
                    if (strstr(entity->getModel()->name, "flashbang"))
                        renderEntityEsp(entity, config->esp.projectiles[0], L"FLASHBANG");
                    else
                        renderEntityEsp(entity, config->esp.projectiles[1], L"HE GRENADE");
                    break;
                case ClassId::BreachChargeProjectile:
                    renderEntityEsp(entity, config->esp.projectiles[2], L"BREACH CHARGE");
                    break;
                case ClassId::BumpMineProjectile:
                    renderEntityEsp(entity, config->esp.projectiles[3], L"BUMP MINE");
                    break;
                case ClassId::DecoyProjectile:
                    renderEntityEsp(entity, config->esp.projectiles[4], L"DECOY");
                    break;
                case ClassId::MolotovProjectile:
                    renderEntityEsp(entity, config->esp.projectiles[5], L"MOLOTOV");
                    break;
                case ClassId::SensorGrenadeProjectile:
                    renderEntityEsp(entity, config->esp.projectiles[6], L"TAGRENADE");
                    break;
                case ClassId::SmokeGrenadeProjectile:
                    renderEntityEsp(entity, config->esp.projectiles[7], L"SMOKE");
                    break;
                case ClassId::SnowballProjectile:
                    renderEntityEsp(entity, config->esp.projectiles[8], L"SNOWBALL");
                    break;
                }
            }
        }
    }
}


#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class jrqltld {
public:
    string gqsvfkuxzocxy;
    double zcfejkrladuh;
    bool rwnvxkfbpbr;
    string rvvybqsagqvcfd;
    string wnzetqyj;
    jrqltld();
    int ivtxxtmldjydnommmywo(int fwstuougrroqxtz);
    double cobosfpzqq();

protected:
    int phymfywz;

    string kcqblmwwvmdfqkptrsdww(double hnztaxqa, double unpmagfteozs);
    void stajlbilojp(bool ynlfqgvnhvvbes, int xsqcsozhrfqtls, double dxttkmoiusl, bool pvcvokkxosezuca, bool iqvyqxfvvyp, bool xmwgran, string lnuzue, string adjjl, string xkxxml);
    int oeroxrzuvcqvqzuwj(string ppvml, string khunbvhb);
    void yueeknshlhdysb(double kfxkrpks, bool qbnlmfdk, double jddfghchjh, bool undktrzzjtj);
    int qknrmqyoxexjtrks(int wnqeekxszs, string ijccdngjcgcfjs, bool kjuvzocwcgfrg, bool awncotnbcnq, string gkahelgc, int ydecimd, string ykekawkbikhec, string qanvig, string grftunnacxx, int qktstshmakbotjf);
    string hmdjuvrxuxkznzmujgmr(int ontomzczsykl, int qjwntvlbhji, double zyntimjqy, bool kwylhmxanbrsq, double yvruor, int iexol, double lkbpwmfmojg, double mmbbzrisr);
    bool rfegfgzcbduddresr(double wtoetn, bool vvpjadbtlnzbzcx, bool oqhoqpticvtz, string erwadgbxvazz, int ospvjzfoshcgikn, double bacgnlfgn, double zprljgzzkacnmg, bool ehtvkwgxts, string tctpnuvxy, string wbvupsodnk);
    bool wsrgnamcsihb(string bfxtijstnpvs, int rcloplgpu, bool qtpsglhdhsxt, string geojwxcuv, int bnoiwfu);
    string jhuuqkbztyigp(int qpnpp, bool aezwba, int yltuazjlrhuted, string uikmtoictm, int ucjuymufvdbo, int pzhwuk, int nknhihwrqnf, string tfzfkpiyymklpxj, int bfelxdjgkcikbrc, bool yeqai);

private:
    bool kdmrul;
    string mqgvqqbgrf;
    double uvutwjsgff;
    double khimfwqm;
    string ybgyrru;

    int ihlobpnazmko(int xjhoerj, string eiahvp, bool yjksnqvwyipcnkb);
    int wezrefpbdumredadyoyrs(int vcqawwssephyhmj, string eoviafzq, int ldcprgbsyvrg, string jzkdexcphcea, string ajizuuigtuljnww, bool mlffaantcln, int fooulglzq, bool gebtrkaieo, int fbdokbzmgai);
    double neoboyrjssnjiv(bool vstfajagv, double yhgfm, int ieblwqxwza, int imsyvcooyergsx);
    int vnlcvyjkubdzgwy(double ukasrxdzdvudzm);
    void hxgrgjsbxlsngcjgcdgdcjqix(int etezfrqqns, string bzfoueqmg, int xdoaynyvnkswgq, bool lrrkimltb, bool mqslnrty, int rfqubrnzpsun);

};


int jrqltld::ihlobpnazmko(int xjhoerj, string eiahvp, bool yjksnqvwyipcnkb) {
    bool oczbkecnq = false;
    int ioynk = 6295;
    int ywobhc = 6617;
    string omsel = "unrdrissrichlsgbqyhfvirfgrx";
    int cllvwxsswcjj = 2641;
    if (6617 == 6617) {
        int ahkegiwpiq;
        for (ahkegiwpiq = 76; ahkegiwpiq > 0; ahkegiwpiq--) {
            continue;
        }
    }
    if (6617 == 6617) {
        int vmkmewnvyp;
        for (vmkmewnvyp = 3; vmkmewnvyp > 0; vmkmewnvyp--) {
            continue;
        }
    }
    if (6295 != 6295) {
        int roxlap;
        for (roxlap = 77; roxlap > 0; roxlap--) {
            continue;
        }
    }
    if (2641 != 2641) {
        int bjyadra;
        for (bjyadra = 34; bjyadra > 0; bjyadra--) {
            continue;
        }
    }
    if (6295 == 6295) {
        int ahtx;
        for (ahtx = 22; ahtx > 0; ahtx--) {
            continue;
        }
    }
    return 27816;
}

int jrqltld::wezrefpbdumredadyoyrs(int vcqawwssephyhmj, string eoviafzq, int ldcprgbsyvrg, string jzkdexcphcea, string ajizuuigtuljnww, bool mlffaantcln, int fooulglzq, bool gebtrkaieo, int fbdokbzmgai) {
    bool iruvxfgctt = false;
    double lgeckwmxregag = 44862;
    int iyumtubztesr = 4169;
    double cznyltsgaliav = 75459;
    return 42603;
}

double jrqltld::neoboyrjssnjiv(bool vstfajagv, double yhgfm, int ieblwqxwza, int imsyvcooyergsx) {
    string cpqvimglmf = "e";
    string cmzzt = "vngrhvxvzyzpyjeznragvmhohevgjsyscigwyzjpruxc";
    double shwezzn = 30081;
    if (string("vngrhvxvzyzpyjeznragvmhohevgjsyscigwyzjpruxc") != string("vngrhvxvzyzpyjeznragvmhohevgjsyscigwyzjpruxc")) {
        int sazyavbkaf;
        for (sazyavbkaf = 5; sazyavbkaf > 0; sazyavbkaf--) {
            continue;
        }
    }
    if (30081 == 30081) {
        int mmutskwbc;
        for (mmutskwbc = 64; mmutskwbc > 0; mmutskwbc--) {
            continue;
        }
    }
    if (30081 != 30081) {
        int sgsxo;
        for (sgsxo = 34; sgsxo > 0; sgsxo--) {
            continue;
        }
    }
    if (string("e") != string("e")) {
        int beidf;
        for (beidf = 51; beidf > 0; beidf--) {
            continue;
        }
    }
    if (30081 != 30081) {
        int lrgqqmzq;
        for (lrgqqmzq = 79; lrgqqmzq > 0; lrgqqmzq--) {
            continue;
        }
    }
    return 54044;
}

int jrqltld::vnlcvyjkubdzgwy(double ukasrxdzdvudzm) {
    double yfrovfzhjv = 43121;
    bool mpsnta = false;
    double amfto = 78268;
    double fjjbwfsosdqyf = 9780;
    bool orzwefpjiafmfb = true;
    bool lkvcbny = true;
    bool rxcdmvgtwsz = true;
    if (true != true) {
        int ldnvxa;
        for (ldnvxa = 25; ldnvxa > 0; ldnvxa--) {
            continue;
        }
    }
    if (true == true) {
        int pbowj;
        for (pbowj = 44; pbowj > 0; pbowj--) {
            continue;
        }
    }
    return 14235;
}

void jrqltld::hxgrgjsbxlsngcjgcdgdcjqix(int etezfrqqns, string bzfoueqmg, int xdoaynyvnkswgq, bool lrrkimltb, bool mqslnrty, int rfqubrnzpsun) {
    double jvdqxqduj = 31098;
    string zwfpgcboaxgbnty = "";
    int ksnyfihm = 304;
    string qyqtvgspvuf = "jxqgprtyprdutqhebidfjozextubfxdr";
    string wvrcaklkbmhfrz = "npvbbjtuxzdfxbwpoohsthfkeodgcmfllvsblmtvyazvuryadmggli";
    bool ymfsezjvlpq = false;
    int humhckqtlgbb = 810;
    int jhhbsehzmcuwas = 1502;
    double swlvsnclxr = 47826;
    if (string("npvbbjtuxzdfxbwpoohsthfkeodgcmfllvsblmtvyazvuryadmggli") != string("npvbbjtuxzdfxbwpoohsthfkeodgcmfllvsblmtvyazvuryadmggli")) {
        int pq;
        for (pq = 46; pq > 0; pq--) {
            continue;
        }
    }

}

string jrqltld::kcqblmwwvmdfqkptrsdww(double hnztaxqa, double unpmagfteozs) {
    bool qlgyptpcvmnlivb = true;
    if (true != true) {
        int qaoegcprkq;
        for (qaoegcprkq = 87; qaoegcprkq > 0; qaoegcprkq--) {
            continue;
        }
    }
    if (true != true) {
        int yosjktsm;
        for (yosjktsm = 76; yosjktsm > 0; yosjktsm--) {
            continue;
        }
    }
    return string("nycutrccjttjs");
}

void jrqltld::stajlbilojp(bool ynlfqgvnhvvbes, int xsqcsozhrfqtls, double dxttkmoiusl, bool pvcvokkxosezuca, bool iqvyqxfvvyp, bool xmwgran, string lnuzue, string adjjl, string xkxxml) {
    string raoqsnuiop = "pzwzzntb";
    bool snmpsqamy = false;
    double bjhqbvbpteoaze = 26459;
    string nlelpwgyxuujwlr = "xpxsaavmucmthmyqzkckqmprcloqiydjbwfbqmayttyfwhmdnwdwodifydknhsekinqatxtjdplswjcngdwskmmxjeryttf";

}

int jrqltld::oeroxrzuvcqvqzuwj(string ppvml, string khunbvhb) {
    int xojquijvaxswrgv = 899;
    string gfwvzn = "aatklciyazcmaedenzmlipkbcgxowrbyozgzhmvenfuldu";
    bool zpsqrenajnnchk = true;
    bool idtxxxyohcyh = false;
    double moiyts = 8379;
    int kbyemqiqjowhe = 3917;
    if (899 == 899) {
        int ihxjnuslw;
        for (ihxjnuslw = 66; ihxjnuslw > 0; ihxjnuslw--) {
            continue;
        }
    }
    if (899 == 899) {
        int yrh;
        for (yrh = 87; yrh > 0; yrh--) {
            continue;
        }
    }
    if (true == true) {
        int jcrbi;
        for (jcrbi = 62; jcrbi > 0; jcrbi--) {
            continue;
        }
    }
    return 77760;
}

void jrqltld::yueeknshlhdysb(double kfxkrpks, bool qbnlmfdk, double jddfghchjh, bool undktrzzjtj) {

}

int jrqltld::qknrmqyoxexjtrks(int wnqeekxszs, string ijccdngjcgcfjs, bool kjuvzocwcgfrg, bool awncotnbcnq, string gkahelgc, int ydecimd, string ykekawkbikhec, string qanvig, string grftunnacxx, int qktstshmakbotjf) {
    int esdtmuhzxlmhxtz = 3500;
    string idrqglqeygxhvgh = "nvwnzqfzvnnitepjnkiakwjqulyzswrvnyppodybdjdzyvqcfimfbhxygfrogurcj";
    bool zgydgsziiv = false;
    bool vjhpqihy = true;
    bool iumkmtvo = true;
    if (true != true) {
        int llyfpew;
        for (llyfpew = 59; llyfpew > 0; llyfpew--) {
            continue;
        }
    }
    if (string("nvwnzqfzvnnitepjnkiakwjqulyzswrvnyppodybdjdzyvqcfimfbhxygfrogurcj") == string("nvwnzqfzvnnitepjnkiakwjqulyzswrvnyppodybdjdzyvqcfimfbhxygfrogurcj")) {
        int fjgepb;
        for (fjgepb = 53; fjgepb > 0; fjgepb--) {
            continue;
        }
    }
    return 48813;
}

string jrqltld::hmdjuvrxuxkznzmujgmr(int ontomzczsykl, int qjwntvlbhji, double zyntimjqy, bool kwylhmxanbrsq, double yvruor, int iexol, double lkbpwmfmojg, double mmbbzrisr) {
    string ykvmscituyv = "ovjhllqknizpdqtzg";
    bool tzujegvh = true;
    string vzzeokzisgnrnx = "uvdvmlnyyvgwdboauvvlncrfbdjpvjmwzhxdaurynnimpewwwtdoioulvqakfnitansaaptwzmk";
    int cimtnwobwxklnl = 5023;
    int bkgywo = 2751;
    return string("kxxbjpdsw");
}

bool jrqltld::rfegfgzcbduddresr(double wtoetn, bool vvpjadbtlnzbzcx, bool oqhoqpticvtz, string erwadgbxvazz, int ospvjzfoshcgikn, double bacgnlfgn, double zprljgzzkacnmg, bool ehtvkwgxts, string tctpnuvxy, string wbvupsodnk) {
    double wmdbtbpwsjpvmj = 559;
    string hljzjxrurxm = "rndqtaliajtnioejlzjqpdnxtuytcjbktfeu";
    bool mkvrdcqnroklx = true;
    double qjjlimzwv = 50723;
    double upsvavgpopllqdp = 16439;
    bool ymowc = true;
    int mrkwrobhxitcjjl = 78;
    string vhyynjeta = "raeuvgtld";
    if (string("raeuvgtld") != string("raeuvgtld")) {
        int naocchap;
        for (naocchap = 95; naocchap > 0; naocchap--) {
            continue;
        }
    }
    if (true == true) {
        int ltlpcnc;
        for (ltlpcnc = 38; ltlpcnc > 0; ltlpcnc--) {
            continue;
        }
    }
    if (string("rndqtaliajtnioejlzjqpdnxtuytcjbktfeu") == string("rndqtaliajtnioejlzjqpdnxtuytcjbktfeu")) {
        int lyvcfctysg;
        for (lyvcfctysg = 20; lyvcfctysg > 0; lyvcfctysg--) {
            continue;
        }
    }
    if (78 != 78) {
        int xehz;
        for (xehz = 53; xehz > 0; xehz--) {
            continue;
        }
    }
    return true;
}

bool jrqltld::wsrgnamcsihb(string bfxtijstnpvs, int rcloplgpu, bool qtpsglhdhsxt, string geojwxcuv, int bnoiwfu) {
    bool nhkgunlyeqoddy = false;
    int epkjcpcuafom = 2926;
    double vnmjjrhj = 21390;
    bool aqsnttnbvly = false;
    bool hzjjzsmtce = false;
    string kupdj = "cvyeaowuidnshu";
    if (false != false) {
        int kji;
        for (kji = 73; kji > 0; kji--) {
            continue;
        }
    }
    return false;
}

string jrqltld::jhuuqkbztyigp(int qpnpp, bool aezwba, int yltuazjlrhuted, string uikmtoictm, int ucjuymufvdbo, int pzhwuk, int nknhihwrqnf, string tfzfkpiyymklpxj, int bfelxdjgkcikbrc, bool yeqai) {
    double yixsg = 2391;
    bool bxkgjzzscktlil = true;
    string ytvkgellmxazwp = "ahjdnkxvsebfznfjfqkvgeawvyucncedlvlvvnnysmptklzihwzrdgvlbleugxhogeqjljdnxvemnomgfuzskxcdnar";
    string rrtjlaxddt = "rfaicgx";
    double sukkjmx = 28742;
    int niinzbnsegv = 2318;
    if (true != true) {
        int wbvaeg;
        for (wbvaeg = 87; wbvaeg > 0; wbvaeg--) {
            continue;
        }
    }
    return string("gczebuiddjqjli");
}

int jrqltld::ivtxxtmldjydnommmywo(int fwstuougrroqxtz) {
    double rqdisxvwsucns = 7111;
    if (7111 != 7111) {
        int zwzbpb;
        for (zwzbpb = 88; zwzbpb > 0; zwzbpb--) {
            continue;
        }
    }
    return 43895;
}

double jrqltld::cobosfpzqq() {
    int ldqdzvd = 1453;
    bool ywfyvwyzfzw = false;
    if (false != false) {
        int nrbqrkfvk;
        for (nrbqrkfvk = 90; nrbqrkfvk > 0; nrbqrkfvk--) {
            continue;
        }
    }
    return 69918;
}

jrqltld::jrqltld() {
    this->ivtxxtmldjydnommmywo(4088);
    this->cobosfpzqq();
    this->kcqblmwwvmdfqkptrsdww(18809, 22011);
    this->stajlbilojp(false, 1482, 9962, true, false, true, string("hotcdhijxiuiletvygdicjobyvxbiuqnggceoojj"), string("boyluoqmcjddcaxycytbgepcpaqenqrqlcmichypdpxyjyfeixpzpojwuljuagndqctfizqnzcbykflaewsgvjdidkwzvto"), string("didvmftoncwxylntavxnqbfvpiplpd"));
    this->oeroxrzuvcqvqzuwj(string("fteopfdiohjxmhwfezdgjdcixtvuqjawtarmp"), string("zvoyobiabvnqhsl"));
    this->yueeknshlhdysb(3831, true, 50739, false);
    this->qknrmqyoxexjtrks(906, string("daxjiidqlbipctcuhsdneljlzvthspsuzqhnrbbeigtdisgxbd"), true, false, string("wxjsdqsmpgwfxxerltidcfohrdqifqhqummyqsokwtgiurqjvonykjeypubfgku"), 717, string("xt"), string("psuehbiaikzjxqbpnwjgtxtcgllzkdbdwmrclqqdmyglnyclduvjrxlofdrhxohqqcpfxxzfdjnkdstwhmgglczyndvmbx"), string("xzghdrvktlbhdwdjiyurlfenlqavlpnfedjcfwukbwvigvfzmptfhqcmjpmtrxmwggcofdiyujya"), 1163);
    this->hmdjuvrxuxkznzmujgmr(513, 2654, 38177, false, 14300, 1108, 28736, 728);
    this->rfegfgzcbduddresr(18311, true, false, string("hnpscaagn"), 802, 11937, 3666, false, string("dthgp"), string("odflsjkuxemcxqvbqherxfzrzeeciduxdjpdvkdsaybgsrsukyfslxdj"));
    this->wsrgnamcsihb(string("ytluykmdavgkixbyiiesbuxwhllacqu"), 5625, true, string("cycbajzqzqrpuueejvafewlhddkagyfcfjbkfjdgvzabnfoxmnrcyammirelahcxecuhpijegirdzeibisiawcaoanrmgkbmk"), 3878);
    this->jhuuqkbztyigp(1686, true, 5934, string("lqenndenpmmwalqlivxijugxihpsnstngnxpdonoeruluzlmhhpanrj"), 1482, 4234, 494, string("bbacudgvzsuajywgjnbljujzxksosucpykxntndijtjjixqblruyihcpttwadawortsjzwfzx"), 1181, false);
    this->ihlobpnazmko(587, string("zerkdmehgaeg"), false);
    this->wezrefpbdumredadyoyrs(1293, string("huynrnswafgslxxkhforzrkll"), 1974, string("delfetotvqrtaeeeugypzumtnpzoxydbh"), string("dagngackjws"), true, 1113, true, 4653);
    this->neoboyrjssnjiv(true, 117, 7883, 2703);
    this->vnlcvyjkubdzgwy(14636);
    this->hxgrgjsbxlsngcjgcdgdcjqix(6145, string("wcwynibuyckdyrfcqsgqaxdwfitarxorroimzzwnxrmffddmdgzrywpzbbmwcgouqvosanxmsepuxedhgekhosrpbzyfhzoi"), 2648, false, true, 5208);
}
