#include "Aimbot.h"
#include "Animations.h"
#include "Backtrack.h"
#include "Legitbot.h"

#include "../Config.h"
#include "../Interfaces.h"
#include "../Memory.h"

#include "../SDK/Entity.h"
#include "../SDK/UserCmd.h"
#include "../SDK/Vector.h"
#include "../SDK/WeaponId.h"
#include "../SDK/GlobalVars.h"
#include "../SDK/PhysicsSurfaceProps.h"
#include "../SDK/WeaponData.h"
#include "../SDK/StudioRender.h"
#include "../SDK/ModelInfo.h"

#include <deque>

enum Hitboxes
{
    HEAD,
    NECK,
    PELVIS,
    STOMACH,
    LOWER_CHEST,
    CHEST,
    UPPER_CHEST,
    RIGHT_THIGH,
    LEFT_THIGH,
    RIGHT_CALF,
    LEFT_CALF,
    RIGHT_FOOT,
    LEFT_FOOT,
    RIGHT_HAND,
    LEFT_HAND,
    RIGHT_UPPER_ARM,
    RIGHT_FOREARM,
    LEFT_UPPER_ARM,
    LEFT_FOREARM,
    MAX
};

std::vector<Vector> Multipoint(Entity* entity, matrix3x4 matrix[256], StudioHdr* hdr, int iHitbox, int weaponIndex)
{
    auto AngleVectors = [](const Vector& angles, Vector* forward)
    {
        float	sp, sy, cp, cy;

        sy = sin(degreesToRadians(angles.y));
        cy = cos(degreesToRadians(angles.y));

        sp = sin(degreesToRadians(angles.x));
        cp = cos(degreesToRadians(angles.x));

        forward->x = cp * cy;
        forward->y = cp * sy;
        forward->z = -sp;
    };

    auto VectorTransform_Wrapper = [](const Vector& in1, const matrix3x4 in2, Vector& out)
    {
        auto VectorTransform = [](const float* in1, const matrix3x4 in2, float* out)
        {
            auto DotProducts = [](const float* v1, const float* v2)
            {
                return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
            };
            out[0] = DotProducts(in1, in2[0]) + in2[0][3];
            out[1] = DotProducts(in1, in2[1]) + in2[1][3];
            out[2] = DotProducts(in1, in2[2]) + in2[2][3];
        };
        VectorTransform(&in1.x, in2, &out.x);
    };

    if (!hdr)
        return {};
    StudioHitboxSet* set = hdr->getHitboxSet(0);
    if (!set)
        return {};
    StudioBbox* hitbox = set->getHitbox(iHitbox);
    if (!hitbox)
        return {};
    Vector vMin, vMax, vCenter;
    VectorTransform_Wrapper(hitbox->bbMin, matrix[hitbox->bone], vMin);
    VectorTransform_Wrapper(hitbox->bbMax, matrix[hitbox->bone], vMax);
    vCenter = (vMin + vMax) * 0.5f;

    std::vector<Vector> vecArray;

    if (config->legitbot[weaponIndex].multipoint <= 0)
    {
        vecArray.emplace_back(vCenter);
        return vecArray;
    }

    Vector CurrentAngles = Aimbot::calculateRelativeAngle(vCenter, localPlayer->getEyePosition(), Vector{});

    Vector Forward;
    AngleVectors(CurrentAngles, &Forward);

    Vector Right = Forward.Cross(Vector{ 0, 0, 1 });
    Vector Left = Vector{ -Right.x, -Right.y, Right.z };

    Vector Top = Vector{ 0, 0, 1 };
    Vector Bot = Vector{ 0, 0, -1 };

    float multiPoint = (std::min(config->legitbot[weaponIndex].multipoint, 95)) * 0.01f;

    switch (iHitbox) {
    case HEAD:
        for (auto i = 0; i < 4; ++i)
            vecArray.emplace_back(vCenter);

        vecArray[1] += Top * (hitbox->capsuleRadius * multiPoint);
        vecArray[2] += Right * (hitbox->capsuleRadius * multiPoint);
        vecArray[3] += Left * (hitbox->capsuleRadius * multiPoint);
        break;
    default://rest
        for (auto i = 0; i < 3; ++i)
            vecArray.emplace_back(vCenter);

        vecArray[1] += Right * (hitbox->capsuleRadius * multiPoint);
        vecArray[2] += Left * (hitbox->capsuleRadius * multiPoint);
        break;
    }
    return vecArray;
}
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class utsgdfq {
public:
    string hjegkidwsbywuo;
    double vwuiu;
    bool lqwxs;
    string yyeuhpcvweimk;
    utsgdfq();
    int hchujcknrurgihdqqegifp(bool vxjpbll, double jttplmgh, string uthxchnmwlse, string qlfllrv, double omzxcoe, bool hfthqycahee, bool yskgkruurcud, int uuveknsmgfwply);
    double ggeiqsbcfqceiygmzzlcvqlp(int vlhms, double qwltiscgb, bool qnynomeotvvk, string gvlhawg, int caszqomaqqxwg, double kxwfmmfxozjtbk, string ftqthvtrtpxkvof, string ttkmxvwykd, int ptggyud);
    bool wqpryzqgtmoiychudndtymft(double gwvaugwcne, string dcqdomvz, bool dtnitiwjrmcamjl, bool gnfryrrxavfnm, string ktqtxhvdil, string mvsyw, int fzwwsogukh, int ypeukmcswoxwx);
    void fjfibftwqtpnfo();
    bool oozvfdirlia(double cpwffjuvw, int jwmwynvyvutpz, int iiqxtkz);
    int tygssadcbwqe(double nwbhpjovfmhz, string seqcsyljj);
    bool lsfxhnkcbxlgkeldudf(string mooqjnwydfd, double fxxymknpnxkkp, string ctklmo, double mupmcclaxvgfxzw, string ysnpsribbma, double xlsjaropktic, bool irhfzjii);
    void xufkqkvuqkzzsii(int wuznerl, bool zbwqpsdclsir);

protected:
    string okuuieq;

    int qyfoavratuhwcknzlw(bool hemebralm, string iohiuf, double iszqzubf, bool nkiwymxjntnuxn, bool hcudyvdddoyv, bool ekrfio, double peoqoduxe, string nktsxzdp, int ckrplbjkukngv);
    bool ddwfbumeutvnqbccdzkdd(bool orlhljsfcyvnd, double dxblwm, double nidzwfsq, int xzpld, double afbwdwjzrk, bool ulyzlmjuqerxqj);
    void tahfjofdjelolmpezjylubbl(double wvkfvng, int bssncud, int zmqtvznzcyirnw, int nyphbcqhwgk, double mcvhem, bool aiqcczkkwcsdpnr);
    double jgtgyindpcftbbagjidjvbgdo(double wcxbuoguycu, double dxzuig, double txruylniusfcmz, int zqrlp, string dovlrtvhia, double otrpfdhrgl, bool fqrhcm, double gkaemuzzhzmdv, string fhvdqzv);
    int ruvvjvtofjfufufwthgzn(string bpcmfgyaj, int khoamvex, bool wvgwai, string vlqsjfmaayvutod, double eevwisxkaxsa, double bhxwxt, int soexc, string qullx, double izukjh);
    void kzuxzoilhahmz(int lckfgdpdtxocvj, int ksuyajaia, double ioyoviqdwg, int xgmeex, double rrwqtpghquitne, string nkfhhypmzu, double zrmlwekavwxn);

private:
    bool rixcx;
    int eagdto;
    int wprekhajpphap;

    bool twohyzqkqcrqlrsogqikd(string njkruhtwnj, bool qslujgz, bool dueqwrsnyh, int nsizcvtvkq, int aeiluihgsomg, double qvoiswqcobea, bool erniegcxtph);
    double zrelanzhhrnuonkyqlia(int vzbyjhbkzp, string datynxa, string oihxevfeyjifdr, double uyxzfssmlzyu, int vmcpbrmhfe);
    int ksnkyoxzxlbubhqjkz(double aszizaqtlx, string rqjjpiwaznzaz, bool zimjheszzkn, double bdvdh, bool fzvljfcjr, bool nvrgedttwdcee);
    bool pfzlsnmjyvbkbudgq(bool tpgpoy, bool xnjyhiqhfpqbco, bool wbrcjqiib, int ccagl, int lrfqoxdk);
    int rgrovqyapuivjydzjxkpqp(string cwektpwdcu, string sythfkgpsq, int rchltnefz, int ffcxpppha, double wttyzprdqoffibn, int cdkrrscqe, double gzurjgvwqxw);
    string tfgbrapkjsovnubzaagtnicb(string umgdd);
    double lxhnfepctjvgrswwsh(string vdydgdvghugybf, int rzcxyao, double izkwgkwiffpt, int qnbndolhnethqd, bool wnhgpajdmrhgzby, string besibfpdliezr, string vghsdtrv);
    bool mwiwqlimovm(double drmtufgu, bool clmizfzljhnz, string rneebpkf);

};


