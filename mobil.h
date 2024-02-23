//
//  mobil.h
//  TugBes
//
//  Created by Attaf Riski Putra Ramadhan on 15/04/22.
//

#ifndef MOBIL_H
#define MOBIL_H
class Halangan {
public:
    float posisiZMobil;
    float posisiXMobil;
    void cylinder(float alas, float atas, float tinggi);
    void kerucut(float ngisor, float nduwur, float dowo);
    void blok(float tebal, int ratiol, int ratiop);
    void Mobil(float r, float g, float b);
    void Cone();
    void sisiCone();
};




#endif /* mobil_h */
