#include <iostream>
#include <fstream>
#include <string>
#include <list> 
#include <iterator> 


using namespace std;

void devam(string);

struct info {

    string inf;
    int devamsizlik;
};

info inf1;
list <struct info> list0;


int main() {




    list <struct info> ::iterator it;
    ifstream ptr("LUT.txt");
    string satir = "";
    int a, no;

    if (!ptr) {
        cout << "lut açýlmadý";
    }

    else {

        getline(ptr, satir);//ilk satýrý okuma isim soyisim vs
        while (getline(ptr, satir)) {
            //cout << satir << endl;
            int l = satir.length();
            a = satir.find("    "); //ayýracaðýmýz yeri bulma
            string str = satir.substr(a + 4, l); // str = numara+isim soy isim
            //cout << str << endl;
            no = str.find("2"); //numara baþlangýcýný bulma

            if (no == -1) //-1 bulamaz ise döndürdüðü deðer
            {
                continue;
            }
            string str1 = str.substr(no, no + 8); //str1 numaranýn kendisi

            //cout << str1 << endl;
            inf1.inf = str1;
            inf1.devamsizlik = 0;

            list0.push_back(inf1);

        }
        //cout << "derse kayitli olanlar" << endl;
       // cout << "----------------" << endl;
    }
    ptr.close();


    devam("chat1.txt");
    // cout << "chat 1 acildi";
    devam("chat2.txt");
    //cout << "chat 2 acildi";
    devam("chat3.txt");
    //cout << "chat 3 acildi";
    devam("chat4.txt");
    //cout << "chat 4 acildi";
    devam("chat5.txt");
    //cout << "chat 5 acildi";

    //cout << "-----------------------" << endl;
    ifstream aptr("LUT.txt");
    it = list0.begin();
    string name, name1;

    int smt = 0, l = 0;
    getline(aptr, satir);
    while (getline(aptr, satir)) {
        l = satir.length();
        smt = satir.find("    ");
        name = satir.substr(smt + 3);
        smt = name.find("    ");
        name1 = name.substr(smt + 3);
        cout << it->inf << " " << name1 << "  ogrenci derslere " << it->devamsizlik << " kere katildi" << endl;
        ++it;
    }

    aptr.close();
    return 0;
}
//devamsýzlýðý hesaplýyor
void devam(string a) {

    ifstream ptr1(a);
    string satir1;
    int no1, a1;
    list <struct info> ::iterator it2;
    it2 = list0.begin();
    if (!ptr1) {
        cout << a << "açýlamadý" << endl;
    }
    else {
        for (it2 = list0.begin(); it2 != list0.end(); ++it2) {
            while (getline(ptr1, satir1)) {
                int a = 0;
                //cout << satir << endl;
                int l = satir1.length();
                a1 = satir1.find(": "); //ayýracaðýmýz yeri bulma
                string str = satir1.substr(a1 + 2, l); // str = numara+isim soy isim
                //cout << str << endl;
                no1 = str.find("2"); //numara baþlangýcýný bulma
                if (no1 == -1) //-1 bulamaz ise döndürdüðü deðer
                {
                    continue;
                }
                string str1 = str.substr(no1, no1 + 8); //str1 numaranýn kendisi
                if (str1 == it2->inf) {
                    it2->devamsizlik++;
                    break;
                }
            }
            ptr1.clear();
            ptr1.seekg(0);
        }

    }
    ptr1.close();
    //cout << "------------"<<endl;
}

//for while olucak ve while ile yer deðiþecek