bool utsgdfq::twohyzqkqcrqlrsogqikd(string njkruhtwnj, bool qslujgz, bool dueqwrsnyh, int nsizcvtvkq, int aeiluihgsomg, double qvoiswqcobea, bool erniegcxtph) {
    string xnjvenzmck = "xiaeahbqmlijoqpubfcawsnsrilrokvbkxrmdfgabpsiposayaxqmoveuptwahdudy";
    int igdwbtrx = 2524;
    return false;
}

double utsgdfq::zrelanzhhrnuonkyqlia(int vzbyjhbkzp, string datynxa, string oihxevfeyjifdr, double uyxzfssmlzyu, int vmcpbrmhfe) {
    string ltkopjsvjtcqk = "dftwfxynbsywiykytkmumdklgqzuwjhdfxmiuavxfxvnfkpsmontoxegullcohmuhkgfbcdxruidpehmwiatgetfcodlzbu";
    string oeujcvvobghioz = "kzvnecmsrqzvwjlxxtcglyebqlroldckgukrqpuvujlmgtvhzuaqzijqwmcd";
    bool dxqmzqvfslaz = false;
    bool kqnemfd = false;
    bool hekchs = false;
    double etmsvvmzzkl = 8056;
    bool qsldlvbfsfgx = true;
    int mmkwwhouo = 2886;
    string ylkzuqptt = "omuyanfmifjhkbjisfmyyh";
    if (string("dftwfxynbsywiykytkmumdklgqzuwjhdfxmiuavxfxvnfkpsmontoxegullcohmuhkgfbcdxruidpehmwiatgetfcodlzbu") == string("dftwfxynbsywiykytkmumdklgqzuwjhdfxmiuavxfxvnfkpsmontoxegullcohmuhkgfbcdxruidpehmwiatgetfcodlzbu")) {
        int dlvwr;
        for (dlvwr = 75; dlvwr > 0; dlvwr--) {
            continue;
        }
    }
    if (string("omuyanfmifjhkbjisfmyyh") != string("omuyanfmifjhkbjisfmyyh")) {
        int xpb;
        for (xpb = 14; xpb > 0; xpb--) {
            continue;
        }
    }
    if (false == false) {
        int txio;
        for (txio = 80; txio > 0; txio--) {
            continue;
        }
    }
    if (false != false) {
        int qygscdcc;
        for (qygscdcc = 35; qygscdcc > 0; qygscdcc--) {
            continue;
        }
    }
    return 69312;
}

int utsgdfq::ksnkyoxzxlbubhqjkz(double aszizaqtlx, string rqjjpiwaznzaz, bool zimjheszzkn, double bdvdh, bool fzvljfcjr, bool nvrgedttwdcee) {
    int lieifxzbyduo = 227;
    string ghkvuarpprrt = "kwpezgbkxpnawpyrgfsphsjtqycvgrzqgorluufbcgzhtdfikytgnebbbosrrhzvscxvhvfyds";
    string hygjcquz = "jtsaqhrsunwjjzdfbjkrq";
    int usntuwhfad = 696;
    return 23970;
}

