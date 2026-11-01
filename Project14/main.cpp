#include <iostream>
#include <vector>
using namespace std;




class instrument {
protected:
    string name;
    string sound;




public:




    instrument(string _n, string _s) {
        name = _n;
        sound = _s;
    }




    string get_name() {
        return name;
    }
    string get_sound() {
        return sound;
    }




    virtual void play() = 0;




};




class brass :public instrument {
public:
    brass(string _n, string _s) : instrument(_n, _s) {};




    void play() {
        cout << name << ": " << sound << " " << sound << " " << sound << endl;
    }
};




class trumpet :public brass {
public:
    trumpet(string _s) : brass("Trumpet", _s) {};
};




class thrombone :public brass {
public:
    thrombone(string _s) : brass("Thrombone", _s) {};
    void play() {
        cout << name << ": " << sound << endl;
    }
};




class tuba :public brass {
public:
    tuba(string _s) : brass("Tuba", _s) {};
    void play() {
        cout << name << ": " << sound << " " << sound << endl;
    }
};




class woodwind :public instrument {
public:
    woodwind(string _n, string _s) : instrument(_n, _s) {};




    void play() {
        cout << name << ": " << sound << " " << sound << " " << sound << endl;
    }
};




class flute :public woodwind {
public:
    flute(string _s) : woodwind("Flute", _s) {};




    void play() {
        cout << name << ": " << sound << endl;
    }
};




class choir :public instrument {
public:
    choir(string _s) : instrument("Choir", _s) {};




    void play() {
        cout << name << ":  " << sound << " " << sound << endl;
    }
};




class orchestra :public instrument {
protected:
    vector<instrument*> band;




public:
    orchestra(string _n) :instrument(_n, " ") {};
    void add_to_list(instrument* v) {
        band.push_back(v);
    }
    void play() {
        auto start = band.begin();
        auto end = band.end();
        for (auto i = start;i != end;i++)
        {
            (*i)->play();
        }
    }
};
int main()
{
    trumpet a = trumpet("doot");
    thrombone b = thrombone("wah");
    tuba t = tuba("doo");
    brass l = brass("French Horn", "ha");


    flute c = flute("dit");
    choir youth = choir("la");
    woodwind d = woodwind("claranet", "wi");




    orchestra e = orchestra("orchestra");


    e.add_to_list(&a);
    e.add_to_list(&b);
    e.add_to_list(&t);
    e.add_to_list(&l);
    e.add_to_list(&c);
    e.add_to_list(&youth);
    e.add_to_list(&d);
    e.play();
}