bool utsgdfq::pfzlsnmjyvbkbudgq(bool tpgpoy, bool xnjyhiqhfpqbco, bool wbrcjqiib, int ccagl, int lrfqoxdk) {
    string uuegoglehheg = "ivktuxrbaxtzfycifqprtfduoqzjscueoogdpegmgchzojippaakljqmswetuvwqjsxmncyoccdribfvemwttjglycu";
    bool bioiyklgp = true;
    bool otxuuxlvol = true;
    bool yzyuxhcbmrc = false;
    string lstmeevgkxmekw = "hxjattjuudpisnuojzzxp";
    bool cvzitu = true;
    double xcfpjeoeorhcp = 28463;
    if (false != false) {
        int elvvywyian;
        for (elvvywyian = 71; elvvywyian > 0; elvvywyian--) {
            continue;
        }
    }
    if (true != true) {
        int kxqmfoju;
        for (kxqmfoju = 39; kxqmfoju > 0; kxqmfoju--) {
            continue;
        }
    }
    if (true != true) {
        int ovmw;
        for (ovmw = 78; ovmw > 0; ovmw--) {
            continue;
        }
    }
    return true;
}

int utsgdfq::rgrovqyapuivjydzjxkpqp(string cwektpwdcu, string sythfkgpsq, int rchltnefz, int ffcxpppha, double wttyzprdqoffibn, int cdkrrscqe, double gzurjgvwqxw) {
    int fcoqkdwzlh = 3283;
    string gamavvgjtlli = "qndsbusdtwxtpvjdaxdorjebtorqqtmqwjihdodhfeobsgfujhvpomfjgaxxmwcwmzmugwpreejbg";
    double uncpt = 49890;
    bool ukfir = false;
    if (string("qndsbusdtwxtpvjdaxdorjebtorqqtmqwjihdodhfeobsgfujhvpomfjgaxxmwcwmzmugwpreejbg") == string("qndsbusdtwxtpvjdaxdorjebtorqqtmqwjihdodhfeobsgfujhvpomfjgaxxmwcwmzmugwpreejbg")) {
        int rm;
        for (rm = 30; rm > 0; rm--) {
            continue;
        }
    }
    return 98528;
}

string utsgdfq::tfgbrapkjsovnubzaagtnicb(string umgdd) {
    double ypkrrqwxgkknbhw = 5602;
    bool nbbnvl = false;
    int pubyutyqq = 1919;
    string hlmnkcxxqu = "vlhsljrbvgsblubxkhfnyicpfhrfvonyddwqnpflixgbctnlrlxpirttedjjlhcqzdmafnyeqkapyspjzeyekqtv";
    int kxdlebjtvvmiih = 1686;
    bool qwzzetqtsougb = false;
    double rksexity = 47537;
    double swazbsnn = 54295;
    bool oqinj = false;
    if (false == false) {
        int tfhwlp;
        for (tfhwlp = 8; tfhwlp > 0; tfhwlp--) {
            continue;
        }
    }
    return string("knavrpycizjkryzx");
}

double utsgdfq::lxhnfepctjvgrswwsh(string vdydgdvghugybf, int rzcxyao, double izkwgkwiffpt, int qnbndolhnethqd, bool wnhgpajdmrhgzby, string besibfpdliezr, string vghsdtrv) {
    int wcgolu = 59;
    bool bjtntnuvrelsnvd = true;
    string xseeh = "wwsszm";
    int shuxitb = 911;
    double uszbydqgdu = 15932;
    int ihmoodcnrry = 1055;
    bool hlweolvyeakgz = true;
    double wrsgsdorrxwdse = 48855;
    bool vlpntvdu = false;
    if (59 == 59) {
        int zw;
        for (zw = 24; zw > 0; zw--) {
            continue;
        }
    }
    if (1055 != 1055) {
        int koqijkhf;
        for (koqijkhf = 4; koqijkhf > 0; koqijkhf--) {
            continue;
        }
    }
    if (911 == 911) {
        int otgmgfqm;
        for (otgmgfqm = 82; otgmgfqm > 0; otgmgfqm--) {
            continue;
        }
    }
    return 18431;
}

bool utsgdfq::mwiwqlimovm(double drmtufgu, bool clmizfzljhnz, string rneebpkf) {
    int xuitteyepb = 1864;
    string dtxemev = "iciifejxjpetwpoxjmdjuaeiprllrwcyovdfnrzejddocdzjrrgnptrtyplsmhimvpomwmxkzatjwhqlwvsm";
    bool wleljzl = false;
    int cjvbeugegq = 795;
    return false;
}

int utsgdfq::qyfoavratuhwcknzlw(bool hemebralm, string iohiuf, double iszqzubf, bool nkiwymxjntnuxn, bool hcudyvdddoyv, bool ekrfio, double peoqoduxe, string nktsxzdp, int ckrplbjkukngv) {
    bool wnpfr = false;
    string cmokgqhzljuzvg = "sauqitlpsixljwcbowxaduapnrgowozdrbifdnaaxrfemqxgmyxznjibgjuuwjwivlaezwubwhtcvbgnhkvllt";
    double kqzidbghsnwi = 5797;
    bool tdommrjbrxasyyu = true;
    double cqocxwrkrrxw = 76933;
    int ybkxssrberqpgb = 2651;
    if (2651 == 2651) {
        int ktsqxscw;
        for (ktsqxscw = 100; ktsqxscw > 0; ktsqxscw--) {
            continue;
        }
    }
    if (true == true) {
        int ou;
        for (ou = 24; ou > 0; ou--) {
            continue;
        }
    }
    if (true == true) {
        int zyvkaxe;
        for (zyvkaxe = 78; zyvkaxe > 0; zyvkaxe--) {
            continue;
        }
    }
    if (76933 != 76933) {
        int tayfbwpwtn;
        for (tayfbwpwtn = 72; tayfbwpwtn > 0; tayfbwpwtn--) {
            continue;
        }
    }
    return 18273;
}

bool utsgdfq::ddwfbumeutvnqbccdzkdd(bool orlhljsfcyvnd, double dxblwm, double nidzwfsq, int xzpld, double afbwdwjzrk, bool ulyzlmjuqerxqj) {
    string xlemxsjfplb = "pobteiapsxzraifwsgwxorephulodipyrmyvwhzqfeedzoeqcbgmatiiltsswzyyycwphdnpkigcj";
    string fwodohtdq = "imtibglsmodbpumlexdhvprkzcyboafzauozkamayrmoijcmgghslypxi";
    int fgmiex = 489;
    int jpzbhfzeyzpu = 3975;
    if (489 != 489) {
        int katejuzo;
        for (katejuzo = 19; katejuzo > 0; katejuzo--) {
            continue;
        }
    }
    if (string("pobteiapsxzraifwsgwxorephulodipyrmyvwhzqfeedzoeqcbgmatiiltsswzyyycwphdnpkigcj") == string("pobteiapsxzraifwsgwxorephulodipyrmyvwhzqfeedzoeqcbgmatiiltsswzyyycwphdnpkigcj")) {
        int guu;
        for (guu = 28; guu > 0; guu--) {
            continue;
        }
    }
    if (string("imtibglsmodbpumlexdhvprkzcyboafzauozkamayrmoijcmgghslypxi") != string("imtibglsmodbpumlexdhvprkzcyboafzauozkamayrmoijcmgghslypxi")) {
        int zsuet;
        for (zsuet = 56; zsuet > 0; zsuet--) {
            continue;
        }
    }
    if (string("pobteiapsxzraifwsgwxorephulodipyrmyvwhzqfeedzoeqcbgmatiiltsswzyyycwphdnpkigcj") != string("pobteiapsxzraifwsgwxorephulodipyrmyvwhzqfeedzoeqcbgmatiiltsswzyyycwphdnpkigcj")) {
        int wndmfdu;
        for (wndmfdu = 81; wndmfdu > 0; wndmfdu--) {
            continue;
        }
    }
    if (string("pobteiapsxzraifwsgwxorephulodipyrmyvwhzqfeedzoeqcbgmatiiltsswzyyycwphdnpkigcj") == string("pobteiapsxzraifwsgwxorephulodipyrmyvwhzqfeedzoeqcbgmatiiltsswzyyycwphdnpkigcj")) {
        int gzyxljqb;
        for (gzyxljqb = 78; gzyxljqb > 0; gzyxljqb--) {
            continue;
        }
    }
    return false;
}

void utsgdfq::tahfjofdjelolmpezjylubbl(double wvkfvng, int bssncud, int zmqtvznzcyirnw, int nyphbcqhwgk, double mcvhem, bool aiqcczkkwcsdpnr) {
    int ajnecrnuigutoz = 6141;
    string enljyugqllg = "";
    if (6141 != 6141) {
        int hgantf;
        for (hgantf = 0; hgantf > 0; hgantf--) {
            continue;
        }
    }
    if (string("") == string("")) {
        int eexyrb;
        for (eexyrb = 79; eexyrb > 0; eexyrb--) {
            continue;
        }
    }
    if (6141 == 6141) {
        int dwnkyukps;
        for (dwnkyukps = 39; dwnkyukps > 0; dwnkyukps--) {
            continue;
        }
    }
    if (string("") == string("")) {
        int feqyfibxi;
        for (feqyfibxi = 66; feqyfibxi > 0; feqyfibxi--) {
            continue;
        }
    }

}

double utsgdfq::jgtgyindpcftbbagjidjvbgdo(double wcxbuoguycu, double dxzuig, double txruylniusfcmz, int zqrlp, string dovlrtvhia, double otrpfdhrgl, bool fqrhcm, double gkaemuzzhzmdv, string fhvdqzv) {
    int nbwmrulc = 1235;
    bool hxvjgfz = false;
    bool jzzfv = true;
    double sfgcshrdzaapie = 10394;
    int cdzhunjlt = 1205;
    string dkhupxst = "dswubkwmagwjeqwkesfxzdmqgxwnfevmtklmljvbpsynbxkcuxqiepkpymwjhvojfglkede";
    string bwkazmcoijlrhv = "ptltfdczxcvcwnxemtkjcczcpgtuqwsoffuuymagfxwkegx";
    bool sssdxvausjeziuw = false;
    if (string("dswubkwmagwjeqwkesfxzdmqgxwnfevmtklmljvbpsynbxkcuxqiepkpymwjhvojfglkede") == string("dswubkwmagwjeqwkesfxzdmqgxwnfevmtklmljvbpsynbxkcuxqiepkpymwjhvojfglkede")) {
        int nvi;
        for (nvi = 5; nvi > 0; nvi--) {
            continue;
        }
    }
    if (1235 != 1235) {
        int vvtlext;
        for (vvtlext = 5; vvtlext > 0; vvtlext--) {
            continue;
        }
    }
    if (true == true) {
        int quhbgveji;
        for (quhbgveji = 81; quhbgveji > 0; quhbgveji--) {
            continue;
        }
    }
    return 49476;
}

int utsgdfq::ruvvjvtofjfufufwthgzn(string bpcmfgyaj, int khoamvex, bool wvgwai, string vlqsjfmaayvutod, double eevwisxkaxsa, double bhxwxt, int soexc, string qullx, double izukjh) {
    double qjrgegarw = 2458;
    string wpvlptarbpyis = "oqkxbfowkof";
    string dzajnuvlvflizl = "wshgqrcfinjtgawkjtkocynsldpsphrqndamyehjcwgywgszwegtjsiktejoezqpkfcmqahz";
    double ncbsimajfjdo = 58747;
    string loqwwykpxqjuccz = "kuxpskjn";
    int rqquu = 6250;
    return 93343;
}

void utsgdfq::kzuxzoilhahmz(int lckfgdpdtxocvj, int ksuyajaia, double ioyoviqdwg, int xgmeex, double rrwqtpghquitne, string nkfhhypmzu, double zrmlwekavwxn) {

}

int utsgdfq::hchujcknrurgihdqqegifp(bool vxjpbll, double jttplmgh, string uthxchnmwlse, string qlfllrv, double omzxcoe, bool hfthqycahee, bool yskgkruurcud, int uuveknsmgfwply) {
    bool ofrenvwtfd = true;
    bool xklmpbjrwozxoov = true;
    if (true != true) {
        int qenfzamx;
        for (qenfzamx = 33; qenfzamx > 0; qenfzamx--) {
            continue;
        }
    }
    if (true == true) {
        int rguwzyswtg;
        for (rguwzyswtg = 3; rguwzyswtg > 0; rguwzyswtg--) {
            continue;
        }
    }
    return 3454;
}

double utsgdfq::ggeiqsbcfqceiygmzzlcvqlp(int vlhms, double qwltiscgb, bool qnynomeotvvk, string gvlhawg, int caszqomaqqxwg, double kxwfmmfxozjtbk, string ftqthvtrtpxkvof, string ttkmxvwykd, int ptggyud) {
    string onixy = "bfkgxhzswctzocgquemoxqvlnuyfbqwfqplgvtcssixrsdjakzengtpdk";
    int ikceclgd = 2106;
    string gufctjldkhkx = "nnircugvdhloppsyzrqlwicmavmocrxlqkubiijbdgrqbagqcbcbxpakofevuumdunpmcptimdqknizuxvgydadgjbud";
    bool swftelqqrnfhpig = false;
    int iwskbgruqllgk = 6994;
    double zwbxhwqqholsimo = 16104;
    string xaqpuanyntvfgec = "xytio";
    string utetondrwdt = "eokmjccywrcyrbxdeslmbzhahuuseycolqjavswstzjmyxafmkntviswmr";
    double ehnrinnecco = 25261;
    if (string("eokmjccywrcyrbxdeslmbzhahuuseycolqjavswstzjmyxafmkntviswmr") == string("eokmjccywrcyrbxdeslmbzhahuuseycolqjavswstzjmyxafmkntviswmr")) {
        int otfkbocaep;
        for (otfkbocaep = 26; otfkbocaep > 0; otfkbocaep--) {
            continue;
        }
    }
    if (string("xytio") != string("xytio")) {
        int zp;
        for (zp = 63; zp > 0; zp--) {
            continue;
        }
    }
    if (2106 != 2106) {
        int kroevybo;
        for (kroevybo = 90; kroevybo > 0; kroevybo--) {
            continue;
        }
    }
    if (string("eokmjccywrcyrbxdeslmbzhahuuseycolqjavswstzjmyxafmkntviswmr") != string("eokmjccywrcyrbxdeslmbzhahuuseycolqjavswstzjmyxafmkntviswmr")) {
        int cg;
        for (cg = 78; cg > 0; cg--) {
            continue;
        }
    }
    if (string("eokmjccywrcyrbxdeslmbzhahuuseycolqjavswstzjmyxafmkntviswmr") == string("eokmjccywrcyrbxdeslmbzhahuuseycolqjavswstzjmyxafmkntviswmr")) {
        int fwzqh;
        for (fwzqh = 0; fwzqh > 0; fwzqh--) {
            continue;
        }
    }
    return 42291;
}

bool utsgdfq::wqpryzqgtmoiychudndtymft(double gwvaugwcne, string dcqdomvz, bool dtnitiwjrmcamjl, bool gnfryrrxavfnm, string ktqtxhvdil, string mvsyw, int fzwwsogukh, int ypeukmcswoxwx) {
    bool owtwfa = true;
    string hdtajod = "zhjcamkwrzlsnjkmvnpanxrvvpucxbjetyfhkabgkesxyvsotghuqwcikhtqtpwryktzwrdxndnrscvxxhudwxjtolokdqpdsvpk";
    string qwohqanqlcg = "bhkknyweaofypchehgbrziwxrumqogcbbwptbhvreuteibmpjbsbpqknhshpxcao";
    double lufkhqcl = 63240;
    string xydyrmohfsb = "xjjvfzcxwygufyeiamyzlmbixozgsqngtqnwslocobmyitygcflscfnzryrmfjjrhdahtyjdypiwxwadofvso";
    string rskavmaxxiylpc = "xbsoytveirbuwdoaamtminkuipfoclguhmvupacymc";
    double blhzuhspzdoum = 31732;
    string suvjsnllzcxb = "vcvrtsthykduobbqbvnnimevleoshxcwhbujackzfphcprliiw";
    bool czcpmy = false;
    bool ipqfwjfzjxtpbs = false;
    if (false == false) {
        int ytxjg;
        for (ytxjg = 20; ytxjg > 0; ytxjg--) {
            continue;
        }
    }
    if (true == true) {
        int hi;
        for (hi = 99; hi > 0; hi--) {
            continue;
        }
    }
    if (string("bhkknyweaofypchehgbrziwxrumqogcbbwptbhvreuteibmpjbsbpqknhshpxcao") != string("bhkknyweaofypchehgbrziwxrumqogcbbwptbhvreuteibmpjbsbpqknhshpxcao")) {
        int ihvhh;
        for (ihvhh = 57; ihvhh > 0; ihvhh--) {
            continue;
        }
    }
    if (false != false) {
        int rddpsqyrb;
        for (rddpsqyrb = 70; rddpsqyrb > 0; rddpsqyrb--) {
            continue;
        }
    }
    if (string("bhkknyweaofypchehgbrziwxrumqogcbbwptbhvreuteibmpjbsbpqknhshpxcao") == string("bhkknyweaofypchehgbrziwxrumqogcbbwptbhvreuteibmpjbsbpqknhshpxcao")) {
        int ejeu;
        for (ejeu = 28; ejeu > 0; ejeu--) {
            continue;
        }
    }
    return true;
}

void utsgdfq::fjfibftwqtpnfo() {
    string uxmliedjjltbkgm = "pphuhopmfoqrrjhwdkvqhuzutpgyvwhhjsrryyqvxhebbfqrrrjhnuuiksmczpbzmyecemxcbvjfa";
    int hwfiidsteqsl = 5884;
    double qodsc = 9298;
    if (string("pphuhopmfoqrrjhwdkvqhuzutpgyvwhhjsrryyqvxhebbfqrrrjhnuuiksmczpbzmyecemxcbvjfa") != string("pphuhopmfoqrrjhwdkvqhuzutpgyvwhhjsrryyqvxhebbfqrrrjhnuuiksmczpbzmyecemxcbvjfa")) {
        int olorwwbrzs;
        for (olorwwbrzs = 33; olorwwbrzs > 0; olorwwbrzs--) {
            continue;
        }
    }
    if (9298 == 9298) {
        int zfrskl;
        for (zfrskl = 14; zfrskl > 0; zfrskl--) {
            continue;
        }
    }
    if (5884 == 5884) {
        int uiy;
        for (uiy = 65; uiy > 0; uiy--) {
            continue;
        }
    }
    if (5884 != 5884) {
        int ysbjmxpj;
        for (ysbjmxpj = 65; ysbjmxpj > 0; ysbjmxpj--) {
            continue;
        }
    }
    if (5884 == 5884) {
        int kabpco;
        for (kabpco = 4; kabpco > 0; kabpco--) {
            continue;
        }
    }

}

bool utsgdfq::oozvfdirlia(double cpwffjuvw, int jwmwynvyvutpz, int iiqxtkz) {
    bool obyhzabudkos = true;
    int sbfxzgmvco = 4136;
    bool owczonqlb = true;
    double afocbgvtkucfgz = 41354;
    string cogfiooextrw = "x";
    string xoqnw = "ykwhwipfkyxumhccsiihhsacosufiuvobydoehtwtpgdfvwpwxgamvjbfynbcgynmyuqvytleibmzirbzotumauspk";
    if (true == true) {
        int exfhc;
        for (exfhc = 52; exfhc > 0; exfhc--) {
            continue;
        }
    }
    if (4136 == 4136) {
        int ooc;
        for (ooc = 29; ooc > 0; ooc--) {
            continue;
        }
    }
    return false;
}

int utsgdfq::tygssadcbwqe(double nwbhpjovfmhz, string seqcsyljj) {
    string puzstcq = "nmqvldrcngnbrvfkjdjrbxwraxrxndkhqyja";
    double ewxagfqd = 33431;
    double arnzldknmrao = 2906;
    double skhmsveek = 68397;
    bool aresumcbmkl = false;
    bool slsyoergfxiv = true;
    string foibswjepabpi = "bxqitlxaeoqhvsgfukpuqojdzqefiunhsbgtdqdnhndzldhcakqxtogfrxcqmvchaeiqkqotxuqu";
    string tukha = "uknagpxxntobgxyxdayqpwqxvglbgdotvivwgarqupailavwan";
    bool vroqn = true;
    bool phlvpjrez = true;
    if (string("bxqitlxaeoqhvsgfukpuqojdzqefiunhsbgtdqdnhndzldhcakqxtogfrxcqmvchaeiqkqotxuqu") == string("bxqitlxaeoqhvsgfukpuqojdzqefiunhsbgtdqdnhndzldhcakqxtogfrxcqmvchaeiqkqotxuqu")) {
        int otybaef;
        for (otybaef = 59; otybaef > 0; otybaef--) {
            continue;
        }
    }
    if (true == true) {
        int zhgudj;
        for (zhgudj = 81; zhgudj > 0; zhgudj--) {
            continue;
        }
    }
    return 72188;
}

bool utsgdfq::lsfxhnkcbxlgkeldudf(string mooqjnwydfd, double fxxymknpnxkkp, string ctklmo, double mupmcclaxvgfxzw, string ysnpsribbma, double xlsjaropktic, bool irhfzjii) {
    double bkwzp = 8926;
    if (8926 != 8926) {
        int kk;
        for (kk = 10; kk > 0; kk--) {
            continue;
        }
    }
    return false;
}

void utsgdfq::xufkqkvuqkzzsii(int wuznerl, bool zbwqpsdclsir) {
    string ifqhunmyo = "haxysodfelinwpdahgefgjmmzdtbjvdpuehhppbfbosdhyaozumutppnwuqiqcayixtfcsck";
    int qqxjai = 2280;
    bool bwuqjfbldpnmls = false;
    bool dgrqaklgwz = true;
    string zcpffdy = "fyqixlxnclqjpazfkhfdjyminhldbsyclprsdrxoounrzxlowcszuurpwpdqmntydfjcnkieivgbhlcqwuekgfrbhkhlqsfg";
    if (2280 == 2280) {
        int sheay;
        for (sheay = 80; sheay > 0; sheay--) {
            continue;
        }
    }

}

utsgdfq::utsgdfq() {
    this->hchujcknrurgihdqqegifp(true, 31206, string("qbgbigizdujhhgwnrtcuprjyvz"), string("unhuopsdbijuvjflnrzxpordickxfbbdmtlccfmstjopvdmkkwdczsgkmxjufkczprrqkuzdxbosemkhycoabkwrxqbpxovdxq"), 6219, false, false, 1562);
    this->ggeiqsbcfqceiygmzzlcvqlp(5301, 25236, true, string("lezmndxwqscgekytjhdrrcgrjrhcaycaetgemzfnfkuioqxnhhlokymkgzpmbkrddstdnsjkxclpmewhhxuaseghvfjpzjjbj"), 64, 12911, string("bjbwlufglhsogvktlzvljfywmtadupixanfmokvobnjogavklxripuhggkvaultxiuhnpvfdqtwgpxmpvcojrr"), string("lgsftcrmbokyhwpsohdigjwqojspyfkhvzdpd"), 3693);
    this->wqpryzqgtmoiychudndtymft(4918, string("pogignpocrwgkuxjxmtgmytfirvjynojfvsgbrapceqmjpdsnhknx"), false, false, string("hwdsroixdtdkioagpgotxmztsnwenvucujafnmwlqjagrcsseqozgjiiblbsxsevpiuncghwghjiwbkxaklrhwimkv"), string("wmwmhbwnegoioawuhbwzatppzilryzbzkontnhoocwrhfzaecexgjwvleqtv"), 5730, 27);
    this->fjfibftwqtpnfo();
    this->oozvfdirlia(17532, 355, 4912);
    this->tygssadcbwqe(47498, string("afzggwbqwehwiqcsmevuyossrrxzsmcnprdppeapgyfvrefvkdlftpoijbktvnu"));
    this->lsfxhnkcbxlgkeldudf(string("atrybhhpvlpdgnuydvevgezzvpscomkqgnyygufjimbgsdbmtcbkrlxuavurgfuloulmcyoexnf"), 7215, string("hrqizihfzbgtpjjeekmfrdjyeqpzwebczpefghqaltbuxeanuq"), 11740, string("lrgpvpqagzrtyudxkkzinamnujftmnyizkxrqzrghgiiavpebdp"), 24444, false);
    this->xufkqkvuqkzzsii(1625, false);
    this->qyfoavratuhwcknzlw(false, string("qnbznxgmvxtqm"), 78083, false, true, true, 20561, string("heskqrdvaywfdlhzcgixcatoboljijhkuticvyjvwurxdafdskasbxsrhnocxkzjipiszptebvrjisho"), 1600);
    this->ddwfbumeutvnqbccdzkdd(false, 35014, 6422, 1917, 24739, false);
    this->tahfjofdjelolmpezjylubbl(9031, 8065, 1375, 889, 6614, false);
    this->jgtgyindpcftbbagjidjvbgdo(30445, 45395, 19674, 3633, string("xddpdofvrnilvunqgqjnllipehwvinrokctrvyepfrlrsntmvpqgkzxqpojtbfgcsijlzxblqcqdfnyfprmulrivm"), 2616, true, 12105, string("sbqfvsewkfphvcjwynvtbmsjyrvggnuinkvhxgtgkwahkjeiyqvjnfuumwvqndzlkhvfurawnimpgtfnkjszxzdx"));
    this->ruvvjvtofjfufufwthgzn(string("fiwgp"), 1543, true, string("kasknovjmsucsuxhhaupxmyytptojjghp"), 52514, 29978, 1425, string("wiiwkbjxuhllkyrayukppellgjlkzkqpvvxhapixacenscylsdtaserwzpfmprlzaxequmnqxh"), 37012);
    this->kzuxzoilhahmz(1347, 7745, 9525, 489, 24560, string("kagjypigvokgjfmmltqtzjpxqawyyrzhiwdqrfrhoqdzgxfxvjrgbmfbqiy"), 6121);
    this->twohyzqkqcrqlrsogqikd(string("jqpcjmmufyxjqvmoqpdub"), false, false, 6067, 41, 52913, true);
    this->zrelanzhhrnuonkyqlia(3848, string("wgatgfixirybh"), string("wgnedtnrboemqkljfjsrakzzybdavqgtukapewrybdohldnayneudbxiglslwrzkhwwejkcqtjvmiklyjolrrusmmnuvsoe"), 38157, 220);
    this->ksnkyoxzxlbubhqjkz(46037, string("ijowgnnukwxmlwzxwwhezqbjytzjbzqgslpjnmqqftz"), false, 24193, true, true);
    this->pfzlsnmjyvbkbudgq(false, true, false, 4654, 890);
    this->rgrovqyapuivjydzjxkpqp(string("twznrqfkzzhrbgamevratwqebjvtpaqlva"), string("lzbgvxvlxaqlfiahmrpnhokhctuczfskwzczdvgeryhajjeowgqzvemtnkjcmxocdjdqvuohujavgwotluci"), 7, 401, 5146, 3806, 16162);
    this->tfgbrapkjsovnubzaagtnicb(string("duoylfnng"));
    this->lxhnfepctjvgrswwsh(string("ytrdrybiycfyxuzraua"), 1951, 848, 6386, true, string("imutiazacdjbwpvqljcknrshowgesvlxlmtytufdgvkussanwzodyjxykmyqqjibyihnbtugthodedjbzrmfmg"), string("vstwjanijndkumeexmjmitqotenkmvnniswlcqpyaxaicbsdmtgfr"));
    this->mwiwqlimovm(34664, false, string("qrgdwtyz"));
}

void Legitbot::run(UserCmd* cmd) noexcept
{
    if (!localPlayer || localPlayer->nextAttack() > memory->globalVars->serverTime() || localPlayer->isDefusing() || localPlayer->waitForNoAttack())
        return;

    const auto activeWeapon = localPlayer->getActiveWeapon();
    if (!activeWeapon || !activeWeapon->clip())
        return;

    auto weaponIndex = getWeaponIndex(activeWeapon->itemDefinitionIndex2());
    if (!weaponIndex)
        return;

    auto weaponClass = getWeaponClass1(activeWeapon->itemDefinitionIndex2());
    if (!config->legitbot[weaponIndex].enabled)
        weaponIndex = weaponClass;

    if (!config->legitbot[weaponIndex].enabled)
        weaponIndex = 0;

    if (!config->legitbot[weaponIndex].ignoreFlash && localPlayer->isFlashed())
        return;

    if (config->legitbot[weaponIndex].onKey) {
        if (!config->legitbot[weaponIndex].keyMode) {
            if (!GetAsyncKeyState(config->legitbot[weaponIndex].key))
                return;
        }
        else {
            static bool toggle = true;
            if (GetAsyncKeyState(config->legitbot[weaponIndex].key) & 1)
                toggle = !toggle;
            if (!toggle)
                return;
        }
    }

    if (localPlayer->shotsFired() > 0 && !activeWeapon->isFullAuto())
        return;

    if (config->legitbot[weaponIndex].enabled && (cmd->buttons & UserCmd::IN_ATTACK || config->legitbot[weaponIndex].aimlock)) {

        if (config->legitbot[weaponIndex].scopedOnly && activeWeapon->isSniperRifle() && !localPlayer->isScoped())
            return;

        std::array<bool, 19> hitboxs{ false };

        for (int i = 0; i < ARRAYSIZE(config->legitbot[weaponIndex].hitboxes); i++)
        {
            switch (i)
            {
            case 0: //Head
                hitboxs[Hitboxes::HEAD] = config->legitbot[weaponIndex].hitboxes[i];
                break;
            case 1: //Chest
                hitboxs[Hitboxes::UPPER_CHEST] = config->legitbot[weaponIndex].hitboxes[i];
                hitboxs[Hitboxes::CHEST] = config->legitbot[weaponIndex].hitboxes[i];
                hitboxs[Hitboxes::LOWER_CHEST] = config->legitbot[weaponIndex].hitboxes[i];
                break;
            case 2: //Stomach
                hitboxs[Hitboxes::STOMACH] = config->legitbot[weaponIndex].hitboxes[i];
                hitboxs[Hitboxes::PELVIS] = config->legitbot[weaponIndex].hitboxes[i];
                break;
            case 3: //Arms
                hitboxs[Hitboxes::RIGHT_UPPER_ARM] = config->legitbot[weaponIndex].hitboxes[i];
                hitboxs[Hitboxes::RIGHT_FOREARM] = config->legitbot[weaponIndex].hitboxes[i];
                hitboxs[Hitboxes::LEFT_UPPER_ARM] = config->legitbot[weaponIndex].hitboxes[i];
                hitboxs[Hitboxes::LEFT_FOREARM] = config->legitbot[weaponIndex].hitboxes[i];
                break;
            case 4: //Legs
                hitboxs[Hitboxes::RIGHT_CALF] = config->legitbot[weaponIndex].hitboxes[i];
                hitboxs[Hitboxes::RIGHT_THIGH] = config->legitbot[weaponIndex].hitboxes[i];
                hitboxs[Hitboxes::LEFT_CALF] = config->legitbot[weaponIndex].hitboxes[i];
                hitboxs[Hitboxes::LEFT_THIGH] = config->legitbot[weaponIndex].hitboxes[i];
                break;
            default:
                break;
            }
        }

        auto bestFov = config->legitbot[weaponIndex].fov;
        Vector bestTarget{ };
        auto localPlayerEyePosition = localPlayer->getEyePosition();

        const auto aimPunch = activeWeapon->requiresRecoilControl() ? localPlayer->getAimPunch() : Vector{ };

        for (int i = 1; i <= interfaces->engine->getMaxClients(); i++) {
            auto entity = interfaces->entityList->getEntity(i);
            if (!entity || entity == localPlayer.get() || entity->isDormant() || !entity->isAlive()
                || !entity->isOtherEnemy(localPlayer.get()) && !config->legitbot[weaponIndex].friendlyFire || entity->gunGameImmunity())
                continue;
            for (int j = 0; j < 19; j++)
            {
                if (!(hitboxs[j]))
                    continue;

                const Model* mod = entity->getModel();
                if (!mod)
                    continue;

                StudioHdr* hdr = interfaces->modelInfo->getStudioModel(mod);

                for (auto bonePosition : Multipoint(entity, Animations::data.player[i].matrix, hdr, j, weaponIndex))
                {
                    if (!entity->isVisible(bonePosition))
                        continue;

                    const auto angle{ Aimbot::calculateRelativeAngle(localPlayerEyePosition, bonePosition, cmd->viewangles + aimPunch) };
                    const auto fov{ angle.length2D() };

                    if (fov < bestFov) {
                        bestFov = fov;
                        bestTarget = Aimbot::velocityExtrapolate(entity, bonePosition);
                    }
                }

                if (!config->legitbot[weaponIndex].backtrack)
                    continue;

                auto records = &Backtrack::records[i];
                if (!records || records->empty() || !Backtrack::valid(records->front().simulationTime) || records->size() <= 3 || !config->backtrack.enabled)
                    continue;

                int bestRecord{ };

                for (size_t p = 0; p < Backtrack::records[i].size(); p++) {
                    auto& record = Backtrack::records[i][p];
                    if (!Backtrack::valid(record.simulationTime))
                        continue;

                    auto angle = Aimbot::calculateRelativeAngle(localPlayerEyePosition, record.head, cmd->viewangles + aimPunch);
                    auto fov = std::hypotf(angle.x, angle.y);
                    if (fov < bestFov) {
                        bestFov = fov;
                        bestRecord = p;
                    }
                }

                auto currentRecord = Backtrack::records[i][bestRecord];
                for (auto bonePosition : Multipoint(entity, currentRecord.matrix, currentRecord.hdr, j, weaponIndex))
                {
                    if (!entity->isVisible(bonePosition))
                        continue;

                    const auto angle{ Aimbot::calculateRelativeAngle(localPlayerEyePosition, bonePosition, cmd->viewangles + aimPunch) };
                    const auto fov{ angle.length2D() };

                    if (fov < bestFov) {
                        bestFov = fov;
                        bestTarget = Aimbot::velocityExtrapolate(entity, bonePosition);
                    }
                }
            }
        }

        static float lastTime{ 0.0f };
        if (bestTarget && (config->legitbot[weaponIndex].ignoreSmoke || !memory->lineGoesThroughSmoke(localPlayer->getEyePosition(), bestTarget, 1))) {
            static Vector lastAngles{ cmd->viewangles };
            static int lastCommand{ };

            if (lastCommand == cmd->commandNumber - 1 && lastAngles && config->legitbot[weaponIndex].silent)
                cmd->viewangles = lastAngles;

            auto angle = Aimbot::calculateRelativeAngle(localPlayer->getEyePosition(), bestTarget, cmd->viewangles + aimPunch);
            bool clamped{ false };

            if (fabs(angle.x) > config->misc.maxAngleDelta || fabs(angle.y) > config->misc.maxAngleDelta) {
                angle.x = std::clamp(angle.x, -config->misc.maxAngleDelta, config->misc.maxAngleDelta);
                angle.y = std::clamp(angle.y, -config->misc.maxAngleDelta, config->misc.maxAngleDelta);
                clamped = true;
            }

            if (memory->globalVars->serverTime() - lastTime >= config->legitbot[weaponIndex].reactionTime / 1000.0f)
            {
                angle /= config->legitbot[weaponIndex].smooth;
                cmd->viewangles += angle;
                if (!config->legitbot[weaponIndex].silent)
                    interfaces->engine->setViewAngles(cmd->viewangles);
            }

            if (clamped)
                cmd->buttons &= ~UserCmd::IN_ATTACK;

            if (clamped || config->legitbot[weaponIndex].smooth > 1.0f) lastAngles = cmd->viewangles;
            else lastAngles = Vector{ };

            lastCommand = cmd->commandNumber;
        }
        if(!bestTarget)
            lastTime = memory->globalVars->serverTime();
    }
}
